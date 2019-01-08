//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://
#include "DTL.hpp"

#include <cstdint>
#include <iostream>
#include <array>

int main() {

	//盤の整数型
	using reversi_t = std::uint_fast8_t;

	//8*8の盤を生成
	std::array<std::array<reversi_t, 8>, 8> stl_{ {} };

	//どちらの駒の番か記録する変数
	reversi_t turn{ dtl::reversi_black };
	std::int_fast32_t counter{};

	std::int_fast32_t black_num{};
	std::int_fast32_t white_num{};
	std::int_fast32_t empty_num{};

	double counter_total{};
	double black_total_num{};
	double white_total_num{};
	double empty_total_num{};
	double winner_total{};

	std::cout << "|Winner|Black|White|Empty|Count|" << std::endl;
	std::cout << "|:---|:---|:---|:---|:---|" << std::endl;

	//試合数
	constexpr std::size_t loop_max{ 10000 };
	for (std::size_t ii{}; ii < loop_max; ++ii) {

		dtl::dungeonInit(stl_);
		dtl::createReversi<reversi_t>(stl_);

		//メインループ
		while (true) {
			//出力(出力が見たい場合はコメントを外す)
			//dtl::dungeonStringOutput(stl_, "・", "○", "●");
			//std::cout << std::endl;

			++counter;
			if (!dtl::isPassReversi<reversi_t>(stl_, turn)) {
				//戦わせたいAIを記入する。
				dtl::reversiAI<reversi_t>(stl_, turn, dtl::reversiAI_Priority, dtl::reversiAI_Priority, turn == dtl::reversi_black);
			}
			turn = 3 - turn;

			if (dtl::checkResultReversi<reversi_t>(stl_)) break;
		}
		for (const auto& i : stl_)
			for (const auto& j : i) {
				if (j == dtl::reversi_black) ++black_num;
				else if (j == dtl::reversi_white) ++white_num;
				else if (j == dtl::reversi_empty) ++empty_num;
			}

		if (black_num > white_num) winner_total += 1.0;
		else if (black_num < white_num) winner_total += -1.0;

		counter_total += static_cast<double>(counter);
		black_total_num += static_cast<double>(black_num);
		white_total_num += static_cast<double>(white_num);
		empty_total_num += static_cast<double>(empty_num);

		counter = 0;
		black_num = 0;
		white_num = 0;
		empty_num = 0;
	}
	//勝率表を出力
	std::cout << "|" << winner_total / loop_max; 
	std::cout << "|" << black_total_num / loop_max; 
	std::cout << "|" << white_total_num / loop_max; 
	std::cout << "|" << empty_total_num / loop_max; 
	std::cout << "|" << counter_total / loop_max; 
	std::cout << "|" << std::endl;
}