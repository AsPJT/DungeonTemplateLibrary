/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RETOUCH_BURY_POINT_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RETOUCH_BURY_POINT_HPP

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <Macros/nodiscard.hpp>
#include <Macros/constexpr.hpp>

namespace dtl {
	inline namespace retouch {

		//マスを指定した数値で埋める
		template<typename Matrix_Int_>
		class BuryPoint {
		private:


			///// エイリアス /////

			using Index_Size = std::size_t;
			


			///// メンバ変数 /////

			Index_Size start_x{};
			Index_Size start_y{};
			Index_Size width{};
			Index_Size height{};


			///// 代入処理 /////

			template<typename Matrix_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionSTL(Matrix_&& matrix_, const Index_Size end_x_, const Index_Size end_y_) const noexcept {
				if (matrix_[end_y_][end_x_] != matrix_[end_y_][end_x_ - 1] && matrix_[end_y_][end_x_] != matrix_[end_y_][end_x_ + 1] && matrix_[end_y_][end_x_] != matrix_[end_y_ - 1][end_x_] && matrix_[end_y_][end_x_] != matrix_[end_y_ + 1][end_x_])
					matrix_[end_y_][end_x_] = matrix_[end_y_][end_x_ + 1];
			}
			template<typename Matrix_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionArray(Matrix_ && matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_) const noexcept {
				if (matrix_[end_y_ * max_x_ + end_x_] != matrix_[end_y_ * max_x_ + end_x_ - 1] && matrix_[end_y_ * max_x_ + end_x_] != matrix_[end_y_ * max_x_ + end_x_ + 1] && matrix_[end_y_ * max_x_ + end_x_] != matrix_[end_y_ - 1 * max_x_ + end_x_] && matrix_[end_y_ * max_x_ + end_x_] != matrix_[end_y_ + 1 * max_x_ + end_x_])
					matrix_[end_y_ * max_x_ + end_x_] = matrix_[end_y_ * max_x_ + end_x_ + 1];
			}
			template<typename Matrix_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionLayer(Matrix_ && matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_) const noexcept {
				if (matrix_[end_y_][end_x_][layer_] != matrix_[end_y_][end_x_ - 1][layer_] && matrix_[end_y_][end_x_][layer_] != matrix_[end_y_][end_x_ + 1][layer_] && matrix_[end_y_][end_x_][layer_] != matrix_[end_y_ - 1][end_x_][layer_] && matrix_[end_y_][end_x_][layer_] != matrix_[end_y_ + 1][end_x_][layer_])
					matrix_[end_y_][end_x_][layer_] = matrix_[end_y_][end_x_ + 1][layer_];
			}

			template<typename Matrix_, typename Function_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionSTL(Matrix_ && matrix_, const Index_Size end_x_, const Index_Size end_y_, Function_ && function_) const noexcept {
				if (matrix_[end_y_][end_x_] != matrix_[end_y_][end_x_ - 1] && matrix_[end_y_][end_x_] != matrix_[end_y_][end_x_ + 1] && matrix_[end_y_][end_x_] != matrix_[end_y_ - 1][end_x_] && matrix_[end_y_][end_x_] != matrix_[end_y_ + 1][end_x_] && function_(matrix_[end_y_][end_x_]))
					matrix_[end_y_][end_x_] = matrix_[end_y_][end_x_ + 1];
			}
			template<typename Matrix_, typename Function_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionArray(Matrix_ && matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Function_ && function_) const noexcept {
				if (matrix_[end_y_ * max_x_ + end_x_] != matrix_[end_y_ * max_x_ + end_x_ - 1] && matrix_[end_y_ * max_x_ + end_x_] != matrix_[end_y_ * max_x_ + end_x_ + 1] && matrix_[end_y_ * max_x_ + end_x_] != matrix_[end_y_ - 1 * max_x_ + end_x_] && matrix_[end_y_ * max_x_ + end_x_] != matrix_[end_y_ + 1 * max_x_ + end_x_] && function_(matrix_[end_y_][end_x_]))
					matrix_[end_y_ * max_x_ + end_x_] = matrix_[end_y_ * max_x_ + end_x_ + 1];
			}
			template<typename Matrix_, typename Function_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionLayer(Matrix_ && matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Function_ && function_) const noexcept {
				if (matrix_[end_y_][end_x_][layer_] != matrix_[end_y_][end_x_ - 1][layer_] && matrix_[end_y_][end_x_][layer_] != matrix_[end_y_][end_x_ + 1][layer_] && matrix_[end_y_][end_x_][layer_] != matrix_[end_y_ - 1][end_x_][layer_] && matrix_[end_y_][end_x_][layer_] != matrix_[end_y_ + 1][end_x_][layer_] && function_(matrix_[end_y_][end_x_]))
					matrix_[end_y_][end_x_][layer_] = matrix_[end_y_][end_x_ + 1][layer_];
			}


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawSTL(Matrix_ && matrix_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y + 1 }; row < end_y_ - 1; ++row)
					for (Index_Size col{ this->start_x + 1 }; col < matrix_[row].size() - 1; ++col)
						this->substitutionSTL(matrix_, col, row, args_...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawWidthSTL(Matrix_ && matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y + 1 }; row < end_y_ - 1; ++row)
					for (Index_Size col{ this->start_x + 1 }; col < matrix_[row].size() - 1 && col < end_x_ - 1; ++col)
						this->substitutionSTL(matrix_, col, row, args_...);
				return true;
			}

