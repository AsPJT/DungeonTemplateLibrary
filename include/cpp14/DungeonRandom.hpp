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
#include <limits>

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

	class RandXor128
	{
	private:
		std::uint_fast32_t x{ 123456789 }, y{ 362436069 }, z{ 521288629 }, w{ 88675123 };
	public:
		//通常の乱数
		constexpr std::uint_fast32_t operator()() noexcept {
			const std::uint_fast32_t t{ (x ^ (x << 11)) };
			x = y; y = z; z = w;
			return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
		}
		//0～最大値-1 (余りの範囲の一様分布乱数)
		constexpr std::uint_fast32_t operator()(const std::uint_fast32_t max_) noexcept {
			return ((std::uint_fast32_t)(((double)operator()() / ((double)(std::numeric_limits<std::uint_fast32_t>::max)() + 1)) * max_));
		}
		//最小値～最大値
		constexpr std::uint_fast32_t operator()(const std::uint_fast32_t min_, const std::uint_fast32_t max_) noexcept {
			return ((std::uint_fast32_t)(((double)operator()() / ((double)(std::numeric_limits<std::uint_fast32_t>::max)() + 1)) * (max_ - min_ + 1)) + min_);
		}

		constexpr void setSeed(const std::uint_fast32_t x_, const std::uint_fast32_t y_, const std::uint_fast32_t z_, const std::uint_fast32_t w_) noexcept {
			x = x_;
			y = y_;
			z = z_;
			w = w_;
		}

	};
	static thread_local RandXor128 rnd_xor_128;

}

#endif //Included Dungeon Template Library