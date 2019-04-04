<p align="center">
    <br>
    <img src="https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Logo/logo_color640.gif" alt="Search Library" width="640px">
    <br><br>
  <a href="http://creativecommons.org/publicdomain/zero/1.0/deed.ja"><img src="https://img.shields.io/badge/license-BSL--1.0-blue.svg"></a> <a href="https://github.com/Kasugaccho/AsLib"><img src="https://img.shields.io/badge/build-passing-brightgreen.svg"></a>
<a href="https://join.slack.com/t/dungeon-generation/shared_invite/enQtNTM4MzQwMDU5MTIyLWEwNjAwMTQyZjk4MDQyNDU0Y2NlMTU2OTE5YTcwOTM5MzJmZWJlMWY3ZWRkZWU4ZDY1MjJlNDU4M2Y4ZDZmOWI"><img src="https://img.shields.io/badge/slack-online-red.svg"></a>
 <br><br>
 DTL (Dungeon Template Library)
</p>





[>> Japanese(日本語ページはこちら)](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/%E3%83%9B%E3%83%BC%E3%83%A0)

# [Download](https://github.com/Kasugaccho/DungeonTemplateLibrary/releases)

### [>> Download](https://github.com/Kasugaccho/DungeonTemplateLibrary/releases)
### [>> Web Trial (Wandbox)](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/Web-Trial)

# Overview

### [>> SampleCode](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/SampleCode)

## Version 0.3.0 [ C++17 ]

