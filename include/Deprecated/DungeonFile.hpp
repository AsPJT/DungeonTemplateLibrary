/*#######################################################################################
	Made by Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_FILE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_FILE_HPP

/* Character Code : UTF-8 (BOM) */
/* [2019/03/09] Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <fstream>
#include <string>
#include <sstream>
#include <typeinfo>
#include <iomanip>
#include <array>
#include <Macros/constexpr.hpp>

//Dungeon Template Library Namespace
namespace dtl {
	inline namespace file {
		namespace read {
			namespace stl {


				//バイナリファイルの読み込み
				template<typename Matrix_>
				bool dtlm(Matrix_& matrix_, const std::string& str_) noexcept {
					if (matrix_.size() == 0 || matrix_[0].size() == 0) return false;
					std::ifstream ifs(str_, std::ios::binary);
					if (ifs.fail()) return false;
					if (ifs.eof()) return false;
					std::uint64_t x_max{};
					std::uint64_t y_max{};
					ifs.read(reinterpret_cast<char*>(&x_max), sizeof(std::uint64_t));
					if (ifs.eof()) return false;
					ifs.read(reinterpret_cast<char*>(&y_max), sizeof(std::uint64_t));

					auto read_value{ matrix_[0][0] };
					std::size_t x_count{};
					std::size_t y_count{};
					while (!ifs.eof()) {
						ifs.read(reinterpret_cast<char*>(&read_value), sizeof(matrix_[0][0]));
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
		}
	}
}
namespace dtl {
	inline namespace file {
		namespace write {
			namespace stl {

				namespace hiding {

					template<typename Matrix_>
					DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
						void stringTemplate_svg(const Matrix_& matrix_, std::ofstream& ofs_) noexcept {
						ofs_ << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << '\n';
						ofs_ << "<svg version=\"1.1\" id=\"layer\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" x=\"0px\" y=\"0px\" viewBox=\"0 0 ";
						ofs_ << ((matrix_.size() == 0) ? 0 : matrix_[0].size()) << " ";
						ofs_ << matrix_.size() << "\"";
						ofs_ << " style=\"enable-background:new 0 0 ";
						ofs_ << ((matrix_.size() == 0) ? 0 : matrix_[0].size()) << " ";
						ofs_ << matrix_.size();
						ofs_ << ";\" xml:space=\"preserve\">" << '\n';
					}
					void rectTemplate_svg(std::ofstream & ofs_, const std::size_t col_, const std::size_t row_) noexcept {
						ofs_ << "<rect x=\"" << col_ << "\" y=\"" << row_ << "\" width=\"1\" height=\"1\"/>" << '\n';
					}
					void rectTemplateColor_svg(std::ofstream & ofs_, const std::size_t col_, const std::size_t row_) noexcept {
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

				namespace hiding {

					void write_objOutputId(std::ofstream& ofs_, const std::size_t id_ = 0) noexcept {
						ofs_ << "f " << (1 + id_ * 8) << " " << (3 + id_ * 8) << " " << (4 + id_ * 8) << " " << (2 + id_ * 8) << '\n';
						ofs_ << "f " << (1 + id_ * 8) << " " << (5 + id_ * 8) << " " << (7 + id_ * 8) << " " << (3 + id_ * 8) << '\n';
						ofs_ << "f " << (2 + id_ * 8) << " " << (4 + id_ * 8) << " " << (8 + id_ * 8) << " " << (6 + id_ * 8) << '\n';
						ofs_ << "f " << (1 + id_ * 8) << " " << (2 + id_ * 8) << " " << (6 + id_ * 8) << " " << (5 + id_ * 8) << '\n';
						ofs_ << "f " << (3 + id_ * 8) << " " << (7 + id_ * 8) << " " << (8 + id_ * 8) << " " << (4 + id_ * 8) << '\n';
						ofs_ << "f " << (5 + id_ * 8) << " " << (6 + id_ * 8) << " " << (8 + id_ * 8) << " " << (7 + id_ * 8) << '\n';
					}
					void write_objOutputCube(std::ofstream & ofs_, std::int_fast32_t start_x, std::int_fast32_t start_y, std::int_fast32_t start_z, std::int_fast32_t size_x, std::int_fast32_t size_y, std::int_fast32_t size_z, std::size_t id_ = 0) noexcept {
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

					std::size_t square_count{ 1 };
					for (std::size_t row{}; row < 1; ++row)
						for (std::size_t col{}; col < matrix_[row].size(); ++col) {
							dtl::file::write::stl::hiding::write_objOutputCube(ofs, (std::int_fast32_t)col, 0, (std::int_fast32_t)row, 1, matrix_[row][col], 1, square_count);
							++square_count;
						}
					for (std::size_t row{ matrix_.size() - 2 }; row < matrix_.size(); ++row)
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
				bool objBoard(const Matrix_ & matrix_, const std::string & str_, const std::int_fast32_t block_size_ = 1, const Matrix_Int_ output_id_ = 1) noexcept {
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
				bool dtlm(const Matrix_ & matrix_, const std::string & str_) noexcept {
					if (matrix_.size() == 0 || matrix_[0].size() == 0) return false;
					std::ofstream ofs(str_, std::ios::binary);
					if (ofs.fail()) return false;

					std::uint64_t y_max{ static_cast<std::uint64_t>(matrix_.size()) };
					std::uint64_t x_max{ ((matrix_.size() == 0) ? static_cast <std::uint64_t>(0) : static_cast<std::uint64_t>(matrix_[0].size())) };
					ofs.write(reinterpret_cast<char*>(&x_max), sizeof(std::uint64_t));
					ofs.write(reinterpret_cast<char*>(&y_max), sizeof(std::uint64_t));

					auto write_value{ matrix_[0][0] };
					for (std::size_t row{}; row < matrix_.size(); ++row)
						for (std::size_t col{}; col < matrix_[row].size(); ++col) {
							write_value = matrix_[row][col];
							ofs.write(reinterpret_cast<const char*>(&write_value), sizeof(write_value));
						}
					return true;
				}

				template<typename Matrix_>
				bool all(const Matrix_ & matrix_, const std::string & str_) noexcept {
					//Text
					dtl::file::write::stl::dtlm(matrix_, str_ + ".dtlm");
					dtl::file::write::stl::csv(matrix_, str_ + ".csv");
					//Picture
					dtl::file::write::stl::svg(matrix_, str_ + ".svg");
					return true;
				}
				template<typename Matrix_>
				bool folderAll(const Matrix_ & matrix_, const std::string & str_1, const std::string & str_2) noexcept {
					//Text
					dtl::file::write::stl::dtlm(matrix_, str_1 + "dtlm\\" + str_2 + ".dtlm");
					dtl::file::write::stl::csv(matrix_, str_1 + "csv\\" + str_2 + ".csv");
					//Picture
					dtl::file::write::stl::svg(matrix_, str_1 + "svg\\" + str_2 + ".svg");
					return true;
				}

			} //namespace
		}
	}
}

#endif //Included Dungeon Template Library