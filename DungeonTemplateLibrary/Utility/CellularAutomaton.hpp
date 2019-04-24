/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_CELLULAR_AUTOMATON
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_CELLULAR_AUTOMATON

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <Random/MersenneTwister32bit.hpp>
#include <Macros/nodiscard.hpp>

namespace dtl {
	inline namespace utility {

		//マスを指定した数値で埋める
		template<typename Matrix_Int_>
		class CellularAutomation {
		private:


			///// エイリアス /////

			using Index_Size = std::size_t;
			using PairSize = std::pair<Index_Size, Index_Size>;


			///// メンバ変数 /////

			Index_Size point_x{};
			Index_Size point_y{};
			Index_Size width{};
			Index_Size height{};

			template<typename Matrix_>
			constexpr inline void switchSTL(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				switch (dtl::random::mt64bit_4.get()) {
				case 0:matrix_[point_y_][point_x_] = matrix_[point_y_][point_x_ - 1]; break;
				case 1:matrix_[point_y_][point_x_] = matrix_[point_y_][point_x_ + 1]; break;
				case 2:matrix_[point_y_][point_x_] = matrix_[point_y_ - 1][point_x_]; break;
				case 3:matrix_[point_y_][point_x_] = matrix_[point_y_ + 1][point_x_]; break;
				}
			}
			template<typename Matrix_>
			constexpr inline void switchArray(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
				switch (dtl::random::mt64bit_4.get()) {
				case 0:matrix_[point_y_ * max_x_ + point_x_] = matrix_[point_y_ * max_x_ + point_x_ - 1]; break;
				case 1:matrix_[point_y_ * max_x_ + point_x_] = matrix_[point_y_ * max_x_ + point_x_ + 1]; break;
				case 2:matrix_[point_y_ * max_x_ + point_x_] = matrix_[(point_y_ - 1) * max_x_ + point_x_]; break;
				case 3:matrix_[point_y_ * max_x_ + point_x_] = matrix_[(point_y_ + 1) * max_x_ + point_x_]; break;
				}
			}
			template<typename Matrix_>
			constexpr inline void switchLayer(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				switch (dtl::random::mt64bit_4.get()) {
				case 0:matrix_[point_y_][point_x_][layer_] = matrix_[point_y_][point_x_ - 1][layer_]; break;
				case 1:matrix_[point_y_][point_x_][layer_] = matrix_[point_y_][point_x_ + 1][layer_]; break;
				case 2:matrix_[point_y_][point_x_][layer_] = matrix_[point_y_ - 1][point_x_][layer_]; break;
				case 3:matrix_[point_y_][point_x_][layer_] = matrix_[point_y_ + 1][point_x_][layer_]; break;
				}
			}


			///// 代入処理 /////

			template<typename Matrix_>
			constexpr inline void substitutionSTL(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				if (matrix_[point_y_][point_x_ - 1] == matrix_[point_y_][point_x_ + 1] && matrix_[point_y_][point_x_ + 1] == matrix_[point_y_ - 1][point_x_] && matrix_[point_y_ - 1][point_x_] == matrix_[point_y_ + 1][point_x_])
					matrix_[point_y_][point_x_] = matrix_[point_y_][point_x_ + 1];
				else this->switchSTL(matrix_, point_x_, point_y_);
			}
			template<typename Matrix_>
			constexpr inline void substitutionArray(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
				if (matrix_[point_y_ * max_x_ + point_x_ - 1] == matrix_[point_y_ * max_x_ + point_x_ + 1] && matrix_[point_y_ * max_x_ + point_x_ + 1] == matrix_[(point_y_ - 1) * max_x_ + point_x_] && matrix_[(point_y_ - 1) * max_x_ + point_x_] == matrix_[(point_y_ + 1) * max_x_ + point_x_])
					matrix_[point_y_ * max_x_ + point_x_] = matrix_[point_y_ * max_x_ + point_x_ + 1];
				else this->switchArray(matrix_, point_x_, point_y_, max_x_);
			}
			template<typename Matrix_>
			constexpr inline void substitutionLayer(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				if (matrix_[point_y_][point_x_ - 1][layer_] == matrix_[point_y_][point_x_ + 1][layer_] && matrix_[point_y_][point_x_ + 1][layer_] == matrix_[point_y_ - 1][point_x_][layer_] && matrix_[point_y_ - 1][point_x_][layer_] == matrix_[point_y_ + 1][point_x_][layer_])
					matrix_[point_y_][point_x_][layer_] = matrix_[point_y_][point_x_ + 1][layer_];
				else this->switchLayer(matrix_, layer_, point_x_, point_y_);
			}

			template<typename Matrix_, typename Function_>
			constexpr inline void substitutionSTL(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, Function_ && function_) const noexcept {
				if (matrix_[point_y_][point_x_ - 1] == matrix_[point_y_][point_x_ + 1] && matrix_[point_y_][point_x_ + 1] == matrix_[point_y_ - 1][point_x_] && matrix_[point_y_ - 1][point_x_] == matrix_[point_y_ + 1][point_x_] && function_(matrix_[point_y_][point_x_]))
					matrix_[point_y_][point_x_] = matrix_[point_y_][point_x_ + 1];
				else this->switchSTL(matrix_, point_x_, point_y_);
			}
			template<typename Matrix_, typename Function_>
			constexpr inline void substitutionArray(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Function_ && function_) const noexcept {
				if (matrix_[point_y_ * max_x_ + point_x_ - 1] == matrix_[point_y_ * max_x_ + point_x_ + 1] && matrix_[point_y_ * max_x_ + point_x_ + 1] == matrix_[(point_y_ - 1) * max_x_ + point_x_] && matrix_[(point_y_ - 1) * max_x_ + point_x_] == matrix_[(point_y_ + 1) * max_x_ + point_x_] && function_(matrix_[point_y_][point_x_]))
					matrix_[point_y_ * max_x_ + point_x_] = matrix_[point_y_ * max_x_ + point_x_ + 1];
				else this->switchArray(matrix_, point_x_, point_y_, max_x_);
			}
			template<typename Matrix_, typename Function_>
			constexpr inline void substitutionLayer(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Function_ && function_) const noexcept {
				if (matrix_[point_y_][point_x_ - 1][layer_] == matrix_[point_y_][point_x_ + 1][layer_] && matrix_[point_y_][point_x_ + 1][layer_] == matrix_[point_y_ - 1][point_x_][layer_] && matrix_[point_y_ - 1][point_x_][layer_] == matrix_[point_y_ + 1][point_x_][layer_] && function_(matrix_[point_y_][point_x_]))
					matrix_[point_y_][point_x_][layer_] = matrix_[point_y_][point_x_ + 1][layer_];
				else this->switchLayer(matrix_, layer_, point_x_, point_y_);
			}


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawSTL(Matrix_ && matrix_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->point_y + 1 }; row < point_y_ - 1; ++row)
					for (Index_Size col{ this->point_x + 1 }; col < matrix_[row].size() - 1; ++col)
						this->substitutionSTL(matrix_, col, row, args_...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawWidthSTL(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->point_y + 1 }; row < point_y_ - 1; ++row)
					for (Index_Size col{ this->point_x + 1 }; col < matrix_[row].size() - 1 && col < point_x_ - 1; ++col)
						this->substitutionSTL(matrix_, col, row, args_...);
				return true;
			}

