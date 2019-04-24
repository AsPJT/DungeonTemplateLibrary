/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/

///// ///// ///// 非推奨ライブラリ ///// ///// /////

/*機能が古くなった関数やクラスを扱う。
(特に "STL, Normal, Array, LayerSTL, LayerNormal"の中の一部の出力機能が欠けている場合が多い)*/

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DEPRECATED
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DEPRECATED

#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DEPRECATED
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DEPRECATED


///// 関連ツール /////

//#include <Deprecated/DungeonBinarization.hpp>

#include <Deprecated/DungeonNoise.hpp>

//#include <Deprecated/DungeonOutput.hpp>

//#include <Deprecated/DungeonRandom.hpp>

#include <Deprecated/DungeonFile.hpp>

#include <Deprecated/DungeonMatrix.hpp>


///// ダンジョン /////

#include <Deprecated/FractalIsland.hpp>

//#include <Deprecated/MazeDig.hpp>

#include <Deprecated/RogueLike.hpp>

//#include <Deprecated/SimpleRogueLike.hpp>

#include <Deprecated/SimpleVoronoiIsland.hpp>

#include <Deprecated/BoardGame.hpp>

#include <Deprecated/HorizontalScroll.hpp>


///// ペイント /////

#include <Deprecated/DungeonPaint.hpp>

#endif //INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DEPRECATED
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DEPRECATED