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

namespace DTL.Base {
    public class Coordinate3DimensionalAndLength3Dimensional :
        IEquatable<Coordinate3DimensionalAndLength3Dimensional>,
        IComparable<Coordinate3DimensionalAndLength3Dimensional> {

        public int x { get; set; }
        public int y { get; set; }
        public int z { get; set; }
        public int w { get; set; }
        public int h { get; set; }
        public int d { get; set; }

        public Coordinate3DimensionalAndLength3Dimensional() { } // default

        public Coordinate3DimensionalAndLength3Dimensional(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public Coordinate3DimensionalAndLength3Dimensional(int x, int y, int z, int l) : this(x, y, z) {
            this.w = l;
            this.h = l;
            this.d = l;
        }

        public Coordinate3DimensionalAndLength3Dimensional(int x, int y, int z, int w, int h, int d) : this(x, y, z) {
            this.w = w;
            this.h = h;
            this.d = d;
        }

        public bool Equals(Coordinate3DimensionalAndLength3Dimensional others) {
            if (others == null || !this.GetType().Equals(others.GetType())) {
                return false;
            }

            return (x.Equals(others.x) && y.Equals(others.y) && z.Equals(others.z) && w.Equals(others.w) &&
                    h.Equals(others.h) && d.Equals(others.d));
        }

        public override bool Equals(object obj) {
            return this.Equals(obj);
        }

        public int CompareTo(Coordinate3DimensionalAndLength3Dimensional other) {
            return w * h * d - other.w * other.h * other.d;
        }

        public static bool operator ==(Coordinate3DimensionalAndLength3Dimensional lhs,
            Coordinate3DimensionalAndLength3Dimensional rhs) {
            return lhs != null && lhs.Equals(rhs);
        }

        public static bool operator !=(Coordinate3DimensionalAndLength3Dimensional lhs,
            Coordinate3DimensionalAndLength3Dimensional rhs) {
            return lhs != null && !lhs.Equals(rhs);
        }

        public static bool operator >(Coordinate3DimensionalAndLength3Dimensional lhs,
            Coordinate3DimensionalAndLength3Dimensional rhs) {
            if (lhs == null || rhs == null) {
                return false;

            }
            return lhs.CompareTo(rhs) > 0;
        }

        public static bool operator <(Coordinate3DimensionalAndLength3Dimensional lhs,
            Coordinate3DimensionalAndLength3Dimensional rhs) {
            if (lhs == null || rhs == null) {
                return false;

            }
            return lhs.CompareTo(rhs) < 0;
        }

        public static bool operator >=(Coordinate3DimensionalAndLength3Dimensional lhs,
            Coordinate3DimensionalAndLength3Dimensional rhs) {
            if (lhs == null || rhs == null) {
                return false;

            }
            return lhs.CompareTo(rhs) >= 0;
        }

        public static bool operator <=(Coordinate3DimensionalAndLength3Dimensional lhs,
            Coordinate3DimensionalAndLength3Dimensional rhs) {
            if (lhs == null || rhs == null) {
                return false;

            }
            return lhs.CompareTo(rhs) <= 0;
        }
    }
}
