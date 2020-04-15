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

public class GenerateBorderOdd : MonoBehaviour {

    public int height = 16;
    public int width = 12;
    public int drawValue = 5;

    void Start () {
		BorderOdd borderOdd = new BorderOdd(drawValue);
        var matrix = new int[height, width];
        var matrix2 = new int[height - 1, width - 1];
        borderOdd.Draw(matrix);
        borderOdd.Draw(matrix2);
        new OutputConsole().Draw(matrix);
        new OutputConsole().Draw(matrix2);
    }
}
