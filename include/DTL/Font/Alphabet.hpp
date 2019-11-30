/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_FONT_ALPHABET_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_FONT_ALPHABET_HPP

#include <array>
#include <DTL/Type/SizeT.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace font { //"dtl::font"名前空間に属する

		constexpr dtl::type::size alphabet_num{ 26 };

		constexpr std::array<std::array<std::array<bool, 4>, 4>, alphabet_num> alphabet4x4{ {
	{{ //A
	{true,true,true,true},
	{true,false,false,true},
	{true,true,true,true},
	{true,false,false,true}
	}},{{ //B
	{true,true,true,false},
	{true,false,true,false},
	{true,false,false,true},
	{true,true,true,true}
	}},{{ //C
	{true,true,true,true},
	{true,false,false,false},
	{true,false,false,false},
	{true,true,true,true}
	}},{{ //D
	{true,true,true,false},
	{true,false,false,true},
	{true,false,false,true},
	{true,true,true,false}
	}},{{ //E
	{true,true,true,true},
	{true,false,false,false},
	{true,true,false,false},
	{true,true,true,true}
	}},{{ //F
	{true,true,true,true},
	{true,false,false,false},
	{true,true,true,true},
	{true,false,false,false}
	}},{{ //G
	{true,true,true,true},
	{true,false,false,false},
	{true,false,false,true},
	{true,true,true,true}
	}},{{ //H
	{true,false,false,true},
	{true,false,false,true},
	{true,true,true,true},
	{true,false,false,true}
	}},{{ //I
	{true,true,true,true},
	{false,false,true,false},
	{false,false,true,false},
	{true,true,true,true}
	}},{{ //J
	{false,false,false,true},
	{false,false,false,true},
	{true,false,false,true},
	{true,true,true,true}
	}},{{ //K
	{true,false,true,true},
	{true,true,true,false},
	{true,false,true,false},
	{true,false,true,true}
	}},{{ //L
	{true,false,false,false},
	{true,false,false,false},
	{true,false,false,false},
	{true,true,true,true}
	}},{{ //M
	{true,true,true,true},
	{true,false,true,true},
	{true,false,false,true},
	{true,false,false,true}
	}},{{ //N
	{true,false,false,true},
	{true,true,false,true},
	{true,false,true,true},
	{true,false,false,true}
	}},{{ //O
	{true,true,true,true},
	{true,false,false,true},
	{true,false,false,true},
	{true,true,true,true}
	}},{{ //P
	{true,true,true,true},
	{true,false,false,true},
	{true,true,true,true},
	{true,false,false,false}
	}},{{ //Q
	{true,true,true,true},
	{true,false,false,true},
	{true,false,true,true},
	{true,true,true,true}
	}},{{ //R
	{true,true,true,true},
	{true,false,false,true},
	{true,true,true,true},
	{true,false,true,false}
	}},{{ //S
	{true,true,true,true},
	{true,false,false,false},
	{false,false,false,true},
	{true,true,true,true}
	}},{{ //T
	{true,true,true,true},
	{false,false,true,false},
	{false,false,true,false},
	{false,false,true,false}
	}},{{ //U
	{true,false,false,true},
	{true,false,false,true},
	{true,false,false,true},
	{true,true,true,true}
	}},{{ //V
	{true,false,false,true},
	{true,false,false,true},
	{true,false,false,true},
	{false,true,true,false}
	}},{{ //W
	{true,false,false,true},
	{true,false,false,true},
	{true,false,true,true},
	{true,true,true,true}
	}},{{ //X
	{true,true,false,true},
	{false,false,true,false},
	{false,true,false,false},
	{true,false,true,true}
	}},{{ //Y
	{true,false,false,true},
	{true,false,false,true},
	{true,true,true,true},
	{false,false,true,false}
	}},{{ //Z
	{true,true,true,true},
	{false,false,false,true},
	{true,false,false,false},
	{true,true,true,true}
	}}
} };

	}
}

#endif //Included Dungeon Template Library
