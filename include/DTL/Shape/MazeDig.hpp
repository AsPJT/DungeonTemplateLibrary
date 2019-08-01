/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_MAZE_DIG_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_MAZE_DIG_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::MazeDig-(形状クラス)/
#######################################################################################*/

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Random/MersenneTwister32bit.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/New.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Type/SSizeT.hpp>
#include <DTL/Type/UniquePtr.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace shape { //"dtl::shape"名前空間に属する

		//マスを指定した数値で埋める
		template<typename Matrix_Var_, typename UniquePtr_ = DTL_TYPE_UNIQUE_PTR<::dtl::type::size[]>>
		class MazeDig {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;


			///// メンバ変数 (Member Variable) /////

			Index_Size start_x{};
			Index_Size start_y{};
			Index_Size width{};
			Index_Size height{};

			Matrix_Var_ empty_value{};
			Matrix_Var_ wall_value{};

			//穴掘り
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void mazeDig_Dig(Matrix_&& matrix_, const ::dtl::type::size j_max, const ::dtl::type::size i_max, ::dtl::type::size x_, ::dtl::type::size y_) const noexcept {
				::dtl::type::ssize dx{}, dy{};
				for (::dtl::type::size random{ ::dtl::random::mt32bit.get<::dtl::type::size>() }, counter{}; counter < 4;) {
					switch ((random + counter) & 3) {
					case 0:dx = 0; dy = -2; break;
					case 1:dx = -2; dy = 0; break;
					case 2:dx = 0; dy = 2; break;
					case 3:dx = 2; dy = 0; break;
					default:dx = 0; dy = 0; break;
					}
					if (static_cast<::dtl::type::ssize>(x_ + dx) <= static_cast<::dtl::type::ssize>(start_x) || 
						static_cast<::dtl::type::ssize>(y_ + dy) <= static_cast<::dtl::type::ssize>(start_y) || 
						(x_ + dx) >= j_max || (y_ + dy) >= i_max || static_cast<Matrix_Var_>(matrix_[y_ + dy][x_ + dx]) == this->empty_value) {
						++counter;
					}
					else if (matrix_[y_ + dy][x_ + dx] == this->wall_value) {
						matrix_[y_ + (dy / 2)][x_ + (dx / 2)] = this->empty_value;
						matrix_[y_ + dy][x_ + dx] = this->empty_value;
						x_ += dx;
						y_ += dy;
						counter = 0;
						random = ::dtl::random::mt32bit.get<::dtl::type::size>();
					}
				}
				return;
			}
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void mazeDig_DigLayer(Matrix_&& matrix_, const Index_Size layer_, const ::dtl::type::size j_max, const ::dtl::type::size i_max, ::dtl::type::size x_, ::dtl::type::size y_) const noexcept {
				::dtl::type::ssize dx{}, dy{};
				for (::dtl::type::size random{ ::dtl::random::mt32bit.get<::dtl::type::size>() }, counter{}; counter < 4;) {
					switch ((random + counter) & 3) {
					case 0:dx = 0; dy = -2; break;
					case 1:dx = -2; dy = 0; break;
					case 2:dx = 0; dy = 2; break;
					case 3:dx = 2; dy = 0; break;
					default:dx = 0; dy = 0; break;
					}
					if (x_ + dx <= static_cast<::dtl::type::ssize>(start_x) || y_ + dy <= static_cast<::dtl::type::ssize>(start_y) || (x_ + dx) >= j_max || (y_ + dy) >= i_max || matrix_[y_ + dy][x_ + dx][layer_] == this->empty_value) {
						++counter;
					}
					else if (matrix_[y_ + dy][x_ + dx][layer_] == this->wall_value) {
						matrix_[y_ + (dy / 2)][x_ + (dx / 2)][layer_] = this->empty_value;
						matrix_[y_ + dy][x_ + dx][layer_] = this->empty_value;
						x_ += dx;
						y_ += dy;
						counter = 0;
						random = ::dtl::random::mt32bit.get<::dtl::type::size>();
					}
				}
				return;
			}
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void mazeDig_DigArray(Matrix_&& matrix_, const Index_Size max_x_, const ::dtl::type::size j_max, const ::dtl::type::size i_max, ::dtl::type::size x_, ::dtl::type::size y_) const noexcept {
				::dtl::type::ssize dx{}, dy{};
				for (::dtl::type::size random{ ::dtl::random::mt32bit.get<::dtl::type::size>() }, counter{}; counter < 4;) {
					switch ((random + counter) & 3) {
					case 0:dx = 0; dy = -2; break;
					case 1:dx = -2; dy = 0; break;
					case 2:dx = 0; dy = 2; break;
					case 3:dx = 2; dy = 0; break;
					default:dx = 0; dy = 0; break;
					}
					if (static_cast<::dtl::type::ssize>(x_ + dx) <= static_cast<::dtl::type::ssize>(start_x) ||
						static_cast<::dtl::type::ssize>(y_ + dy) <= static_cast<::dtl::type::ssize>(start_y) ||
						(x_ + dx) >= j_max || 
						(y_ + dy) >= i_max || 
						matrix_[(y_ + dy) * max_x_ + x_ + dx] == this->empty_value) {
						++counter;
					}
					else if (matrix_[(y_ + dy) * max_x_ + x_ + dx] == this->wall_value) {
						matrix_[(y_ + (dy / 2)) * max_x_ + x_ + (dx / 2)] = this->empty_value;
						matrix_[(y_ + dy) * max_x_ + x_ + dx] = this->empty_value;
						x_ += dx;
						y_ += dy;
						counter = 0;
						random = ::dtl::random::mt32bit.get<::dtl::type::size>();
					}
				}
				return;
			}
			//迷路生成
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				::dtl::type::size mazeDig_CreateLoop(const Matrix_& matrix_, const ::dtl::type::size j_max, const ::dtl::type::size i_max, UniquePtr_& select_x, UniquePtr_& select_y) const noexcept {
				::dtl::type::size select_id{};
				for (::dtl::type::size i{ this->start_y + 1 }; i < i_max; i += 2)
					for (::dtl::type::size j{ this->start_x + 1 }; j < j_max; j += 2) {
						if (matrix_[i][j] != this->empty_value) continue;
						if ((i >= this->start_y + 2 && matrix_[i - 2][j] == this->wall_value) || (j >= this->start_x + 2 && matrix_[i][j - 2] == this->wall_value)) {
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
			DTL_VERSIONING_CPP14_CONSTEXPR
				::dtl::type::size mazeDig_CreateLoopLayer(const Matrix_& matrix_, const Index_Size layer_, const ::dtl::type::size j_max, const ::dtl::type::size i_max, UniquePtr_& select_x, UniquePtr_& select_y) const noexcept {
				::dtl::type::size select_id{};
				for (::dtl::type::size i{ this->start_y + 1 }; i < i_max; i += 2)
					for (::dtl::type::size j{ this->start_x + 1 }; j < j_max; j += 2) {
						if (matrix_[i][j][layer_] != this->empty_value) continue;
						if ((i >= this->start_y + 2 && matrix_[i - 2][j][layer_] == this->wall_value) || (j >= this->start_x + 2 && matrix_[i][j - 2][layer_] == this->wall_value)) {
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
			DTL_VERSIONING_CPP14_CONSTEXPR
				::dtl::type::size mazeDig_CreateLoopArray(const Matrix_& matrix_, const Index_Size max_x_, const ::dtl::type::size j_max, const ::dtl::type::size i_max, UniquePtr_& select_x, UniquePtr_& select_y) const noexcept {
				::dtl::type::size select_id{};
				for (::dtl::type::size i{ this->start_y + 1 }; i < i_max; i += 2)
					for (::dtl::type::size j{ this->start_x + 1 }; j < j_max; j += 2) {
						if (matrix_[i * max_x_ + j] != this->empty_value) continue;
						if ((i >= this->start_y + 2 && matrix_[(i - 2) * max_x_ + j] == this->wall_value) || (j >= this->start_x + 2 && matrix_[i * max_x_ + j - 2] == this->wall_value)) {
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
			bool drawNormal(Matrix_ && matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ...) const noexcept {
				matrix_[this->start_y + 1][this->start_x + 1] = this->empty_value;

				UniquePtr_ select_x{ DTL_TYPE_NEW ::dtl::type::size[end_x_ * end_y_] };
				if (!select_x) return false;
				UniquePtr_ select_y{ DTL_TYPE_NEW ::dtl::type::size[end_x_ * end_y_] };
				if (!select_y) return false;

				const ::dtl::type::size i_max{ ((((end_y_ - this->start_y) & 1) == 0) ? end_y_ - 2 : end_y_ - 1) };
				const ::dtl::type::size j_max{ ((((end_x_ - this->start_x) & 1) == 0) ? end_x_ - 2 : end_x_ - 1) };

				//座標を選ぶ
				for (::dtl::type::size select_id{};;) {
					select_id = mazeDig_CreateLoop(matrix_, j_max, i_max, select_x, select_y);
					if (select_id == 0) break;
					select_id = ::dtl::random::mt32bit.get<::dtl::type::size>(select_id);
					mazeDig_Dig(matrix_, j_max, i_max, select_x[select_id], select_y[select_id]);
				}
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
			bool drawLayerNormal(Matrix_&& matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_&& ...) const noexcept {
				matrix_[this->start_y + 1][this->start_x + 1][layer_] = this->empty_value;

				UniquePtr_ select_x{ DTL_TYPE_NEW ::dtl::type::size[end_x_ * end_y_] };
				if (!select_x) return false;
				UniquePtr_ select_y{ DTL_TYPE_NEW ::dtl::type::size[end_x_ * end_y_] };
				if (!select_y) return false;

				const ::dtl::type::size i_max{ ((((end_y_ - this->start_y) & 1) == 0) ? end_y_ - 2 : end_y_ - 1) };
				const ::dtl::type::size j_max{ ((((end_x_ - this->start_x) & 1) == 0) ? end_x_ - 2 : end_x_ - 1) };

				//座標を選ぶ
				for (::dtl::type::size select_id{};;) {
					select_id = mazeDig_CreateLoopLayer(matrix_, layer_, j_max, i_max, select_x, select_y);
					if (select_id == 0) break;
					select_id = ::dtl::random::mt32bit.get<::dtl::type::size>(select_id);
					mazeDig_DigLayer(matrix_, layer_, j_max, i_max, select_x[select_id], select_y[select_id]);
				}

				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			bool drawArray(Matrix_&& matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Args_&& ...) const noexcept {
				matrix_[(this->start_y + 1) * max_x_ + start_x + 1] = this->empty_value;

				UniquePtr_ select_x{ DTL_TYPE_NEW ::dtl::type::size[end_x_ * end_y_] };
				if (!select_x) return false;
				UniquePtr_ select_y{ DTL_TYPE_NEW ::dtl::type::size[end_x_ * end_y_] };
				if (!select_y) return false;

				const ::dtl::type::size i_max{ ((((end_y_ - this->start_y) & 1) == 0) ? end_y_ - 2 : end_y_ - 1) };
				const ::dtl::type::size j_max{ ((((end_x_ - this->start_x) & 1) == 0) ? end_x_ - 2 : end_x_ - 1) };

				//座標を選ぶ
				for (::dtl::type::size select_id{};;) {
					select_id = mazeDig_CreateLoopArray(matrix_, max_x_, j_max, i_max, select_x, select_y);
					if (select_id == 0) break;
					select_id = ::dtl::random::mt32bit.get<::dtl::type::size>(select_id);
					mazeDig_DigArray(matrix_, max_x_, j_max, i_max, select_x[select_id], select_y[select_id]);
				}

				return true;
			}

		public:


			///// メンバ変数の値を取得 (Get Value) /////

/*#######################################################################################
	[概要] 描画始点座標Xを取得する。
	[戻り値] 戻り値の型は std::size_t である。
	[Summary] Gets the drawing start point coordinate X.
	[Return value] The return type is std::size_t.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getPointX() const noexcept {
				return this->start_x;
			}

/*#######################################################################################
	[概要] 描画始点座標Yを取得する。
	[戻り値] 戻り値の型は std::size_t である。
	[Summary] Gets the drawing start point coordinate Y.
	[Return value] The return type is std::size_t.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getPointY() const noexcept {
				return this->start_y;
			}

/*#######################################################################################
	[概要] 描画横幅Wを取得する。
	[戻り値] 戻り値の型は std::size_t である。
	[Summary] Gets the drawing width.
	[Return value] The return type is std::size_t.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getWidth() const noexcept {
				return this->width;
			}

/*#######################################################################################
	[概要] 描画縦幅Hを取得する。
	[戻り値] 戻り値の型は std::size_t である。
	[Summary] Gets the drawing height.
	[Return value] The return type is std::size_t.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getHeight() const noexcept {
				return this->height;
			}


			///// 生成呼び出し (Drawing Function Call) /////

			//STL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_) const noexcept {
				return this->drawNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, Function_ && function_) const noexcept {
				return this->drawNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//LayerSTL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_) const noexcept {
				return this->drawLayerNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
				return this->drawLayerNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//Normal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//LayerNormal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawLayerNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawLayerNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//Array
			template<typename Matrix_>
			constexpr bool drawArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawArray(DTL_TYPE_FORWARD<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, max_x_);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperatorArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawArray(DTL_TYPE_FORWARD<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, max_x_, function_);
			}


			///// 生成呼び出しファンクタ (Drawing Functor) /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				return this->draw(DTL_TYPE_FORWARD<Matrix_>(matrix_), DTL_TYPE_FORWARD<Args_>(args_)...);
			}


			///// ダンジョン行列生成 (Create Dungeon Matrix) /////

			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& create(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->draw(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& createArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawArray(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& createOperator(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperator(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& createOperatorArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperatorArray(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}


			///// 消去 (Clear) /////

/*#######################################################################################
	[概要] 描画始点座標Xを初期値に戻す(描画始点座標Xを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing start coordinate X to the initial value (deletes the drawing start coordinate X).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				MazeDig& clearPointX() noexcept {
				this->start_x = 0;
				return *this;
			}

/*#######################################################################################
	[概要] 描画始点座標Yを初期値に戻す(描画始点座標Yを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing start coordinate Y to the initial value (deletes the drawing start coordinate Y).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				MazeDig& clearPointY() noexcept {
				this->start_y = 0;
				return *this;
			}

/*#######################################################################################
	[概要] 範囲の大きさ(X軸方向)を初期値に戻す(描画横幅Wを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the width of the range (X axis direction) to the initial value (deletes the drawing width).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				MazeDig& clearWidth() noexcept {
				this->width = 0;
				return *this;
			}

/*#######################################################################################
	[概要] 範囲の大きさ(Y軸方向)を初期値に戻す(描画縦幅Hを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the height of the range (Y axis direction) to the initial value (deletes the drawing height).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				MazeDig& clearHeight() noexcept {
				this->height = 0;
				return *this;
			}

/*#######################################################################################
	[概要] 描画始点座標(X,Y)を初期値に戻す(描画始点座標(X,Y)を消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing start coordinate (X, Y) to the initial value (deletes the drawing start coordinate (X, Y)).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				MazeDig& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}

/*#######################################################################################
	[概要] 描画範囲を初期値に戻す(描画範囲(X,Y,W,H)を消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing range to the initial value (deletes the drawing range (X, Y, W, H)).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				MazeDig& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}

/*#######################################################################################
	[概要] 全ての値を初期値に戻す。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Reset all values to their initial values.
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				MazeDig& clear() noexcept {
				this->clearRange();
				return *this;
			}


			///// 代入 /////

			DTL_VERSIONING_CPP14_CONSTEXPR
				MazeDig& setPointX(const Index_Size end_x_) noexcept {
				this->start_x = end_x_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				MazeDig& setPointY(const Index_Size end_y_) noexcept {
				this->start_y = end_y_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				MazeDig& setWidth(const Index_Size width_) noexcept {
				this->width = width_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				MazeDig& setHeight(const Index_Size height_) noexcept {
				this->height = height_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				MazeDig& setPoint(const Index_Size point_) noexcept {
				this->start_x = point_;
				this->start_y = point_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				MazeDig& setPoint(const Index_Size end_x_, const Index_Size end_y_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				MazeDig& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size length_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				this->width = length_;
				this->height = length_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				MazeDig& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				this->width = width_;
				this->height = height_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				MazeDig& setRange(const ::dtl::base::MatrixRange & matrix_range_) noexcept {
				this->start_x = matrix_range_.x;
				this->start_y = matrix_range_.y;
				this->width = matrix_range_.w;
				this->height = matrix_range_.h;
				return *this;
			}


			///// コンストラクタ (Constructor) /////

			MazeDig() = default;
			constexpr explicit MazeDig(const Matrix_Var_ & empty_value_) noexcept
				:empty_value(empty_value_) {}
			constexpr MazeDig(const Matrix_Var_& empty_value_, const Matrix_Var_& wall_value_) noexcept
				:empty_value(empty_value_), wall_value(wall_value_) {}
			constexpr explicit MazeDig(const ::dtl::base::MatrixRange & matrix_range_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}
			constexpr MazeDig(const ::dtl::base::MatrixRange & matrix_range_, const Matrix_Var_ & empty_value_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				empty_value(empty_value_) {}
			constexpr MazeDig(const ::dtl::base::MatrixRange& matrix_range_, const Matrix_Var_& empty_value_, const Matrix_Var_& wall_value_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				empty_value(empty_value_), wall_value(wall_value_) {}
			constexpr MazeDig(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_) {}
			constexpr MazeDig(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_, const Matrix_Var_& empty_value_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_),
				empty_value(empty_value_) {}
			constexpr MazeDig(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_, const Matrix_Var_& empty_value_, const Matrix_Var_& wall_value_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_),
				empty_value(empty_value_), wall_value(wall_value_) {}
		};
	}
}

#endif //Included Dungeon Template Library