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

public class GeneratingMaze : MonoBehaviour {

    public int height = 30;
    public int width = 30;

    [SerializeField] public GameObject road;
    [SerializeField] public GameObject wall;

	void Start () {
        var matrix = new int[height, width];
        ClusteringMaze clusteringMaze = new ClusteringMaze(1);
        clusteringMaze.Draw(matrix);
        InstantiateMaze(matrix);
    }

    void InstantiateMaze(int[,] matrix) {
        for (var i = 0; i < matrix.GetLength(0); ++i) {
            for (var j = 0; j < matrix.GetLength(1); ++j) {
                if (matrix[i, j] == 1) {
                    // road
                    Instantiate(road, new Vector3(j, 0, i), Quaternion.identity);
                }
                else {
                    // wall
                    Instantiate(wall, new Vector3(j, 0, i), Quaternion.identity);
                }
            }
        }
    }
}
