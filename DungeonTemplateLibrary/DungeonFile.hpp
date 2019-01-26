#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_FILE
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_FILE
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>
#include <cstdint>
#include <fstream>
#include <string>
#include <sstream>
#include <typeinfo>
#include <iomanip>

//Dungeon Template Library Namespace
namespace dtl {

	//文字として保存された数字を数値に変換する
	template<typename Matrix_Int_>
	Matrix_Int_ fileReadSplitReturnValue_csv(const std::string& field_) noexcept {
		return static_cast<Matrix_Int_>(std::stoi(field_));
	}
	template<>
	long fileReadSplitReturnValue_csv<long>(const std::string& field_) noexcept {
		return std::stol(field_);
	}
	template<>
	long long fileReadSplitReturnValue_csv<long long>(const std::string& field_) noexcept {
		return std::stoll(field_);
	}
	template<>
	unsigned long fileReadSplitReturnValue_csv<unsigned long>(const std::string& field_) noexcept {
		return std::stoul(field_);
	}
	template<>
	unsigned long long fileReadSplitReturnValue_csv<unsigned long long>(const std::string& field_) noexcept {
		return std::stoull(field_);
	}
	template<>
	float fileReadSplitReturnValue_csv<float>(const std::string& field_) noexcept {
		return std::stof(field_);
	}
	template<>
	double fileReadSplitReturnValue_csv<double>(const std::string& field_) noexcept {
		return std::stod(field_);
	}
	template<>
	long double fileReadSplitReturnValue_csv<long double>(const std::string& field_) noexcept {
		return std::stold(field_);
	}

