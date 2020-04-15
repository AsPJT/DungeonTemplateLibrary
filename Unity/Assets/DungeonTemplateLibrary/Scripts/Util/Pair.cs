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

namespace DTL.Util {
    /**
     * DTL.Util.Pair
     * System.Web.UIを模倣
     * 登録されている名前空間が気になるので自作する。
     */

    // 永続化することはないような気がするのでSerializable属性は付けないでおく
    public class Pair {
        public object First;
        public object Second;

        public Pair() {
        }

        public Pair(object x, object y) {
            First = x;
            Second = y;
        }
    }
}