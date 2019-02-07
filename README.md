<p align="center">
    <br>
    <img src="https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Logo/logo_color640.gif" alt="Search Library" width="640px">
    <br><br>
  <a href="http://creativecommons.org/publicdomain/zero/1.0/deed.ja"><img src="https://img.shields.io/badge/license-CC0-blue.svg"></a> <a href="https://github.com/Kasugaccho/AsLib"><img src="https://img.shields.io/badge/build-passing-brightgreen.svg"></a>
<a href="https://join.slack.com/t/dungeon-generation/shared_invite/enQtNTM4MzQwMDU5MTIyLWEwNjAwMTQyZjk4MDQyNDU0Y2NlMTU2OTE5YTcwOTM5MzJmZWJlMWY3ZWRkZWU4ZDY1MjJlNDU4M2Y4ZDZmOWI"><img src="https://img.shields.io/badge/slack-online-red.svg"></a>
 <br><br>
 DTL (Dungeon Template Library)
</p>





[>> Japanese](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/%5Bja%5D-Home)

# [Download](https://github.com/Kasugaccho/DungeonTemplateLibrary/releases)

### [>> Download](https://github.com/Kasugaccho/DungeonTemplateLibrary/releases)
### [>> Web Trial (Wandbox)](https://wandbox.org/permlink/gUpHgebVyqi7D3F4)

# Overview

### [>> SampleCode](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/SampleCode)

## Matrix Type

### Main Code

```cpp
using dungeon_t = std::uint_fast8_t;
constexpr std::size_t x_size{ 12 };
constexpr std::size_t y_size{ 8 };
```

### STL Matrix ![stl_matrix](https://img.shields.io/badge/STL-passing-brightgreen.svg)

