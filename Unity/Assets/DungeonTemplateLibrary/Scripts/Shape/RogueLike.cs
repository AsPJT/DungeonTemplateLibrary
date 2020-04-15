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
using DTL.Random;
using DTL.Util;
using System.Collections.Generic;
using System.Linq;
using MatrixRange = DTL.Base.Coordinate2DimensionalAndLength2Dimensional;


namespace DTL.Shape {
    /*#######################################################################################
        [概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
        [Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
    #######################################################################################*/

    class RogueLikeOutputNumber {
        public int x { get; set; }
        public int y { get; set; }
        public int w { get; set; }
        public int h { get; set; }

        public RogueLikeOutputNumber() {
        } // = default()

        public RogueLikeOutputNumber(int x, int y, int w, int h) {
            this.x = x;
            this.y = y;
            this.w = w;
            this.h = h;
        }
    }

    /* The type of array to store dungeon data is int[,] */

    public sealed class RogueLike : DTL.Range.RectBaseRogueLike<RogueLike>, IDrawer<int> {
        private DTLRandom rand = new DTLRandom();

        enum Direction : uint {
            North,
            South,
            West,
            East,
            Count,
        }

        private readonly uint directionCount = 4;

        /* Implement Drawer */
        public bool Draw(int[,] matrix) {
            return startX >= MatrixUtil.GetX(matrix) || startY >= MatrixUtil.GetY(matrix) ? false : DrawNormal(matrix);
        }

        public int[,] Create(int[,] matrix) {
            this.Draw(matrix);
            return matrix;
        }

        /* 基本処理 */
        bool DrawNormal(int[,] matrix) {
            if (this.roomRange.w < 1 || this.roomRange.h < 1 || this.wayRange.w < 1 || this.wayRange.h < 1)
                return false;

            var endX = MatrixUtil.GetX(matrix);
            var endY = MatrixUtil.GetY(matrix);

            var sizeX = endX - this.startX;
            var sizeY = endY - this.startY;

            var roomRect = new List<RogueLikeOutputNumber>();
            var branchPoint = new List<RogueLikeOutputNumber>();
            var isWay = new List<bool>();

            // 最初の部屋を生成
            if (!MakeRoom(matrix, sizeX, sizeY, roomRect, branchPoint, isWay, (int)sizeX / 2, (int)sizeY / 2,
                (Direction)rand.Next(directionCount))) return false;

            // 機能配置
            for (uint i = 1; i < maxWay; ++i) {
                if (!CreateNext2(matrix, sizeX, sizeY, roomRect, branchPoint, isWay)) break;
            }

            return true;
        }

        private bool CreateNext2(int[,] matrix, uint sizeX, uint sizeY, List<RogueLikeOutputNumber> roomRect,
            List<RogueLikeOutputNumber> branchPoint, List<bool> isWay) {
            /* 0xffff = 65535 までループを回す */
            for (int i = 0, r = 0; i < 65535; ++i) {
                if (!branchPoint.Any()) break;

                r = rand.Next(branchPoint.Count());
                int x = rand.Next(branchPoint[r].x, branchPoint[r].x + branchPoint[r].w);
                int y = rand.Next(branchPoint[r].y, branchPoint[r].y + branchPoint[r].h);

                // 方角カウンタ
                for (int j = 0; j < (int)Direction.Count; ++j) {
                    if (!CreateNext(matrix, sizeX, sizeY, roomRect, branchPoint, isWay, isWay[r], x, y,
                        (Direction)j)) continue;
                    branchPoint.RemoveAt(r);
                    isWay.RemoveAt(r);
                    return true;
                }
            }

            return false;
        }

        private bool CreateNext(int[,] matrix, uint sizeX, uint sizeY, List<RogueLikeOutputNumber> roomRect,
            List<RogueLikeOutputNumber> branchPoint, List<bool> isWayList, bool isWay, int x_, int y_, Direction dir_) {
            int dx = 0;
            int dy = 0;

            switch (dir_) {
                case Direction.North:
                    dy = 1;
                    break;
                case Direction.South:
                    dy = -1;
                    break;
                case Direction.West:
                    dx = 1;
                    break;
                case Direction.East:
                    dx = -1;
                    break;
            }

            // 範囲外参照(meta programming 部分)
            if (startX + x_ + dx < 0 || startX + x_ + dx >= sizeX || startY + y_ + dy < 0 ||
                startY + y_ + dy >= sizeY) {
                return false;
            }

            if (matrix[startY + y_ + dy, startX + x_ + dx] != rogueLikeList.roomId &&
                matrix[startY + y_ + dy, startX + x_ + dx] != rogueLikeList.wayId) return false;

            if (!isWay) {
                if (!MakeWay(matrix, sizeX, sizeY, branchPoint, isWayList, x_, y_, dir_)) return false;
                if (matrix[startY + y_ + dy, startX + x_ + dx] == rogueLikeList.roomId)
                    matrix[y_, x_] = rogueLikeList.entranceId;
                else matrix[y_, x_] = rogueLikeList.wayId;
                return true;
            }

            // 1/2
            if (rand.Probability(0.5)) {
                if (!MakeRoom(matrix, sizeX, sizeY, roomRect, branchPoint, isWayList, x_, y_, dir_)) return false;
                matrix[y_, x_] = rogueLikeList.entranceId;
                return true;
            }

            // 通路を生成
            if (!MakeWay(matrix, sizeX, sizeY, branchPoint, isWayList, x_, y_, dir_)) return false;
            if (matrix[startY + y_ + dy, startX + x_ + dx] == rogueLikeList.roomId) {
                matrix[y_, x_] = rogueLikeList.entranceId;
            } else {
                matrix[y_, x_] = rogueLikeList.wayId;
            }

            return true;
        }

