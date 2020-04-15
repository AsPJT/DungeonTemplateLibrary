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

using DTL.Console;
using UnityEngine;
using DTL.Shape;
using RangeMatrix = DTL.Base.Coordinate2DimensionalAndLength2Dimensional;

public class GenerateSimpleRogueLikeDungeon : MonoBehaviour {

    public int width = 48;
    public int height = 36;
    public uint divisionMin = 4;
    public uint divisionRandMax = 4;
    public uint roomMinX = 5;
    public uint roomRandMaxX = 2;
    public uint roomMinY = 5;
    public uint roomRandMaxY = 2;

    /*#################################################################################
     * SimpleRogueLike Constructor
     * roomValue : ダンジョンで部屋として出力される値 (The value that output as Room)
     * roadValue : ダンジョンで道として出力される値 (The value that output as Road)
     * divisionMin : 部屋生成候補数の最小値 (Minimum number of candidate room sites)
     * divisionRandMax : divisionの振れ幅 (divisionMin + [0, divisionRandMax) equals to maximum number of candidates room sites)
     * roomMinX : 部屋のX軸の最小値 (Minimum value of room's X axis)
     * roomRandMaxX : 部屋のX軸の振れ幅 (roomMinX + roomRandMaxX equals to maximum number of room's X axis)
     * roomMinY : 部屋のY軸の最小値 (Minimum value of room's Y axis)
     * roomRandMaxY : 部屋のY軸の振れ幅 (roomMinY + roomRandMaxY equals to maximum number of room's Y axis)
     *#################################################################################*/
    private SimpleRogueLike simpleRogueLike;


    //    private SimpleRogueLike simpleRogueLike = new SimpleRogueLike();
    //    private SimpleRogueLike simpleRogueLike = new SimpleRogueLike(1);
    //    private SimpleRogueLike simpleRogueLike = new SimpleRogueLike(1, 2);
    //    private SimpleRogueLike simpleRogueLike = new SimpleRogueLike(new RangeMatrix(0, 0, width, height));
    //    private SimpleRogueLike simpleRogueLike = new SimpleRogueLike(new RangeMatrix(0, 0, width, height), 1);
    //    private SimpleRogueLike simpleRogueLike = new SimpleRogueLike(new RangeMatrix(0, 0, width, height), 1, 2);
    //    private SimpleRogueLike simpleRogueLike =
    //    new SimpleRogueLike(new RangeMatrix(0, 0, width, height), 1, 2, 4, 5, 5, 2, 5, 2);

    public GameObject Floor;
    public GameObject Wall;

    private void Start() {
        int[,] matrix = new int[height, width];
        simpleRogueLike 
            = new SimpleRogueLike(1, 2, divisionMin, divisionRandMax, roomMinX, roomRandMaxX, roomMinY, roomRandMaxY);
        simpleRogueLike.Draw(matrix);
        new OutputConsole().Draw(matrix);
        DungeonInstantiate(matrix);
    }

    private void DungeonInstantiate(int[,] matrix) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (matrix[i, j] == 0) {
                    Instantiate(Wall, new Vector3(j, 0, i), Quaternion.identity);
                } else {
                    Instantiate(Floor, new Vector3(j, 0, i), Quaternion.identity);
                }
            }
        }
    }
}
