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

using DTL.Shape;
using DTL.Random;
using System.Collections.Generic;
using DTL.Util;
using UnityEngine;

public class GenerateFractalIslandTerrain : MonoBehaviour {
    public int depth = 50;
    public int width = 512;
    public int height = 512;
    public int minValue = 10;
    public int altitude = 60;
    public int addAltitude = 10;

    private Terrain terrain;
    private FractalIsland fractalIsland;
    private XorShift128 rand = new XorShift128();

    public List<Texture2D> texture2D = new List<Texture2D>();

    void Start() {
        fractalIsland = new FractalIsland(minValue, altitude, addAltitude);
        this.terrain = GetComponent<Terrain>();
        TerrainUtil terrainUtil = new TerrainUtil(terrain, texture2D, fractalIsland, height, width, depth, 2);
        terrainUtil.Draw();
    }
}