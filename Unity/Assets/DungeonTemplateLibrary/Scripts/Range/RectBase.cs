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
using MatrixRange = DTL.Base.Coordinate2DimensionalAndLength2Dimensional;

namespace DTL.Range {
    public class RectBase<TDerived> : BasicRect<RectBase<TDerived>> where TDerived : RectBase<TDerived> {

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

        public TDerived Clear() {
            this.ClearRange();
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

        public RectBase() {
        } // = default()

        public RectBase(MatrixRange matrixRange) : base(matrixRange) {
        }

        public RectBase(uint startX, uint startY, uint width, uint height) : base(startX, startY, width, height) {
        }
    }
}