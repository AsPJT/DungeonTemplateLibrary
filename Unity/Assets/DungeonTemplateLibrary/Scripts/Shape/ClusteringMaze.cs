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

using System.Collections.Generic;
using DTL.Range;
using DTL.Util;
using DTL.Random;
using UnityEngine;
using MatrixRange = DTL.Base.Coordinate2DimensionalAndLength2Dimensional;

namespace DTL.Shape {
    public class ClusteringMaze : RectBaseWithValue<ClusteringMaze>, IDrawer<int> {
        private RandomBase rand = new RandomBase();

        private enum Direction {
            UP_DIR = 0,
            RIGHT_DIR,
            DOWN_DIR,
            LEFT_DIR
        }

        int dirDx(Direction dir) {
            switch (dir) {
                case Direction.UP_DIR:
                case Direction.DOWN_DIR: return 0;
                case Direction.RIGHT_DIR: return 1;
                case Direction.LEFT_DIR: return -1;
            }
            return 0;
        }
        int dirDy(Direction dir) {
            switch (dir) {
                case Direction.RIGHT_DIR:
                case Direction.LEFT_DIR:return 0;
                case Direction.UP_DIR:return -1;
                case Direction.DOWN_DIR:return 1;
            }
            return 0;
        }

        private uint root(uint[] data, uint x) {
            return data[x] == x ? x : data[x] = this.root(data, data[x]);
        }

        private bool same(uint[] data, uint x, uint y) {
            return this.root(data, x) == this.root(data, y);
        }
        
        private void unite(uint[] data, uint[] rank, uint x, uint y) {
            x = this.root(data, x);
            y = this.root(data, y);

            if (rank[x] < rank[y]) data[x] = y;
            else {
                data[y] = x;
                if (rank[x] == rank[y]) ++rank[x];
            }
        }

        private void uniteDifNeighbor(uint[] data, uint[] rank, uint mWidth, uint mHeight, uint mSize, uint x, uint y,
            ref uint outX, ref uint outY, ref Direction outDir) {
            uint oX = 0, oY = 0;
            Direction oDir = Direction.UP_DIR;
            if (this.findDifNeighbor(data, mWidth, mHeight, mSize, x, y, ref oX, ref oY, ref oDir) != -1)
                this.unite(data, rank, y * mWidth + x, oY * mWidth + oX);
            outX = oX;
            outY = oY;
            outDir = oDir;
        }

        int findDifNeighbor(uint[] data, uint mWidth, uint mHeight, uint mSize, uint x, uint y,
            ref uint outX, ref uint outY, ref Direction outDir) {
            var sameTags = new List<uint>();
            var cellind = y * mWidth + x;
            for (uint i = 0; i < mSize; ++i) {
                if (this.same(data, cellind, i)) sameTags.Add(i);
            }

            ArrayUtil.Shuffle(sameTags, rand);

            uint cell1X = 0, cell1Y = 0, cell2X = 0, cell2Y = 0, cell2ind = 0;
            var dirs = new Direction[4];
            dirs[0] = Direction.UP_DIR;
            dirs[1] = Direction.RIGHT_DIR;
            dirs[2] = Direction.DOWN_DIR;
            dirs[3] = Direction.LEFT_DIR;

            foreach (var cell1ind in sameTags) {
//                Debug.Log(cell1ind);
                cell1X = cell1ind % mWidth;
                cell1Y = cell1ind / mWidth;
                dirs = ArrayUtil.Shuffle(dirs, rand);
                foreach (var dir in dirs) {
//                    Debug.Log(dir.ToString());
                    if ((dirDx(dir) < 0 && cell1X == 0) || (dirDx(dir) > 0 && cell1X == mWidth - 1)) continue;
                    cell2X = (uint) ((int) cell1X + dirDx(dir));
                    if ((dirDy(dir) < 0 && cell1Y == 0) || (dirDy(dir) > 0 && cell1Y == mHeight - 1)) continue;
                    cell2Y = (uint) ((int) cell1Y + dirDy(dir));
                    cell2ind = cell2Y * mWidth + cell2X;
                    if (!this.same(data, cell1ind, cell2ind)) {
                        outX = cell2X;
                        outY = cell2Y;
                        outDir = dir;
                        return 0;
                    }
                }
            }

            return -1;
        }

        private bool isAllSame(uint[] data, uint dSize) {
            for (uint i = 1; i < dSize; ++i)
                if (!this.same(data, i, 0))
                    return false;
            return true;
        }

        public bool Draw(int[,] matrix) {
            return DrawNormal(matrix);
        }

        private bool DrawNormal(int[,] matrix) {
            var width = this.CalcEndX(MatrixUtil.GetX(matrix) - this.startX);
            var height = this.CalcEndY(MatrixUtil.GetY(matrix) - this.startY);

            var width3 = width % 2 == 0 ? width - 1 : width;
            var height3 = height % 2 == 0 ? height - 1 : height;

            for (var i = 0; i < width3 / 2; ++i) {
                for (var j = 0; j < height3 / 2; ++j) {
                    matrix[this.startY + (2 * j + 1), this.startX + (2 * i + 1)] = this.drawValue;
                }
            }

            var mWidth = width3 / 2;
            var mHeight = height3 / 2;
            var mSize = mWidth * mHeight;

            // Union Find, Collectionを使わずに素の配列で実装する。
            var data = new uint[mSize];
            var rank = new uint[mSize];
            for (uint i = 0; i < mSize; ++i) data[i] = i; // 自分の親は自分

            uint randCellX = 0;
            uint randCellY = 0;
            uint outX = 0;
            uint outY = 0;
            Direction outDir = Direction.UP_DIR;
            while (!this.isAllSame(data, mSize)) {
                randCellX = rand.Next() % (width3 / 2);
                randCellY = rand.Next() % (height3 / 2);

                this.uniteDifNeighbor(data, rank, mWidth, mHeight, mSize, randCellX, randCellY, ref outX, ref outY, ref outDir);

                // break wall
                matrix[2 * outY + 1 - this.dirDy(outDir), 2 * outX + 1 - this.dirDx(outDir)] = this.drawValue;
            }

            return true;
        }

        public ClusteringMaze() {
        } // = default();

        public ClusteringMaze(int drawValue, MatrixRange matrixRange) : base(drawValue, matrixRange) {
        }

        public ClusteringMaze(int drawValue, uint startX, uint startY, uint width, uint height) : base(drawValue,
            startX, startY, width, height) {
        }

        public ClusteringMaze(int drawValue) : base(drawValue) {
        }
    }
}