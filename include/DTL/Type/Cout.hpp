/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_COUT_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_COUT_HPP

#ifndef DTL_TYPE_COUT

#if defined(UE_BUILD_FINAL_RELEASE) //Platform UE4

#include <sstream>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	namespace type { //"dtl::type"名前空間に属する
		class CoutUE4 {
		public:
			::std::stringstream ue4_sstream{};

			CoutUE4() {
				this->ue4_sstream << "[DTL]\n\n";
			}

			void output() {
				UE_LOG(LogTemp, Log, TEXT("%s"), *FString(this->ue4_sstream.str().c_str()));
				this->ue4_sstream = ::std::stringstream();
				this->ue4_sstream << "[DTL]\n\n";
			}
		};
		static CoutUE4 cout_ue4{};
	}
}
#define DTL_TYPE_COUT ::dtl::type::cout_ue4.ue4_sstream
#ifndef DTL_TYPE_COUT_END
#define DTL_TYPE_COUT_END ::dtl::type::cout_ue4.output();
#endif

#else //Platform Default

#ifndef DTL_DOES_NOT_INCLUDE_IOSTREAM
#include <iostream>
#define DTL_TYPE_COUT ::std::cout
#else //DTL_DOES_NOT_INCLUDE_IOSTREAM
#include <cstdio>
#include <string>
namespace dtl {
	namespace print {
		class Cout {
		public:
			const Cout& operator<<(const char output_) const {
				::std::printf("%c", output_);
				return *this;
			}
			const Cout& operator<<(const signed char output_) const {
				::std::printf("%hhd", output_);
				return *this;
			}
			const Cout& operator<<(const unsigned char output_) const {
				::std::printf("%hhu", output_);
				return *this;
			}
			const Cout& operator<<(const short output_) const {
				::std::printf("%hd", output_);
				return *this;
			}
			const Cout& operator<<(const unsigned short output_) const {
				::std::printf("%hu", output_);
				return *this;
			}
			const Cout& operator<<(const int output_) const {
				::std::printf("%d", output_);
				return *this;
			}
			const Cout& operator<<(const unsigned int output_) const {
				::std::printf("%u", output_);
				return *this;
			}
			const Cout& operator<<(const long output_) const {
				::std::printf("%ld", output_);
				return *this;
			}
			const Cout& operator<<(const unsigned long output_) const {
				::std::printf("%lu", output_);
				return *this;
			}
			const Cout& operator<<(const long long output_) const {
				::std::printf("%lld", output_);
				return *this;
			}
			const Cout& operator<<(const unsigned long long output_) const {
				::std::printf("%llu", output_);
				return *this;
			}
			const Cout& operator<<(const ::std::string& output_) const {
				::std::printf("%s", output_.c_str());
				return *this;
			}
			const Cout& operator<<(const char* const output_) const {
				::std::printf("%s", output_);
				return *this;
			}
			const Cout& operator<<(const float output_) const {
				::std::printf("%lf", output_);
				return *this;
			}
			const Cout& operator<<(const double output_) const {
				::std::printf("%lf", output_);
				return *this;
			}
			const Cout& operator<<(const long double output_) const {
				::std::printf("%Lf", output_);
				return *this;
			}
		};
	}
}
#define DTL_TYPE_COUT ::dtl::print::Cout()
#endif //DTL_DOES_NOT_INCLUDE_IOSTREAM

#endif //Platform

#endif //DTL_TYPE_COUT

#ifndef DTL_TYPE_COUT_END
#define DTL_TYPE_COUT_END
#endif //DTL_TYPE_COUT_END

#endif //Included Dungeon Template Library