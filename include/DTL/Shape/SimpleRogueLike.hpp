/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_SIMPLE_ROGUE_LIKE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_SIMPLE_ROGUE_LIKE_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::SimpleRogueLike-(形状クラス)/
#######################################################################################*/

#include <array>
#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Random/RandomEngine.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/NumericLimits.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Type/SSizeT.hpp>
#include <DTL/Type/Vector.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace shape { //"dtl::shape"名前空間に属する

		//マスを指定した数値で埋める
		template<typename Matrix_Var_>
		class SimpleRogueLike {
		private:

			template<typename Int_>
			constexpr Int_ absTemplate(const Int_& value_) const noexcept {
				return (value_ < 0) ? (-value_) : value_;
			}

			enum : ::dtl::type::ssize {
				RL_COUNT_X,
				RL_COUNT_Y
			};

//生成される部屋の数 (正確に言うと生成される区域の数)---
//マップの区分け最小数
//マップの区分け数加算
//生成される部屋のサイズ---
//部屋のX座標の最小サイズ
//部屋のX座標のサイズ加算
//部屋のY座標の最小サイズ
//部屋のY座標のサイズ加算

			using StartEndArray = ::std::array<::dtl::type::size, 4>;

			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using StartEnd = DTL_TYPE_VECTOR<StartEndArray>;


			///// メンバ変数 (Member Variable) /////

			Index_Size start_x{};
			Index_Size start_y{};
			Index_Size width{};
			Index_Size height{};

			Matrix_Var_ room_value{};
			Matrix_Var_ road_value{};

			::dtl::type::size division_min{ 3 };
			::dtl::type::size division_rand_max{ 4 };
			::dtl::type::size room_min_x{ 5 };
			::dtl::type::size room_rand_max_x{ 2 };
			::dtl::type::size room_min_y{ 5 };
			::dtl::type::size room_rand_max_y{ 2 };


			///// 基本処理 /////

			//Normal
			template<typename Matrix_, typename ...Args_>
				bool drawNormal(Matrix_ && matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ...) const noexcept {
				//マップの区分け数 (部屋の個数) 0~nまでの部屋ID
				const ::dtl::type::size mapDivCount{ this->division_min + DTL_RANDOM_ENGINE.get<::dtl::type::size>(this->division_rand_max) }; //マップの区分け数 (部屋の個数) 0~yまでの部屋ID

				//マップの区域 [部屋ID][X終点 , Y終点 , X始点 , Y始点]
				StartEnd dungeon_division{ ::dtl::type::makeVector<StartEndArray>(mapDivCount, StartEndArray()) };
				//マップの部屋 [部屋ID][X終点 , Y終点 , X始点 , Y始点]
				StartEnd dungeon_room{ ::dtl::type::makeVector<StartEndArray>(mapDivCount, StartEndArray()) };
				//マップの道 [部屋ID(前)][繋がる先の部屋ID(後) , (0.X座標 , 1.Y座標) , (前)側の通路の位置 , (後)側の通路の位置]
				StartEnd dungeon_road{ ::dtl::type::makeVector<StartEndArray>(mapDivCount, StartEndArray()) };

				dungeon_division[0][0] = end_y_ - 1; //マップの区分け初期サイズX終点 (マップの大きさX軸)
				dungeon_division[0][1] = end_x_ - 1; //マップの区分け初期サイズY終点 (マップの大きさY軸)
				dungeon_division[0][2] = this->start_x + 1; //マップの区分け初期サイズX始点 (マップの大きさX軸)
				dungeon_division[0][3] = this->start_y + 1; //マップの区分け初期サイズY始点 (マップの大きさY軸)

				dungeon_road[0][0] = (DTL_TYPE_NUMERIC_LIMITS<::dtl::type::size>::DTL_TYPE_NUMERIC_LIMITS_MAX)();
				dungeon_road[0][1] = (DTL_TYPE_NUMERIC_LIMITS<::dtl::type::size>::DTL_TYPE_NUMERIC_LIMITS_MAX)();

				createDivision(dungeon_road,dungeon_division, mapDivCount);
				createRoom(dungeon_room, dungeon_division,mapDivCount);
				this->assignRoom(dungeon_room, matrix_, mapDivCount);
				createRoad(dungeon_road,dungeon_room, dungeon_division, matrix_, mapDivCount);
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
				bool drawLayerNormal(Matrix_ && matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ...) const noexcept {
				//マップの区分け数 (部屋の個数) 0~nまでの部屋ID
				const ::dtl::type::size mapDivCount{ this->division_min + DTL_RANDOM_ENGINE.get<::dtl::type::size>(this->division_rand_max) }; //マップの区分け数 (部屋の個数) 0~yまでの部屋ID

				//マップの区域 [部屋ID][X終点 , Y終点 , X始点 , Y始点]
				StartEnd dungeon_division{ ::dtl::type::makeVector<StartEndArray>(mapDivCount, StartEndArray()) };
				//マップの部屋 [部屋ID][X終点 , Y終点 , X始点 , Y始点]
				StartEnd dungeon_room{ ::dtl::type::makeVector<StartEndArray>(mapDivCount, StartEndArray()) };
				//マップの道 [部屋ID(前)][繋がる先の部屋ID(後) , (0.X座標 , 1.Y座標) , (前)側の通路の位置 , (後)側の通路の位置]
				StartEnd dungeon_road{ ::dtl::type::makeVector<StartEndArray>(mapDivCount, StartEndArray()) };

				dungeon_division[0][0] = end_y_ - 1; //マップの区分け初期サイズX終点 (マップの大きさX軸)
				dungeon_division[0][1] = end_x_ - 1; //マップの区分け初期サイズY終点 (マップの大きさY軸)
				dungeon_division[0][2] = this->start_x + 1; //マップの区分け初期サイズX始点 (マップの大きさX軸)
				dungeon_division[0][3] = this->start_y + 1; //マップの区分け初期サイズY始点 (マップの大きさY軸)

				dungeon_road[0][0] = (DTL_TYPE_NUMERIC_LIMITS<::dtl::type::size>::DTL_TYPE_NUMERIC_LIMITS_MAX)();
				dungeon_road[0][1] = (DTL_TYPE_NUMERIC_LIMITS<::dtl::type::size>::DTL_TYPE_NUMERIC_LIMITS_MAX)();

				createDivision(dungeon_road,dungeon_division, mapDivCount);
				createRoom(dungeon_room, dungeon_division,mapDivCount);
				this->assignRoomLayer(dungeon_room, matrix_, mapDivCount, layer_);
				createRoadLayer(dungeon_road, dungeon_room, dungeon_division, matrix_, mapDivCount, layer_);
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
				bool drawArray(Matrix_ && matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Args_ && ...) const noexcept {
				//マップの区分け数 (部屋の個数) 0~nまでの部屋ID
				const ::dtl::type::size mapDivCount{ this->division_min + DTL_RANDOM_ENGINE.get<::dtl::type::size>(this->division_rand_max) }; //マップの区分け数 (部屋の個数) 0~yまでの部屋ID

				//マップの区域 [部屋ID][X終点 , Y終点 , X始点 , Y始点]
				StartEnd dungeon_division{ ::dtl::type::makeVector<StartEndArray>(mapDivCount, StartEndArray()) };
				//マップの部屋 [部屋ID][X終点 , Y終点 , X始点 , Y始点]
				StartEnd dungeon_room{ ::dtl::type::makeVector<StartEndArray>(mapDivCount, StartEndArray()) };
				//マップの道 [部屋ID(前)][繋がる先の部屋ID(後) , (0.X座標 , 1.Y座標) , (前)側の通路の位置 , (後)側の通路の位置]
				StartEnd dungeon_road{ ::dtl::type::makeVector<StartEndArray>(mapDivCount, StartEndArray()) };

				dungeon_division[0][0] = end_y_ - 1; //マップの区分け初期サイズX終点 (マップの大きさX軸)
				dungeon_division[0][1] = end_x_ - 1; //マップの区分け初期サイズY終点 (マップの大きさY軸)
				dungeon_division[0][2] = this->start_x + 1; //マップの区分け初期サイズX始点 (マップの大きさX軸)
				dungeon_division[0][3] = this->start_y + 1; //マップの区分け初期サイズY始点 (マップの大きさY軸)

				dungeon_road[0][0] = (DTL_TYPE_NUMERIC_LIMITS<::dtl::type::size>::DTL_TYPE_NUMERIC_LIMITS_MAX)();
				dungeon_road[0][1] = (DTL_TYPE_NUMERIC_LIMITS<::dtl::type::size>::DTL_TYPE_NUMERIC_LIMITS_MAX)();

				createDivision(dungeon_road,dungeon_division,mapDivCount);
				createRoom(dungeon_room, dungeon_division,mapDivCount);
				this->assignRoomArray(dungeon_room, matrix_, mapDivCount, max_x_);
				createRoadArray(dungeon_road, dungeon_room, dungeon_division, matrix_, mapDivCount, max_x_);
				return true;
			}

			void createDivision(StartEnd& dungeon_road,StartEnd& dungeon_division, const ::dtl::type::size mapDivCount) const noexcept {

				//マップを区分けしていく処理(区域を分割する処理)
				::dtl::type::size division_After{};
				::dtl::type::ssize count{}; //(0:X, 1:Y) X軸で分けるかY軸で分けるか決める
				for (::dtl::type::size i{ 1 }; i < mapDivCount; ++i) {

					//今まで作った区分けをランダムに指定(指定した区域をさらに区分けする)
					division_After = DTL_RANDOM_ENGINE.get<::dtl::type::size>(i);

					//指定した区域のXとYの長さによって、分割する向きを決める(長いほうを分割する)
					if (dungeon_division[division_After][0] - dungeon_division[division_After][2] > dungeon_division[division_After][1] - dungeon_division[division_After][3]) count = RL_COUNT_X;
					else count = RL_COUNT_Y;

					if (dungeon_division[division_After][count] - dungeon_division[division_After][count + 2] < division_rand_max * 2 + 8) {
						::dtl::type::size k{};
						for (::dtl::type::size j{ 1 }; j < mapDivCount; ++j) {
							if (dungeon_division[j][0] - dungeon_division[j][2] > k) {
								k = dungeon_division[j][0] - dungeon_division[j][2];
								division_After = j;
								count = RL_COUNT_X;
							}
							if (dungeon_division[j][1] - dungeon_division[j][3] > k) {
								k = dungeon_division[j][1] - dungeon_division[j][3];
								division_After = j;
								count = RL_COUNT_Y;
							}
						}
					}

					dungeon_road[i][0] = division_After;
					dungeon_road[i][1] = count;

					for (::dtl::type::size j{ 1 }; j < i; ++j)
						if (dungeon_road[j][0] == division_After) dungeon_road[j][0] = i;

					//count軸の設定
					//0.軸の右端(iR)の座標(division_After*R/3~2division_After*R/3)
					dungeon_division[i][count] = dungeon_division[division_After][count + 2];
					dungeon_division[i][count] += ((dungeon_division[division_After][count] - dungeon_division[division_After][count + 2]) / 3);
					dungeon_division[i][count] += DTL_RANDOM_ENGINE.get<::dtl::type::size>(1, (dungeon_division[division_After][count] - dungeon_division[division_After][count + 2]) / 3);

					dungeon_division[i][count + 2] = dungeon_division[division_After][count + 2]; //0.軸の左端(iL)の座標(division_AfterL)
					dungeon_division[division_After][count + 2] = dungeon_division[i][count]; //division_After軸の左端(division_AfterL)の座標(iR)

					//countとは逆の軸の設定
					dungeon_division[i][this->absTemplate(count - 1)] = dungeon_division[division_After][this->absTemplate(count - 1)]; //軸の右端(iR)の座標(division_AfterR)
					dungeon_division[i][this->absTemplate(count - 1) + 2] = dungeon_division[division_After][this->absTemplate(count - 1) + 2]; //軸の左端(iL)の座標(division_AfterL)
				}

			}

			void createRoom(StartEnd& dungeon_room,const StartEnd& dungeon_division, const ::dtl::type::size mapDivCount) const noexcept {

				//部屋を生成する処理
				for (::dtl::type::size i{}; i < mapDivCount; ++i) {//区分け
					dungeon_room[i][2] = dungeon_division[i][2]; //区分けX始点をマップX始点へ代入
					dungeon_room[i][3] = dungeon_division[i][3]; //区分けY始点をマップY始点へ代入

					//X座標の部屋の長さを指定
					dungeon_room[i][0] = dungeon_division[i][2] + this->room_min_y + DTL_RANDOM_ENGINE.get<::dtl::type::size>(this->room_rand_max_x);
					if (dungeon_division[i][0] - dungeon_division[i][2] < dungeon_room[i][0] - dungeon_room[i][2] + 5) {
						dungeon_room[i][0] = dungeon_division[i][0] - 4;
						if (dungeon_division[i][0] - dungeon_division[i][2] < dungeon_room[i][0] - dungeon_room[i][2] + 5) {
							dungeon_room[i][0] = dungeon_division[i][2] + 1;
						}
					}

					dungeon_room[i][1] = dungeon_division[i][3] + this->room_min_x + DTL_RANDOM_ENGINE.get<::dtl::type::size>(this->room_rand_max_y);
					if (dungeon_division[i][1] - dungeon_division[i][3] < dungeon_room[i][1] - dungeon_room[i][3] + 5) {
						dungeon_room[i][1] = dungeon_division[i][1] - 4;
						if (dungeon_division[i][1] - dungeon_division[i][3] < dungeon_room[i][1] - dungeon_room[i][3] + 5) {
							dungeon_room[i][1] = dungeon_division[i][3] + 1;
						}
					}

					if (dungeon_room[i][0] - dungeon_division[i][2] <= 1 || dungeon_room[i][1] - dungeon_division[i][3] <= 1) {
						dungeon_room[i][0] = dungeon_division[i][2] + 1;
						dungeon_room[i][1] = dungeon_division[i][3] + 1;
					}
					const ::dtl::type::size l{ DTL_RANDOM_ENGINE.get<::dtl::type::size>(1,dungeon_division[i][0] - dungeon_room[i][0] - 5) + 2 };
					const ::dtl::type::size n{ DTL_RANDOM_ENGINE.get<::dtl::type::size>(1,dungeon_division[i][1] - dungeon_room[i][1] - 5) + 2 };
					dungeon_room[i][0] += l;
					dungeon_room[i][2] += l;
					dungeon_room[i][1] += n;
					dungeon_room[i][3] += n;


				}

			}

			template <typename Matrix_>
			void assignRoom(const StartEnd& dungeon_room, Matrix_&& matrix_, const ::dtl::type::size mapDivCount) const noexcept {
				//部屋を生成する処理
				for (::dtl::type::size i{}; i < mapDivCount; ++i)
					for (::dtl::type::size j{ dungeon_room[i][2] }; j < dungeon_room[i][0]; ++j)
						for (::dtl::type::size k{ dungeon_room[i][3] }; k < dungeon_room[i][1]; ++k)
							matrix_[j][k] = this->room_value;
			}
			template <typename Matrix_>
			void assignRoomLayer(const StartEnd& dungeon_room, Matrix_&& matrix_, const ::dtl::type::size mapDivCount, const Index_Size layer_) const noexcept {
				//部屋を生成する処理
				for (::dtl::type::size i{}; i < mapDivCount; ++i)
					for (::dtl::type::size j{ dungeon_room[i][2] }; j < dungeon_room[i][0]; ++j)
						for (::dtl::type::size k{ dungeon_room[i][3] }; k < dungeon_room[i][1]; ++k)
							matrix_[j][k][layer_] = this->room_value;
			}
			template <typename Matrix_>
			void assignRoomArray(const StartEnd& dungeon_room, Matrix_&& matrix_, const ::dtl::type::size mapDivCount, const Index_Size max_x_) const noexcept {
				//部屋を生成する処理
				for (::dtl::type::size i{}; i < mapDivCount; ++i)
					for (::dtl::type::size j{ dungeon_room[i][2] }; j < dungeon_room[i][0]; ++j)
						for (::dtl::type::size k{ dungeon_room[i][3] }; k < dungeon_room[i][1]; ++k)
							matrix_[j * max_x_ + k] = this->room_value;
			}


			//通路を生成する処理
			//通路は２部屋間の細い道のことを指す。
			//通路を作るために２部屋をそれぞれ前(Before)と後(After)で分ける。
			//for文で全ての部屋をチェックし、前後の部屋を繋ぐ通路を作る。
			//まず、前の通路を作り、次に後の通路を作る。
			//最後に前と後の通路を繋げる。

			template <typename Matrix_>
			void createRoad(StartEnd& dungeon_road, const StartEnd& dungeon_room, const StartEnd& dungeon_division, Matrix_&& matrix_, const ::dtl::type::size mapDivCount) const noexcept {
				for (::dtl::type::size roomBefore{}, roomAfter{}; roomBefore < mapDivCount; ++roomBefore) {
					roomAfter = dungeon_road[roomBefore][0];
					//X座標の通路
					switch (dungeon_road[roomBefore][1]) {
					case RL_COUNT_X:
						dungeon_road[roomBefore][2] = DTL_RANDOM_ENGINE.get<::dtl::type::size>(dungeon_room[roomBefore][1] - dungeon_room[roomBefore][3] - 1); //前側の通路の位置
						dungeon_road[roomBefore][3] = DTL_RANDOM_ENGINE.get<::dtl::type::size>(dungeon_room[roomAfter][1] - dungeon_room[roomAfter][3] - 1); //後側の通路の位置
						//前の通路
						for (::dtl::type::size j{ dungeon_room[roomBefore][0] }; j < dungeon_division[roomBefore][0]; ++j)
							matrix_[j][dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3]] = this->road_value; //通路をマップチップに線画
						//後の通路
						for (::dtl::type::size j{ dungeon_division[roomAfter][2] }; j < dungeon_room[roomAfter][2]; ++j)
							matrix_[j][dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3]] = this->road_value; //通路をマップチップに線画
						//通路をつなぐ
						for (::dtl::type::size j{ dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3] }; j <= dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3]; ++j)
							matrix_[dungeon_division[roomBefore][0]][j] = this->road_value; //通路をマップチップに線画 2から5(上から下)
						for (::dtl::type::size j{ dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3] }; j <= dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3]; ++j)
							matrix_[dungeon_division[roomBefore][0]][j] = this->road_value; //通路をマップチップに線画 5から2(下から上)
						break;
					case RL_COUNT_Y:
						dungeon_road[roomBefore][2] = DTL_RANDOM_ENGINE.get<::dtl::type::size>(dungeon_room[roomBefore][0] - dungeon_room[roomBefore][2] - 1); //前側の通路の位置
						dungeon_road[roomBefore][3] = DTL_RANDOM_ENGINE.get<::dtl::type::size>(dungeon_room[roomAfter][0] - dungeon_room[roomAfter][2] - 1); //後側の通路の位置
						//前の通路
						for (::dtl::type::size j{ dungeon_room[roomBefore][1] }; j < dungeon_division[roomBefore][1]; ++j)
							matrix_[dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2]][j] = this->road_value; //通路をマップチップに線画
						//後の通路
						for (::dtl::type::size j{ dungeon_division[roomAfter][3] }; j < dungeon_room[roomAfter][3]; ++j)
							matrix_[dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2]][j] = this->road_value; //通路をマップチップに線画
						//通路をつなぐ
						for (::dtl::type::size j{ dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2] }; j <= dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2]; ++j)
							matrix_[j][dungeon_division[roomBefore][1]] = this->road_value; //通路をマップチップに線画
						for (::dtl::type::size j{ dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2] }; j <= dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2]; ++j)
							matrix_[j][dungeon_division[roomBefore][1]] = this->road_value; //通路をマップチップに線画
						break;
					}
				}
			}
			template <typename Matrix_>
			void createRoadLayer(StartEnd& dungeon_road, const StartEnd& dungeon_room, const StartEnd& dungeon_division, Matrix_&& matrix_, const ::dtl::type::size mapDivCount, const Index_Size layer_) const noexcept {
				for (::dtl::type::size roomBefore{}, roomAfter{}; roomBefore < mapDivCount; ++roomBefore) {
					roomAfter = dungeon_road[roomBefore][0];
					//X座標の通路
					switch (dungeon_road[roomBefore][1]) {
					case RL_COUNT_X:
						dungeon_road[roomBefore][2] = DTL_RANDOM_ENGINE.get<::dtl::type::size>(dungeon_room[roomBefore][1] - dungeon_room[roomBefore][3] - 1); //前側の通路の位置
						dungeon_road[roomBefore][3] = DTL_RANDOM_ENGINE.get<::dtl::type::size>(dungeon_room[roomAfter][1] - dungeon_room[roomAfter][3] - 1); //後側の通路の位置
						//前の通路
						for (::dtl::type::size j{ dungeon_room[roomBefore][0] }; j < dungeon_division[roomBefore][0]; ++j)
							matrix_[j][dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3]][layer_] = this->road_value; //通路をマップチップに線画
						//後の通路
						for (::dtl::type::size j{ dungeon_division[roomAfter][2] }; j < dungeon_room[roomAfter][2]; ++j)
							matrix_[j][dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3]][layer_] = this->road_value; //通路をマップチップに線画
						//通路をつなぐ
						for (::dtl::type::size j{ dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3] }; j <= dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3]; ++j)
							matrix_[dungeon_division[roomBefore][0]][j][layer_] = this->road_value; //通路をマップチップに線画 2から5(上から下)
						for (::dtl::type::size j{ dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3] }; j <= dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3]; ++j)
							matrix_[dungeon_division[roomBefore][0]][j][layer_] = this->road_value; //通路をマップチップに線画 5から2(下から上)
						break;
					case RL_COUNT_Y:
						dungeon_road[roomBefore][2] = DTL_RANDOM_ENGINE.get<::dtl::type::size>(dungeon_room[roomBefore][0] - dungeon_room[roomBefore][2] - 1); //前側の通路の位置
						dungeon_road[roomBefore][3] = DTL_RANDOM_ENGINE.get<::dtl::type::size>(dungeon_room[roomAfter][0] - dungeon_room[roomAfter][2] - 1); //後側の通路の位置
						//前の通路
						for (::dtl::type::size j{ dungeon_room[roomBefore][1] }; j < dungeon_division[roomBefore][1]; ++j)
							matrix_[dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2]][j][layer_] = this->road_value; //通路をマップチップに線画
						//後の通路
						for (::dtl::type::size j{ dungeon_division[roomAfter][3] }; j < dungeon_room[roomAfter][3]; ++j)
							matrix_[dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2]][j][layer_] = this->road_value; //通路をマップチップに線画
						//通路をつなぐ
						for (::dtl::type::size j{ dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2] }; j <= dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2]; ++j)
							matrix_[j][dungeon_division[roomBefore][1]][layer_] = this->road_value; //通路をマップチップに線画
						for (::dtl::type::size j{ dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2] }; j <= dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2]; ++j)
							matrix_[j][dungeon_division[roomBefore][1]][layer_] = this->road_value; //通路をマップチップに線画
						break;
					}
				}
			}
			template <typename Matrix_>
			void createRoadArray(StartEnd& dungeon_road, const StartEnd& dungeon_room, const StartEnd& dungeon_division, Matrix_&& matrix_, const ::dtl::type::size mapDivCount, const Index_Size max_x_) const noexcept {
				for (::dtl::type::size roomBefore{}, roomAfter{}; roomBefore < mapDivCount; ++roomBefore) {
					roomAfter = dungeon_road[roomBefore][0];
					//X座標の通路
					switch (dungeon_road[roomBefore][1]) {
					case RL_COUNT_X:
						dungeon_road[roomBefore][2] = DTL_RANDOM_ENGINE.get<::dtl::type::size>(dungeon_room[roomBefore][1] - dungeon_room[roomBefore][3] - 1); //前側の通路の位置
						dungeon_road[roomBefore][3] = DTL_RANDOM_ENGINE.get<::dtl::type::size>(dungeon_room[roomAfter][1] - dungeon_room[roomAfter][3] - 1); //後側の通路の位置
						//前の通路
						for (::dtl::type::size j{ dungeon_room[roomBefore][0] }; j < dungeon_division[roomBefore][0]; ++j)
							matrix_[j * max_x_ + dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3]] = this->road_value; //通路をマップチップに線画
						//後の通路
						for (::dtl::type::size j{ dungeon_division[roomAfter][2] }; j < dungeon_room[roomAfter][2]; ++j)
							matrix_[j * max_x_ + dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3]] = this->road_value; //通路をマップチップに線画
						//通路をつなぐ
						for (::dtl::type::size j{ dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3] }; j <= dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3]; ++j)
							matrix_[dungeon_division[roomBefore][0] * max_x_ + j] = this->road_value; //通路をマップチップに線画 2から5(上から下)
						for (::dtl::type::size j{ dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3] }; j <= dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3]; ++j)
							matrix_[dungeon_division[roomBefore][0] * max_x_ + j] = this->road_value; //通路をマップチップに線画 5から2(下から上)
						break;
					case RL_COUNT_Y:
						dungeon_road[roomBefore][2] = DTL_RANDOM_ENGINE.get<::dtl::type::size>(dungeon_room[roomBefore][0] - dungeon_room[roomBefore][2] - 1); //前側の通路の位置
						dungeon_road[roomBefore][3] = DTL_RANDOM_ENGINE.get<::dtl::type::size>(dungeon_room[roomAfter][0] - dungeon_room[roomAfter][2] - 1); //後側の通路の位置
						//前の通路
						for (::dtl::type::size j{ dungeon_room[roomBefore][1] }; j < dungeon_division[roomBefore][1]; ++j)
							matrix_[(dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2]) * max_x_ + j] = this->road_value; //通路をマップチップに線画
						//後の通路
						for (::dtl::type::size j{ dungeon_division[roomAfter][3] }; j < dungeon_room[roomAfter][3]; ++j)
							matrix_[(dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2]) * max_x_ + j] = this->road_value; //通路をマップチップに線画
						//通路をつなぐ
						for (::dtl::type::size j{ dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2] }; j <= dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2]; ++j)
							matrix_[j * max_x_ + dungeon_division[roomBefore][1]] = this->road_value; //通路をマップチップに線画
						for (::dtl::type::size j{ dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2] }; j <= dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2]; ++j)
							matrix_[j * max_x_ + dungeon_division[roomBefore][1]] = this->road_value; //通路をマップチップに線画
						break;
					}
				}
			}

		public:


			///// メンバ変数の値を取得 (Get Value) /////

