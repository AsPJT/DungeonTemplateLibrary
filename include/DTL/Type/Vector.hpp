/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_VECTOR_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_VECTOR_HPP


#ifndef DTL_TYPE_VECTOR


#if defined(UE_BUILD_FINAL_RELEASE) //Platform UE4

#include <DTL/Type/SizeT.hpp>
#define DTL_TYPE_VECTOR ::TArray
#ifndef DTL_TYPE_VSIZE
#define DTL_TYPE_VSIZE Num
#endif
#ifndef DTL_TYPE_VEMPLACE
#define DTL_TYPE_VEMPLACE Emplace
#endif
#ifndef DTL_TYPE_VPUSH
#define DTL_TYPE_VPUSH Add
#endif
#ifndef DTL_TYPE_VSHRINK
#define DTL_TYPE_VSHRINK Shrink
#endif

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	namespace type { //"dtl::type"名前空間に属する
		template<typename Int_>
		DTL_TYPE_VECTOR<Int_> makeVector(const ::dtl::type::size size_, const Int_& int_) noexcept {
			DTL_TYPE_VECTOR<Int_> mv{};
			mv.Init(int_, size_);
			return mv;
		}
	}
}

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	namespace type { //"dtl::type"名前空間に属する
		template<typename Vector_, typename Value_>
		DTL_VERSIONING_CPP14_CONSTEXPR
		void removeVector(Vector_& vector_, const Value_ value_) noexcept {
			vector_.Remove(value_);
		}
	}
}

#else //Platform Default

#include <algorithm>
#include <vector>
#include <DTL/Type/SizeT.hpp>
#define DTL_TYPE_VECTOR ::std::vector
#ifndef DTL_TYPE_VSIZE
#define DTL_TYPE_VSIZE size
#endif
#ifndef DTL_TYPE_VEMPLACE
#define DTL_TYPE_VEMPLACE emplace_back
#endif
#ifndef DTL_TYPE_VPUSH
#define DTL_TYPE_VPUSH push_back
#endif
#ifndef DTL_TYPE_VSHRINK
#define DTL_TYPE_VSHRINK shrink_to_fit
#endif

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	namespace type { //"dtl::type"名前空間に属する
		template<typename Int_>
		DTL_TYPE_VECTOR<Int_> makeVector(const ::dtl::type::size size_, const Int_& int_) noexcept {
			return DTL_TYPE_VECTOR<Int_>(size_, int_);
		}
	}
}

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	namespace type { //"dtl::type"名前空間に属する
		template<typename Vector_,typename Value_>
		DTL_VERSIONING_CPP14_CONSTEXPR
		void removeVector(Vector_& vector_, const Value_ value_) noexcept {
			vector_.erase(::std::remove(vector_.begin(), vector_.end(), value_), vector_.end());
		}
	}
}

#endif //Platform


#endif


#endif //Included Dungeon Template Library