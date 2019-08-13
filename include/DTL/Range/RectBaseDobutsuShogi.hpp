/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANGE_RECT_BASE_DOBUTSU_SHOGI_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANGE_RECT_BASE_DOBUTSU_SHOGI_HPP

#include <DTL/Base/DobutsuShogi.hpp>
#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Range/BasicRect.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace range { //"dtl::range"名前空間に属する

		template<typename Derived_, typename Matrix_Var_>
		class RectBaseDobutsuShogi : public ::dtl::range::BasicRect<Derived_> {
		private:

			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using RectBase_t = ::dtl::range::BasicRect<Derived_>;


		protected:


			///// メンバ変数 (Member Variable) /////

			::dtl::base::DobutsuShogiList<Matrix_Var_> dobutsuShogiList{};

		public:


			///// メンバ変数の値を取得 (Get Value) /////

			template<typename Matrix_Int1_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getChick1(Matrix_Int1_& value_) noexcept {
				value_ = static_cast<Matrix_Int1_>(this->dobutsuShogiList.chick_1);
				return static_cast<Derived_&>(*this);
			}
			template<typename Matrix_Int1_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getChick2(Matrix_Int1_& value_) noexcept {
				value_ = static_cast<Matrix_Int1_>(this->dobutsuShogiList.chick_2);
				return static_cast<Derived_&>(*this);
			}
			template<typename Matrix_Int1_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getElephant1(Matrix_Int1_& value_) noexcept {
				value_ = static_cast<Matrix_Int1_>(this->dobutsuShogiList.elephant_1);
				return static_cast<Derived_&>(*this);
			}
			template<typename Matrix_Int1_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getElephant2(Matrix_Int1_& value_) noexcept {
				value_ = static_cast<Matrix_Int1_>(this->dobutsuShogiList.elephant_2);
				return static_cast<Derived_&>(*this);
			}
			template<typename Matrix_Int1_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getGiraffe1(Matrix_Int1_& value_) noexcept {
				value_ = static_cast<Matrix_Int1_>(this->dobutsuShogiList.giraffe_1);
				return static_cast<Derived_&>(*this);
			}
			template<typename Matrix_Int1_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getGiraffe2(Matrix_Int1_& value_) noexcept {
				value_ = static_cast<Matrix_Int1_>(this->dobutsuShogiList.giraffe_2);
				return static_cast<Derived_&>(*this);
			}
			template<typename Matrix_Int1_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getHen1(Matrix_Int1_& value_) noexcept {
				value_ = static_cast<Matrix_Int1_>(this->dobutsuShogiList.hen_1);
				return static_cast<Derived_&>(*this);
			}
			template<typename Matrix_Int1_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getHen2(Matrix_Int1_& value_) noexcept {
				value_ = static_cast<Matrix_Int1_>(this->dobutsuShogiList.hen_2);
				return static_cast<Derived_&>(*this);
			}
			template<typename Matrix_Int1_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getLion1(Matrix_Int1_& value_) noexcept {
				value_ = static_cast<Matrix_Int1_>(this->dobutsuShogiList.lion_1);
				return static_cast<Derived_&>(*this);
			}
			template<typename Matrix_Int1_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getLion2(Matrix_Int1_& value_) noexcept {
				value_ = static_cast<Matrix_Int1_>(this->dobutsuShogiList.lion_2);
				return static_cast<Derived_&>(*this);
			}

			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getChick1() const noexcept {
				return this->dobutsuShogiList.chick_1;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getChick2() const noexcept {
				return this->dobutsuShogiList.chick_2;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getElephant1() const noexcept {
				return this->dobutsuShogiList.elephant_1;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getElephant2() const noexcept {
				return this->dobutsuShogiList.elephant_2;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getGiraffe1() const noexcept {
				return this->dobutsuShogiList.giraffe_1;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getGiraffe2() const noexcept {
				return this->dobutsuShogiList.giraffe_2;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getHen1() const noexcept {
				return this->dobutsuShogiList.hen_1;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getHen2() const noexcept {
				return this->dobutsuShogiList.hen_2;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getLion1() const noexcept {
				return this->dobutsuShogiList.lion_1;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getLion2() const noexcept {
				return this->dobutsuShogiList.lion_2;
			}

			DTL_VERSIONING_CPP17_NODISCARD
				constexpr ::dtl::base::DobutsuShogiList<Matrix_Var_> getValue() const noexcept {
				return this->dobutsuShogiList;
			}


			///// 消去 (Clear) /////


			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearChick1() noexcept {
				const Matrix_Var_ chick_{};
				this->dobutsuShogiList.chick_1 = chick_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearChick2() noexcept {
				const Matrix_Var_ chick_{};
				this->dobutsuShogiList.chick_2 = chick_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearElephant1() noexcept {
				const Matrix_Var_ elephant_{};
				this->dobutsuShogiList.elephant_1 = elephant_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearElephant2() noexcept {
				const Matrix_Var_ elephant_{};
				this->dobutsuShogiList.elephant_2 = elephant_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearGiraffe1() noexcept {
				const Matrix_Var_ giraffe_{};
				this->dobutsuShogiList.giraffe_1 = giraffe_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearGiraffe2() noexcept {
				const Matrix_Var_ giraffe_{};
				this->dobutsuShogiList.giraffe_2 = giraffe_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearHen1() noexcept {
				const Matrix_Var_ hen_{};
				this->dobutsuShogiList.hen_1 = hen_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearHen2() noexcept {
				const Matrix_Var_ hen_{};
				this->dobutsuShogiList.hen_2 = hen_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearLion1() noexcept {
				const Matrix_Var_ lion_{};
				this->dobutsuShogiList.lion_1 = lion_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearLion2() noexcept {
				const Matrix_Var_ lion_{};
				this->dobutsuShogiList.lion_2 = lion_;
				return static_cast<Derived_&>(*this);
			}

			/*#######################################################################################
				[概要] 塗り値を初期値に戻す(描画値を消去する)。
				[戻り値] 戻り値の型は 当クラスの参照値 である。
				[Summary] Resets the drawing value to the initial value (deletes the drawing value).
				[Return value] The return type is a reference value of this class.
			#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearValue() noexcept {
				const ::dtl::base::DobutsuShogiList<Matrix_Var_> new_draw_value{};
				this->dobutsuShogiList = new_draw_value;
				return static_cast<Derived_&>(*this);
			}

			/*#######################################################################################
				[概要] 全ての値を初期値に戻す。
				[戻り値] 戻り値の型は 当クラスの参照値 である。
				[Summary] Reset all values to their initial values.
				[Return value] The return type is a reference value of this class.
			#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clear() noexcept {
				this->clearRange();
				this->clearValue();
				return static_cast<Derived_&>(*this);
			}


			///// 代入 /////

			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setChick1(const Matrix_Var_& chick_) noexcept {
				return this->dobutsuShogiList.chick_1 = chick_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setChick2(const Matrix_Var_& chick_) noexcept {
				return this->dobutsuShogiList.chick_2 = chick_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setElephant1(const Matrix_Var_& elephant_) noexcept {
				return this->dobutsuShogiList.elephant_1 = elephant_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setElephant2(const Matrix_Var_& elephant_) noexcept {
				return this->dobutsuShogiList.elephant_2 = elephant_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setGiraffe1(const Matrix_Var_& giraffe_) noexcept {
				return this->dobutsuShogiList.giraffe_1 = giraffe_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setGiraffe2(const Matrix_Var_& giraffe_) noexcept {
				return this->dobutsuShogiList.giraffe_2 = giraffe_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setHen1(const Matrix_Var_& hen_) noexcept {
				return this->dobutsuShogiList.hen_1 = hen_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setHen2(const Matrix_Var_& hen_) noexcept {
				return this->dobutsuShogiList.hen_2 = hen_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setLion1(const Matrix_Var_& lion_) noexcept {
				return this->dobutsuShogiList.lion_1 = lion_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setLion2(const Matrix_Var_& lion_) noexcept {
				return this->dobutsuShogiList.lion_2 = lion_;
				return static_cast<Derived_&>(*this);
			}

			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setValue(const ::dtl::base::DobutsuShogiList<Matrix_Var_>& draw_value_) noexcept {
				this->dobutsuShogiList = draw_value_;
				return static_cast<Derived_&>(*this);
			}


			///// コンストラクタ (Constructor) /////

			RectBaseDobutsuShogi() = default;
			constexpr explicit RectBaseDobutsuShogi(const ::dtl::base::MatrixRange& matrix_range_) noexcept
				:RectBase_t(matrix_range_) {}
			constexpr RectBaseDobutsuShogi(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_) noexcept
				:RectBase_t(start_x_, start_y_, width_, height_) {}

			constexpr explicit RectBaseDobutsuShogi(const ::dtl::base::DobutsuShogiList<Matrix_Var_>& draw_value_) noexcept
				:dobutsuShogiList(draw_value_) {}

			constexpr RectBaseDobutsuShogi(
				const Matrix_Var_& chick_1_, const Matrix_Var_& chick_2_,
				const Matrix_Var_& hen_1_, const Matrix_Var_& hen_2_,
				const Matrix_Var_& giraffe_1_, const Matrix_Var_& giraffe_2_,
				const Matrix_Var_& elephant_1_, const Matrix_Var_& elephant_2_,
				const Matrix_Var_& lion_1_, const Matrix_Var_& lion_2_) noexcept :
				dobutsuShogiList(chick_1_, chick_2_, hen_1_, hen_2_, giraffe_1_, giraffe_2_, elephant_1_, elephant_2_, lion_1_, lion_2_) {}

			constexpr RectBaseDobutsuShogi(
				const Matrix_Var_& chick_, const Matrix_Var_& hen_,
				const Matrix_Var_& giraffe_, const Matrix_Var_& elephant_, const Matrix_Var_& lion_) noexcept :
				dobutsuShogiList(chick_, chick_, hen_, hen_, giraffe_, giraffe_, elephant_, elephant_, lion_, lion_) {}

			constexpr RectBaseDobutsuShogi(const ::dtl::base::MatrixRange& matrix_range_, const ::dtl::base::DobutsuShogiList<Matrix_Var_>& draw_value_) noexcept
				:RectBase_t(matrix_range_),
				dobutsuShogiList(draw_value_) {}
			constexpr RectBaseDobutsuShogi(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_, const ::dtl::base::DobutsuShogiList<Matrix_Var_>& draw_value_) noexcept
				:RectBase_t(start_x_, start_y_, width_, height_),
				dobutsuShogiList(draw_value_) {}
		};
	}
}

#endif //Included Dungeon Template Library
