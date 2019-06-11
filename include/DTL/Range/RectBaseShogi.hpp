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

		template<typename Matrix_Int_>
		struct ShogiList {
			Matrix_Int_ fuhyo_1{};
			Matrix_Int_ fuhyo_2{};
			Matrix_Int_ tokin_1{};
			Matrix_Int_ tokin_2{};
			Matrix_Int_ kyosha_1{};
			Matrix_Int_ kyosha_2{};
			Matrix_Int_ narikyo_1{};
			Matrix_Int_ narikyo_2{};
			Matrix_Int_ keima_1{};
			Matrix_Int_ keima_2{};
			Matrix_Int_ narikei_1{};
			Matrix_Int_ narikei_2{};
			Matrix_Int_ ginsho_1{};
			Matrix_Int_ ginsho_2{};
			Matrix_Int_ narigin_1{};
			Matrix_Int_ narigin_2{};
			Matrix_Int_ hisha_1{};
			Matrix_Int_ hisha_2{};
			Matrix_Int_ ryuo_1{};
			Matrix_Int_ ryuo_2{};
			Matrix_Int_ kakugyo_1{};
			Matrix_Int_ kakugyo_2{};
			Matrix_Int_ ryuma_1{};
			Matrix_Int_ ryuma_2{};
			Matrix_Int_ kinsho_1{};
			Matrix_Int_ kinsho_2{};
			Matrix_Int_ osho{};
			Matrix_Int_ gyokusho{};

			constexpr ShogiList() = default;

			constexpr explicit ShogiList(
			const Matrix_Int_& fuhyo_1_, 
			const Matrix_Int_& fuhyo_2_,
			const Matrix_Int_& tokin_1_,
			const Matrix_Int_& tokin_2_,
			const Matrix_Int_& kyosha_1_,
			const Matrix_Int_& kyosha_2_,
			const Matrix_Int_& narikyo_1_,
			const Matrix_Int_& narikyo_2_,
			const Matrix_Int_& keima_1_,
			const Matrix_Int_& keima_2_,
			const Matrix_Int_& narikei_1_,
			const Matrix_Int_& narikei_2_,
			const Matrix_Int_& ginsho_1_,
			const Matrix_Int_& ginsho_2_,
			const Matrix_Int_& narigin_1_,
			const Matrix_Int_& narigin_2_,
			const Matrix_Int_& hisha_1_,
			const Matrix_Int_& hisha_2_,
			const Matrix_Int_& ryuo_1_,
			const Matrix_Int_& ryuo_2_,
			const Matrix_Int_& kakugyo_1_,
			const Matrix_Int_& kakugyo_2_,
			const Matrix_Int_& ryuma_1_,
			const Matrix_Int_& ryuma_2_,
			const Matrix_Int_& kinsho_1_,
			const Matrix_Int_& kinsho_2_,
			const Matrix_Int_& osho_,
			const Matrix_Int_& gyokusho_) noexcept :
			fuhyo_1(fuhyo_1_),
			fuhyo_2(fuhyo_2_),
			tokin_1(tokin_1_),
			tokin_2(tokin_2_),
			kyosha_1(kyosha_1_),
			kyosha_2(kyosha_2_),
			narikyo_1(narikyo_1_),
			narikyo_2(narikyo_2_),
			keima_1(keima_1_),
			keima_2(keima_2_),
			narikei_1(narikei_1_),
			narikei_2(narikei_2_),
			ginsho_1(ginsho_1_),
			ginsho_2(ginsho_2_),
			narigin_1(narigin_1_),
			narigin_2(narigin_2_),
			hisha_1(hisha_1_),
			hisha_2(hisha_2_),
			ryuo_1(ryuo_1_),
			ryuo_2(ryuo_2_),
			kakugyo_1(kakugyo_1_),
			kakugyo_2(kakugyo_2_),
			ryuma_1(ryuma_1_),
			ryuma_2(ryuma_2_),
			kinsho_1(kinsho_1_),
			kinsho_2(kinsho_2_),
			osho(osho_),
			gyokusho(gyokusho_) {}

			constexpr explicit ShogiList(
				const Matrix_Int_& fuhyo_,
				const Matrix_Int_& tokin_,
				const Matrix_Int_& kyosha_,
				const Matrix_Int_& narikyo_,
				const Matrix_Int_& keima_,
				const Matrix_Int_& narikei_,
				const Matrix_Int_& ginsho_,
				const Matrix_Int_& narigin_,
				const Matrix_Int_& hisha_,
				const Matrix_Int_& ryuo_,
				const Matrix_Int_& kakugyo_,
				const Matrix_Int_& ryuma_,
				const Matrix_Int_& kinsho_,
				const Matrix_Int_& osho_) noexcept :
				fuhyo_1(fuhyo_),
				fuhyo_2(fuhyo_),
				tokin_1(tokin_),
				tokin_2(tokin_),
				kyosha_1(kyosha_),
				kyosha_2(kyosha_),
				narikyo_1(narikyo_),
				narikyo_2(narikyo_),
				keima_1(keima_),
				keima_2(keima_),
				narikei_1(narikei_),
				narikei_2(narikei_),
				ginsho_1(ginsho_),
				ginsho_2(ginsho_),
				narigin_1(narigin_),
				narigin_2(narigin_),
				hisha_1(hisha_),
				hisha_2(hisha_),
				ryuo_1(ryuo_),
				ryuo_2(ryuo_),
				kakugyo_1(kakugyo_),
				kakugyo_2(kakugyo_),
				ryuma_1(ryuma_),
				ryuma_2(ryuma_),
				kinsho_1(kinsho_),
				kinsho_2(kinsho_),
				osho(osho_),
				gyokusho(osho_) {}
		};

		
		template<typename Derived_, typename Matrix_Int_>
		class RectBaseShogi : public ::dtl::range::BasicRect<Derived_> {
		private:

			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using RectBase_t = ::dtl::range::BasicRect<Derived_>;


		protected:


			///// メンバ変数 (Member Variable) /////

			::dtl::range::ShogiList<Matrix_Int_> shogiList{};

		public:


			///// メンバ変数の値を取得 (Get Value) /////

			DTL_VERSIONING_CPP17_NODISCARD
			constexpr ::dtl::range::ShogiList<Matrix_Int_> getValue() const noexcept {
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
				const ::dtl::range::ShogiList<Matrix_Int_> new_draw_value{};
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
				Derived_& setValue(const ::dtl::range::ShogiList<Matrix_Int_>& draw_value_) noexcept {
				this->shogiList = draw_value_;
				return static_cast<Derived_&>(*this);
			}


			///// コンストラクタ (Constructor) /////

			using RectBase_t::RectBase_t;

			constexpr explicit RectBaseShogi(const ::dtl::range::ShogiList<Matrix_Int_>& draw_value_) noexcept
				:shogiList(draw_value_) {}

			constexpr explicit RectBaseShogi(
				const Matrix_Int_& fuhyo_1_, const Matrix_Int_& fuhyo_2_,
				const Matrix_Int_& tokin_1_, const Matrix_Int_& tokin_2_,
				const Matrix_Int_& kyosha_1_, const Matrix_Int_& kyosha_2_,
				const Matrix_Int_& narikyo_1_, const Matrix_Int_& narikyo_2_,
				const Matrix_Int_& keima_1_, const Matrix_Int_& keima_2_,
				const Matrix_Int_& narikei_1_, const Matrix_Int_& narikei_2_,
				const Matrix_Int_& ginsho_1_, const Matrix_Int_& ginsho_2_,
				const Matrix_Int_& narigin_1_, const Matrix_Int_& narigin_2_,
				const Matrix_Int_& hisha_1_, const Matrix_Int_& hisha_2_,
				const Matrix_Int_& ryuo_1_, const Matrix_Int_& ryuo_2_,
				const Matrix_Int_& kakugyo_1_, const Matrix_Int_& kakugyo_2_,
				const Matrix_Int_& ryuma_1_, const Matrix_Int_& ryuma_2_,
				const Matrix_Int_& kinsho_1_, const Matrix_Int_& kinsho_2_,
				const Matrix_Int_& osho_, const Matrix_Int_& gyokusho_) noexcept :
				shogiList(fuhyo_1_, fuhyo_2_, tokin_1_, tokin_2_, kyosha_1_, kyosha_2_, narikyo_1_, narikyo_2_, keima_1_, keima_2_, narikei_1_, narikei_2_, ginsho_1_, ginsho_2_,
					narigin_1_, narigin_2_, hisha_1_, hisha_2_, ryuo_1_, ryuo_2_, kakugyo_1_, kakugyo_2_, ryuma_1_, ryuma_2_, kinsho_1_, kinsho_2_, osho_, gyokusho_) {}

			constexpr explicit RectBaseShogi(
				const Matrix_Int_& fuhyo_, const Matrix_Int_& tokin_,
				const Matrix_Int_& kyosha_, const Matrix_Int_& narikyo_,
				const Matrix_Int_& keima_, const Matrix_Int_& narikei_,
				const Matrix_Int_& ginsho_, const Matrix_Int_& narigin_,
				const Matrix_Int_& hisha_, const Matrix_Int_& ryuo_,
				const Matrix_Int_& kakugyo_, const Matrix_Int_& ryuma_,
				const Matrix_Int_& kinsho_, const Matrix_Int_& osho_) noexcept :
				shogiList(fuhyo_, fuhyo_, tokin_, tokin_, kyosha_, kyosha_, narikyo_, narikyo_, keima_, keima_, narikei_, narikei_, ginsho_, ginsho_,
					narigin_, narigin_, hisha_, hisha_, ryuo_, ryuo_, kakugyo_, kakugyo_, ryuma_, ryuma_, kinsho_, kinsho_, osho_, osho_) {}

			constexpr explicit RectBaseShogi(const ::dtl::base::MatrixRange& matrix_range_, const ::dtl::range::ShogiList<Matrix_Int_>& draw_value_) noexcept
				:RectBase_t(matrix_range_),
				shogiList(draw_value_) {}
			constexpr explicit RectBaseShogi(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_, const ::dtl::range::ShogiList<Matrix_Int_>& draw_value_) noexcept
				:RectBase_t(start_x_, start_y_, width_, height_),
				shogiList(draw_value_) {}
		};
	}
}

#endif //Included Dungeon Template Library
