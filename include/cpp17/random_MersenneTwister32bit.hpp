#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM_MERSENNE_TWISTER_32_BIT
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM_MERSENNE_TWISTER_32_BIT
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

/* Bug Check : not checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstdint>
#include <random>

namespace dtl::random {

	//乱数(32ビット版メルセンヌ・ツイスタ)
	class MersenneTwister32bit {
	private:
		//32ビット版メルセンヌ・ツイスタ
		std::mt19937 mt;
		//非決定論的な乱数
		std::random_device rd;

	public:
		//コンストラクタ(初期化)
		explicit MersenneTwister32bit() noexcept { mt.seed(rd()); }

		//初期値
		void seed() noexcept {
			mt.seed(rd());
		}
		void seed(const std::uint_fast32_t seed_) noexcept {
			mt.seed(seed_);
		}

		//通常の乱数
		[[nodiscard]] std::uint_fast32_t operator()() noexcept {
			return mt();
		}
		//0～最大値-1 (余りの範囲の一様分布乱数)
		[[nodiscard]] std::int_fast32_t operator()(const std::int_fast32_t max_) noexcept {
			if (max_ <= 1) return 0;
			std::uniform_int_distribution<> uid(0, max_ - 1);
			return uid(mt);
		}
		//最小値～最大値
		[[nodiscard]] std::int_fast32_t operator()(const std::int_fast32_t min_, const std::int_fast32_t max_) noexcept {
			std::uniform_int_distribution<> uid((min_ <= max_) ? min_ : max_, (min_ <= max_) ? max_ : min_);
			return uid(mt);
		}
		//確率
		[[nodiscard]] bool probability(const double probability_) noexcept {
			std::bernoulli_distribution uid(probability_);
			return uid(mt);
		}
		//1/2の確率
		[[nodiscard]] bool probability() noexcept {
			std::uniform_int_distribution<> uid(0, 1);
			return ((uid(mt)) ? true : false);
		}

	};
	static thread_local dtl::random::MersenneTwister32bit mersenne_twister_32bit;

} //namespace

#endif //Included Dungeon Template Library