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

using DTL.Console;
using DTL.Shape;
using UnityEngine;

public class SimpleVoronoiGenerator : MonoBehaviour {

    public int height = 50;
    public int width = 50;
    public int landValue = 1;
    public int seaValue = 0;
    public int voronoiPointNum = 40;
    public double probabilityValue = 0.5;
    SimpleVoronoiIsland simpleVoronoiIsland;
    
    void Start () {
        var matrix = new int[height, width];
        simpleVoronoiIsland = new SimpleVoronoiIsland(voronoiPointNum, probabilityValue, landValue, seaValue);
        simpleVoronoiIsland.Draw(matrix);
        new OutputConsole().Draw(matrix);
    }

}