        private bool MakeWay(int[,] matrix, uint sizeX, uint sizeY, List<RogueLikeOutputNumber> branchPoint,
            List<bool> isWay,
            int x_, int y_, Direction dir_) {
            var way_ = new RogueLikeOutputNumber();
            way_.x = x_;
            way_.y = y_;
            
            // 左右
            if (rand.Probability(0.5)) {
                way_.w = rand.Next(wayRange.x, wayRange.x + wayRange.w);
                way_.h = 1;
                switch (dir_) {
                    case Direction.North:
                        way_.y = y_ - 1;
                        if (rand.Probability(0.5)) way_.x = x_ - way_.w + 1;
                        break;
                    case Direction.South:
                        way_.y = y_ + 1;
                        if (rand.Probability(0.5)) way_.x = x_ - way_.w + 1;
                        break;
                    case Direction.West:
                        way_.x = x_ - way_.w;
                        break;
                    case Direction.East:
                        way_.x = x_ + 1;
                        break;
                }
            }
            // 上下
            else {
                way_.w = 1;
                way_.h = rand.Next(wayRange.y, wayRange.y + wayRange.h);

                switch (dir_) {
                    case Direction.North:
                        way_.y = y_ - way_.h;
                        break;
                    case Direction.South:
                        way_.y = y_ + 1;
                        break;
                    case Direction.West:
                        way_.x = x_ - 1;
                        if (rand.Probability(0.5)) way_.y = y_ - way_.h + 1;
                        break;
                    case Direction.East:
                        way_.x = x_ + 1;
                        if (rand.Probability(0.5)) way_.y = y_ - way_.h + 1;
                        break;
                }
            }

            if (!PlaceOutputNumber(matrix, sizeX, sizeY, way_, rogueLikeList.wayId)) return false;
            if (dir_ != Direction.South && way_.w != 1) {
                branchPoint.Add(new RogueLikeOutputNumber(way_.x, way_.y - 1, way_.w, 1));
                isWay.Add(true);
            }

            if (dir_ != Direction.North && way_.w != 1) {
                branchPoint.Add(new RogueLikeOutputNumber(way_.x, way_.y + way_.h, way_.w, 1));
                isWay.Add(true);
            }

            if (dir_ != Direction.East && way_.h != 1) {
                branchPoint.Add(new RogueLikeOutputNumber(way_.x - 1, way_.y, 1, way_.h));
                isWay.Add(true);
            }

            if (dir_ != Direction.West && way_.h != 1) {
                branchPoint.Add(new RogueLikeOutputNumber(way_.x + way_.w, way_.y, 1, way_.h));
                isWay.Add(true);
            }

            return true;
        }

        private bool MakeRoom(int[,] matrix, uint sizeX, uint sizeY, List<RogueLikeOutputNumber> roomRect,
            List<RogueLikeOutputNumber> branchPoint, List<bool> isWay, int x_, int y_, Direction dir_,
            bool firstRoom = false) {
            var room = new RogueLikeOutputNumber();
            room.w = rand.Next(roomRange.x, roomRange.x + roomRange.w);
            room.h = rand.Next(roomRange.y, roomRange.y + roomRange.h);

            switch (dir_) {
                case Direction.North:
                    room.x = x_ - room.w / 2;
                    room.y = y_ - room.h;
                    break;
                case Direction.South:
                    room.x = x_ - room.w / 2;
                    room.y = y_ + 1;
                    break;
                case Direction.West:
                    room.x = x_ - room.w;
                    room.y = y_;// - room.h / 2; Bug? 道の端から部屋を生成するときに、DirectionがWest or Eastだと基点のY軸が上にずれて部屋の生成と道がつながらなくなってしまう。
                    break;
                case Direction.East:
                    room.x = x_ + 1;
                    room.y = y_;// + room.h / 2; Bug? Direction.Westと同様。
                    break;
            }

            if (PlaceOutputNumber(matrix, sizeX, sizeY, room, rogueLikeList.roomId)) {
                roomRect.Add(room);
                if (dir_ != Direction.South || firstRoom) {
                    branchPoint.Add(new RogueLikeOutputNumber(room.x, room.y - 1, room.w, 1));
                    isWay.Add(false);
                }

                if (dir_ != Direction.North || firstRoom) {
                    branchPoint.Add(new RogueLikeOutputNumber(room.x, room.y + room.h, room.w, 1));
                    isWay.Add(false);
                }

                if (dir_ != Direction.East || firstRoom) {
                    branchPoint.Add(new RogueLikeOutputNumber(room.x - 1, room.y, 1, room.h));
                    isWay.Add(false);
                }

                if (dir_ != Direction.West || firstRoom) {
                    branchPoint.Add(new RogueLikeOutputNumber(room.x + room.w, room.y, 1, room.h));
                    isWay.Add(false);
                }

                return true;
            }

            return false;
        }

