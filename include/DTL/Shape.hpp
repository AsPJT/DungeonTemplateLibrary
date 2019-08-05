/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/

///// ///// ///// 形状生成 ///// ///// /////

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_HPP
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_HPP

#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_HPP

#include <DTL/Shape/AscendingOrder.hpp>
#include <DTL/Shape/AscendingOrder2.hpp>
#include <DTL/Shape/Border.hpp>
//Shape_Border + また、指定マスの列数が偶数の時[列数-2列目]を設置し、行数が偶数の時[行数-2行目]のマスに任意の値(1)を設置する(※行/列は0から数える)。
#include <DTL/Shape/BorderOdd.hpp>
#include <DTL/Shape/CellularAutomatonIsland.hpp>
#include <DTL/Shape/CellularAutomatonMixIsland.hpp>
#include <DTL/Shape/DiamondSquareAverage.hpp>
#include <DTL/Shape/DiamondSquareAverageCornerIsland.hpp>
#include <DTL/Shape/DiamondSquareAverageIsland.hpp>
#include <DTL/Shape/DobutsuShogi.hpp>
#include <DTL/Shape/FractalIsland.hpp>
#include <DTL/Shape/FractalLoopIsland.hpp>
#include <DTL/Shape/MazeDig.hpp>
#include <DTL/Shape/MixRect.hpp>
#include <DTL/Shape/PerlinIsland.hpp>
#include <DTL/Shape/PerlinLoopIsland.hpp>
#include <DTL/Shape/Point.hpp>
//指定マスの偶数列目かつ偶数行目に任意の値(1)を設置する。
#include <DTL/Shape/PointGrid.hpp>
//Shape_BorderOdd + Shape_PointGrid + Shape_RandomRect
#include <DTL/Shape/PointGridAndSomeBlocksWithBorder.hpp>
//Shape_BorderOdd + Shape_PointGrid
#include <DTL/Shape/PointGridWithBorder.hpp>
//指定マスに一定の確率で任意の値(1)を設置する。
#include <DTL/Shape/RandomRect.hpp>
#include <DTL/Shape/RandomVoronoi.hpp>
//指定マスの全てに任意の値(1)を設置する。
#include <DTL/Shape/Rect.hpp>
#include <DTL/Shape/Reversi.hpp>
#include <DTL/Shape/Shogi.hpp>
#include <DTL/Shape/SimplePyramid.hpp>
#include <DTL/Shape/SimpleRogueLike.hpp>
#include <DTL/Shape/SimpleTruncatedSquarePyramid.hpp>
#include <DTL/Shape/SimpleVoronoiIsland.hpp>
#include <DTL/Shape/WhiteNoise.hpp>

#endif //INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_HPP
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_HPP
