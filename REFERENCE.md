# API reference

## [Type] Terrain Generation

### [CellularAutomatonMixIsland✅](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::CellularAutomatonMixIsland-(%E5%BD%A2%E7%8A%B6%E3%82%AF%E3%83%A9%E3%82%B9))

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Sea|Blue|
|n|(Biome)|

![ri](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Terrain/CAMI.gif)

### CellularAutomatonIsland✅

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Sea|Blue|
|1|Land|Green|

![ri](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Terrain/CAI.gif)

### FractalLoopIsland✅

|Sample Value|Name|
|:---:|:---|
|0-255|Height|

![FI1](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Terrain/FLI_NEW256.gif)
![fi3d](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/3D/fli.png)

### FractalIsland✅

|Sample Value|Name|
|:---:|:---|
|0-255|Height|

![chunk](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Terrain/FI2.gif)

### [DiamondSquareAverageIsland✅](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::DiamondSquareAverageIsland-(%E5%BD%A2%E7%8A%B6%E3%82%AF%E3%83%A9%E3%82%B9))

|Sample Value|Name|
|:---:|:---|
|0-255|Height|

![sdsai](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Terrain/DSAI256.gif)
![dsai](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/3D/diamond_sqare_ai.png)

### DiamondSquareAverageCornerIsland✅

|Sample Value|Name|
|:---:|:---|
|0-255|Height|

![sdsai](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Terrain/DSAIC.gif)

### SimpleVoronoiIsland✅

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Sea|Blue|
|1|Land|Green|

![voronoi](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Terrain/VIB.gif)

## [Type] Dungeon Generation

### RogueLike

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Outside Wall|Blue|
|1|Inside Wall|White|
|2|Room|Green|
|3|Entrance|Black|
|4|Way|Yellow|

![rl1](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/rls.gif)

### SimpleRogueLike✅

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Wall|Black|
|1|Empty|White|

![STL1](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/SRL_1.gif)
![srl3d](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/3D/simple_roguelike.png)

### MazeDig✅

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Wall|Blue|
|1|Empty|White|

![maze_dig](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/MD_1.gif)
![maze_dig_3d](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/3D/maze_dig.png)

### RogueLikeCave

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Wall|Black|
|1|Room|Brown|
|2|Unknown||
|3|Unknown||
|4|Unknown||

![rl1](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/rogue_like_cave.gif)
![rlc](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/3D/roguelike_cave.png)

## [Type] Common Generation

### [Rect✅](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::Rect-(%E5%BD%A2%E7%8A%B6%E3%82%AF%E3%83%A9%E3%82%B9))

```cpp
dtl::shape::Rect<shape_t>(rect_value).draw(matrix, width, height);
```

|Value Name|Name|Image Color|
|:---:|:---|:---|
|rect_value|Rect|Black|

![di](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/dungeon_init.png)

### [Border✅](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::Border-(%E5%BD%A2%E7%8A%B6%E3%82%AF%E3%83%A9%E3%82%B9))

```cpp
dtl::shape::Border<shape_t>(border_value).draw(matrix, width, height);
```

|Value Name|Name|Image Color|
|:---:|:---|:---|
|default_value|Empty|White|
|border_value|Border|Black|

![db](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/dungeon_border.png)
![border](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/3D/border.png)

### [BorderOdd✅](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::BorderOdd-(%E5%BD%A2%E7%8A%B6%E3%82%AF%E3%83%A9%E3%82%B9))

```cpp
dtl::shape::BorderOdd<shape_t>(border_value).draw(matrix, width, height);
```

|Value Name|Name|Image Color|
|:---:|:---|:---|
|default_value|Empty|White|
|border_value|Border|Black|

![bo](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/dungeon_border_odd.png)

### [PointGrid✅](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::PointGrid-(%E5%BD%A2%E7%8A%B6%E3%82%AF%E3%83%A9%E3%82%B9))

```cpp
dtl::shape::PointGrid<shape_t>(point_grid_value).draw(matrix, width, height);
```

|Value Name|Name|Image Color|
|:---:|:---|:---|
|default_value|Empty|White|
|point_grid_value|PointGrid|Black|

![pg](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/point_grid.png)

### [PointGridWithBorder✅](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::PointGridWithBorder-(%E5%BD%A2%E7%8A%B6%E3%82%AF%E3%83%A9%E3%82%B9))

```cpp
dtl::shape::PointGridWithBorder<shape_t>(point_grid_value, border_value).draw(matrix, width, height);
```

|Value Name|Name|Image Color|
|:---:|:---|:---|
|default_value|Empty|White|
|point_grid_value|PointGrid|Black|
|border_value|Border|Black|

![pgf](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/point_grid_field.png)

### [PointGridAndSomeBlocksWithBorder✅](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::PointGridAndSomeBlocksWithBorder-(%E5%BD%A2%E7%8A%B6%E3%82%AF%E3%83%A9%E3%82%B9))

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

### WhiteNoise✅

```cpp
dtl::shape::WhiteNoise<shape_t>(noise_value).draw(matrix, width, height);
```

|Value Name|Name|Image Color|
|:---:|:---|:---|
|default_value|Empty|White|
|noise_value|Noise|Black|

![wn](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Noise/wn256.gif)

### RandomRect✅

```cpp
dtl::shape::RandomRect<shape_t>(noise_value, probability).draw(matrix, width, height);
```

|Value Name|Name|Image Color|
|:---:|:---|:---|
|default_value|Empty|White|
|noise_value|Noise|Black|

![rr](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Noise/rr256.gif)

### RandomVoronoi✅

```cpp
dtl::shape::RandomVoronoi<shape_t>(voronoi_num, probability, true_value, false_value).draw(matrix, width, height);
```

|Value Name|Name|Image Color|
|:---:|:---|:---|
|false_value|FALSE|White|
|true_value|TRUE|Black|

![rv](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Noise/rv256.gif)

## [Type] BoardGame Generation

### Reversi

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|Green|
|1|White|White|
|2|Black|Black|

![re](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/reversi.png)

![re32](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/reversi_32.gif)

### Chess

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

## [Type] Horizontal Scroll Generation

### Mountain

|Sample Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|Blue|
|1|Mountain|Green|

![mountain](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/mountain.gif)

## Paint Tool

### Pen

![pen](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Paint/pen.gif)

### Bucket

![bucket](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Paint/bucket.gif)

## File

### File Read

|Name|Function|Version|
|:---:|:---|:---|
|.csv|fileRead_csv|v0.1.12~|
|.dtlm|fileRead_dtlm|v0.1.12~|

### File Write (Text)

|Name|Function|Version|
|:---:|:---|:---|
|.csv|fileWrite_csv|v0.1.12~|
|.dtlm|fileWrite_dtlm|v0.1.22~|
|.md|fileWrite_md|v0.1.24~|
|.txt|fileWrite_0_9|v0.1.24~|

### File Write (Picture)

|Name|Function|Version|
|:---:|:---|:---|
|.pbm|fileWrite_pbm|v0.1.22~|
|.svg|fileWrite_svg|v0.1.22~|
|.bmp|fileWrite_bmp|v0.1.23~|

## MapChip File

|Name|Version|
|:---:|:---|
|wolf_auto_tile|v0.2.3~|

### File Write (3D)

|Name|Function|Version|
|:---:|:---|:---|
|.obj|fileWriteTerrain_obj|v0.1.27~|
|.obj|fileWriteBoard_obj|v0.1.28~|

## Artificial Intelligence

### [Reversi AI (v0.1.11~)](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/Reversi-AI)

### Matrix

![matrix](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/matrix.svg)
