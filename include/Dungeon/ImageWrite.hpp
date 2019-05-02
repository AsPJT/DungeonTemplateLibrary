/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################
	Visual Studio Option

	[Language Standard Version] /std:c++latest ( or /std:c++17 or /std:c++14 )
	[Additional Options] /Zc:__cplusplus
#######################################################################################*/

#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_IMAGE_WRITE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_IMAGE_WRITE_HPP

#ifndef STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <ThirdParty/STB/stb_image_write.h>
#endif

#include <Storage/FileBMP.hpp>
#include <Storage/FileHDR.hpp>
#include <Storage/FileJPG.hpp>
#include <Storage/FilePNG.hpp>
#include <Storage/FileTGA.hpp>

#endif //Included Dungeon Template Library