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

using System;
using DTL.Random;
using UnityEngine;
using MatrixRange = DTL.Base.Coordinate2DimensionalAndLength2Dimensional;


/* size_t = uint とする。uint => System.UInt32 */

namespace DTL.Shape {

    /*#######################################################################################
        [概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
        [Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
    #######################################################################################*/

    public class SimpleRogueLike : DTL.Range.RectBaseSimpleRogueLike<SimpleRogueLike>, IDrawer<int> {

        private RandomBase rand = new RandomBase();

        private const int RL_COUNT_X = 0;
        private const int RL_COUNT_Y = 1;

        /* 基本処理 */

        // Normal
        private bool DrawNormal(int[,] matrix_, uint endX_, uint endY_) {
            // マップの区分け数（部屋の個数）0~nまでの部屋ID
            var mapDivCount = divisionMin + rand.Next(divisionRandMax);

            // マップの区域 [部屋ID][X終点 , Y終点 , X始点 , Y始点]
            var dungeonDivision = new uint[mapDivCount, 4];
            // マップの部屋 [部屋ID][X終点 , Y終点 , X始点 , Y始点]
            var dungeonRoom = new uint[mapDivCount, 4];
            // マップの道 [部屋ID][X終点 , Y終点 , X始点 , Y始点]
            var dungeonRoad = new uint[mapDivCount, 4];

            dungeonDivision[0, 0] = endY_ - 1; // マップの区分け初期サイズX終点 (マップの大きさY軸)
            dungeonDivision[0, 1] = endX_ - 1; // マップの区分け初期サイズY終点 (マップの大きさX軸)
            dungeonDivision[0, 2] = startX + 1; // マップの区分け初期サイズX始点 (マップの大きさX軸)
            dungeonDivision[0, 3] = startY + 1; // マップの区分け初期サイズY始点 (マップの大きさY軸)

            dungeonRoad[0, 0] = uint.MaxValue;
            dungeonRoad[0, 1] = uint.MaxValue;

            CreateDivision(dungeonRoad, dungeonDivision, mapDivCount);
            CreateRoom(dungeonRoom, dungeonDivision, mapDivCount);
            AssignRoom(dungeonRoom, matrix_, mapDivCount);
            CreateRoad(dungeonRoad, dungeonRoom, dungeonDivision, matrix_, mapDivCount);
            return true;
        }

        private void CreateDivision(uint[,] dungeonRoad, uint[,] dungeonDivision, uint mapDivCount) {
            // マップを区分けしていく処理(区域を分割する処理)
            uint divisionAfter = 0;
            int count = 0; // x = 0, y = 1, X軸で分けるかY軸で分けるかを決める

            for (int i = 1; i < mapDivCount; ++i) {
                // 今まで作った区分けをランダムに指定(指定した区域をさらに区分けする)
                divisionAfter = rand.Next((uint)i);

                // 指定した区域のXとYの長さによって、分割する向きを決める(長い方を分割する)
                if (dungeonDivision[divisionAfter, 0] - dungeonDivision[divisionAfter, 2] >
                    dungeonDivision[divisionAfter, 1] - dungeonDivision[divisionAfter, 3]) {
                    count = RL_COUNT_X;
                } else {
                    count = RL_COUNT_Y;
                }


                if (dungeonDivision[divisionAfter, count] - dungeonDivision[divisionAfter, count + 2] <
                    divisionRandMax * 2 + 8) {
                    uint k = 0;
                    for (int j = 1; j < mapDivCount; ++j) {
                        if (dungeonDivision[j, 0] - dungeonDivision[j, 2] > k) {
                            k = dungeonDivision[j, 0] - dungeonDivision[j, 2];
                            divisionAfter = (uint)j;
                            count = RL_COUNT_X;
                        }

                        if (dungeonDivision[j, 1] - dungeonDivision[j, 3] > k) {
                            k = dungeonDivision[j, 1] - dungeonDivision[j, 3];
                            divisionAfter = (uint)j;
                            count = RL_COUNT_Y;
                        }
                    }
                }

                dungeonRoad[i, 0] = divisionAfter;
                dungeonRoad[i, 1] = (uint)count;

                for (int j = 1; j < i; ++j) {
                    if (dungeonRoad[j, 0] == divisionAfter) dungeonRoad[j, 0] = (uint)i;
                }

                dungeonDivision[i, count] =
                    dungeonDivision[divisionAfter, count + 2]
                    + (dungeonDivision[divisionAfter, count] - dungeonDivision[divisionAfter, count + 2]) / 3
                    + (uint)rand.Next(1, (dungeonDivision[divisionAfter, count] - dungeonDivision[divisionAfter, count + 2]) / 3);

                dungeonDivision[i, count + 2] = dungeonDivision[divisionAfter, count + 2]; // 0, 軸の左端の座標
                dungeonDivision[divisionAfter, count + 2] = dungeonDivision[i, count]; // divisionAfter軸の左端
                // count とは逆の軸を設定
                dungeonDivision[i, Math.Abs(count - 1)] = dungeonDivision[divisionAfter, Math.Abs(count - 1)];
                dungeonDivision[i, Math.Abs(count - 1) + 2] = dungeonDivision[divisionAfter, Math.Abs(count - 1) + 2];
            }
        }

