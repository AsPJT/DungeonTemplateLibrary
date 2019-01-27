# Dungeon Template Library
 <a href="http://creativecommons.org/publicdomain/zero/1.0/deed.ja"><img src="https://img.shields.io/badge/license-CC0-blue.svg"></a> <a href="https://github.com/Kasugaccho/AsLib"><img src="https://img.shields.io/badge/0.1.0-passing-brightgreen.svg"></a>
 
[![DTL](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/logo.svg "DTL")](https://github.com/Kasugaccho/DungeonTemplateLibrary)

DTL (Dungeon Template Library)

[>> Japanese](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/%5Bja%5D-Home)

# [Download](https://github.com/Kasugaccho/DungeonTemplateLibrary/releases)

### [>> Download](https://github.com/Kasugaccho/DungeonTemplateLibrary/releases)

# Overview

### SampleCode

```cpp
#include <DTL.hpp>
#include <array>

int main() {

	using dungeon_t = std::uint_fast8_t;
	std::array<std::array<dungeon_t, 21>, 21> dungeon{ {} };

	dtl::PointGridField<dungeon_t> point_grid_field(dungeon);
	dtl::dungeonStringOutputBool(dungeon, "#", " ");

	return 0;
}
```

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

### Default Matrix ![default_matrix](https://img.shields.io/badge/Default-passing-brightgreen.svg)

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

## Version 0.1.20 [ C++14 ]

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

## 2. Simple Voronoi Island (v0.1.0~)
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

### Image
![voronoi](https://github.com/Kasugaccho/DTL_SimpleVoronoiIsland/blob/master/picture/voronoi.gif)

## 4. Fractal Island (v0.1.1~)
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

### Image
![FI1](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/FI_1.gif)

## 16. Chunk Island (v0.1.20~)
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

### Image
![chunk](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/chunk_island.gif)

## 17. Simple Diamond Square Average Island (v0.1.21~)
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

### Image
![sdsai](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/simple_diamond_square_average_island.gif)

## 15. Simple Diamond Square Average Island Corner (v0.1.19~)
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

### Image
![sdsai](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/simple_diamond_square_average_island_corner.gif)

# [Type] Dungeon Generation

## 3. RogueLike (v0.1.0~)
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

### Image
![rl1](https://github.com/Kasugaccho/DTL_RogueLike/blob/master/picture/rl.gif)
![rl4](https://github.com/Kasugaccho/DTL_RogueLike/blob/master/picture/rl4.gif)

## 6. Simple RogueLike (v0.1.3~)
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

### Image
![STL1](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/SRL_1.gif)

## 5. Maze Dig (v0.1.2~)
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

### Image
![maze_dig](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/MD_1.gif)

## 17. RogueLike Cave (v0.1.25~)
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

### Image
![rl1](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/rogue_like_cave.gif)

# [Type] Normal Generation

## 7. DungeonInit (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <DungeonStandard.hpp>
```

```cpp
dtl::DungeonInit<dungeon_t> dungeon_init(dungeon);
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

### Image
![di](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/dungeon_init.png)

## 8. Border (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <DungeonStandard.hpp>
```

```cpp
dtl::Border<dungeon_t> border(dungeon);
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

### Image
![db](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/dungeon_border.png)

### Matrix Type
![stl_matrix](https://img.shields.io/badge/STL-passing-brightgreen.svg) ![default_matrix](https://img.shields.io/badge/Default-passing-brightgreen.svg) ![array_matrix](https://img.shields.io/badge/Array-passing-brightgreen.svg)

## 9. BorderOdd (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <DungeonStandard.hpp>
```

```cpp
dtl::BorderOdd<dungeon_t> border_odd(dungeon);
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

### Image
![bo](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/dungeon_border_odd.png)


## 10. PointGrid (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <DungeonStandard.hpp>
```

```cpp
dtl::PointGrid<dungeon_t> point_grid(dungeon);
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

### Image
![pg](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/point_grid.png)

## 11. PointGridField (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <DungeonStandard.hpp>
```

```cpp
dtl::PointGridField<dungeon_t> point_grid_field(dungeon);
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

### Image
![pgf](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/point_grid_field.png)

## 13. PointGridFieldPutBlock (v0.1.13~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <DungeonStandard.hpp>
```

```cpp
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

### Image
![pgfpb](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/point_grid_field_put_block.gif)

# [Type] BoardGame Generation

## 12. Reversi (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <BoardGame.hpp>
```

```cpp
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

### Image
![re](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/reversi.png)

![re32](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/reversi_32.gif)

## 14. Chess (v0.1.14~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <BoardGame.hpp>
```

```cpp
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

### Image
![chess](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/chess.png)

## Maze α
![cpp14](https://img.shields.io/badge/C%2B%2B14-developing-orange.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

Underdevelopment...

### Variable
![bool_false](https://img.shields.io/badge/Variable-bool-red.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

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
![pen](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/Paint/pen.gif)

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
![bucket](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/Paint/bucket.gif)

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

# Artificial Intelligence

## Reversi AI (v0.1.11~)

###  🔱Winning percentage🔱

**Priority > Simple ≈ Greed > Unselfishness**

### reversiAI_Priority

|Winner|Priority|Priority|Empty|Count|
|:---|:---|:---|:---|:---|
|-0.0074|31.7925|31.9628|0.2447|60.1488|

|Winner|Priority|Simple|Empty|Count|
|:---|:---|:---|:---|:---|
|0.7835|40.8016|22.229|0.9694|59.9489|

|Winner|Priority|Greed|Empty|Count|
|:---|:---|:---|:---|:---|
|0.7053|39.5965|23.2626|1.1409|59.304|

|Winner|Priority|Unselfishness|Empty|Count|
|:---|:---|:---|:---|:---|
|0.7996|42.5181|20.7563|0.7256|60.0602|

### reversiAI_Simple

|Winner|Simple|Priority|Empty|Count|
|:---|:---|:---|:---|:---|
|-0.5458|22.6688|41.2262|0.105|60.913|

|Winner|Simple|Simple|Empty|Count|
|:---|:---|:---|:---|:---|
|-1|19|45|0|64|

|Winner|Simple|Greed|Empty|Count|
|:---|:---|:---|:---|:---|
|0.09|32.0689|29.3282|2.6029|60.1052|

|Winner|Simple|Unselfishness|Empty|Count|
|:---|:---|:---|:---|:---|
|0.4185|37.246|26.5962|0.1578|60.8609|

### reversiAI_Greed

|Winner|Greed|Priority|Empty|Count|
|:---|:---|:---|:---|:---|
|-0.7032|23.237|39.6584|1.1046|59.3413|

|Winner|Greed|Simple|Empty|Count|
|:---|:---|:---|:---|:---|
|-0.1217|30.7936|32.1165|1.0899|61.4612|

|Winner|Greed|Greed|Empty|Count|
|:---|:---|:---|:---|:---|
|-0.0097|31.7787|32.1442|0.0771|60.3203|

|Winner|Greed|Unselfishness|Empty|Count|
|:---|:---|:---|:---|:---|
|0.3536|35.073|24.5509|4.3761|57.4842|

### reversiAI_Unselfishness

|Winner|Unselfishness|Priority|Empty|Count|
|:---|:---|:---|:---|:---|
|-0.7935|20.9607|42.3865|0.6528|60.1339|

|Winner|Unselfishness|Simple|Empty|Count|
|:---|:---|:---|:---|:---|
|-0.4015|26.6318|37.2226|0.1456|60.9599|

|Winner|Unselfishness|Greed|Empty|Count|
|:---|:---|:---|:---|:---|
|-0.3935|23.6703|35.5719|4.7578|57.0582|

|Winner|Unselfishness|Unselfishness|Empty|Count|
|:---|:---|:---|:---|:---|
|-0.0295|31.7327|32.2625|0.0048|60.7481|

## License

These codes are licensed under CC0.

[![CC0](https://mirrors.creativecommons.org/presskit/buttons/88x31/svg/cc-zero.svg "CC0")](http://creativecommons.org/publicdomain/zero/1.0/deed.ja)

## Contact

|E-mail:|wanotaitei@gmail.com|
|:---|:---|
|Twitter:|[@wanotaitei](https://twitter.com/wanotaitei)|
|![svg](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/as_logo.svg)|**As Project**|
|![gaccho](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/gaccho_icon.svg)|Made by Gaccho.|

Japan Terrain Generation Research Institute

