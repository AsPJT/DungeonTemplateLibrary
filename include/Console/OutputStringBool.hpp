/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_OUTPUT_STRING_BOOL_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_OUTPUT_STRING_BOOL_HPP

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <iostream>
#include <string>
#include <Base/Struct.hpp>
#include <Macros/nodiscard.hpp>
#include <Macros/constexpr.hpp>

namespace dtl {
	inline namespace console {

		//四角形の生成
		template<typename Matrix_Int_, typename OutputString_ = std::string>
		class OutputStringBool {
		private:


			///// エイリアス /////

			using Index_Size = std::size_t;
			


			///// メンバ変数 /////

			Index_Size start_x{};
			Index_Size start_y{};
			Index_Size width{};
			Index_Size height{};
			OutputString_ false_string{};
			OutputString_ true_string{};


			///// 代入処理 /////

			template<typename Matrix_>
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr inline Matrix_Int_ outputSTL(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				return matrix_[point_y_][point_x_];
			}
			template<typename Matrix_>
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr inline Matrix_Int_ outputArray(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
				return matrix_[point_y_ * max_x_ + point_x_];
			}
			template<typename Matrix_>
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr inline Matrix_Int_ outputLayer(const Matrix_& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				return matrix_[point_y_][point_x_][layer_];
			}

			template<typename Matrix_, typename Function_>
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr inline Matrix_Int_ outputSTL(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_, Function_&& function_) const noexcept {
				return function_(matrix_[point_y_][point_x_]);
			}
			template<typename Matrix_, typename Function_>
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr inline Matrix_Int_ outputArray(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Function_&& function_) const noexcept {
				return function_(matrix_[point_y_ * max_x_ + point_x_]);
			}
			template<typename Matrix_, typename Function_>
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr inline Matrix_Int_ outputLayer(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Function_ && function_) const noexcept {
				return function_(matrix_[point_y_][point_x_][layer_]);
			}


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename ...Args_>
			bool drawSTL(const Matrix_ & matrix_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					for (Index_Size col{ this->start_x }; col < matrix_[row].size(); ++col)
						std::cout << ((this->outputSTL(matrix_, col, row, args_...)) ? this->true_string : this->false_string);
					std::cout << '\n';
				}
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			bool drawWidthSTL(const Matrix_ & matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					for (Index_Size col{ this->start_x }; col < matrix_[row].size() && col < end_x_; ++col)
						std::cout << ((this->outputSTL(matrix_, col, row, args_...)) ? this->true_string : this->false_string);
					std::cout << '\n';
				}
				return true;
			}

			//LayerSTL
			template<typename Matrix_, typename ...Args_>
			bool drawLayerSTL(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					for (Index_Size col{ this->start_x }; col < matrix_[row].size(); ++col)
						std::cout << ((this->outputLayer(matrix_, layer_, col, row, args_...)) ? this->true_string : this->false_string);
					std::cout << '\n';
				}
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			bool drawLayerWidthSTL(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					for (Index_Size col{ this->start_x }; col < matrix_[row].size() && col < end_x_; ++col)
						std::cout << ((this->outputLayer(matrix_, layer_, col, row, args_...)) ? this->true_string : this->false_string);
					std::cout << '\n';
				}
				return true;
			}

