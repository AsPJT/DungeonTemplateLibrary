/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_UTILITY_CAMERA_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_UTILITY_CAMERA_HPP

///// DTL Only /////

#include <DTL/Macros/constexpr.hpp>
#include <DTL/Base/Struct.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace utility { //"dtl::utility"名前空間に属する

		template<typename Float_, typename Int_>
		DTL_VERSIONING_CPP14_CONSTEXPR
		void setCameraLoop(const dtl::MatrixRange& win, const dtl::MatrixVec2& wp, const dtl::Vec2<Float_>& mc, dtl::Vec2 <Int_>& wssp, dtl::Vec2 <Int_>& wsss) noexcept {
			const Float_ wsx{ (mc.x - static_cast<Float_>(win.w / 2) / static_cast<Float_>(wp.x)) };
			const Float_ wsy{ (mc.y - static_cast<Float_>(win.h / 2) / static_cast<Float_>(wp.y)) };
			const Float_ wsxi{ static_cast<Float_>(static_cast<Int_>(wsx)) };
			const Float_ wsyi{ static_cast<Float_>(static_cast<Int_>(wsy)) };
			wssp.x = (wsxi == wsx) ? 0 : int(-(wsx - wsxi) * (wp.x) - float((wsx > 0.0f) ? 0 : int(wp.x)));
			wssp.y = (wsyi == wsy) ? 0 : int(-(wsy - wsyi) * (wp.y) - float((wsy > 0.0f) ? 0 : int(wp.y)));
			wsss.x = (wsxi == wsx) ? int(wsx) : float((wsx > 0.0f) ? int(wsx) : int(wsx) - 1);
			wsss.y = (wsyi == wsy) ? int(wsy) : float((wsy > 0.0f) ? int(wsy) : int(wsy) - 1);
		}

		template<typename Float_, typename Int_>
		DTL_VERSIONING_CPP14_CONSTEXPR
		void setCamera(const dtl::MatrixRange& win, const dtl::MatrixVec2& wp, const dtl::Vec2<Float_>& mc, dtl::Vec2 <Int_>& wssp, dtl::MatrixVec2& wsss) noexcept {
			const Float_ wsx{ (mc.x - static_cast<Float_>(win.w / 2) / static_cast<Float_>(wp.x)) };
			const Float_ wsy{ (mc.y - static_cast<Float_>(win.h / 2) / static_cast<Float_>(wp.y)) };
			const Float_ wsxi{ static_cast<Float_>(static_cast<Int_>(wsx)) };
			const Float_ wsyi{ static_cast<Float_>(static_cast<Int_>(wsy)) };
			wssp.x = (wsxi == wsx) ? 0 : static_cast<Int_>(-(wsx - wsxi) * (wp.x));
			wssp.y = (wsyi == wsy) ? 0 : static_cast<Int_>(-(wsy - wsyi) * (wp.y));
			dtl::Vec2<Int_> wss(static_cast<Int_>(wsx), static_cast<Int_>(wsy));
			if (wss.x < 0) {
				wssp.x += (-wss.x * static_cast<Int_>(wp.x));
				wss.x = 0;
			}
			if (wss.y < 0) {
				wssp.y += (-wss.y * static_cast<Int_>(wp.y));
				wss.y = 0;
			}
			wsss.x = static_cast<size_t>(wss.x);
			wsss.y = static_cast<size_t>(wss.y);
		}

	}
}

#endif //Included Dungeon Template Library