        private void CreateRoom(uint[,] dungeonRoom, uint[,] dungeonDivision, uint mapDivCount) {

            // 部屋を生成する処理
            for (int i = 0; i < mapDivCount; ++i) { // 区分け
                dungeonRoom[i, 2] = dungeonDivision[i, 2];
                dungeonRoom[i, 3] = dungeonDivision[i, 3];

                // X座標の部屋の長さを指定
                dungeonRoom[i, 0] = dungeonDivision[i, 2] + roomMinY + rand.Next(roomRandMaxX);

                if (dungeonDivision[i, 0] - dungeonDivision[i, 2] < dungeonRoom[i, 0] - dungeonRoom[i, 2] + 5) {
                    dungeonRoom[i, 0] = dungeonDivision[i, 0] - 4;
                    if (dungeonDivision[i, 0] - dungeonDivision[i, 2] < dungeonRoom[i, 0] - dungeonRoom[i, 2] + 5) {
                        dungeonRoom[i, 0] = dungeonDivision[i, 2] + 1;
                    }
                }

                // Y座標の部屋の長さを指定
                dungeonRoom[i, 1] = dungeonDivision[i, 3] + roomMinX + rand.Next(roomRandMaxY);

                if (dungeonDivision[i, 1] - dungeonDivision[i, 3] < dungeonRoom[i, 1] - dungeonRoom[i, 3] + 5) {
                    dungeonRoom[i, 1] = dungeonDivision[i, 1] - 4;
                    if (dungeonDivision[i, 1] - dungeonDivision[i, 3] < dungeonRoom[i, 1] - dungeonRoom[i, 3] + 5) {
                        dungeonRoom[i, 1] = dungeonDivision[i, 3] + 1;
                    }
                }

                if (dungeonRoom[i, 0] - dungeonDivision[i, 2] <= 1 || dungeonRoom[i, 1] - dungeonDivision[i, 3] <= 1) {
                    dungeonRoom[i, 0] = dungeonDivision[i, 2] + 1;
                    dungeonRoom[i, 1] = dungeonDivision[i, 3] + 1;
                }


                uint l = dungeonDivision[i, 0] - dungeonRoom[i, 0] - 5 == 0 ? 2 : rand.Next(1, (dungeonDivision[i, 0] - dungeonRoom[i, 0]) - 5) + 2;
                uint n = dungeonDivision[i, 1] - dungeonRoom[i, 1] - 5 == 0 ? 2 : rand.Next(1, (dungeonDivision[i, 1] - dungeonRoom[i, 1]) - 5) + 2;

                dungeonRoom[i, 0] += l;
                dungeonRoom[i, 2] += l;
                dungeonRoom[i, 1] += n;
                dungeonRoom[i, 3] += n;
            }
        }

