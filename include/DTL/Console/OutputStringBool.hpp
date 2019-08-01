/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_CONSOLE_OUTPUT_STRING_BOOL_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_CONSOLE_OUTPUT_STRING_BOOL_HPP

#include <DTL/Workaround/cstdioGets.hpp> //Support Clang 3.4.2

#include <string>
#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/Cout.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/SizeT.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace console { //"dtl::console"名前空間に属する

/*#######################################################################################
	[概要] OutputStringBoolとは "Matrixの描画範囲の値を指定した文字列で出力する" 機能を持つクラスである。
	[Summary] OutputStringBool is a class that outputs Matrix values as strings.
#######################################################################################*/
		template<typename Matrix_Var_, typename OutputString_ = ::std::string>
		class OutputStringBool {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			


			///// メンバ変数 (Member Variable) /////

			Index_Size start_x{};
			Index_Size start_y{};
			Index_Size width{};
			Index_Size height{};
			OutputString_ false_string{};
			OutputString_ true_string{};


			///// 代入処理 /////

			template<typename Matrix_>
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr inline Matrix_Var_ outputSTL(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				return matrix_[point_y_][point_x_];
			}
			template<typename Matrix_>
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr inline Matrix_Var_ outputArray(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
				return matrix_[point_y_ * max_x_ + point_x_];
			}
			template<typename Matrix_>
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr inline Matrix_Var_ outputLayer(const Matrix_& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				return matrix_[point_y_][point_x_][layer_];
			}
			template<typename Matrix_>
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr inline Matrix_Var_ outputList(const Matrix_& matrix_) const noexcept {
				return matrix_;
			}

			template<typename Matrix_, typename Function_>
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr inline Matrix_Var_ outputSTL(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_, Function_&& function_) const noexcept {
				return function_(matrix_[point_y_][point_x_]);
			}
			template<typename Matrix_, typename Function_>
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr inline Matrix_Var_ outputArray(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Function_&& function_) const noexcept {
				return function_(matrix_[point_y_ * max_x_ + point_x_]);
			}
			template<typename Matrix_, typename Function_>
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr inline Matrix_Var_ outputLayer(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Function_ && function_) const noexcept {
				return function_(matrix_[point_y_][point_x_][layer_]);
			}
			template<typename Matrix_, typename Function_>
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr inline Matrix_Var_ outputList(const Matrix_& matrix_, Function_&& function_) const noexcept {
				return function_(matrix_);
			}


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename ...Args_>
			bool drawSTL(const Matrix_ & matrix_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					for (Index_Size col{ this->start_x }; col < matrix_[row].size(); ++col)
						DTL_TYPE_COUT << ((this->outputSTL(matrix_, col, row, args_...)) ? this->true_string : this->false_string);
					DTL_TYPE_COUT << '\n';
				}
				DTL_TYPE_COUT_END
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			bool drawWidthSTL(const Matrix_ & matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					for (Index_Size col{ this->start_x }; col < matrix_[row].size() && col < end_x_; ++col)
						DTL_TYPE_COUT << ((this->outputSTL(matrix_, col, row, args_...)) ? this->true_string : this->false_string);
					DTL_TYPE_COUT << '\n';
				}
				DTL_TYPE_COUT_END
				return true;
			}

			//LayerSTL
			template<typename Matrix_, typename ...Args_>
			bool drawLayerSTL(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					for (Index_Size col{ this->start_x }; col < matrix_[row].size(); ++col)
						DTL_TYPE_COUT << ((this->outputLayer(matrix_, layer_, col, row, args_...)) ? this->true_string : this->false_string);
					DTL_TYPE_COUT << '\n';
				}
				DTL_TYPE_COUT_END
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			bool drawLayerWidthSTL(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					for (Index_Size col{ this->start_x }; col < matrix_[row].size() && col < end_x_; ++col)
						DTL_TYPE_COUT << ((this->outputLayer(matrix_, layer_, col, row, args_...)) ? this->true_string : this->false_string);
					DTL_TYPE_COUT << '\n';
				}
				DTL_TYPE_COUT_END
				return true;
			}

			//Normal
			template<typename Matrix_, typename ...Args_>
			bool drawNormal(const Matrix_ & matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						DTL_TYPE_COUT << ((this->outputSTL(matrix_, col, row, args_...)) ? this->true_string : this->false_string);
					DTL_TYPE_COUT << '\n';
				}
				DTL_TYPE_COUT_END
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
			bool drawLayerNormal(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						DTL_TYPE_COUT << ((this->outputLayer(matrix_, layer_, col, row, args_...)) ? this->true_string : this->false_string);
					DTL_TYPE_COUT << '\n';
				}
				DTL_TYPE_COUT_END
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			bool drawArray(const Matrix_ & matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Args_ && ... args_) const noexcept {
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						DTL_TYPE_COUT << ((this->outputArray(matrix_, col, row, max_x_, args_...)) ? this->true_string : this->false_string);
					DTL_TYPE_COUT << '\n';
				}
				DTL_TYPE_COUT_END
				return true;
			}

			//List
			template<typename Matrix_, typename ...Args_>
			bool drawList(const Matrix_& matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_&& ... args_) const noexcept {
				::dtl::type::size row_count{}, col_count{};
				for (const auto& row : matrix_) {
					++row_count;
					if (row_count <= this->start_y) continue;
					if (end_y_ != 1 && row_count >= end_y_) break;
					col_count = 0;
					for (const auto& col : row) {
						++col_count;
						if (col_count <= this->start_x) continue;
						if (end_x_ != 1 && col_count >= end_x_) break;
						DTL_TYPE_COUT << ((this->outputList(col, args_...)) ? this->true_string : this->false_string);
					}
					DTL_TYPE_COUT << '\n';
				}
				DTL_TYPE_COUT_END
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
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr OutputString_ getTrueString() const noexcept {
				return this->true_string;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr OutputString_ getFalseString() const noexcept {
				return this->false_string;
			}


			///// 生成呼び出し (Drawing Function Call) /////

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

			//List
			template<typename Matrix_>
			bool drawList(const Matrix_& matrix_) const noexcept {
				return this->drawList(matrix_, this->start_x + this->width + 1, this->start_y + this->height + 1);
			}
			template<typename Matrix_, typename Function_>
			bool drawOperatorList(const Matrix_& matrix_, Function_&& function_) const noexcept {
				return this->drawList(matrix_, this->start_x + this->width + 1, this->start_y + this->height + 1, function_);
			}


			///// 生成呼び出しファンクタ (Drawing Functor) /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(const Matrix_& matrix_, Args_&& ... args_) const noexcept {
				return this->draw(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
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
				OutputStringBool& clearPointX() noexcept {
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
				OutputStringBool& clearPointY() noexcept {
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
				OutputStringBool& clearWidth() noexcept {
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
				OutputStringBool& clearHeight() noexcept {
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
				OutputStringBool& clearPoint() noexcept {
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
				OutputStringBool& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputStringBool& clearTrueString() noexcept {
				OutputString_ output_string{};
				this->true_string = output_string;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputStringBool& clearFalseString() noexcept {
				OutputString_ output_string{};
				this->false_string = output_string;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputStringBool& clearString() noexcept {
				this->clearTrueString();
				this->clearFalseString();
				return *this;
			}

/*#######################################################################################
	[概要] 全ての値を初期値に戻す。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Reset all values to their initial values.
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputStringBool& clear() noexcept {
				this->clearRange();
				this->clearString();
				return *this;
			}


			///// 代入 /////

			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputStringBool& setPointX(const Index_Size start_x_) noexcept {
				this->start_x = start_x_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputStringBool& setPointY(const Index_Size start_y_) noexcept {
				this->start_y = start_y_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputStringBool& setWidth(const Index_Size width_) noexcept {
				this->width = width_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputStringBool& setHeight(const Index_Size height_) noexcept {
				this->height = height_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputStringBool& setPoint(const Index_Size point_) noexcept {
				this->start_x = point_;
				this->start_y = point_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputStringBool& setPoint(const Index_Size start_x_, const Index_Size start_y_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputStringBool& setRange(const Index_Size start_x_, const Index_Size start_y_, const Index_Size length_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				this->width = length_;
				this->height = length_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputStringBool& setRange(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				this->width = width_;
				this->height = height_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputStringBool& setRange(const ::dtl::base::MatrixRange& matrix_range_) noexcept {
				this->start_x = matrix_range_.x;
				this->start_y = matrix_range_.y;
				this->width = matrix_range_.w;
				this->height = matrix_range_.h;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputStringBool& setTrueString(const OutputString_& output_string_) noexcept {
				this->true_string = output_string_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				OutputStringBool& setFalseString(const OutputString_& output_string_) noexcept {
				this->false_string = output_string_;
				return *this;
			}


			///// コンストラクタ (Constructor) /////

			OutputStringBool() = default;
			constexpr explicit OutputStringBool(const OutputString_ & true_string_) noexcept
				:true_string(true_string_) {}
			constexpr OutputStringBool(const OutputString_ & true_string_, const OutputString_ & false_string_) noexcept
				:false_string(false_string_), true_string(true_string_) {}

			constexpr explicit OutputStringBool(const ::dtl::base::MatrixRange& matrix_range_)
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}
			constexpr OutputStringBool(const ::dtl::base::MatrixRange& matrix_range_, const OutputString_& true_string_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				true_string(true_string_) {}
			constexpr OutputStringBool(const ::dtl::base::MatrixRange& matrix_range_, const OutputString_& true_string_, const OutputString_& false_string_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				false_string(false_string_), true_string(true_string_) {}

			constexpr OutputStringBool(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_) noexcept
				:start_x(start_x_), start_y(start_y_),
				width(width_), height(height_) {}
			constexpr OutputStringBool(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_, const OutputString_ & true_string_) noexcept
				:start_x(start_x_), start_y(start_y_),
				width(width_), height(height_),
				true_string(true_string_) {}
			constexpr OutputStringBool(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_, const OutputString_ & true_string_, const OutputString_ & false_string_) noexcept
				:start_x(start_x_), start_y(start_y_),
				width(width_), height(height_),
				false_string(false_string_), true_string(true_string_) {}
		};
	}
}

#endif //Included Dungeon Template Library