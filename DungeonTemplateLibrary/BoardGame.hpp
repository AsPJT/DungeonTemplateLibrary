#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BOARD_GAME
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BOARD_GAME
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>

//Dungeon Template Library Namespace
namespace dtl {

	enum :std::size_t {
		reversi_empty,
		reversi_white,
		reversi_black
	};

	template<typename Int_, typename STL_>
	constexpr void createReversi(STL_& stl_, const Int_ black_ = 2, const Int_ white_ = 1) noexcept {
		if (stl_.size() < 2 || stl_[0].size() < 2) return;
		const std::size_t& set_y{ stl_.size() / 2 };
		const std::size_t& set_x{ stl_[0].size() / 2 };
		stl_[set_y - 1][set_x - 1] = white_;
		stl_[set_y - 1][set_x] = black_;
		stl_[set_y][set_x - 1] = black_;
		stl_[set_y][set_x] = white_;
	}
	template<typename Int_>
	class Reversi {
	public:
		//コンストラクタ
		constexpr Reversi() noexcept = default;
		template<typename STL_>
		constexpr explicit Reversi(STL_& stl_, const Int_ black_ = 2, const Int_ white_ = 1) noexcept {
			create(stl_, black_, white_);
		}
		template<typename STL_>
		constexpr void create(STL_& stl_, const Int_ black_ = 2, const Int_ white_ = 1) noexcept {
			createReversi(stl_, black_, white_);
		}
	};

	enum :std::size_t {
		shogi_empty,
		shogi_next_place1,
		shogi_next_place2,
		//王将&玉将
		shogi_osho,
		shogi_gyokusho,
		//金将
		shogi_kinsho1,
		shogi_kinsho2,

		//ここより先は成る。----------------------------------------

		//飛車
		shogi_hisha1,
		shogi_ryuo1,
		shogi_hisha2,
		shogi_ryuo2,
		//角行
		shogi_kakugyo1,
		shogi_ryuma1,
		shogi_kakugyo2,
		shogi_ryuma2,

		//ここより先は成ると金と同じ動きになる。--------------------

		//銀将
		shogi_ginsho1,
		shogi_narigin1,
		shogi_ginsho2,
		shogi_narigin2,
		//桂馬
		shogi_keima1,
		shogi_narikei1,
		shogi_keima2,
		shogi_narikei2,
		//香車
		shogi_kyosha1,
		shogi_narikyo1,
		shogi_kyosha2,
		shogi_narikyo2,
		//歩兵
		shogi_fuhyo1,
		shogi_tokin1,
		shogi_fuhyo2,
		shogi_tokin2
	};

	template<typename Int_>
	constexpr bool isShogiNarikin(const Int_ koma_) noexcept {
		if (koma_ >= shogi_ginsho1 && shogi_narigin1 % 2 == koma_ % 2) return true;
		return false;
	}

}

#endif //Included Dungeon Template Library