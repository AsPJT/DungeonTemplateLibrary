/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANGE_RECT_BASE_SIMPLE_ROGUE_LIKE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANGE_RECT_BASE_SIMPLE_ROGUE_LIKE_HPP

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
		class RectBaseSimpleRogueLike : public ::dtl::range::BasicRect<Derived_> {
		private:

			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using RectBase_t = ::dtl::range::BasicRect<Derived_>;


		protected:


			///// メンバ変数 (Member Variable) /////

			Matrix_Var_ room_value{};
			Matrix_Var_ road_value{};

			::dtl::type::size division_min{ 3 };
			::dtl::type::size division_rand_max{ 4 };
			::dtl::type::size room_min_x{ 5 };
			::dtl::type::size room_rand_max_x{ 2 };
			::dtl::type::size room_min_y{ 5 };
			::dtl::type::size room_rand_max_y{ 2 };

		public:


			///// メンバ変数の値を取得 (Get Value) /////

			template<typename Matrix_Int1_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getRoom(Matrix_Int1_& value_) noexcept {
				value_ = static_cast<Matrix_Int1_>(this->room_value);
				return static_cast<Derived_&>(*this);
			}
			template<typename Matrix_Int1_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getWay(Matrix_Int1_& value_) noexcept {
				value_ = static_cast<Matrix_Int1_>(this->road_value);
				return static_cast<Derived_&>(*this);
			}

			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getRoom() const noexcept {
				return this->room_value;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getWay() const noexcept {
				return this->road_value;
			}

			DTL_VERSIONING_CPP17_NODISCARD
				constexpr ::dtl::base::RogueLikeList<Matrix_Var_> getValue() const noexcept {
				return this->room_value;
			}


			///// 消去 (Clear) /////

			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearRoom() noexcept {
				const Matrix_Var_ elephant_{};
				this->room_value = elephant_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearWay() noexcept {
				const Matrix_Var_ giraffe_{};
				this->road_value = giraffe_;
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
				this->clearRoom();
				this->clearWay();
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
				Derived_& setRoom(const Matrix_Var_& elephant_) noexcept {
				this->room_value = elephant_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setWay(const Matrix_Var_& giraffe_) noexcept {
				this->road_value = giraffe_;
				return static_cast<Derived_&>(*this);
			}

			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setValue(const Matrix_Var_& elephant_) noexcept {
				this->room_value = elephant_;
				return static_cast<Derived_&>(*this);
			}

			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setRogueLike(const ::dtl::type::size division_min_, const ::dtl::type::size division_rand_max_, const ::dtl::type::size room_min_x_, const ::dtl::type::size room_rand_max_x_, const ::dtl::type::size room_min_y_, const ::dtl::type::size room_rand_max_y_) noexcept {
				division_min = division_min_;
				division_rand_max = division_rand_max_;
				room_min_x = room_min_x_;
				room_rand_max_x = room_rand_max_x_;
				room_min_y = room_min_y_;
				room_rand_max_y = room_rand_max_y_;
				return static_cast<Derived_&>(*this);
			}


			///// コンストラクタ (Constructor) /////

			RectBaseSimpleRogueLike() = default;
			constexpr explicit RectBaseSimpleRogueLike(const Matrix_Var_& room_value_) noexcept
				:room_value(room_value_) {}
			constexpr RectBaseSimpleRogueLike(const Matrix_Var_& room_value_, const Matrix_Var_& road_value_) noexcept
				:room_value(room_value_), road_value(road_value_) {}

			constexpr RectBaseSimpleRogueLike(const Matrix_Var_& room_value_, const Matrix_Var_& road_value_, const ::dtl::type::size division_min_, const ::dtl::type::size division_rand_max_, const ::dtl::type::size room_min_x_, const ::dtl::type::size room_rand_max_x_, const ::dtl::type::size room_min_y_, const ::dtl::type::size room_rand_max_y_) noexcept
				:room_value(room_value_), road_value(road_value_),
				division_min(division_min_),
				division_rand_max(division_rand_max_),
				room_min_x(room_min_x_),
				room_rand_max_x(room_rand_max_x_),
				room_min_y(room_min_y_),
				room_rand_max_y(room_rand_max_y_) {}

			constexpr explicit RectBaseSimpleRogueLike(const ::dtl::base::MatrixRange& matrix_range_) noexcept
				:RectBase_t(matrix_range_) {}
			constexpr RectBaseSimpleRogueLike(const ::dtl::base::MatrixRange& matrix_range_, const Matrix_Var_& room_value_) noexcept
				:RectBase_t(matrix_range_),
				room_value(room_value_) {}
			constexpr RectBaseSimpleRogueLike(const ::dtl::base::MatrixRange& matrix_range_, const Matrix_Var_& room_value_, const Matrix_Var_& road_value_) noexcept
				:RectBase_t(matrix_range_),
				room_value(room_value_), road_value(road_value_) {}

			constexpr RectBaseSimpleRogueLike(const ::dtl::base::MatrixRange& matrix_range_, const Matrix_Var_& room_value_, const Matrix_Var_& road_value_, const ::dtl::type::size division_min_, const ::dtl::type::size division_rand_max_, const ::dtl::type::size room_min_x_, const ::dtl::type::size room_rand_max_x_, const ::dtl::type::size room_min_y_, const ::dtl::type::size room_rand_max_y_) noexcept
				:RectBase_t(matrix_range_),
				room_value(room_value_), road_value(road_value_),
				division_min(division_min_),
				division_rand_max(division_rand_max_),
				room_min_x(room_min_x_),
				room_rand_max_x(room_rand_max_x_),
				room_min_y(room_min_y_),
				room_rand_max_y(room_rand_max_y_) {}

			constexpr RectBaseSimpleRogueLike(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept
				:RectBase_t(end_x_, end_y_, width_, height_) {}

		};
	}
}

#endif //Included Dungeon Template Library
