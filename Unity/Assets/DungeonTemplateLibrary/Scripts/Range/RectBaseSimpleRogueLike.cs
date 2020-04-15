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
using MatrixRange = DTL.Base.Coordinate2DimensionalAndLength2Dimensional;

/*
 * Range機能(配列の特定の範囲を描画する機能)は未実装.
 * 将来的に実装することを見据えて名前空間は本家DTLに倣うことにする.
 */

namespace DTL.Range {
    /*#######################################################################################
        [概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
        [Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
    #######################################################################################*/

    public class RectBaseSimpleRogueLike<TDerived> : BasicRect<RectBaseSimpleRogueLike<TDerived>>
        where TDerived : RectBaseSimpleRogueLike<TDerived> {
        public int roomValue { get; protected set; }
        public int roadValue { get; protected set; }

        public uint divisionMin { get; protected set; } = 3;
        public uint divisionRandMax { get; protected set; } = 4;
        public uint roomMinX { get; protected set; } = 5;
        public uint roomRandMaxX { get; protected set; } = 2;
        public uint roomMinY { get; protected set; } = 5;
        public uint roomRandMaxY { get; protected set; } = 2;

        /* Getter */

        public TDerived GetRoom(ref int value) {
            value = roomValue;
            return (TDerived) this;
        }

        public TDerived GetRoad(ref int value) {
            value = roomValue;
            return (TDerived) this;
        }

        public TDerived GetWay(ref int value) {
            value = roomValue;
            return (TDerived)this;
        }

        public int GetWay() {
            return this.roadValue;
        }

        public int GetRoom() {
            return this.roomValue;
        }

        public int GetRoad() {
            return this.roadValue;
        }

        public int GetValue() {
            return this.roomValue;
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
        
        // 消去 (clear) //

        public TDerived ClearRoom() {
            roomValue = 0;
            return (TDerived) this;
        }

        public TDerived ClearWay() {
            roadValue = 0;
            return (TDerived) this;
        }

        public TDerived ClearRoad() {
            roadValue = 0;
            return (TDerived) this;
        }

        public TDerived ClearValue() {
            ClearRoom();
            ClearRoad();
            return (TDerived) this;
        }

        public TDerived Clear() {
            ClearRange();
            ClearValue();
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

        // Setter //

        public TDerived SetRoom(int roomValue) {
            this.roomValue = roomValue;
            return (TDerived) this;
        }

        public TDerived SetWay(int roadValue) {
            this.roadValue = roadValue;
            return (TDerived) this;
        }

        public TDerived SetRoad(int roadValue) {
            this.roadValue = roadValue;
            return (TDerived) this;
        }

        public TDerived SetRogueLike(uint divisionMin, uint divisionRandMax, uint roomMinX,
            uint roomRandMaxX, uint roomMinY, uint roomRandMaxY) {
            this.divisionMin = divisionMin;
            this.divisionRandMax = divisionRandMax;
            this.roomMinX = roomMinX;
            this.roomRandMaxX = roomRandMaxX;
            this.roomMinY = roomMinY;
            this.roomRandMaxY = roomRandMaxY;
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

        /* Constructors */
        public RectBaseSimpleRogueLike() {
        } // = default();

        public RectBaseSimpleRogueLike(int roomValue) {
            this.roomValue = roomValue;
        }

        public RectBaseSimpleRogueLike(int roomValue, int roadValue) {
            this.roomValue = roomValue;
            this.roadValue = roadValue;
        }

        public RectBaseSimpleRogueLike(int roomValue, int roadValue, uint divisionMin,
            uint divisionRandMax, uint roomMinX, uint roomRandMaxX, uint roomMinY, uint roomRandMaxY) {
            this.roomValue = roomValue;
            this.roadValue = roadValue;
            this.divisionMin = divisionMin;
            this.divisionRandMax = divisionRandMax;
            this.roomMinX = roomMinX;
            this.roomRandMaxX = roomRandMaxX;
            this.roomMinY = roomMinY;
            this.roomRandMaxY = roomRandMaxY;
        }

        public RectBaseSimpleRogueLike(MatrixRange matrixRange) {
            this.startX = (uint) matrixRange.x;
            this.startY = (uint) matrixRange.y;
            this.width = (uint) matrixRange.w;
            this.height = (uint) matrixRange.h;
        }

        public RectBaseSimpleRogueLike(MatrixRange matrixRange, int roomValue) : this(matrixRange) {
            this.roomValue = roomValue;
        }

        public RectBaseSimpleRogueLike(MatrixRange matrixRange, int roomValue, int roadValue) : this(matrixRange,
            roomValue) {
            this.roadValue = roadValue;
        }

        public RectBaseSimpleRogueLike(MatrixRange matrixRange, int roomValue, int roadValue, uint divisionMin,
            uint divisionRandMax, uint roomMinX, uint roomRandMaxX, uint roomMinY, uint roomRandMaxY)
            : this(matrixRange, roomValue, roadValue) {
            this.roomValue = roomValue;
            this.roadValue = roadValue;
            this.divisionMin = divisionMin;
            this.divisionRandMax = divisionRandMax;
            this.roomMinX = roomMinX;
            this.roomRandMaxX = roomRandMaxX;
            this.roomMinY = roomMinY;
            this.roomRandMaxY = roomRandMaxY;
        }

        // Vector2とかを引数に取るコンストラクタがあってもいいかもしれない
        // 使い方を要検討.
    }
}