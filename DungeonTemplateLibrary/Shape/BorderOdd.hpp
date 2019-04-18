/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_BORDER_ODD
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_BORDER_ODD

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::Border-(%E5%BD%A2%E7%8A%B6%E3%82%AF%E3%83%A9%E3%82%B9)/
#######################################################################################*/

/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <Base/Struct.hpp>

namespace dtl {
	inline namespace shape {

		//四角形の生成
		template<typename Matrix_Int_>
		class BorderOdd {
		private:


			///// エイリアス /////

			using Index_Size = std::size_t;
			using PairSize = std::pair<Index_Size, Index_Size>;


			///// メンバ変数 /////

			Index_Size point_x{};
			Index_Size point_y{};
			Index_Size width{};
			Index_Size height{};
			Matrix_Int_ draw_value{};


			///// 代入処理 /////

			template<typename Matrix_>
			constexpr inline void substitutionSTL(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				matrix_[point_y_][point_x_] = draw_value;
			}
			template<typename Matrix_>
			constexpr inline void substitutionArray(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
				matrix_[point_y_ * max_x_ + point_x_] = draw_value;
			}
			template<typename Matrix_>
			constexpr inline void substitutionLayer(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				matrix_[point_y_][point_x_][layer_] = draw_value;
			}

			template<typename Matrix_, typename Function_>
			constexpr inline void substitutionSTL(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, Function_&& function_) const noexcept {
				if (function_(matrix_[point_y_][point_x_])) matrix_[point_y_][point_x_] = draw_value;
			}
			template<typename Matrix_, typename Function_>
			constexpr inline void substitutionArray(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Function_&& function_) const noexcept {
				if (function_(matrix_[point_y_ * max_x_ + point_x_])) matrix_[point_y_ * max_x_ + point_x_] = draw_value;
			}
			template<typename Matrix_, typename Function_>
			constexpr inline void substitutionLayer(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Function_ && function_) const noexcept {
				if (function_(matrix_[point_y_][point_x_][layer_])) matrix_[point_y_][point_x_][layer_] = draw_value;
			}


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawSTL(Matrix_ && matrix_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				if (point_y_ == 0) return true;
				for (Index_Size col{ point_x }; col < matrix_[point_y].size(); ++col)
					this->substitutionSTL(matrix_, col, point_y, args_...);
				for (Index_Size col{ point_x }; col < matrix_[point_y_ - 1].size(); ++col) {
					if ((point_y_ - point_y) % 2 == 0) this->substitutionSTL(matrix_, col, point_y_ - 2, args_...);
					this->substitutionSTL(matrix_, col, point_y_ - 1, args_...);
				}
				for (Index_Size row{ point_y }; row < point_y_; ++row) {
					if (matrix_[row].size() == 0) continue;
					this->substitutionSTL(matrix_, point_x, row, args_...);
					if ((matrix_[row].size() - point_x) % 2 == 0) this->substitutionSTL(matrix_, matrix_[row].size() - 2, row, args_...);
					this->substitutionSTL(matrix_, matrix_[row].size() - 1, row, std::forward<Args_>(args_)...);
				}
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawWidthSTL(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				if (point_y_ < 2) return true;
				for (Index_Size col{ point_x }; col < point_x_ && col < matrix_[point_y].size(); ++col)
					this->substitutionSTL(matrix_, col, point_y, args_...);
				for (Index_Size col{ point_x }; col < point_x_ && col < matrix_[point_y_ - 1].size(); ++col) {
					if ((point_y_ - point_y) % 2 == 0) this->substitutionSTL(matrix_, col, point_y_ - 2, args_...);
					this->substitutionSTL(matrix_, col, point_y_ - 1, args_...);
				}
				if (point_x_ < 2) return true;
				for (Index_Size row{ point_y }; row < point_y_; ++row) {
					if (matrix_[row].size() == 0) continue;
					this->substitutionSTL(matrix_, point_x, row, args_...);
					if (matrix_[row].size() <= point_x_) {
						if ((matrix_[row].size() - point_x) % 2 == 0) this->substitutionSTL(matrix_, matrix_[row].size() - 2, row, args_...);
						this->substitutionSTL(matrix_, matrix_[row].size() - 1, row, args_...);
					}
					else {
						if ((point_x_ - point_x) % 2 == 0) this->substitutionSTL(matrix_, point_x_ - 2, row, args_...);
						this->substitutionSTL(matrix_, point_x_ - 1, row, std::forward<Args_>(args_)...);
					}
				}
				return true;
			}

			//LayerSTL
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawLayerSTL(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				if (point_y_ < 2) return true;
				for (Index_Size col{ point_x }; col < matrix_[point_y].size(); ++col)
					this->substitutionLayer(matrix_, layer_, col, point_y, args_...);
				for (Index_Size col{ point_x }; col < matrix_[point_y_ - 1].size(); ++col) {
					if ((point_y_ - point_y) % 2 == 0) this->substitutionLayer(matrix_, layer_, col, point_y_ - 2, args_...);
					this->substitutionLayer(matrix_, layer_, col, point_y_ - 1, args_...);
				}
				for (Index_Size row{ point_y }; row < point_y_; ++row) {
					if (matrix_[row].size() < 2) continue;
					this->substitutionLayer(matrix_, layer_, point_x, row, args_...);
					if ((matrix_[row].size() - point_x) % 2 == 0) this->substitutionLayer(matrix_, layer_, matrix_[row].size() - 2, row, args_...);
					this->substitutionLayer(matrix_, layer_, matrix_[row].size() - 1, row, std::forward<Args_>(args_)...);
				}
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawLayerWidthSTL(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				if (point_y_ < 2) return true;
				for (Index_Size col{ point_x }; col < point_x_ && col < matrix_[point_y].size(); ++col)
					this->substitutionLayer(matrix_, layer_, col, point_y, args_...);
				for (Index_Size col{ point_x }; col < point_x_ && col < matrix_[point_y_ - 1].size(); ++col) {
					if ((point_y_ - point_y) % 2 == 0) this->substitutionLayer(matrix_, layer_, col, point_y_ - 2, args_...);
					this->substitutionLayer(matrix_, layer_, col, point_y_ - 1, args_...);
				}
				if (point_x_ < 2) return true;
				for (Index_Size row{ point_y }; row < point_y_; ++row) {
					if (matrix_[row].size() == 0) continue;
					this->substitutionLayer(matrix_, layer_, point_x, row, args_...);
					if (matrix_[row].size() <= point_x_) {
						if ((matrix_[row].size() - point_x) % 2 == 0) this->substitutionLayer(matrix_, layer_, matrix_[row].size() - 2, row, args_...);
						this->substitutionLayer(matrix_, layer_, matrix_[row].size() - 1, row, args_...);
					}
					else {
						if ((point_x_ - point_x) % 2 == 0) this->substitutionLayer(matrix_, layer_, point_x_ - 2, row, args_...);
						this->substitutionLayer(matrix_, layer_, point_x_ - 1, row, std::forward<Args_>(args_)...);
					}
				}
				return true;
			}

			//Normal
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawNormal(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				if (point_x_ < 2 || point_y_ < 2) return true;
				for (Index_Size col{ point_x }; col < point_x_; ++col) {
					this->substitutionSTL(matrix_, col, point_y, args_...);
					if ((point_y_ - point_y) % 2 == 0) this->substitutionSTL(matrix_, col, point_y_ - 2, args_...);
					this->substitutionSTL(matrix_, col, point_y_ - 1, args_...);
				}
				for (Index_Size row{ point_y }; row < point_y_; ++row) {
					this->substitutionSTL(matrix_, point_x, row, args_...);
					if ((point_x_ - point_x) % 2 == 0) this->substitutionSTL(matrix_, point_x_ - 2, row, args_...);
					this->substitutionSTL(matrix_, point_x_ - 1, row, std::forward<Args_>(args_)...);
				}
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawLayerNormal(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				if (point_x_ < 2 || point_y_ < 2) return true;
				for (Index_Size col{ point_x }; col < point_x_; ++col) {
					this->substitutionLayer(matrix_, layer_, col, point_y, args_...);
					if ((point_y_ - point_y) % 2 == 0) this->substitutionLayer(matrix_, layer_, col, point_y_ - 2, args_...);
					this->substitutionLayer(matrix_, layer_, col, point_y_ - 1, args_...);
				}
				for (Index_Size row{ point_y }; row < point_y_; ++row) {
					this->substitutionLayer(matrix_, layer_, point_x, row, args_...);
					if ((point_y_ - point_y) % 2 == 0) this->substitutionLayer(matrix_, layer_, point_x_ - 2, row, args_...);
					this->substitutionLayer(matrix_, layer_, point_x_ - 1, row, std::forward<Args_>(args_)...);
				}
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawArray(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Args_ && ... args_) const noexcept {
				if (point_x_ < 2 || point_y_ < 2) return true;
				for (Index_Size col{ point_x }; col < point_x_; ++col) {
					this->substitutionArray(matrix_, col, point_y, max_x_, args_...);
					if ((point_y_ - point_y) % 2 == 0) this->substitutionArray(matrix_, col, point_y_ - 2, max_x_, args_...);
					this->substitutionArray(matrix_, col, point_y_ - 1, max_x_, args_...);
				}
				for (Index_Size row{ point_y }; row < point_y_; ++row) {
					this->substitutionArray(matrix_, point_x, row, max_x_, args_...);
					if ((point_y_ - point_y) % 2 == 0) this->substitutionArray(matrix_, point_x_ - 2, row, max_x_, args_...);
					this->substitutionArray(matrix_, point_x_ - 1, row, max_x_, std::forward<Args_>(args_)...);
				}
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

			constexpr BorderOdd() noexcept = default;
			constexpr explicit BorderOdd(const Matrix_Int_ & draw_value_) noexcept
				:draw_value(draw_value_) {}
			constexpr explicit BorderOdd(const dtl::base::MatrixRange & matrix_range_) noexcept
				:point_x(matrix_range_.x), point_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}
			constexpr explicit BorderOdd(const dtl::base::MatrixRange & matrix_range_, const Matrix_Int_ & draw_value_) noexcept
				:point_x(matrix_range_.x), point_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				draw_value(draw_value_) {}
			constexpr explicit BorderOdd(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
				:point_x(point_x_), point_y(point_y_),
				width(width_), height(height_) {}
			constexpr explicit BorderOdd(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_ & draw_value_) noexcept
				:point_x(point_x_), point_y(point_y_),
				width(width_), height(height_),
				draw_value(draw_value_) {}
		};
	}
}

#endif //Included Dungeon Template Library