/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/

using System.Collections.Generic;
using DTL.Range;
using DTL.Random;
using DTL.Util;
using MatrixRange = DTL.Base.Coordinate2DimensionalAndLength2Dimensional;

namespace DTL.Shape {

    public class HalfMixRect : RectBaseWithIList<HalfMixRect>, IDrawer<int> {
        RandomBase rand = new RandomBase();

        public bool Draw(int[,] matrix) {
            return this.DrawNormal(matrix);
        }

        private bool DrawNormal(int[,] matrix) {
            uint drawValueCount = (uint) this.drawValue.Count;
            var endX = this.CalcEndX(MatrixUtil.GetX(matrix));
            var endY = this.CalcEndY(MatrixUtil.GetY(matrix));
            for (var row = this.startY; row < endY; ++row)
                for (var col = this.startX; col < endX; ++col) 
                    matrix[row, col] 
                        = this.rand.Probability(0.5) ? 
                        this.drawValue[0] : this.drawValue[(int) rand.Next(drawValueCount)];
            return true;
        }

        /* Constructors */

        public HalfMixRect() {} // default

        public HalfMixRect(IList<int> drawValue) : base(drawValue) {    
        }

        public HalfMixRect(MatrixRange matrixRange, IList<int> drawValue) : base(matrixRange, drawValue) {
        }
    }
}