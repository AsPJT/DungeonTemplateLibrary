/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_SIMPLE_ROGUE_LIKE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_SIMPLE_ROGUE_LIKE_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::SimpleRogueLike-(%E5%BD%A2%E7%8A%B6%E3%82%AF%E3%83%A9%E3%82%B9)/
#######################################################################################*/

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>
#include <array>
#include <limits>
#include <Random/MersenneTwister32bit.hpp>
#include <Base/Struct.hpp>
#include <Macros/nodiscard.hpp>
#include <Macros/constexpr.hpp>

namespace dtl {
	inline namespace shape {

		//マスを指定した数値で埋める
		template<typename Matrix_Int_>
		class SimpleRogueLike {
		private:

			template<typename Int_>
			constexpr Int_ absTemplate(const Int_& value_) const noexcept {
				return (value_ < 0) ? (-value_) : value_;
			}

			enum :std::int_fast32_t {
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

			using StartEndArray = std::array<std::size_t, 4>;

			///// エイリアス /////

			using Index_Size = std::size_t;
			


			///// メンバ変数 /////

			Index_Size start_x{};
			Index_Size start_y{};
			Index_Size width{};
			Index_Size height{};

			Matrix_Int_ room_value{};
			Matrix_Int_ road_value{};

			std::size_t division_min{ 3 };
			std::size_t division_rand_max{ 4 };
			std::size_t room_min_x{ 5 };
			std::size_t room_rand_max_x{ 2 };
			std::size_t room_min_y{ 5 };
			std::size_t room_rand_max_y{ 2 };


			///// 基本処理 /////

			//Normal
			template<typename Matrix_, typename ...Args_>
				bool drawNormal(Matrix_ && matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ...) const noexcept {
				//マップの区分け数 (部屋の個数) 0~nまでの部屋ID
				const std::size_t mapDivCount{ this->division_min + dtl::random::mt32bit.get<std::size_t>(this->division_rand_max) }; //マップの区分け数 (部屋の個数) 0~yまでの部屋ID

				//マップの区域 [部屋ID][X終点 , Y終点 , X始点 , Y始点]
				std::vector<StartEndArray> dungeon_division(mapDivCount, StartEndArray());
				//マップの部屋 [部屋ID][X終点 , Y終点 , X始点 , Y始点]
				std::vector<StartEndArray> dungeon_room(mapDivCount, StartEndArray());
				//マップの道 [部屋ID(前)][繋がる先の部屋ID(後) , (0.X座標 , 1.Y座標) , (前)側の通路の位置 , (後)側の通路の位置]
				std::vector<StartEndArray> dungeon_road(mapDivCount, StartEndArray());

				dungeon_division[0][0] = end_y_ - 1; //マップの区分け初期サイズX終点 (マップの大きさX軸)
				dungeon_division[0][1] = end_x_ - 1; //マップの区分け初期サイズY終点 (マップの大きさY軸)
				dungeon_division[0][2] = this->start_x + 1; //マップの区分け初期サイズX始点 (マップの大きさX軸)
				dungeon_division[0][3] = this->start_y + 1; //マップの区分け初期サイズY始点 (マップの大きさY軸)

				dungeon_road[0][0] = (std::numeric_limits<std::size_t>::max)();
				dungeon_road[0][1] = (std::numeric_limits<std::size_t>::max)();

				createDivision(dungeon_road,dungeon_division, mapDivCount);
				createRoom(dungeon_room, dungeon_division,mapDivCount);
				this->substitutionRoom(dungeon_room, matrix_, mapDivCount);
				createRoad(dungeon_road,dungeon_room, dungeon_division, matrix_, mapDivCount);
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
				bool drawLayerNormal(Matrix_ && matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ...) const noexcept {
				//マップの区分け数 (部屋の個数) 0~nまでの部屋ID
				const std::size_t mapDivCount{ this->division_min + dtl::random::mt32bit.get<std::size_t>(this->division_rand_max) }; //マップの区分け数 (部屋の個数) 0~yまでの部屋ID

				//マップの区域 [部屋ID][X終点 , Y終点 , X始点 , Y始点]
				std::vector<StartEndArray> dungeon_division(mapDivCount, StartEndArray());
				//マップの部屋 [部屋ID][X終点 , Y終点 , X始点 , Y始点]
				std::vector<StartEndArray> dungeon_room(mapDivCount, StartEndArray());
				//マップの道 [部屋ID(前)][繋がる先の部屋ID(後) , (0.X座標 , 1.Y座標) , (前)側の通路の位置 , (後)側の通路の位置]
				std::vector<StartEndArray> dungeon_road(mapDivCount, StartEndArray());

				dungeon_division[0][0] = end_y_ - 1; //マップの区分け初期サイズX終点 (マップの大きさX軸)
				dungeon_division[0][1] = end_x_ - 1; //マップの区分け初期サイズY終点 (マップの大きさY軸)
				dungeon_division[0][2] = this->start_x + 1; //マップの区分け初期サイズX始点 (マップの大きさX軸)
				dungeon_division[0][3] = this->start_y + 1; //マップの区分け初期サイズY始点 (マップの大きさY軸)

				dungeon_road[0][0] = (std::numeric_limits<std::size_t>::max)();
				dungeon_road[0][1] = (std::numeric_limits<std::size_t>::max)();

				createDivision(dungeon_road,dungeon_division, mapDivCount);
				createRoom(dungeon_room, dungeon_division,mapDivCount);
				this->substitutionRoomLayer(dungeon_room, matrix_, mapDivCount, layer_);
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
				bool drawArray(Matrix_ && matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Args_ && ...) const noexcept {
				//マップの区分け数 (部屋の個数) 0~nまでの部屋ID
				const std::size_t mapDivCount{ this->division_min + dtl::random::mt32bit.get<std::size_t>(this->division_rand_max) }; //マップの区分け数 (部屋の個数) 0~yまでの部屋ID

				//マップの区域 [部屋ID][X終点 , Y終点 , X始点 , Y始点]
				std::vector<StartEndArray> dungeon_division(mapDivCount, StartEndArray());
				//マップの部屋 [部屋ID][X終点 , Y終点 , X始点 , Y始点]
				std::vector<StartEndArray> dungeon_room(mapDivCount, StartEndArray());
				//マップの道 [部屋ID(前)][繋がる先の部屋ID(後) , (0.X座標 , 1.Y座標) , (前)側の通路の位置 , (後)側の通路の位置]
				std::vector<StartEndArray> dungeon_road(mapDivCount, StartEndArray());

				dungeon_division[0][0] = end_y_ - 1; //マップの区分け初期サイズX終点 (マップの大きさX軸)
				dungeon_division[0][1] = end_x_ - 1; //マップの区分け初期サイズY終点 (マップの大きさY軸)
				dungeon_division[0][2] = this->start_x + 1; //マップの区分け初期サイズX始点 (マップの大きさX軸)
				dungeon_division[0][3] = this->start_y + 1; //マップの区分け初期サイズY始点 (マップの大きさY軸)

				dungeon_road[0][0] = (std::numeric_limits<std::size_t>::max)();
				dungeon_road[0][1] = (std::numeric_limits<std::size_t>::max)();

				createDivision(dungeon_road,dungeon_division,mapDivCount);
				createRoom(dungeon_room, dungeon_division,mapDivCount);
				this->substitutionRoomArray(dungeon_room, matrix_, mapDivCount, max_x_);
				return true;
			}

			void createDivision(std::vector<StartEndArray>& dungeon_road,std::vector<StartEndArray>& dungeon_division, const std::size_t mapDivCount) const noexcept {

				//マップを区分けしていく処理(区域を分割する処理)
				std::size_t division_After{};
				std::int_fast32_t count{}; //(0:X, 1:Y) X軸で分けるかY軸で分けるか決める
				for (std::size_t i{ 1 }; i < mapDivCount; ++i) {

					//今まで作った区分けをランダムに指定(指定した区域をさらに区分けする)
					division_After = dtl::random::mt32bit.get<std::size_t>(i);

					//指定した区域のXとYの長さによって、分割する向きを決める(長いほうを分割する)
					if (dungeon_division[division_After][0] - dungeon_division[division_After][2] > dungeon_division[division_After][1] - dungeon_division[division_After][3]) count = RL_COUNT_X;
					else count = RL_COUNT_Y;

					if (dungeon_division[division_After][count] - dungeon_division[division_After][count + 2] < division_rand_max * 2 + 8) {
						std::size_t k{};
						for (std::size_t j{ 1 }; j < mapDivCount; ++j) {
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

					for (std::size_t j{ 1 }; j < i; ++j)
						if (dungeon_road[j][0] == division_After) dungeon_road[j][0] = i;

					//count軸の設定
					//0.軸の右端(iR)の座標(division_After*R/3~2division_After*R/3)
					dungeon_division[i][count] = dungeon_division[division_After][count + 2] + ((dungeon_division[division_After][count] - dungeon_division[division_After][count + 2]) / 3) + dtl::random::mt32bit.get<std::size_t>(1, (dungeon_division[division_After][count] - dungeon_division[division_After][count + 2]) / 3);

					dungeon_division[i][count + 2] = dungeon_division[division_After][count + 2]; //0.軸の左端(iL)の座標(division_AfterL)
					dungeon_division[division_After][count + 2] = dungeon_division[i][count]; //division_After軸の左端(division_AfterL)の座標(iR)

					//countとは逆の軸の設定
					dungeon_division[i][this->absTemplate(count - 1)] = dungeon_division[division_After][this->absTemplate(count - 1)]; //軸の右端(iR)の座標(division_AfterR)
					dungeon_division[i][this->absTemplate(count - 1) + 2] = dungeon_division[division_After][this->absTemplate(count - 1) + 2]; //軸の左端(iL)の座標(division_AfterL)
				}

			}

			void createRoom(std::vector<StartEndArray>& dungeon_room,const std::vector<StartEndArray>& dungeon_division, const std::size_t mapDivCount) const noexcept {

				//部屋を生成する処理
				for (std::size_t i{}; i < mapDivCount; ++i) {//区分け
					dungeon_room[i][2] = dungeon_division[i][2]; //区分けX始点をマップX始点へ代入
					dungeon_room[i][3] = dungeon_division[i][3]; //区分けY始点をマップY始点へ代入

					//X座標の部屋の長さを指定
					dungeon_room[i][0] = dungeon_division[i][2] + this->room_min_y + dtl::random::mt32bit.get<std::size_t>(this->room_rand_max_x);
					if (dungeon_division[i][0] - dungeon_division[i][2] < dungeon_room[i][0] - dungeon_room[i][2] + 5) {
						dungeon_room[i][0] = dungeon_division[i][0] - 4;
						if (dungeon_division[i][0] - dungeon_division[i][2] < dungeon_room[i][0] - dungeon_room[i][2] + 5) {
							dungeon_room[i][0] = dungeon_division[i][2] + 1;
						}
					}

					dungeon_room[i][1] = dungeon_division[i][3] + this->room_min_x + dtl::random::mt32bit.get<std::size_t>(this->room_rand_max_y);
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
					const std::size_t l{ dtl::random::mt32bit.get<std::size_t>(1,dungeon_division[i][0] - dungeon_room[i][0] - 5) + 2 };
					const std::size_t n{ dtl::random::mt32bit.get<std::size_t>(1,dungeon_division[i][1] - dungeon_room[i][1] - 5) + 2 };
					dungeon_room[i][0] += l;
					dungeon_room[i][2] += l;
					dungeon_room[i][1] += n;
					dungeon_room[i][3] += n;


				}

			}

			template <typename Matrix_>
			void substitutionRoom(const std::vector<StartEndArray>& dungeon_room, Matrix_&& matrix_, const std::size_t mapDivCount) const noexcept {
				//部屋を生成する処理
				for (std::size_t i{}; i < mapDivCount; ++i)
					for (std::size_t j{ dungeon_room[i][2] }; j < dungeon_room[i][0]; ++j)
						for (std::size_t k{ dungeon_room[i][3] }; k < dungeon_room[i][1]; ++k)
							matrix_[j][k] = this->room_value;
			}
			template <typename Matrix_>
			void substitutionRoomLayer(const std::vector<StartEndArray>& dungeon_room, Matrix_&& matrix_, const std::size_t mapDivCount, const Index_Size layer_) const noexcept {
				//部屋を生成する処理
				for (std::size_t i{}; i < mapDivCount; ++i)
					for (std::size_t j{ dungeon_room[i][2] }; j < dungeon_room[i][0]; ++j)
						for (std::size_t k{ dungeon_room[i][3] }; k < dungeon_room[i][1]; ++k)
							matrix_[j][k][layer_] = this->room_value;
			}
			template <typename Matrix_>
			void substitutionRoomArray(const std::vector<StartEndArray>& dungeon_room, Matrix_&& matrix_, const std::size_t mapDivCount, const Index_Size max_x_) const noexcept {
				//部屋を生成する処理
				for (std::size_t i{}; i < mapDivCount; ++i)
					for (std::size_t j{ dungeon_room[i][2] }; j < dungeon_room[i][0]; ++j)
						for (std::size_t k{ dungeon_room[i][3] }; k < dungeon_room[i][1]; ++k)
							matrix_[j * max_x_ + k] = this->room_value;
			}


			//通路を生成する処理
			//通路は２部屋間の細い道のことを指す。
			//通路を作るために２部屋をそれぞれ前(Before)と後(After)で分ける。
			//for文で全ての部屋をチェックし、前後の部屋を繋ぐ通路を作る。
			//まず、前の通路を作り、次に後の通路を作る。
			//最後に前と後の通路を繋げる。

			template <typename Matrix_>
			void createRoad(std::vector<StartEndArray>& dungeon_road, const std::vector<StartEndArray>& dungeon_room, const std::vector<StartEndArray>& dungeon_division, Matrix_&& matrix_, const std::size_t mapDivCount) const noexcept {
				for (std::size_t roomBefore{}, roomAfter{}; roomBefore < mapDivCount; ++roomBefore) {
					roomAfter = dungeon_road[roomBefore][0];
					//X座標の通路
					switch (dungeon_road[roomBefore][1]) {
					case RL_COUNT_X:
						dungeon_road[roomBefore][2] = dtl::random::mt32bit.get<std::size_t>(dungeon_room[roomBefore][1] - dungeon_room[roomBefore][3] - 1); //前側の通路の位置
						dungeon_road[roomBefore][3] = dtl::random::mt32bit.get<std::size_t>(dungeon_room[roomAfter][1] - dungeon_room[roomAfter][3] - 1); //後側の通路の位置
						//前の通路
						for (std::size_t j{ dungeon_room[roomBefore][0] }; j < dungeon_division[roomBefore][0]; ++j)
							matrix_[j][dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3]] = this->road_value; //通路をマップチップに線画
						//後の通路
						for (std::size_t j{ dungeon_division[roomAfter][2] }; j < dungeon_room[roomAfter][2]; ++j)
							matrix_[j][dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3]] = this->road_value; //通路をマップチップに線画
						//通路をつなぐ
						for (std::size_t j{ dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3] }; j <= dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3]; ++j)
							matrix_[dungeon_division[roomBefore][0]][j] = this->road_value; //通路をマップチップに線画 2から5(上から下)
						for (std::size_t j{ dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3] }; j <= dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3]; ++j)
							matrix_[dungeon_division[roomBefore][0]][j] = this->road_value; //通路をマップチップに線画 5から2(下から上)
						break;
					case RL_COUNT_Y:
						dungeon_road[roomBefore][2] = dtl::random::mt32bit.get<std::size_t>(dungeon_room[roomBefore][0] - dungeon_room[roomBefore][2] - 1); //前側の通路の位置
						dungeon_road[roomBefore][3] = dtl::random::mt32bit.get<std::size_t>(dungeon_room[roomAfter][0] - dungeon_room[roomAfter][2] - 1); //後側の通路の位置
						//前の通路
						for (std::size_t j{ dungeon_room[roomBefore][1] }; j < dungeon_division[roomBefore][1]; ++j)
							matrix_[dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2]][j] = this->road_value; //通路をマップチップに線画
						//後の通路
						for (std::size_t j{ dungeon_division[roomAfter][3] }; j < dungeon_room[roomAfter][3]; ++j)
							matrix_[dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2]][j] = this->road_value; //通路をマップチップに線画
						//通路をつなぐ
						for (std::size_t j{ dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2] }; j <= dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2]; ++j)
							matrix_[j][dungeon_division[roomBefore][1]] = this->road_value; //通路をマップチップに線画
						for (std::size_t j{ dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2] }; j <= dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2]; ++j)
							matrix_[j][dungeon_division[roomBefore][1]] = this->road_value; //通路をマップチップに線画
						break;
					}
				}
			}
			template <typename Matrix_>
			void createRoadLayer(std::vector<StartEndArray>& dungeon_road, const std::vector<StartEndArray>& dungeon_room, const std::vector<StartEndArray>& dungeon_division, Matrix_&& matrix_, const std::size_t mapDivCount, const Index_Size layer_) const noexcept {
				for (std::size_t roomBefore{}, roomAfter{}; roomBefore < mapDivCount; ++roomBefore) {
					roomAfter = dungeon_road[roomBefore][0];
					//X座標の通路
					switch (dungeon_road[roomBefore][1]) {
					case RL_COUNT_X:
						dungeon_road[roomBefore][2] = dtl::random::mt32bit.get<std::size_t>(dungeon_room[roomBefore][1] - dungeon_room[roomBefore][3] - 1); //前側の通路の位置
						dungeon_road[roomBefore][3] = dtl::random::mt32bit.get<std::size_t>(dungeon_room[roomAfter][1] - dungeon_room[roomAfter][3] - 1); //後側の通路の位置
						//前の通路
						for (std::size_t j{ dungeon_room[roomBefore][0] }; j < dungeon_division[roomBefore][0]; ++j)
							matrix_[j][dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3]][layer_] = this->road_value; //通路をマップチップに線画
						//後の通路
						for (std::size_t j{ dungeon_division[roomAfter][2] }; j < dungeon_room[roomAfter][2]; ++j)
							matrix_[j][dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3]][layer_] = this->road_value; //通路をマップチップに線画
						//通路をつなぐ
						for (std::size_t j{ dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3] }; j <= dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3]; ++j)
							matrix_[dungeon_division[roomBefore][0]][j][layer_] = this->road_value; //通路をマップチップに線画 2から5(上から下)
						for (std::size_t j{ dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3] }; j <= dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3]; ++j)
							matrix_[dungeon_division[roomBefore][0]][j][layer_] = this->road_value; //通路をマップチップに線画 5から2(下から上)
						break;
					case RL_COUNT_Y:
						dungeon_road[roomBefore][2] = dtl::random::mt32bit.get<std::size_t>(dungeon_room[roomBefore][0] - dungeon_room[roomBefore][2] - 1); //前側の通路の位置
						dungeon_road[roomBefore][3] = dtl::random::mt32bit.get<std::size_t>(dungeon_room[roomAfter][0] - dungeon_room[roomAfter][2] - 1); //後側の通路の位置
						//前の通路
						for (std::size_t j{ dungeon_room[roomBefore][1] }; j < dungeon_division[roomBefore][1]; ++j)
							matrix_[dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2]][j][layer_] = this->road_value; //通路をマップチップに線画
						//後の通路
						for (std::size_t j{ dungeon_division[roomAfter][3] }; j < dungeon_room[roomAfter][3]; ++j)
							matrix_[dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2]][j][layer_] = this->road_value; //通路をマップチップに線画
						//通路をつなぐ
						for (std::size_t j{ dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2] }; j <= dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2]; ++j)
							matrix_[j][dungeon_division[roomBefore][1]][layer_] = this->road_value; //通路をマップチップに線画
						for (std::size_t j{ dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2] }; j <= dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2]; ++j)
							matrix_[j][dungeon_division[roomBefore][1]][layer_] = this->road_value; //通路をマップチップに線画
						break;
					}
				}
			}
			template <typename Matrix_>
			void createRoadArray(std::vector<StartEndArray>& dungeon_road, const std::vector<StartEndArray>& dungeon_room, const std::vector<StartEndArray>& dungeon_division, Matrix_&& matrix_, const std::size_t mapDivCount, const Index_Size max_x_) const noexcept {
				for (std::size_t roomBefore{}, roomAfter{}; roomBefore < mapDivCount; ++roomBefore) {
					roomAfter = dungeon_road[roomBefore][0];
					//X座標の通路
					switch (dungeon_road[roomBefore][1]) {
					case RL_COUNT_X:
						dungeon_road[roomBefore][2] = dtl::random::mt32bit.get<std::size_t>(dungeon_room[roomBefore][1] - dungeon_room[roomBefore][3] - 1); //前側の通路の位置
						dungeon_road[roomBefore][3] = dtl::random::mt32bit.get<std::size_t>(dungeon_room[roomAfter][1] - dungeon_room[roomAfter][3] - 1); //後側の通路の位置
						//前の通路
						for (std::size_t j{ dungeon_room[roomBefore][0] }; j < dungeon_division[roomBefore][0]; ++j)
							matrix_[j * max_x_ + dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3]] = this->road_value; //通路をマップチップに線画
						//後の通路
						for (std::size_t j{ dungeon_division[roomAfter][2] }; j < dungeon_room[roomAfter][2]; ++j)
							matrix_[j * max_x_ + dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3]] = this->road_value; //通路をマップチップに線画
						//通路をつなぐ
						for (std::size_t j{ dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3] }; j <= dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3]; ++j)
							matrix_[dungeon_division[roomBefore][0] * max_x_ + j] = this->road_value; //通路をマップチップに線画 2から5(上から下)
						for (std::size_t j{ dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3] }; j <= dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3]; ++j)
							matrix_[dungeon_division[roomBefore][0] * max_x_ + j] = this->road_value; //通路をマップチップに線画 5から2(下から上)
						break;
					case RL_COUNT_Y:
						dungeon_road[roomBefore][2] = dtl::random::mt32bit.get<std::size_t>(dungeon_room[roomBefore][0] - dungeon_room[roomBefore][2] - 1); //前側の通路の位置
						dungeon_road[roomBefore][3] = dtl::random::mt32bit.get<std::size_t>(dungeon_room[roomAfter][0] - dungeon_room[roomAfter][2] - 1); //後側の通路の位置
						//前の通路
						for (std::size_t j{ dungeon_room[roomBefore][1] }; j < dungeon_division[roomBefore][1]; ++j)
							matrix_[(dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2]) * max_x_ + j] = this->road_value; //通路をマップチップに線画
						//後の通路
						for (std::size_t j{ dungeon_division[roomAfter][3] }; j < dungeon_room[roomAfter][3]; ++j)
							matrix_[(dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2]) * max_x_ + j] = this->road_value; //通路をマップチップに線画
						//通路をつなぐ
						for (std::size_t j{ dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2] }; j <= dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2]; ++j)
							matrix_[j * max_x_ + dungeon_division[roomBefore][1]] = this->road_value; //通路をマップチップに線画
						for (std::size_t j{ dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2] }; j <= dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2]; ++j)
							matrix_[j * max_x_ + dungeon_division[roomBefore][1]] = this->road_value; //通路をマップチップに線画
						break;
					}
				}
			}

		public:


			///// 情報取得 /////

			DTL_NODISCARD
			constexpr Index_Size getPointX() const noexcept {
				return this->start_x;
			}
			DTL_NODISCARD
			constexpr Index_Size getPointY() const noexcept {
				return this->start_y;
			}
			DTL_NODISCARD
			constexpr Index_Size getWidth() const noexcept {
				return this->width;
			}
			DTL_NODISCARD
			constexpr Index_Size getHeight() const noexcept {
				return this->height;
			}


			///// 生成呼び出し /////

			//STL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_) const noexcept {
				return this->drawNormal(std::forward<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, Function_ && function_) const noexcept {
				return this->drawNormal(std::forward<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//LayerSTL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_) const noexcept {
				return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
				return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//Normal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawNormal(std::forward<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawNormal(std::forward<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//LayerNormal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//Array
			template<typename Matrix_>
			constexpr bool drawArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawArray(std::forward<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, max_x_);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperatorArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawArray(std::forward<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, max_x_, function_);
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				return this->draw(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

			template<typename Matrix_, typename ...Args_>
			DTL_CPP14_CONSTEXPR
				Matrix_&& create(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->draw(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_CPP14_CONSTEXPR
				Matrix_&& createArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_CPP14_CONSTEXPR
				Matrix_&& createOperator(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperator(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_CPP14_CONSTEXPR
				Matrix_&& createOperatorArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}


			///// 消去 /////

			//始点座標Xを初期値に戻す
			DTL_CPP14_CONSTEXPR
				SimpleRogueLike& clearPointX() noexcept {
				this->start_x = 0;
				return *this;
			}
			//始点座標Yを初期値に戻す
			DTL_CPP14_CONSTEXPR
				SimpleRogueLike& clearPointY() noexcept {
				this->start_y = 0;
				return *this;
			}
			//範囲の大きさ(X軸方向)を初期値に戻す
			DTL_CPP14_CONSTEXPR
				SimpleRogueLike& clearWidth() noexcept {
				this->width = 0;
				return *this;
			}
			//範囲の大きさ(Y軸方向)を初期値に戻す
			DTL_CPP14_CONSTEXPR
				SimpleRogueLike& clearHeight() noexcept {
				this->height = 0;
				return *this;
			}
			//始点座標(X,Y)を初期値に戻す
			DTL_CPP14_CONSTEXPR
				SimpleRogueLike& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
			//描画範囲を初期値に戻す
			DTL_CPP14_CONSTEXPR
				SimpleRogueLike& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			//全ての値を初期値に戻す
			DTL_CPP14_CONSTEXPR
				SimpleRogueLike& clear() noexcept {
				this->clearRange();
				return *this;
			}


			///// 代入 /////

			DTL_CPP14_CONSTEXPR
				SimpleRogueLike& setPointX(const Index_Size end_x_) noexcept {
				this->start_x = end_x_;
				return *this;
			}
			DTL_CPP14_CONSTEXPR
				SimpleRogueLike& setPointY(const Index_Size end_y_) noexcept {
				this->start_y = end_y_;
				return *this;
			}
			DTL_CPP14_CONSTEXPR
				SimpleRogueLike& setWidth(const Index_Size width_) noexcept {
				this->width = width_;
				return *this;
			}
			DTL_CPP14_CONSTEXPR
				SimpleRogueLike& setHeight(const Index_Size height_) noexcept {
				this->height = height_;
				return *this;
			}
			DTL_CPP14_CONSTEXPR
				SimpleRogueLike& setPoint(const Index_Size point_) noexcept {
				this->start_x = point_;
				this->start_y = point_;
				return *this;
			}
			DTL_CPP14_CONSTEXPR
				SimpleRogueLike& setPoint(const Index_Size end_x_, const Index_Size end_y_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				return *this;
			}
			DTL_CPP14_CONSTEXPR
				SimpleRogueLike& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size length_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				this->width = length_;
				this->height = length_;
				return *this;
			}
			DTL_CPP14_CONSTEXPR
				SimpleRogueLike& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				this->width = width_;
				this->height = height_;
				return *this;
			}
			DTL_CPP14_CONSTEXPR
				SimpleRogueLike& setRange(const dtl::base::MatrixRange & matrix_range_) noexcept {
				this->start_x = matrix_range_.x;
				this->start_y = matrix_range_.y;
				this->width = matrix_range_.w;
				this->height = matrix_range_.h;
				return *this;
			}

			DTL_CPP14_CONSTEXPR
				SimpleRogueLike& setRogueLike(const std::size_t division_min_, const std::size_t division_rand_max_, const std::size_t room_min_x_, const std::size_t room_rand_max_x_, const std::size_t room_min_y_, const std::size_t room_rand_max_y_) noexcept {
				division_min = division_min_;
				division_rand_max = division_rand_max_;
				room_min_x = room_min_x_;
				room_rand_max_x = room_rand_max_x_;
				room_min_y = room_min_y_;
				room_rand_max_y = room_rand_max_y_;
				return *this;
			}


			///// コンストラクタ /////

			constexpr SimpleRogueLike() noexcept = default;
			constexpr explicit SimpleRogueLike(const Matrix_Int_& room_value_) noexcept
				:room_value(room_value_) {}
			constexpr explicit SimpleRogueLike(const Matrix_Int_& room_value_, const Matrix_Int_& road_value_) noexcept
				:room_value(room_value_), road_value(road_value_) {}

			constexpr explicit SimpleRogueLike(const Matrix_Int_& room_value_, const Matrix_Int_& road_value_, const std::size_t division_min_, const std::size_t division_rand_max_, const std::size_t room_min_x_, const std::size_t room_rand_max_x_, const std::size_t room_min_y_, const std::size_t room_rand_max_y_) noexcept
				:room_value(room_value_), road_value(road_value_),
				division_min(division_min_),
				division_rand_max(division_rand_max_),
				room_min_x(room_min_x_),
				room_rand_max_x(room_rand_max_x_),
				room_min_y(room_min_y_),
				room_rand_max_y(room_rand_max_y_) {}

			constexpr explicit SimpleRogueLike(const dtl::base::MatrixRange & matrix_range_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}
			constexpr explicit SimpleRogueLike(const dtl::base::MatrixRange& matrix_range_, const Matrix_Int_& room_value_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				room_value(room_value_) {}
			constexpr explicit SimpleRogueLike(const dtl::base::MatrixRange& matrix_range_, const Matrix_Int_& room_value_, const Matrix_Int_& road_value_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				room_value(room_value_), road_value(road_value_) {}

			constexpr explicit SimpleRogueLike(const dtl::base::MatrixRange& matrix_range_, const Matrix_Int_& room_value_, const Matrix_Int_& road_value_, const std::size_t division_min_, const std::size_t division_rand_max_, const std::size_t room_min_x_, const std::size_t room_rand_max_x_, const std::size_t room_min_y_, const std::size_t room_rand_max_y_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				room_value(room_value_), road_value(road_value_),
				division_min(division_min_),
				division_rand_max(division_rand_max_),
				room_min_x(room_min_x_),
				room_rand_max_x(room_rand_max_x_),
				room_min_y(room_min_y_),
				room_rand_max_y(room_rand_max_y_) {}

			constexpr explicit SimpleRogueLike(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_) {}
		};
	}
}

#endif //Included Dungeon Template Library