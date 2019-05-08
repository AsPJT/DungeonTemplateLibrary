/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/

///// ///// ///// 非推奨ライブラリ ///// ///// /////

/*機能が古くなった関数やクラスを扱う。
(特に "STL, Normal, Array, LayerSTL, LayerNormal"の中の一部の出力機能が欠けている場合が多い)*/

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DEPRECATED_HPP
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DEPRECATED_HPP

#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DEPRECATED_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DEPRECATED_HPP


///// 関連ツール /////

#include <Deprecated/DungeonFile.hpp>
#include <Deprecated/DungeonMatrix.hpp>
#include <Deprecated/DungeonNoise.hpp>


///// ダンジョン /////

#include <Deprecated/BoardGame.hpp>
#include <Deprecated/FractalIsland.hpp>
#include <Deprecated/HorizontalScroll.hpp>
#include <Deprecated/RogueLike.hpp>


///// ペイント /////

#include <Deprecated/DungeonPaint.hpp>

#endif //INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DEPRECATED_HPP
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DEPRECATED_HPP