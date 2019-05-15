/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_CONSOLE_OUTPUT_NUMBER_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_CONSOLE_OUTPUT_NUMBER_HPP

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <iostream>
#include <string>
#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Utility/IsOutputCast.hpp>

namespace dtl {
	inline namespace console {

		//四角形の生成
		template<typename Matrix_Int_, typename OutputString_ = std::string>
		class OutputNumber {
		private:


			///// エイリアス /////

			using Index_Size = ::dtl::type::size;
			


			///// メンバ変数 /////

			Index_Size start_x{};
			Index_Size start_y{};
			Index_Size width{};
			Index_Size height{};
			OutputString_ draw_string{};
			OutputString_ before_draw_string{};


			///// 代入処理 /////

			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				inline void outputSTL(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				std::cout << this->before_draw_string << ((::dtl::utility::isOutputCast<Matrix_Int_>()) ? static_cast<int>(matrix_[point_y_][point_x_]) : matrix_[point_y_][point_x_]) << this->draw_string;
			}
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				inline void outputArray(const Matrix_ & matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
				std::cout << this->before_draw_string << ((::dtl::utility::isOutputCast<Matrix_Int_>()) ? static_cast<int>(matrix_[point_y_ * max_x_ + point_x_]) : matrix_[point_y_ * max_x_ + point_x_]) << this->draw_string;
			}
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				inline void outputLayer(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				std::cout << this->before_draw_string << ((::dtl::utility::isOutputCast<Matrix_Int_>()) ? static_cast<int>(matrix_[point_y_][point_x_][layer_]) : matrix_[point_y_][point_x_][layer_]) << this->draw_string;
			}
			template<typename Matrix_Value_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				inline void outputList(const Matrix_Value_& matrix_) const noexcept {
				std::cout << this->before_draw_string << ((::dtl::utility::isOutputCast<Matrix_Int_>()) ? static_cast<int>(matrix_) : matrix_) << this->draw_string;
			}


			///// 基本処理 /////

			//STL
			template<typename Matrix_>
			bool drawSTL(const Matrix_ & matrix_, const Index_Size end_y_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					for (Index_Size col{ this->start_x }; col < matrix_[row].size(); ++col)
						this->outputSTL(matrix_, col, row);
					std::cout << '\n';
				}
				return true;
			}
			template<typename Matrix_>
			bool drawWidthSTL(const Matrix_ & matrix_, const Index_Size end_x_, const Index_Size end_y_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					for (Index_Size col{ this->start_x }; col < matrix_[row].size() && col < end_x_; ++col)
						this->outputSTL(matrix_, col, row);
					std::cout << '\n';
				}
				return true;
			}

