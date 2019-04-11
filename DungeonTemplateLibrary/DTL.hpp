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




///// ///// ///// 非推奨ライブラリ ///// ///// /////

/*機能が古くなった関数やクラスを扱う。
(特に "STL, Normal, Array, LayerSTL, LayerNormal"の中の一部の出力機能が欠けている場合が多い)*/

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DEPRECATED
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DEPRECATED

#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DEPRECATED
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DEPRECATED

///// 関連ツール /////

#include <Deprecated/DungeonBinarization.hpp>

#include <Deprecated/DungeonNoise.hpp>

#include <Deprecated/DungeonOutput.hpp>

#include <Deprecated/DungeonRandom.hpp>

#include <Deprecated/DungeonFile.hpp>

#include <Deprecated/DungeonMatrix.hpp>


///// ダンジョン /////

#include <Deprecated/FractalIsland.hpp>

#include <Deprecated/MazeDig.hpp>

#include <Deprecated/RogueLike.hpp>

#include <Deprecated/SimpleRogueLike.hpp>

#include <Deprecated/SimpleVoronoiIsland.hpp>

#include <Deprecated/BoardGame.hpp>

#include <Deprecated/HorizontalScroll.hpp>
//ペイント
#include <Deprecated/DungeonPaint.hpp>

#endif //INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DEPRECATED
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DEPRECATED

#include <Storage/FileCSV.hpp>

#include <Storage/FileTerrainOBJ.hpp>




///// ///// ///// コンソール出力 ///// ///// /////

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE

#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE

//指定マスの値を数値で出力する。
#include <Console/OutputNumber.hpp>
//指定マスの値を指定した文字で出力する。
#include <Console/OutputString.hpp>
//指定マスの値(2値)を指定した文字で出力する。
#include <Console/OutputStringBool.hpp>

#endif //INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE




///// ///// ///// 便利な機能 ///// ///// /////

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY

#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY

#include <Utility/Binarization.hpp>

#include <Utility/Binarization_Over.hpp>

#include <Utility/Copy.hpp>

#include <Utility/Init.hpp>

#include <Utility/NoiseBool.hpp>

#include <Utility/NoiseShoreBool.hpp>

#include <Utility/Replace.hpp>

#include <Utility/SetItem.hpp>

#endif //INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY




///// ///// ///// エンティティ ///// ///// /////

#include <Entity/MobManager.hpp>




///// ///// ///// 修正 ///// ///// /////

#include <Retouch/BuryPoint.hpp>

#include <Retouch/RemovePoint.hpp>




///// ///// ///// 乱数 ///// ///// /////

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM

#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM

//乱数生成
#include <Random/MersenneTwister32bit.hpp>

#endif //INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM




///// ///// ///// 標準生成 ///// ///// /////

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE

#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE

/* https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/std::shape::Border-(%E5%BD%A2%E7%8A%B6%E3%82%AF%E3%83%A9%E3%82%B9)/ */
#include <Shape/Border.hpp>
//Shape_Border + また、指定マスの列数が偶数の時[列数-2列目]を設置し、行数が偶数の時[行数-2行目]のマスに任意の値(1)を設置する(※行/列は0から数える)。
#include <Shape/BorderOdd.hpp>
//
#include <Shape/CellularAutomatonIsland.hpp>
//
#include <Shape/CellularAutomatonMixIsland.hpp>
//
#include <Shape/DiamondSquareAverage.hpp>
//
#include <Shape/MazeDig.hpp>
//
#include <Shape/MixRect.hpp>
//指定マスの全てに任意の値(1)を設置する。
#include <Shape/Rect.hpp>
//[削除予定]
#include <Shape/OneLine.hpp>
//
#include <Shape/Point.hpp>
//指定マスの偶数列目かつ偶数行目に任意の値(1)を設置する。
#include <Shape/PointGrid.hpp>
//Shape_BorderOdd + Shape_PointGrid
#include <Shape/PointGridWithBorder.hpp>
//Shape_BorderOdd + Shape_PointGrid + Shape_RandomRect
#include <Shape/PointGridAndSomeBlocksWithBorder.hpp>
//指定マスに一定の確率で任意の値(1)を設置する。
#include <Shape/RandomRect.hpp>

#endif //INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE



#include <Camera/MatrixView.hpp>

#endif //Included Dungeon Template Library