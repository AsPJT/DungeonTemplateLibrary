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

// Terrainの生成, heightMapの生成など

using System.Collections.Generic;
using UnityEngine;
using DTL.Shape;

namespace DTL.Util {
    public class TerrainUtil {
        public Terrain terrain { get; private set; }
        public TerrainData terrainData { get; private set; }
        public List<float> textureToHeight { get; set; }
        public int depth { get; set; }
        public int width { get; set; }
        public int height { get; set; }
        public float[,] matrix { get; private set; }
        public uint smooth { get; set; }

        private List<Texture2D> texture2D;
        private ITerrainDrawer terrainGenerator;

        public void Draw() {
            Generate();
            SetTerrainData();
            float[,,] textureMap;
            terrainData.SetHeights(0, 0, matrix);
            if (this.texture2D.Count > 0) {
                textureMap = GetTexture(matrix, terrainData.alphamapWidth, terrainData.alphamapHeight);
                terrainData.SetAlphamaps(0, 0, textureMap);
            }
        }

        private void Generate() {
            matrix = new float[height, width];
            terrainGenerator.DrawNormalize(matrix);
            Smooth(matrix, smooth);
        }

        // 各種情報の設定
        private void SetTerrainData() {
            terrainData.size = new Vector3(width, depth, height);
            var alphaMapResolution = Mathf.Max(height, width);
            var heightMapResolution = Mathf.Max(height, width);
            var splatPrototypeArray = this.SetSplatPrototypes();
            SetResolutions(alphaMapResolution, heightMapResolution);
            terrainData.splatPrototypes = splatPrototypeArray;
        }

        // heightMapの解像度設定
        private void SetResolutions(int alphaR, int heightR) {
            this.terrainData.alphamapResolution = alphaR;
            this.terrainData.heightmapResolution = heightR;
        }

        // Textureの設定
        private SplatPrototype[] SetSplatPrototypes() {
            var len = this.texture2D.Count;
            var splatPrototype = new SplatPrototype[len];
            for (int i = 0; i < len; ++i) {
                splatPrototype[i] = new SplatPrototype();
                splatPrototype[i].tileSize = Vector2.one;
                splatPrototype[i].texture = texture2D[i];
            }

            return splatPrototype;
        }

        // HeightMapとテクスチャを対応させる
        private float[,,] GetTexture(float[,] matrix, int w, int h) {
            var map = new float[w, h, texture2D.Count];
            for (var y = 0; y < h; ++y) {
                for (var x = 0; x < h; ++x) {
                    var idx = LowerBound(this.textureToHeight, matrix[y, x]);
                    map[y, x, idx] = 1f;
                }
            }

            return map;
        }

        // binary search
        // list<T>.BinarySearchはstd::lower_boundのように動かないために自作
        // indexを返す
        private int LowerBound(List<float> list, float value) {
            var left = 0;
            var right = list.Count;
            while (left + 1 < right) {
                int mid = (left + right) / 2;
                if (value > list[mid]) {
                    left = mid;
                } else {
                    right = mid;
                }
            }

            return left;
        }

        // 最初にheightMapとテクスチャの関係が指定されなかったときに呼ばれる関数
        private void SetTextureToHeight() {
            var len = this.texture2D.Count;
            this.textureToHeight = new List<float>();
            var hValue = 0.0f;
            var dh = (float)1.0f / len;

            this.textureToHeight.Add(hValue);
            for (int i = 1; i < len; ++i)
                textureToHeight.Add(hValue + i * dh);

        }

        public void Smooth(float[,] heightMap, uint iterationNum) {
            // Height = height
            // Width = width
            // 周囲のマスと自分の高さから平均化

            var dh = new[] { 1, -1, 0, 0 };
            var dw = new[] { 0, 0, 1, -1 };
            for (int iter = 0; iter < iterationNum; ++iter) {
                for (var h = 0; h < height; ++h) {
                    for (var w = 0; w < width; ++w) {
                        // 配列の範囲内の8方向の高さを加算
                        var cumulative = 0;
                        float cumulativeValue = 0f;
                        for (int i = 0; i < 4; ++i) {
                            var nh = h + dh[i];
                            var nw = w + dw[i];

                            if (nh >= 0 && nw >= 0 && nh < height && nw < width) {
                                ++cumulative;
                                cumulativeValue += heightMap[nh, nw];
                            }
                        }

                        // 自分を足す
                        cumulativeValue += heightMap[h, w];
                        ++cumulative;

                        heightMap[h, w] = (float)cumulativeValue / cumulative;
                    }
                }
            }
        }

        public TerrainUtil(Terrain terrain, List<Texture2D> texture2D, ITerrainDrawer terrainGenerator,
            int height, int width, int depth, uint smooth = 0) {
            this.terrain = terrain;
            this.texture2D = texture2D;
            this.terrainGenerator = terrainGenerator;
            this.terrainData = terrain.terrainData;
            this.height = height;
            this.width = width;
            this.depth = depth;
            this.smooth = smooth;
            SetTextureToHeight();
        }

        public TerrainUtil(Terrain terrain, List<Texture2D> texture2D, ITerrainDrawer terrainGenerator,
            int height, int width, int depth, List<float> textureToHeight, uint smooth = 0) {
            this.terrain = terrain;
            this.texture2D = texture2D;
            this.terrainGenerator = terrainGenerator;
            this.terrainData = terrain.terrainData;
            this.textureToHeight = textureToHeight;
            this.height = height;
            this.width = width;
            this.depth = depth;
            this.smooth = smooth;
        }
    }
}