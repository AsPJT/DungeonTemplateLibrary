/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_MAZE_DIG
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_MAZE_DIG

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	/
#######################################################################################*/

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <memory>
#include <new>
#include <Base/Struct.hpp>
#include <Random/MersenneTwister32bit.hpp>

namespace dtl {
	inline namespace shape {

		//マスを指定した数値で埋める
		template<typename Matrix_Int_>
		class MazeDig {
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


			//生成チェック
			template<typename Matrix_>
			constexpr bool mazeDig_Check(const Matrix_& matrix_) const noexcept {
				if (matrix_.size() <= 2) return false;
				if (matrix_[1].size() <= 2) return false;
				return true;
			}
			//穴掘り
			template<typename Matrix_>
			constexpr void mazeDig_Dig(Matrix_ & matrix_, std::size_t x_, std::size_t y_, const Matrix_Int_ id_wall_, const Matrix_Int_ id_empty_) const noexcept {

				using dtl::random::mersenne_twister_32bit;

				if (!mazeDig_Check(matrix_)) return;
				std::int_fast32_t dx{}, dy{};
				std::size_t random = std::size_t(mersenne_twister_32bit()), counter = 0;

				const std::size_t i_max{ ((matrix_.size() % 2) == 0) ? matrix_.size() - 2 : matrix_.size() - 1 };
				const std::size_t j_max{ ((matrix_[0].size() % 2) == 0) ? matrix_[0].size() - 2 : matrix_[0].size() - 1 };

				while (counter < 4) {
					switch ((random + counter) & 3)
					{
					case 0:dx = 0; dy = -2; break;
					case 1:dx = -2; dy = 0; break;
					case 2:dx = 0; dy = 2; break;
					case 3:dx = 2; dy = 0; break;
					default:dx = 0; dy = 0; break;
					}
					if (x_ + dx <= 0 || y_ + dy <= 0 || (x_ + dx) >= i_max || (y_ + dy) >= j_max || matrix_[x_ + dx][y_ + dy] == id_empty_) {
						++counter;
					}
					else if (matrix_[x_ + dx][y_ + dy] == id_wall_) {
						matrix_[x_ + (dx / 2)][y_ + (dy / 2)] = id_empty_;
						matrix_[x_ + dx][y_ + dy] = id_empty_;
						x_ += dx;
						y_ += dy;
						counter = 0;
						random = std::size_t(mersenne_twister_32bit());
					}
				}
				return;
			}
			//迷路生成
			template<typename Matrix_>
			constexpr std::size_t mazeDig_CreateLoop(const Matrix_ & matrix_, const Matrix_Int_ id_wall_, const Matrix_Int_ id_empty_, std::unique_ptr<std::size_t[]> & select_x, std::unique_ptr<std::size_t[]> & select_y) const noexcept {
				std::size_t select_id{};
				const std::size_t i_max{ ((matrix_.size() % 2) == 0) ? matrix_.size() - 2 : matrix_.size() - 1 };
				const std::size_t j_max{ ((matrix_[0].size() % 2) == 0) ? matrix_[0].size() - 2 : matrix_[0].size() - 1 };

				for (std::size_t i{ 1 }; i < i_max; i += 2)
					for (std::size_t j{ 1 }; j < j_max; j += 2) {
						if (matrix_[i][j] != id_empty_) continue;
						if ((i >= 2 && matrix_[i - 2][j] == id_wall_) || (j >= 2 && matrix_[i][j - 2] == id_wall_)) {
							select_x[select_id] = i;
							select_y[select_id] = j;
							++select_id;
						}
						else if ((j == j_max - 1) && (i == i_max - 1)) break;
						else if ((i + 2 < (i_max + 1) && matrix_[i + 2][j] == id_wall_) || (j + 2 < (j_max + 1) && matrix_[i][j + 2] == id_wall_)) {
							select_x[select_id] = i;
							select_y[select_id] = j;
							++select_id;
						}
					}
				return select_id;
			}
			//穴掘り法の迷路を生成する
			template<typename Matrix_>
			void mazeDig_Create(Matrix_ & matrix_, const Matrix_Int_ max_x_, const Matrix_Int_ max_y_, const Matrix_Int_ id_wall_, const Matrix_Int_ id_empty_) const noexcept {

				if (max_x_ <= 2 || max_y_ <= 2) return;
				matrix_[1][1] = id_empty_;

				std::size_t select_id{};

				std::unique_ptr<std::size_t[]> select_x{ new(std::nothrow) std::size_t[matrix_.size() * matrix_[0].size()] };
				if (!select_x) return;
				std::unique_ptr<std::size_t[]> select_y{ new(std::nothrow) std::size_t[matrix_.size() * matrix_[0].size()] };
				if (!select_y) return;

				//座標を選ぶ
				while (true) {
					select_id = mazeDig_CreateLoop(matrix_, id_wall_, id_empty_, select_x, select_y);
					if (select_id == 0) break;
					select_id = dtl::random::mt32bit.get<std::size_t>(select_id);
					mazeDig_Dig(matrix_, select_x[select_id], select_y[select_id], id_wall_, id_empty_);
				}
				return;
			}


			///// 代入処理 /////

			template<typename Matrix_>
			constexpr inline void substitutionSTL(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				matrix_[point_y_][point_x_] = draw_value;
			}
			template<typename Matrix_>
			constexpr inline void substitutionArray(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
				matrix_[point_y_ * max_x_ + point_x_] = draw_value;
			}
			template<typename Matrix_>
			constexpr inline void substitutionLayer(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				matrix_[point_y_][point_x_][layer_] = draw_value;
			}

			template<typename Matrix_, typename Function_>
			constexpr inline void substitutionSTL(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, Function_ && function_) const noexcept {
				if (function_(matrix_[point_y_][point_x_])) matrix_[point_y_][point_x_] = draw_value;
			}
			template<typename Matrix_, typename Function_>
			constexpr inline void substitutionArray(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Function_ && function_) const noexcept {
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
				mazeDig_Create(matrix_, (matrix_.size() == 0) ? 0 : matrix_[0].size(), matrix_.size(), 0, 1);
				//for (Index_Size row{ point_y }; row < point_y_; ++row)
				//	for (Index_Size col{ point_x }; col < matrix_[row].size(); ++col)
				//		this->substitutionSTL(matrix_, col, row, args_...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawWidthSTL(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				mazeDig_Create(matrix_, (matrix_.size() == 0) ? 0 : matrix_[0].size(), matrix_.size(), 0, 1);
				//for (Index_Size row{ point_y }; row < point_y_; ++row)
				//	for (Index_Size col{ point_x }; col < matrix_[row].size() && col < point_x_; ++col)
				//		this->substitutionSTL(matrix_, col, row, args_...);
				return true;
			}

			//LayerSTL
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawLayerSTL(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ point_y }; row < point_y_; ++row)
					for (Index_Size col{ point_x }; col < matrix_[row].size(); ++col)
						this->substitutionLayer(matrix_, layer_, col, row, args_...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawLayerWidthSTL(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ point_y }; row < point_y_; ++row)
					for (Index_Size col{ point_x }; col < matrix_[row].size() && col < point_x_; ++col)
						this->substitutionLayer(matrix_, layer_, col, row, args_...);
				return true;
			}

