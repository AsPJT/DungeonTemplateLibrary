/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY


#include "Base_Struct.hpp"

///// β版テストライブラリ /////

/*機能が不十分な関数やクラスを扱う。
(特に "STL, Normal, Array, LayerSTL, LayerNormal"の中の一部の出力機能が欠けている場合が多い)*/

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BETA
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BETA

///// 関連ツール /////

#include "Beta_DungeonBinarization.hpp"
#include "Beta_DungeonNoise.hpp"
#include "Beta_DungeonOutput.hpp"
#include "Beta_DungeonRandom.hpp"
#include "Beta_DungeonFile.hpp"
#include "Beta_DungeonMatrix.hpp"

///// ダンジョン /////

#include "Beta_FractalIsland.hpp"
#include "Beta_MazeDig.hpp"
#include "Beta_RogueLike.hpp"
#include "Beta_SimpleRogueLike.hpp"
#include "Beta_SimpleVoronoiIsland.hpp"
#include "Beta_BoardGame.hpp"
#include "Beta_HorizontalScroll.hpp"
//ペイント
#include "Beta_DungeonPaint.hpp"
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BETA


///// コンソール出力 /////

/* 完全0.4.X対応 */

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE
//指定マスの値を数値で出力する。
#include "Console_OutputNumber.hpp"
//指定マスの値を指定した文字で出力する。
#include "Console_OutputString.hpp"
//指定マスの値(2値)を指定した文字で出力する。
#include "Console_OutputStringBool.hpp"
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE


///// 便利な機能 /////

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY
#include "Utility_Binarization.hpp"
#include "Utility_Binarization_Over.hpp"
#include "Utility_Copy.hpp"
#include "Utility_Init.hpp"
#include "Utility_NoiseBool.hpp"
#include "Utility_NoiseShoreBool.hpp"
#include "Utility_Replace.hpp"
#include "Utility_SetItem.hpp"
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY


///// エンティティ /////

#include "Entity_MobManager.hpp"


///// 修正 /////

#include "Retouch_RemovePoint.hpp"


///// 乱数 /////

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM
//乱数生成
#include "Random_MersenneTwister32bit.hpp"
#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_RANDOM


///// 標準生成 /////

//#define NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_COMMON
#ifndef NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_COMMON
//指定マスの周囲1マスに任意の値(1)を設置する。
#include "Shape_Border.hpp"
//Shape_Border + また、指定マスの列数が偶数の時[列数-2列目]を設置し、行数が偶数の時[行数-2行目]のマスに任意の値(1)を設置する(※行/列は0から数える)。
#include "Shape_BorderOdd.hpp"
//
#include "Shape_CellularAutomatonIsland.hpp"
//
#include "Shape_MixRect.hpp"
//指定マスの全てに任意の値(1)を設置する。
#include "Shape_Rect.hpp"
//[削除予定]
#include "Shape_OneLine.hpp"
//指定マスの偶数列目かつ偶数行目に任意の値(1)を設置する。
#include "Shape_PointGrid.hpp"
//Shape_BorderOdd + Shape_PointGrid
#include "Shape_PointGridWithBorder.hpp"
//Shape_BorderOdd + Shape_PointGrid + Shape_RandomRect
#include "Shape_PointGridAndSomeBlocksWithBorder.hpp"
//指定マスに一定の確率で任意の値(1)を設置する。
#include "Shape_RandomRect.hpp"

#endif //NOT_INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_COMMON

//
#include "Generator_Terrain_SimpleBiomeIsland.hpp"
//


//
#include "Shape_Point.hpp"

#include "Camera_MatrixView.hpp"

#endif //Included Dungeon Template Library