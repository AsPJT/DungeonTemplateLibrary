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
using UnityEngine;
using DTL.Shape;
using DTL.Util;

public class GenerateDiamondSquareAverageCornerIsland : MonoBehaviour {
    public int depth = 200;
    public int width = 512;
    public int height = 512;
    public int minValue = 10;
    public int altitude = 100;
    public int addAltitude = 200;

    private Terrain terrain;
    private DiamondSquareAverageCornerIsland diamondSquareAverageCornerIsland;

    public List<Texture2D> texture2D = new List<Texture2D>();

    void Start() {
        diamondSquareAverageCornerIsland = new DiamondSquareAverageCornerIsland(minValue, altitude, addAltitude);
        this.terrain = GetComponent<Terrain>();
        TerrainUtil terrainUtil =
            new TerrainUtil(terrain, texture2D, diamondSquareAverageCornerIsland, height + 1, width + 1, depth);
        terrainUtil.Draw();
    }
}