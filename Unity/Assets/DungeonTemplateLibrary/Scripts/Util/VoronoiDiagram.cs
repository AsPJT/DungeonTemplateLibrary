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
using UnityEngine;
using DTL.Random;
using MatrixRange = DTL.Base.Coordinate2DimensionalAndLength2Dimensional;

namespace DTL.Util {
    public class VoronoiDiagram {
        RandomBase rand = new RandomBase();

        public uint startX { get; set; }
        public uint startY { get; set; }
        public uint width { get; set; }
        public uint height { get; set; }
        public int drawValue { get; set; }

        /* Draw */ 

        public bool Draw(int[,] matrix, DTLDelegate.VoronoiDiagramDelegate function_) {
            var lenX = MatrixUtil.GetX(matrix);
            var lenY = MatrixUtil.GetY(matrix);

            return this.DrawNormal(
                matrix,
                this.width == 0 || this.startX + this.width >= ((lenX == 0) ? 0 : lenX)
                    ? ((lenX == 0) ? 0 : lenX)
                    : this.startX + this.width,
                (this.height == 0 || this.startY + this.height >= lenY) ? lenY : this.startY + this.height,
                function_);
        }

        bool DrawNormal(int[,] matrix, uint endX, uint endY, DTLDelegate.VoronoiDiagramDelegate function_) {
            this.assignSTL(matrix, endX, endY, function_);
            return true;
        }

        private void assignSTL(int[,] matrix, uint endX, uint endY, DTLDelegate.VoronoiDiagramDelegate function_) {
            Pair[] point = new Pair[drawValue];
            int[] color = new int[drawValue];
            CreatePoint(point, color, endX, endY, function_);
            CreateSites(point, color, matrix, endX, endY);
        }

        private void CreateSites(Pair[] point, int[] color, int[,] matrix, uint w, uint h) {
            int ds = 0, dist = 0;
            for (int hh = 0, ind = 0; hh < h; ++hh) {
                for (var ww = 0; ww < w; ++ww) {
                    if (CreateSitesDistance(point, ref ind, ref dist, ref ds, ww, hh))
                        matrix[hh, ww] = color[ind];
                }
            }
        }

        private bool CreateSitesDistance(Pair[] point, ref int ind, ref int dist, ref int ds, int ww, int hh) {
            ind = int.MaxValue;
            dist = int.MaxValue;

            for (var it = 0; it < this.drawValue; ++it) {
                if ((ds = this.distanceSqrd(point[it], ww, hh)) >= dist) continue;
                dist = ds;
                ind = it;
            }

            return ind != int.MaxValue;
        }

        private int distanceSqrd(Pair pair, int x, int y) {
            x -= (int) pair.First;
            y -= (int) pair.Second;
            return x * x + y * y;
        }

        private void CreatePoint(Pair[] point, int[] color, uint w, uint h,
            DTLDelegate.VoronoiDiagramDelegate function_) {
            for (int arrayNum = 0; arrayNum < this.drawValue; ++arrayNum) {
                point[arrayNum] = new Pair((int)rand.Next(w), (int)rand.Next(h));
                function_(ref point[arrayNum], ref color[arrayNum], startX, startY, w, h);
            }
        }

        /* Create Dungeon Matrix */

        /*
        [ObsoleteAttribute("please use Draw Method", false)]
        public int[,] Create(int[,] matrix) {
            this.Draw(matrix);
            return matrix;
        }
        */

        /* Clear */

        public VoronoiDiagram ClearPointX() {
            this.startX = 0;
            return this;
        }

        public VoronoiDiagram ClearPointY() {
            this.startY = 0;
            return this;
        }

        public VoronoiDiagram ClearWidth() {
            this.width = 0;
            return this;
        }

        public VoronoiDiagram ClearHeight() {
            this.height = 0;
            return this;
        }

        public VoronoiDiagram ClearValue() {
            this.drawValue = 0;
            return this;
        }

        public VoronoiDiagram ClearPoint() {
            this.startX = 0;
            this.startY = 0;
            return this;
        }

        public VoronoiDiagram ClearRange() {
            this.ClearPointX();
            this.ClearPointY();
            this.ClearWidth();
            this.ClearHeight();
            return this;
        }

        public VoronoiDiagram Clear() {
            this.ClearRange();
            this.ClearValue();
            return this;
        }

        /* Setter */

        public VoronoiDiagram SetRange(uint startX, uint startY, uint length) {
            this.startX = startX;
            this.startY = startY;
            this.width = length;
            this.height = length;
            return this;
        }

        public VoronoiDiagram SetRange(uint startX, uint startY, uint width, uint height) {
            this.startX = startX;
            this.startY = startY;
            this.width = width;
            this.height = height;
            return this;
        }

        /* Constructors */

        public VoronoiDiagram() {
        } // default

        public VoronoiDiagram(int drawValue) {
            this.drawValue = drawValue;
        }

        public VoronoiDiagram(MatrixRange matrixRange) {
            this.startX = (uint) matrixRange.x;
            this.startY = (uint) matrixRange.y;
            this.width = (uint) matrixRange.w;
            this.height = (uint) matrixRange.h;
        }

        public VoronoiDiagram(MatrixRange matrixRange, int drawValue) {
            this.startX = (uint) matrixRange.x;
            this.startY = (uint) matrixRange.y;
            this.width = (uint) matrixRange.w;
            this.height = (uint) matrixRange.h;
            this.drawValue = drawValue;
        }

        public VoronoiDiagram(uint startX, uint startY, uint width, uint height) {
            this.startX = startX;
            this.startY = startY;
            this.width = width;
            this.height = height;
        }

        public VoronoiDiagram(uint startX, uint startY, uint width, uint height, int drawValue) {
            this.startX = startX;
            this.startY = startY;
            this.width = width;
            this.height = height;
            this.drawValue = drawValue;
        }
    }
}