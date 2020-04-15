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
using DTL.Random;

namespace DTL.Shape {
    public static class DiamondSquareAverage {
        // Diamond Square
        public static void CreateDiamondSquareAverage<TRand>(int[,] matrix_, uint startX_, uint startY_,
            uint x_, uint y_, uint size_, int t1_, int t2_, int t3_, int t4_, int maxValue_, int addAltitude_,
            TRand rand, Func<int, int> func) where TRand : IRandomable {

            // 再起の終了処理
            if (size_ == 0) return;
            int vertexRand = (int) rand.Next((uint) addAltitude_);
            int vertexHeight = t1_ / 4 + t2_ / 4 + t3_ / 4 + t4_ / 4;
            matrix_[startY_ + y_, startX_ + x_] = vertexHeight + vertexRand;

            // 4つの中点
            int s1 = (int) t1_ / 2 + t2_ / 2;
            int s2 = (int) t1_ / 2 + t3_ / 2;
            int s3 = (int) t2_ / 2 + t4_ / 2;
            int s4 = (int) t3_ / 2 + t4_ / 2;

            matrix_[startY_ + y_ + size_, startX_ + x_] = s3;
            matrix_[startY_ + y_ - size_, startX_ + x_] = s2;
            matrix_[startY_ + y_, startX_ + x_ + size_] = s4;
            matrix_[startY_ + y_, startX_ + x_ - size_] = s1;
            size_ /= 2;

            CreateDiamondSquareAverage(matrix_, startX_, startY_, x_ - size_, y_ - size_, size_, t1_, s1, s2,
                matrix_[startY_ + y_, startX_ + x_], maxValue_, func(addAltitude_), rand, func);
            CreateDiamondSquareAverage(matrix_, startX_, startY_, x_ - size_, y_ + size_, size_, s1, t2_,
                matrix_[startY_ + y_, startX_ + x_], s3, maxValue_, func(addAltitude_), rand, func);
            CreateDiamondSquareAverage(matrix_, startX_, startY_, x_ + size_, y_ - size_, size_, s2,
                matrix_[startY_ + y_, startX_ + x_], t3_, s4, maxValue_, func(addAltitude_), rand, func);
            CreateDiamondSquareAverage(matrix_, startX_, startY_, x_ + size_, y_ + size_, size_,
                matrix_[startY_ + y_, startX_ + x_], s3, s4, t4_, maxValue_, func(addAltitude_), rand, func);
        }
    }

    /**
     * Algorithm
     * t1 &&&&&&&&&&&&&&&&&&& t2
     * &                       &
     * &                       &
     * &                       &
     * &           X           &
     * &                       &
     * &                       &
     * &                       &
     * t3 &&&&&&&&&&&&&&&&&&& t4
     *
     * 1. calculate X value. (t1 + t2 + t3 + t4) / 4
     * 2. add offset. X + rand. rand depends on addAltitude.
     *
     * t1 &&&&&&&&&s1&&&&&&&& t2
     * &                       &
     * &                       &
     * &                       &
     * s1           X          s3
     * &                       &
     * &                       &
     * &                       &
     * t3 &&&&&&&&&s4&&&&&&&& t4
     *
     * 3. calculate s1 & s2 & s3 & s4. midpoint of (ti, tj) (i, j) is 0 ~ 3 
     * 4. recursive
     */
}