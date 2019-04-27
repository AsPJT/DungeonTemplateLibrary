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

## Version 0.4.4 [ C++14/17 ]

|Compiler|[C++17 (v0.3.0~)](https://github.com/Kasugaccho/DungeonTemplateLibrary/tree/master/include/cpp17)|[C++14 (~v0.2.4/v0.4.3.1\~)](https://github.com/Kasugaccho/DungeonTemplateLibrary/tree/master/include/cpp14)|[C99](https://github.com/Kasugaccho/DungeonTemplateLibrary/tree/master/include/c99)|
|:---|:---|:---|:---|
|MSVC|14.10-passing|14.10-passing|14.10-passing|
|GCC|unknown|5.1.0-passing|4.4.7-passing|
|Clang|5.0.0-passing|3.8.1-passing|3.1-passing|
|Zapcc|unknown|1.0.1-passing|unknown||
|ICC|unknown|unknown|unknown|

# [Type] Terrain Generation

## [CellularAutomatonMixIsland✅](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::CellularAutomatonMixIsland-(%E5%BD%A2%E7%8A%B6%E3%82%AF%E3%83%A9%E3%82%B9))

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Sea|Blue|
|n|(Biome)|

![ri](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Terrain/CAMI.gif)

## CellularAutomatonIsland✅

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Sea|Blue|
|1|Land|Green|

![ri](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Terrain/CAI.gif)

## FractalLoopIsland✅

|Sample Value|Name|
|:---:|:---|
|0-255|Height|

![FI1](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Terrain/FLI_NEW256.gif)
![fi3d](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/3D/fli.png)

## FractalIsland✅

|Sample Value|Name|
|:---:|:---|
|0-255|Height|

![chunk](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Terrain/FI2.gif)

## [DiamondSquareAverageIsland✅](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::DiamondSquareAverageIsland-(%E5%BD%A2%E7%8A%B6%E3%82%AF%E3%83%A9%E3%82%B9))

|Sample Value|Name|
|:---:|:---|
|0-255|Height|

![sdsai](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Terrain/DSAI256.gif)
![dsai](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/3D/diamond_sqare_ai.png)

## DiamondSquareAverageCornerIsland✅

|Sample Value|Name|
|:---:|:---|
|0-255|Height|

![sdsai](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Terrain/DSAIC.gif)

## SimpleVoronoiIsland

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Sea|Blue|
|1|Land|Green|

![voronoi](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Terrain/VIB.gif)

# [Type] Dungeon Generation

## RogueLike

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Outside Wall|Blue|
|1|Inside Wall|White|
|2|Room|Green|
|3|Entrance|Black|
|4|Way|Yellow|

![rl1](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/rls.gif)

## SimpleRogueLike✅

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Wall|Black|
|1|Empty|White|

![STL1](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/SRL_1.gif)
![srl3d](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/3D/simple_roguelike.png)

## MazeDig✅

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Wall|Blue|
|1|Empty|White|

![maze_dig](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/MD_1.gif)
![maze_dig_3d](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/3D/maze_dig.png)

## RogueLikeCave

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

## [Rect✅](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::Rect-(%E5%BD%A2%E7%8A%B6%E3%82%AF%E3%83%A9%E3%82%B9))

```cpp
dtl::shape::Rect<shape_t>(rect_value).draw(matrix, width, height);
```

|Value Name|Name|Image Color|
|:---:|:---|:---|
|rect_value|Rect|Black|

![di](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/dungeon_init.png)

## [Border✅](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::Border-(%E5%BD%A2%E7%8A%B6%E3%82%AF%E3%83%A9%E3%82%B9))

```cpp
dtl::shape::Border<shape_t>(border_value).draw(matrix, width, height);
```

|Value Name|Name|Image Color|
|:---:|:---|:---|
|default_value|Empty|White|
|border_value|Border|Black|

![db](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/dungeon_border.png)
![border](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/3D/border.png)

## [BorderOdd✅](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::BorderOdd-(%E5%BD%A2%E7%8A%B6%E3%82%AF%E3%83%A9%E3%82%B9))

```cpp
dtl::shape::BorderOdd<shape_t>(border_value).draw(matrix, width, height);
```

|Value Name|Name|Image Color|
|:---:|:---|:---|
|default_value|Empty|White|
|border_value|Border|Black|

![bo](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/dungeon_border_odd.png)

## [PointGrid✅](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::PointGrid-(%E5%BD%A2%E7%8A%B6%E3%82%AF%E3%83%A9%E3%82%B9))

```cpp
dtl::shape::PointGrid<shape_t>(point_grid_value).draw(matrix, width, height);
```

|Value Name|Name|Image Color|
|:---:|:---|:---|
|default_value|Empty|White|
|point_grid_value|PointGrid|Black|

![pg](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/point_grid.png)

## [PointGridWithBorder✅](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::PointGridWithBorder-(%E5%BD%A2%E7%8A%B6%E3%82%AF%E3%83%A9%E3%82%B9))

```cpp
dtl::shape::PointGridWithBorder<shape_t>(point_grid_value, border_value).draw(matrix, width, height);
```

|Value Name|Name|Image Color|
|:---:|:---|:---|
|default_value|Empty|White|
|point_grid_value|PointGrid|Black|
|border_value|Border|Black|

![pgf](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/point_grid_field.png)

## [PointGridAndSomeBlocksWithBorder✅](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::PointGridAndSomeBlocksWithBorder-(%E5%BD%A2%E7%8A%B6%E3%82%AF%E3%83%A9%E3%82%B9))

```cpp
dtl::shape::PointGridAndSomeBlocksWithBorder<shape_t>(point_grid_value, border_value, block_value).draw(matrix, width, height);
```

|Value Name|Name|Image Color|
|:---:|:---|:---|
|default_value|Empty|White|
|point_grid_value|PointGrid|Black|
|border_value|Border|Black|
|block_value|Block|Red|

![pgfpb](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/point_grid_field_put_block.gif)

## WhiteNoise✅

```cpp
dtl::shape::WhiteNoise<shape_t>(noise_value).draw(matrix, width, height);
```

|Value Name|Name|Image Color|
|:---:|:---|:---|
|default_value|Empty|White|
|noise_value|Noise|Black|

![wn](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Noise/wn256.gif)

# [Type] BoardGame Generation

## Reversi

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|Green|
|1|White|White|
|2|Black|Black|

![re](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/reversi.png)

![re32](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/reversi_32.gif)

## Chess

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

## Mountain

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|Blue|
|1|Mountain|Green|

![mountain](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/mountain.gif)

# Paint Tool

## Pen

![pen](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Paint/pen.gif)

## Bucket

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

