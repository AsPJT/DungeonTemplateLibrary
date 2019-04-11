/*#######################################################################################
	Made by Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_FILE
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_FILE

/* [2019/03/09] Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <fstream>
#include <string>
#include <sstream>
#include <typeinfo>
#include <iomanip>
#include <array>
#include <Utility/IsOutputCast.hpp>
#include <Storage/FileCSV.hpp>

//Dungeon Template Library Namespace
namespace dtl::file::read::stl {
	

	//バイナリファイルの読み込み
	template<typename Matrix_>
	bool dtlm(Matrix_& matrix_, const std::string& str_) noexcept {
		if (matrix_.size() == 0 || matrix_[0].size() == 0) return false;
		std::ifstream ifs(str_, std::ios::binary);
		if (ifs.fail()) return false;
		if (ifs.eof()) return false;
		std::uint64_t x_max{};
		std::uint64_t y_max{};
		ifs.read(reinterpret_cast<char *>(&x_max), sizeof(std::uint64_t));
		if (ifs.eof()) return false;
		ifs.read(reinterpret_cast<char *>(&y_max), sizeof(std::uint64_t));

		auto read_value{ matrix_[0][0] };
		std::size_t x_count{};
		std::size_t y_count{};
		while (!ifs.eof()) {
			ifs.read(reinterpret_cast<char *>(&read_value), sizeof(matrix_[0][0]));
			if (x_count >= static_cast<std::size_t>(x_max)) {
				x_count = static_cast<std::size_t>(0);
				++y_count;
			}
			if (y_count >= matrix_.size()) break;
			if (x_count >= matrix_[y_count].size()) continue;

			matrix_[y_count][x_count] = read_value;
			++x_count;
		}
		return true;
	}

} //namespace
namespace dtl::file::write::stl {
	//mdファイルの書き込み
	template<typename Matrix_>
	bool md(const Matrix_& matrix_, const std::string& str_) noexcept {
		if (matrix_.size() == 0 || matrix_[0].size() == 0) return false;
		std::ofstream ofs(str_);
		if (ofs.fail()) return false;
		ofs << '|';
		for (std::size_t row{}; row < matrix_.size(); ++row)
			ofs << row << '|';
		ofs << '\n' << '|';
		for (std::size_t row{}; row < matrix_.size(); ++row)
			ofs << ":---|";
		ofs << '\n';
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() == 0) continue;
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				ofs << '|';
				ofs << dtl::utility::tool::getOutputNumber(matrix_[row][col]);
			}
			ofs << '|';
			ofs << '\n';
		}
		return true;
	}
	//0~9ファイルの書き込み
	template<typename Matrix_>
	bool txt_0_9(const Matrix_& matrix_, const std::string& str_) noexcept {
		std::ofstream ofs(str_);
		if (ofs.fail()) return false;
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (matrix_[row][col] <= 0) ofs << 0;
				else if (matrix_[row][col] >= 9) ofs << 9;
				ofs << dtl::utility::tool::getOutputNumber(matrix_[row][col]);
			}
			ofs << '\n';
		}
		return true;
	}
	//pbmファイルの書き込み
	template<typename Matrix_>
	bool pbm(const Matrix_& matrix_, const std::string& str_) noexcept {
		std::ofstream ofs(str_);
		if (ofs.fail()) return false;

		ofs << "P1" << '\n';
		ofs << ((matrix_.size() == 0) ? 0 : matrix_[0].size()) << " ";
		ofs << matrix_.size() << '\n';

		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() == 0) continue;
			if (matrix_[row][0]) ofs << 1;
			else ofs << 0;
			for (std::size_t col{ 1 }; col < matrix_[row].size(); ++col) {
				ofs << " ";
				if (matrix_[row][col]) ofs << 1;
				else ofs << 0;
			}
			ofs << '\n';
		}
		return true;
	}

	namespace hiding {

		template<typename Matrix_>
		constexpr void stringTemplate_svg(const Matrix_& matrix_, std::ofstream& ofs_) noexcept {
			ofs_ << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << '\n';
			ofs_ << "<svg version=\"1.1\" id=\"layer\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" x=\"0px\" y=\"0px\" viewBox=\"0 0 ";
			ofs_ << ((matrix_.size() == 0) ? 0 : matrix_[0].size()) << " ";
			ofs_ << matrix_.size() << "\"";
			ofs_ << " style=\"enable-background:new 0 0 ";
			ofs_ << ((matrix_.size() == 0) ? 0 : matrix_[0].size()) << " ";
			ofs_ << matrix_.size();
			ofs_ << ";\" xml:space=\"preserve\">" << '\n';
		}
		void rectTemplate_svg(std::ofstream& ofs_, const std::size_t col_, const std::size_t row_) noexcept {
			ofs_ << "<rect x=\"" << col_ << "\" y=\"" << row_ << "\" width=\"1\" height=\"1\"/>" << '\n';
		}
		void rectTemplateColor_svg(std::ofstream& ofs_, const std::size_t col_, const std::size_t row_) noexcept {
			ofs_ << "<rect x=\"" << col_ << "\" y=\"" << row_ << "\" class=\"st1\" width=\"1\" height=\"1\"/>" << '\n';
		}

	}

	//svgファイルの書き込み(色付き)
	template<typename Matrix_>
	bool svgColor(const Matrix_& matrix_, const std::string& str_, const std::size_t color_true_ = 0, const std::size_t color_false_ = 0xffffff) noexcept {
		std::ofstream ofs(str_);
		if (ofs.fail()) return false;

		dtl::file::write::stl::hiding::stringTemplate_svg(matrix_, ofs);
		ofs << "<style type=\"text/css\">.st0{fill:#";
		ofs << std::hex << std::setw(6) << std::setfill('0') << color_false_ << std::dec;
		ofs << ";}.st1{fill:#";
		ofs << std::hex << std::setw(6) << std::setfill('0') << color_true_ << std::dec;
		ofs << ";}" << '\n';

		ofs << "</style>" << '\n';
		ofs << "<rect class=\"st0\" width=\"" << ((matrix_.size() == 0) ? 0 : matrix_[0].size()) << "\" height=\"" << matrix_.size() << "\"/>" << '\n';

		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() == 0) continue;
			if (matrix_[row][0]) dtl::file::write::stl::hiding::rectTemplateColor_svg(ofs, 0, row);
			for (std::size_t col{ 1 }; col < matrix_[row].size(); ++col) {
				if (matrix_[row][col]) dtl::file::write::stl::hiding::rectTemplateColor_svg(ofs, col, row);
			}
		}
		ofs << "</svg>";
		return true;
	}
	//svgファイルの書き込み
	template<typename Matrix_>
	bool svg(const Matrix_& matrix_, const std::string& str_) noexcept {
		std::ofstream ofs(str_);
		if (ofs.fail()) return false;

		dtl::file::write::stl::hiding::stringTemplate_svg(matrix_, ofs);

		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() == 0) continue;
			if (matrix_[row][0]) dtl::file::write::stl::hiding::rectTemplate_svg(ofs, 0, row);
			for (std::size_t col{ 1 }; col < matrix_[row].size(); ++col) {
				if (matrix_[row][col]) dtl::file::write::stl::hiding::rectTemplate_svg(ofs, col, row);
			}
		}
		ofs << "</svg>";
		return true;
	}
	//objファイルの書き込み
	template<typename Matrix_>
	bool objTerrain(const Matrix_& matrix_, const std::string& str_) noexcept {
		if (matrix_.size() == 0 || matrix_[0].size() == 0) return false;
		std::ofstream ofs(str_);
		if (ofs.fail()) return false;

			for (std::size_t row{}; row < matrix_.size(); ++row)
				for (std::size_t col{}; col < matrix_[row].size(); ++col)
					ofs << "v " << col << " " << dtl::utility::tool::getOutputNumber(matrix_[row][col]) << " " << row << '\n';

		std::size_t x_size{ matrix_[0].size() };
		for (std::size_t row{ 1 }; row < matrix_.size(); ++row)
			for (std::size_t col{ 2 }; col <= matrix_[row].size(); ++col) {
				ofs << "f " << (row*x_size + col) << " " << ((row - 1)*x_size + col) << " " << ((row - 1)*x_size + (col - 1)) << '\n';
				ofs << "f " << (row * x_size + (col - 1)) << " " << (row * x_size + col) << " " << ((row - 1)*x_size + (col - 1)) << '\n';
			}
		return true;
	}

	namespace hiding {

		void write_objOutputId(std::ofstream& ofs_, const std::size_t id_ = 0) noexcept {
			ofs_ << "f " << (1 + id_ * 8) << " " << (3 + id_ * 8) << " " << (4 + id_ * 8) << " " << (2 + id_ * 8) << '\n';
			ofs_ << "f " << (1 + id_ * 8) << " " << (5 + id_ * 8) << " " << (7 + id_ * 8) << " " << (3 + id_ * 8) << '\n';
			ofs_ << "f " << (2 + id_ * 8) << " " << (4 + id_ * 8) << " " << (8 + id_ * 8) << " " << (6 + id_ * 8) << '\n';
			ofs_ << "f " << (1 + id_ * 8) << " " << (2 + id_ * 8) << " " << (6 + id_ * 8) << " " << (5 + id_ * 8) << '\n';
			ofs_ << "f " << (3 + id_ * 8) << " " << (7 + id_ * 8) << " " << (8 + id_ * 8) << " " << (4 + id_ * 8) << '\n';
			ofs_ << "f " << (5 + id_ * 8) << " " << (6 + id_ * 8) << " " << (8 + id_ * 8) << " " << (7 + id_ * 8) << '\n';
		}
		void write_objOutputCube(std::ofstream& ofs_, std::int_fast32_t start_x, std::int_fast32_t start_y, std::int_fast32_t start_z, std::int_fast32_t size_x, std::int_fast32_t size_y, std::int_fast32_t size_z, std::size_t id_ = 0) noexcept {
			ofs_ << "v " << start_x << " " << start_y << " " << start_z << " " << '\n';
			ofs_ << "v " << start_x + size_x << " " << start_y << " " << start_z << " " << '\n';
			ofs_ << "v " << start_x << " " << start_y + size_y << " " << start_z << " " << '\n';
			ofs_ << "v " << start_x + size_x << " " << start_y + size_y << " " << start_z << " " << '\n';
			ofs_ << "v " << start_x << " " << start_y << " " << start_z + size_z << " " << '\n';
			ofs_ << "v " << start_x + size_x << " " << start_y << " " << start_z + size_z << " " << '\n';
			ofs_ << "v " << start_x << " " << start_y + size_y << " " << start_z + size_z << " " << '\n';
			ofs_ << "v " << start_x + size_x << " " << start_y + size_y << " " << start_z + size_z << " " << '\n';
			dtl::file::write::stl::hiding::write_objOutputId(ofs_, id_);
		}

	}

	template<typename Matrix_Int_, typename Matrix_>
	bool objSandbox(const Matrix_& matrix_, const std::string& str_) noexcept {
		if (matrix_.size() == 0 || matrix_[0].size() == 0) return false;
		std::ofstream ofs(str_);
		if (ofs.fail()) return false;

		dtl::file::write::stl::hiding::write_objOutputCube(ofs, 0, -1, 0, (std::int_fast32_t)matrix_[0].size(), 1, (std::int_fast32_t)matrix_.size());

		std::size_t square_count{1};
		for (std::size_t row{}; row < 1; ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				dtl::file::write::stl::hiding::write_objOutputCube(ofs, (std::int_fast32_t)col, 0, (std::int_fast32_t)row, 1, matrix_[row][col], 1, square_count);
				++square_count;
			}
		for (std::size_t row{ matrix_.size() - 2}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				dtl::file::write::stl::hiding::write_objOutputCube(ofs, (std::int_fast32_t)col, 0, (std::int_fast32_t)row, 1, matrix_[row][col], 1, square_count);
				++square_count;
			}
		for (std::size_t row{ 1 }; row < matrix_.size() - 1; ++row) {
			for (std::size_t col{}; col < 1; ++col) {
				dtl::file::write::stl::hiding::write_objOutputCube(ofs, (std::int_fast32_t)col, 0, (std::int_fast32_t)row, 1, matrix_[row][col], 1, square_count);
				++square_count;
			}
			for (std::size_t col{ 1 }; col < matrix_[row].size() - 1; ++col) {
				auto tmp{ matrix_[row][col - 1] };
				if (tmp >= matrix_[row][col + 1]) tmp = matrix_[row][col + 1];
				if (tmp >= matrix_[row - 1][col]) tmp = matrix_[row - 1][col];
				if (tmp >= matrix_[row + 1][col]) tmp = matrix_[row + 1][col];
				if (tmp >= matrix_[row][col]) dtl::file::write::stl::hiding::write_objOutputCube(ofs, (std::int_fast32_t)col, matrix_[row][col] - 1, (std::int_fast32_t)row, 1, 1, 1, square_count);
				else dtl::file::write::stl::hiding::write_objOutputCube(ofs, (std::int_fast32_t)col, tmp, (std::int_fast32_t)row, 1, matrix_[row][col] - tmp, 1, square_count);
				++square_count;
			}
			for (std::size_t col{ matrix_[row].size() - 2 }; col < matrix_[row].size(); ++col) {
				dtl::file::write::stl::hiding::write_objOutputCube(ofs, (std::int_fast32_t)col, 0, (std::int_fast32_t)row, 1, matrix_[row][col], 1, square_count);
				++square_count;
			}
		}
		return true;
	}

	template<typename Matrix_Int_, typename Matrix_>
	bool objBoard(const Matrix_& matrix_, const std::string& str_, const std::int_fast32_t block_size_ = 1, const Matrix_Int_ output_id_ = 1) noexcept {
		if (matrix_.size() == 0 || matrix_[0].size() == 0) return false;
		std::ofstream ofs(str_);
		if (ofs.fail()) return false;

		dtl::file::write::stl::hiding::write_objOutputCube(ofs, 0, -1, 0, (std::int_fast32_t)matrix_[0].size(), 1, (std::int_fast32_t)matrix_.size());

		std::size_t square_count{ 1 };
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				if (matrix_[row][col] == output_id_) {
					dtl::file::write::stl::hiding::write_objOutputCube(ofs, (std::int_fast32_t)col, 0, (std::int_fast32_t)row, 1, block_size_, 1, square_count);
					++square_count;
				}
		return true;
	}
	//バイナリファイルの書き込み
	template<typename Matrix_>
	bool dtlm(const Matrix_& matrix_, const std::string& str_) noexcept {
		if (matrix_.size() == 0 || matrix_[0].size() == 0) return false;
		std::ofstream ofs(str_, std::ios::binary);
		if (ofs.fail()) return false;

		std::uint64_t y_max{ static_cast<std::uint64_t>(matrix_.size()) };
		std::uint64_t x_max{ ((matrix_.size() == 0) ? static_cast <std::uint64_t>(0) : static_cast<std::uint64_t>(matrix_[0].size())) };
		ofs.write(reinterpret_cast<char *>(&x_max), sizeof(std::uint64_t));
		ofs.write(reinterpret_cast<char *>(&y_max), sizeof(std::uint64_t));

		auto write_value{ matrix_[0][0] };
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				write_value = matrix_[row][col];
				ofs.write(reinterpret_cast<const char *>(&write_value), sizeof(write_value));
			}
		return true;
	}

	namespace data {

		constexpr std::size_t file_write_bmp_format_1bit_size{ 62 };
		constexpr std::array<std::uint8_t, file_write_bmp_format_1bit_size> file_write_bmp_format_1bit{ {
				//ファイルヘッダ(14)----------
				0x42,0x4d,
				0,0,0,0,//データ数
				0,0,
				0,0,
				0x3e,0,0,0,//データ数
				//情報ヘッダ(40)----------
				0x28,0,0,0,
				0,0,0,0,//画像x
				0,0,0,0,//画像y
				0x1,0,
				0x1,0,
				0,0,0,0,
				0,0,0,0,//データ数
				0,0,0,0,//画像x
				0,0,0,0,//画像y
				0,0,0,0,
				0,0,0,0,
				//パレットデータ(8)----------
				0xff,0xff,0xff,0,
				0,0,0,0
		} };

	}

	namespace hiding {

		void writeMatrixSize_bmp(std::array<std::uint_fast8_t, dtl::file::write::stl::data::file_write_bmp_format_1bit_size>& bmp_file_, std::uint32_t x_, std::uint32_t y_) noexcept {
			bmp_file_[38] = bmp_file_[18] = x_ & 0xff;
			bmp_file_[39] = bmp_file_[19] = (x_ >>= 8) & 0xff;
			bmp_file_[40] = bmp_file_[20] = (x_ >>= 8) & 0xff;
			bmp_file_[41] = bmp_file_[21] = (x_ >>= 8) & 0xff;
			bmp_file_[42] = bmp_file_[22] = y_ & 0xff;
			bmp_file_[43] = bmp_file_[23] = (y_ >>= 8) & 0xff;
			bmp_file_[44] = bmp_file_[24] = (y_ >>= 8) & 0xff;
			bmp_file_[45] = bmp_file_[25] = (y_ >>= 8) & 0xff;
		}

	}

	template<typename Matrix_>
	bool bmp(const Matrix_& matrix_, const std::string& str_, const std::uint32_t x_, const std::uint32_t y_) noexcept {
		std::ofstream ofs(str_, std::ios::binary);
		if (ofs.fail()) return false;

		std::array<std::uint_fast8_t, dtl::file::write::stl::data::file_write_bmp_format_1bit_size> format_1bit(dtl::file::write::stl::data::file_write_bmp_format_1bit);

		dtl::file::write::stl::hiding::writeMatrixSize_bmp(format_1bit, x_, y_);

		std::uint32_t size_x{ x_ / 8 + ((x_ % 8 != 0) ? 1 : 0) };
		if (size_x % 4 != 0) size_x += 4 - (size_x % 4);

		std::uint32_t picture_size{ size_x*y_ };
		std::uint32_t total_size{ static_cast<std::uint32_t>(dtl::file::write::stl::data::file_write_bmp_format_1bit_size) + picture_size };
		format_1bit[2] = total_size & 0xff;
		format_1bit[3] = (total_size >>= 8) & 0xff;
		format_1bit[4] = (total_size >>= 8) & 0xff;
		format_1bit[5] = (total_size >>= 8) & 0xff;

		format_1bit[34] = picture_size & 0xff;
		format_1bit[35] = (picture_size >>= 8) & 0xff;
		format_1bit[36] = (picture_size >>= 8) & 0xff;
		format_1bit[37] = (picture_size >>= 8) & 0xff;

		ofs.write(reinterpret_cast<const char *>(format_1bit.data()), format_1bit.size());

		std::uint8_t str{};
		for (std::size_t yy{ y_ - 1 }, i{};; --yy) {
			i = 0;
			for (std::size_t xx{}; xx < (x_ / 8); ++xx) {
				str = 0;
				for (std::size_t count{}; count < 8; ++i, ++count)
					str += (((matrix_[yy][i]) ? 1 : 0) << (7 - count));
				ofs.write(reinterpret_cast<const char *>(&str), sizeof(std::uint8_t));
			}
			str = 0;
			if (x_ % 8 != 0)
				for (std::size_t count{}; count < 8; ++i, ++count) {
					str += (((matrix_[yy][i]) ? 1 : 0) << (7 - count));
				}
			else if (x_ / 8 == size_x) {
				if (yy == 0) break;
				continue;
			}
			ofs.write(reinterpret_cast<const char *>(&str), sizeof(std::uint8_t));
			str = 0;
			for (std::size_t xx{ (x_ / 8) + 1 }; xx < size_x; ++xx) {
				ofs.write(reinterpret_cast<const char *>(&str), sizeof(std::uint8_t));
			}
			if (yy == 0) break;
		}
		return true;
	}

	template<typename Matrix_>
	bool bmp(const Matrix_& matrix_, const std::string& str_) noexcept {
		return bmp(matrix_, str_, (matrix_.size() == 0) ? 0 : static_cast<std::uint32_t>(matrix_[0].size()), static_cast<std::uint32_t>(matrix_.size()));
	}

	template<typename Matrix_>
	bool all(const Matrix_& matrix_, const std::string& str_) noexcept {
		//Text
		dtl::file::write::stl::dtlm(matrix_, str_ + ".dtlm");
		dtl::file::write::stl::csv(matrix_, str_ + ".csv");
		dtl::file::write::stl::md(matrix_, str_ + ".md");
		dtl::file::write::stl::txt_0_9(matrix_, str_ + "_0_9.txt");
		//Picture
		dtl::file::write::stl::pbm(matrix_, str_ + ".pbm");
		dtl::file::write::stl::svg(matrix_, str_ + ".svg");
		dtl::file::write::stl::bmp(matrix_, str_ + ".bmp");
		return true;
	}
	template<typename Matrix_>
	bool folderAll(const Matrix_& matrix_, const std::string& str_1, const std::string& str_2) noexcept {
		//Text
		dtl::file::write::stl::dtlm(matrix_, str_1 + "dtlm\\" + str_2 + ".dtlm");
		dtl::file::write::stl::csv(matrix_, str_1 + "csv\\" + str_2 + ".csv");
		dtl::file::write::stl::md(matrix_, str_1 + "md\\" + str_2 + ".md");
		dtl::file::write::stl::txt_0_9(matrix_, str_1 + "txt\\" + str_2 + "_0_9.txt");
		//Picture
		dtl::file::write::stl::pbm(matrix_, str_1 + "pbm\\" + str_2 + ".pbm");
		dtl::file::write::stl::svg(matrix_, str_1 + "svg\\" + str_2 + ".svg");
		dtl::file::write::stl::bmp(matrix_, str_1 + "bmp\\" + str_2 + ".bmp");
		return true;
	}

} //namespace

#endif //Included Dungeon Template Library