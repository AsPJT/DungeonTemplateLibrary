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
    public class AscendingOrder : RectBaseWithValue<AscendingOrder>, IDrawer<int> {
        public bool Draw(int[,] matrix) {
            return DrawNormal(matrix);
        }

        public int[,] Create(int[,] matrix) {
            this.Draw(matrix);
            return matrix;
        }
        
        private bool DrawNormal(int[,] matrix) {
            var value = this.drawValue;
            var endX = this.CalcEndX(MatrixUtil.GetX(matrix));
            var endY = this.CalcEndY(MatrixUtil.GetY(matrix));
            for (var row = startY; row < endY; ++row)
                for (var col = startX; col < endX; ++col, value++)
                    matrix[row, col] = value;

            return true;
        }


        public AscendingOrder() { } // = default();

        public AscendingOrder(int drawValue, MatrixRange matrixRange) : base(drawValue, matrixRange) {
            this.drawValue = drawValue;
        }

        public AscendingOrder(int drawValue, uint startX, uint startY, uint width, uint height) : base(drawValue, startX, startY, width,
            height) {
            this.drawValue = drawValue;
        }

        public AscendingOrder(int drawValue) : base(drawValue) {
            this.drawValue = drawValue;
        }

    }
}