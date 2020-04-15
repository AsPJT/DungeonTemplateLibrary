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
using DTL.Random;
using DTL.Shape;
using MatrixRange = DTL.Base.Coordinate2DimensionalAndLength2Dimensional;
using System;
using UnityEngine;

/**
 * Fractal Island
 * Diamond Square法を使って地形を生成する。
 * 本家のコードはリファクタ前？DrawJaggedとかを継承していない、TMPを使用していないなど
 * PerlinNoiseなどの実装に合わせる
 */

namespace DTL.Shape {
    public sealed class FractalIsland : RectBaseFractal<FractalIsland>, IDrawer<int>, ITerrainDrawer {
        private XorShift128 rand = new XorShift128();

        // fractal island の１チャンクの大きさ
        // Diamond Square は2^N + 1 * 2^N + 1 の大きさしかにしかheightmapをレンダーできない。
        private readonly int fiChunkSize = 16;

        public bool Draw(int[,] matrix) {
            return DrawNormal(matrix);
        }

        public bool DrawNormalize(float[,] matrix) {
            int[,] convertedMatrix = new int[matrix.GetLength(0), matrix.GetLength(1)];

            // I cannot use LINQ for 2 dim array. Please tell me how to use LINQ for 2 dim array...orz
            for (int y = 0; y < MatrixUtil.GetY(matrix); ++y) {
                for (int x = 0; x < MatrixUtil.GetX(matrix); ++x) {
                    convertedMatrix[y, x] = (int)matrix[y, x];
                }
            }

            DrawNormal(convertedMatrix);
            Normalize(convertedMatrix, matrix);
            return true;
        }

        public int[,] Create(int[,] matrix) {
            this.Draw(matrix);
            return matrix;
        }

        private void Normalize(int[,] matrix, float[,] retMatrix) {
            var maxHeight = MatrixUtil.GetMax(matrix);

            for (int y = 0; y < MatrixUtil.GetY(matrix); ++y) {
                for (int x = 0; x < MatrixUtil.GetX(matrix); ++x) {
                    retMatrix[y, x] = (float)matrix[y, x] / maxHeight;
                }
            }
        }

        private bool DrawNormal(int[,] matrix) {
            var chunkMatrix = new int[fiChunkSize + 1, fiChunkSize + 1];
            var endX = CalcEndX(MatrixUtil.GetX(matrix));
            var endY = CalcEndY(MatrixUtil.GetY(matrix));

            if (this.altitude < 2) return false;

            int chunkX = (int) (endX - this.startX) / fiChunkSize;
            int chunkY = (int) (endY - this.startY) / fiChunkSize;

            var randUp = new int[chunkX + 1];
            var randDown = new int[chunkX + 1]; // バグ？(ではないっぽい)

            for (var col = 0; col <= chunkX; ++col) {
                randUp[col] = 0;
            }

            for (var row = 0; row < chunkY; ++row) {
                if (row + 1 == chunkY) {
                    for (var col = 0; col <= chunkX; ++col) {
                        randDown[col] = 0;
                    }
                }
                else { 
                    for (var col = 1; col < chunkX; ++col) {
                        randDown[col] = (int) rand.Next((uint) this.altitude);
                    }

                    randDown[0] = 0;
                    randDown[chunkX] = randDown[0];
                }

                for (var col = 0; col < chunkX; ++col) {
                    chunkMatrix[0, 0] = randUp[col];
                    chunkMatrix[fiChunkSize, 0] = randDown[col];
                    chunkMatrix[0, fiChunkSize] = randUp[col + 1];
                    chunkMatrix[fiChunkSize, fiChunkSize] = randDown[col + 1];

                    // 地形の生成
                    this.CreateWorldMapSimple(chunkMatrix);

                    for (var row2 = 0; row2 < fiChunkSize; ++row2) {
                        for (var col2 = 0; col2 < fiChunkSize; ++col2) {
                            matrix[this.startY + row * fiChunkSize + row2, startX + col * fiChunkSize + col2] =
                                chunkMatrix[row2, col2];
                        }
                    }
                }

                for (var col = 0; col <= chunkX; ++col) {
                    randUp[col] = randDown[col];
                }
            }

            return true;
        }

        private void CreateWorldMapSimple(int[,] chunkMatrix) {
            CreateWorldMap(chunkMatrix, (int x) => x / 2);
        }

        private void CreateWorldMap(int[,] chunkMatrix, Func<int, int> func) {
            DiamondSquareAverage.CreateDiamondSquareAverage(chunkMatrix, 0, 0, (uint)fiChunkSize / 2, (uint)fiChunkSize / 2,
                (uint)fiChunkSize / 2, chunkMatrix[0, 0], chunkMatrix[fiChunkSize, 0], chunkMatrix[0, fiChunkSize],
                chunkMatrix[fiChunkSize, fiChunkSize], this.minValue + this.altitude, this.addAltitude, rand, func
            );
        }

        /* constructors */

        public FractalIsland() {
        } // = default()

        public FractalIsland(uint startX, uint startY, uint width, uint height) :
            base(startX, startY, width, height) {
        }

        public FractalIsland(int minValue) : base(minValue) {
        }

        public FractalIsland(int minValue, int altitude) : base(minValue, altitude) {
        }

        public FractalIsland(int minValue, int altitude, int addAltitude) : base(minValue, altitude, addAltitude) {
        }

        public FractalIsland(MatrixRange matrixRange, int minValue) : base(matrixRange, minValue) {
        }

        public FractalIsland(MatrixRange matrixRange, int minValue, int altitude) : base(matrixRange, minValue,
            altitude) {
        }

        public FractalIsland(MatrixRange matrixRange, int minValue, int altitude, int addAltitude) : base(matrixRange,
            minValue, altitude, addAltitude) {
        }

        public FractalIsland(uint startX, uint startY, uint width, uint height, int minValue) :
            base(startX, startY, width, height, minValue) {
        }

        public FractalIsland(uint startX, uint startY, uint width, uint height, int minValue, int altitude) :
            base(startX, startY, width, height, minValue, altitude) {
        }

        public FractalIsland(uint startX, uint startY, uint width, uint height, int minValue, int altitude,
            int addAltitude) :
            base(startX, startY, width, height, minValue, altitude, addAltitude) {
        }
    }
}