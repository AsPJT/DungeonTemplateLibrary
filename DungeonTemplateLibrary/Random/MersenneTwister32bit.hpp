/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM_MERSENNE_TWISTER_32_BIT
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM_MERSENNE_TWISTER_32_BIT

/* Character Code : UTF-8 (BOM) */
/* Bug Check : not checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstdint>
#include <random>
#include <bitset>

namespace dtl {
	inline namespace random {

		//乱数(64ビット版メルセンヌ・ツイスタ)
		class MersenneTwister_64bit {
		private:
			//64ビット版メルセンヌ・ツイスタ
			std::mt19937_64 mt;
			//非決定論的な乱数
			std::random_device rd;

		public:
			//コンストラクタ(初期化)
			explicit MersenneTwister_64bit() noexcept { mt.seed(rd()); }

			//初期値
			void seed() noexcept {
				mt.seed(rd());
			}
			template<typename Random_Int_ = std::uint_fast64_t>
			void seed(const Random_Int_ seed_) noexcept {
				mt.seed(static_cast<std::uint_fast64_t>(seed_));
			}

			//通常の乱数
			template<typename Random_Int_ = std::uint_fast64_t>
			[[nodiscard]] Random_Int_ get() noexcept {
				return static_cast<Random_Int_>(mt());
			}

		};
		static thread_local dtl::random::MersenneTwister_64bit mt64bit;

		constexpr std::size_t counter_num_1{ 64 };
		class MT64bit_1 {
		private:
			std::size_t counter{ counter_num_1 };
			std::uint_fast64_t random_num{};
		public:
			[[nodiscard]] bool get() noexcept {
				if (counter >= counter_num_1) {
					random_num = dtl::random::mt64bit.get();
					counter = 0;
				}
				else ++counter;

				const bool tmp{ (random_num & 1) == 0 };
				random_num >>= 1;
				return tmp;
			}
		};
		static thread_local dtl::random::MT64bit_1 mt64bit_1;

		//乱数(32ビット版メルセンヌ・ツイスタ)
		class MersenneTwister_32bit {
		private:
			//32ビット版メルセンヌ・ツイスタ
			std::mt19937 mt;
			//非決定論的な乱数
			std::random_device rd;

		public:
			//コンストラクタ(初期化)
			explicit MersenneTwister_32bit() noexcept { mt.seed(rd()); }

			//初期値
			void seed() noexcept {
				mt.seed(rd());
			}
			template<typename Random_Int_ = std::uint_fast32_t>
			void seed(const Random_Int_ seed_) noexcept {
				mt.seed(static_cast<std::uint_fast32_t>(seed_));
			}

			//通常の乱数
			template<typename Random_Int_ = std::uint_fast32_t>
			[[nodiscard]] Random_Int_ get() noexcept {
				return static_cast<Random_Int_>(mt());
			}
			//0～最大値-1 (余りの範囲の一様分布乱数)
			template<typename Random_Int_ = std::int_fast32_t, typename Random_Int2_>
			[[nodiscard]] Random_Int_ get(const Random_Int2_ max_) noexcept {
				if (static_cast<std::int_fast32_t>(max_) <= 1) return 0;
				std::uniform_int_distribution<> uid(0, static_cast<std::int_fast32_t>(max_) - 1);
				return static_cast<Random_Int_>(uid(mt));
			}
			//最小値～最大値
			template<typename Random_Int_ = std::int_fast32_t, typename Random_Int2_, typename Random_Int3_>
			[[nodiscard]] Random_Int_ get(const Random_Int2_ min_, const Random_Int3_ max_) noexcept {
				std::uniform_int_distribution<> uid(static_cast<std::int_fast32_t>((min_ <= static_cast<Random_Int2_>(max_)) ? min_ : static_cast<Random_Int2_>(max_)), static_cast<std::int_fast32_t>((min_ <= static_cast<Random_Int2_>(max_)) ? static_cast<Random_Int2_>(max_) : min_));
				return static_cast<Random_Int_>(uid(mt));
			}
			//確率
			[[nodiscard]] bool probability(const double probability_) noexcept {
				std::bernoulli_distribution uid(probability_);
				return uid(mt);
			}
			//1/2の確率
			[[nodiscard]] bool probability() noexcept {
				//std::uniform_int_distribution<> uid(0, 1);
				//return ((uid(mt)) ? true : false);
				return dtl::random::mt64bit_1.get();
			}

		};
		static thread_local dtl::random::MersenneTwister_32bit mt32bit;



		constexpr std::size_t counter_num_2{ 32 };
		constexpr std::size_t counter_bit_num_2{ counter_num_2 * 2 };
		class MT64bit_4 {
		private:
			std::size_t counter{ counter_num_2 };
			std::uint_fast64_t random_num{};
		public:
			template<typename Random_Int_ = std::uint_fast64_t>
			[[nodiscard]] Random_Int_ get() noexcept {
				if (counter >= counter_num_2) {
					random_num = dtl::random::mt64bit.get();
					counter = 0;
				}
				else ++counter;
				const auto tmp{ random_num & 3 };
				random_num >>= 2;
				return static_cast<Random_Int_>(tmp);
			}
		};
		static thread_local dtl::random::MT64bit_4 mt64bit_4;

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
}

#endif //Included Dungeon Template Library