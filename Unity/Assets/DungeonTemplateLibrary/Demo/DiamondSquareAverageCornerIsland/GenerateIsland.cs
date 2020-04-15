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

public class GenerateIsland : MonoBehaviour {
    public int height = 65;
    public int width = 65;

    public int minValue = 10;
    public int altitude = 100;
    public int addAltitude = 50;

    private DiamondSquareAverageCornerIsland diamondSquareAverageCornerIsland;

	void Start() {
        var matrix = new int[height, width];
	    diamondSquareAverageCornerIsland = new DiamondSquareAverageCornerIsland(minValue, altitude, addAltitude);
        diamondSquareAverageCornerIsland.Draw(matrix);

        new OutputConsole().Draw(matrix);
        new OutputConsole(arg => arg < 90, "..", "##").Draw(matrix);
    }
	
}
