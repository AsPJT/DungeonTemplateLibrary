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
using System.Collections.Specialized;
using DTL.Random;
using DTL.Util;
using UnityEngine;

namespace DTL.Util {
    // PerlinNoise Utilities. Expect double or float.
    public class PerlinNoise {
        /* private member */
        private XorShift128 rand;
        private int[] p = new int[512];

        /* private members */

        private double GetFade(double t) {
            return t * t * t * (t * (t * 6 - 15) + 10);
        }

        private double GetLerp(double t, double a, double b) {
            return a + t * (b - a);
        }

        private double MakeGradUV(int hash, double u, double v) {
            return ((hash & 1) == 0 ? u : -u) + ((hash & 2) == 0 ? v : -v);
        }

        private double MakeGrad(int hash, double x, double y) {
            return MakeGradUV(hash, (hash < 8) ? x : y, (hash < 4) ? y : hash == 12 || hash == 14 ? x : 0.0);
        }

        private double MakeGrad(int hash, double x, double y, double z) {
            return MakeGradUV(hash, (hash < 8) ? x : y, (hash < 4) ? y : hash == 12 || hash == 14 ? x : z);
        }

        private double GetGrad(int hash, double x, double y) {
            return MakeGrad(hash & 15, x, y);
        }

        private double GetGrad(int hash, double x, double y, double z) {
            return MakeGrad(hash & 15, x, y, z);
        }

        private double SetNoise(double x = 0.0, double y = 0.0) {
            uint xInt = (uint) Math.Floor(x) & 255;
            uint yInt = (uint) Math.Floor(y) & 255;
            x -= Math.Floor(x);
            y -= Math.Floor(y);
            double u = this.GetFade(x);
            double v = this.GetFade(y);
            uint a0 = (uint) (this.p[xInt] + yInt);
            uint a1 = (uint) this.p[a0];
            uint a2 = (uint) this.p[a0 + 1];
            uint b0 = (uint) (this.p[xInt + 1] + yInt);
            uint b1 = (uint) this.p[b0];
            uint b2 = (uint) this.p[b0 + 1];

            return GetLerp(v,
                GetLerp(u, GetGrad(this.p[a1], x, y), GetGrad(this.p[b1], x - 1, y)),
                GetLerp(u, GetGrad(this.p[a2], x, y - 1), GetGrad(this.p[b2], x - 1, y - 1)));
        }

        private double SetNoise(double x, double y, double z) {
            uint xInt = (uint) Math.Floor(x) & 255;
            uint yInt = (uint) Math.Floor(y) & 255;
            uint zInt = (uint) Math.Floor(z) & 255;
            x -= Math.Floor(x);
            y -= Math.Floor(y);
            z -= Math.Floor(z);
            double u = GetFade(x);
            double v = GetFade(y);
            double w = GetFade(z);
            uint a0 = (uint) this.p[xInt] + yInt;
            uint a1 = (uint) this.p[a0] + zInt;
            uint a2 = (uint) this.p[a0 + 1] + zInt;
            uint b0 = (uint) this.p[xInt + 1] + yInt;
            uint b1 = (uint) this.p[b0] + zInt;
            uint b2 = (uint) this.p[b0 + 1] + zInt;

            return GetLerp(w,
                GetLerp(v,
                    GetLerp(u, this.GetGrad(this.p[a1], x, y, z), this.GetGrad(this.p[b1], x - 1, y, z)),
                    GetLerp(u, this.GetGrad(this.p[a2], x, y - 1, z),
                        this.GetGrad(this.p[b2], x - 1, y - 1, z))),
                GetLerp(v,
                    GetLerp(u, this.GetGrad(this.p[a1 + 1], x, y, z - 1),
                        this.GetGrad(this.p[b1 + 1], x - 1, y, z - 1)),
                    GetLerp(u, this.GetGrad(this.p[a2 + 1], x, y - 1, z - 1),
                        this.GetGrad(this.p[b2 + 1], x - 1, y - 1, z - 1))));
        }

        private double SetOctaveNoise(uint octaves, double x) {
            double noiseValue = 0;
            double amp = 1.0;
            for (int i = 0; i < octaves; ++i) {
                noiseValue += this.SetNoise(x) * amp;
                x *= 2.0;
                amp *= 0.5;
            }

            return noiseValue;
        }

        private double SetOctaveNoise(uint octaves, double x, double y) {
            double noiseValue = 0;
            double amp = 1.0;
            for (int i = 0; i < octaves; ++i) {
                noiseValue += this.SetNoise(x, y) * amp;
                x *= 2.0;
                y *= 2.0;
                amp *= 0.5;
            }

            return noiseValue;
        }

        private double SetOctaveNoise(uint octaves, double x, double y, double z) {
            double noiseValue = 0;
            double amp = 1.0;
            for (int i = 0; i < octaves; ++i) {
                noiseValue += this.SetNoise(x, y, z) * amp;
                x *= 2.0;
                y *= 2.0;
                z *= 2.0;
                amp *= 0.5;
            }

            return noiseValue;
        }


        /* public methods */

        public double Noise(double x, double y) {
            double noiseValue = SetNoise(x, y) * 0.5 + 0.5;
            return (noiseValue >= 1.0) ? 1.0 : (noiseValue <= 0.0) ? 0.0 : noiseValue;
        }

        public double Noise(double x, double y, double z) {
            double noiseValue = SetNoise(x, y, z) * 0.5 * 0.5;
            return (noiseValue >= 1.0) ? 1.0 : (noiseValue <= 0.0) ? 0.0 : noiseValue;
        }


        //オクターブ有りノイズを取得する
        public double OctaveNoise(uint octaves_, double x) {
            double noiseValue = SetOctaveNoise(octaves_, x) * 0.5 + 0.5;
            return (noiseValue >= 1.0) ? 1.0 : (noiseValue <= 0.0) ? 0.0 : noiseValue;
        }

        public double OctaveNoise(uint octaves_, double x, double y) {
            double noiseValue = SetOctaveNoise(octaves_, x, y) * 0.5 + 0.5;
            return (noiseValue >= 1.0) ? 1.0 : (noiseValue <= 0.0) ? 0.0 : noiseValue;
        }

        public double OctaveNoise(uint octaves_, double x, double y, double z) {
            double noiseValue = SetOctaveNoise(octaves_, x, y, z) * 0.5 + 0.5;
            return (noiseValue >= 1.0) ? 1.0 : (noiseValue <= 0.0) ? 0.0 : noiseValue;
        }

        // SEED値をセットする
        public void SetSeed(uint seed) {
            for (int i = 0; i < 256; ++i)
                this.p[i] = i;
            ArrayUtil.Shuffle(p, 256, rand);
            for (int i = 0; i < 256; ++i) {
                this.p[256 + i] = this.p[i];
            }
        }

        /* Constructor */
        public PerlinNoise() {
            this.rand = new XorShift128();
            SetSeed(rand.Next());
        } // = default();

        public PerlinNoise(int seed) {
            this.rand = new XorShift128((uint)seed);
            SetSeed((uint) seed);
        }
    }
}