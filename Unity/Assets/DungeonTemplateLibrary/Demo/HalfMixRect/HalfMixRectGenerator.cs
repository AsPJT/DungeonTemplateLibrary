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
using DTL.Console;
using DTL.Shape;
using UnityEngine;

public class HalfMixRectGenerator : MonoBehaviour {
    public int width = 40;
    public int height = 40;
    public List<int> outputList = new List<int>();

    private HalfMixRect halfMixRect;

	void Start () {
        var matrix = new int[height, width];
        halfMixRect = new HalfMixRect(outputList);
        halfMixRect.Draw(matrix);
        new OutputConsole().Draw(matrix);
    }

}
