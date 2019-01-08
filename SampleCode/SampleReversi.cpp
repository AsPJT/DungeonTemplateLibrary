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
	//リバーシの駒を初期配置
	dtl::Reversi<reversi_t> reversi(stl_);

	//どちらの駒の番か記録する変数
	reversi_t turn{ dtl::reversi_black };

	//メインループ
	while (true) {
		//出力
		dtl::dungeonStringOutput(stl_, "・", "○", "●");
		std::cout << std::endl;

		if (!dtl::isPassReversi<reversi_t>(stl_, turn)) {
			//戦わせたいAIを記入する。
			dtl::reversiAI<reversi_t>(stl_, turn, dtl::reversiAI_Simple, dtl::reversiAI_Simple, turn == dtl::reversi_black);
		}
		turn = 3 - turn;

		if (dtl::checkResultReversi<reversi_t>(stl_)) break;
	}

}