	//csvファイルの読み込み時の分割
	template<typename Matrix_Int_, typename Matrix_>
	void fileReadSplit_csv(Matrix_& matrix_, const std::size_t y_id_, std::string& input_line_, const char delimiter_) noexcept {
		if (matrix_.size() <= y_id_) return;
		std::istringstream stream(input_line_);
		std::string field{};
		std::size_t x_id{};
		while (std::getline(stream, field, delimiter_)) {
			if (matrix_[y_id_].size() <= x_id) return;
			matrix_[y_id_][x_id] = fileReadSplitReturnValue_csv<Matrix_Int_>(field);
			++x_id;
		}
		return;
	}
	//csvファイルの読み込み
	template<typename Matrix_Int_, typename Matrix_>
	bool fileRead_csv(Matrix_& matrix_, const std::string& str_, const char delimiter_ = ',') noexcept {
		std::ifstream ifs(str_);
		if (ifs.fail()) return false;
		std::size_t y_id{};
		std::string line{};
		while (std::getline(ifs, line)) {
			fileReadSplit_csv<Matrix_Int_>(matrix_, y_id, line, delimiter_);
			++y_id;
		}
		return true;
	}
	//csvファイルの書き込み
	template<typename Matrix_Int_, typename Matrix_>
	bool fileWrite_csv(const Matrix_& matrix_, const std::string& str_) noexcept {
		std::ofstream ofs(str_);
		if (ofs.fail()) return false;
		const bool is_char{ (typeid(Matrix_Int_) == typeid(unsigned char) || typeid(Matrix_Int_) == typeid(signed char)) };
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() == 0) continue;
			if(is_char) ofs << static_cast<int>(matrix_[row][0]);
			else ofs << matrix_[row][0];
			for (std::size_t col{ 1 }; col < matrix_[row].size(); ++col) {
				ofs << ',';
				if (is_char) ofs << static_cast<int>(matrix_[row][col]);
				else ofs << matrix_[row][col];
			}
			ofs << std::endl;
		}
		return true;
	}
	//pbmファイルの書き込み
	template<typename Matrix_Int_, typename Matrix_>
	bool fileWrite_pbm(const Matrix_& matrix_, const std::string& str_) noexcept {
		std::ofstream ofs(str_);
		if (ofs.fail()) return false;

		ofs << "P1" << std::endl;
		ofs << ((matrix_.size() == 0) ? 0 : matrix_[0].size()) << " ";
		ofs << matrix_.size() << std::endl;

		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() == 0) continue;
			if (matrix_[row][0]) ofs << 1;
			else ofs << 0;
			for (std::size_t col{ 1 }; col < matrix_[row].size(); ++col) {
				ofs << " ";
				if (matrix_[row][col]) ofs << 1;
				else ofs << 0;
			}
			ofs << std::endl;
		}
		return true;
	}

	template<typename Matrix_>
	constexpr void fileWriteStringTemplate_svg(const Matrix_& matrix_, std::ofstream& ofs_) noexcept {
		ofs_ << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << std::endl;
		ofs_ << "<svg version=\"1.1\" id=\"layer\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" x=\"0px\" y=\"0px\" viewBox=\"0 0 ";
		ofs_ << ((matrix_.size() == 0) ? 0 : matrix_[0].size()) << " ";
		ofs_ << matrix_.size() << "\"";
		ofs_ << " style=\"enable-background:new 0 0 ";
		ofs_ << ((matrix_.size() == 0) ? 0 : matrix_[0].size()) << " ";
		ofs_ << matrix_.size();
		ofs_ << ";\" xml:space=\"preserve\">" << std::endl;
	}
	void fileWriteRectTemplate_svg(std::ofstream& ofs_, const std::size_t col_, const std::size_t row_) noexcept {
		ofs_ << "<rect x=\"" << col_ << "\" y=\"" << row_ << "\" width=\"1\" height=\"1\"/>" << std::endl;
	}
	void fileWriteRectTemplateColor_svg(std::ofstream& ofs_, const std::size_t col_, const std::size_t row_) noexcept {
		ofs_ << "<rect x=\"" << col_ << "\" y=\"" << row_ << "\" class=\"st1\" width=\"1\" height=\"1\"/>" << std::endl;
	}

	//svgファイルの書き込み(色付き)
	template<typename Matrix_>
	bool fileWriteColor_svg(const Matrix_& matrix_, const std::string& str_, const std::size_t color_true_ = 0, const std::size_t color_false_ = 0xffffff) noexcept {
		std::ofstream ofs(str_);
		if (ofs.fail()) return false;

		fileWriteStringTemplate_svg(matrix_, ofs);
		ofs << "<style type=\"text/css\">.st0{fill:#";
		ofs << std::hex << std::setw(6) << std::setfill('0') << color_false_ << std::dec;
		ofs << ";}.st1{fill:#";
		ofs << std::hex << std::setw(6) << std::setfill('0') << color_true_ << std::dec;
		ofs << ";}" << std::endl;

		ofs << "</style>" << std::endl;
		ofs << "<rect class=\"st0\" width=\"" << ((matrix_.size() == 0) ? 0 : matrix_[0].size()) << "\" height=\"" << matrix_.size() << "\"/>" << std::endl;

		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() == 0) continue;
			if (matrix_[row][0]) fileWriteRectTemplateColor_svg(ofs, 0, row);
			for (std::size_t col{ 1 }; col < matrix_[row].size(); ++col) {
				if (matrix_[row][col]) fileWriteRectTemplateColor_svg(ofs, col, row);
			}
		}
		ofs << "</svg>";
		return true;
	}
	//svgファイルの書き込み
	template<typename Matrix_>
	bool fileWrite_svg(const Matrix_& matrix_, const std::string& str_) noexcept {
		std::ofstream ofs(str_);
		if (ofs.fail()) return false;

		fileWriteStringTemplate_svg(matrix_, ofs);

		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() == 0) continue;
			if (matrix_[row][0]) fileWriteRectTemplate_svg(ofs, 0, row);
			for (std::size_t col{ 1 }; col < matrix_[row].size(); ++col) {
				if (matrix_[row][col]) fileWriteRectTemplate_svg(ofs, col, row);
			}
		}
		ofs << "</svg>";
		return true;
	}
	//バイナリファイルの書き込み
	template<typename Matrix_Int_, typename Matrix_>
	bool fileWrite(const Matrix_& matrix_, const std::string& str_) noexcept {
		std::ofstream ofs(str_, std::ios::binary);
		if (ofs.fail()) return false;

		std::uint64_t y_max{ static_cast<std::uint64_t>(matrix_.size()) };
		std::uint64_t x_max{ ((matrix_.size() == 0) ? static_cast <std::uint64_t>(0) : static_cast<std::uint64_t>(matrix_[0].size())) };
		ofs.write(reinterpret_cast<char *>(&x_max), sizeof(std::uint64_t));
		ofs.write(reinterpret_cast<char *>(&y_max), sizeof(std::uint64_t));

		Matrix_Int_ write_value{};
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				write_value = matrix_[row][col];
				ofs.write(reinterpret_cast<const char *>(&write_value), sizeof(Matrix_Int_));
			}
		return true;
	}
	//バイナリファイルの読み込み
	template<typename Matrix_Int_, typename Matrix_>
	bool fileRead(Matrix_& matrix_, const std::string& str_) noexcept {
		std::ifstream ifs(str_, std::ios::binary);
		if (ifs.fail()) return false;
		if (ifs.eof()) return false;
		std::uint64_t x_max{};
		std::uint64_t y_max{};
		ifs.read(reinterpret_cast<char *>(&x_max), sizeof(std::uint64_t));
		if (ifs.eof()) return false;
		ifs.read(reinterpret_cast<char *>(&y_max), sizeof(std::uint64_t));

		Matrix_Int_ read_value{};
		std::size_t x_count{};
		std::size_t y_count{};
		while (!ifs.eof()) {
			ifs.read(reinterpret_cast<char *>(&read_value), sizeof(Matrix_Int_));
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

	//dtlmファイルの読み込み
	template<typename Matrix_Int_, typename Matrix_>
	bool fileRead_dtlm(Matrix_& matrix_, const std::string& str_) noexcept {
		return fileRead(matrix_, str_);
	}
	//dtlmファイルの書き込み
	template<typename Matrix_Int_, typename Matrix_>
	bool fileWrite_dtlm(Matrix_& matrix_, const std::string& str_) noexcept {
		return fileWrite(matrix_, str_);
	}

}

#endif //Included Dungeon Template Library