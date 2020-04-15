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

public class RandomVoronoiGenerator : MonoBehaviour {

    public int height = 50;
    public int width = 50;
    public int drawValue = 40;
    public int trueColor = 1;
    public int falseColor = 0;
    public double probability = 0.5;
    private RandomVoronoi randomVoronoi;

    // Use this for initialization
	void Start () {
        var matrix = new int[height, width];
		randomVoronoi = new RandomVoronoi(drawValue, probability, trueColor, falseColor);
        randomVoronoi.Draw(matrix);
        new OutputConsole().Draw(matrix);
    }
}
