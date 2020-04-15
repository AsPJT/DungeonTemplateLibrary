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
using DTL.Retouch;
using MatrixRange = DTL.Base.Coordinate2DimensionalAndLength2Dimensional;

namespace DTL.Shape {
    public class CellularAutomatonMixIsland : IDrawer<int> {
        private CellularAutomaton cellularAutomaton = new CellularAutomaton();
        Border border = new Border();
        HalfMixRect mixRect;
        protected uint loopNum = 1;

        public bool Draw(int[,] matrix) {
            this.mixRect.Draw(matrix);
            this.border.Draw(matrix);
            for (var i = 0; i < this.loopNum; ++i) 
                this.cellularAutomaton.Draw(matrix);
            return true;
        }

        /* Create Dungeon Matrix ダンジョン行列生成  */

        public int[,] Create(int[,] matrix) {
            this.Draw(matrix);
            return matrix;
        }

        /* Getter */

        public uint GetPointX() {
            return this.border.GetPointX();
        }

        public uint GetPointY() {
            return this.border.GetPointY();
        }

        public uint GetWidth() {
            return this.border.GetWidth();
        }

        public uint Getheight() {
            return this.border.GetHeight();
        }

// Todo GetValue()
/*        public uint GetValue() {
            return this.border.GetValue();
        }*/

        /* Setter */

        public CellularAutomatonMixIsland SetPointX(uint endX) {
            this.mixRect.SetPointX(endX);
            this.border.SetPointX(endX);
            this.cellularAutomaton.SetPointX(endX);
            return this;
        }

        public CellularAutomatonMixIsland SetPointY(uint endY) {
            this.mixRect.SetPointY(endY);
            this.border.SetPointY(endY);
            this.cellularAutomaton.SetPointY(endY);
            return this;
        }

        public CellularAutomatonMixIsland SetWidth(uint width) {
            this.mixRect.SetWidth(width);
            this.border.SetWidth(width);
            this.cellularAutomaton.SetWidth(width);
            return this;
        }

        public CellularAutomatonMixIsland SetHeight(uint height) {
            this.mixRect.SetHeight(height);
            this.border.SetHeight(height);
            this.cellularAutomaton.SetHeight(height);
            return this;
        }

        /*public CellularAutomatonMixIsland setValue() {
            this.mixRect.setValue()
        }*/

        public CellularAutomatonMixIsland SetRange(MatrixRange matrixRange) {
            this.mixRect.SetRange(matrixRange);
            this.border.SetRange(matrixRange);
            this.cellularAutomaton.SetRange(matrixRange);
            return this;
        }

        public CellularAutomatonMixIsland SetRange(uint endX, uint endY, uint length) { 
            this.SetPointX(endX);
            this.SetPointY(endY);
            this.SetWidth(length);
            this.SetHeight(length);
            return this;
        }

        public CellularAutomatonMixIsland SetRange(uint endX, uint endY, uint width, uint height) { 
            this.SetPointX(endX);
            this.SetPointY(endY);
            this.SetWidth(width);
            this.SetHeight(height);
            return this;
        }

        public CellularAutomatonMixIsland SetPoint(uint point) {
            this.SetPointX(point);
            this.SetPointY(point);
            return this;
        }

        public CellularAutomatonMixIsland SetPoint(uint endX, uint endY) {
            this.SetPointX(endX);
            this.SetPointY(endY);
            return this;
        }

        /* Clear */

        public CellularAutomatonMixIsland ClearPointX() {
            this.mixRect.ClearPointX();
            this.border.ClearPointX();
            this.cellularAutomaton.ClearPointX();
            return this;
        }

        public CellularAutomatonMixIsland ClearPointY() {
            this.mixRect.ClearPointY();
            this.border.ClearPointY();
            this.cellularAutomaton.ClearPointY();
            return this;
        }

        public CellularAutomatonMixIsland ClearWidth() {
            this.mixRect.ClearWidth();
            this.border.ClearWidth();
            this.cellularAutomaton.ClearWidth();
            return this;
        }

        public CellularAutomatonMixIsland ClearHeight() {
            this.mixRect.ClearHeight();
            this.border.ClearHeight();
            this.cellularAutomaton.ClearHeight();
            return this;
        }

        public CellularAutomatonMixIsland ClearValue() {
            this.mixRect.ClearValue();
            this.border.ClearValue();
            // this.cellularAutomaton.ClearValue(); DTL版 (存在するか？)
            this.cellularAutomaton.Clear(); // CellularAutomatonにClearValueのシグネチャを見つけられない
            return this;
        }

        public CellularAutomatonMixIsland ClearRange() {
            this.mixRect.ClearRange();
            this.border.ClearRange();
            this.cellularAutomaton.ClearPointY();
            return this;
        }

        public CellularAutomatonMixIsland ClearPoint() {
            this.ClearPointX();
            this.ClearPointY();
            return this;
        }

        /* Constructors */

        public CellularAutomatonMixIsland() {
            this.mixRect = new HalfMixRect();
        } // default

        public CellularAutomatonMixIsland(uint loopNum, IList<int> list) {
            this.loopNum = loopNum;
            this.mixRect = new HalfMixRect(list);
        }

        public CellularAutomatonMixIsland(MatrixRange matrixRange, uint loopNum, IList<int> list) {
            this.loopNum = loopNum;
            this.mixRect = new HalfMixRect(matrixRange, list);
            this.cellularAutomaton = new CellularAutomaton(matrixRange);
        }
    }
}