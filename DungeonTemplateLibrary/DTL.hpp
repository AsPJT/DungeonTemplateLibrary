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

#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_HPP

/* バージョン */
#ifndef DTL_VERSION
#define DTL_VERSION (20190427L)
#endif

/* 基本クラスライブラリ (dtl::base) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BASE_HPP
#include <DTL/Base.hpp>

/* 視点ライブラリ (dtl::camera) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CAMERA_HPP
#include <DTL/Camera.hpp>

/* コンソールライブラリ (dtl::console) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_HPP
#include <DTL/Console.hpp>

/* 非推奨ライブラリ */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DEPRECATED_HPP
#include <DTL/Deprecated.hpp>

/* 実体ライブラリ (dtl::entity) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_ENTITY_HPP
#include <DTL/Entity.hpp>

/* 乱数ライブラリ (dtl::random) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM_HPP
#include <DTL/Random.hpp>

/* 加工ライブラリ (dtl::retouch) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RETOUCH_HPP
#include <DTL/Retouch.hpp>

/* 形状生成ライブラリ (dtl::shape) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_HPP
#include <DTL/Shape.hpp>

/* ストレージライブラリ (dtl::storage) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_STORAGE_HPP
#include <DTL/Storage.hpp>

/* 多用途ライブラリ (dtl::utility) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_HPP
#include <DTL/Utility.hpp>

/* 画像書き出しライブラリ (dtl::thirdParty::stb) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_THIRD_PARTY_HPP
#include <DTL/ThirdParty.hpp>

#endif //Included Dungeon Template Library