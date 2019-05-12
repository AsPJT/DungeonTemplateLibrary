/*#######################################################################################
	https://github.com/Kasugaccho/DungeonTemplateLibrary

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_SAMPLE_DUNGEON_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_SAMPLE_DUNGEON_HPP

#include <Type/Forward.hpp>
#include <Base/Struct.hpp>
#include <Macros/constexpr.hpp>
#include <Macros/nodiscard.hpp>
#include <Type/SizeT.hpp>
/* ここに必要なら追加のインクルードを書く */

namespace dtl {
	inline namespace shape {

		//(ここに機能の説明を書く)
		template<typename Matrix_Int_>
		class SampleDungeon {
		private:


			///// エイリアス /////

			using Index_Size = dtl::type::size;


			///// メンバ変数(範囲指定) /////

			/* ここは基本的には変えない */

			Index_Size start_x{};
			Index_Size start_y{};
			Index_Size width{};
			Index_Size height{};


			///// メンバ変数(自由に追加・削除してよい) /////

			Matrix_Int_ draw_value{};


			///// 代入処理(自由に追加・削除してよい) /////

			template<typename Matrix_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionSTL(Matrix_&& matrix_, const Index_Size end_x_, const Index_Size end_y_) const noexcept {
				matrix_[end_y_][end_x_] = this->draw_value;
			}
			template<typename Matrix_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionArray(Matrix_&& matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_) const noexcept {
				matrix_[end_y_ * max_x_ + end_x_] = this->draw_value;
			}
			template<typename Matrix_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionLayer(Matrix_&& matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_) const noexcept {
				matrix_[end_y_][end_x_][layer_] = this->draw_value;
			}

			template<typename Matrix_, typename Function_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionSTL(Matrix_&& matrix_, const Index_Size end_x_, const Index_Size end_y_, Function_&& function_) const noexcept {
				if (function_(matrix_[end_y_][end_x_])) matrix_[end_y_][end_x_] = this->draw_value;
			}
			template<typename Matrix_, typename Function_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionArray(Matrix_&& matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Function_&& function_) const noexcept {
				if (function_(matrix_[end_y_ * max_x_ + end_x_])) matrix_[end_y_ * max_x_ + end_x_] = this->draw_value;
			}
			template<typename Matrix_, typename Function_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionLayer(Matrix_ && matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Function_ && function_) const noexcept {
				if (function_(matrix_[end_y_][end_x_][layer_])) matrix_[end_y_][end_x_][layer_] = this->draw_value;
			}


			///// 基本処理(自由に関数の中身を変えてよい) /////

			//Normal
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawNormal(Matrix_&& matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_&& ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						this->substitutionSTL(matrix_, col, row, args_...);
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawLayerNormal(Matrix_ && matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						this->substitutionLayer(matrix_, layer_, col, row, args_...);
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawArray(Matrix_ && matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						this->substitutionArray(matrix_, col, row, max_x_, args_...);
				return true;
			}

		public:


			///// 情報取得 /////

			/* ここは基本的には変えない */

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
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
				constexpr Matrix_Int_ getValue() const noexcept {
				return this->draw_value;
			}


			///// 生成呼び出し /////

			/* ここは基本的には変えない */

			//STL
			template<typename Matrix_>
			constexpr bool draw(Matrix_&& matrix_) const noexcept {
				return this->drawNormal(DUNGEON_TEMPLATE_LIBRARY_FORWARD<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, Function_ && function_) const noexcept {
				return this->drawNormal(DUNGEON_TEMPLATE_LIBRARY_FORWARD<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//LayerSTL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_) const noexcept {
				return this->drawLayerNormal(DUNGEON_TEMPLATE_LIBRARY_FORWARD<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
				return this->drawLayerNormal(DUNGEON_TEMPLATE_LIBRARY_FORWARD<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//Normal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawNormal(DUNGEON_TEMPLATE_LIBRARY_FORWARD<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawNormal(DUNGEON_TEMPLATE_LIBRARY_FORWARD<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//LayerNormal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawLayerNormal(DUNGEON_TEMPLATE_LIBRARY_FORWARD<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawLayerNormal(DUNGEON_TEMPLATE_LIBRARY_FORWARD<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//Array
			template<typename Matrix_>
			constexpr bool drawArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawArray(DUNGEON_TEMPLATE_LIBRARY_FORWARD<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, max_x_);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperatorArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawArray(DUNGEON_TEMPLATE_LIBRARY_FORWARD<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, max_x_, function_);
			}


			///// 生成呼び出しファンクタ /////

			/* ここは基本的には変えない */

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				return true;
			}


			///// ダンジョン行列生成 /////

			/* ここは基本的には変えない */

			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& create(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->draw(matrix_, DUNGEON_TEMPLATE_LIBRARY_FORWARD<Args_>(args_)...);
				return DUNGEON_TEMPLATE_LIBRARY_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& createArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawArray(matrix_, DUNGEON_TEMPLATE_LIBRARY_FORWARD<Args_>(args_)...);
				return DUNGEON_TEMPLATE_LIBRARY_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& createOperator(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperator(matrix_, DUNGEON_TEMPLATE_LIBRARY_FORWARD<Args_>(args_)...);
				return DUNGEON_TEMPLATE_LIBRARY_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& createOperatorArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperatorArray(matrix_, DUNGEON_TEMPLATE_LIBRARY_FORWARD<Args_>(args_)...);
				return DUNGEON_TEMPLATE_LIBRARY_FORWARD<Matrix_>(matrix_);
			}


			///// 消去 /////

			/* ここは基本的には変えない */

			//始点座標Xを初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SampleDungeon& clearPointX() noexcept {
				this->start_x = 0;
				return *this;
			}
			//始点座標Yを初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SampleDungeon& clearPointY() noexcept {
				this->start_y = 0;
				return *this;
			}
			//範囲の大きさ(X軸方向)を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SampleDungeon& clearWidth() noexcept {
				this->width = 0;
				return *this;
			}
			//範囲の大きさ(Y軸方向)を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SampleDungeon& clearHeight() noexcept {
				this->height = 0;
				return *this;
			}
			//塗り値を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SampleDungeon& clearValue() noexcept {
				const Matrix_Int_ new_draw_value{};
				this->draw_value = new_draw_value;
				return *this;
			}
			//始点座標(X,Y)を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SampleDungeon& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
			//描画範囲を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SampleDungeon& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			//全ての値を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SampleDungeon& clear() noexcept {
				this->clearRange();
				this->clearValue();
				return *this;
			}


			///// 代入 /////

			/* ここは基本的には変えない */

			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SampleDungeon& setPointX(const Index_Size end_x_) noexcept {
				this->start_x = end_x_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SampleDungeon& setPointY(const Index_Size end_y_) noexcept {
				this->start_y = end_y_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SampleDungeon& setWidth(const Index_Size width_) noexcept {
				this->width = width_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SampleDungeon& setHeight(const Index_Size height_) noexcept {
				this->height = height_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SampleDungeon& setValue(const Matrix_Int_ & draw_value_) noexcept {
				this->draw_value = draw_value_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SampleDungeon& setPoint(const Index_Size point_) noexcept {
				this->start_x = point_;
				this->start_y = point_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SampleDungeon& setPoint(const Index_Size end_x_, const Index_Size end_y_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SampleDungeon& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size length_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				this->width = length_;
				this->height = length_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SampleDungeon& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				this->width = width_;
				this->height = height_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				SampleDungeon& setRange(const dtl::base::MatrixRange & matrix_range_) noexcept {
				this->start_x = matrix_range_.x;
				this->start_y = matrix_range_.y;
				this->width = matrix_range_.w;
				this->height = matrix_range_.h;
				return *this;
			}


			///// コンストラクタ(一部、自由に変えてよい) /////

			/* 非範囲指定版 */

			constexpr SampleDungeon() noexcept = default; //これは固定

			constexpr explicit SampleDungeon(const Matrix_Int_ & draw_value_) noexcept
				:draw_value(draw_value_) {}

			/* 構造体での範囲指定版 */

			constexpr explicit SampleDungeon(const dtl::base::MatrixRange & matrix_range_) noexcept //これは固定
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}
			constexpr explicit SampleDungeon(const dtl::base::MatrixRange & matrix_range_, const Matrix_Int_ & draw_value_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				draw_value(draw_value_) {}
			
			/* リテラルでの範囲指定版 */

			constexpr explicit SampleDungeon(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_) {}
			constexpr explicit SampleDungeon(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_ & draw_value_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_),
				draw_value(draw_value_) {}
		};
	}
}

#endif //Included Dungeon Template Library