![no_default_array](https://img.shields.io/badge/default%20array-nothing-lightgrey.svg) ![std_array](https://img.shields.io/badge/std%3A%3Aarray-passing-brightgreen.svg) ![std_bitset](https://img.shields.io/badge/std%3A%3Abitset-passing-brightgreen.svg) ![std_vector](https://img.shields.io/badge/std%3A%3Avector-passing-brightgreen.svg) ![std_deque](https://img.shields.io/badge/std%3A%3Adeque-passing-brightgreen.svg) ![no_std_unique__ptr](https://img.shields.io/badge/std%3A%3Aunique__ptr-nothing-lightgrey.svg)

|Required Class Function:|operator[]|size|
|:---|:---|:---|

```cpp
std::array<std::array<dungeon_t, x_size>, y_size> dungeon_stl_matrix{ {} };
```

### Normal Matrix ![default_matrix](https://img.shields.io/badge/Default-passing-brightgreen.svg)

![default_array](https://img.shields.io/badge/default%20array-passing-brightgreen.svg) ![std_array](https://img.shields.io/badge/std%3A%3Aarray-passing-brightgreen.svg) ![std_bitset](https://img.shields.io/badge/std%3A%3Abitset-passing-brightgreen.svg) ![std_vector](https://img.shields.io/badge/std%3A%3Avector-passing-brightgreen.svg) ![std_deque](https://img.shields.io/badge/std%3A%3Adeque-passing-brightgreen.svg) ![std_unique__ptr](https://img.shields.io/badge/std%3A%3Aunique__ptr-passing-brightgreen.svg)

|Required Class Function:|operator[]|
|:---|:---|

```cpp
dungeon_t dungeon_default_matrix[y_size][x_size]{};
```

### Array Matrix ![array_matrix](https://img.shields.io/badge/Array-passing-brightgreen.svg)

![default_array](https://img.shields.io/badge/default%20array-passing-brightgreen.svg) ![std_array](https://img.shields.io/badge/std%3A%3Aarray-passing-brightgreen.svg) ![std_bitset](https://img.shields.io/badge/std%3A%3Abitset-passing-brightgreen.svg) ![std_vector](https://img.shields.io/badge/std%3A%3Avector-passing-brightgreen.svg) ![std_deque](https://img.shields.io/badge/std%3A%3Adeque-passing-brightgreen.svg) ![std_unique__ptr](https://img.shields.io/badge/std%3A%3Aunique__ptr-passing-brightgreen.svg)

|Required Class Function:|operator[]|
|:---|:---|

```cpp
dungeon_t dungeon_array_matrix[x_size*y_size]{};
```

## 👾Test👾

[Wandbox(1-4)](https://wandbox.org/permlink/VDWP5m3EZQeB3zVT)

## Version 0.1.30 [ C++14 ]

|View|Test Code|
|:---|:---|
|PC View|[Wandbox](https://wandbox.org/permlink/VC13TPmxcO49LRBD)|
|SP View|[WandBox](https://wandbox.org/permlink/D3LFLXm4gum8Rg7N)|

|Compiler|[Pass_C++14](https://github.com/Kasugaccho/DungeonTemplateLibrary/tree/master/include/cpp14)|[Pass_C99](https://github.com/Kasugaccho/DungeonTemplateLibrary/tree/master/include/c99)|
|:---|:---|:---|
|MSVC|![cl](https://img.shields.io/badge/cl%2014.10-passing-brightgreen.svg)|![cl](https://img.shields.io/badge/cl%2014.10-passing-brightgreen.svg)|
|GCC|![gcc](https://img.shields.io/badge/gcc%205.1.0-passing-brightgreen.svg)|![gcc](https://img.shields.io/badge/gcc%204.4.7-passing-brightgreen.svg)|
|Clang|![clang](https://img.shields.io/badge/clang%203.8.1-passing-brightgreen.svg)|![clang](https://img.shields.io/badge/clang%203.1-passing-brightgreen.svg)|
|Zapcc|![zapcc](https://img.shields.io/badge/zapcc%201.0.1-passing-brightgreen.svg)|![zapcc](https://img.shields.io/badge/zapcc%201.0.1-unknown-lightgrey.svg)||
|ICC|![icc](https://img.shields.io/badge/icc-unknown-lightgrey.svg)|![icc](https://img.shields.io/badge/icc-unknown-lightgrey.svg)|

# [Type] Terrain Generation

## [1] Simple Voronoi Island (v0.1.0~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99](https://img.shields.io/badge/C99-passing-brightgreen.svg)

```cpp
#include <SimpleVoronoiIsland.hpp>
```

|Default Value|Name|Image Color|
|:---:|:---|:---|
|0|Sea|Pale Brown|
|1|Land|Dark Olive|

|Capacity Requirement|
|:---:|
|1 bit|

### Variable
![bool_true](https://img.shields.io/badge/Variable-bool-brightgreen.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Matrix Type
![stl_matrix](https://img.shields.io/badge/STL-passing-brightgreen.svg) ![no_default_matrix](https://img.shields.io/badge/Default-nothing-lightgrey.svg) ![no_array_matrix](https://img.shields.io/badge/Array-nothing-lightgrey.svg)

### Generation Type
[![gt_r](https://img.shields.io/badge/generation%20type-random-orange.svg)](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/Generation-Type)

### Image
![voronoi](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/svi.gif)

## [3] Fractal Island (v0.1.1~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99](https://img.shields.io/badge/C99-passing-brightgreen.svg)

```cpp
#include <FractalIsland.hpp>
```

|Default Value|Name|
|:---:|:---|
|0-255|Height|

|Capacity Requirement|
|:---:|
|8 bit|

### Variable
![bool_false](https://img.shields.io/badge/Variable-bool-red.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Matrix Type
![stl_matrix](https://img.shields.io/badge/STL-passing-brightgreen.svg) ![no_default_matrix](https://img.shields.io/badge/Default-nothing-lightgrey.svg) ![no_array_matrix](https://img.shields.io/badge/Array-nothing-lightgrey.svg)

### Generation Type
[![gt_r](https://img.shields.io/badge/generation%20type-random-orange.svg)](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/Generation-Type)

### Image
![FI1](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/FI_1.gif)
![3D](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/3D/fractal_island_3d_2.gif)
![fi3d](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/3D/fractal_island_3d.gif)

## [15] Chunk Island (v0.1.20~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <FractalIsland.hpp>
```

|Default Value|Name|
|:---:|:---|
|0-255|Height|

|Capacity Requirement|
|:---:|
|8 bit|

### Variable
![bool_false](https://img.shields.io/badge/Variable-bool-red.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Matrix Type
![stl_matrix](https://img.shields.io/badge/STL-passing-brightgreen.svg) ![no_default_matrix](https://img.shields.io/badge/Default-nothing-lightgrey.svg) ![no_array_matrix](https://img.shields.io/badge/Array-nothing-lightgrey.svg)

### Generation Type
[![gt_r](https://img.shields.io/badge/generation%20type-random-orange.svg)](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/Generation-Type)

### Image
![chunk](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/chunk_island.gif)

## [16] Simple Diamond Square Average Island (v0.1.21~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <FractalIsland.hpp>
```

|Default Value|Name|
|:---:|:---|
|0-255|Height|

|Capacity Requirement|
|:---:|
|8 bit|

### Variable
![bool_false](https://img.shields.io/badge/Variable-bool-red.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Matrix Type
![stl_matrix](https://img.shields.io/badge/STL-passing-brightgreen.svg) ![no_default_matrix](https://img.shields.io/badge/Default-nothing-lightgrey.svg) ![no_array_matrix](https://img.shields.io/badge/Array-nothing-lightgrey.svg)

### Generation Type
[![gt_r](https://img.shields.io/badge/generation%20type-random-orange.svg)](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/Generation-Type)

### Image
![sdsai](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/simple_diamond_square_average_island.gif)

## [14] Simple Diamond Square Average Island Corner (v0.1.19~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <FractalIsland.hpp>
```

|Default Value|Name|
|:---:|:---|
|0-255|Height|

|Capacity Requirement|
|:---:|
|8 bit|

### Variable
![bool_false](https://img.shields.io/badge/Variable-bool-red.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Matrix Type
![stl_matrix](https://img.shields.io/badge/STL-passing-brightgreen.svg) ![no_default_matrix](https://img.shields.io/badge/Default-nothing-lightgrey.svg) ![no_array_matrix](https://img.shields.io/badge/Array-nothing-lightgrey.svg)

### Generation Type
[![gt_r](https://img.shields.io/badge/generation%20type-random-orange.svg)](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/Generation-Type)

### Image
![sdsai](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/simple_diamond_square_average_island_corner.gif)

# [Type] Dungeon Generation

## [2] RogueLike (v0.1.0~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <RogueLike.hpp>
```

|Default Value|Name|Image Color|
|:---:|:---|:---|
|0|Outside Wall|Blue|
|1|Inside Wall|White|
|2|Room|Green|
|3|Entrance|Black|
|4|Way|Yellow|

|Capacity Requirement|
|:---:|
|3 bit|

### Variable
![bool_false](https://img.shields.io/badge/Variable-bool-red.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Matrix Type
![stl_matrix](https://img.shields.io/badge/STL-passing-brightgreen.svg) ![no_default_matrix](https://img.shields.io/badge/Default-nothing-lightgrey.svg) ![no_array_matrix](https://img.shields.io/badge/Array-nothing-lightgrey.svg)

### Generation Type
[![gt_r](https://img.shields.io/badge/generation%20type-random-orange.svg)](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/Generation-Type)

### Image
![rl1](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/rl1.gif)
![rl4](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/rl2.gif)

## [5] Simple RogueLike (v0.1.3~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99](https://img.shields.io/badge/C99-passing-brightgreen.svg)

```cpp
#include <SimpleRogueLike.hpp>
```

|Default Value|Name|Image Color|
|:---:|:---|:---|
|0|Wall|Black|
|1|Empty|White|

|Capacity Requirement|
|:---:|
|1 bit|

### Variable
![bool_true](https://img.shields.io/badge/Variable-bool-brightgreen.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Matrix Type
![stl_matrix](https://img.shields.io/badge/STL-passing-brightgreen.svg) ![no_default_matrix](https://img.shields.io/badge/Default-nothing-lightgrey.svg) ![no_array_matrix](https://img.shields.io/badge/Array-nothing-lightgrey.svg)

### Generation Type
[![gt_r](https://img.shields.io/badge/generation%20type-random-orange.svg)](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/Generation-Type)

### Image
![STL1](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/SRL_1.gif)
![srl3d](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/3D/simple_roguelike.gif)

## [4] Maze Dig (v0.1.2~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99](https://img.shields.io/badge/C99-passing-brightgreen.svg)

```cpp
#include <MazeDig.hpp>
```

|Default Value|Name|Image Color|
|:---:|:---|:---|
|0|Wall|Blue|
|1|Empty|White|

|Capacity Requirement|
|:---:|
|1 bit|

### Variable
![bool_true](https://img.shields.io/badge/Variable-bool-brightgreen.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Matrix Type
![stl_matrix](https://img.shields.io/badge/STL-passing-brightgreen.svg) ![no_default_matrix](https://img.shields.io/badge/Default-nothing-lightgrey.svg) ![no_array_matrix](https://img.shields.io/badge/Array-nothing-lightgrey.svg)

### Generation Type
[![gt_r](https://img.shields.io/badge/generation%20type-random-orange.svg)](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/Generation-Type)

### Image
![maze_dig](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/MD_1.gif)
![maze_dig_3d](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/3D/maze_dig.gif)

## [17] RogueLike Cave (v0.1.25~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <RogueLike.hpp>
```

|Default Value|Name|Image Color|
|:---:|:---|:---|
|0|Wall|Black|
|1|Room|Brown|
|2|Unknown||
|3|Unknown||
|4|Unknown||

|Capacity Requirement|
|:---:|
|3 bit|

### Variable
![bool_false](https://img.shields.io/badge/Variable-bool-red.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Matrix Type
![stl_matrix](https://img.shields.io/badge/STL-passing-brightgreen.svg) ![no_default_matrix](https://img.shields.io/badge/Default-nothing-lightgrey.svg) ![no_array_matrix](https://img.shields.io/badge/Array-nothing-lightgrey.svg)

### Generation Type
[![gt_r](https://img.shields.io/badge/generation%20type-random-orange.svg)](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/Generation-Type)

### Image
![rl1](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/rogue_like_cave.gif)
![rlc](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/3D/roguelike_cave.gif)

## Maze α
![cpp14](https://img.shields.io/badge/C%2B%2B14-developing-orange.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

Underdevelopment...

# [Type] Common Generation

## [6] DungeonInit (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <DungeonStandard.hpp>
```

```cpp
//class
dtl::DungeonInit<dungeon_t> dungeon_init(dungeon);

//function
dtl::dungeonInit(dungeon);
```
|Matrix Size Min|Matrix Size Max|
|:---:|:---|
|0|(Variable Max)|

|Default Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|Black|

|Capacity Requirement|
|:---:|
|1 bit|

### Variable
![bool_true](https://img.shields.io/badge/Variable-bool-brightgreen.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Matrix Type
![stl_matrix](https://img.shields.io/badge/STL-passing-brightgreen.svg) ![default_matrix](https://img.shields.io/badge/Default-passing-brightgreen.svg) ![array_matrix](https://img.shields.io/badge/Array-passing-brightgreen.svg)

### Generation Type
[![gt_f](https://img.shields.io/badge/generation%20type-fixed-lightgrey.svg)](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/Generation-Type)

### Image
![di](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/dungeon_init.png)

## [7] Border (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <DungeonStandard.hpp>
```

```cpp
//class
dtl::Border<dungeon_t> border(dungeon);

//function
dtl::createBorder(dungeon);
```

|Matrix Size Min|Matrix Size Max|
|:---:|:---|
|1|(Variable Max)|

|Default Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|White|
|1|Wall|Black|

|Capacity Requirement|
|:---:|
|1 bit|

### Variable
![bool_true](https://img.shields.io/badge/Variable-bool-brightgreen.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Generation Type
[![gt_f](https://img.shields.io/badge/generation%20type-fixed-lightgrey.svg)](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/Generation-Type)

### Image
![db](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/dungeon_border.png)
![border](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/3D/border.gif)

### Matrix Type
![stl_matrix](https://img.shields.io/badge/STL-passing-brightgreen.svg) ![default_matrix](https://img.shields.io/badge/Default-passing-brightgreen.svg) ![array_matrix](https://img.shields.io/badge/Array-passing-brightgreen.svg)

## [8] BorderOdd (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <DungeonStandard.hpp>
```

```cpp
//class
dtl::BorderOdd<dungeon_t> border_odd(dungeon);

//function
dtl::createBorderOdd(dungeon);
```

|Matrix Size Min|Matrix Size Max|
|:---:|:---|
|2|(Variable Max)|

|Default Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|White|
|1|Wall|Black|

|Capacity Requirement|
|:---:|
|1 bit|

### Variable
![bool_true](https://img.shields.io/badge/Variable-bool-brightgreen.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Matrix Type
![stl_matrix](https://img.shields.io/badge/STL-passing-brightgreen.svg) ![default_matrix](https://img.shields.io/badge/Default-passing-brightgreen.svg) ![array_matrix](https://img.shields.io/badge/Array-passing-brightgreen.svg)

### Generation Type
[![gt_f](https://img.shields.io/badge/generation%20type-fixed-lightgrey.svg)](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/Generation-Type)

### Image
![bo](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/dungeon_border_odd.png)


## [9] PointGrid (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <DungeonStandard.hpp>
```

```cpp
//class
dtl::PointGrid<dungeon_t> point_grid(dungeon);

//function
dtl::createPointGrid(dungeon);
```

|Matrix Size Min|Matrix Size Max|
|:---:|:---|
|0|(Variable Max)|

|Default Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|White|
|1|Wall|Black|

|Capacity Requirement|
|:---:|
|1 bit|

### Variable
![bool_true](https://img.shields.io/badge/Variable-bool-brightgreen.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Matrix Type
![stl_matrix](https://img.shields.io/badge/STL-passing-brightgreen.svg) ![default_matrix](https://img.shields.io/badge/Default-passing-brightgreen.svg) ![array_matrix](https://img.shields.io/badge/Array-passing-brightgreen.svg)

### Generation Type
[![gt_f](https://img.shields.io/badge/generation%20type-fixed-lightgrey.svg)](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/Generation-Type)

### Image
![pg](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/point_grid.png)

## [10] PointGridField (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <DungeonStandard.hpp>
```

```cpp
//class
dtl::PointGridField<dungeon_t> point_grid_field(dungeon);

//function
dtl::createPointGridField(dungeon);
```

|Matrix Size Min|Matrix Size Max|
|:---:|:---|
|2|(Variable Max)|

|Default Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|White|
|1|Wall|Black|

|Capacity Requirement|
|:---:|
|1 bit|

### Variable
![bool_true](https://img.shields.io/badge/Variable-bool-brightgreen.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Matrix Type
![stl_matrix](https://img.shields.io/badge/STL-passing-brightgreen.svg) ![default_matrix](https://img.shields.io/badge/Default-passing-brightgreen.svg) ![array_matrix](https://img.shields.io/badge/Array-passing-brightgreen.svg)

### Generation Type
[![gt_f](https://img.shields.io/badge/generation%20type-fixed-lightgrey.svg)](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/Generation-Type)

### Image
![pgf](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/point_grid_field.png)

## [12] PointGridFieldPutBlock (v0.1.13~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <DungeonStandard.hpp>
```

```cpp
//class
dtl::PointGridFieldPutBlock<dungeon_t> point_grid_field_put_block(dungeon);
```

|Matrix Size Min|Matrix Size Max|
|:---:|:---|
|3|(Variable Max)|

|Default Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|White|
|1|Wall|Black|
|2|Block|Red|

|Capacity Requirement|
|:---:|
|2 bit|

### Variable
![bool_false](https://img.shields.io/badge/Variable-bool-red.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Matrix Type
![stl_matrix](https://img.shields.io/badge/STL-passing-brightgreen.svg) ![default_matrix](https://img.shields.io/badge/Default-passing-brightgreen.svg) ![array_matrix](https://img.shields.io/badge/Array-passing-brightgreen.svg)

### Generation Type
[![gt_r](https://img.shields.io/badge/generation%20type-random-orange.svg)](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/Generation-Type)

### Image
![pgfpb](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/point_grid_field_put_block.gif)

# [Type] BoardGame Generation

## [11] Reversi (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <BoardGame.hpp>
```

```cpp
//class
dtl::Reversi<dungeon_t> reversi(dungeon);
```

|Matrix Size Min|Matrix Size Max|
|:---:|:---|
|2|(Variable Max)|

|Default Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|Green|
|1|White|White|
|2|Black|Black|

|Capacity Requirement|
|:---:|
|2 bit|

### Variable
![bool_false](https://img.shields.io/badge/Variable-bool-red.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Matrix Type
![stl_matrix](https://img.shields.io/badge/STL-passing-brightgreen.svg) ![no_default_matrix](https://img.shields.io/badge/Default-nothing-lightgrey.svg) ![no_array_matrix](https://img.shields.io/badge/Array-nothing-lightgrey.svg)

### Generation Type
[![gt_f](https://img.shields.io/badge/generation%20type-fixed-lightgrey.svg)](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/Generation-Type)

### Image
![re](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/reversi.png)

![re32](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/reversi_32.gif)

## [13] Chess (v0.1.14~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <BoardGame.hpp>
```

```cpp
//class
dtl::Chess<dungeon_t> chess(dungeon);
```

|Matrix Size Min|Matrix Size Max|
|:---:|:---|
|4|(Variable Max)|

|Default Value|Name|
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

|Capacity Requirement|
|:---:|
|4 bit|

### Variable
![bool_false](https://img.shields.io/badge/Variable-bool-red.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Matrix Type
![stl_matrix](https://img.shields.io/badge/STL-passing-brightgreen.svg) ![no_default_matrix](https://img.shields.io/badge/Default-nothing-lightgrey.svg) ![no_array_matrix](https://img.shields.io/badge/Array-nothing-lightgrey.svg)

### Generation Type
[![gt_f](https://img.shields.io/badge/generation%20type-fixed-lightgrey.svg)](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/Generation-Type)

### Image
![chess](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/fixed/chess.png)

### Variable
![bool_false](https://img.shields.io/badge/Variable-bool-red.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

# [Type] Horizontal Scroll Generation

## [18] Mountain (v0.1.26~)

```cpp
#include <HorizontalScroll.hpp>
```

|Default Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|Blue|
|1|Mountain|Green|

|Capacity Requirement|
|:---:|
|1 bit|

### Variable
![bool_true](https://img.shields.io/badge/Variable-bool-brightgreen.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Matrix Type
![stl_matrix](https://img.shields.io/badge/STL-passing-brightgreen.svg) ![no_default_matrix](https://img.shields.io/badge/Default-nothing-lightgrey.svg) ![no_array_matrix](https://img.shields.io/badge/Array-nothing-lightgrey.svg)

### Generation Type
[![gt_r](https://img.shields.io/badge/generation%20type-random-orange.svg)](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/Generation-Type)

### Image

![mountain](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/2D/random/mountain.gif)

# Paint Tool

## Pen (v0.1.9~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <DungeonPaint.hpp>
```

```cpp
dtl::Pen<dungeon_t> pen(dungeon, x, y, paint_value);
```

### Variable
![bool_true](https://img.shields.io/badge/Variable-bool-brightgreen.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Matrix Type
![stl_matrix](https://img.shields.io/badge/STL-passing-brightgreen.svg) ![default_matrix](https://img.shields.io/badge/Default-passing-brightgreen.svg) ![no_array_matrix](https://img.shields.io/badge/Array-nothing-lightgrey.svg)

### Image
![pen](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/Paint/pen.gif)

## Bucket (v0.1.9~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <DungeonPaint.hpp>
```

```cpp
dtl::Bucket<dungeon_t> bucket(dungeon, x, y, paint_value);
```

### Variable
![bool_true](https://img.shields.io/badge/Variable-bool-brightgreen.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Matrix Type
![stl_matrix](https://img.shields.io/badge/STL-passing-brightgreen.svg) ![no_default_matrix](https://img.shields.io/badge/Default-nothing-lightgrey.svg) ![no_array_matrix](https://img.shields.io/badge/Array-nothing-lightgrey.svg)

### Image
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

These codes are licensed under CC0.

[![CC0](https://mirrors.creativecommons.org/presskit/buttons/88x31/svg/cc-zero.svg "CC0")](http://creativecommons.org/publicdomain/zero/1.0/deed.ja)

Created by Gaccho on December 15th, 2018.

## Contact

|E-mail:|wanotaitei@gmail.com|
|:---|:---|
|Twitter:|[@wanotaitei](https://twitter.com/wanotaitei)|
|![svg](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/as_logo.svg)|**As Project**|
|![gaccho](https://github.com/Kasugaccho/DungeonPicture/blob/master/Picture/gaccho_icon.svg)|Made by Gaccho.|

Japan Terrain Generation Research Institute

