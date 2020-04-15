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

using DTL.Base;
using UnityEngine;
using MatrixRange = DTL.Base.Coordinate2DimensionalAndLength2Dimensional;

namespace DTL.Range {
    public class RectBasePerlin<TDerived> : BasicRect<RectBasePerlin<TDerived>>
        where TDerived : RectBasePerlin<TDerived> {
        public double frequency { get; protected set; }
        public uint octaves { get; protected set; }
        public int minHeight { get; protected set; }
        public int maxHeight { get; protected set; }

        /* Getter */

        public double GetFrequency() {
            return this.frequency;
        }

        public double GetOctaves() {
            return this.octaves;
        }

        public int GetMinHeight() {
            return this.minHeight;
        }

        public int GetMaxHeight() {
            return this.maxHeight;
        }

        public double GetValue() {
            return this.frequency;
        }

        public new TDerived GetPointX(ref uint value) {
            base.GetPointX(ref value);
            return (TDerived)this;
        }

        public new TDerived GetPointY(ref uint value) {
            base.GetPointY(ref value);
            return (TDerived)this;
        }

        public new TDerived GetHeight(ref uint value) {
            base.GetPointY(ref value);
            return (TDerived)this;
        }

        public new TDerived GetWidth(ref uint value) {
            base.GetWidth(ref value);
            return (TDerived)this;
        }

        public new TDerived GetPoint(ref uint value, ref uint value2) {
            base.GetPoint(ref value, ref value2);
            return (TDerived)this;
        }

        public new TDerived GetRange(ref uint value, ref uint value2, ref uint value3, ref uint value4) {
            base.GetRange(ref value, ref value2, ref value3, ref value4);
            return (TDerived)this;
        }

        public new uint GetPointX() {
            return base.GetPointX();
        }

        public new uint GetPointY() {
            return base.GetPointX();
        }

        public new uint GetWidth() {
            return base.GetWidth();
        }

        public new uint GetHeight() {
            return base.GetHeight();
        }

        /* Setter */

        public TDerived SetValue(double frequency) {
            this.frequency = frequency;
            return (TDerived) this;
        }

        public TDerived SetFrequency(double frequency) {
            this.frequency = frequency;
            return (TDerived) this;
        }

        public TDerived SetOctaves(uint octaves) {
            this.octaves = octaves;
            return (TDerived) this;
        }

        public TDerived SetMinHeight(int minHeight) {
            this.minHeight = minHeight;
            return (TDerived) this;
        }

        public TDerived SetMaxHeight(int maxHeight) {
            this.maxHeight = maxHeight;
            return (TDerived) this;
        }

        public new TDerived SetPointX(uint startX) {
            base.SetPointX(startX);
            return (TDerived)this;
        }

        public new TDerived SetPointY(uint startY) {
            base.SetPointY(startY);
            return (TDerived)this;
        }

        public new TDerived SetWidth(uint width) {
            base.SetWidth(width);
            return (TDerived)this;
        }

        public new TDerived SetHeight(uint height) {
            base.SetHeight(height);
            return (TDerived)this;
        }

        public new TDerived SetPoint(uint point) {
            base.SetPoint(point);
            return (TDerived)this;
        }

        public new TDerived SetPoint(uint startX, uint startY) {
            base.SetPoint(startX, startY);
            return (TDerived)this;
        }

        public new TDerived SetRange(uint startX, uint startY, uint length) {
            base.SetRange(startX, startY, length);
            return (TDerived)this;
        }

        public new TDerived SetRange(uint startX, uint startY, uint width, uint height) {
            base.SetRange(startX, startY, width, height);
            return (TDerived)this;
        }

        public new TDerived SetRange(MatrixRange matrixRange) {
            base.SetRange(matrixRange);
            return (TDerived)this;
        }

        /* clear */

        public TDerived ClearValue() {
            this.frequency = 0.0;
            this.octaves = 0;
            this.maxHeight = 0;
            this.minHeight = 0;
            return (TDerived) (this);
        }

        public TDerived ClearFrequency() {
            this.frequency = 0.0;
            return (TDerived) (this);
        }

        public TDerived ClearOctaves() {
            this.octaves = 0;
            return (TDerived) (this);
        }

        public TDerived ClearMinHeight() {
            this.minHeight = 0;
            return (TDerived)(this);
        }

        public TDerived ClearMaxHeight() {
            this.maxHeight = 0;
            return (TDerived)(this);
        }

        public TDerived Clear() {
            this.ClearRange();
            this.ClearValue();
            return (TDerived)(this);
        }

        public new TDerived ClearPointX() {
            base.ClearPointX();
            return (TDerived)this;
        }

        public new TDerived ClearPointY() {
            base.ClearPointY();
            return (TDerived)this;
        }

        public new TDerived ClearPoint() {
            base.ClearPoint();
            return (TDerived)this;
        }

        public new TDerived ClearWidth() {
            base.ClearWidth();
            return (TDerived)this;
        }

        public new TDerived ClearHeight() {
            base.ClearHeight();
            return (TDerived)this;
        }

        public new TDerived ClearLength() {
            base.ClearHeight();
            return (TDerived)this;
        }

        public new TDerived ClearRange() {
            base.ClearRange();
            return (TDerived)this;
        }

        public RectBasePerlin() {
        } // = default()

        public RectBasePerlin(uint startX, uint startY, uint width, uint height) : base(startX, startY, width, height) {
        }

        public RectBasePerlin(double frequency) {
            this.frequency = frequency;
        }

        public RectBasePerlin(double frequency, uint octaves) {
            this.frequency = frequency;
            this.octaves = octaves;
        }

        public RectBasePerlin(double frequency, uint octaves, int maxHeight) {
            this.frequency = frequency;
            this.octaves = octaves;
            this.maxHeight = maxHeight;
        }

        public RectBasePerlin(double frequency, uint octaves, int maxHeight, int minHeight) {
            this.frequency = frequency;
            this.octaves = octaves;
            this.maxHeight = maxHeight;
            this.minHeight = minHeight;
        }

        public RectBasePerlin(MatrixRange matrixRange, double frequency) : base(matrixRange) {
            this.frequency = frequency;
        }

        public RectBasePerlin(MatrixRange matrixRange, double frequency, uint octaves) : base(matrixRange) {
            this.frequency = frequency;
            this.octaves = octaves;
        }

        public RectBasePerlin(MatrixRange matrixRange, double frequency, uint octaves, int maxHeight) : base(
            matrixRange) {
            this.frequency = frequency;
            this.octaves = octaves;
            this.maxHeight = maxHeight;
        }

        public RectBasePerlin(MatrixRange matrixRange, double frequency, uint octaves, int maxHeight, int minHeight) :
            base(matrixRange) {
            this.frequency = frequency;
            this.octaves = octaves;
            this.maxHeight = maxHeight;
            this.minHeight = minHeight;
        }

        public RectBasePerlin(uint startX, uint startY, uint width, uint height, double frequency) : base(startX,
            startY, width, height) {
            this.frequency = frequency;
        }

        public RectBasePerlin(uint startX, uint startY, uint width, uint height, double frequency, uint octaves) : base(
            startX, startY, width, height) {
            this.frequency = frequency;
            this.octaves = octaves;
        }

        public RectBasePerlin(uint startX, uint startY, uint width, uint height, double frequency, uint octaves,
            int maxHeight) : base(startX, startY, width, height) {
            this.frequency = frequency;
            this.octaves = octaves;
            this.maxHeight = maxHeight;
        }

        public RectBasePerlin(uint startX, uint startY, uint width, uint height, double frequency, uint octaves,
            int maxHeight, int minHeight) : base(startX, startY, width, height) {
            this.frequency = frequency;
            this.octaves = octaves;
            this.maxHeight = maxHeight;
            this.minHeight = minHeight;
        }
    }
}