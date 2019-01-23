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

//Dungeon Template Library Namespace
namespace dtl {
	template<typename Matrix_Int_>
	Matrix_Int_ fileReadSplitReturnValue_CSV(const std::string& field_) noexcept {
		return static_cast<Matrix_Int_>(std::stoi(field_));
	}
	template<>
	long fileReadSplitReturnValue_CSV<long>(const std::string& field_) noexcept {
		return std::stol(field_);
	}
	template<>
	long long fileReadSplitReturnValue_CSV<long long>(const std::string& field_) noexcept {
		return std::stoll(field_);
	}
	template<>
	unsigned long fileReadSplitReturnValue_CSV<unsigned long>(const std::string& field_) noexcept {
		return std::stoul(field_);
	}
	template<>
	unsigned long long fileReadSplitReturnValue_CSV<unsigned long long>(const std::string& field_) noexcept {
		return std::stoull(field_);
	}
	template<>
	float fileReadSplitReturnValue_CSV<float>(const std::string& field_) noexcept {
		return std::stof(field_);
	}
	template<>
	double fileReadSplitReturnValue_CSV<double>(const std::string& field_) noexcept {
		return std::stod(field_);
	}
	template<>
	long double fileReadSplitReturnValue_CSV<long double>(const std::string& field_) noexcept {
		return std::stold(field_);
	}

	template<typename Matrix_Int_, typename Matrix_>
	void fileReadSplit_CSV(Matrix_& matrix_, const std::size_t y_id_, std::string& input_line_, const char delimiter_) noexcept {
		if (matrix_.size() <= y_id_) return;
		std::istringstream stream(input_line_);
		std::string field{};
		std::size_t x_id{};
		while (std::getline(stream, field, delimiter_)) {
			if (matrix_[y_id_].size() <= x_id) return;
			matrix_[y_id_][x_id] = fileReadSplitReturnValue_CSV<Matrix_Int_>(field);
			++x_id;
		}
		return;
	}

	template<typename Matrix_Int_, typename Matrix_>
	bool fileRead_CSV(Matrix_& matrix_, const std::string& str_, const char delimiter_ = ',') noexcept {
		std::ifstream ifs(str_);
		if (ifs.fail()) return false;
		std::size_t y_id{};
		std::string line{};
		while (std::getline(ifs, line)) {
			fileReadSplit_CSV<Matrix_Int_>(matrix_, y_id, line, delimiter_);
			++y_id;
		}
		return true;
	}

	template<typename Matrix_Int_, typename Matrix_>
	bool fileWrite_CSV(const Matrix_& matrix_, const std::string& str_) noexcept {
		std::ofstream ofs(str_);
		if (ofs.fail()) return false;
		const bool is_char{ (typeid(Matrix_Int_) == typeid(unsigned char) || typeid(Matrix_Int_) == typeid(signed char)) };
		for (std::size_t i{}; i < matrix_.size(); ++i) {
			if (matrix_[i].size() == 0) continue;
			if(is_char) ofs << static_cast<int>(matrix_[i][0]);
			else ofs << matrix_[i][0];;
			for (std::size_t j{ 1 }; j < matrix_[i].size(); ++j) {
				ofs << ',';
				if (is_char) ofs << static_cast<int>(matrix_[i][j]);
				else ofs << matrix_[i][j];
			}
			ofs << std::endl;
		}
		return true;
	}

	template<typename Matrix_Int_, typename Matrix_>
	bool fileWrite(const Matrix_& matrix_, const std::string& str_) noexcept {
		std::ofstream ofs(str_, std::ios::binary);
		if (ofs.fail()) return false;

		std::uint64_t y_max{ static_cast<std::uint64_t>(matrix_.size()) };
		std::uint64_t x_max{ ((matrix_.size() == 0) ? static_cast <std::uint64_t>(0) : static_cast<std::uint64_t>(matrix_[0].size())) };
		ofs.write(reinterpret_cast<char *>(&x_max), sizeof(std::uint64_t));
		ofs.write(reinterpret_cast<char *>(&y_max), sizeof(std::uint64_t));

		Matrix_Int_ write_value{};
		for (std::size_t i{}; i < matrix_.size(); ++i)
			for (std::size_t j{}; j < matrix_[i].size(); ++j) {
				write_value = matrix_[i][j];
				ofs.write(reinterpret_cast<const char *>(&write_value), sizeof(Matrix_Int_));
			}
		return true;
	}
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
}

#endif //Included Dungeon Template Library