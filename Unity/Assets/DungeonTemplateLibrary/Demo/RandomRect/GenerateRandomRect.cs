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
using UnityEngine;
using DTL.Shape;

public class GenerateRandomRect : MonoBehaviour {
    public int width = 16;
    public int height = 20;
    public double probability = 0.5;
    public int drawValue = 1;

	void Start () {
        var matrix = new int[height, width];
        RandomRect randomRect = new RandomRect(drawValue, probability);
        randomRect.Draw(matrix);

        new OutputConsole().Draw(matrix);
        new OutputConsole(x => x < 1, "//", "##").Draw(matrix);
    }
}
