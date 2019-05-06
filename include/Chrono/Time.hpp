/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CHRONO_TIME_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CHRONO_TIME_HPP

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <chrono>
#include <Macros/nodiscard.hpp>

namespace dtl {
	inline namespace chrono {

		template<typename Clock_, typename Duration_>
		class Time {

			Clock_ mul_value{};
			std::chrono::system_clock::time_point sc{ std::chrono::system_clock::now() };
			std::chrono::system_clock::time_point old_sc{};
			Clock_ clock{};

		public:

			constexpr Time(const Clock_& value_) noexcept :mul_value(value_) {}

			Time& update() noexcept {
				this->old_sc = this->sc;
				this->sc = std::chrono::system_clock::now();
				this->clock = static_cast<Clock_>(std::chrono::duration_cast<Duration_>(this->sc - this->old_sc).count()) * this->mul_value;
				return *this;
			}

			DTL_NODISCARD
			constexpr Clock_ get() const noexcept { return this->clock; }

		};
		static thread_local Time<double, std::chrono::nanoseconds> system_time(1.0e-09);

	}
}

#endif //Included Dungeon Template Library