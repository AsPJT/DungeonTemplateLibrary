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
using DTL.Range;
using DTL.Util;
using DTL.Random;
using MatrixRange = DTL.Base.Coordinate2DimensionalAndLength2Dimensional;

namespace DTL.Shape {
    public class DiamondSquareAverageCornerIsland : RectBaseFractal<DiamondSquareAverageCornerIsland>, IDrawer<int>, ITerrainDrawer {
        XorShift128 rand = new XorShift128();

        // のちのちUtilに入れるか...
        public int GetMatrixSize(int matrixSize) {
            var mapSize = 2; // note, overflow.
            while (true) {
                if (mapSize + 1 > matrixSize) return mapSize >>= 1;
                else mapSize <<= 1;
            }
        }

        public bool Draw(int[,] matrix) {
            return DrawNormal(matrix);
        }

        public int[,] Create(int[,] matrix) {
            Draw(matrix);
            return matrix;
        }

        private bool DrawNormal(int[,] matrix) {
            if (this.altitude < 2) return false;
            return (this.width == 0)
                ? DrawSTL(matrix, CalcEndY(MatrixUtil.GetY(matrix)))
                : DrawWidthSTL(matrix, this.startX + this.width, this.CalcEndY(MatrixUtil.GetY(matrix)));
            // return DrawSTL(matrix, CalcEndY(MatrixUtil.GetY(matrix)));
        }

        public bool DrawNormalize(float[,] matrix) {
            int[,] convertedMatrix = new int[matrix.GetLength(0), matrix.GetLength(1)];

            // I cannot use LINQ for 2 dim array. Please tell me how to use LINQ for 2 dim array...orz
            for (int y = 0; y < MatrixUtil.GetY(matrix); ++y) {
                for (int x = 0; x < MatrixUtil.GetX(matrix); ++x) {
                    convertedMatrix[y, x] = (int) matrix[y, x];
                }
            }

            DrawNormal(convertedMatrix);
            Normalize(convertedMatrix, matrix);
            return true;
        }

        private void Normalize(int[,] matrix, float[,] retMatrix) {
            var maxHeight = MatrixUtil.GetMax(matrix);

            for (int y = 0; y < MatrixUtil.GetY(matrix); ++y) {
                for (int x = 0; x < MatrixUtil.GetX(matrix); ++x) {
                    retMatrix[y, x] = (float) matrix[y, x] / maxHeight;
                }
            }
        }

        private bool DrawWidthSTL(int[,] matrix, uint endX, uint endY) {
            var x_ = MatrixUtil.GetX(matrix);
            if (this.altitude < 2) return false;
            AssignSTL(matrix,
                GetMatrixSize(endY > Math.Min((int) x_, (int) endX) ? (int) Math.Min(x_, endX) : (int) endY));
            return true;
        }

        private bool DrawSTL(int[,] matrix, uint endY) {
            var x_ = MatrixUtil.GetX(matrix);
            AssignSTL(matrix, GetMatrixSize(endY > x_ ? (int) x_ : (int) endY));
            return true;
        }

        private void AssignSTL(int[,] matrix, int mapSize) {
            Func<int, int> func = arg => arg / 2;
            AssignSTL(matrix, mapSize, func);
        }

        private void AssignSTL(int[,] matrix, int mapSize, Func<int, int> func) {
            matrix[this.startY, this.startX] = this.minValue + this.altitude;
            matrix[this.startY, this.startX + mapSize] = this.minValue + (int) rand.Next((uint) this.altitude);
            matrix[this.startY + mapSize, this.startX] = this.minValue + (int) rand.Next((uint) this.altitude);
            matrix[this.startY + mapSize, this.startX + mapSize] =
                this.minValue + (int) rand.Next((uint) this.altitude);
            DiamondSquareAverage.CreateDiamondSquareAverage(matrix, this.startX, this.startY, (uint) mapSize / 2,
                (uint) mapSize / 2,
                (uint) mapSize / 2, matrix[this.startY, this.startX], matrix[this.startY + mapSize, this.startX],
                matrix[this.startY, this.startX + mapSize], matrix[this.startY + mapSize, this.startX + mapSize],
                this.minValue + this.altitude, this.addAltitude, rand, func);
        }

        /* constructors */
        public DiamondSquareAverageCornerIsland() {
        } // = default()

        public DiamondSquareAverageCornerIsland(uint startX, uint startY, uint width, uint height) :
            base(startX, startY, width, height) {
        }

        public DiamondSquareAverageCornerIsland(int minValue) : base(minValue) {
        }

        public DiamondSquareAverageCornerIsland(int minValue, int altitude) : base(minValue, altitude) {
        }

        public DiamondSquareAverageCornerIsland(int minValue, int altitude, int addAltitude) : base(minValue, altitude,
            addAltitude) {
        }

        public DiamondSquareAverageCornerIsland(MatrixRange matrixRange, int minValue) : base(matrixRange, minValue) {
        }

        public DiamondSquareAverageCornerIsland(MatrixRange matrixRange, int minValue, int altitude) : base(matrixRange,
            minValue,
            altitude) {
        }

        public DiamondSquareAverageCornerIsland(MatrixRange matrixRange, int minValue, int altitude, int addAltitude) :
            base(
                matrixRange,
                minValue, altitude, addAltitude) {
        }

        public DiamondSquareAverageCornerIsland(uint startX, uint startY, uint width, uint height, int minValue) :
            base(startX, startY, width, height, minValue) {
        }

        public DiamondSquareAverageCornerIsland(uint startX, uint startY, uint width, uint height, int minValue,
            int altitude) :
            base(startX, startY, width, height, minValue, altitude) {
        }

        public DiamondSquareAverageCornerIsland(uint startX, uint startY, uint width, uint height, int minValue,
            int altitude,
            int addAltitude) :
            base(startX, startY, width, height, minValue, altitude, addAltitude) {
        }
    }
}