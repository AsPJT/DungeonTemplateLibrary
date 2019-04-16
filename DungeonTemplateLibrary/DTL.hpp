/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/

#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY

/* 基本クラスライブラリ (dtl::base) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BASE
#include <DungeonBase.hpp>

/* 視点ライブラリ */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CAMERA
#include <DungeonCamera.hpp>

/* コンソールライブラリ (dtl::console) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE
#include <DungeonConsole.hpp>

/* 非推奨ライブラリ */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DEPRECATED
#include <DungeonDeprecated.hpp>

/* 実体ライブラリ (dtl::entity) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_ENTITY
#include <DungeonEntity.hpp>

/* 乱数ライブラリ (dtl::random) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM
#include <DungeonRandom.hpp>

/* 加工ライブラリ (dtl::retouch) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RETOUCH
#include <DungeonRetouch.hpp>

/* 形状生成ライブラリ (dtl::shape) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE
#include <DungeonShape.hpp>

/* ストレージライブラリ (dtl::storage) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_STORAGE
#include <DungeonStorage.hpp>

/* 多用途ライブラリ (dtl::utility) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY
#include <DungeonUtility.hpp>

/* 画像書き出しライブラリ (dtl::thirdParty::stb) */
#include <DungeonThirdParty.hpp>

#endif //Included Dungeon Template Library