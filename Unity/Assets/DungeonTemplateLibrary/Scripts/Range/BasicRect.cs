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
using MatrixRange = DTL.Base.Coordinate2DimensionalAndLength2Dimensional;

namespace DTL.Range {
    /*#######################################################################################
        [概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
        [Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
    #######################################################################################*/

    /* std::size_t = uint */

    public class BasicRect<TDerived> where TDerived : BasicRect<TDerived> {
        public uint startX { get; protected set; }
        public uint startY { get; protected set; }
        public uint width { get; protected set; }
        public uint height { get; protected set; }

        /* 計算補助 */
        protected uint CalcEndX(uint maxX) {
            return (this.width == 0 || this.startX + this.width >= maxX) ? maxX : this.startX + this.width;
        }

        protected uint CalcEndY(uint maxY) {
            return (this.height == 0 || this.startY + this.height >= maxY) ? maxY : this.startY + this.height;
        }

        /* Constructors */
        public BasicRect() {
        } // = default()

        public BasicRect(MatrixRange matrixRange) {
            this.startX = (uint) matrixRange.x;
            this.startY = (uint) matrixRange.y;
            this.width = (uint) matrixRange.w;
            this.height = (uint) matrixRange.h;
        }

        public BasicRect(uint startX, uint startY, uint width, uint height) {
            this.startX = startX;
            this.startY = startY;
            this.width = width;
            this.height = height;
        }

        /* Clear */
        public TDerived ClearPointX() {
            this.startX = 0;
            return (TDerived) this;
        }

        public TDerived ClearPointY() {
            this.startY = 0;
            return (TDerived) this;
        }

        public TDerived ClearPoint() {
            this.startX = 0;
            this.startY = 0;
            return (TDerived) this;
        }

        public TDerived ClearWidth() {
            this.width = 0;
            return (TDerived) this;
        }

        public TDerived ClearHeight() {
            this.height = 0;
            return (TDerived) this;
        }

        public TDerived ClearLength() {
            ClearWidth();
            ClearHeight();
            return (TDerived) this;
        }

        public TDerived ClearRange() {
            ClearLength();
            ClearPointX();
            ClearPointY();
            return (TDerived) this;
        }

        /* Getter */
        public TDerived GetPointX(ref uint value) {
            value = this.startX;
            return (TDerived) this;
        }

        public TDerived GetPointY(ref uint value) {
            value = this.startY;
            return (TDerived) this;
        }

        public TDerived GetHeight(ref uint value) {
            value = this.height;
            return (TDerived) this;
        }

        public TDerived GetWidth(ref uint value) {
            value = this.width;
            return (TDerived) this;
        }

        public TDerived GetPoint(ref uint value, ref uint value2) {
            value = this.startX;
            value2 = this.startY;
            return (TDerived) this;
        }

        public TDerived GetRange(ref uint value, ref uint value2, ref uint value3, ref uint value4) {
            value = this.startX;
            value2 = this.startY;
            value3 = this.width;
            value4 = this.height;
            return (TDerived) this;
        }

        public uint GetPointX() {
            return this.startX;
        }

        public uint GetPointY() {
            return this.startY;
        }

        public uint GetWidth() {
            return this.width;
        }

        public uint GetHeight() {
            return this.height;
        }

        /* Setter returns */

        public TDerived SetPointX(uint startX) {
            this.startX = startX;
            return (TDerived) this;
        }

        public TDerived SetPointY(uint startY) {
            this.startY = startY;
            return (TDerived) this;
        }

        public TDerived SetWidth(uint width) {
            this.width = width;
            return (TDerived) this;
        }

        public TDerived SetHeight(uint height) {
            this.height = height;
            return (TDerived) this;
        }

        public TDerived SetPoint(uint point) {
            this.startX = point;
            this.startY = point;
            return (TDerived) this;
        }

        public TDerived SetPoint(uint startX, uint startY) {
            this.startX = startX;
            this.startY = startY;
            return (TDerived) this;
        }

        public TDerived SetRange(uint startX, uint startY, uint length) {
            this.startX = startX;
            this.startY = startY;
            this.width = length;
            this.height = length;
            return (TDerived) this;
        }

        public TDerived SetRange(uint startX, uint startY, uint width, uint height) {
            this.startX = startX;
            this.startY = startY;
            this.width = width;
            this.height = height;
            return (TDerived) this;
        }

        public TDerived SetRange(MatrixRange matrixRange) {
            this.startX = (uint) matrixRange.x;
            this.startY = (uint) matrixRange.y;
            this.width = (uint) matrixRange.w;
            this.height = (uint) matrixRange.h;
            return (TDerived) this;
        }
    }
}