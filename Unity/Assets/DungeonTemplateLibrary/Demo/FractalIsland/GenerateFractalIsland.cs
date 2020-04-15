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

public class GenerateFractalIsland : MonoBehaviour {
    public int width = 48;
    public int height = 48;
    public int minValue = 10;
    public int altitude = 150;
    public int addAltitude = 75;

    private FractalIsland fractalIsland;

	void Start () {
        var matrix = new int[height, width];
		fractalIsland = new FractalIsland(minValue, altitude, addAltitude);
        fractalIsland.Draw(matrix);

        new OutputConsole().Draw(matrix);
        new OutputConsole(arg => arg < 100, "..", "##").Draw(matrix);
    }

}