        private bool PlaceOutputNumber(int[,] matrix, uint sizeX, uint sizeY, RogueLikeOutputNumber rect, int tile) {
            if (rect.x < 1 || rect.y < 1 || rect.x + rect.w > sizeX - 1 || rect.y + rect.h > sizeY - 1) {
                return false;
            }

            for (int y = rect.y; y < rect.y + rect.h; ++y) {
                for (int x = rect.x; x < rect.x + rect.w; ++x) {
                    if (matrix[startY + y, startX + x] != rogueLikeList.outsideWallId) {
                        return false;
                    }
                }
            }

            for (int y = rect.y - 1; y < rect.y + rect.h + 1; ++y) {
                for (int x = rect.x - 1; x < rect.x + rect.w + 1; ++x) {
                    if (y == rect.y - 1 || x == rect.x - 1 || y == rect.y + rect.h || x == rect.x + rect.w) {
                        matrix[y, x] = rogueLikeList.insideWallId;
                    } else {
                        matrix[y, x] = tile;
                    }
                }
            }

            return true;
        }

        /* Constructors */

        public RogueLike() {
        } // = default();

        public RogueLike(MatrixRange matrixRange) : base(matrixRange) {
        }

        public RogueLike(uint startX, uint startY, uint width, uint height) : base(startX, startY, width, height) {
        }

        public RogueLike(RogueLikeList drawValue) : base(drawValue) {
        }

        public RogueLike(RogueLikeList drawValue, uint maxWay) : base(drawValue, maxWay) {
        }

        public RogueLike(RogueLikeList drawValue, uint maxWay, MatrixRange roomRange) : base(drawValue, maxWay,
            roomRange) {
        }

        public RogueLike(RogueLikeList drawValue, uint maxWay, MatrixRange roomRange, MatrixRange wayRange) : base(
            drawValue, maxWay, roomRange, wayRange) {
        }

        public RogueLike(int outsideWallId, int insideWallId, int roomId, int entranceId, int wayId) : base(
            outsideWallId, insideWallId, roomId, entranceId, wayId) {
        }

        public RogueLike(int outsideWallId, int insideWallId, int roomId, int entranceId, int wayId, uint maxWay) :
            base(outsideWallId, insideWallId, roomId, entranceId, wayId, maxWay) {
        }

        public RogueLike(int outsideWallId, int insideWallId, int roomId, int entranceId, int wayId, uint maxWay,
            MatrixRange roomRange) : base(outsideWallId, insideWallId, roomId, entranceId, wayId, maxWay, roomRange) {
        }

        public RogueLike(int outsideWallId, int insideWallId, int roomId, int entranceId, int wayId, uint maxWay,
            MatrixRange roomRange, MatrixRange wayRange) : base(outsideWallId, insideWallId, roomId, entranceId, wayId,
            maxWay,
            roomRange, wayRange) {
        }

        public RogueLike(MatrixRange matrixRange, RogueLikeList drawValue, uint maxWay) : base(matrixRange, drawValue,
            maxWay) {
        }

        public RogueLike(MatrixRange matrixRange, RogueLikeList drawValue, uint maxWay, MatrixRange roomRange) : base(
            matrixRange, drawValue, maxWay, roomRange) {
        }

        public RogueLike(MatrixRange matrixRange, RogueLikeList drawValue, uint maxWay, MatrixRange roomRange,
            MatrixRange wayRange) : base(matrixRange, drawValue, maxWay, roomRange, wayRange) {
        }

        public RogueLike(uint startX, uint startY, uint width, uint height, RogueLikeList drawValue,
            uint maxWay) : base(startX, startY, width, height, drawValue, maxWay) {
        }

        public RogueLike(uint startX, uint startY, uint width, uint height, RogueLikeList drawValue,
            uint maxWay, MatrixRange roomRange) : base(startX, startY, width, height, drawValue, maxWay, roomRange) {
        }

        public RogueLike(uint startX, uint startY, uint width, uint height, RogueLikeList drawValue,
            uint maxWay, MatrixRange roomRange, MatrixRange wayRange) : base(startX, startY, width, height, drawValue,
            maxWay, roomRange, wayRange) {
        }
    }
}       