			//Normal
			template<typename Matrix_, typename ...Args_>
			bool drawNormal(const Matrix_ & matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						std::cout << ((this->outputSTL(matrix_, col, row, args_...)) ? this->true_string : this->false_string);
					std::cout << '\n';
				}
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
			bool drawLayerNormal(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						std::cout << ((this->outputLayer(matrix_, layer_, col, row, args_...)) ? this->true_string : this->false_string);
					std::cout << '\n';
				}
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			bool drawArray(const Matrix_ & matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						std::cout << ((this->outputArray(matrix_, col, row, max_x_, args_...)) ? this->true_string : this->false_string);
					std::cout << '\n';
				}
				return true;
			}

		public:


			///// 情報取得 /////

			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr Index_Size getPointX() const noexcept {
				return this->start_x;
			}
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr Index_Size getPointY() const noexcept {
				return this->start_y;
			}
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr Index_Size getWidth() const noexcept {
				return this->width;
			}
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr Index_Size getHeight() const noexcept {
				return this->height;
			}


			///// 生成呼び出し /////

			//STL
			template<typename Matrix_>
			bool draw(const Matrix_ & matrix_) const noexcept {
				return (this->width == 0) ? this->drawSTL(matrix_, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height) : this->drawWidthSTL(matrix_, this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			bool drawOperator(const Matrix_ & matrix_, Function_ && function_) const noexcept {
				return (this->width == 0) ? this->drawSTL(matrix_, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_) : this->drawWidthSTL(matrix_, this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//LayerSTL
			template<typename Matrix_>
			bool draw(const Matrix_ & matrix_, const Index_Size layer_) const noexcept {
				return (this->width == 0) ? this->drawLayerSTL(matrix_, layer_, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height) : this->drawLayerWidthSTL(matrix_, layer_, this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			bool drawOperator(const Matrix_ & matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
				return (this->width == 0) ? this->drawLayerSTL(matrix_, layer_, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_) : this->drawLayerWidthSTL(matrix_, layer_, this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//Normal
			template<typename Matrix_>
			bool draw(const Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawNormal(matrix_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			bool drawOperator(const Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawNormal(matrix_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//LayerNormal
			template<typename Matrix_>
			bool draw(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawLayerNormal(matrix_, layer_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			bool drawOperator(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawLayerNormal(matrix_, layer_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//Array
			template<typename Matrix_>
			bool drawArray(const Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawArray(matrix_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, max_x_);
			}
			template<typename Matrix_, typename Function_>
			bool drawOperatorArray(const Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawArray(matrix_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, max_x_, function_);
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(const Matrix_& matrix_, Args_&& ... args_) const noexcept {
				return this->draw(matrix_, std::forward<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& create(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->draw(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& createArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& createOperator(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperator(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& createOperatorArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}


			///// 消去 /////

			//始点座標Xを初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputStringBool& clearPointX() noexcept {
				this->start_x = 0;
				return *this;
			}
			//始点座標Yを初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputStringBool& clearPointY() noexcept {
				this->start_y = 0;
				return *this;
			}
			//範囲の大きさ(X軸方向)を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputStringBool& clearWidth() noexcept {
				this->width = 0;
				return *this;
			}
			//範囲の大きさ(Y軸方向)を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputStringBool& clearHeight() noexcept {
				this->height = 0;
				return *this;
			}
			//始点座標(X,Y)を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputStringBool& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
			//描画範囲を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputStringBool& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			//全ての値を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputStringBool& clear() noexcept {
				this->clearRange();
				return *this;
			}


			///// 代入 /////

			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputStringBool& setPointX(const Index_Size start_x_) noexcept {
				this->start_x = start_x_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputStringBool& setPointY(const Index_Size start_y_) noexcept {
				this->start_y = start_y_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputStringBool& setWidth(const Index_Size width_) noexcept {
				this->width = width_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputStringBool& setHeight(const Index_Size height_) noexcept {
				this->height = height_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputStringBool& setPoint(const Index_Size point_) noexcept {
				this->start_x = point_;
				this->start_y = point_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputStringBool& setPoint(const Index_Size start_x_, const Index_Size start_y_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputStringBool& setRange(const Index_Size start_x_, const Index_Size start_y_, const Index_Size length_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				this->width = length_;
				this->height = length_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputStringBool& setRange(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				this->width = width_;
				this->height = height_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputStringBool& setRange(const dtl::base::MatrixRange& matrix_range_) noexcept {
				this->start_x = matrix_range_.x;
				this->start_y = matrix_range_.y;
				this->width = matrix_range_.w;
				this->height = matrix_range_.h;
				return *this;
			}


			///// コンストラクタ /////

			constexpr OutputStringBool() noexcept = default;
			constexpr explicit OutputStringBool(const OutputString_ & true_string_) noexcept
				:true_string(true_string_) {}
			constexpr explicit OutputStringBool(const OutputString_ & true_string_, const OutputString_ & false_string_) noexcept
				:false_string(false_string_), true_string(true_string_) {}

			constexpr OutputStringBool(const dtl::base::MatrixRange& matrix_range_)
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}
			constexpr explicit OutputStringBool(const dtl::base::MatrixRange& matrix_range_, const OutputString_& true_string_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				true_string(true_string_) {}
			constexpr explicit OutputStringBool(const dtl::base::MatrixRange& matrix_range_, const OutputString_& true_string_, const OutputString_& false_string_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				false_string(false_string_), true_string(true_string_) {}

			constexpr explicit OutputStringBool(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_) noexcept
				:start_x(start_x_), start_y(start_y_),
				width(width_), height(height_) {}
			constexpr explicit OutputStringBool(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_, const OutputString_ & true_string_) noexcept
				:start_x(start_x_), start_y(start_y_),
				width(width_), height(height_),
				true_string(true_string_) {}
			constexpr explicit OutputStringBool(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_, const OutputString_ & true_string_, const OutputString_ & false_string_) noexcept
				:start_x(start_x_), start_y(start_y_),
				width(width_), height(height_),
				false_string(false_string_), true_string(true_string_) {}
		};
	}
}

#endif //Included Dungeon Template Library