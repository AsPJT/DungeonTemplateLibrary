/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_STORAGE_FILE_CSV_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_STORAGE_FILE_CSV_HPP

/* Character Code : UTF-8 (BOM) */
/* Bug Check : not checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <Utility/CharCast.hpp>
#include <Macros/constexpr.hpp>

namespace dtl {
	inline namespace storage {

		using namespace std::literals::string_literals;

		template<typename Matrix_Int_>
		class FileCSV {
		private:

			///// エイリアス /////

			using Index_Size = std::size_t;
			


			///// メンバ変数 /////

			std::string str{ "file.csv"s };
			char delimiter{ ',' };


			///// 代入処理 /////

			template<typename Matrix_>
			DTL_CONSTEXPR_CPP14
				inline void substitutionSTL(Matrix_&& matrix_, const Index_Size end_x_, const Index_Size end_y_, const Matrix_Int_& value_) const noexcept {
				matrix_[end_y_][end_x_] = value_;
			}
			template<typename Matrix_>
			DTL_CONSTEXPR_CPP14
				inline void substitutionArray(Matrix_&& matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, const Matrix_Int_& value_) const noexcept {
				matrix_[end_y_ * max_x_ + end_x_] = value_;
			}
			template<typename Matrix_>
			DTL_CONSTEXPR_CPP14
				inline void substitutionLayer(Matrix_&& matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, const Matrix_Int_& value_) const noexcept {
				matrix_[end_y_][end_x_][layer_] = value_;
			}

			//csvファイルの読み込み時の分割
			template<typename Matrix_>
			void xSplitCSV(Matrix_& matrix_, const Index_Size y_id_, std::string& input_line_) const noexcept {
				if (matrix_.size() <= y_id_) return;
				std::istringstream stream(input_line_);
				std::string field{};
				for (Index_Size x_id{}; std::getline(stream, field, delimiter); ++x_id) {
					if (matrix_[y_id_].size() <= x_id) return;
					this->substitutionSTL(matrix_, x_id, y_id_, dtl::utility::charCast<Matrix_Int_>(field));
				}
				return;
			}
			template<typename Matrix_>
			void xSplitCSV(Matrix_ & matrix_, const Index_Size y_id_, std::string & input_line_, const Index_Size layer_) const noexcept {
				if (matrix_.size() <= y_id_) return;
				std::istringstream stream(input_line_);
				std::string field{};
				for (Index_Size x_id{}; std::getline(stream, field, delimiter); ++x_id) {
					if (matrix_[y_id_].size() <= x_id) return;
					this->substitutionLayer(matrix_, layer_, x_id, y_id_, dtl::utility::charCast<Matrix_Int_>(field));
				}
				return;
			}
			template<typename Matrix_>
			void xSplitCSV(Matrix_ & matrix_, const Index_Size y_id_, std::string & input_line_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				if (max_y_ <= y_id_) return;
				std::istringstream stream(input_line_);
				std::string field{};
				for (Index_Size x_id{}; std::getline(stream, field, delimiter); ++x_id) {
					if (max_x_ <= x_id) return;
					this->substitutionSTL(matrix_, x_id, y_id_, dtl::utility::charCast<Matrix_Int_>(field));
				}
				return;
			}
			template<typename Matrix_>
			void xSplitCSV(Matrix_ & matrix_, const Index_Size y_id_, std::string & input_line_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				if (max_y_ <= y_id_) return;
				std::istringstream stream(input_line_);
				std::string field{};
				for (Index_Size x_id{}; std::getline(stream, field, delimiter); ++x_id) {
					if (max_x_ <= x_id) return;
					this->substitutionLayer(matrix_, layer_, x_id, y_id_, dtl::utility::charCast<Matrix_Int_>(field));
				}
				return;
			}
			template<typename Matrix_>
			void xSplitCSV_Array(Matrix_ & matrix_, const Index_Size y_id_, std::string & input_line_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				if (max_y_ <= y_id_) return;
				std::istringstream stream(input_line_);
				std::string field{};
				for (Index_Size x_id{}; std::getline(stream, field, delimiter); ++x_id) {
					if (max_x_ <= x_id) return;
					this->substitutionArray(matrix_, x_id, y_id_, max_x_, dtl::utility::charCast<Matrix_Int_>(field));
				}
				return;
			}

			//csvファイルの読み込み
			template<typename Matrix_, typename ...Args_>
			bool ySplitCSV(Matrix_ & matrix_, Args_ && ... args_) const noexcept {
				std::ifstream ifs(str);
				if (ifs.fail()) return false;
				std::string line{};
				for (Index_Size y_id{}; std::getline(ifs, line); ++y_id)
					xSplitCSV(matrix_, y_id, line, args_...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			bool ySplitCSV_Array(Matrix_ & matrix_, Args_ && ... args_) const noexcept {
				std::ifstream ifs(str);
				if (ifs.fail()) return false;
				std::string line{};
				for (Index_Size y_id{}; std::getline(ifs, line); ++y_id)
					xSplitCSV_Array(matrix_, y_id, line, args_...);
				return true;
			}

		public:

			//csvファイルの読み込み
			template<typename Matrix_, typename ...Args_>
			bool read(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				return ySplitCSV(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			}
			template<typename Matrix_, typename ...Args_>
			bool readArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				return ySplitCSV_Array(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			}

			//csvファイルの書き込み
			template<typename Matrix_>
			bool write(Matrix_ && matrix_) noexcept {
				if (matrix_.size() == 0 || matrix_[0].size() == 0) return false;
				std::ofstream ofs(str);
				if (ofs.fail()) return false;
				for (std::size_t row{}; row < matrix_.size(); ++row) {
					if (matrix_[row].size() == 0) continue;
					ofs << dtl::utility::tool::getOutputNumber(matrix_[row][0]);
					for (std::size_t col{ 1 }; col < matrix_[row].size(); ++col) {
						ofs << delimiter;

						ofs << ((dtl::utility::isOutputCast<Matrix_Int_>()) ? static_cast<int>(matrix_[row][col]) : matrix_[row][col]);
					}
					ofs << '\n';
				}
				return true;
			}

			constexpr FileCSV() noexcept = default;
			constexpr FileCSV(const std::string & str_)noexcept :str(str_) {}
			constexpr FileCSV(const std::string & str_, const char delimiter_) noexcept :str(str_), delimiter(delimiter_) {}


		};

	}
}

//Dungeon Template Library Namespace
namespace dtl {
	inline namespace file {
		namespace read {
			namespace stl {

				namespace hiding {

					//文字として保存された数字を数値に変換する
					template<typename Cast_After_, typename Cast_Before_> //maybe_unused
					Cast_After_ splitReturnValue_csv(const Cast_After_, const Cast_Before_, const std::string& field_) noexcept {
						std::istringstream field_stream(field_);
						Cast_Before_ field_int{};
						field_stream >> field_int;
						return static_cast<Cast_After_>(field_int);
					}

					//csvファイルの読み込み時の分割
					template<typename Matrix_>
					void split_csv(Matrix_& matrix_, const std::size_t y_id_, std::string& input_line_, const char delimiter_) noexcept {
						if (matrix_.size() <= y_id_) return;
						std::istringstream stream(input_line_);
						std::string field{};
						std::size_t x_id{};
						while (std::getline(stream, field, delimiter_)) {
							if (matrix_[y_id_].size() <= x_id) return;
							matrix_[y_id_][x_id] = dtl::file::read::stl::hiding::splitReturnValue_csv(matrix_[y_id_][x_id], dtl::utility::tool::getOutputNumber(matrix_[y_id_][x_id]), field);
							++x_id;
						}
						return;
					}
					//csvファイルの読み込み時の分割
					template<typename Matrix_>
					void splitPush_csv(Matrix_ & matrix_, const std::size_t y_id_, std::string & input_line_, const char delimiter_) noexcept {
						matrix_.emplace_back(0);
						if (matrix_.size() <= y_id_) return;
						std::istringstream stream(input_line_);
						std::string field{};
						std::size_t x_id{};
						while (std::getline(stream, field, delimiter_)) {
							matrix_[y_id_].emplace_back(0);
							if (matrix_[y_id_].size() <= x_id) return;
							matrix_[y_id_][x_id] = dtl::file::read::stl::hiding::splitReturnValue_csv(matrix_[y_id_][x_id], dtl::utility::tool::getOutputNumber(matrix_[y_id_][x_id]), field);
							++x_id;
						}
						return;
					}

				}

				//csvファイルの読み込み
				template<typename Matrix_>
				bool csv(Matrix_ & matrix_, const std::string & str_, const char delimiter_ = ',') noexcept {
					std::ifstream ifs(str_);
					if (ifs.fail()) return false;

					std::size_t y_id{};
					std::string line{};
					while (std::getline(ifs, line)) {
						dtl::file::read::stl::hiding::split_csv(matrix_, y_id, line, delimiter_);
						++y_id;
					}
					return true;
				}

			}
		}
	}
}
namespace dtl {
	inline namespace file {
		namespace write {
			namespace stl {
				//csvファイルの書き込み
				template<typename Matrix_>
				bool csv(const Matrix_& matrix_, const std::string& str_) noexcept {
					if (matrix_.size() == 0 || matrix_[0].size() == 0) return false;
					std::ofstream ofs(str_);
					if (ofs.fail()) return false;
					for (std::size_t row{}; row < matrix_.size(); ++row) {
						if (matrix_[row].size() == 0) continue;
						ofs << dtl::utility::tool::getOutputNumber(matrix_[row][0]);
						for (std::size_t col{ 1 }; col < matrix_[row].size(); ++col) {
							ofs << ',';
							ofs << dtl::utility::tool::getOutputNumber(matrix_[row][col]);
						}
						ofs << '\n';
					}
					return true;
				}

			}
		}
	}
}

#endif //Included Dungeon Template Library