/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_UNREAL_ENGINE_BLUEPRINT_FUNCTION_LIBRARY_DTL_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_UNREAL_ENGINE_BLUEPRINT_FUNCTION_LIBRARY_DTL_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::PerlinIsland-(形状クラス)/
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::PerlinIsland-in-Unreal-Engine-(形状クラス)/
#######################################################################################*/

#ifdef DTL_UNREAL_ENGINE_API

UCLASS()
class DTL_UNREAL_ENGINE_API UDungeonTemplateLibraryUnrealEngine : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = DTL, meta = (HidePin = "worldContextObject_", DefaultToSelf = "worldContextObject_"))
		static bool LandscapeMazeDig(const UObject* worldContextObject_, int32 max_value, int32 min_value) {

		dtl::shape::MazeDig<uint16> generator(
			static_cast<uint16>(max_value),
			static_cast<uint16>(min_value));

		::UWorld* world{ worldContextObject_->GetWorld() };
		for (TActorIterator<ALandscape> actorItr(world); actorItr; ++actorItr) {
			::ALandscape* landscape{ *actorItr };
			if (landscape == nullptr) continue;
			::ULandscapeInfo::RecreateLandscapeInfo(world, false);

			::FIntRect rect{ landscape->GetBoundingRect() };
			const int32 w{ rect.Width() + 1 };
			const int32 h{ rect.Height() + 1 };

			::TArray<uint16> Data;
			Data.Init(min_value, w * h);
			generator.drawArray(Data, w, h);
			LandscapeEditorUtils::SetHeightmapData(landscape, Data);
			return true;
		}
		return false;
	}
};

#endif

#endif //Included Dungeon Template Library
