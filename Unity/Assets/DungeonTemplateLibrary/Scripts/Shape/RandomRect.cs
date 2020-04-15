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
using DTL.Util;
using MatrixRange = DTL.Base.Coordinate2DimensionalAndLength2Dimensional;

// 1bitの値を詰め込んだ行列を生成する生成器
namespace DTL.Shape {
    public class RandomRect : IDrawer<int> {
        private RandomBase randBase = new RandomBase();

        public uint startX { get; set; }
        public uint startY { get; set; }
        public uint width { get; set; }
        public uint height { get; set; }
        public int drawValue { get; set; }
        private double probabilityValue = 0.5;

        public bool Draw(int[,] matrix) { 
            return (this.width == 0)
                ? this.DrawSTL(matrix,
                    (this.height == 0 || this.startY + this.height >= MatrixUtil.GetY(matrix))
                        ? MatrixUtil.GetY(matrix)
                        : this.startY + this.height)
                : this.DrawWidthSTL(matrix, this.startX + this.width,
                    (this.height == 0 || this.startY + this.height >= MatrixUtil.GetY(matrix))
                        ? MatrixUtil.GetY(matrix)
                        : this.startY + this.height);
        }

        public bool DrawOperator(int[,] matrix, Func<int, bool> func) {
            return (this.width == 0)
                ? this.DrawSTL(matrix,
                    (this.height == 0 || this.startY + this.height >= MatrixUtil.GetY(matrix))
                        ? MatrixUtil.GetY(matrix)
                        : this.startY + this.height, func)
                : this.DrawWidthSTL(matrix, this.startX + this.width,
                    (this.height == 0 || this.startY + this.height >= MatrixUtil.GetY(matrix))
                        ? MatrixUtil.GetY(matrix)
                        : this.startY + this.height, func);
        }

        public int[,] Create(int[,] matrix) {
            this.Draw(matrix);
            return matrix;
        }

        public int[,] Create(int[,] matrix, Func<int, bool> func) {
            this.DrawOperator(matrix, func);
            return matrix;
        }

        private bool DrawSTL(int[,] matrix, uint endY) {
            for (var row = this.startY; row < endY; ++row)
            for (var col = this.startX; col < MatrixUtil.GetX(matrix, (int)row); ++col)
                this.AssignSTL(matrix, col, row);
            return true;
        }

        private bool DrawWidthSTL(int[,] matrix, uint endX, uint endY) {
            for (var row = this.startY; row < endY; ++row)
            for (var col = this.startX; col < MatrixUtil.GetX(matrix, (int)row) && col < endX; ++col)
                this.AssignSTL(matrix, col, row);
            return true;
        }

        private bool DrawSTL(int[,] matrix, uint endY, Func<int, bool> func) {
            for (var row = this.startY; row < endY; ++row)
            for (var col = this.startX; col < MatrixUtil.GetX(matrix, (int)row); ++col)
                this.AssignSTL(matrix, col, row, func);
            return true;
        }

        private bool DrawWidthSTL(int[,] matrix, uint endX, uint endY, Func<int, bool> func) {
            for (var row = this.startY; row < endY; ++row)
            for (var col = this.startX; col < MatrixUtil.GetX(matrix, (int)row) && col < endX; ++col)
                this.AssignSTL(matrix, col, row, func);
            return true;
        }


        private void AssignSTL(int[,] matrix, uint endX, uint endY) {
            if (randBase.Probability(probabilityValue)) matrix[endY, endX] = this.drawValue;
        }

        private void AssignSTL(int[,] matrix, uint endX, uint endY, Func<int, bool> func) {
            if (func(matrix[endY, endX]) && randBase.Probability(probabilityValue)) matrix[endY, endX] = this.drawValue;
        }

        /* Constructors */
        public RandomRect() { } // = default()

        public RandomRect(int drawValue) {
            this.drawValue = drawValue;
        }

        public RandomRect(int drawValue, double probabilityValue) {
            this.drawValue = drawValue;
            this.probabilityValue = probabilityValue;
        }


        public RandomRect(MatrixRange matrixRange) {
            this.startX = (uint) matrixRange.x;
            this.startY = (uint) matrixRange.y;
            this.width = (uint) matrixRange.w;
            this.height = (uint) matrixRange.h;
        }

        public RandomRect(MatrixRange matrixRange, int drawValue) {
            this.startX = (uint)matrixRange.x;
            this.startY = (uint)matrixRange.y;
            this.width = (uint)matrixRange.w;
            this.height = (uint)matrixRange.h;
            this.drawValue = drawValue;
        }

        public RandomRect(MatrixRange matrixRange, int drawValue, double probabilityValue) {
            this.startX = (uint)matrixRange.x;
            this.startY = (uint)matrixRange.y;
            this.width = (uint)matrixRange.w;
            this.height = (uint)matrixRange.h;
            this.drawValue = drawValue;
            this.probabilityValue = probabilityValue;
        }

        public RandomRect(uint endX, uint endY, uint width, uint height) {
            this.startX = endX;
            this.startY = endY;
            this.width = width;
            this.height = height;
        }

        public RandomRect(uint endX, uint endY, uint width, uint height, int drawValue) {
            this.startX = endX;
            this.startY = endY;
            this.width = width;
            this.height = height;
            this.drawValue = drawValue;
        }

        public RandomRect(uint endX, uint endY, uint width, uint height, int drawValue, double probabilityValue) {
            this.startX = endX;
            this.startY = endY;
            this.width = width;
            this.height = height;
            this.drawValue = drawValue;
            this.probabilityValue = probabilityValue;
        }
    } // namespace DTL.Shape
}