|Compiler|[C++17 (v0.3.0~)](https://github.com/Kasugaccho/DungeonTemplateLibrary/tree/master/include/cpp17)|[C++14 (~v0.2.4)](https://github.com/Kasugaccho/DungeonTemplateLibrary/tree/master/include/cpp14)|[C99](https://github.com/Kasugaccho/DungeonTemplateLibrary/tree/master/include/c99)|
|:---|:---|:---|:---|
|MSVC|14.10-passing|14.10-passing|14.10-passing|
|GCC|unknown|5.1.0-passing|4.4.7-passing|
|Clang|5.0.0-passing|3.8.1-passing|3.1-passing|
|Zapcc|unknown|1.0.1-passing|unknown||
|ICC|unknown|unknown|unknown|

# [Type] Terrain Generation

## Simple Voronoi Island
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99](https://img.shields.io/badge/C99-passing-brightgreen.svg)

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Sea|Pale Brown|
|1|Land|Dark Olive|

![voronoi](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/svi.gif)

## [19] Simple Cellular Automaton Island (v0.2.1~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Sea|Pale Brown|
|1|Land|Dark Olive|

![ri](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/ri.gif)

## [19] Simple Biome Island (v0.2.2~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Sea|Blue|
|n|(Biome)|

![ri](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/rpgi.gif)
![ri](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/rpgi.png)

## [3] Fractal Island (v0.1.1~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99](https://img.shields.io/badge/C99-passing-brightgreen.svg)

|Sample Value|Name|
|:---:|:---|
|0-255|Height|

![FI1](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/FI_1.gif)
![fi3d](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/3D/fractal_island_3d.png)

## [15] Chunk Island (v0.1.20~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

|Sample Value|Name|
|:---:|:---|
|0-255|Height|

![chunk](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/chunk_island.gif)

## [16] Simple Diamond Square Average Island (v0.1.21~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

|Sample Value|Name|
|:---:|:---|
|0-255|Height|

![sdsai](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/simple_diamond_square_average_island.gif)

## [14] Simple Diamond Square Average Island Corner (v0.1.19~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

|Sample Value|Name|
|:---:|:---|
|0-255|Height|

![sdsai](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/simple_diamond_square_average_island_corner.gif)

# [Type] Dungeon Generation

## [2] RogueLike (v0.1.0~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Outside Wall|Blue|
|1|Inside Wall|White|
|2|Room|Green|
|3|Entrance|Black|
|4|Way|Yellow|

![rl1](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/rl1.gif)
![rl4](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/rl2.gif)
![](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/aroguelike.png)

## [5] Simple RogueLike (v0.1.3~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99](https://img.shields.io/badge/C99-passing-brightgreen.svg)

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Wall|Black|
|1|Empty|White|

![STL1](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/SRL_1.gif)
![srl3d](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/3D/simple_roguelike.png)

## [4] Maze Dig (v0.1.2~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99](https://img.shields.io/badge/C99-passing-brightgreen.svg)

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Wall|Blue|
|1|Empty|White|

![maze_dig](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/MD_1.gif)
![maze_dig_3d](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/3D/maze_dig.png)

## [17] RogueLike Cave (v0.1.25~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Wall|Black|
|1|Room|Brown|
|2|Unknown||
|3|Unknown||
|4|Unknown||

![rl1](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/rogue_like_cave.gif)
![rlc](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/3D/roguelike_cave.png)

# [Type] Common Generation

## [6] [DungeonInit](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/Rect) (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|Black|

![di](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/dungeon_init.png)

## [7] [Border](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/Border) (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|White|
|1|Wall|Black|

![db](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/dungeon_border.png)
![border](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/3D/border.png)

### Matrix Type
![stl_matrix](https://img.shields.io/badge/STL-passing-brightgreen.svg) ![default_matrix](https://img.shields.io/badge/Default-passing-brightgreen.svg) ![array_matrix](https://img.shields.io/badge/Array-passing-brightgreen.svg)

## [8] [BorderOdd](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/BorderOdd) (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|White|
|1|Wall|Black|

![bo](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/dungeon_border_odd.png)


## [9] [PointGrid](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/PointGrid) (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|White|
|1|Wall|Black|

![pg](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/point_grid.png)

## [10] PointGridField (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|White|
|1|Wall|Black|

![pgf](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/point_grid_field.png)

## [12] PointGridFieldPutBlock (v0.1.13~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|White|
|1|Wall|Black|
|2|Block|Red|

![pgfpb](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/point_grid_field_put_block.gif)

# [Type] BoardGame Generation

## [11] Reversi (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|Green|
|1|White|White|
|2|Black|Black|

![re](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/reversi.png)

![re32](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/reversi_32.gif)

## [13] Chess (v0.1.14~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

|Sample Value|Name|
|:---:|:---|
|0|Empty|
|1|White King|
|2|Black King|
|3|White Queen|
|4|Black Queen|
|5|White Bishop|
|6|Black Bishop|
|7|White Knight|
|8|Black Knight|
|9|White Rook|
|10|Black Rook|
|11|White Pawn|
|12|Black Pawn|

![chess](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/chess.png)

# [Type] Horizontal Scroll Generation

## [18] Mountain (v0.1.26~)

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|Blue|
|1|Mountain|Green|

![mountain](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/mountain.gif)

# Paint Tool

## Pen (v0.1.9~)

![pen](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Paint/pen.gif)

## Bucket (v0.1.9~)

![bucket](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Paint/bucket.gif)

# File

## File Read

|Name|Function|Version|
|:---:|:---|:---|
|.csv|fileRead_csv|v0.1.12~|
|.dtlm|fileRead_dtlm|v0.1.12~|

## File Write (Text)

|Name|Function|Version|
|:---:|:---|:---|
|.csv|fileWrite_csv|v0.1.12~|
|.dtlm|fileWrite_dtlm|v0.1.22~|
|.md|fileWrite_md|v0.1.24~|
|.txt|fileWrite_0_9|v0.1.24~|

## File Write (Picture)

|Name|Function|Version|
|:---:|:---|:---|
|.pbm|fileWrite_pbm|v0.1.22~|
|.svg|fileWrite_svg|v0.1.22~|
|.bmp|fileWrite_bmp|v0.1.23~|

# MapChip File

|Name|Version|
|:---:|:---|
|wolf_auto_tile|v0.2.3~|

## File Write (3D)

|Name|Function|Version|
|:---:|:---|:---|
|.obj|fileWriteTerrain_obj|v0.1.27~|
|.obj|fileWriteBoard_obj|v0.1.28~|

# Artificial Intelligence

## [Reversi AI (v0.1.11~)](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/Reversi-AI)

## Matrix

![matrix](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/matrix.svg)

## License

Copyright (c) 2017-2019 Kasugaccho.

Distributed under the Boost Software License, Version 1.0.

(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

## Contact

|E-mail:|wanotaitei@gmail.com|
|:---|:---|
|Twitter:|[@wanotaitei](https://twitter.com/wanotaitei)|
|![svg](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/as_logo.svg)|**As Project**|
|![gaccho](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/gaccho_icon.svg)|Made by Gaccho.|

Japan Terrain Generation Research Institute