			//LayerSTL
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawLayerSTL(Matrix_ && matrix_, const Index_Size layer_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y + 1 }; row < end_y_ - 1; ++row)
					for (Index_Size col{ this->start_x + 1 }; col < matrix_[row].size() - 1; ++col)
						this->substitutionLayer(matrix_, layer_, col, row, args_...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawLayerWidthSTL(Matrix_ && matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y + 1 }; row < end_y_ - 1; ++row)
					for (Index_Size col{ this->start_x + 1 }; col < matrix_[row].size() - 1 && col < end_x_ - 1; ++col)
						this->substitutionLayer(matrix_, layer_, col, row, args_...);
				return true;
			}

			//Normal
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawNormal(Matrix_ && matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y + 1 }; row < end_y_ - 1; ++row)
					for (Index_Size col{ this->start_x + 1 }; col < end_x_ - 1; ++col)
						this->substitutionSTL(matrix_, col, row, args_...);
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawLayerNormal(Matrix_ && matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y + 1 }; row < end_y_ - 1; ++row)
					for (Index_Size col{ this->start_x + 1 }; col < end_x_ - 1; ++col)
						this->substitutionLayer(matrix_, layer_, col, row, args_...);
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawArray(Matrix_ && matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y + 1 }; row < end_y_ - 1; ++row)
					for (Index_Size col{ this->start_x + 1 }; col < end_x_ - 1; ++col)
						this->substitutionArray(matrix_, col, row, max_x_, args_...);
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
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr Matrix_Int_ getValue() const noexcept {
				return this->draw_value;
			}


			///// 生成呼び出し /////

			//STL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_) const noexcept {
				return (this->width == 0) ? this->drawSTL(std::forward<Matrix_>(matrix_), (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height) : this->drawWidthSTL(matrix_, this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, Function_ && function_) const noexcept {
				return (this->width == 0) ? this->drawSTL(std::forward<Matrix_>(matrix_), (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_) : this->drawWidthSTL(matrix_, this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//LayerSTL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_) const noexcept {
				return (this->width == 0) ? this->drawLayerSTL(std::forward<Matrix_>(matrix_), layer_, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height) : this->drawLayerWidthSTL(matrix_, layer_, this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
				return (this->width == 0) ? this->drawLayerSTL(std::forward<Matrix_>(matrix_), layer_, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_) : this->drawLayerWidthSTL(matrix_, layer_, this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//Normal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawNormal(std::forward<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawNormal(std::forward<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//LayerNormal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//Array
			template<typename Matrix_>
			constexpr bool drawArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawArray(std::forward<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, max_x_);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperatorArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawArray(std::forward<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, max_x_, function_);
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				return this->draw(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
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
				BuryPoint& clearPointX() noexcept {
				this->start_x = 0;
				return *this;
			}
			//始点座標Yを初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				BuryPoint& clearPointY() noexcept {
				this->start_y = 0;
				return *this;
			}
			//範囲の大きさ(X軸方向)を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				BuryPoint& clearWidth() noexcept {
				this->width = 0;
				return *this;
			}
			//範囲の大きさ(Y軸方向)を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				BuryPoint& clearHeight() noexcept {
				this->height = 0;
				return *this;
			}
			//始点座標(X,Y)を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				BuryPoint& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
			//描画範囲を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				BuryPoint& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			//全ての値を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				BuryPoint& clear() noexcept {
				this->clearRange();
				return *this;
			}


			///// 代入 /////

			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				BuryPoint& setPointX(const Index_Size end_x_) noexcept {
				this->start_x = end_x_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				BuryPoint& setPointY(const Index_Size end_y_) noexcept {
				this->start_y = end_y_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				BuryPoint& setWidth(const Index_Size width_) noexcept {
				this->width = width_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				BuryPoint& setHeight(const Index_Size height_) noexcept {
				this->height = height_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				BuryPoint& setPoint(const Index_Size point_) noexcept {
				this->start_x = point_;
				this->start_y = point_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				BuryPoint& setPoint(const Index_Size end_x_, const Index_Size end_y_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				BuryPoint& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size length_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				this->width = length_;
				this->height = length_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				BuryPoint& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				this->width = width_;
				this->height = height_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				BuryPoint& setRange(const dtl::base::MatrixRange& matrix_range_) noexcept {
				this->start_x = matrix_range_.x;
				this->start_y = matrix_range_.y;
				this->width = matrix_range_.w;
				this->height = matrix_range_.h;
				return *this;
			}


			///// コンストラクタ /////

			constexpr BuryPoint() noexcept = default;
			constexpr explicit BuryPoint(const dtl::base::MatrixRange& matrix_range_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}
			constexpr explicit BuryPoint(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_) {}
		};
	}
}

#endif //Included Dungeon Template Library