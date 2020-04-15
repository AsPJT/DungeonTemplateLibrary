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

namespace DTL.Util {
    /*#######################################################################################
        [概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
        [Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
    #######################################################################################*/

    public static class MatrixUtil {

        public static uint GetX<T>(T[,] matrix) {
            return (uint)matrix.GetLength(1);
        }

        public static uint GetX<T>(T[,] matrix, int y_) {
            var lengthY = MatrixUtil.GetY(matrix);
            return y_ < lengthY ? MatrixUtil.GetX(matrix) : 0;
        }

        public static uint GetY<T>(T[,] matrix) {
            return (uint)matrix.GetLength(0);
        }

        public static int GetMax(int[,] matrix) {
            var x = GetX(matrix);
            var y = GetY(matrix);
            var mMax = matrix[0, 0];

            for (int row = 0; row < y; ++row)
            for (int col = 0; col < x; ++col)
                mMax = Math.Max(matrix[row, col], mMax);

            return mMax;
        }

        public static float GetMax(float[,] matrix) {
            var x = GetX(matrix);
            var y = GetY(matrix);
            var mMax = matrix[0, 0];

            for (int row = 0; row < y; ++row)
            for (int col = 0; col < x; ++col)
                mMax = Math.Max(matrix[row, col], mMax);

            return mMax;
        }

        public static double GetMax(double[,] matrix) {
            var x = GetX(matrix);
            var y = GetY(matrix);
            var mMax = matrix[0, 0];

            for (int row = 0; row < y; ++row)
            for (int col = 0; col < x; ++col)
                mMax = Math.Max(matrix[row, col], mMax);

            return mMax;
        }

        public static int GetMin(int[,] matrix) {
            var x = GetX(matrix);
            var y = GetY(matrix);
            var mMin = matrix[0, 0];

            for (int row = 0; row < y; ++row)
            for (int col = 0; col < x; ++col)
                mMin = Math.Min(matrix[row, col], mMin);

            return mMin;
        }

        public static float GetMin(float[,] matrix) {
            var x = GetX(matrix);
            var y = GetY(matrix);
            var mMin = matrix[0, 0];

            for (int row = 0; row < y; ++row)
            for (int col = 0; col < x; ++col)
                mMin = Math.Min(matrix[row, col], mMin);

            return mMin;
        }

        public static double GetMin(double[,] matrix) {
            var x = GetX(matrix);
            var y = GetY(matrix);
            var mMin = matrix[0, 0];

            for (int row = 0; row < y; ++row)
            for (int col = 0; col < x; ++col)
                mMin = Math.Min(matrix[row, col], mMin);

            return mMin;
        }

    }
}