/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANGE_RECT_BASE_SHOGI_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANGE_RECT_BASE_SHOGI_HPP

#include <DTL/Base/Shogi.hpp>
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
		class RectBaseShogi : public ::dtl::range::BasicRect<Derived_> {
		private:

			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using RectBase_t = ::dtl::range::BasicRect<Derived_>;


		protected:


			///// メンバ変数 (Member Variable) /////

			::dtl::base::ShogiList<Matrix_Var_> shogiList{};

		public:


			///// メンバ変数の値を取得 (Get Value) /////

			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getFuhyo1() const noexcept {
				return this->shogiList.fuhyo_1;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getFuhyo2() const noexcept {
				return this->shogiList.fuhyo_2;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getTokin1() const noexcept {
				return this->shogiList.tokin_1;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getTokin2() const noexcept {
				return this->shogiList.tokin_2;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getKyosha1() const noexcept {
				return this->shogiList.kyosha_1;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getKyosha2() const noexcept {
				return this->shogiList.kyosha_2;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getNarikyo1() const noexcept {
				return this->shogiList.narikyo_1;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getNarikyo2() const noexcept {
				return this->shogiList.narikyo_2;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getKeima1() const noexcept {
				return this->shogiList.keima_1;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getKeima2() const noexcept {
				return this->shogiList.keima_2;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getNarikei1() const noexcept {
				return this->shogiList.narikei_1;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getNarikei2() const noexcept {
				return this->shogiList.narikei_2;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getGinsho1() const noexcept {
				return this->shogiList.ginsho_1;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getGinsho2() const noexcept {
				return this->shogiList.ginsho_2;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getNarigin1() const noexcept {
				return this->shogiList.narigin_1;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getNarigin2() const noexcept {
				return this->shogiList.narigin_2;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getHisha1() const noexcept {
				return this->shogiList.hisha_1;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getHisha2() const noexcept {
				return this->shogiList.hisha_2;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getRyuo1() const noexcept {
				return this->shogiList.ryuo_1;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getRyuo2() const noexcept {
				return this->shogiList.ryuo_2;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getKakugyo1() const noexcept {
				return this->shogiList.kakugyo_1;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getKakugyo2() const noexcept {
				return this->shogiList.kakugyo_2;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getRyuma1() const noexcept {
				return this->shogiList.ryuma_1;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getRyuma2() const noexcept {
				return this->shogiList.ryuma_2;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getKinsho1() const noexcept {
				return this->shogiList.kinsho_1;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getKinsho2() const noexcept {
				return this->shogiList.kinsho_2;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getOsho() const noexcept {
				return this->shogiList.osho_1;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getGyokusho() const noexcept {
				return this->shogiList.gyokusho_2;
			}

			DTL_VERSIONING_CPP17_NODISCARD
			constexpr ::dtl::base::ShogiList<Matrix_Var_> getValue() const noexcept {
				return this->shogiList;
			}


			///// 消去 (Clear) /////


/*#######################################################################################
	[概要] 塗り値を初期値に戻す(描画値を消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing value to the initial value (deletes the drawing value).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearValue() noexcept {
				const ::dtl::base::ShogiList<Matrix_Var_> new_draw_value{};
				this->shogiList = new_draw_value;
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
				Derived_& setValue(const ::dtl::base::ShogiList<Matrix_Var_>& draw_value_) noexcept {
				this->shogiList = draw_value_;
				return static_cast<Derived_&>(*this);
			}


			///// コンストラクタ (Constructor) /////

			RectBaseShogi() = default;
			constexpr explicit RectBaseShogi(const ::dtl::base::MatrixRange& matrix_range_) noexcept
				:RectBase_t(matrix_range_) {}
			constexpr RectBaseShogi(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_) noexcept
				:RectBase_t(start_x_, start_y_, width_, height_) {}

			constexpr explicit RectBaseShogi(const ::dtl::base::ShogiList<Matrix_Var_>& draw_value_) noexcept
				:shogiList(draw_value_) {}

			//28
			constexpr RectBaseShogi(
				const Matrix_Var_& fuhyo_1_, const Matrix_Var_& fuhyo_2_,
				const Matrix_Var_& tokin_1_, const Matrix_Var_& tokin_2_,
				const Matrix_Var_& kyosha_1_, const Matrix_Var_& kyosha_2_,
				const Matrix_Var_& narikyo_1_, const Matrix_Var_& narikyo_2_,
				const Matrix_Var_& keima_1_, const Matrix_Var_& keima_2_,
				const Matrix_Var_& narikei_1_, const Matrix_Var_& narikei_2_,
				const Matrix_Var_& ginsho_1_, const Matrix_Var_& ginsho_2_,
				const Matrix_Var_& narigin_1_, const Matrix_Var_& narigin_2_,
				const Matrix_Var_& hisha_1_, const Matrix_Var_& hisha_2_,
				const Matrix_Var_& ryuo_1_, const Matrix_Var_& ryuo_2_,
				const Matrix_Var_& kakugyo_1_, const Matrix_Var_& kakugyo_2_,
				const Matrix_Var_& ryuma_1_, const Matrix_Var_& ryuma_2_,
				const Matrix_Var_& kinsho_1_, const Matrix_Var_& kinsho_2_,
				const Matrix_Var_& osho_, const Matrix_Var_& gyokusho_) noexcept :
				shogiList(fuhyo_1_, fuhyo_2_, tokin_1_, tokin_2_, kyosha_1_, kyosha_2_, narikyo_1_, narikyo_2_, keima_1_, keima_2_, narikei_1_, narikei_2_, ginsho_1_, ginsho_2_,
					narigin_1_, narigin_2_, hisha_1_, hisha_2_, ryuo_1_, ryuo_2_, kakugyo_1_, kakugyo_2_, ryuma_1_, ryuma_2_, kinsho_1_, kinsho_2_, osho_, gyokusho_) {}

			//14
			constexpr RectBaseShogi(
				const Matrix_Var_& fuhyo_, const Matrix_Var_& tokin_,
				const Matrix_Var_& kyosha_, const Matrix_Var_& narikyo_,
				const Matrix_Var_& keima_, const Matrix_Var_& narikei_,
				const Matrix_Var_& ginsho_, const Matrix_Var_& narigin_,
				const Matrix_Var_& hisha_, const Matrix_Var_& ryuo_,
				const Matrix_Var_& kakugyo_, const Matrix_Var_& ryuma_,
				const Matrix_Var_& kinsho_, const Matrix_Var_& osho_) noexcept :
				shogiList(fuhyo_, fuhyo_, tokin_, tokin_, kyosha_, kyosha_, narikyo_, narikyo_, keima_, keima_, narikei_, narikei_, ginsho_, ginsho_,
					narigin_, narigin_, hisha_, hisha_, ryuo_, ryuo_, kakugyo_, kakugyo_, ryuma_, ryuma_, kinsho_, kinsho_, osho_, osho_) {}

			constexpr RectBaseShogi(const ::dtl::base::MatrixRange& matrix_range_, const ::dtl::base::ShogiList<Matrix_Var_>& draw_value_) noexcept
				:RectBase_t(matrix_range_),
				shogiList(draw_value_) {}
			constexpr RectBaseShogi(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_, const ::dtl::base::ShogiList<Matrix_Var_>& draw_value_) noexcept
				:RectBase_t(start_x_, start_y_, width_, height_),
				shogiList(draw_value_) {}
		};
	}
}

#endif //Included Dungeon Template Library