			//LayerSTL
			template<typename Matrix_>
			bool drawLayerSTL(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size end_y_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					for (Index_Size col{ this->start_x }; col < matrix_[row].size(); ++col)
						this->outputLayer(matrix_, layer_, col, row);
					std::cout << '\n';
				}
				return true;
			}
			template<typename Matrix_>
			bool drawLayerWidthSTL(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					for (Index_Size col{ this->start_x }; col < matrix_[row].size() && col < end_x_; ++col)
						this->outputLayer(matrix_, layer_, col, row);
					std::cout << '\n';
				}
				return true;
			}

			//Normal
			template<typename Matrix_>
			bool drawNormal(const Matrix_ & matrix_, const Index_Size end_x_, const Index_Size end_y_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						this->outputSTL(matrix_, col, row);
					std::cout << '\n';
				}
				return true;
			}

			//LayerNormal
			template<typename Matrix_>
			bool drawLayerNormal(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						this->outputLayer(matrix_, layer_, col, row);
					std::cout << '\n';
				}
				return true;
			}

			//Array
			template<typename Matrix_>
			bool drawArray(const Matrix_ & matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						this->outputArray(matrix_, col, row, max_x_);
					std::cout << '\n';
				}
				return true;
			}

			//List
			template<typename Matrix_>
			bool drawList(const Matrix_& matrix_, const Index_Size end_x_, const Index_Size end_y_) const noexcept {
				::dtl::type::size row_count{}, col_count{};
				for (const auto& row : matrix_) {
					++row_count;
					if (row_count <= this->start_y) continue;
					if (end_y_ != 1 && row_count >= end_y_) break;
					col_count = 0;
					for (const auto& col : row) {
						++col_count;
						if (col_count <= this->start_x) continue;
						if (end_x_ != 1 && col_count >= end_x_) break;
						this->outputList(col);
					}
					std::cout << '\n';
				}
				return true;
			}

		public:


			///// 情報取得 /////

			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getPointX() const noexcept {
				return this->start_x;
			}
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getPointY() const noexcept {
				return this->start_y;
			}
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getWidth() const noexcept {
				return this->width;
			}
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getHeight() const noexcept {
				return this->height;
			}


			///// 生成呼び出し /////

			//STL
			template<typename Matrix_>
			bool draw(const Matrix_ & matrix_) const noexcept {
				return (this->width == 0) ? this->drawSTL(matrix_, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height) : this->drawWidthSTL(matrix_, this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height);
			}

			//LayerSTL
			template<typename Matrix_>
			bool draw(const Matrix_ & matrix_, const Index_Size layer_) const noexcept {
				return (this->width == 0) ? this->drawLayerSTL(matrix_, layer_, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height) : this->drawLayerWidthSTL(matrix_, layer_, this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height);
			}

			//Normal
			template<typename Matrix_>
			bool draw(const Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawNormal(matrix_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height);
			}

			//LayerNormal
			template<typename Matrix_>
			bool draw(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawLayerNormal(matrix_, layer_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height);
			}

			//Array
			template<typename Matrix_>
			bool drawArray(const Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawArray(matrix_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, max_x_);
			}

			//List
			template<typename Matrix_>
			bool drawList(const Matrix_& matrix_) const noexcept {
				return this->drawList(matrix_, this->start_x + this->width + 1, this->start_y + this->height + 1);
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(const Matrix_& matrix_, Args_&& ... args_) const noexcept {
				return this->draw(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& create(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->draw(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& createArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawArray(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}


			///// 消去 /////

			//始点座標Xを初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputNumber& clearPointX() noexcept {
				this->start_x = 0;
				return *this;
			}
			//始点座標Yを初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputNumber& clearPointY() noexcept {
				this->start_y = 0;
				return *this;
			}
			//範囲の大きさ(X軸方向)を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputNumber& clearWidth() noexcept {
				this->width = 0;
				return *this;
			}
			//範囲の大きさ(Y軸方向)を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputNumber& clearHeight() noexcept {
				this->height = 0;
				return *this;
			}
			//始点座標(X,Y)を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputNumber& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
			//描画範囲を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputNumber& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			//全ての値を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputNumber& clear() noexcept {
				this->clearRange();
				return *this;
			}


			///// 代入 /////

			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputNumber& setPointX(const Index_Size start_x_) noexcept {
				this->start_x = start_x_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputNumber& setPointY(const Index_Size start_y_) noexcept {
				this->start_y = start_y_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputNumber& setWidth(const Index_Size width_) noexcept {
				this->width = width_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputNumber& setHeight(const Index_Size height_) noexcept {
				this->height = height_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputNumber& setPoint(const Index_Size point_) noexcept {
				this->start_x = point_;
				this->start_y = point_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputNumber& setPoint(const Index_Size start_x_, const Index_Size start_y_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputNumber& setRange(const Index_Size start_x_, const Index_Size start_y_, const Index_Size length_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				this->width = length_;
				this->height = length_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputNumber& setRange(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				this->width = width_;
				this->height = height_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputNumber& setRange(const ::dtl::base::MatrixRange& matrix_range_) noexcept {
				this->start_x = matrix_range_.x;
				this->start_y = matrix_range_.y;
				this->width = matrix_range_.w;
				this->height = matrix_range_.h;
				return *this;
			}


			///// コンストラクタ /////
			
			constexpr OutputNumber() noexcept = default;
			constexpr explicit OutputNumber(const OutputString_ & draw_string_) noexcept
				:draw_string(draw_string_) {}
			constexpr explicit OutputNumber(const OutputString_ & before_draw_string_, const OutputString_ & draw_string_) noexcept
				:draw_string(draw_string_), before_draw_string(before_draw_string_) {}

			constexpr OutputNumber(const ::dtl::base::MatrixRange& matrix_range_)
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}
			constexpr explicit OutputNumber(const ::dtl::base::MatrixRange& matrix_range_, const OutputString_& draw_string_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h), draw_string(draw_string_) {}
			constexpr explicit OutputNumber(const ::dtl::base::MatrixRange& matrix_range_, const OutputString_& before_draw_string_, const OutputString_& draw_string_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h), draw_string(draw_string_), before_draw_string(before_draw_string_) {}

			constexpr explicit OutputNumber(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_) noexcept
				:start_x(start_x_), start_y(start_y_),
				width(width_), height(height_) {}
			constexpr explicit OutputNumber(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_, const OutputString_ & draw_string_) noexcept
				:start_x(start_x_), start_y(start_y_),
				width(width_), height(height_),
				draw_string(draw_string_) {}
			constexpr explicit OutputNumber(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_, const OutputString_ & before_draw_string_, const OutputString_ & draw_string_) noexcept
				:start_x(start_x_), start_y(start_y_),
				width(width_), height(height_),
				draw_string(draw_string_), before_draw_string(before_draw_string_) {}
		};
	}
}

#endif //Included Dungeon Template Library