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
using DTL.Util;
using MatrixRange = DTL.Base.Coordinate2DimensionalAndLength2Dimensional;

namespace DTL.Shape {
    public class Border : RectBaseWithValue<Border>, IDrawer<int> {
        public bool Draw(int[,] matrix) {
            return DrawNormal(matrix);
        }

        public int[,] Create(int[,] matrix) {
            Draw(matrix);
            return matrix;
        }

        public bool DrawNormal(int[,] matrix) {
            var endX = this.CalcEndX(MatrixUtil.GetX(matrix));
            var endY = this.CalcEndY(MatrixUtil.GetY(matrix));
            if (endX <= startX || endY <= this.startY) return true;
            for (var col = startX; col < endX; ++col) {
                matrix[this.startY, col] = this.drawValue;
                matrix[endY - 1, col] = this.drawValue;
            }

            for (var row = this.startY; row < endY; ++row) {
                matrix[row, startX] = this.drawValue;
                matrix[row, endX - 1] = this.drawValue;
            }
            return true;
        }

        public Border() { } // = default();

        public Border(int drawValue, MatrixRange matrixRange) : base(drawValue, matrixRange) {
            this.drawValue = drawValue;
        }

        public Border(int drawValue, uint startX, uint startY, uint width, uint height) : base(drawValue, startX, startY, width,
            height) {
            this.drawValue = drawValue;
        }

        public Border(int drawValue) : base(drawValue) {
            this.drawValue = drawValue;
        }
    }
}