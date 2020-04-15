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

    public class Coordinate2DimensionalAndLength2Dimensional :
        IEquatable<Coordinate2DimensionalAndLength2Dimensional>,
        IComparable<Coordinate2DimensionalAndLength2Dimensional> {

        public int x { get; set; }
        public int y { get; set; }
        public int w { get; set; }
        public int h { get; set; }

        public Coordinate2DimensionalAndLength2Dimensional() { }

        public Coordinate2DimensionalAndLength2Dimensional(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public Coordinate2DimensionalAndLength2Dimensional(int x, int y, int w) : this(x, y) {
            this.w = w;
        }

        public Coordinate2DimensionalAndLength2Dimensional(int x, int y, int w, int h) : this(x, y, w) {
            this.h = h;
        }

        // Check 'Value Equation'
        public bool Equals(Coordinate2DimensionalAndLength2Dimensional others) {
            if (others == null) 
                return false;
        
            return (this.x.Equals(others.x) && this.y.Equals(others.y) && this.w.Equals(others.w) && this.h.Equals(others.h));
        }

        public override bool Equals(System.Object obj) {
            Coordinate2DimensionalAndLength2Dimensional coord2d = obj as Coordinate2DimensionalAndLength2Dimensional;
            if (coord2d == null) return false;
            return this.Equals(coord2d);
        }

        public int CompareTo(Coordinate2DimensionalAndLength2Dimensional other) {
            return w * h - other.w * other.h;
        }

        public static bool operator ==(Coordinate2DimensionalAndLength2Dimensional lhs,
            Coordinate2DimensionalAndLength2Dimensional rhs) {
            if((System.Object) lhs == null && (System.Object) rhs == null) 
                return System.Object.Equals(lhs, rhs);

            return lhs.Equals(rhs);
        }

        public static bool operator !=(Coordinate2DimensionalAndLength2Dimensional lhs,
            Coordinate2DimensionalAndLength2Dimensional rhs) {
            if((System.Object) lhs == null && (System.Object) rhs == null) 
                return System.Object.Equals(lhs, rhs);
            return (System.Object) lhs != null && !lhs.Equals(rhs);
        }

        public static bool operator >(Coordinate2DimensionalAndLength2Dimensional lhs,
            Coordinate2DimensionalAndLength2Dimensional rhs) {
            return (System.Object) lhs != null && (System.Object) rhs != null && lhs.CompareTo(rhs) > 0;
        }

        public static bool operator <(Coordinate2DimensionalAndLength2Dimensional lhs,
            Coordinate2DimensionalAndLength2Dimensional rhs) {
            return (System.Object) lhs != null && (System.Object) rhs != null && lhs.CompareTo(rhs) < 0;
        }

        public static bool operator >=(Coordinate2DimensionalAndLength2Dimensional lhs,
            Coordinate2DimensionalAndLength2Dimensional rhs) {
            return (System.Object) lhs != null && (System.Object) rhs != null && lhs.CompareTo(rhs) >= 0;
        }

        public static bool operator <=(Coordinate2DimensionalAndLength2Dimensional lhs,
            Coordinate2DimensionalAndLength2Dimensional rhs) {
            return (System.Object) lhs != null && (System.Object) rhs != null && lhs.CompareTo(rhs) <= 0;
        }

    }
}