/*#######################################################################################
	[概要] 描画始点座標Xを取得する。
	[戻り値] 戻り値の型は std::size_t である。
	[Summary] Gets the drawing start point coordinate X.
	[Return value] The return type is std::size_t.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getPointX() const noexcept {
				return this->start_x;
			}

/*#######################################################################################
	[概要] 描画始点座標Yを取得する。
	[戻り値] 戻り値の型は std::size_t である。
	[Summary] Gets the drawing start point coordinate Y.
	[Return value] The return type is std::size_t.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getPointY() const noexcept {
				return this->start_y;
			}

/*#######################################################################################
	[概要] 描画横幅Wを取得する。
	[戻り値] 戻り値の型は std::size_t である。
	[Summary] Gets the drawing width.
	[Return value] The return type is std::size_t.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getWidth() const noexcept {
				return this->width;
			}

/*#######################################################################################
	[概要] 描画縦幅Hを取得する。
	[戻り値] 戻り値の型は std::size_t である。
	[Summary] Gets the drawing height.
	[Return value] The return type is std::size_t.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getHeight() const noexcept {
				return this->height;
			}


			///// 生成呼び出し (Drawing Function Call) /////

			//STL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_) const noexcept {
				return this->drawNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, Function_ && function_) const noexcept {
				return this->drawNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//LayerSTL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_) const noexcept {
				return this->drawLayerNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
				return this->drawLayerNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//Normal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//LayerNormal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawLayerNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawLayerNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//Array
			template<typename Matrix_>
			constexpr bool drawArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawArray(DTL_TYPE_FORWARD<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, max_x_);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperatorArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawArray(DTL_TYPE_FORWARD<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, max_x_, function_);
			}


			///// 生成呼び出しファンクタ (Drawing Functor) /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				return this->draw(DTL_TYPE_FORWARD<Matrix_>(matrix_), DTL_TYPE_FORWARD<Args_>(args_)...);
			}


			///// ダンジョン行列生成 (Create Dungeon Matrix) /////

			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& create(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->draw(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& createArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawArray(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& createOperator(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperator(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& createOperatorArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperatorArray(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}


			///// 消去 (Clear) /////

/*#######################################################################################
	[概要] 描画始点座標Xを初期値に戻す(描画始点座標Xを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing start coordinate X to the initial value (deletes the drawing start coordinate X).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleRogueLike& clearPointX() noexcept {
				this->start_x = 0;
				return *this;
			}

/*#######################################################################################
	[概要] 描画始点座標Yを初期値に戻す(描画始点座標Yを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing start coordinate Y to the initial value (deletes the drawing start coordinate Y).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleRogueLike& clearPointY() noexcept {
				this->start_y = 0;
				return *this;
			}

/*#######################################################################################
	[概要] 範囲の大きさ(X軸方向)を初期値に戻す(描画横幅Wを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the width of the range (X axis direction) to the initial value (deletes the drawing width).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleRogueLike& clearWidth() noexcept {
				this->width = 0;
				return *this;
			}

/*#######################################################################################
	[概要] 範囲の大きさ(Y軸方向)を初期値に戻す(描画縦幅Hを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the height of the range (Y axis direction) to the initial value (deletes the drawing height).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleRogueLike& clearHeight() noexcept {
				this->height = 0;
				return *this;
			}

/*#######################################################################################
	[概要] 描画始点座標(X,Y)を初期値に戻す(描画始点座標(X,Y)を消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing start coordinate (X, Y) to the initial value (deletes the drawing start coordinate (X, Y)).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleRogueLike& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}

/*#######################################################################################
	[概要] 描画範囲を初期値に戻す(描画範囲(X,Y,W,H)を消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing range to the initial value (deletes the drawing range (X, Y, W, H)).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleRogueLike& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}

/*#######################################################################################
	[概要] 全ての値を初期値に戻す。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Reset all values to their initial values.
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleRogueLike& clear() noexcept {
				this->clearRange();
				return *this;
			}


			///// 代入 /////

			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleRogueLike& setPointX(const Index_Size end_x_) noexcept {
				this->start_x = end_x_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleRogueLike& setPointY(const Index_Size end_y_) noexcept {
				this->start_y = end_y_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleRogueLike& setWidth(const Index_Size width_) noexcept {
				this->width = width_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleRogueLike& setHeight(const Index_Size height_) noexcept {
				this->height = height_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleRogueLike& setPoint(const Index_Size point_) noexcept {
				this->start_x = point_;
				this->start_y = point_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleRogueLike& setPoint(const Index_Size end_x_, const Index_Size end_y_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleRogueLike& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size length_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				this->width = length_;
				this->height = length_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleRogueLike& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				this->width = width_;
				this->height = height_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleRogueLike& setRange(const ::dtl::base::MatrixRange & matrix_range_) noexcept {
				this->start_x = matrix_range_.x;
				this->start_y = matrix_range_.y;
				this->width = matrix_range_.w;
				this->height = matrix_range_.h;
				return *this;
			}

			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleRogueLike& setRogueLike(const ::dtl::type::size division_min_, const ::dtl::type::size division_rand_max_, const ::dtl::type::size room_min_x_, const ::dtl::type::size room_rand_max_x_, const ::dtl::type::size room_min_y_, const ::dtl::type::size room_rand_max_y_) noexcept {
				division_min = division_min_;
				division_rand_max = division_rand_max_;
				room_min_x = room_min_x_;
				room_rand_max_x = room_rand_max_x_;
				room_min_y = room_min_y_;
				room_rand_max_y = room_rand_max_y_;
				return *this;
			}


			///// コンストラクタ (Constructor) /////

			SimpleRogueLike() = default;
			constexpr explicit SimpleRogueLike(const Matrix_Var_& room_value_) noexcept
				:room_value(room_value_) {}
			constexpr SimpleRogueLike(const Matrix_Var_& room_value_, const Matrix_Var_& road_value_) noexcept
				:room_value(room_value_), road_value(road_value_) {}

			constexpr SimpleRogueLike(const Matrix_Var_& room_value_, const Matrix_Var_& road_value_, const ::dtl::type::size division_min_, const ::dtl::type::size division_rand_max_, const ::dtl::type::size room_min_x_, const ::dtl::type::size room_rand_max_x_, const ::dtl::type::size room_min_y_, const ::dtl::type::size room_rand_max_y_) noexcept
				:room_value(room_value_), road_value(road_value_),
				division_min(division_min_),
				division_rand_max(division_rand_max_),
				room_min_x(room_min_x_),
				room_rand_max_x(room_rand_max_x_),
				room_min_y(room_min_y_),
				room_rand_max_y(room_rand_max_y_) {}

			constexpr explicit SimpleRogueLike(const ::dtl::base::MatrixRange & matrix_range_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}
			constexpr SimpleRogueLike(const ::dtl::base::MatrixRange& matrix_range_, const Matrix_Var_& room_value_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				room_value(room_value_) {}
			constexpr SimpleRogueLike(const ::dtl::base::MatrixRange& matrix_range_, const Matrix_Var_& room_value_, const Matrix_Var_& road_value_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				room_value(room_value_), road_value(road_value_) {}

			constexpr SimpleRogueLike(const ::dtl::base::MatrixRange& matrix_range_, const Matrix_Var_& room_value_, const Matrix_Var_& road_value_, const ::dtl::type::size division_min_, const ::dtl::type::size division_rand_max_, const ::dtl::type::size room_min_x_, const ::dtl::type::size room_rand_max_x_, const ::dtl::type::size room_min_y_, const ::dtl::type::size room_rand_max_y_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				room_value(room_value_), road_value(road_value_),
				division_min(division_min_),
				division_rand_max(division_rand_max_),
				room_min_x(room_min_x_),
				room_rand_max_x(room_rand_max_x_),
				room_min_y(room_min_y_),
				room_rand_max_y(room_rand_max_y_) {}

			constexpr SimpleRogueLike(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_) {}
		};
	}
}

#endif //Included Dungeon Template Library