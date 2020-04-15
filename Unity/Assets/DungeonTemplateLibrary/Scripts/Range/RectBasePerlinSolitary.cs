/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/

using DTL.Base;
using UnityEngine;
using MatrixRange = DTL.Base.Coordinate2DimensionalAndLength2Dimensional;

namespace DTL.Range {
    public class RectBasePerlinSolitary<TDerived> : BasicRect<RectBasePerlinSolitary<TDerived>>
        where TDerived : RectBasePerlinSolitary<TDerived> {
        public double truncatedProportion { get; protected set; }
        public double mountainProportion { get; protected set; }
        public double frequency { get; protected set; }
        public uint octaves { get; protected set; }
        public int minHeight { get; protected set; }
        public int maxHeight { get; protected set; }

        /* Getter */

        public double GetTruncatedProportion() {
            return this.truncatedProportion;
        }

        public double GetMountainProportion() {
            return this.mountainProportion;
        }

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

        public TDerived SetTruncatedProportion(double truncatedProportion) {
            this.truncatedProportion = truncatedProportion;
            return (TDerived) this;
        }

        public TDerived SetMountainProportion(double mountainProportion) {
            this.mountainProportion = mountainProportion;
            return (TDerived) this;
        }

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
            this.truncatedProportion = 0.0;
            this.mountainProportion = 0.0;
            this.octaves = 0;
            this.minHeight = 0;
            this.maxHeight = 0;
            return (TDerived) this;
        }

        public TDerived ClearTruncatedProportion() {
            this.truncatedProportion = 0.0;
            return (TDerived) this;
        }

        public TDerived ClearMountainProportion() {
            this.mountainProportion = 0.0;
            return (TDerived) this;
        }

        public TDerived ClearFrequency() {
            this.frequency = 0.0;
            return (TDerived) this;
        }

        public TDerived ClearOctaves() {
            this.octaves = 0;
            return (TDerived) this;
        }

        public TDerived ClaerMinHeight() {
            this.minHeight = 0;
            return (TDerived) this;
        }

        public TDerived ClearMaxHeight() {
            this.maxHeight = 0;
            return (TDerived) this;
        }

