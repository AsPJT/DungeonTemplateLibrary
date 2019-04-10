/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY


#include <Base/Struct.hpp>

///// β版テストライブラリ /////

/*機能が不十分な関数やクラスを扱う。
(特に "STL, Normal, Array, LayerSTL, LayerNormal"の中の一部の出力機能が欠けている場合が多い)*/

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BETA
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BETA

///// 関連ツール /////

#include <Beta/DungeonBinarization.hpp>
#include <Beta/DungeonNoise.hpp>
#include <Beta/DungeonOutput.hpp>
#include <Beta/DungeonRandom.hpp>
#include <Beta/DungeonFile.hpp>
#include <Beta/DungeonMatrix.hpp>

#include <Storage/FileCSV.hpp>
#include <Storage/FileTerrainOBJ.hpp>

///// ダンジョン /////

#include <Beta/FractalIsland.hpp>
#include <Beta/MazeDig.hpp>
#include <Beta/RogueLike.hpp>
#include <Beta/SimpleRogueLike.hpp>
#include <Beta/SimpleVoronoiIsland.hpp>
#include <Beta/BoardGame.hpp>
#include <Beta/HorizontalScroll.hpp>
//ペイント
#include <Beta/DungeonPaint.hpp>
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BETA


///// コンソール出力 /////

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE
//指定マスの値を数値で出力する。
#include <Console/OutputNumber.hpp>
//指定マスの値を指定した文字で出力する。
#include <Console/OutputString.hpp>
//指定マスの値(2値)を指定した文字で出力する。
#include <Console/OutputStringBool.hpp>
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE


///// 便利な機能 /////

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY
#include <Utility/Binarization.hpp>
#include <Utility/Binarization_Over.hpp>
#include <Utility/Copy.hpp>
#include <Utility/Init.hpp>
#include <Utility/NoiseBool.hpp>
#include <Utility/NoiseShoreBool.hpp>
#include <Utility/Replace.hpp>
#include <Utility/SetItem.hpp>
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY


///// エンティティ /////

#include <Entity/MobManager.hpp>


///// 修正 /////

#include <Retouch/BuryPoint.hpp>
#include <Retouch/RemovePoint.hpp>


///// 乱数 /////

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM
//乱数生成
#include <Random/MersenneTwister32bit.hpp>
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM


///// 標準生成 /////

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_COMMON
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_COMMON
//指定マスの周囲1マスに任意の値(1)を設置する。
#include <Shape/Border.hpp>
//Shape_Border + また、指定マスの列数が偶数の時[列数-2列目]を設置し、行数が偶数の時[行数-2行目]のマスに任意の値(1)を設置する(※行/列は0から数える)。
#include <Shape/BorderOdd.hpp>
//
#include <Shape/CellularAutomatonIsland.hpp>
//
#include <Shape/MixRect.hpp>
//指定マスの全てに任意の値(1)を設置する。
#include <Shape/Rect.hpp>
//[削除予定]
#include <Shape/OneLine.hpp>
//指定マスの偶数列目かつ偶数行目に任意の値(1)を設置する。
#include <Shape/PointGrid.hpp>
//Shape_BorderOdd + Shape_PointGrid
#include <Shape/PointGridWithBorder.hpp>
//Shape_BorderOdd + Shape_PointGrid + Shape_RandomRect
#include <Shape/PointGridAndSomeBlocksWithBorder.hpp>
//指定マスに一定の確率で任意の値(1)を設置する。
#include <Shape/RandomRect.hpp>

#include <Shape/MazeDig.hpp>

#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_COMMON

//
#include <Shape/CellularAutomatonMixIsland.hpp>

#include <DiamondSquareAverage.hpp>
//


//
#include <Shape/Point.hpp>

#include <Camera/MatrixView.hpp>

#endif //Included Dungeon Template Library