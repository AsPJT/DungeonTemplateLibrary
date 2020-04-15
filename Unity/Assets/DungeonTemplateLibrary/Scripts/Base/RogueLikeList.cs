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

namespace DTL.Base {
    /*#######################################################################################
        [概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
        [Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
    #######################################################################################*/
    public class RogueLikeList {
        public int outsideWallId { get; set; }
        public int insideWallId { get; set; }
        public int roomId { get; set; }
        public int entranceId { get; set; }
        public int wayId { get; set; }

        public RogueLikeList() { } // = default()

        public RogueLikeList(int wallId, int wayId) {
            this.outsideWallId = wallId;
            this.insideWallId = wallId;
            this.roomId = wayId;
            this.entranceId = wayId;
            this.wayId = wayId;
        }

        public RogueLikeList(int wallId, int roomId, int wayId) {
            this.outsideWallId = wallId;
            this.insideWallId = wallId;
            this.roomId = roomId;
            this.entranceId = roomId;
            this.wayId = wayId;
        }

        public RogueLikeList(int wallId, int roomId, int entranceId, int wayId) {
            this.outsideWallId = wallId;
            this.insideWallId = wallId;
            this.roomId = roomId;
            this.entranceId = entranceId;
            this.wayId = wayId;
        }

        public RogueLikeList(int outsideWallId, int insideWallId, int roomId, int entranceId, int wayId) {
            this.outsideWallId = outsideWallId;
            this.insideWallId = insideWallId;
            this.roomId = roomId;
            this.entranceId = entranceId;
            this.wayId = wayId;
        }

        public RogueLikeList DefaultRogueLikeList() => new RogueLikeList(0, 1, 2, 3, 4);
    }
}
