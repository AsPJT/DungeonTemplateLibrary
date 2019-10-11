/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_UTILITY_MATRIX_WRAPPER_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_UTILITY_MATRIX_WRAPPER_HPP

#include <cassert>
#include <array>
#include <bitset>
#include <type_traits>
#include <utility>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Type/EnableIf.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/SizeT.hpp>

#ifdef DTL_USE_BOOST_ARRAY
#include <boost/array.hpp>
#endif

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace utility { //"dtl::utility"名前空間に属する

		// Detection Ideom 用ユーティリティ
		template<typename...>
		struct void_helper {
			using type = void;
		};

		template<typename... Ts>
		using void_t = typename ::dtl::utility::void_helper<Ts...>::type;


		// 型リスト保持用クラステンプレート
		template<typename...>
		struct TList {};


		// 要素型取得用クラステンプレート
		template<typename, typename = void>
		struct to_element {
			static constexpr bool value = false;
		};

		template<typename T>
		struct to_element<T, ::dtl::utility::void_t<decltype(::std::declval<T&>()[0])>> {
			static constexpr bool value = true;
			using type = typename ::std::remove_reference<decltype(::std::declval<T&>()[0])>::type;
		};

		template<typename T>
		using to_element_t = typename ::dtl::utility::to_element<T>::type;


		// Matrix のカテゴリ
		// サイズはコンストラクタ引数で決定(メンバ変数に保持)
		template<typename T>
		struct mcat_fixed {
			using is_jagged = ::std::false_type;

			constexpr ::dtl::type::size get(const T&) const noexcept { return max_; }
			constexpr mcat_fixed(::dtl::type::size max_) noexcept : max_(max_) {}

		private:
			::dtl::type::size max_;
		};

		// サイズはコンパイル時に決定
		template<typename T, ::dtl::type::size N>
		struct mcat_const {
			using is_jagged = ::std::false_type;

			constexpr ::dtl::type::size get(const T&) const noexcept { return N; }
		};

		// サイズはMatrixのメンバ関数で取得
		template<typename T>
		struct mcat_memfn {
			using is_jagged = ::std::true_type;

			constexpr ::dtl::type::size get(const T& v) const noexcept(noexcept(v.size())) { return v.size(); }
		};


		// 共通基底クラステンプレート
		template<typename B, typename V, typename M, typename TY, typename TX>
		struct MatrixWrapperCommon : TX, TY {
			using Index_Size = ::dtl::type::size;
			using is_jagged = typename TX::is_jagged;

			constexpr MatrixWrapperCommon(M& mat, Index_Size max_x, Index_Size max_y) noexcept : TX(max_x), TY(max_y), mat(mat) {}
			constexpr MatrixWrapperCommon(M& mat) noexcept : mat(mat) {}

			constexpr Index_Size getX(const Index_Size pos = 0) const
				noexcept(noexcept(::std::declval<MatrixWrapperCommon>().getY()) && noexcept(::std::declval<TX>().get(::std::declval<M&>()[0]))) {
				return is_jagged::value&& getY() <= pos ? 0 : TX::get(mat[pos]);
			}
			constexpr Index_Size getY() const noexcept(noexcept(::std::declval<TY>().get(::std::declval<M&>()))) {
				return TY::get(mat);
			}

			DTL_VERSIONING_CPP14_CONSTEXPR
				void set(const Index_Size point_x_, const Index_Size point_y_, V value_)
				noexcept(noexcept(::std::declval<B&>()(0, 0) = {})) {
				static_cast<B&>(*this)(point_x_, point_y_) = value_;
			}
			template<typename Function_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void set(const Index_Size point_x_, const Index_Size point_y_, V value_, Function_&& function_)
				noexcept(noexcept(function_(::std::declval<B&>()(0, 0))) && noexcept(::std::declval<B&>()(0, 0) = {})) {
				if (function_(static_cast<B&>(*this)(point_x_, point_y_)))
					static_cast<B&>(*this)(point_x_, point_y_) = value_;
			}
			//4 Add
			DTL_VERSIONING_CPP14_CONSTEXPR
				void set(const Index_Size point_x_, const Index_Size point_y_, V value_, int, int, int, int)
				noexcept(noexcept(::std::declval<B&>()(0, 0) = {})) {
				static_cast<B&>(*this)(point_x_, point_y_) += value_;
			}
			//4 Add (Func)
			template<typename Function_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void set(const Index_Size point_x_, const Index_Size point_y_, V value_, Function_&& function_, int, int, int)
				noexcept(noexcept(function_(::std::declval<B&>()(0, 0))) && noexcept(::std::declval<B&>()(0, 0) = {})) {
				if (function_(static_cast<B&>(*this)(point_x_, point_y_)))
					static_cast<B&>(*this)(point_x_, point_y_) += value_;
			}
			//5 Func (Func)
			template<typename Function_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void set(const Index_Size point_x_, const Index_Size point_y_, V value_, Function_&& function_, int, int, int, int)
				noexcept(noexcept(function_(::std::declval<B&>()(0, 0), {})) && noexcept(::std::declval<B&>()(0, 0) = {})) {
				function_(static_cast<B&>(*this)(point_x_, point_y_), value_);
			}
			//6 Other
			template<typename Matrix_, typename Matrix_Var2_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void set(const Index_Size point_x_, const Index_Size point_y_, V value_, Matrix_&& matrix_, Matrix_Var2_, int, int, int, int) {
				matrix_.set(point_x_, point_y_, static_cast<Matrix_Var2_>(value_));
			}

			DTL_VERSIONING_CPP14_CONSTEXPR
				V get(const Index_Size point_x_, const Index_Size point_y_)
				noexcept(noexcept(::std::declval<B&>()(0, 0) = {})) {
				return static_cast<B&>(*this)(point_x_, point_y_);
			}
			template<typename Function_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				V get(const Index_Size point_x_, const Index_Size point_y_, Function_&& function_)
				noexcept(noexcept(function_(::std::declval<B&>()(0, 0))) && noexcept(::std::declval<B&>()(0, 0) = {})) {
				if (function_(static_cast<B&>(*this)(point_x_, point_y_)))
					return static_cast<B&>(*this)(point_x_, point_y_);
			}

			DTL_VERSIONING_CPP14_CONSTEXPR
				void add(const Index_Size point_x_, const Index_Size point_y_, V value_)
				noexcept(noexcept(::std::declval<B&>()(0, 0) = {})) {
				static_cast<B&>(*this)(point_x_, point_y_) += value_;
			}
			template<typename Function_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void add(const Index_Size point_x_, const Index_Size point_y_, V value_, Function_&& function_)
				noexcept(noexcept(function_(::std::declval<B&>()(0, 0))) && noexcept(::std::declval<B&>()(0, 0) = {})) {
				if (function_(static_cast<B&>(*this)(point_x_, point_y_)))
					static_cast<B&>(*this)(point_x_, point_y_) += value_;
			}

			DTL_VERSIONING_CPP14_CONSTEXPR
				void sub(const Index_Size point_x_, const Index_Size point_y_, V value_)
				noexcept(noexcept(::std::declval<B&>()(0, 0) = {})) {
				static_cast<B&>(*this)(point_x_, point_y_) -= value_;
			}
			template<typename Function_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void sub(const Index_Size point_x_, const Index_Size point_y_, V value_, Function_&& function_)
				noexcept(noexcept(function_(::std::declval<B&>()(0, 0))) && noexcept(::std::declval<B&>()(0, 0) = {})) {
				if (function_(static_cast<B&>(*this)(point_x_, point_y_)))
					static_cast<B&>(*this)(point_x_, point_y_) -= value_;
			}

			DTL_VERSIONING_CPP14_CONSTEXPR
				void mul(const Index_Size point_x_, const Index_Size point_y_, V value_)
				noexcept(noexcept(::std::declval<B&>()(0, 0) = {})) {
				static_cast<B&>(*this)(point_x_, point_y_) *= value_;
			}
			template<typename Function_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void mul(const Index_Size point_x_, const Index_Size point_y_, V value_, Function_&& function_)
				noexcept(noexcept(function_(::std::declval<B&>()(0, 0))) && noexcept(::std::declval<B&>()(0, 0) = {})) {
				if (function_(static_cast<B&>(*this)(point_x_, point_y_)))
					static_cast<B&>(*this)(point_x_, point_y_) *= value_;
			}

			DTL_VERSIONING_CPP14_CONSTEXPR
				void div(const Index_Size point_x_, const Index_Size point_y_, V value_)
				noexcept(noexcept(::std::declval<B&>()(0, 0) = {})) {
				static_cast<B&>(*this)(point_x_, point_y_) /= value_;
			}
			template<typename Function_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void div(const Index_Size point_x_, const Index_Size point_y_, V value_, Function_&& function_)
				noexcept(noexcept(function_(::std::declval<B&>()(0, 0))) && noexcept(::std::declval<B&>()(0, 0) = {})) {
				if (function_(static_cast<B&>(*this)(point_x_, point_y_)))
					static_cast<B&>(*this)(point_x_, point_y_) /= value_;
			}

			DTL_VERSIONING_CPP14_CONSTEXPR
				void mod(const Index_Size point_x_, const Index_Size point_y_, V value_)
				noexcept(noexcept(::std::declval<B&>()(0, 0) = {})) {
				static_cast<B&>(*this)(point_x_, point_y_) %= value_;
			}
			template<typename Function_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void mod(const Index_Size point_x_, const Index_Size point_y_, V value_, Function_&& function_)
				noexcept(noexcept(function_(::std::declval<B&>()(0, 0))) && noexcept(::std::declval<B&>()(0, 0) = {})) {
				if (function_(static_cast<B&>(*this)(point_x_, point_y_)))
					static_cast<B&>(*this)(point_x_, point_y_) %= value_;
			}

		protected:
			M& mat;
		};


		// MatrixWrapperの1次元用基底クラステンプレート
		template<typename V, typename M, typename = ::dtl::utility::void_t<decltype(static_cast<V>(::std::declval<M&>()[0]))>>
		struct MatrixWrapperBase1 : ::dtl::utility::MatrixWrapperCommon<MatrixWrapperBase1<V, M>, V, M, ::dtl::utility::mcat_fixed<M>, ::dtl::utility::mcat_fixed<::dtl::utility::to_element_t<M>>> {
			using Base_t = ::dtl::utility::MatrixWrapperCommon<MatrixWrapperBase1, V, M, ::dtl::utility::mcat_fixed<M>, ::dtl::utility::mcat_fixed<::dtl::utility::to_element_t<M>>>;
			using Index_Size = typename Base_t::Index_Size;

			using Base_t::Base_t;
			decltype(::std::declval<M&>()[0]) operator()(Index_Size x, Index_Size y) noexcept(noexcept(::std::declval<M&>()[0])) { return Base_t::mat[y * Base_t::getX() + x]; }
			typename std::add_const<decltype(::std::declval<M&>()[0])>::type operator()(Index_Size x, Index_Size y) const noexcept(noexcept(::std::declval<M&>()[0])) { return Base_t::mat[y * Base_t::getX() + x]; }
		};

		// MatrixWrapperの2次元用基底クラステンプレート
		template<typename V, typename M, typename TY, typename TX, typename = ::dtl::utility::void_t<decltype(static_cast<V>(::std::declval<M&>()[0][0]))>>
		struct MatrixWrapperBase2 : ::dtl::utility::MatrixWrapperCommon<MatrixWrapperBase2<V, M, TY, TX>, V, M, TY, TX> {
			using Base_t = ::dtl::utility::MatrixWrapperCommon<MatrixWrapperBase2, V, M, TY, TX>;
			using Index_Size = typename Base_t::Index_Size;

			using Base_t::Base_t;
			decltype(::std::declval<M&>()[0][0]) operator()(Index_Size x, Index_Size y) noexcept(noexcept(::std::declval<M&>()[0][0])) { return Base_t::mat[y][x]; } //todo
			typename std::add_const<decltype(::std::declval<M&>()[0][0])>::type operator()(Index_Size x, Index_Size y) const noexcept(noexcept(::std::declval<M&>()[0][0])) { return Base_t::mat[y][x]; }
		};

		// MatrixWrapperの3次元用基底クラステンプレート
		template<typename V, typename M, typename TY, typename TX, typename = ::dtl::utility::void_t<decltype(static_cast<V>(::std::declval<M&>()[0][0][0]))>>
		struct MatrixWrapperBase3 : ::dtl::utility::MatrixWrapperCommon<MatrixWrapperBase3<V, M, TY, TX>, V, M, TY, TX> {
			using Base_t = ::dtl::utility::MatrixWrapperCommon<MatrixWrapperBase3, V, M, TY, TX>;
			using Index_Size = typename Base_t::Index_Size;

			constexpr MatrixWrapperBase3(M& mat, Index_Size draw_layer, Index_Size max_x, Index_Size max_y) noexcept : Base_t(mat, max_x, max_y), draw_layer_(draw_layer) {}
			constexpr MatrixWrapperBase3(M& mat, Index_Size draw_layer) noexcept : Base_t(mat), draw_layer_(draw_layer) {}
			decltype(::std::declval<M&>()[0][0][0]) operator()(Index_Size x, Index_Size y) noexcept(noexcept(::std::declval<M&>()[0][0][0])) { return Base_t::mat[y][x][draw_layer_]; }
			typename std::add_const<decltype(::std::declval<M&>()[0][0][0])>::type operator()(Index_Size x, Index_Size y) const noexcept(noexcept(::std::declval<M&>()[0][0][0])) { return Base_t::mat[y][x][draw_layer_]; }

		private:
			Index_Size draw_layer_;
		};


		// Matrix解析用クラステンプレート
		// プライマリテンプレート
		template<typename, typename = TList<>, typename = void>
		struct MatrixWrapperImpl;

		// ポインタ
		template<typename E, typename... Ts>
		struct MatrixWrapperImpl<E*, TList<Ts...>, ::dtl::utility::void_t<::dtl::utility::to_element_t<E*>>> : MatrixWrapperImpl<E, TList<Ts..., ::dtl::utility::mcat_fixed<E*>>> {};

		// 配列
		template<typename E, ::dtl::type::size N, typename... Ts>
		struct MatrixWrapperImpl<E[N], TList<Ts...>, ::dtl::utility::void_t<::dtl::utility::to_element_t<E[N]>>> : MatrixWrapperImpl<E, TList<Ts..., ::dtl::utility::mcat_const<E[N], N>>> {};

		// std::array
		template<typename E, ::dtl::type::size N, typename... Ts>
		struct MatrixWrapperImpl<::std::array<E, N>, TList<Ts...>, ::dtl::utility::void_t<::dtl::utility::to_element_t<::std::array<E, N>>>> : MatrixWrapperImpl<E, TList<Ts..., ::dtl::utility::mcat_const<::std::array<E, N>, N>>> {};

#ifdef DTL_USE_BOOST_ARRAY
		// boost::array
		template<typename E, ::dtl::type::size N, typename... Ts>
		struct MatrixWrapperImpl<boost::array<E, N>, TList<Ts...>, ::dtl::utility::void_t<::dtl::utility::to_element_t<boost::array<E, N>>>> : MatrixWrapperImpl<E, TList<Ts..., ::dtl::utility::mcat_const<boost::array<E, N>, N>>> {};
#endif

		// std::bitset
		template<::dtl::type::size N, typename... Ts>
		struct MatrixWrapperImpl<::std::bitset<N>, TList<Ts...>, ::dtl::utility::void_t<::dtl::utility::to_element_t<::std::bitset<N>>>> : MatrixWrapperImpl<bool, TList<Ts..., ::dtl::utility::mcat_const<::std::bitset<N>, N>>> {};

		// 上記以外
		template<typename T, typename... Ts>
		struct MatrixWrapperImpl<T, TList<Ts...>, ::dtl::utility::void_t<::dtl::utility::to_element_t<T>>> : MatrixWrapperImpl<::dtl::utility::to_element_t<T>, TList<Ts..., ::dtl::utility::mcat_memfn<T>>> {};

		// 1次元
		template<typename T, typename TX>
		struct MatrixWrapperImpl<T, TList<TX>, typename DTL_TYPE_ENABLE_IF<!::dtl::utility::to_element<T>::value>::DTL_TYPE_EITYPE> {
			template<typename V, typename M>
			using Base_t = ::dtl::utility::MatrixWrapperBase1<V, M>;
		};

		// 2次元
		template<typename T, typename TY, typename TX>
		struct MatrixWrapperImpl<T, TList<TY, TX>, typename DTL_TYPE_ENABLE_IF<!::dtl::utility::to_element<T>::value>::DTL_TYPE_EITYPE> {
			template<typename V, typename M>
			using Base_t = ::dtl::utility::MatrixWrapperBase2<V, M, TY, TX>;
		};

		// 3次元
		template<typename T, typename TY, typename TX, typename TL>
		struct MatrixWrapperImpl<T, TList<TY, TX, TL>, typename DTL_TYPE_ENABLE_IF<!::dtl::utility::to_element<T>::value>::DTL_TYPE_EITYPE> {
			template<typename V, typename M>
			using Base_t = ::dtl::utility::MatrixWrapperBase3<V, M, TY, TX>;
		};


		// MatrixWrapperのプライマリテンプレート。2 or 3次元用。MatrixWrapperImpl::Base_tに委譲
		template<typename V, typename M, ::dtl::type::size N, typename = void>
		struct MatrixWrapper : ::dtl::utility::MatrixWrapperImpl<M>::template Base_t<V, M> {
			using Base_t = typename ::dtl::utility::MatrixWrapperImpl<M>::template Base_t<V, M>;

			using Base_t::Base_t;
		};

		// 引数2個、1次元用。MatrixWrapperBase1に委譲
		template<typename V, typename M>
		struct MatrixWrapper<V, M, 2, typename DTL_TYPE_ENABLE_IF<!::dtl::utility::to_element<::dtl::utility::to_element_t<M>>::value>::DTL_TYPE_EITYPE>
			: ::dtl::utility::MatrixWrapperBase1<V, M> {
			using Base_t = ::dtl::utility::MatrixWrapperBase1<V, M>;

			using Base_t::Base_t;
		};

		// 引数2個、2次元用。MatrixWrapperBase2に委譲
		template<typename V, typename M>
		struct MatrixWrapper<V, M, 2, typename DTL_TYPE_ENABLE_IF<::dtl::utility::to_element<::dtl::utility::to_element_t<M>>::value>::DTL_TYPE_EITYPE>
			: ::dtl::utility::MatrixWrapperBase2<V, M, ::dtl::utility::mcat_fixed<M>, ::dtl::utility::mcat_fixed<::dtl::utility::to_element_t<M>>> {
			using Base_t = ::dtl::utility::MatrixWrapperBase2<V, M, ::dtl::utility::mcat_fixed<M>, ::dtl::utility::mcat_fixed<::dtl::utility::to_element_t<M>>>;

			using Base_t::Base_t;
		};

		// 引数3個、3次元用。MatrixWrapperBase3に委譲
		template<typename V, typename M>
		struct MatrixWrapper<V, M, 3>
			: ::dtl::utility::MatrixWrapperBase3<V, M, ::dtl::utility::mcat_fixed<M>, ::dtl::utility::mcat_fixed<::dtl::utility::to_element_t<M>>> {
			using Base_t = ::dtl::utility::MatrixWrapperBase3<V, M, ::dtl::utility::mcat_fixed<M>, ::dtl::utility::mcat_fixed<::dtl::utility::to_element_t<M>>>;

			using Base_t::Base_t;
		};


		// MatrixWrapper生成用ユーティリティ関数
		template<typename V, typename M, typename... Args>
		constexpr MatrixWrapper<V, typename ::std::remove_reference<M>::type, sizeof...(Args)> makeWrapper(M&& mat, Args&& ... args) {
			return MatrixWrapper<V, typename ::std::remove_reference<M>::type, sizeof...(Args)>(mat, DTL_TYPE_FORWARD<Args>(args)...);
		}
	}
}

#endif //Included Dungeon Template Library
