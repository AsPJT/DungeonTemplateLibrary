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
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using UnityEditor;


namespace DTL.Base {

    /*#######################################################################################
        [概要] 'Coordinate2Dimensional' は2次元の座標を表すクラス。
        [Summary] 'Coordinate2Dimensional' represents 2D coordinates.
    #######################################################################################*/
    public class Coordinate2Dimensional : IEquatable<Coordinate2Dimensional> {
        public int x { get; set; }
        public int y { get; set; }

        public Coordinate2Dimensional(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public bool Equals(Coordinate2Dimensional others) {
            if (others == null || !this.GetType().Equals(others.GetType())) {
                return false;
            }

            return x.Equals(others.x) && y.Equals(others.y);
        }

        public override bool Equals(object obj) {
            return Equals(obj);
        }

        public static bool operator ==(Coordinate2Dimensional lhs, Coordinate2Dimensional rhs) {
            return lhs != null && lhs.Equals(rhs);
        }

        public static bool operator !=(Coordinate2Dimensional lhs, Coordinate2Dimensional rhs) {
            return lhs != null && !lhs.Equals(rhs);
        }
    }
}
