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

using DTL.Random;
using DTL.Util;
using MatrixRange = DTL.Base.Coordinate2DimensionalAndLength2Dimensional;

namespace DTL.Shape {
    public class RandomVoronoi : IDrawer<int> {
        private RandomBase rand = new RandomBase();
        private VoronoiDiagram voronoiDiagram;
        public double probabilityValue { get; set; }
        public int trueColor { get; set; }
        public int falseColor { get; set; }

        public bool Draw(int[,] matrix) {
            DTLDelegate.VoronoiDiagramDelegate voronoiDiagramDelegate =
                (ref Pair point, ref int color, uint startX, uint startY, uint w, uint h) => {
                    if (rand.Probability((this.probabilityValue)))
                        color = this.trueColor;
                    else
                        color = this.falseColor;
                };

            voronoiDiagram.Draw(matrix, voronoiDiagramDelegate);
            return true;
        }

        public int[,] Create(int[,] matrix) {
            this.Draw(matrix);
            return matrix;
        }

        /* Getter */
        public uint GetPointX() {
            return voronoiDiagram.startX;
        }

        public uint GetPointY() {
            return voronoiDiagram.startY;
        }

        public uint GetWidth() {
            return voronoiDiagram.width;
        }

        public uint GetHeight() {
            return voronoiDiagram.height;
        }

        public int GetValue() {
            return voronoiDiagram.drawValue;
        }

        /* Setter */
        public RandomVoronoi SetPointX(uint value) {
            this.voronoiDiagram.startX = value;
            return this;
        }

        public RandomVoronoi SetPointY(uint value) {
            voronoiDiagram.startY = value;
            return this;
        }

        public RandomVoronoi SetWidth(uint value) {
            voronoiDiagram.width = value;
            return this;
        }

        public RandomVoronoi SetHeight(uint value) {
            voronoiDiagram.height = value;
            return this;
        }

        public RandomVoronoi SetPoint(uint value) {
            voronoiDiagram.startX = value;
            voronoiDiagram.startY = value;
            return this;
        }

        public RandomVoronoi SetPoint(uint startX, uint startY) {
            voronoiDiagram.startX = startX;
            voronoiDiagram.startY = startY;
            return this;
        }

        public RandomVoronoi SetRange(uint startX, uint startY, uint width, uint height) {
            voronoiDiagram.startX = startX;
            voronoiDiagram.startY = startY;
            voronoiDiagram.width = width;
            voronoiDiagram.height = height;
            return this;
        }

        public RandomVoronoi SetRange(MatrixRange matrixRange) {
            voronoiDiagram.startX = (uint) matrixRange.x;
            voronoiDiagram.startY = (uint) matrixRange.y;
            voronoiDiagram.width = (uint) matrixRange.w;
            voronoiDiagram.height = (uint) matrixRange.h;
            return this;
        }


        /* Clear */

        public RandomVoronoi ClearPointX() {
            this.voronoiDiagram.ClearPointX();
            return this;
        }

        public RandomVoronoi ClearPointY() {
            this.voronoiDiagram.ClearPointY();
            return this;
        }

        public RandomVoronoi ClearWidth() {
            this.voronoiDiagram.ClearWidth();
            return this;
        }

        public RandomVoronoi ClearHeight() {
            this.voronoiDiagram.ClearHeight();
            return this;
        }

        public RandomVoronoi ClearValue() {
            this.voronoiDiagram.ClearValue();
            return this;
        }

        public RandomVoronoi ClearPoint() {
            this.ClearPointX();
            this.ClearPointY();
            return this;
        }

        public RandomVoronoi ClearRange() {
            this.ClearPointX();
            this.ClearPointY();
            this.ClearWidth();
            this.ClearHeight();
            return this;
        }

        public RandomVoronoi Clear() {
            this.ClearRange();
            this.ClearValue();
            return this;
        }

        /* Constructors */

        public RandomVoronoi() {
            voronoiDiagram = new VoronoiDiagram();
        } // default

        public RandomVoronoi(int drawValue) {
            voronoiDiagram = new VoronoiDiagram(drawValue);
        }

        public RandomVoronoi(int drawValue, double probabilityValue) {
            voronoiDiagram = new VoronoiDiagram(drawValue);
            this.probabilityValue = probabilityValue;
        }

        public RandomVoronoi(int drawValue, double probabilityValue, int trueColor) {
            voronoiDiagram = new VoronoiDiagram(drawValue);
            this.probabilityValue = probabilityValue;
            this.trueColor = trueColor;
        }

        public RandomVoronoi(int drawValue, double probabilityValue, int trueColor, int falseColor) {
            voronoiDiagram = new VoronoiDiagram(drawValue);
            this.probabilityValue = probabilityValue;
            this.trueColor = trueColor;
            this.falseColor = falseColor;
        }

        public RandomVoronoi(MatrixRange matrixRange) {
            voronoiDiagram = new VoronoiDiagram(matrixRange);
        }

        public RandomVoronoi(MatrixRange matrixRange, int drawValue) {
            voronoiDiagram = new VoronoiDiagram(matrixRange, drawValue);
        }

        public RandomVoronoi(MatrixRange matrixRange, int drawValue, double probabilityValue) {
            voronoiDiagram = new VoronoiDiagram(matrixRange, drawValue);
            this.probabilityValue = probabilityValue;
        }

        public RandomVoronoi(MatrixRange matrixRange, int drawValue, double probabilityValue, int trueColor) {
            voronoiDiagram = new VoronoiDiagram(matrixRange, drawValue);
            this.probabilityValue = probabilityValue;
            this.trueColor = trueColor;
        }

        public RandomVoronoi(MatrixRange matrixRange, int drawValue, double probabilityValue, int trueColor,
            int falseColor) {
            voronoiDiagram = new VoronoiDiagram(matrixRange, drawValue);
            this.probabilityValue = probabilityValue;
            this.trueColor = trueColor;
            this.falseColor = falseColor;
        }
    }
}