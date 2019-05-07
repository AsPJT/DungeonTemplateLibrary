/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_OUTPUT_VIEW_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_OUTPUT_VIEW_HPP

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <iostream>
#include <string>
#include <Macros/nodiscard.hpp>
#include <Macros/constexpr.hpp>

namespace dtl {
	inline namespace console {

		//四角形の生成
		template<typename Matrix_Int_, typename OutputView_ = std::size_t>
		class OutputView {
		private:


			///// エイリアス /////

			using Index_Size = std::size_t;
			


			///// メンバ変数 /////

			Index_Size start_x{};
			Index_Size start_y{};
			Index_Size width{};
			Index_Size height{};

			OutputView_ view_width{};
			OutputView_ view_height{};


			///// 代入処理 /////

			template<typename Matrix_, typename Function_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void outputSTL(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_, Function_&& function_) const noexcept {
				function_(matrix_[point_y_][point_x_], static_cast<OutputView_>(point_x_), static_cast<OutputView_>(point_y_), this->view_width, this->view_height);
			}
			template<typename Matrix_, typename Function_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void outputArray(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Function_&& function_) const noexcept {
				function_(matrix_[point_y_ * max_x_ + point_x_], static_cast<OutputView_>(point_x_), static_cast<OutputView_>(point_y_), this->view_width, this->view_height);
			}
			template<typename Matrix_, typename Function_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void outputLayer(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Function_ && function_) const noexcept {
				function_(matrix_[point_y_][point_x_][layer_], static_cast<OutputView_>(point_x_), static_cast<OutputView_>(point_y_), this->view_width, this->view_height);
			}


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename ...Args_>
			bool drawSTL(const Matrix_ & matrix_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < matrix_[row].size(); ++col)
						this->outputSTL(matrix_, col, row, args_...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			bool drawWidthSTL(const Matrix_ & matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < matrix_[row].size() && col < end_x_; ++col)
						this->outputSTL(matrix_, col, row, args_...);
				return true;
			}

			//LayerSTL
			template<typename Matrix_, typename ...Args_>
			bool drawLayerSTL(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < matrix_[row].size(); ++col)
						this->outputLayer(matrix_, layer_, col, row, args_...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			bool drawLayerWidthSTL(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < matrix_[row].size() && col < end_x_; ++col)
						this->outputLayer(matrix_, layer_, col, row, args_...);
				return true;
			}

			//Normal
			template<typename Matrix_, typename ...Args_>
			bool drawNormal(const Matrix_ & matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						this->outputSTL(matrix_, col, row, args_...);
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
			bool drawLayerNormal(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						this->outputLayer(matrix_, layer_, col, row, args_...);
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			bool drawArray(const Matrix_ & matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						this->outputArray(matrix_, col, row, max_x_, args_...);
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
			template<typename Matrix_, typename Function_>
			bool draw(const Matrix_ & matrix_, Function_ && function_) const noexcept {
				return (this->width == 0) ? this->drawSTL(matrix_, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_) : this->drawWidthSTL(matrix_, this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//LayerSTL
			template<typename Matrix_, typename Function_>
			bool draw(const Matrix_ & matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
				return (this->width == 0) ? this->drawLayerSTL(matrix_, layer_, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_) : this->drawLayerWidthSTL(matrix_, layer_, this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//Normal
			template<typename Matrix_, typename Function_>
			bool draw(const Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawNormal(matrix_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//LayerNormal
			template<typename Matrix_, typename Function_>
			bool draw(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawLayerNormal(matrix_, layer_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//Array
			template<typename Matrix_, typename Function_>
			bool drawArray(const Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawArray(matrix_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, max_x_, function_);
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(const Matrix_ & matrix_, Args_ && ... args_) const noexcept {
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


			///// 消去 /////

			//始点座標Xを初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputView& clearPointX() noexcept {
				this->start_x = 0;
				return *this;
			}
			//始点座標Yを初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputView& clearPointY() noexcept {
				this->start_y = 0;
				return *this;
			}
			//範囲の大きさ(X軸方向)を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputView& clearWidth() noexcept {
				this->width = 0;
				return *this;
			}
			//範囲の大きさ(Y軸方向)を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputView& clearHeight() noexcept {
				this->height = 0;
				return *this;
			}
			//始点座標(X,Y)を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputView& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
			//描画範囲を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputView& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			//全ての値を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputView& clear() noexcept {
				this->clearRange();
				return *this;
			}


			///// 代入 /////

			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputView& setPointX(const Index_Size start_x_) noexcept {
				this->start_x = start_x_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputView& setPointY(const Index_Size start_y_) noexcept {
				this->start_y = start_y_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputView& setWidth(const Index_Size width_) noexcept {
				this->width = width_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputView& setHeight(const Index_Size height_) noexcept {
				this->height = height_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputView& setPoint(const Index_Size point_) noexcept {
				this->start_x = point_;
				this->start_y = point_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputView& setPoint(const Index_Size start_x_, const Index_Size start_y_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputView& setRange(const Index_Size start_x_, const Index_Size start_y_, const Index_Size length_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				this->width = length_;
				this->height = length_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputView& setRange(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				this->width = width_;
				this->height = height_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				OutputView& setRange(const dtl::base::MatrixRange& matrix_range_) noexcept {
				this->start_x = matrix_range_.x;
				this->start_y = matrix_range_.y;
				this->width = matrix_range_.w;
				this->height = matrix_range_.h;
				return *this;
			}


			///// コンストラクタ /////

			constexpr OutputView() noexcept = default;
			constexpr explicit OutputView(const OutputView_& view_) noexcept
				:view_width(view_), view_height(view_) {}
			constexpr explicit OutputView(const OutputView_& view_width_, const OutputView_& view_height_) noexcept
				:view_width(view_width_), view_height(view_height_) {}
			constexpr explicit OutputView(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_) noexcept
				:start_x(start_x_), start_y(start_y_),
				width(width_), height(height_) {}
			constexpr explicit OutputView(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_, const OutputView_& view_) noexcept
				:start_x(start_x_), start_y(start_y_),
				width(width_), height(height_),
				view_width(view_), view_height(view_) {}
			constexpr explicit OutputView(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_, const OutputView_& view_width_, const OutputView_& view_height_) noexcept
				:start_x(start_x_), start_y(start_y_),
				width(width_), height(height_),
				view_width(view_width_), view_height(view_height_) {}
		};
	}
}

#endif //Included Dungeon Template Library