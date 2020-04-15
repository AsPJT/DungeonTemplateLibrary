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
using DTL.Util;
using DTL.Random;
using MatrixRange = DTL.Base.Coordinate2DimensionalAndLength2Dimensional;

namespace DTL.Retouch {

    // マスを指定した数値で埋める
    public class CellularAutomaton : RectBase<CellularAutomaton>, IDrawer<int> {

        RandomBase rand = new RandomBase();

        public bool Draw(int[,] matrix) {
            return DrawNormal(matrix);
        }

        /**
         * Do CellAutomaton
         */
        private void Assign(int[,] matrix, uint col, uint row) {
            if (matrix[row, col - 1] == matrix[row, col + 1] &&
                matrix[row, col + 1] == matrix[row - 1, col] &&
                matrix[row - 1, col] == matrix[row + 1, col])
                matrix[row, col] = matrix[row, col + 1];
            else
                switch (rand.Next(4)) {
                    case 0:
                        matrix[row, col] = matrix[row, col - 1];
                        break;
                    case 1:
                        matrix[row, col] = matrix[row, col + 1];
                        break;
                    case 2:
                        matrix[row, col] = matrix[row - 1, col];
                        break;
                    case 3:
                        matrix[row, col] = matrix[row + 1, col];
                        break;
                }
        }

        private bool DrawNormal(int[,] matrix) {
            var endX = this.CalcEndX(MatrixUtil.GetX(matrix)) - 1;
            var endY = this.CalcEndY(MatrixUtil.GetY(matrix)) - 1;
            for (var row = this.startY + 1; row < endY; ++row) {
                for (var col = this.startX + 1; col < endX; ++col)
                    Assign(matrix, col, row);
            }

            return true;
        }

        public CellularAutomaton() {
        } // = default()

        public CellularAutomaton(MatrixRange matrixRange) : base(matrixRange) {
        }

        public CellularAutomaton(uint startX, uint startY, uint width, uint height) : base(startX, startY, width, height) {
        }
    }
}