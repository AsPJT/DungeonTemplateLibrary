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

using System.Collections.Generic;
using DTL.Random;

namespace DTL.Util {
    public static class ArrayUtil {
        static void Swap<T>(ref T a, ref T b) {
            T tmp;
            tmp = a;
            a = b;
            b = tmp;
        }

        static void Swap<T>(IList<T> list, int a, int b) {
            // assert( a,b < list.Count )
            T tmp;
            tmp = list[a];
            list[a] = list[b];
            list[b] = tmp;
        }

        /**
         * IList Shuffle
         */
        public static void Shuffle<T, TRand>(IList<T> list, TRand rand) where TRand : IRandomable {
            var listLength = list.Count;
            for (int i = 0; i < listLength; ++i) {
                Swap(list, i, (int) rand.Next((uint) listLength - 1));
            }
        }

        /**
         * Todo void関数化。オブジェクトは参照渡しになるので返り値はメモリの無駄。
         */
        public static T[] Shuffle<T, TRand>(T[] array, TRand rand) where TRand : IRandomable {
            int arrayLength = array.Length;
            for (int i = 0; i < arrayLength; ++i) {
                Swap(ref array[i], ref array[rand.Next((uint) arrayLength - 1)]);
            }

            return array;
        }

        // shuffle array from 0 to max - 1 =- [0, max)
        public static T[] Shuffle<T, TRand>(T[] array, uint max, TRand rand) where TRand : IRandomable {
            uint arrayLength = (uint) array.Length;
            max = max > arrayLength - 1 ? arrayLength : max;
            for (int i = 0; i < max; ++i) {
                Swap(ref array[i], ref array[rand.Next(max)]);
            }

            return array;
        }
    }
}