        private void CreateRoad(uint[,] dungeonRoad, uint[,] dungeonRoom, uint[,] dungeonDivision, int[,] matrix_, uint mapDivCount) {
            for (uint roomBefore = 0, roomAfter = 0; roomBefore < mapDivCount; ++roomBefore) {
                roomAfter = dungeonRoad[roomBefore, 0];
                switch (dungeonRoad[roomBefore, 1]) {
                    case RL_COUNT_X:
                        dungeonRoad[roomBefore, 2] = rand.Next(dungeonRoom[roomBefore, 1] - dungeonRoom[roomBefore, 3] - 1);
                        dungeonRoad[roomBefore, 3] = rand.Next(dungeonRoom[roomAfter, 1] - dungeonRoom[roomAfter, 3] - 1);

                        // 前の通路
                        for (uint j = dungeonRoom[roomBefore, 0]; j < dungeonDivision[roomBefore, 0]; ++j)
                            matrix_[j, dungeonRoad[roomBefore, 2] + dungeonRoom[roomBefore, 3]] = roadValue;
                        // 後の通路
                        for (uint j = dungeonDivision[roomAfter, 2]; j < dungeonRoom[roomAfter, 2]; ++j)
                            matrix_[j, dungeonRoad[roomBefore, 3] + dungeonRoom[roomAfter, 3]] = roadValue;

                        // 通路をつなぐ
                        for (uint j = dungeonRoad[roomBefore, 2] + dungeonRoom[roomBefore, 3]; j <= dungeonRoad[roomBefore, 3] + dungeonRoom[roomAfter, 3]; ++j)
                            matrix_[dungeonDivision[roomBefore, 0], j] = roadValue; // 通路にマップチップを線画
                        for (uint j = dungeonRoad[roomBefore, 3] + dungeonRoom[roomAfter, 3]; j <= dungeonRoad[roomBefore, 2] + dungeonRoom[roomBefore, 3]; ++j)
                            matrix_[dungeonDivision[roomBefore, 0], j] = roadValue; // 通路にマップチップを線画
                        break;
                    case RL_COUNT_Y:
                        dungeonRoad[roomBefore, 2] = rand.Next(dungeonRoom[roomBefore, 0] - dungeonRoom[roomBefore, 2] - 1);
                        dungeonRoad[roomBefore, 3] = rand.Next(dungeonRoom[roomAfter, 0] - dungeonRoom[roomAfter, 2] - 1);

                        // 前の通路
                        for (uint j = dungeonRoom[roomBefore, 1]; j < dungeonDivision[roomBefore, 1]; ++j)
                            matrix_[dungeonRoad[roomBefore, 2] + dungeonRoom[roomBefore, 2], j] = roadValue;
                        // 後の通路
                        for (uint j = dungeonDivision[roomAfter, 3]; j < dungeonRoom[roomAfter, 3]; ++j)
                            matrix_[dungeonRoad[roomBefore, 3] + dungeonRoom[roomAfter, 2], j] = roadValue;

                        // 通路をつなぐ
                        for (uint j = dungeonRoad[roomBefore, 2] + dungeonRoom[roomBefore, 2]; j <= dungeonRoad[roomBefore, 3] + dungeonRoom[roomAfter, 2]; ++j)
                            matrix_[j, dungeonDivision[roomBefore, 1]] = roadValue; // 通路にマップチップを線画
                        for (uint j = dungeonRoad[roomBefore, 3] + dungeonRoom[roomAfter, 2]; j <= dungeonRoad[roomBefore, 2] + dungeonRoom[roomBefore, 2]; ++j)
                            matrix_[j, dungeonDivision[roomBefore, 1]] = roadValue; // 通路にマップチップを線画
                        break;

                }
            }
        }

        private void AssignRoom(uint[,] dungeonRoom, int[,] matrix_, uint mapDivCount) {
            // 部屋を生成する処理(始点 -> 終点)
            for (uint i = 0; i < mapDivCount; ++i)
                for (uint j = dungeonRoom[i, 2]; j < dungeonRoom[i, 0]; ++j)
                    for (uint k = dungeonRoom[i, 3]; k < dungeonRoom[i, 1]; ++k)
                        matrix_[j, k] = roomValue;
        }

        // 生成呼び出し (drawing function call)
        public bool Draw(int[,] matrix_) {
            return DrawNormal(
                matrix_,
                (width == 0 || startX + width >= (matrix_.Length == 0 ? 0 : (uint)(matrix_.Length / matrix_.GetLength(0)))) ? (uint)(matrix_.Length / matrix_.GetLength(0)) : startX + width,
                (height == 0 || startY + height >= matrix_.GetLength(0)) ? (uint)(matrix_.Length == 0 ? 0 : matrix_.GetLength(0)) : startY + height);
        }

        public int[,] Create(int[,] matrix) {
            this.Draw(matrix);
            return matrix;
        }

        /* Constructors */
        public SimpleRogueLike() { } // = default();

        public SimpleRogueLike(int roomValue) : base(roomValue) { }

        public SimpleRogueLike(int roomValue, int roadValue) : base(roomValue, roadValue) { }

        public SimpleRogueLike(int roomValue, int roadValue, uint divisionMin,
            uint divisionRandMax, uint roomMinX, uint roomRandMaxX, uint roomMinY, uint roomRandMaxY) : base(roomValue, roadValue, divisionMin, divisionRandMax, roomMinX, roomRandMaxX, roomMinY, roomRandMaxY) { }

        public SimpleRogueLike(MatrixRange matrixRange) : base(matrixRange) { }

        public SimpleRogueLike(MatrixRange matrixRange, int roomValue) : base(matrixRange, roomValue) { }

        public SimpleRogueLike(MatrixRange matrixRange, int roomValue, int roadValue) : base(matrixRange, roomValue, roadValue) { }

        public SimpleRogueLike(MatrixRange matrixRange, int roomValue, int roadValue, uint divisionMin,
            uint divisionRandMax, uint roomMinX, uint roomRandMaxX, uint roomMinY, uint roomRandMaxY)
            : base(matrixRange, roomValue, roadValue, divisionMin, divisionRandMax, roomMinX, roomRandMaxX, roomMinY, roomRandMaxY) { }
    }
}