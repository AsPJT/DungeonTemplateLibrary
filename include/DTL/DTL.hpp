/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


============================    Contributors    =========================

	[[Committers]]
	
	Mitama (@LoliGothick)
	Miutsuru kariya (@kariya-mitsuru)
	yumetodo (@yumetodo)

	[[UE4 Supporter]]

	ai (@ai2playgame)
	motty01 (@motty01)

#######################################################################################*/

#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_DTL_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_DTL_HPP

/* DTL宣言マクロ */
#ifndef DUNGEON_TEMPLATE_LIBRARY
#define DUNGEON_TEMPLATE_LIBRARY
#endif

/* バージョン */
#ifndef DUNGEON_TEMPLATE_LIBRARY_VERSION
#define DUNGEON_TEMPLATE_LIBRARY_VERSION (20190629L)
#endif


/* 基本クラスライブラリ (::dtl::base) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_BASE_HPP
#include <DTL/Base.hpp>

/* 文字列クラスライブラリ (::dtl::board) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_BOARD_HPP
#include <DTL/Board.hpp>

/* 視点ライブラリ (::dtl::camera) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_CAMERA_HPP
#include <DTL/Camera.hpp>

/* 時間ライブラリ (::dtl::chrono) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_CHRONO_HPP
#include <DTL/Chrono.hpp>

/* コンソールライブラリ (::dtl::console) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_CONSOLE_HPP
#include <DTL/Console.hpp>

/* 立体ライブラリ (::dtl::cuboid) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_CUBOID_HPP
#include <DTL/Cuboid.hpp>

/* 実体ライブラリ (::dtl::entity) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_ENTITY_HPP
#include <DTL/Entity.hpp>

/* 乱数ライブラリ (::dtl::random) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANDOM_HPP
#include <DTL/Random.hpp>

/* 加工ライブラリ (::dtl::retouch) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RETOUCH_HPP
#include <DTL/Retouch.hpp>

/* 形状生成ライブラリ (::dtl::shape) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_HPP
#include <DTL/Shape.hpp>

/* ストレージライブラリ (::dtl::storage) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_STORAGE_HPP
#include <DTL/Storage.hpp>

/* 多用途ライブラリ (::dtl::utility) */
//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_UTILITY_HPP
#include <DTL/Utility.hpp>

#endif //Included Dungeon Template Library
