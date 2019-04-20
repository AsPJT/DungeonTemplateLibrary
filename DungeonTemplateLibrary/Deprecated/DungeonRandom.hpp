/*#######################################################################################
	Made by Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_RANDOM
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_RANDOM

/* Character Code : UTF-8 (BOM) */
/* [2019/03/08] Android NDK Compile (Clang 5.0) : already checked */

#include <cstdint>
#include <random>
#include <limits>

//Dungeon Template Library Namespace
namespace dtl {
	inline namespace random {

		//乱数(Xorshift128)
		class Xor128
		{
		private:
			std::uint_fast32_t x{ 123456789 };
			std::uint_fast32_t y{ 362436069 };
			std::uint_fast32_t z{ 521288629 };
			std::uint_fast32_t w{ 88675123 };

		public:
			//通常の乱数
			constexpr std::uint_fast32_t operator()() noexcept {
				const std::uint_fast32_t t{ (x ^ (x << 11)) };
				x = y; y = z; z = w;
				return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
			}
			//0～最大値-1 (余りの範囲の一様分布乱数)
			[[nodiscard]] constexpr std::uint_fast32_t operator()(const std::uint_fast32_t max_) noexcept {
				return ((std::uint_fast32_t)(((double)operator()() / ((double)(std::numeric_limits<std::uint_fast32_t>::max)() + 1)) * max_));
			}
			//最小値～最大値
			[[nodiscard]] constexpr std::uint_fast32_t operator()(const std::uint_fast32_t min_, const std::uint_fast32_t max_) noexcept {
				//todo
				return ((std::uint_fast32_t)(((double)operator()() / ((double)(std::numeric_limits<std::uint_fast32_t>::max)() + 1)) * (max_ - min_ + 1)) + min_);
			}

			constexpr void setSeed(const std::uint_fast32_t x_, const std::uint_fast32_t y_, const std::uint_fast32_t z_, const std::uint_fast32_t w_) noexcept {
				x = x_;
				y = y_;
				z = z_;
				w = w_;
			}

		};
		static thread_local dtl::random::Xor128 xor_128;

		//乱数(Xorshift8)
		class Xor8
		{
		private:
			uint_fast8_t x{ 1 };
			uint_fast8_t a{ 1 };
			uint_fast8_t b{ 1 };
			uint_fast8_t c{ 2 };

		public:
			explicit Xor8() noexcept :x(static_cast<std::uint_fast8_t>(mersenne_twister_32bit(1, 255))) {}

			//通常の乱数
			[[nodiscard]] std::uint_fast8_t operator()() noexcept {
				x ^= x >> a;
				x ^= x << b;
				x ^= x >> c;
				return x;
			}
			//0～最大値-1 (余りの範囲の一様分布乱数)
			[[nodiscard]] std::uint_fast8_t operator()(const std::uint_fast8_t max_) noexcept {
				return ((std::uint_fast8_t)(((double)operator()() / ((double)(std::numeric_limits<std::uint_fast8_t>::max)() + 1)) * max_));
			}
			//最小値～最大値
			[[nodiscard]] std::uint_fast8_t operator()(const std::uint_fast8_t min_, const std::uint_fast8_t max_) noexcept {
				//todo
				return ((std::uint_fast8_t)(((double)operator()() / ((double)(std::numeric_limits<std::uint_fast8_t>::max)() + 1)) * (max_ - min_ + 1)) + min_);
			}

			void seed(const std::uint_fast8_t x_) noexcept {
				x = x_;
			}

		};
		static thread_local dtl::random::Xor8 xor_8;

	} //namespace
}

#endif //Included Dungeon Template Library