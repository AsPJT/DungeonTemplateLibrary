/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANDOM_MERSENNE_TWISTER_32_BIT_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANDOM_MERSENNE_TWISTER_32_BIT_HPP

#include <cstdint>
#include <bitset>
#include <random>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Type/ThreadLocal.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace random { //"dtl::random"名前空間に属する


/*#######################################################################################
	[概要] 乱数 (64ビット版メルセンヌ・ツイスタ)
	[Summary] Random number (64-bit version Mersenne Twister)
#######################################################################################*/
		class MersenneTwister_64bit {
		private:
			//64ビット版メルセンヌ・ツイスタ (64-bit version Mersenne Twister)
			::std::mt19937_64 mt;
			//非決定論的な乱数
			::std::random_device rd;

		public:
			//コンストラクタ(初期化)
			explicit MersenneTwister_64bit() { this->mt.seed(this->rd()); }


/*#######################################################################################
	[概要] 自動的に乱数値をSEED値に設定する。
	[Summary] Set the random value to the SEED value.
#######################################################################################*/
			void seed() {
				this->mt.seed(this->rd());
			}


/*#######################################################################################
	[概要] 指定した値をSEED値に設定する。
	[Summary] Set the argument value to the SEED value.
#######################################################################################*/
			template<typename Random_Int_ = ::std::uint_fast64_t>
			void seed(const Random_Int_ seed_) {
				this->mt.seed(static_cast< ::std::uint_fast64_t>(seed_));
			}


/*#######################################################################################
	[概要] 乱数を取得する。
	[戻り値] 戻り値の型は Random_Int_(デフォルトはstd::uint_fast64_t) である。
	[Summary] Get a random number.
	[Return value] The return type is Random_Int_ (default is std::uint_fast64_t).
#######################################################################################*/
			template<typename Random_Int_ = ::std::uint_fast64_t>
			DTL_VERSIONING_CPP17_NODISCARD
			Random_Int_ get() {
				return static_cast<Random_Int_>(this->mt());
			}

		};
		static DTL_TYPE_THREAD_LOCAL::dtl::random::MersenneTwister_64bit mt64bit;

		constexpr ::dtl::type::size mt64_bit_counter_num_1{ 64 };
		class MT64bit_1 {
		private:
			::dtl::type::size counter{ mt64_bit_counter_num_1 };
			::std::uint_fast64_t random_num{};
		public:
			DTL_VERSIONING_CPP17_NODISCARD
			bool get() {
				if (this->counter >= mt64_bit_counter_num_1) {
					this->random_num = ::dtl::random::mt64bit.get();
					this->counter = 0;
				}
				else ++(this->counter);

				const bool tmp{ (this->random_num & 1) == 0 };
				this->random_num >>= 1;
				return tmp;
			}
		};
		static DTL_TYPE_THREAD_LOCAL::dtl::random::MT64bit_1 mt64bit_1;

		constexpr ::dtl::type::size mt32_bit_counter_num_1{ 32 };


