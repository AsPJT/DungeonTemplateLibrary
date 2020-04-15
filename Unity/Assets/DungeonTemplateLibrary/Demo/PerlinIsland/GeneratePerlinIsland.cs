/*#######################################################################################
    Copyright (c) 2017-2019 Kasugaccho
    Copyright (c) 2018-2019 As Project
    https://github.com/Kasugaccho/DungeonTemplateLibrary
    wanotaitei@gmail.com

    DungeonTemplateLibraryUnity
    https://github.com/sitRyo/DungeonTemplateLibraryUnity
    seriru.rcvmailer@gmail.com

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/

using DTL.Range;
using DTL.Shape;
using UnityEngine;
using System.Collections.Generic;
using DTL.Console;

public class GeneratePerlinIsland : MonoBehaviour {
    public const int height = 200;
    public const int width = 200;

    private PerlinIsland perlinIsland;

    public List<GameObject> cubes = new List<GameObject>();

    private void Start () {
        var matrix = new int[height, width];
        perlinIsland = new PerlinIsland(6.0, 8, 150);
        perlinIsland.Draw(matrix);
        new OutputConsole().Draw(matrix);
        Generate(height, width, matrix, 150);
    }

    private void Generate(int height, int width, int[,] matrix, int maxHeight) {
        int[] limited = new int[cubes.Count];
        SetLimit(limited, maxHeight);
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                var cubeHeight = GetMapHeight(matrix[row, col], limited);
                CubeInstantiate(row, cubeHeight, col);
            }
        }
    }

    private void CubeInstantiate(int x, int y, int z) {
        Instantiate(cubes[y], new Vector3(x, y, z), Quaternion.identity);
    }

    private int GetMapHeight(int arrayValue, int[] limit) {
        var length = limit.Length;
        var value = length-1;
        for (int i = 0; i < length; ++i) {
            if (arrayValue < limit[i]) {
                value = i-1;
                return value;
            }
        }

        return value;
    }

    private int[] SetLimit(int[] limit, int maxHeight) {
        var length = limit.Length;
        var heightUnit = (int) maxHeight / length;
        var count = 0;
        for (int i = 0; i < length; ++i) {
            limit[i] = count;
            count += heightUnit;
        }

        return limit;
    }

}
