/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_MATRIX_WRAPPER_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_MATRIX_WRAPPER_HPP

/* Character Code : UTF-8 (BOM) */
/* Bug Check : not checked */

#include <cassert>
#include <cstddef>
#include <array>
#include <type_traits>
#include <Macros/constexpr.hpp>

//共有データ
namespace dtl {
	inline namespace utility {

		// ネストした std::array 用別名

		template<typename Matrix_Int_, std::size_t max_x_, std::size_t max_y_>
		using array2D = std::array<std::array<Matrix_Int_, max_x_>, max_y_>;

		template<typename Matrix_Int_, std::size_t max_l_, std::size_t max_x_, std::size_t max_y_>
		using array3D = std::array<std::array<std::array<Matrix_Int_, max_l_>, max_x_>, max_y_>;


		// Detection Ideom 用ユーティリティ

		template <class... Types>
		struct voidHelper {
			using type = void;
		};

		template <class... Types>
		using void_t = typename voidHelper<Types...>::type;


		// ネストした std::array 判別用トレイツ

		template<typename Matrix_>
		struct is_Array2D : std::false_type {};

		template<typename Matrix_Int_, std::size_t max_y_, std::size_t max_x_>
		struct is_Array2D<array2D<Matrix_Int_, max_x_, max_y_>> : std::true_type {};

		template<typename Matrix_>
		struct is_Array3D : std::false_type {};

		template<typename Matrix_Int_, std::size_t max_y_, std::size_t max_x_, std::size_t max_l_>
		struct is_Array3D<array3D<Matrix_Int_, max_l_, max_x_, max_y_>> : std::true_type {};


		// std::array 以外の STL コンテナ判別用トレイツ

		template<typename Matrix_, typename = void>
		struct is_STL2D : std::false_type {};

		template<typename Matrix_>
		struct is_STL2D<Matrix_, void_t<typename Matrix_::value_type::value_type>>
		: std::conditional<is_Array2D<Matrix_>::value, std::false_type, std::is_integral<typename Matrix_::value_type::value_type>>::type {};

		template<typename Matrix_, typename = void>
		struct is_STL3D : std::false_type {};

		template<typename Matrix_>
		struct is_STL3D<Matrix_, void_t<typename Matrix_::value_type::value_type::value_type>>
		: std::conditional<is_Array3D<Matrix_>::value, std::false_type, std::is_integral<typename Matrix_::value_type::value_type::value_type>>::type {};


		// 要素アクセス用ベースクラス

		template<typename Matrix_, typename Matrix_Int_, typename Index_Size_>
		struct MatrixBase {
			DTL_VERSIONING_CPP14_CONSTEXPR
			void set(const Index_Size_ point_x_, const Index_Size_ point_y_, const Matrix_Int_ value_) noexcept {
				static_cast<Matrix_&>(*this)(point_x_, point_y_) = value_;
			}
			template<typename Function_>
			DTL_VERSIONING_CPP14_CONSTEXPR
			void set(const Index_Size_ point_x_, const Index_Size_ point_y_, const Matrix_Int_ value_, Function_&& function_) noexcept {
				if (function_(static_cast<Matrix_&>(*this)(point_x_, point_y_)))
					static_cast<Matrix_&>(*this)(point_x_, point_y_) = value_;
			}
		};


		// Matrix 用ラッパークラス

		template<typename Matrix_, typename = void>
		struct MatrixWrapper;

		// 2次元配列
		template<typename Matrix_Int_, std::size_t max_y_, std::size_t max_x_>
		struct MatrixWrapper<Matrix_Int_[max_y_][max_x_]>
			: MatrixBase<MatrixWrapper<Matrix_Int_[max_y_][max_x_]>, Matrix_Int_, std::size_t> {
			using Matrix = Matrix_Int_[max_y_][max_x_];
			using Matrix_Int = Matrix_Int_;
			using Index_Size = std::size_t;
			using is_jagged = std::false_type;
			constexpr MatrixWrapper(Matrix& mat) noexcept : mat(mat) {}
			DTL_VERSIONING_CPP14_CONSTEXPR
			MatrixWrapper(Matrix& mat, const Index_Size max_x, const Index_Size max_y) : mat(mat) { assert(max_x_ == max_x); assert(max_y_ == max_y); }
			constexpr Index_Size getX() const noexcept { return max_x_; }
			constexpr Index_Size getY() const noexcept { return max_y_; }
			Matrix& mat;
			Matrix_Int& operator()(Index_Size x, Index_Size y) noexcept { return mat[y][x]; }
		};

		// 2次元配列(サイズ不明)
		template<typename Matrix_Int_, std::size_t max_x_>
		struct MatrixWrapper<Matrix_Int_(*)[max_x_]>
			: MatrixBase<MatrixWrapper<Matrix_Int_(*)[max_x_]>, Matrix_Int_, std::size_t> {
			using Matrix = Matrix_Int_(*)[max_x_];
			using Matrix_Int = Matrix_Int_;
			using Index_Size = std::size_t;
			using is_jagged = std::false_type;
			Matrix mat;
			Index_Size max_y_;
			DTL_VERSIONING_CPP14_CONSTEXPR
			MatrixWrapper(Matrix mat, const Index_Size max_x, const Index_Size max_y) : mat(mat), max_y_(max_y) { assert(max_x_ == max_x); }
			constexpr Index_Size getX() const noexcept { return max_x_; }
			constexpr Index_Size getY() const noexcept { return max_y_; }
			Matrix_Int& operator()(Index_Size x, Index_Size y) noexcept { return mat[y][x]; }
		};

		// 3次元配列
		template<typename Matrix_Int_, std::size_t max_y_, std::size_t max_x_, std::size_t max_l_>
		struct MatrixWrapper<Matrix_Int_[max_y_][max_x_][max_l_]>
			: MatrixBase<MatrixWrapper<Matrix_Int_[max_y_][max_x_][max_l_]>, Matrix_Int_, std::size_t> {
			using Matrix = Matrix_Int_[max_y_][max_x_][max_l_];
			using Matrix_Int = Matrix_Int_;
			using Index_Size = std::size_t;
			using is_jagged = std::false_type;
			Matrix& mat;
			Index_Size layer_;
			constexpr MatrixWrapper(Matrix& mat, const Index_Size layer) noexcept : mat(mat), layer_(layer) {}
			DTL_VERSIONING_CPP14_CONSTEXPR
			MatrixWrapper(Matrix& mat, const Index_Size layer, const Index_Size max_x, const Index_Size max_y) : mat(mat), layer_(layer) { assert(max_x_ == max_x); assert(max_y_ == max_y); }
			constexpr Index_Size getX() const noexcept { return max_x_; }
			constexpr Index_Size getY() const noexcept { return max_y_; }
			Matrix_Int& operator()(Index_Size x, Index_Size y) noexcept { return mat[y][x][layer_]; }
		};

		// 3次元配列(サイズ不明)
		template<typename Matrix_Int_, std::size_t max_x_, std::size_t max_l_>
		struct MatrixWrapper<Matrix_Int_(*)[max_x_][max_l_]>
			: MatrixBase<MatrixWrapper<Matrix_Int_(*)[max_x_][max_l_]>, Matrix_Int_, std::size_t> {
			using Matrix = Matrix_Int_(*)[max_x_][max_l_];
			using Matrix_Int = Matrix_Int_;
			using Index_Size = std::size_t;
			using is_jagged = std::false_type;
			Matrix mat;
			Index_Size layer_;
			Index_Size max_y_;
			DTL_VERSIONING_CPP14_CONSTEXPR
			MatrixWrapper(Matrix mat, const Index_Size layer, const Index_Size max_x, const Index_Size max_y) : mat(mat), layer_(layer), max_y_(max_y) { assert(max_x_ == max_x); }
			constexpr Index_Size getX() const noexcept { return max_x_; }
			constexpr Index_Size getY() const noexcept { return max_y_; }
			Matrix_Int& operator()(Index_Size x, Index_Size y) noexcept { return mat[y][x][layer_]; }
		};

		// 2次元 std::array
		template<typename Matrix_Int_, std::size_t max_y_, std::size_t max_x_>
		struct MatrixWrapper<array2D<Matrix_Int_, max_x_, max_y_>>
			: MatrixBase<MatrixWrapper<array2D<Matrix_Int_, max_x_, max_y_>>, Matrix_Int_, std::size_t> {
			using Matrix = array2D<Matrix_Int_, max_x_, max_y_>;
			using Matrix_Int = Matrix_Int_;
			using Index_Size = std::size_t;
			using is_jagged = std::false_type;
			Matrix& mat;
			constexpr MatrixWrapper(Matrix& mat) noexcept : mat(mat) {}
			DTL_VERSIONING_CPP14_CONSTEXPR
			MatrixWrapper(Matrix& mat, const Index_Size max_x, const Index_Size max_y) : mat(mat) { assert(max_x_ == max_x); assert(max_y_ == max_y); }
			constexpr Index_Size getX() const noexcept { return max_x_; }
			constexpr Index_Size getY() const noexcept { return max_y_; }
			Matrix_Int& operator()(Index_Size x, Index_Size y) noexcept { return mat[y][x]; }
		};

		// 3次元 std::array
		template<typename Matrix_Int_, std::size_t max_y_, std::size_t max_x_, std::size_t max_l_>
		struct MatrixWrapper<array3D<Matrix_Int_, max_l_, max_x_, max_y_>>
			: MatrixBase<MatrixWrapper<array3D<Matrix_Int_, max_l_, max_x_, max_y_>>, Matrix_Int_, std::size_t> {
			using Matrix = array3D<Matrix_Int_, max_l_, max_x_, max_y_>;
			using Matrix_Int = Matrix_Int_;
			using Index_Size = std::size_t;
			using is_jagged = std::false_type;
			Matrix& mat;
			Index_Size layer_;
			constexpr MatrixWrapper(Matrix& mat, const Index_Size layer) noexcept : mat(mat), layer_(layer) {}
			constexpr Index_Size getX() const noexcept { return max_x_; }
			constexpr Index_Size getY() const noexcept { return max_y_; }
			Matrix_Int& operator()(Index_Size x, Index_Size y) noexcept { return mat[y][x][layer_]; }
		};

		// 1次元配列
		template<typename Matrix_Int_, std::size_t max_len_>
		struct MatrixWrapper<Matrix_Int_[max_len_]>
			: MatrixBase<MatrixWrapper<Matrix_Int_[max_len_]>, Matrix_Int_, std::size_t> {
			using Matrix = Matrix_Int_[max_len_];
			using Matrix_Int = Matrix_Int_;
			using Index_Size = std::size_t;
			using is_jagged = std::false_type;
			Matrix& mat;
			Index_Size max_x_;
			DTL_VERSIONING_CPP14_CONSTEXPR
			MatrixWrapper(Matrix& mat, const Index_Size max_x, const Index_Size max_y) : mat(mat), max_x_(max_x) { assert(max_x * max_y == max_len_); }
			constexpr Index_Size getX() const noexcept { return max_x_; }
			constexpr Index_Size getY() const noexcept { return max_len_ / max_x_; }
			Matrix_Int& operator()(Index_Size x, Index_Size y) noexcept { return mat[y * max_x_ + x]; }
		};

		// 1次元配列(サイズ不明)
		template<typename Matrix_Int_>
		struct MatrixWrapper<Matrix_Int_*>
			: MatrixBase<MatrixWrapper<Matrix_Int_*>, Matrix_Int_, std::size_t> {
			using Matrix = Matrix_Int_*;
			using Matrix_Int = Matrix_Int_;
			using Index_Size = std::size_t;
			using is_jagged = std::false_type;
			Matrix mat;
			Index_Size max_x_;
			Index_Size max_y_;
			constexpr MatrixWrapper(Matrix mat, const Index_Size max_x, const Index_Size max_y) noexcept : mat(mat), max_x_(max_x), max_y_(max_y) {}
			constexpr Index_Size getX() const noexcept { return max_x_; }
			constexpr Index_Size getY() const noexcept { return max_y_; }
			Matrix_Int& operator()(Index_Size x, Index_Size y) noexcept { return mat[y * max_x_ + x]; }
		};

		// 2次元 STL コンテナ
		template<typename Matrix_>
		struct MatrixWrapper<Matrix_, typename std::enable_if<is_STL2D<Matrix_>::value>::type>
			: MatrixBase<MatrixWrapper<Matrix_, typename std::enable_if<is_STL2D<Matrix_>::value>::type>, typename Matrix_::value_type::value_type, typename Matrix_::size_type> {
			using Matrix = Matrix_;
			using Matrix_Int = typename Matrix_::value_type::value_type;
			using Index_Size = typename Matrix_::size_type;
			using is_jagged = std::true_type;
			Matrix& mat;
			constexpr MatrixWrapper(Matrix& mat) noexcept : mat(mat) {}
			constexpr Index_Size getX() const noexcept { return mat.size() == 0 ? 0 : mat[0].size(); }
			constexpr Index_Size getX(const Index_Size row) const noexcept { return row >= mat.size() ? 0 : mat[row].size(); }
			constexpr Index_Size getY() const noexcept { return mat.size(); }
			Matrix_Int& operator()(Index_Size x, Index_Size y) noexcept { return mat[y][x]; }
		};

		// 3次元 STL コンテナ
		template<typename Matrix_>
			struct MatrixWrapper<Matrix_, typename std::enable_if<is_STL3D<Matrix_>::value>::type>
			: MatrixBase<MatrixWrapper<Matrix_, typename std::enable_if<is_STL3D<Matrix_>::value>::type>, typename Matrix_::value_type::value_type, typename Matrix_::size_type> {
			using Matrix = Matrix_;
			using Matrix_Int = typename Matrix_::value_type::value_type::value_type;
			using Index_Size = typename Matrix::size_type;
			using is_jagged = std::true_type;
			Matrix& mat;
			Index_Size layer_;
			constexpr MatrixWrapper(Matrix& mat, const Index_Size layer) noexcept : mat(mat), layer_(layer) {}
			constexpr Index_Size getX() const noexcept { return mat.size() == 0 ? 0 : mat[0].size(); }
			constexpr Index_Size getX(const Index_Size row) const noexcept { return row >= mat.size() ? 0 : mat[row].size(); }
			constexpr Index_Size getY() const noexcept { return mat.size(); }
			Matrix_Int& operator()(Index_Size x, Index_Size y) noexcept { return mat[y][x][layer_]; }
		};

		template<typename Matrix_, typename... Args_>
		constexpr MatrixWrapper<typename std::remove_reference<Matrix_>::type> makeWrapper(Matrix_&& mat, Args_&&... args_) {
			return MatrixWrapper<typename std::remove_reference<Matrix_>::type>(mat, std::forward<Args_>(args_)...);
		}
	}
}

#endif //Included Dungeon Template Library