/*#######################################################################################
	[概要] 乱数 (32ビット版メルセンヌ・ツイスタ)
	[Summary] Random number (32-bit version Mersenne Twister)
#######################################################################################*/
		class MersenneTwister_32bit {
		private:
			//32ビット版メルセンヌ・ツイスタ
			::std::mt19937 mt;
			//非決定論的な乱数
			::std::random_device rd;

			::dtl::type::size counter_bit1{ mt32_bit_counter_num_1 };
			::std::uint_fast32_t random_num_bit1{};

			DTL_VERSIONING_CPP17_NODISCARD
				bool getBit1() {
				if (counter_bit1 >= mt32_bit_counter_num_1) {
					random_num_bit1 = this->get();
					counter_bit1 = 0;
				}
				else ++counter_bit1;

				const bool tmp{ (random_num_bit1 & 1) == 0 };
				random_num_bit1 >>= 1;
				return tmp;
			}

		public:
			//コンストラクタ(初期化)
			explicit MersenneTwister_32bit() { this->mt.seed(this->rd()); }


/*#######################################################################################
	[概要] 自動的に乱数値をSEED値に設定する。
	[Summary] Set the random value to the SEED value.
#######################################################################################*/
			void seed() {
				this->mt.seed(this->rd());
			}


/*#######################################################################################
	[概要] 引数の値をSEED値に設定する。
	[Summary] Set the argument value to the SEED value.
#######################################################################################*/
			template<typename Random_Int_ = ::std::uint_fast32_t>
			void seed(const Random_Int_ seed_) {
				this->mt.seed(static_cast< ::std::uint_fast32_t>(seed_));
			}


/*#######################################################################################
	[概要] 乱数を取得する。
	[戻り値] 戻り値の型は Random_Int_(デフォルトはstd::uint_fast32_t) である。
	[Summary] Get a random number.
	[Return value] The return type is Random_Int_ (default is std::uint_fast32_t).
#######################################################################################*/
			template<typename Random_Int_ = ::std::uint_fast32_t>
			DTL_VERSIONING_CPP17_NODISCARD
			Random_Int_ get() {
				return static_cast<Random_Int_>(this->mt());
			}


/*#######################################################################################
	[概要] "0"から"引数の値-1"まで(余りの範囲の一様分布乱数)の範囲の乱数を取得する。
	[戻り値] 戻り値の型は Random_Int_(デフォルトはstd::int_fast32_t) である。
	[Summary] Get a random number in the range of 0 to argument value - 1.
	[Return value] The return type is Random_Int_ (default is std::int_fast32_t).
#######################################################################################*/
			template<typename Random_Int_ = ::std::int_fast32_t, typename Random_Int2_>
			DTL_VERSIONING_CPP17_NODISCARD
			Random_Int_ get(const Random_Int2_ max_) {
				if (static_cast< ::std::int_fast32_t>(max_) <= 1) return 0;
				::std::uniform_int_distribution<> uid(0, static_cast< ::std::int_fast32_t>(max_) - 1);
				return static_cast<Random_Int_>(uid(this->mt));
			}


/*#######################################################################################
	[概要] "第一引数の値"から"第二引数の値"までの範囲の乱数を取得する。
	[戻り値] 戻り値の型は Random_Int_(デフォルトはstd::int_fast32_t) である。
	[Summary] Gets a random number in the range of the first argument value to the second argument value.
	[Return value] The return type is Random_Int_ (default is std::int_fast32_t).
#######################################################################################*/
			template<typename Random_Int_ = ::std::int_fast32_t, typename Random_Int2_, typename Random_Int3_>
			DTL_VERSIONING_CPP17_NODISCARD
			Random_Int_ get(const Random_Int2_ min_, const Random_Int3_ max_) {
				::std::uniform_int_distribution<> uid(static_cast< ::std::int_fast32_t>((min_ <= static_cast<Random_Int2_>(max_)) ? min_ : static_cast<Random_Int2_>(max_)), static_cast< ::std::int_fast32_t>((min_ <= static_cast<Random_Int2_>(max_)) ? static_cast<Random_Int2_>(max_) : min_));
				return static_cast<Random_Int_>(uid(this->mt));
			}


/*#######################################################################################
	[概要] 引数の値(0.0から1.0)の確率で"true"を返し、その他の確率で"false"を返す。
	[戻り値] 戻り値の型は bool である。
	[Summary] Returns "true" with probability of argument value (0.0 to 1.0) and "false" with other probability.
	[Return value] The return type is bool.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
			bool probability(const double probability_) {
				::std::bernoulli_distribution uid(probability_);
				return uid(this->mt);
			}


/*#######################################################################################
	[概要] 50%の確率で"true"を返し、50%の確率で"false"を返す。
	[戻り値] 戻り値の型は bool である。
	[Summary] It returns "true" with a 50% probability, and returns "false" with a 50% probability.
	[Return value] The return type is bool.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
			bool probability() {
				return this->getBit1();
			}

		};
		static DTL_TYPE_THREAD_LOCAL::dtl::random::MersenneTwister_32bit mt32bit;

		
		class MT32bit_1 {
		private:
			::dtl::type::size counter{ mt32_bit_counter_num_1 };
			::std::uint_fast32_t random_num{};
		public:
			DTL_VERSIONING_CPP17_NODISCARD
				bool get() {
				if (counter >= mt32_bit_counter_num_1) {
					random_num = ::dtl::random::mt32bit.get();
					counter = 0;
				}
				else ++counter;

				const bool tmp{ (random_num & 1) == 0 };
				random_num >>= 1;
				return tmp;
			}
		};
		static DTL_TYPE_THREAD_LOCAL::dtl::random::MT32bit_1 mt32bit_1;


		constexpr ::dtl::type::size counter_num_2{ 32 };
		constexpr ::dtl::type::size counter_bit_num_2{ counter_num_2 * 2 };
		class MT64bit_4 {
		private:
			::dtl::type::size counter{ counter_num_2 };
			::std::uint_fast64_t random_num{};
		public:
			template<typename Random_Int_ = ::std::uint_fast64_t>
			DTL_VERSIONING_CPP17_NODISCARD
			Random_Int_ get() {
				if (this->counter >= counter_num_2) {
					this->random_num = ::dtl::random::mt64bit.get();
					this->counter = 0;
				}
				else ++(this->counter);
				const ::std::uint_fast64_t tmp{ this->random_num & 3 };
				this->random_num >>= 2;
				return static_cast<Random_Int_>(tmp);
			}
		};
		static DTL_TYPE_THREAD_LOCAL::dtl::random::MT64bit_4 mt64bit_4;

		//乱数(32ビット版メルセンヌ・ツイスタ)
		class MersenneTwister32bit {
		private:
			//32ビット版メルセンヌ・ツイスタ
			::std::mt19937 mt;
			//非決定論的な乱数
			::std::random_device rd;

		public:
			//コンストラクタ(初期化)
			explicit MersenneTwister32bit() { this->mt.seed(this->rd()); }


/*#######################################################################################
	[概要] 自動的に乱数値をSEED値に設定する。
	[Summary] Set the random value to the SEED value.
#######################################################################################*/
			void seed() {
				this->mt.seed(this->rd());
			}

/*#######################################################################################
	[概要] 指定した値をSEED値に設定する。
	[Summary] Set the argument value to the SEED value.
#######################################################################################*/
			void seed(const ::std::uint_fast32_t seed_) {
				this->mt.seed(seed_);
			}

			//通常の乱数
			DTL_VERSIONING_CPP17_NODISCARD
			::std::uint_fast32_t operator()() {
				return this->mt();
			}
			//0～最大値-1 (余りの範囲の一様分布乱数)
			DTL_VERSIONING_CPP17_NODISCARD
			::std::int_fast32_t operator()(const ::std::int_fast32_t max_) {
				if (max_ <= 1) return 0;
				::std::uniform_int_distribution<> uid(0, max_ - 1);
				return uid(this->mt);
			}
			//最小値～最大値
			DTL_VERSIONING_CPP17_NODISCARD
			::std::int_fast32_t operator()(const ::std::int_fast32_t min_, const ::std::int_fast32_t max_) {
				::std::uniform_int_distribution<> uid((min_ <= max_) ? min_ : max_, (min_ <= max_) ? max_ : min_);
				return uid(this->mt);
			}


/*#######################################################################################
	[概要] 引数の値(0.0から1.0)の確率で"true"を返し、その他の確率で"false"を返す。
	[戻り値] 戻り値の型は bool である。
	[Summary] Returns "true" with probability of argument value (0.0 to 1.0) and "false" with other probability.
	[Return value] The return type is bool.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
			bool probability(const double probability_) {
				::std::bernoulli_distribution uid(probability_);
				return uid(this->mt);
			}


/*#######################################################################################
	[概要] 50%の確率で"true"を返し、50%の確率で"false"を返す。
	[戻り値] 戻り値の型は bool である。
	[Summary] It returns "true" with a 50% probability, and returns "false" with a 50% probability.
	[Return value] The return type is bool.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
			bool probability() {
				::std::uniform_int_distribution<> uid(0, 1);
				return ((uid(this->mt)) ? true : false);
			}

		};
		static DTL_TYPE_THREAD_LOCAL::dtl::random::MersenneTwister32bit mersenne_twister_32bit;

	} //namespace
}

#endif //Included Dungeon Template Library
