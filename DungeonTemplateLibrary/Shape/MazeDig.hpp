/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_MAZE_DIG
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_MAZE_DIG

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
#include <Random/MersenneTwister32bit.hpp>
#include <Base/Struct.hpp>

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

			Matrix_Int_ empty_value{};
			Matrix_Int_ wall_value{};

			//穴掘り
			template<typename Matrix_>
			constexpr void mazeDig_Dig(Matrix_&& matrix_, const std::size_t j_max, const std::size_t i_max, std::size_t x_, std::size_t y_) const noexcept {
				std::int_fast32_t dx{}, dy{};
				for (std::size_t random{ dtl::random::mt32bit.get<std::size_t>() }, counter{}; counter < 4;) {
					switch ((random + counter) & 3) {
					case 0:dx = 0; dy = -2; break;
					case 1:dx = -2; dy = 0; break;
					case 2:dx = 0; dy = 2; break;
					case 3:dx = 2; dy = 0; break;
					default:dx = 0; dy = 0; break;
					}
					if (x_ + dx <= static_cast<std::int_fast32_t>(point_x) || y_ + dy <= static_cast<std::int_fast32_t>(point_y) || (x_ + dx) >= j_max || (y_ + dy) >= i_max || matrix_[y_ + dy][x_ + dx] == this->empty_value) {
						++counter;
					}
					else if (matrix_[y_ + dy][x_ + dx] == this->wall_value) {
						matrix_[y_ + (dy / 2)][x_ + (dx / 2)] = this->empty_value;
						matrix_[y_ + dy][x_ + dx] = this->empty_value;
						x_ += dx;
						y_ += dy;
						counter = 0;
						random = dtl::random::mt32bit.get<std::size_t>();
					}
				}
				return;
			}
			template<typename Matrix_>
			constexpr void mazeDig_DigLayer(Matrix_&& matrix_, const Index_Size layer_, const std::size_t j_max, const std::size_t i_max, std::size_t x_, std::size_t y_) const noexcept {
				std::int_fast32_t dx{}, dy{};
				for (std::size_t random{ dtl::random::mt32bit.get<std::size_t>() }, counter{}; counter < 4;) {
					switch ((random + counter) & 3) {
					case 0:dx = 0; dy = -2; break;
					case 1:dx = -2; dy = 0; break;
					case 2:dx = 0; dy = 2; break;
					case 3:dx = 2; dy = 0; break;
					default:dx = 0; dy = 0; break;
					}
					if (x_ + dx <= static_cast<std::int_fast32_t>(point_x) || y_ + dy <= static_cast<std::int_fast32_t>(point_y) || (x_ + dx) >= j_max || (y_ + dy) >= i_max || matrix_[y_ + dy][x_ + dx][layer_] == this->empty_value) {
						++counter;
					}
					else if (matrix_[y_ + dy][x_ + dx][layer_] == this->wall_value) {
						matrix_[y_ + (dy / 2)][x_ + (dx / 2)][layer_] = this->empty_value;
						matrix_[y_ + dy][x_ + dx][layer_] = this->empty_value;
						x_ += dx;
						y_ += dy;
						counter = 0;
						random = dtl::random::mt32bit.get<std::size_t>();
					}
				}
				return;
			}
			template<typename Matrix_>
			constexpr void mazeDig_DigArray(Matrix_&& matrix_, const Index_Size max_x_, const std::size_t j_max, const std::size_t i_max, std::size_t x_, std::size_t y_) const noexcept {
				std::int_fast32_t dx{}, dy{};
				for (std::size_t random{ dtl::random::mt32bit.get<std::size_t>() }, counter{}; counter < 4;) {
					switch ((random + counter) & 3) {
					case 0:dx = 0; dy = -2; break;
					case 1:dx = -2; dy = 0; break;
					case 2:dx = 0; dy = 2; break;
					case 3:dx = 2; dy = 0; break;
					default:dx = 0; dy = 0; break;
					}
					if (x_ + dx <= static_cast<std::int_fast32_t>(point_x) || y_ + dy <= static_cast<std::int_fast32_t>(point_y) || (x_ + dx) >= j_max || (y_ + dy) >= i_max || matrix_[(y_ + dy) * max_x_ + x_ + dx] == this->empty_value) {
						++counter;
					}
					else if (matrix_[(y_ + dy) * max_x_ + x_ + dx] == this->wall_value) {
						matrix_[(y_ + (dy / 2)) * max_x_ + x_ + (dx / 2)] = this->empty_value;
						matrix_[(y_ + dy) * max_x_ + x_ + dx] = this->empty_value;
						x_ += dx;
						y_ += dy;
						counter = 0;
						random = dtl::random::mt32bit.get<std::size_t>();
					}
				}
				return;
			}
			//迷路生成
			template<typename Matrix_>
			constexpr std::size_t mazeDig_CreateLoop(const Matrix_& matrix_, const std::size_t j_max, const std::size_t i_max, std::unique_ptr<std::size_t[]>& select_x, std::unique_ptr<std::size_t[]>& select_y) const noexcept {
				std::size_t select_id{};
				for (std::size_t i{ this->point_y + 1 }; i < i_max; i += 2)
					for (std::size_t j{ this->point_x + 1 }; j < j_max; j += 2) {
						if (matrix_[i][j] != this->empty_value) continue;
						if ((i >= this->point_y + 2 && matrix_[i - 2][j] == this->wall_value) || (j >= this->point_x + 2 && matrix_[i][j - 2] == this->wall_value)) {
							select_x[select_id] = j;
							select_y[select_id] = i;
							++select_id;
						}
						else if ((j >= j_max - 1) && (i >= i_max - 1)) break;
						else if ((i + 2 < (i_max + 1) && matrix_[i + 2][j] == this->wall_value) || (j + 2 < (j_max + 1) && matrix_[i][j + 2] == this->wall_value)) {
							select_x[select_id] = j;
							select_y[select_id] = i;
							++select_id;
						}
					}
				return select_id;
			}
			template<typename Matrix_>
			constexpr std::size_t mazeDig_CreateLoopLayer(const Matrix_& matrix_, const Index_Size layer_, const std::size_t j_max, const std::size_t i_max, std::unique_ptr<std::size_t[]>& select_x, std::unique_ptr<std::size_t[]>& select_y) const noexcept {
				std::size_t select_id{};
				for (std::size_t i{ this->point_y + 1 }; i < i_max; i += 2)
					for (std::size_t j{ this->point_x + 1 }; j < j_max; j += 2) {
						if (matrix_[i][j][layer_] != this->empty_value) continue;
						if ((i >= this->point_y + 2 && matrix_[i - 2][j][layer_] == this->wall_value) || (j >= this->point_x + 2 && matrix_[i][j - 2][layer_] == this->wall_value)) {
							select_x[select_id] = j;
							select_y[select_id] = i;
							++select_id;
						}
						else if ((j >= j_max - 1) && (i >= i_max - 1)) break;
						else if ((i + 2 < (i_max + 1) && matrix_[i + 2][j][layer_] == this->wall_value) || (j + 2 < (j_max + 1) && matrix_[i][j + 2][layer_] == this->wall_value)) {
							select_x[select_id] = j;
							select_y[select_id] = i;
							++select_id;
						}
					}
				return select_id;
			}
			template<typename Matrix_>
			constexpr std::size_t mazeDig_CreateLoopArray(const Matrix_& matrix_, const Index_Size max_x_, const std::size_t j_max, const std::size_t i_max, std::unique_ptr<std::size_t[]>& select_x, std::unique_ptr<std::size_t[]>& select_y) const noexcept {
				std::size_t select_id{};
				for (std::size_t i{ this->point_y + 1 }; i < i_max; i += 2)
					for (std::size_t j{ this->point_x + 1 }; j < j_max; j += 2) {
						if (matrix_[i * max_x_ + j] != this->empty_value) continue;
						if ((i >= this->point_y + 2 && matrix_[(i - 2) * max_x_ + j] == this->wall_value) || (j >= this->point_x + 2 && matrix_[i * max_x_ + j - 2] == this->wall_value)) {
							select_x[select_id] = j;
							select_y[select_id] = i;
							++select_id;
						}
						else if ((j >= j_max - 1) && (i >= i_max - 1)) break;
						else if ((i + 2 < (i_max + 1) && matrix_[(i + 2) * max_x_ + j] == this->wall_value) || (j + 2 < (j_max + 1) && matrix_[i * max_x_ + j + 2] == this->wall_value)) {
							select_x[select_id] = j;
							select_y[select_id] = i;
							++select_id;
						}
					}
				return select_id;
			}


			///// 基本処理 /////

			//Normal
			template<typename Matrix_, typename ...Args_>
			bool drawNormal(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				matrix_[this->point_y + 1][this->point_x + 1] = this->empty_value;
				std::unique_ptr<std::size_t[]> select_x{ new(std::nothrow) std::size_t[point_x_ * point_y_] };
				if (!select_x) return false;
				std::unique_ptr<std::size_t[]> select_y{ new(std::nothrow) std::size_t[point_x_ * point_y_] };
				if (!select_y) return false;

				const std::size_t i_max{ ((((point_y_ - this->point_y) & 1) == 0) ? point_y_ - 2 : point_y_ - 1) };
				const std::size_t j_max{ ((((point_x_ - this->point_x) & 1) == 0) ? point_x_ - 2 : point_x_ - 1) };

				//座標を選ぶ
				for (std::size_t select_id{};;) {
					select_id = mazeDig_CreateLoop(matrix_, j_max, i_max, select_x, select_y);
					if (select_id == 0) break;
					select_id = dtl::random::mt32bit.get<std::size_t>(select_id);
					mazeDig_Dig(matrix_, j_max, i_max, select_x[select_id], select_y[select_id]);
				}
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
			bool drawLayerNormal(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_&& ... args_) const noexcept {
				matrix_[this->point_y + 1][this->point_x + 1][layer_] = this->empty_value;
				std::unique_ptr<std::size_t[]> select_x{ new(std::nothrow) std::size_t[point_x_ * point_y_] };
				if (!select_x) return false;
				std::unique_ptr<std::size_t[]> select_y{ new(std::nothrow) std::size_t[point_x_ * point_y_] };
				if (!select_y) return false;

				const std::size_t i_max{ ((((point_y_ - this->point_y) & 1) == 0) ? point_y_ - 2 : point_y_ - 1) };
				const std::size_t j_max{ ((((point_x_ - this->point_x) & 1) == 0) ? point_x_ - 2 : point_x_ - 1) };

				//座標を選ぶ
				for (std::size_t select_id{};;) {
					select_id = mazeDig_CreateLoopLayer(matrix_, layer_, j_max, i_max, select_x, select_y);
					if (select_id == 0) break;
					select_id = dtl::random::mt32bit.get<std::size_t>(select_id);
					mazeDig_DigLayer(matrix_, layer_, j_max, i_max, select_x[select_id], select_y[select_id]);
				}

				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			bool drawArray(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Args_&& ... args_) const noexcept {
				matrix_[(this->point_y + 1) * max_x_ + point_x + 1] = this->empty_value;
				std::unique_ptr<std::size_t[]> select_x{ new(std::nothrow) std::size_t[point_x_ * point_y_] };
				if (!select_x) return false;
				std::unique_ptr<std::size_t[]> select_y{ new(std::nothrow) std::size_t[point_x_ * point_y_] };
				if (!select_y) return false;

				const std::size_t i_max{ ((((point_y_ - this->point_y) & 1) == 0) ? point_y_ - 2 : point_y_ - 1) };
				const std::size_t j_max{ ((((point_x_ - this->point_x) & 1) == 0) ? point_x_ - 2 : point_x_ - 1) };

				//座標を選ぶ
				for (std::size_t select_id{};;) {
					select_id = mazeDig_CreateLoopArray(matrix_, max_x_, j_max, i_max, select_x, select_y);
					if (select_id == 0) break;
					select_id = dtl::random::mt32bit.get<std::size_t>(select_id);
					mazeDig_DigArray(matrix_, max_x_, j_max, i_max, select_x[select_id], select_y[select_id]);
				}

				return true;
			}

		public:


			///// 情報取得 /////

#if defined(_MSVC_LANG) //C++17 use nodiscard
#if (_MSVC_LANG >= 201703L)
			[[nodiscard]]
#endif
#elif defined(__cplusplus)
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr Index_Size getPointX() const noexcept {
				return this->point_x;
			}
#if defined(_MSVC_LANG) //C++17 use nodiscard
#if (_MSVC_LANG >= 201703L)
			[[nodiscard]]
#endif
#elif defined(__cplusplus)
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr Index_Size getPointY() const noexcept {
				return this->point_y;
			}
#if defined(_MSVC_LANG) //C++17 use nodiscard
#if (_MSVC_LANG >= 201703L)
			[[nodiscard]]
#endif
#elif defined(__cplusplus)
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr Index_Size getWidth() const noexcept {
				return this->width;
			}
#if defined(_MSVC_LANG) //C++17 use nodiscard
#if (_MSVC_LANG >= 201703L)
			[[nodiscard]]
#endif
#elif defined(__cplusplus)
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr Index_Size getHeight() const noexcept {
				return this->height;
			}


			///// 生成呼び出し /////

			//STL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_) const noexcept {
				return this->drawNormal(std::forward<Matrix_>(matrix_), (this->width == 0 || this->point_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->point_x + this->width, (this->height == 0 || this->point_y + this->height >= matrix_.size()) ? matrix_.size() : this->point_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, Function_ && function_) const noexcept {
				return this->drawNormal(std::forward<Matrix_>(matrix_), (this->width == 0 || this->point_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->point_x + this->width, (this->height == 0 || this->point_y + this->height >= matrix_.size()) ? matrix_.size() : this->point_y + this->height, function_);
			}

			//LayerSTL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_) const noexcept {
				return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (this->width == 0 || this->point_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->point_x + this->width, (this->height == 0 || this->point_y + this->height >= matrix_.size()) ? matrix_.size() : this->point_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
				return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (this->width == 0 || this->point_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->point_x + this->width, (this->height == 0 || this->point_y + this->height >= matrix_.size()) ? matrix_.size() : this->point_y + this->height, function_);
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
			constexpr MazeDig& clearPointX() noexcept {
				this->point_x = 0;
				return *this;
			}
			//始点座標Yを初期値に戻す
			constexpr MazeDig& clearPointY() noexcept {
				this->point_y = 0;
				return *this;
			}
			//範囲の大きさ(X軸方向)を初期値に戻す
			constexpr MazeDig& clearWidth() noexcept {
				this->width = 0;
				return *this;
			}
			//範囲の大きさ(Y軸方向)を初期値に戻す
			constexpr MazeDig& clearHeight() noexcept {
				this->height = 0;
				return *this;
			}
			//始点座標(X,Y)を初期値に戻す
			constexpr MazeDig& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
			//描画範囲を初期値に戻す
			constexpr MazeDig& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			//全ての値を初期値に戻す
			constexpr MazeDig& clear() noexcept {
				this->clearRange();
				return *this;
			}


			///// 代入 /////

			constexpr MazeDig& setPointX(const Index_Size point_x_) noexcept {
				this->point_x = point_x_;
				return *this;
			}
			constexpr MazeDig& setPointY(const Index_Size point_y_) noexcept {
				this->point_y = point_y_;
				return *this;
			}
			constexpr MazeDig& setWidth(const Index_Size width_) noexcept {
				this->width = width_;
				return *this;
			}
			constexpr MazeDig& setHeight(const Index_Size height_) noexcept {
				this->height = height_;
				return *this;
			}
			constexpr MazeDig& setPoint(const Index_Size point_) noexcept {
				this->point_x = point_;
				this->point_y = point_;
				return *this;
			}
			constexpr MazeDig& setPoint(const Index_Size point_x_, const Index_Size point_y_) noexcept {
				this->point_x = point_x_;
				this->point_y = point_y_;
				return *this;
			}
			constexpr MazeDig& setRange(const Index_Size point_x_, const Index_Size point_y_, const Index_Size length_) noexcept {
				this->point_x = point_x_;
				this->point_y = point_y_;
				this->width = length_;
				this->height = length_;
				return *this;
			}
			constexpr MazeDig& setRange(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->point_x = point_x_;
				this->point_y = point_y_;
				this->width = width_;
				this->height = height_;
				return *this;
			}
			constexpr MazeDig& setRange(const dtl::base::MatrixRange & matrix_range_) noexcept {
				this->point_x = matrix_range_.x;
				this->point_y = matrix_range_.y;
				this->width = matrix_range_.w;
				this->height = matrix_range_.h;
				return *this;
			}


			///// コンストラクタ /////

			constexpr MazeDig() noexcept = default;
			constexpr explicit MazeDig(const Matrix_Int_ & empty_value_) noexcept
				:empty_value(empty_value_) {}
			constexpr explicit MazeDig(const Matrix_Int_& empty_value_, const Matrix_Int_& wall_value_) noexcept
				:empty_value(empty_value_), wall_value(wall_value_) {}
			constexpr explicit MazeDig(const dtl::base::MatrixRange & matrix_range_) noexcept
				:point_x(matrix_range_.x), point_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}
			constexpr explicit MazeDig(const dtl::base::MatrixRange & matrix_range_, const Matrix_Int_ & empty_value_) noexcept
				:point_x(matrix_range_.x), point_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				empty_value(empty_value_) {}
			constexpr explicit MazeDig(const dtl::base::MatrixRange& matrix_range_, const Matrix_Int_& empty_value_, const Matrix_Int_& wall_value_) noexcept
				:point_x(matrix_range_.x), point_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				empty_value(empty_value_), wall_value(wall_value_) {}
			constexpr explicit MazeDig(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
				:point_x(point_x_), point_y(point_y_),
				width(width_), height(height_) {}
			constexpr explicit MazeDig(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_& empty_value_) noexcept
				:point_x(point_x_), point_y(point_y_),
				width(width_), height(height_),
				empty_value(empty_value_) {}
			constexpr explicit MazeDig(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_& empty_value_, const Matrix_Int_& wall_value_) noexcept
				:point_x(point_x_), point_y(point_y_),
				width(width_), height(height_),
				empty_value(empty_value_), wall_value(wall_value_) {}
		};
	}
}

#endif //Included Dungeon Template Library