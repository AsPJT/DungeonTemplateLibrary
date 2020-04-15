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

using UnityEngine;
using DTL.Shape;
using DTL.Console;

public class GenerateDiamondSquareAverageIsland : MonoBehaviour {
    public int height = 66;
    public int width = 66;
    public int minWidth = 10;
    public int altitude = 30;
    public int addAltitude = 20;

    private DiamondSquareAverageIsland diamondSquareAverageIsland;

	void Start () {
        var matrix = new int[height, width];
        diamondSquareAverageIsland = new DiamondSquareAverageIsland(minWidth, altitude, addAltitude);
        diamondSquareAverageIsland.Draw(matrix);

        new OutputConsole().Draw(matrix);
        new OutputConsole(arg => arg < (altitude + addAltitude) / 2 + minWidth , "..", "##").Draw(matrix);
    }

}
