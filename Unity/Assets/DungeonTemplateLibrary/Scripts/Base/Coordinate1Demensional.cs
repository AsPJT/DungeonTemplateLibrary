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

using System;
using System.Collections;

namespace DTL.Base {
    /*#######################################################################################
        [概要] 'Coordinate1Dimensional' は1次元の座標を表すクラス。
        [Summary] 'Coordinate1Dimensional' represents 1D coordinates.
    #######################################################################################*/
    public class Coordinate1Dimensional {
        public int x { get; set; }

        Coordinate1Dimensional(int x) {
            this.x = x;
        }
    }
}
