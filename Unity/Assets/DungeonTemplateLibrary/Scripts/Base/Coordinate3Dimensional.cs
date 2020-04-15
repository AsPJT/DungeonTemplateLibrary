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

namespace DTL.Base {
    /*#######################################################################################
        [概要] 'Coordinate3Dimensional' は3次元の座標を表すクラス。
        [Summary] 'Coordinate3Dimensional' represents 3D coordinates.
    #######################################################################################*/
    public class Coordinate3Dimensional : IEquatable<Coordinate3Dimensional> {
        public int x { get; set; }
        public int y { get; set; }
        public int z { get; set; }

        public Coordinate3Dimensional(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public bool Equals(Coordinate3Dimensional others) {
            if (others == null || this.GetType().Equals(others.GetType())) {
                return false;
            }

            return x.Equals(others.x) && y.Equals(others.y) && z.Equals(others.z);
        }

        public override bool Equals(object obj) {
            return Equals(obj);
        }

        public static bool operator ==(Coordinate3Dimensional lhs, Coordinate3Dimensional rhs) {
            return lhs != null && lhs.Equals(rhs);
        }

        public static bool operator !=(Coordinate3Dimensional lhs, Coordinate3Dimensional rhs) {
            return lhs != null && !lhs.Equals(rhs);
        }
    }
}
