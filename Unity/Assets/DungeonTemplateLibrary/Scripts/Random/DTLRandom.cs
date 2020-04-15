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

namespace DTL.Random {
    /*#######################################################################################
        [概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
        [Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
    #######################################################################################*/


    /* [概要] "DTLRandom"は"System.Random"のメソッドのオーバーロードを定義することでキャストを明示せずに使用できるようにしたクラス。  */
    public class DTLRandom {
        private System.Random rand;

        /* Next Methods Overloads */

        /* Returns [0, int.MaxValue) */
        public int Next() {
            return rand.Next();
        }

        /* Returns [0, x) */
        public int Next(int x) {
            return rand.Next(x);
        }

        /* Returns [0, x) */
        public uint Next(uint x) {
            return (uint)rand.Next((int)x);
        }

        /* Returns [min, max)
           Note! when mix > max, generates RuntimeError. */
        public int Next(int min, int max) {
            return rand.Next(min, max);
        }

        /* Returns [min, max)
           Note! when mix > max, generates RuntimeError. */
        public int Next(uint min, int max) {
            return rand.Next((int)min, max);
        }

        /* Returns [min, max)
           Note! when mix > max or max > int.MaxValue, generates RuntimeError. */
        public int Next(int min, uint max) {
            return rand.Next(min, (int)max);
        }

        /* Returns [min, max)
           Note! when mix > max or min > int.MaxValue, max > int.MaxValue, generates RuntimeError. */
        public uint Next(uint min, uint max) {
            return (uint)rand.Next((int)min, (int)max);
        }

        /* Using Uniform Distribution methods */

        /* Returns [0.0, 1.0) (double)  */
        public double NextDouble() {
            return rand.NextDouble();
        }

        /* Returns "true" width probalility of argument value (0.0 to 1.0) and "false" with other probability */
        public bool Probability(double probability) {
            return probability >= NextDouble();
        }


        /* コンストラクタ */

        // Randomのシードを指定することができる。
        // デバッグの時に同じ状況を再現できるので便利かもしれない。
        public DTLRandom(int? seed_ = null) {
            rand = seed_ == null ? new System.Random() : new System.Random((int)seed_);
        } // default;
    }
}