#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_RANDOM
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_RANDOM
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstdint>
#include <random>

//Dungeon Template Library Namespace
namespace dtl {

	class Rand {
	public:
		//コンストラクタ(初期化)
		explicit Rand() { mt.seed(rd()); }
	private:
		//32ビット版メルセンヌ・ツイスタ
		std::mt19937 mt;
		//非決定論的な乱数
		std::random_device rd;

	public:
		//初期値
		void seed() noexcept {
			mt.seed(rd());
		}
		void seed(const std::uint_fast32_t seed_) noexcept {
			mt.seed(seed_);
		}

		//通常の乱数
		std::uint_fast32_t operator()() noexcept {
			return mt();
		}
		//0～最大値-1 (余りの範囲の一様分布乱数)
		std::int_fast32_t operator()(const std::int_fast32_t max_) noexcept {
			std::uniform_int_distribution<> uid(0, ((max_ > 0) ? max_ - 1 : 0));
			return uid(mt);
		}
		//最小値～最大値
		std::int_fast32_t operator()(const std::int_fast32_t min_, const std::int_fast32_t max_) noexcept {
			std::uniform_int_distribution<> uid((min_ <= max_) ? min_ : max_, (min_ <= max_) ? max_ : min_);
			return uid(mt);
		}
		//確率
		bool randBool(const double probability_) noexcept {
			std::bernoulli_distribution uid(probability_);
			return uid(mt);
		}
		bool randBool() noexcept {
			std::uniform_int_distribution<> uid(0, 1);
			return ((uid(mt)) ? true : false);
		}
	};
	static thread_local Rand rnd;

}

#endif //Included Dungeon Template Library