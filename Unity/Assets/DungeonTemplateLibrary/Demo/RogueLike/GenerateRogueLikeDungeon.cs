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
using MatrixRange = DTL.Base.Coordinate2DimensionalAndLength2Dimensional;

public class GenerateRogueLikeDungeon : MonoBehaviour {
    private readonly int height = 32;
    private readonly int width = 48;
    private const int outsideWallId = 0;
    private const int insideWallId = 1;
    private const int roomId = 2;
    private const int entranceId = 3;
    private const int wayId = 4;

    public GameObject OutsideWall;
    public GameObject InsideWall;
    public GameObject Room;
    public GameObject Entrance;
    public GameObject Way;


    /*#################################################################################
         * RogueLike Constructor
         " outsideWallId: 外壁として出力する値 (The number represents as OutsideWall)
         * insideWallId: 内壁として出力する値 (The number represents as InsideWall)
         * roomId: 部屋として出力する値 (The number represents as Room)
         * wayId: 部屋と部屋をつなぐ道として出力する値 (The number represents as Room)
         * maxWay: 部屋と道の最大生成数 (The maximum number Room + Way)
         * roomRange: 部屋の最低限の大きさ(x, y), ランダム性(w, h) (The minimum number and random)
         * wayRange: 道の最低限の大きさ(x, y), ランダム性(w, h) (The minimum number and random)
     *#################################################################################*/
    RogueLike rogueLike = new RogueLike(0, 1, 2, 3, 4, 30,
        new MatrixRange(3, 3, 2, 2), new MatrixRange(3, 3, 4, 4));

    void Start() {
        int[,] matrix = new int[height, width];
        rogueLike.Draw(matrix);
        new OutputConsole().Draw(matrix);
        DungeonInstantiate(matrix, height, width);
    }

    private void DungeonInstantiate(int[,] matrix, int h, int w) {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                int pos1 = j;
                switch (matrix[i, j]) {
                    case outsideWallId:
                        Instantiate(OutsideWall, new Vector3(pos1, 0, i), Quaternion.identity);
                        break;
                    case insideWallId:
                        Instantiate(InsideWall, new Vector3(pos1, 0, i), Quaternion.identity);
                        break;
                    case roomId:
                        Instantiate(Room, new Vector3(pos1, 0, i), Quaternion.identity);
                        break;
                    case entranceId:
                        Instantiate(Entrance, new Vector3(pos1, 0, i), Quaternion.identity);
                        break;
                    case wayId:
                        Instantiate(Way, new Vector3(pos1, 0, i), Quaternion.identity);
                        break;
                }
            }
        }
    }
}