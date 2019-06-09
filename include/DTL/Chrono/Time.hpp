/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_CHRONO_TIME_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_CHRONO_TIME_HPP

#include <chrono>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/ThreadLocal.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace chrono { //"dtl::chrono"名前空間に属する

		template<typename Clock_, typename Duration_>
		class Time {

			Clock_ mul_value{};
			::std::chrono::system_clock::time_point sc{ ::std::chrono::system_clock::now() };
			::std::chrono::system_clock::time_point old_sc{};
			Clock_ clock{};

		public:

			constexpr Time(const Clock_& value_) noexcept :mul_value(value_) {}

			Time& update() noexcept {
				this->old_sc = this->sc;
				this->sc = ::std::chrono::system_clock::now();
				this->clock = static_cast<Clock_>( ::std::chrono::duration_cast<Duration_>(this->sc - this->old_sc).count()) * this->mul_value;
				return *this;
			}

			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Clock_ get() const noexcept { return this->clock; }

		};
		//static DTL_TYPE_THREAD_LOCAL Time<double, ::std::chrono::nanoseconds> system_time(1.0e-09);

	}
}

#endif //Included Dungeon Template Library