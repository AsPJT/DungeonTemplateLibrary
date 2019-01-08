#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BOARD_GAME
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BOARD_GAME
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>
#include <cstdint>
#include <array>
#include <limits>

//Dungeon Template Library Namespace
namespace dtl {

	//指定した場所に駒を置く
	template<typename Int_, typename STL_>
	std::size_t putPieceReversi(STL_& stl_, const std::size_t  x_, const std::size_t y_, const Int_ turn_, const bool is_put_) noexcept {
		if (stl_.size() == 0) return 0;
		std::size_t piece_turn_num{};
		if (stl_[y_][x_] > 0) return 0;

		std::unique_ptr<std::int_fast32_t[]> stl_tmp_x(new std::int_fast32_t[stl_[0].size()]);
		std::unique_ptr<std::int_fast32_t[]> stl_tmp_y(new std::int_fast32_t[stl_.size()]);

		for (std::int_fast32_t y{ -1 }; y <= 1; ++y)
			for (std::int_fast32_t x{ -1 }; x <= 1; ++x) {
				for (std::size_t i{}; i < stl_[0].size(); ++i) stl_tmp_x[i] = 0;
				for (std::size_t i{}; i < stl_.size(); ++i) stl_tmp_y[i] = 0;
				for (std::size_t turn_tmp_id{};; ++turn_tmp_id) {
					std::int_fast32_t turn_x{ static_cast<std::int_fast32_t>(x_) + x * (static_cast<std::int_fast32_t>(turn_tmp_id) + 1) };
					std::int_fast32_t turn_y{ static_cast<std::int_fast32_t>(y_) + y * (static_cast<std::int_fast32_t>(turn_tmp_id) + 1) };
					if (turn_x < 0 || turn_x >= stl_[0].size() || turn_y < 0 || turn_y >= stl_.size() || stl_[turn_y][turn_x] == 0) break;
					if (stl_[turn_y][turn_x] == turn_) {
						if (is_put_)
							for (std::size_t i{}; i < turn_tmp_id; ++i)
								stl_[static_cast<std::size_t>(stl_tmp_y[i])][static_cast<std::size_t>(stl_tmp_x[i])] = turn_;
						piece_turn_num += turn_tmp_id;
						break;
					}
					stl_tmp_x[turn_tmp_id] = turn_x; stl_tmp_y[turn_tmp_id] = turn_y;
				}
			}
		if (piece_turn_num > 0 && is_put_) stl_[y_][x_] = turn_;
		return piece_turn_num;
	}
	//パスの有無
	template<typename Int_, typename STL_>
	constexpr bool isPassReversi(STL_& stl_, const Int_ turn_) noexcept {
		for (std::size_t i{}; i < stl_.size(); ++i)
			for (std::size_t j{}; j < stl_[i].size(); ++j)
				if (putPieceReversi(stl_, j, i, turn_, false)) return false;
		return true;
	}
	//最初に見つけた置ける場所を選ぶ
	template<typename Int_, typename STL_>
	constexpr bool reversiAI_Simple(STL_& stl_, const Int_ turn_) noexcept {
		for (std::size_t i{}; i < stl_.size(); ++i)
			for (std::size_t j{}; j < stl_[i].size(); ++j)
				if (putPieceReversi(stl_, j, i, turn_, true)) return true;
		return true;
	}
	//最も多くの駒が取れる場所を選ぶ
	template<typename Int_, typename STL_>
	constexpr bool reversiAI_Greed(STL_& stl_, const Int_ turn_) noexcept {
		std::size_t piece_turn_max{};
		std::size_t put_piece_x{}, put_piece_y{};
		for (std::size_t i{}; i < stl_.size(); ++i)
			for (std::size_t j{}; j < stl_[i].size(); ++j) {
				const auto& num{ putPieceReversi(stl_, j,i, turn_, false) };
				if (piece_turn_max < num || (piece_turn_max == num && dtl::rnd.randBool())) {
					piece_turn_max = num;
					put_piece_x = j;
					put_piece_y = i;
				}
			}
		putPieceReversi(stl_, put_piece_x, put_piece_y, turn_, true);
		return true;
	}
	//最も少なく駒が取れる場所を選ぶ
	template<typename Int_, typename STL_>
	constexpr bool reversiAI_Unselfishness(STL_& stl_, const Int_ turn_) noexcept {
		std::size_t piece_turn_min{ std::numeric_limits<std::size_t>::max() };
		std::size_t put_piece_x{}, put_piece_y{};
		for (std::size_t i{}; i < stl_.size(); ++i)
			for (std::size_t j{}; j < stl_[i].size(); ++j) {
				const auto& num{ putPieceReversi(stl_, j,i, turn_, false) };
				if (num > 0 && (piece_turn_min > num || (piece_turn_min == num && dtl::rnd.randBool()))) {
					piece_turn_min = num;
					put_piece_x = j;
					put_piece_y = i;
				}
			}
		putPieceReversi(stl_, put_piece_x, put_piece_y, turn_, true);
		return true;
	}
	//優先順位
	constexpr std::int_fast32_t checkPriorityReversi(std::int_fast32_t x_, std::int_fast32_t y_, const std::int_fast32_t x_max_, const std::int_fast32_t y_max_) noexcept {
		if (x_ == x_max_) x_ = 0;
		else if (x_ == x_max_ - 1) x_ = 1;
		else if (x_ == x_max_ - 2) x_ = 2;
		if (y_ == y_max_) y_ = 0;
		else if (y_ == y_max_ - 1) y_ = 1;
		else if (y_ == y_max_ - 2) y_ = 2;
		switch (x_)
		{
		case 0:
			switch (y_)
			{
			case 0:return 0;
			case 1:return 6;
			case 2:return 2;
			default:return 1;
			}
		case 1:
			switch (y_)
			{
			case 0:return 6;
			case 1:return 6;
			case 2:return 6;
			default:return 4;
			}
		case 2:
			switch (y_)
			{
			case 0:return 2;
			case 1:return 5;
			case 2:return 2;
			default:return 3;
			}
		}
		switch (y_)
		{
		case 0:return 1;
		case 1:return 4;
		case 2:return 3;
		default:return 3;
		}
		return 0;
	}
	//優先順位の高い場所を選ぶ
	template<typename Int_, typename STL_>
	constexpr bool reversiAI_Priority(STL_& stl_, const Int_ turn_) noexcept {
		std::size_t piece_turn_max{};
		std::size_t put_piece_x{}, put_piece_y{};
		for (std::uint_fast8_t piece_priority{}; piece_priority < 7 && piece_turn_max == 0; ++piece_priority)
			for (std::size_t i{}; i < stl_.size(); ++i)
				for (std::size_t j{}; j < stl_[i].size(); ++j) {
					if (checkPriorityReversi(static_cast<std::int_fast32_t>(j), static_cast<std::int_fast32_t>(i), static_cast<std::int_fast32_t>(stl_[i].size()) - 1, static_cast<std::int_fast32_t>(stl_.size()) - 1) != piece_priority) continue;
					const auto& num{ putPieceReversi(stl_, j, i, turn_, false) };
					if (piece_turn_max < num || (piece_turn_max == num && dtl::rnd.randBool())) {
						piece_turn_max = num;
						put_piece_x = j;
						put_piece_y = i;
					}
				}
		putPieceReversi(stl_, put_piece_x, put_piece_y, turn_, true);
		return true;
	}
	//AI同士をまとめる関数
	template<typename Int_, typename STL_>
	constexpr bool reversiAI(STL_& stl_, const Int_ turn_, bool(*black_ai_)(STL_&, const Int_), bool(*white_ai_)(STL_&, const Int_), const bool is_black_ai_) noexcept {
		return (is_black_ai_) ? black_ai_(stl_, turn_) : white_ai_(stl_, turn_);
	}

	template<typename Int_, typename STL_>
	constexpr std::int_fast32_t checkResultReversi(STL_& stl_) noexcept {
		std::array<std::int_fast32_t, 2> piece_num{ {} };
		std::int_fast32_t result{};
		for (std::size_t i{}; i < stl_.size(); ++i)
			for (std::size_t j{}; j < stl_[i].size(); ++j)
				if (stl_[i][j] > 0) ++piece_num[stl_[i][j] - 1];
		if (isPassReversi(stl_, (Int_)1) && isPassReversi(stl_, (Int_)2)) {
			if (piece_num[0] > piece_num[1]) result = 1;
			else if (piece_num[0] < piece_num[1]) result = 2;
			else result = 3;
		}
		return result;
	}

	enum :std::size_t {
		reversi_empty,
		reversi_white,
		reversi_black
	};
	//リバーシを初期化する
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