/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RETOUCH_BURY_POINT
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RETOUCH_BURY_POINT

/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>

namespace dtl {
	inline namespace retouch {

		//マスを指定した数値で埋める
		template<typename Matrix_Int_>
		class BuryPoint {
		private:


			///// エイリアス /////

			using Index_Size = std::size_t;
			using PairSize = std::pair<Index_Size, Index_Size>;


			///// メンバ変数 /////

			Index_Size point_x{};
			Index_Size point_y{};
			Index_Size width{};
			Index_Size height{};


			///// 代入処理 /////

			template<typename Matrix_>
			constexpr inline void substitutionSTL(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				if (matrix_[point_y_][point_x_] != matrix_[point_y_][point_x_ - 1] && matrix_[point_y_][point_x_] != matrix_[point_y_][point_x_ + 1] && matrix_[point_y_][point_x_] != matrix_[point_y_ - 1][point_x_] && matrix_[point_y_][point_x_] != matrix_[point_y_ + 1][point_x_])
					matrix_[point_y_][point_x_] = matrix_[point_y_][point_x_ + 1];
			}
			template<typename Matrix_>
			constexpr inline void substitutionArray(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
				if (matrix_[point_y_ * max_x_ + point_x_] != matrix_[point_y_ * max_x_ + point_x_ - 1] && matrix_[point_y_ * max_x_ + point_x_] != matrix_[point_y_ * max_x_ + point_x_ + 1] && matrix_[point_y_ * max_x_ + point_x_] != matrix_[point_y_ - 1 * max_x_ + point_x_] && matrix_[point_y_ * max_x_ + point_x_] != matrix_[point_y_ + 1 * max_x_ + point_x_])
					matrix_[point_y_ * max_x_ + point_x_] = matrix_[point_y_ * max_x_ + point_x_ + 1];
			}
			template<typename Matrix_>
			constexpr inline void substitutionLayer(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				if (matrix_[point_y_][point_x_][layer_] != matrix_[point_y_][point_x_ - 1][layer_] && matrix_[point_y_][point_x_][layer_] != matrix_[point_y_][point_x_ + 1][layer_] && matrix_[point_y_][point_x_][layer_] != matrix_[point_y_ - 1][point_x_][layer_] && matrix_[point_y_][point_x_][layer_] != matrix_[point_y_ + 1][point_x_][layer_])
					matrix_[point_y_][point_x_][layer_] = matrix_[point_y_][point_x_ + 1][layer_];
			}

			template<typename Matrix_, typename Function_>
			constexpr inline void substitutionSTL(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, Function_ && function_) const noexcept {
				if (matrix_[point_y_][point_x_] != matrix_[point_y_][point_x_ - 1] && matrix_[point_y_][point_x_] != matrix_[point_y_][point_x_ + 1] && matrix_[point_y_][point_x_] != matrix_[point_y_ - 1][point_x_] && matrix_[point_y_][point_x_] != matrix_[point_y_ + 1][point_x_] && function_(matrix_[point_y_][point_x_]))
					matrix_[point_y_][point_x_] = matrix_[point_y_][point_x_ + 1];
			}
			template<typename Matrix_, typename Function_>
			constexpr inline void substitutionArray(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Function_ && function_) const noexcept {
				if (matrix_[point_y_ * max_x_ + point_x_] != matrix_[point_y_ * max_x_ + point_x_ - 1] && matrix_[point_y_ * max_x_ + point_x_] != matrix_[point_y_ * max_x_ + point_x_ + 1] && matrix_[point_y_ * max_x_ + point_x_] != matrix_[point_y_ - 1 * max_x_ + point_x_] && matrix_[point_y_ * max_x_ + point_x_] != matrix_[point_y_ + 1 * max_x_ + point_x_] && function_(matrix_[point_y_][point_x_]))
					matrix_[point_y_ * max_x_ + point_x_] = matrix_[point_y_ * max_x_ + point_x_ + 1];
			}
			template<typename Matrix_, typename Function_>
			constexpr inline void substitutionLayer(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Function_ && function_) const noexcept {
				if (matrix_[point_y_][point_x_][layer_] != matrix_[point_y_][point_x_ - 1][layer_] && matrix_[point_y_][point_x_][layer_] != matrix_[point_y_][point_x_ + 1][layer_] && matrix_[point_y_][point_x_][layer_] != matrix_[point_y_ - 1][point_x_][layer_] && matrix_[point_y_][point_x_][layer_] != matrix_[point_y_ + 1][point_x_][layer_] && function_(matrix_[point_y_][point_x_]))
					matrix_[point_y_][point_x_][layer_] = matrix_[point_y_][point_x_ + 1][layer_];
			}


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawSTL(Matrix_ && matrix_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ point_y + 1 }; row < point_y_ - 1; ++row)
					for (Index_Size col{ point_x + 1 }; col < matrix_[row].size() - 1; ++col)
						this->substitutionSTL(matrix_, col, row, args_...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawWidthSTL(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ point_y + 1 }; row < point_y_ - 1; ++row)
					for (Index_Size col{ point_x + 1 }; col < matrix_[row].size() - 1 && col < point_x_ - 1; ++col)
						this->substitutionSTL(matrix_, col, row, args_...);
				return true;
			}