        public TDerived Clear() {
            this.ClearValue();
            this.ClearRange();
            return (TDerived) this;
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

        /* constructors */

        public RectBasePerlinSolitary() {
        } // = default()

        public RectBasePerlinSolitary(uint startX, uint startY, uint width, uint height) : base(startX, startY, width,
            height) {
        }

        public RectBasePerlinSolitary(double truncatedProportion) {
            this.truncatedProportion = truncatedProportion;
        }

        public RectBasePerlinSolitary(double truncatedProportion, double mountainProportion) {
            this.truncatedProportion = truncatedProportion;
            this.mountainProportion = mountainProportion;
        }

        public RectBasePerlinSolitary(double truncatedProportion, double mountainProportion, double frequency) {
            this.truncatedProportion = truncatedProportion;
            this.mountainProportion = mountainProportion;
            this.frequency = frequency;
        }

        public RectBasePerlinSolitary(double truncatedProportion, double mountainProportion, double frequency,
            uint octaves) {
            this.truncatedProportion = truncatedProportion;
            this.mountainProportion = mountainProportion;
            this.frequency = frequency;
            this.octaves = octaves;
        }

        public RectBasePerlinSolitary(double truncatedProportion, double mountainProportion, double frequency,
            uint octaves, int maxHeight) {
            this.truncatedProportion = truncatedProportion;
            this.mountainProportion = mountainProportion;
            this.frequency = frequency;
            this.octaves = octaves;
            this.maxHeight = maxHeight;
        }

        public RectBasePerlinSolitary(double truncatedProportion, double mountainProportion, double frequency,
            uint octaves, int maxHeight, int minHeight) {
            this.truncatedProportion = truncatedProportion;
            this.mountainProportion = mountainProportion;
            this.frequency = frequency;
            this.octaves = octaves;
            this.maxHeight = maxHeight;
            this.minHeight = minHeight;
        }

        public RectBasePerlinSolitary(MatrixRange matrixRange, double truncatedProportion) : base(matrixRange) {
            this.truncatedProportion = truncatedProportion;
        }

        public RectBasePerlinSolitary(MatrixRange matrixRange, double truncatedProportion, double mountainProportion) :
            base(matrixRange) {
            this.truncatedProportion = truncatedProportion;
            this.mountainProportion = mountainProportion;
        }

        public RectBasePerlinSolitary(MatrixRange matrixRange, double truncatedProportion, double mountainProportion,
            double frequency) : base(matrixRange) {
            this.truncatedProportion = truncatedProportion;
            this.mountainProportion = mountainProportion;
            this.frequency = frequency;
        }

        public RectBasePerlinSolitary(MatrixRange matrixRange, double truncatedProportion, double mountainProportion,
            double frequency, uint octaves) : base(matrixRange) {
            this.truncatedProportion = truncatedProportion;
            this.mountainProportion = mountainProportion;
            this.frequency = frequency;
            this.octaves = octaves;
        }

        public RectBasePerlinSolitary(MatrixRange matrixRange, double truncatedProportion, double mountainProportion,
            double frequency, uint octaves, int maxHeight) : base(matrixRange) {
            this.truncatedProportion = truncatedProportion;
            this.mountainProportion = mountainProportion;
            this.frequency = frequency;
            this.octaves = octaves;
            this.maxHeight = maxHeight;
        }

        public RectBasePerlinSolitary(MatrixRange matrixRange, double truncatedProportion, double mountainProportion,
            double frequency, uint octaves, int maxHeight, int minHeight) : base(matrixRange) {
            this.truncatedProportion = truncatedProportion;
            this.mountainProportion = mountainProportion;
            this.frequency = frequency;
            this.octaves = octaves;
            this.maxHeight = maxHeight;
            this.minHeight = minHeight;
        }

        public RectBasePerlinSolitary(uint startX, uint startY, uint width, uint height, double truncatedProportion) :
            base(startX, startY, width, height) {
            this.truncatedProportion = truncatedProportion;
        }

        public RectBasePerlinSolitary(uint startX, uint startY, uint width, uint height, double truncatedProportion,
            double mountainProportion) : base(startX, startY, width, height) {
            this.truncatedProportion = truncatedProportion;
            this.mountainProportion = mountainProportion;
        }

        public RectBasePerlinSolitary(uint startX, uint startY, uint width, uint height, double truncatedProportion,
            double mountainProportion, double frequency) : base(startX, startY, width, height) {
            this.truncatedProportion = truncatedProportion;
            this.mountainProportion = mountainProportion;
            this.frequency = frequency;
        }

        public RectBasePerlinSolitary(uint startX, uint startY, uint width, uint height, double truncatedProportion,
            double mountainProportion, double frequency, uint octaves) : base(startX, startY, width, height) {
            this.truncatedProportion = truncatedProportion;
            this.mountainProportion = mountainProportion;
            this.frequency = frequency;
            this.octaves = octaves;
        }

        public RectBasePerlinSolitary(uint startX, uint startY, uint width, uint height, double truncatedProportion,
            double mountainProportion, double frequency, uint octaves, int maxHeight) : base(startX, startY, width,
            height) {
            this.truncatedProportion = truncatedProportion;
            this.mountainProportion = mountainProportion;
            this.frequency = frequency;
            this.octaves = octaves;
            this.maxHeight = maxHeight;
        }

        public RectBasePerlinSolitary(uint startX, uint startY, uint width, uint height, double truncatedProportion,
            double mountainProportion, double frequency, uint octaves, int maxHeight, int minHeight) : base(startX,
            startY, width, height) {
            this.truncatedProportion = truncatedProportion;
            this.mountainProportion = mountainProportion;
            this.frequency = frequency;
            this.octaves = octaves;
            this.maxHeight = maxHeight;
            this.minHeight = minHeight;
        }
    }
}