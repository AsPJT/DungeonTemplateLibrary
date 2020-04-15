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
using DTL.Console;

public class CellularAutomatonMixIslandGenerator : MonoBehaviour {

	public int width = 50;
	public int height = 50;
    public uint loopNum = 5;
	public List<int> list = new List<int>();
    CellularAutomatonMixIsland cellularAutomatonMixIsland;
	void Start () {
        var matrix = new int[height, width];
		cellularAutomatonMixIsland = new CellularAutomatonMixIsland(loopNum, list);
        cellularAutomatonMixIsland.Draw(matrix);
        new OutputConsole().Draw(matrix);
	}
}
