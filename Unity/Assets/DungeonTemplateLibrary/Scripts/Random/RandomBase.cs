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

namespace DTL.Random {
    // RNGCryptoServiceProviderを使うか？
    // => RNGCryptoServiceProviderを使うことによる計算コストや他の副作用が考えられないため、今回は乱数発生機をジェネリックとして渡すことにする。
    // 渡せる乱数生成機はIRandomableをインタフェースとして持つクラス。その中にRNGCryptoServiceProviderも入れておけばよい
    // TODO IRandamableをインタフェースとして実装したRNGCryptoServiceProviderWrapperの実装

    public class RandomBase : IRandomable {
        private IRandomable rand;

        public bool Probability(double p) {
            var q = UniformRealDistribution();
            return p > q;
        }

        // 一様な乱数を[0, 1]の範囲で生成することを保証する。
        public double UniformRealDistribution() {
            return Normalize(rand.Next());
        }

        // 整数xを[0, 1]に正規化する。
        private double Normalize(uint x) {
            return (double) x / uint.MaxValue;
        }

        // 整数xを[0, 1]に正規化する。
        private double Normalize(int x) {
            return (double) x / int.MaxValue;
        }

        public uint Next(uint min, uint max) {
            return rand.Next(min, max);
        }

        public uint Next(uint max) {
            return rand.Next(max);
        }

        public uint Next() {
            return rand.Next();
        }

        /* Constructors */

        public RandomBase() {
            this.rand = new XorShift128();
        }

        public RandomBase(IRandomable rand) {
            this.rand = rand;
        }
    }
}