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
#ifndef DUNGEON_TEMPLATE_LIBRARY_VERSION
#define DUNGEON_TEMPLATE_LIBRARY_VERSION (20190511L)
#endif


/* 基本クラスライブラリ (dtl::base) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BASE_HPP
#include <Dungeon/Base.hpp>

/* 視点ライブラリ (dtl::camera) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CAMERA_HPP
#include <Dungeon/Camera.hpp>

/* 時間ライブラリ (dtl::chrono) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CHRONO_HPP
#include <Dungeon/Chrono.hpp>

/* コンソールライブラリ (dtl::console) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_HPP
#include <Dungeon/Console.hpp>

/* 非推奨ライブラリ */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DEPRECATED_HPP
#if defined(_MSC_VER)
#if defined(_MSVC_LANG)
#if (_MSVC_LANG > 201103L)
#include <Dungeon/Deprecated.hpp>
#endif
#endif
#elif defined(__cplusplus)
#if (__cplusplus > 201103L)
#include <Dungeon/Deprecated.hpp>
#endif
#endif

/* 実体ライブラリ (dtl::entity) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_ENTITY_HPP
#include <Dungeon/Entity.hpp>

/* 乱数ライブラリ (dtl::random) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM_HPP
#include <Dungeon/Random.hpp>

/* 加工ライブラリ (dtl::retouch) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RETOUCH_HPP
#include <Dungeon/Retouch.hpp>

/* 形状生成ライブラリ (dtl::shape) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_HPP
#include <Dungeon/Shape.hpp>

/* ストレージライブラリ (dtl::storage) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_STORAGE_HPP
#include <Dungeon/Storage.hpp>

/* 多用途ライブラリ (dtl::utility) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_HPP
#include <Dungeon/Utility.hpp>

///* 画像書き出しライブラリ (dtl::thirdParty::stb) */
////#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_THIRD_PARTY_HPP
//#include <Dungeon/ThirdParty.hpp>

#endif //Included Dungeon Template Library