			//LayerSTL
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawLayerSTL(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ point_y + 1 }; row < point_y_ - 1; ++row)
					for (Index_Size col{ point_x + 1 }; col < matrix_[row].size() - 1; ++col)
						this->substitutionLayer(matrix_, layer_, col, row, args_...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawLayerWidthSTL(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ point_y + 1 }; row < point_y_ - 1; ++row)
					for (Index_Size col{ point_x + 1 }; col < matrix_[row].size() - 1 && col < point_x_ - 1; ++col)
						this->substitutionLayer(matrix_, layer_, col, row, args_...);
				return true;
			}

			//Normal
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawNormal(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ point_y + 1 }; row < point_y_ - 1; ++row)
					for (Index_Size col{ point_x + 1 }; col < point_x_ - 1; ++col)
						this->substitutionSTL(matrix_, col, row, args_...);
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawLayerNormal(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ point_y + 1 }; row < point_y_ - 1; ++row)
					for (Index_Size col{ point_x + 1 }; col < point_x_ - 1; ++col)
						this->substitutionLayer(matrix_, layer_, col, row, args_...);
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawArray(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ point_y + 1 }; row < point_y_ - 1; ++row)
					for (Index_Size col{ point_x + 1 }; col < point_x_ - 1; ++col)
						this->substitutionArray(matrix_, col, row, max_x_, args_...);
				return true;
			}

		public:


			///// 情報取得 /////

			[[nodiscard]] constexpr Index_Size getPointX() const noexcept {
				return this->point_x;
			}
			[[nodiscard]] constexpr Index_Size getPointY() const noexcept {
				return this->point_y;
			}
			[[nodiscard]] constexpr Index_Size getWidth() const noexcept {
				return this->width;
			}
			[[nodiscard]] constexpr Index_Size getHeight() const noexcept {
				return this->height;
			}
			[[nodiscard]] constexpr Matrix_Int_ getValue() const noexcept {
				return this->draw_value;
			}


			///// 生成呼び出し /////

			//STL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_) const noexcept {
				return (width == 0) ? this->drawSTL(std::forward<Matrix_>(matrix_), (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height) : this->drawWidthSTL(matrix_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, Function_ && function_) const noexcept {
				return (width == 0) ? this->drawSTL(std::forward<Matrix_>(matrix_), (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_) : this->drawWidthSTL(matrix_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_);
			}

			//LayerSTL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_) const noexcept {
				return (width == 0) ? this->drawLayerSTL(std::forward<Matrix_>(matrix_), layer_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height) : this->drawLayerWidthSTL(matrix_, layer_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
				return (width == 0) ? this->drawLayerSTL(std::forward<Matrix_>(matrix_), layer_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_) : this->drawLayerWidthSTL(matrix_, layer_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_);
			}

			//Normal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawNormal(std::forward<Matrix_>(matrix_), (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawNormal(std::forward<Matrix_>(matrix_), (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, function_);
			}

			//LayerNormal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, function_);
			}

			//Array
			template<typename Matrix_>
			constexpr bool drawArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawArray(std::forward<Matrix_>(matrix_), (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, max_x_);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperatorArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawArray(std::forward<Matrix_>(matrix_), (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, max_x_, function_);
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr auto operator()(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				return this->draw(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

			template<typename Matrix_, typename ...Args_>
			constexpr auto create(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->draw(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr auto createArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr auto createOperator(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperator(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr auto createOperatorArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}


			///// コンストラクタ /////

			constexpr BuryPoint() noexcept = default;
			constexpr explicit BuryPoint(const PairSize & length_) noexcept
				:width(length_.first), height(length_.second) {}
			constexpr explicit BuryPoint(const PairSize & position_, const PairSize & length_) noexcept
				:point_x(position_.first), point_y(position_.second),
				width(length_.first), height(length_.second) {}
			constexpr explicit BuryPoint(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
				:point_x(point_x_), point_y(point_y_),
				width(width_), height(height_) {}
		};
	}
}

#endif //Included Dungeon Template Library