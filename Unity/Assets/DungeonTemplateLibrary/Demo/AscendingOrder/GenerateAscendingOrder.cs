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

public class GenerateAscendingOrder : MonoBehaviour {
    public int height = 15;
    public int width = 10;
    public int value = 1;

    private void Start() {
        var matrix = new int[height, width];
        AscendingOrder ascendingOrder = new AscendingOrder(value);
        ascendingOrder.Draw(matrix);

        new OutputConsole().Draw(matrix);
    }
}
