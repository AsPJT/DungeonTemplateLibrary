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
		shogi_next_place,
		//王玉
		shogi_osho,
		shogi_gyokusho,
		//金将
		shogi_kinsho,

		//ここより先は成る。----------------------------------------

		//飛車
		shogi_hisha,
		shogi_ryuo,
		//角行
		shogi_kakugyo,
		shogi_ryuma,

		//ここより先は成ると金と同じ動きになる。--------------------

		//銀将
		shogi_ginsho,
		shogi_narigin,
		//桂馬
		shogi_keima,
		shogi_narikei,
		//香車
		shogi_kyosha,
		shogi_narikyo,
		//歩兵
		shogi_fuhyo,
		shogi_tokin
	};

}

#endif //Included Dungeon Template Library