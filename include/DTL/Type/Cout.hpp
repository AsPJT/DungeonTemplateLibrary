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

#if defined(UE_BUILD_FINAL_RELEASE) //UE4

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

#else

#include <iostream>
#define DTL_TYPE_COUT ::std::cout

#endif

#endif

#ifndef DTL_TYPE_COUT_END
#define DTL_TYPE_COUT_END
#endif

#endif //Included Dungeon Template Library