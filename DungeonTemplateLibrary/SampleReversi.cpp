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
	//dtl::Reversi<reversi_t> reversi(stl_);

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

	std::cout << "|Winner|Simple|Simple|Empty|Count|\n";
	std::cout << "|:---|:---|:---|:---|:---|\n";

	constexpr std::size_t loop_max{ 10000 };
	for (std::size_t ii{}; ii < loop_max; ++ii) {

		dtl::dungeonInit(stl_);
		dtl::createReversi<reversi_t>(stl_);

		//メインループ
		while (true) {
			//出力
			//dtl::dungeonStringOutput(stl_, "・", "○", "●");
			//std::cout << std::endl;
			++counter;

			if (!dtl::isPassReversi<reversi_t>(stl_, turn)) dtl::reversiAI<reversi_t>(stl_, turn, dtl::reversiAI_Simple, dtl::reversiAI_Simple, turn == dtl::reversi_black);
			turn = 3 - turn;

			if (dtl::checkResultReversi<reversi_t>(stl_)) break;
		}
		for (const auto& i : stl_)
			for (const auto& j : i) {
				if (j == dtl::reversi_black) ++black_num;
				else if (j == dtl::reversi_white) ++white_num;
				else if (j == dtl::reversi_empty) ++empty_num;
			}

		//std::cout << "|";
		if (black_num == white_num) {
			//std::cout << 0;
			winner_total += 0.0;
		}
		else if (black_num > white_num) {
			//std::cout << 1;
			winner_total += 1.0;
		}
		else {
			//std::cout << -1;
			winner_total += -1.0;
		}
		//std::cout << "|" << black_num << "|" << white_num << "|" << empty_num << "|" << counter << "|\n";

		counter_total += (double)counter;
		black_total_num += (double)black_num;
		white_total_num += (double)white_num;
		empty_total_num += (double)empty_num;

		counter = 0;
		black_num = 0;
		white_num = 0;
		empty_num = 0;
	}
	std::cout << "|" << winner_total / loop_max << "|" << black_total_num / loop_max << "|" << white_total_num / loop_max << "|" << empty_total_num / loop_max << "|" << counter_total / loop_max << "|\n";

}