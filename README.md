# Dungeon Template Library
 <a href="http://creativecommons.org/publicdomain/zero/1.0/deed.ja"><img src="https://img.shields.io/badge/license-CC0-blue.svg"></a> <a href="https://github.com/Kasugaccho/AsLib"><img src="https://img.shields.io/badge/0.1.0-passing-brightgreen.svg"></a>
 
[![DTL](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/DTL_logo.svg "DTL")](https://github.com/Kasugaccho/DungeonTemplateLibrary)

DTL (Dungeon Template Library)

[>> Japanese](https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/%5Bja%5D-Home)

# Overview

## [Type] Dungeon Generation
 - RogueLike Generation
 
 RogueLike
 
 SimpleRogueLike
 
 - Maze Generation
 
 MazeDig

## [Type] Terrain Generation
 - Terrain Generation

SimpleVoronoiIsland

FractalIsland

## 👾Test👾

[Wandbox(1-4)](https://wandbox.org/permlink/VDWP5m3EZQeB3zVT)

## Version 0.1.9 [ C++14 ]

|View|Test Code|
|:---|:---|
|PC View|[Wandbox](https://wandbox.org/permlink/VC13TPmxcO49LRBD)|
|SP View|[WandBox](https://wandbox.org/permlink/D3LFLXm4gum8Rg7N)|

|Compiler|[Pass_C++14](https://github.com/Kasugaccho/DungeonTemplateLibrary/tree/master/include/cpp14)|[Pass_C99](https://github.com/Kasugaccho/DungeonTemplateLibrary/tree/master/include/c99)|
|:---|:---|:---|
|MSVC|![cl](https://img.shields.io/badge/cl%2014.10-passing-brightgreen.svg)|![cl](https://img.shields.io/badge/cl%2014.10-passing-brightgreen.svg)|
|GCC|![gcc](https://img.shields.io/badge/gcc%205.1.0-passing-brightgreen.svg)|![gcc](https://img.shields.io/badge/gcc%204.4.7-passing-brightgreen.svg)|
|Clang|![clang](https://img.shields.io/badge/clang%203.5.0-passing-brightgreen.svg)|![clang](https://img.shields.io/badge/clang%203.1-passing-brightgreen.svg)|

## RogueLike (v0.1.0~)
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

### Variable
![bool_false](https://img.shields.io/badge/Variable-bool-red.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Image
![rl1](https://github.com/Kasugaccho/DTL_RogueLike/blob/master/picture/rl.gif)
![rl4](https://github.com/Kasugaccho/DTL_RogueLike/blob/master/picture/rl4.gif)

## Simple Voronoi Island (v0.1.0~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99](https://img.shields.io/badge/C99-passing-brightgreen.svg)

```cpp
#include <SimpleVoronoiIsland.hpp>
```

|Default Value|Name|Image Color|
|:---:|:---|:---|
|0|Sea|Pale Brown|
|1|Land|Dark Olive|

### Variable
![bool_true](https://img.shields.io/badge/Variable-bool-brightgreen.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Image
![voronoi](https://github.com/Kasugaccho/DTL_SimpleVoronoiIsland/blob/master/picture/voronoi.gif)

## Fractal Island (v0.1.1~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99](https://img.shields.io/badge/C99-passing-brightgreen.svg)

```cpp
#include <FractalIsland.hpp>
```

|Default Value|Name|
|:---:|:---|
|0-255|Height|

### Variable
![bool_false](https://img.shields.io/badge/Variable-bool-red.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Image
![FI1](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/FI_1.gif)

## Maze Dig (v0.1.2~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99](https://img.shields.io/badge/C99-passing-brightgreen.svg)

```cpp
#include <MazeDig.hpp>
```

|Default Value|Name|Image Color|
|:---:|:---|:---|
|0|Wall|Blue|
|1|Empty|White|

### Variable
![bool_true](https://img.shields.io/badge/Variable-bool-brightgreen.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Image
![maze_dig](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/MD_1.gif)

## Simple RogueLike (v0.1.3~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99](https://img.shields.io/badge/C99-passing-brightgreen.svg)

```cpp
#include <SimpleRogueLike.hpp>
```

|Default Value|Name|Image Color|
|:---:|:---|:---|
|0|Wall|Black|
|1|Empty|White|

### Variable
![bool_true](https://img.shields.io/badge/Variable-bool-brightgreen.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Image
![STL1](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/SRL_1.gif)


## DungeonInit (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <DungeonStandard.hpp>
```

|Default Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|Black|

### Variable
![bool_true](https://img.shields.io/badge/Variable-bool-brightgreen.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Image
![di](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/dungeon_init.png)

## Border (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <DungeonStandard.hpp>
```

|Default Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|White|
|1|Wall|Black|

### Variable
![bool_true](https://img.shields.io/badge/Variable-bool-brightgreen.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Image
![db](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/dungeon_border.png)

## BorderOdd (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <DungeonStandard.hpp>
```

|Default Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|White|
|1|Wall|Black|

### Variable
![bool_true](https://img.shields.io/badge/Variable-bool-brightgreen.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Image
![bo](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/dungeon_border_odd.png)


## PointGrid (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <DungeonStandard.hpp>
```

|Default Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|White|
|1|Wall|Black|

### Variable
![bool_true](https://img.shields.io/badge/Variable-bool-brightgreen.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Image
![pg](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/point_grid.png)

## PointGridField (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <DungeonStandard.hpp>
```

|Default Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|White|
|1|Wall|Black|

### Variable
![bool_true](https://img.shields.io/badge/Variable-bool-brightgreen.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Image
![pgf](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/point_grid_field.png)

## Reversi (v0.1.10~)
![cpp14](https://img.shields.io/badge/C%2B%2B14-passing-brightgreen.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

```cpp
#include <BoardGame.hpp>
```

|Default Value|Name|Image Color|
|:---:|:---|:---|
|0|Empty|Green|
|1|White|White|
|2|Black|Black|

### Variable
![bool_false](https://img.shields.io/badge/Variable-bool-red.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

### Image
![re](https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/master/Picture/reversi.png)

## Maze α
![cpp14](https://img.shields.io/badge/C%2B%2B14-developing-orange.svg) ![c99_no](https://img.shields.io/badge/C99-nothing-lightgrey.svg)

Underdevelopment...

### Variable
![bool_false](https://img.shields.io/badge/Variable-bool-red.svg) ![int_true](https://img.shields.io/badge/Variable-Integer%20Types-brightgreen.svg)

# AI

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

