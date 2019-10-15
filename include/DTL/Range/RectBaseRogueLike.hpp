/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANGE_RECT_BASE_ROGUE_LIKE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANGE_RECT_BASE_ROGUE_LIKE_HPP

#include <DTL/Base/RogueLike.hpp>
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
		class RectBaseRogueLike : public ::dtl::range::BasicRect<Derived_> {
		private:

			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using RectBase_t = ::dtl::range::BasicRect<Derived_>;


		protected:


			///// メンバ変数 (Member Variable) /////

			::dtl::base::RogueLikeList<Matrix_Var_> rogueLikeList{};
			Index_Size max_way{ 20 };
			::dtl::base::MatrixRange roomRange{ 3,3,3,3 };
			::dtl::base::MatrixRange wayRange{ 3,3,12,12 };

		public:


			///// メンバ変数の値を取得 (Get Value) /////

			template<typename Matrix_Int1_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getOutsideWall(Matrix_Int1_& value_) noexcept {
				value_ = static_cast<Matrix_Int1_>(this->rogueLikeList.outside_wall_id);
				return static_cast<Derived_&>(*this);
			}
			template<typename Matrix_Int1_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getInsideWall(Matrix_Int1_& value_) noexcept {
				value_ = static_cast<Matrix_Int1_>(this->rogueLikeList.inside_wall_id);
				return static_cast<Derived_&>(*this);
			}
			template<typename Matrix_Int1_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getRoom(Matrix_Int1_& value_) noexcept {
				value_ = static_cast<Matrix_Int1_>(this->rogueLikeList.room_id);
				return static_cast<Derived_&>(*this);
			}
			template<typename Matrix_Int1_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getEntrance(Matrix_Int1_& value_) noexcept {
				value_ = static_cast<Matrix_Int1_>(this->rogueLikeList.entrance_id);
				return static_cast<Derived_&>(*this);
			}
			template<typename Matrix_Int1_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getWay(Matrix_Int1_& value_) noexcept {
				value_ = static_cast<Matrix_Int1_>(this->rogueLikeList.way_id);
				return static_cast<Derived_&>(*this);
			}
			template<typename Matrix_Int1_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getWall(Matrix_Int1_& value_) noexcept {
				value_ = static_cast<Matrix_Int1_>(this->rogueLikeList.outside_wall_id);
				return static_cast<Derived_&>(*this);
			}
			template<typename Matrix_Int1_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getMaxWay(Matrix_Int1_& value_) noexcept {
				value_ = static_cast<Matrix_Int1_>(this->max_way);
				return static_cast<Derived_&>(*this);
			}

			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getOutsideWall() const noexcept {
				return this->rogueLikeList.outside_wall_id;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getInsideWall() const noexcept {
				return this->rogueLikeList.inside_wall_id;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getRoom() const noexcept {
				return this->rogueLikeList.room_id;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getEntrance() const noexcept {
				return this->rogueLikeList.entrance_id;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getWay() const noexcept {
				return this->rogueLikeList.way_id;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getWall() const noexcept {
				return this->rogueLikeList.outside_wall_id;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Index_Size getMaxWay() const noexcept {
				return this->max_way;
			}

			DTL_VERSIONING_CPP17_NODISCARD
				constexpr ::dtl::base::RogueLikeList<Matrix_Var_> getValue() const noexcept {
				return this->rogueLikeList;
			}


			///// 消去 (Clear) /////


			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearOutsideWall() noexcept {
				const Matrix_Var_ chick_{};
				this->rogueLikeList.outside_wall_id = chick_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearInsideWall() noexcept {
				const Matrix_Var_ chick_{};
				this->rogueLikeList.inside_wall_id = chick_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearRoom() noexcept {
				const Matrix_Var_ elephant_{};
				this->rogueLikeList.room_id = elephant_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearEntrance() noexcept {
				const Matrix_Var_ elephant_{};
				this->rogueLikeList.entrance_id = elephant_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearWay() noexcept {
				const Matrix_Var_ giraffe_{};
				this->rogueLikeList.way_id = giraffe_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearWall() noexcept {
				this->clearOutsideWall();
				this->clearInsideWall();
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearMaxWay() noexcept {
				this->max_way = 0;
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
				const ::dtl::base::RogueLikeList<Matrix_Var_> new_draw_value{};
				this->rogueLikeList = new_draw_value;
				this->clearMaxWay();
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
				Derived_& setOutsideWall(const Matrix_Var_& chick_) noexcept {
				return this->rogueLikeList.outside_wall_id = chick_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setInsideWall(const Matrix_Var_& chick_) noexcept {
				return this->rogueLikeList.inside_wall_id = chick_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setRoom(const Matrix_Var_& elephant_) noexcept {
				return this->rogueLikeList.room_id = elephant_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setEntrance(const Matrix_Var_& elephant_) noexcept {
				return this->rogueLikeList.entrance_id = elephant_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setWay(const Matrix_Var_& giraffe_) noexcept {
				return this->rogueLikeList.way_id = giraffe_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setWall(const Matrix_Var_& giraffe_) noexcept {
				return this->rogueLikeList.outside_wall_id = this->rogueLikeList.inside_wall_id = giraffe_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setMaxWay(const Index_Size& giraffe_) noexcept {
				return this->max_way = giraffe_;
				return static_cast<Derived_&>(*this);
			}

			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setValue(const ::dtl::base::RogueLikeList<Matrix_Var_>& draw_value_) noexcept {
				this->rogueLikeList = draw_value_;
				return static_cast<Derived_&>(*this);
			}


			///// コンストラクタ (Constructor) /////

			RectBaseRogueLike() = default;
			constexpr explicit RectBaseRogueLike(const ::dtl::base::MatrixRange& matrix_range_) noexcept
				:RectBase_t(matrix_range_) {}
			constexpr RectBaseRogueLike(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_) noexcept
				:RectBase_t(start_x_, start_y_, width_, height_) {}

			constexpr explicit RectBaseRogueLike(const ::dtl::base::RogueLikeList<Matrix_Var_>& draw_value_) noexcept
				:rogueLikeList(draw_value_) {}

			constexpr explicit RectBaseRogueLike(const ::dtl::base::RogueLikeList<Matrix_Var_>& draw_value_, const Index_Size max_way_) noexcept
				:rogueLikeList(draw_value_), max_way(max_way_) {}

			constexpr explicit RectBaseRogueLike(const ::dtl::base::RogueLikeList<Matrix_Var_>& draw_value_, const Index_Size max_way_, const ::dtl::base::MatrixRange& roomRange_) noexcept
				:rogueLikeList(draw_value_), max_way(max_way_), roomRange(roomRange_) {}

			constexpr explicit RectBaseRogueLike(const ::dtl::base::RogueLikeList<Matrix_Var_>& draw_value_, const Index_Size max_way_, const ::dtl::base::MatrixRange& roomRange_, const ::dtl::base::MatrixRange& wayRange_) noexcept
				:rogueLikeList(draw_value_), max_way(max_way_), roomRange(roomRange_), wayRange(wayRange_) {}

			constexpr RectBaseRogueLike(
				const Matrix_Var_& outside_wall_id_,
				const Matrix_Var_& inside_wall_id_,
				const Matrix_Var_& room_id_,
				const Matrix_Var_& entrance_id_,
				const Matrix_Var_& way_id_) noexcept :
				rogueLikeList(outside_wall_id_, inside_wall_id_, room_id_, entrance_id_, way_id_) {}

			constexpr RectBaseRogueLike(const ::dtl::base::MatrixRange& matrix_range_, const ::dtl::base::RogueLikeList<Matrix_Var_>& draw_value_) noexcept
				:RectBase_t(matrix_range_),
				rogueLikeList(draw_value_) {}
			constexpr RectBaseRogueLike(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_, const ::dtl::base::RogueLikeList<Matrix_Var_>& draw_value_) noexcept
				:RectBase_t(start_x_, start_y_, width_, height_),
				rogueLikeList(draw_value_) {}

			constexpr RectBaseRogueLike(
				const Matrix_Var_& outside_wall_id_,
				const Matrix_Var_& inside_wall_id_,
				const Matrix_Var_& room_id_,
				const Matrix_Var_& entrance_id_,
				const Matrix_Var_& way_id_,
				const Index_Size max_way_) noexcept :
				rogueLikeList(outside_wall_id_, inside_wall_id_, room_id_, entrance_id_, way_id_), max_way(max_way_) {}

			constexpr RectBaseRogueLike(
				const Matrix_Var_& outside_wall_id_,
				const Matrix_Var_& inside_wall_id_,
				const Matrix_Var_& room_id_,
				const Matrix_Var_& entrance_id_,
				const Matrix_Var_& way_id_,
				const Index_Size max_way_, const ::dtl::base::MatrixRange& roomRange_) noexcept :
				rogueLikeList(outside_wall_id_, inside_wall_id_, room_id_, entrance_id_, way_id_), max_way(max_way_), roomRange(roomRange_) {}

			constexpr RectBaseRogueLike(
				const Matrix_Var_& outside_wall_id_,
				const Matrix_Var_& inside_wall_id_,
				const Matrix_Var_& room_id_,
				const Matrix_Var_& entrance_id_,
				const Matrix_Var_& way_id_,
				const Index_Size max_way_, const ::dtl::base::MatrixRange& roomRange_, const ::dtl::base::MatrixRange& wayRange_) noexcept :
				rogueLikeList(outside_wall_id_, inside_wall_id_, room_id_, entrance_id_, way_id_), max_way(max_way_), roomRange(roomRange_), wayRange(wayRange_) {}

			constexpr RectBaseRogueLike(const ::dtl::base::MatrixRange& matrix_range_, const ::dtl::base::RogueLikeList<Matrix_Var_>& draw_value_, const Index_Size max_way_) noexcept
				:RectBase_t(matrix_range_),
				rogueLikeList(draw_value_), max_way(max_way_) {}

			constexpr explicit RectBaseRogueLike(const ::dtl::base::MatrixRange& matrix_range_, const ::dtl::base::RogueLikeList<Matrix_Var_>& draw_value_, const Index_Size max_way_, const ::dtl::base::MatrixRange& roomRange_) noexcept
				:RectBase_t(matrix_range_),
				rogueLikeList(draw_value_), max_way(max_way_), roomRange(roomRange_) {}

			constexpr explicit RectBaseRogueLike(const ::dtl::base::MatrixRange& matrix_range_, const ::dtl::base::RogueLikeList<Matrix_Var_>& draw_value_, const Index_Size max_way_, const ::dtl::base::MatrixRange& roomRange_, const ::dtl::base::MatrixRange& wayRange_) noexcept
				:RectBase_t(matrix_range_),
				rogueLikeList(draw_value_), max_way(max_way_), roomRange(roomRange_), wayRange(wayRange_) {}

			constexpr RectBaseRogueLike(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_, const ::dtl::base::RogueLikeList<Matrix_Var_>& draw_value_, const Index_Size max_way_) noexcept
				:RectBase_t(start_x_, start_y_, width_, height_),
				rogueLikeList(draw_value_), max_way(max_way_) {}

			constexpr explicit RectBaseRogueLike(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_, const ::dtl::base::RogueLikeList<Matrix_Var_>& draw_value_, const Index_Size max_way_, const ::dtl::base::MatrixRange& roomRange_) noexcept
				:RectBase_t(start_x_, start_y_, width_, height_),
				rogueLikeList(draw_value_), max_way(max_way_), roomRange(roomRange_) {}

			constexpr explicit RectBaseRogueLike(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_, const ::dtl::base::RogueLikeList<Matrix_Var_>& draw_value_, const Index_Size max_way_, const ::dtl::base::MatrixRange& roomRange_, const ::dtl::base::MatrixRange& wayRange_) noexcept
				:RectBase_t(start_x_, start_y_, width_, height_),
				rogueLikeList(draw_value_), max_way(max_way_), roomRange(roomRange_), wayRange(wayRange_) {}

			//::dtl::base::MatrixRange roomRange
		};
	}
}

#endif //Included Dungeon Template Library
