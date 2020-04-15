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
using UnityEngine;

namespace DTL.Random {
    /* Xorshift: generates random numbers */
    public class XorShift128 : IRandomable {
        private System.Random rand;

        private uint x = 123456789;
        private uint y = 362436069;
        private uint z = 521288629;
        private uint w = 88675123;

        public uint Min() {
            return System.UInt32.MinValue;
        }

        public uint Max() {
            return System.UInt32.MaxValue;
        }

        public uint Next() {
            var t = x ^ (x << 11);
            x = y;
            y = z;
            z = w;
            w = (w ^ (w >> 19)) ^ (t ^ (t << 8));
            return w;
        }

        public uint Next(uint max) {
            if (max == 0) return 0;
            return Next() % max;
        }

        // Generate random number between [min, max). Note! max >= min
        public uint Next(uint min, uint max) {
            if (max == 0 || max - min == 0) return 0;
            return min + Next() % (max - min);
        }

        private void Init(uint gen) {
            x ^= gen;
            y ^= gen;
            z ^= gen;
            w ^= gen;
        }

        public XorShift128(uint? seed = null) {
            if (seed == null) {
                rand = new System.Random((int) DateTime.Now.Ticks);
                seed = (uint) rand.Next();
            }

            Init((uint) seed);
        }
    }
}