			//Normal
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawNormal(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ point_y }; row < point_y_; ++row)
					for (Index_Size col{ point_x }; col < point_x_; ++col)
						this->substitutionSTL(matrix_, col, row, args_...);
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawLayerNormal(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ point_y }; row < point_y_; ++row)
					for (Index_Size col{ point_x }; col < point_x_; ++col)
						this->substitutionLayer(matrix_, layer_, col, row, args_...);
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawArray(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ point_y }; row < point_y_; ++row)
					for (Index_Size col{ point_x }; col < point_x_; ++col)
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

			constexpr MazeDig() noexcept = default;
			constexpr explicit MazeDig(const Matrix_Int_ & draw_value_) noexcept
				:draw_value(draw_value_) {}
			constexpr explicit MazeDig(const dtl::base::MatrixRange & matrix_range_) noexcept
				:point_x(matrix_range_.x), point_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}
			constexpr explicit MazeDig(const dtl::base::MatrixRange & matrix_range_, const Matrix_Int_ & draw_value_) noexcept
				:point_x(matrix_range_.x), point_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				draw_value(draw_value_) {}
			constexpr explicit MazeDig(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
				:point_x(point_x_), point_y(point_y_),
				width(width_), height(height_) {}
			constexpr explicit MazeDig(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_ & draw_value_) noexcept
				:point_x(point_x_), point_y(point_y_),
				width(width_), height(height_),
				draw_value(draw_value_) {}
		};
	}
}

#endif //Included Dungeon Template Library