			//LayerSTL
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawLayerSTL(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->point_y + 1 }; row < point_y_ - 1; ++row)
					for (Index_Size col{ this->point_x + 1 }; col < matrix_[row].size() - 1; ++col)
						this->substitutionLayer(matrix_, layer_, col, row, args_...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawLayerWidthSTL(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->point_y + 1 }; row < point_y_ - 1; ++row)
					for (Index_Size col{ this->point_x + 1 }; col < matrix_[row].size() - 1 && col < point_x_ - 1; ++col)
						this->substitutionLayer(matrix_, layer_, col, row, args_...);
				return true;
			}

			//Normal
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawNormal(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->point_y + 1 }; row < point_y_ - 1; ++row)
					for (Index_Size col{ this->point_x + 1 }; col < point_x_ - 1; ++col)
						this->substitutionSTL(matrix_, col, row, args_...);
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawLayerNormal(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->point_y + 1 }; row < point_y_ - 1; ++row)
					for (Index_Size col{ this->point_x + 1 }; col < point_x_ - 1; ++col)
						this->substitutionLayer(matrix_, layer_, col, row, args_...);
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawArray(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->point_y + 1 }; row < point_y_ - 1; ++row)
					for (Index_Size col{ this->point_x + 1 }; col < point_x_ - 1; ++col)
						this->substitutionArray(matrix_, col, row, max_x_, args_...);
				return true;
			}

		public:


			///// 情報取得 /////

			DTL_NODISCARD
			constexpr Index_Size getPointX() const noexcept {
				return this->point_x;
			}
			DTL_NODISCARD
			constexpr Index_Size getPointY() const noexcept {
				return this->point_y;
			}
			DTL_NODISCARD
			constexpr Index_Size getWidth() const noexcept {
				return this->width;
			}
			DTL_NODISCARD
			constexpr Index_Size getHeight() const noexcept {
				return this->height;
			}
			DTL_NODISCARD
			constexpr Matrix_Int_ getValue() const noexcept {
				return this->draw_value;
			}


			///// 生成呼び出し /////

			//STL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_) const noexcept {
				return (this->width == 0) ? this->drawSTL(std::forward<Matrix_>(matrix_), (this->height == 0 || this->point_y + this->height >= matrix_.size()) ? matrix_.size() : this->point_y + this->height) : this->drawWidthSTL(matrix_, this->point_x + this->width, (this->height == 0 || this->point_y + this->height >= matrix_.size()) ? matrix_.size() : this->point_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, Function_ && function_) const noexcept {
				return (this->width == 0) ? this->drawSTL(std::forward<Matrix_>(matrix_), (this->height == 0 || this->point_y + this->height >= matrix_.size()) ? matrix_.size() : this->point_y + this->height, function_) : this->drawWidthSTL(matrix_, this->point_x + this->width, (this->height == 0 || this->point_y + this->height >= matrix_.size()) ? matrix_.size() : this->point_y + this->height, function_);
			}

			//LayerSTL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_) const noexcept {
				return (this->width == 0) ? this->drawLayerSTL(std::forward<Matrix_>(matrix_), layer_, (this->height == 0 || this->point_y + this->height >= matrix_.size()) ? matrix_.size() : this->point_y + this->height) : this->drawLayerWidthSTL(matrix_, layer_, this->point_x + this->width, (this->height == 0 || this->point_y + this->height >= matrix_.size()) ? matrix_.size() : this->point_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
				return (this->width == 0) ? this->drawLayerSTL(std::forward<Matrix_>(matrix_), layer_, (this->height == 0 || this->point_y + this->height >= matrix_.size()) ? matrix_.size() : this->point_y + this->height, function_) : this->drawLayerWidthSTL(matrix_, layer_, this->point_x + this->width, (this->height == 0 || this->point_y + this->height >= matrix_.size()) ? matrix_.size() : this->point_y + this->height, function_);
			}

			//Normal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawNormal(std::forward<Matrix_>(matrix_), (this->width == 0 || this->point_x + this->width >= max_x_) ? max_x_ : this->point_x + this->width, (this->height == 0 || this->point_y + this->height >= max_y_) ? max_y_ : this->point_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawNormal(std::forward<Matrix_>(matrix_), (this->width == 0 || this->point_x + this->width >= max_x_) ? max_x_ : this->point_x + this->width, (this->height == 0 || this->point_y + this->height >= max_y_) ? max_y_ : this->point_y + this->height, function_);
			}

			//LayerNormal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (this->width == 0 || this->point_x + this->width >= max_x_) ? max_x_ : this->point_x + this->width, (this->height == 0 || this->point_y + this->height >= max_y_) ? max_y_ : this->point_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (this->width == 0 || this->point_x + this->width >= max_x_) ? max_x_ : this->point_x + this->width, (this->height == 0 || this->point_y + this->height >= max_y_) ? max_y_ : this->point_y + this->height, function_);
			}

			//Array
			template<typename Matrix_>
			constexpr bool drawArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawArray(std::forward<Matrix_>(matrix_), (this->width == 0 || this->point_x + this->width >= max_x_) ? max_x_ : this->point_x + this->width, (this->height == 0 || this->point_y + this->height >= max_y_) ? max_y_ : this->point_y + this->height, max_x_);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperatorArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawArray(std::forward<Matrix_>(matrix_), (this->width == 0 || this->point_x + this->width >= max_x_) ? max_x_ : this->point_x + this->width, (this->height == 0 || this->point_y + this->height >= max_y_) ? max_y_ : this->point_y + this->height, max_x_, function_);
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				return this->draw(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

			template<typename Matrix_, typename ...Args_>
			constexpr Matrix_&& create(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->draw(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr Matrix_&& createArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr Matrix_&& createOperator(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperator(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr Matrix_&& createOperatorArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}


			///// 消去 /////

			//始点座標Xを初期値に戻す
			constexpr CellularAutomation& clearPointX() noexcept {
				this->point_x = 0;
				return *this;
			}
			//始点座標Yを初期値に戻す
			constexpr CellularAutomation& clearPointY() noexcept {
				this->point_y = 0;
				return *this;
			}
			//範囲の大きさ(X軸方向)を初期値に戻す
			constexpr CellularAutomation& clearWidth() noexcept {
				this->width = 0;
				return *this;
			}
			//範囲の大きさ(Y軸方向)を初期値に戻す
			constexpr CellularAutomation& clearHeight() noexcept {
				this->height = 0;
				return *this;
			}
			//始点座標(X,Y)を初期値に戻す
			constexpr CellularAutomation& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
			//描画範囲を初期値に戻す
			constexpr CellularAutomation& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			//全ての値を初期値に戻す
			constexpr CellularAutomation& clear() noexcept {
				this->clearRange();
				return *this;
			}


			///// 代入 /////

			constexpr CellularAutomation& setPointX(const Index_Size point_x_) noexcept {
				this->point_x = point_x_;
				return *this;
			}
			constexpr CellularAutomation& setPointY(const Index_Size point_y_) noexcept {
				this->point_y = point_y_;
				return *this;
			}
			constexpr CellularAutomation& setWidth(const Index_Size width_) noexcept {
				this->width = width_;
				return *this;
			}
			constexpr CellularAutomation& setHeight(const Index_Size height_) noexcept {
				this->height = height_;
				return *this;
			}
			constexpr CellularAutomation& setPoint(const Index_Size point_) noexcept {
				this->point_x = point_;
				this->point_y = point_;
				return *this;
			}
			constexpr CellularAutomation& setPoint(const Index_Size point_x_, const Index_Size point_y_) noexcept {
				this->point_x = point_x_;
				this->point_y = point_y_;
				return *this;
			}
			constexpr CellularAutomation& setRange(const Index_Size point_x_, const Index_Size point_y_, const Index_Size length_) noexcept {
				this->point_x = point_x_;
				this->point_y = point_y_;
				this->width = length_;
				this->height = length_;
				return *this;
			}
			constexpr CellularAutomation& setRange(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->point_x = point_x_;
				this->point_y = point_y_;
				this->width = width_;
				this->height = height_;
				return *this;
			}
			constexpr CellularAutomation& setRange(const dtl::base::MatrixRange & matrix_range_) noexcept {
				this->point_x = matrix_range_.x;
				this->point_y = matrix_range_.y;
				this->width = matrix_range_.w;
				this->height = matrix_range_.h;
				return *this;
			}


			///// コンストラクタ /////

			constexpr CellularAutomation() noexcept = default;
			constexpr explicit CellularAutomation(const dtl::base::MatrixRange & matrix_range_) noexcept
				:point_x(matrix_range_.x), point_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}
			constexpr explicit CellularAutomation(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
				:point_x(point_x_), point_y(point_y_),
				width(width_), height(height_) {}
		};
	}
}

#endif //Included Dungeon Template Library