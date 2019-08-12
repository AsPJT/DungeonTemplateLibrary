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
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/NumericLimits.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Type/ThreadLocal.hpp>

#ifndef DTL_RANDOM_INIT_SEED
#define DTL_RANDOM_INIT_SEED ::std::random_device()()
#endif

#ifndef DTL_RANDOM_ENGINE
#define DTL_RANDOM_ENGINE ::dtl::random::RandClassMT::random_engine
#endif

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace random { //"dtl::random"名前空間に属する

		template<typename T>
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr ::dtl::type::size bitCheck(const T value_, const ::dtl::type::size bit_ = 0) noexcept {
			return (value_ == 0) ? bit_ : ::dtl::random::bitCheck(value_ / 2, bit_ + 1);
		}

/*#######################################################################################
	[概要] 乱数 (32ビット版メルセンヌ・ツイスタ)
	[Summary] Random number (32-bit version Mersenne Twister)
#######################################################################################*/
		template<typename Random_Engine_ = ::std::mt19937>
		class Random {
		private:
			//32ビット版メルセンヌ・ツイスタ
			Random_Engine_ mt;
			//非決定論的な乱数
			//::std::random_device rd;

			::dtl::type::size bit_num{};

			::dtl::type::size counter_bit1{};
			::dtl::type::size counter_bit2{};
			::std::uint_fast32_t random_num_bit1{};
			::std::uint_fast32_t random_num_bit2{};

			template<typename T>
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr ::dtl::type::size bitInit2(T) const noexcept {
				return ::dtl::random::bitCheck((DTL_TYPE_NUMERIC_LIMITS<T>::DTL_TYPE_NUMERIC_LIMITS_MAX)());
			}
			DTL_VERSIONING_CPP17_NODISCARD
			::dtl::type::size bitInit() noexcept {
				return this->bitInit2(this->mt());
			}

			DTL_VERSIONING_CPP17_NODISCARD
				bool getBit1() {
				if (counter_bit1 >= bit_num) {
					random_num_bit1 = this->get();
					counter_bit1 = 0;
				}
				else ++counter_bit1;

				const bool tmp{ (random_num_bit1 & 1) == 0 };
				random_num_bit1 >>= 1;
				return tmp;
			}

		public:
				template<typename Random_Int_ = ::dtl::type::size>
				DTL_VERSIONING_CPP17_NODISCARD
					Random_Int_ getBit2() {
					if (this->counter_bit2 >= bit_num / 2) {
						this->random_num_bit2 = this->get();
						this->counter_bit2 = 0;
					}
					else ++counter_bit2;
					const ::std::uint_fast32_t tmp{ this->random_num_bit2 & 3 };
					this->random_num_bit2 >>= 2;
					return static_cast<Random_Int_>(tmp);
				}

			//コンストラクタ(初期化)
			Random() :mt(DTL_RANDOM_INIT_SEED), bit_num(this->bitInit()), counter_bit1(bit_num), counter_bit2(bit_num / 2) {}

			template<typename Seed_, typename ...Args_>
			Random(Seed_&& seed_, Args_&& ... args_) :mt(DTL_TYPE_FORWARD<Seed_>(seed_), DTL_TYPE_FORWARD<Args_>(args_)...),
				bit_num(this->bitInit()), counter_bit1(bit_num), counter_bit2(bit_num / 2) {}


/*#######################################################################################
	[概要] 自動的に乱数値をSEED値に設定する。
	[Summary] Set the random value to the SEED value.
#######################################################################################*/
			void seed() {
				this->mt.seed(DTL_RANDOM_INIT_SEED);
			}


/*#######################################################################################
	[概要] 引数の値をSEED値に設定する。
	[Summary] Set the argument value to the SEED value.
#######################################################################################*/
			template<typename Seed_, typename ...Args_>
			void seed(Seed_&& seed_, Args_&& ... args_) {
				this->mt.seed(DTL_TYPE_FORWARD<Seed_>(seed_), DTL_TYPE_FORWARD<Args_>(args_)...);
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
		template<typename T>
		struct RandClass {
			static DTL_TYPE_THREAD_LOCAL ::dtl::random::Random<T> random_engine;
		};
		template<typename T>
		DTL_TYPE_THREAD_LOCAL ::dtl::random::Random<T> RandClass<T>::random_engine;
		using RandClassMT = RandClass<::std::mt19937>;

	} //namespace
}

#endif //Included Dungeon Template Library
