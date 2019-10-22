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
#include <DTL/Range/RectBaseSimpleRogueLike.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/NumericLimits.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Type/SSizeT.hpp>
#include <DTL/Type/Vector.hpp>
#include <DTL/Utility/DrawJaggedRandom.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace shape { //"dtl::shape"名前空間に属する


				//マスを指定した数値で埋める
		template<typename Matrix_Var_, typename Random_Engine_ = DTL_RANDOM_DEFAULT_RANDOM>
		class SimpleRogueLike : public ::dtl::range::RectBaseSimpleRogueLike<SimpleRogueLike<Matrix_Var_>, Matrix_Var_>,
			public ::dtl::utility::DrawJaggedRandom<SimpleRogueLike<Matrix_Var_>, Matrix_Var_, Random_Engine_> {
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
			using ShapeBase_t = ::dtl::range::RectBaseSimpleRogueLike<SimpleRogueLike, Matrix_Var_>;
			using DrawBase_t = ::dtl::utility::DrawJaggedRandom<SimpleRogueLike, Matrix_Var_, Random_Engine_>;

			friend DrawBase_t;

			///// 基本処理 /////

			void createDivision(Random_Engine_& random_engine_, StartEnd& dungeon_road, StartEnd& dungeon_division, const ::dtl::type::size mapDivCount) const noexcept {

				//マップを区分けしていく処理(区域を分割する処理)
				::dtl::type::size division_After{};
				::dtl::type::ssize count{}; //(0:X, 1:Y) X軸で分けるかY軸で分けるか決める
				for (::dtl::type::size i{ 1 }; i < mapDivCount; ++i) {

					//今まで作った区分けをランダムに指定(指定した区域をさらに区分けする)
					division_After = static_cast<::dtl::type::size>(random_engine_.get(i));

					//指定した区域のXとYの長さによって、分割する向きを決める(長いほうを分割する)
					if (dungeon_division[division_After][0] - dungeon_division[division_After][2] > dungeon_division[division_After][1] - dungeon_division[division_After][3]) count = RL_COUNT_X;
					else count = RL_COUNT_Y;

					if (dungeon_division[division_After][count] - dungeon_division[division_After][count + 2] < this->division_rand_max * 2 + 8) {
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
					dungeon_division[i][count] += static_cast<::dtl::type::size>(random_engine_.get(1, (dungeon_division[division_After][count] - dungeon_division[division_After][count + 2]) / 3));

					dungeon_division[i][count + 2] = dungeon_division[division_After][count + 2]; //0.軸の左端(iL)の座標(division_AfterL)
					dungeon_division[division_After][count + 2] = dungeon_division[i][count]; //division_After軸の左端(division_AfterL)の座標(iR)

					//countとは逆の軸の設定
					dungeon_division[i][this->absTemplate(count - 1)] = dungeon_division[division_After][this->absTemplate(count - 1)]; //軸の右端(iR)の座標(division_AfterR)
					dungeon_division[i][this->absTemplate(count - 1) + 2] = dungeon_division[division_After][this->absTemplate(count - 1) + 2]; //軸の左端(iL)の座標(division_AfterL)
				}

			}

			void createRoom(Random_Engine_& random_engine_, StartEnd& dungeon_room, const StartEnd& dungeon_division, const ::dtl::type::size mapDivCount) const noexcept {

				//部屋を生成する処理
				for (::dtl::type::size i{}; i < mapDivCount; ++i) {//区分け
					dungeon_room[i][2] = dungeon_division[i][2]; //区分けX始点をマップX始点へ代入
					dungeon_room[i][3] = dungeon_division[i][3]; //区分けY始点をマップY始点へ代入

					//X座標の部屋の長さを指定
					dungeon_room[i][0] = dungeon_division[i][2] + this->room_min_y + static_cast<::dtl::type::size>(random_engine_.get(this->room_rand_max_x));
					if (dungeon_division[i][0] - dungeon_division[i][2] < dungeon_room[i][0] - dungeon_room[i][2] + 5) {
						dungeon_room[i][0] = dungeon_division[i][0] - 4;
						if (dungeon_division[i][0] - dungeon_division[i][2] < dungeon_room[i][0] - dungeon_room[i][2] + 5) {
							dungeon_room[i][0] = dungeon_division[i][2] + 1;
						}
					}

					dungeon_room[i][1] = dungeon_division[i][3] + this->room_min_x + static_cast<::dtl::type::size>(random_engine_.get(this->room_rand_max_y));
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
					const ::dtl::type::size l{ static_cast<::dtl::type::size>(random_engine_.get(1,dungeon_division[i][0] - dungeon_room[i][0] - 5)) + 2 };
					const ::dtl::type::size n{ static_cast<::dtl::type::size>(random_engine_.get(1,dungeon_division[i][1] - dungeon_room[i][1] - 5)) + 2 };
					dungeon_room[i][0] += l;
					dungeon_room[i][2] += l;
					dungeon_room[i][1] += n;
					dungeon_room[i][3] += n;


				}

			}

			template <typename Matrix_, typename ...Args_>
			void assignRoom(const StartEnd& dungeon_room, Matrix_&& matrix_, const ::dtl::type::size mapDivCount, Args_&& ... args_) const noexcept {
				//部屋を生成する処理
				for (::dtl::type::size i{}; i < mapDivCount; ++i)
					for (::dtl::type::size j{ dungeon_room[i][2] }; j < dungeon_room[i][0]; ++j)
						for (::dtl::type::size k{ dungeon_room[i][3] }; k < dungeon_room[i][1]; ++k)
							matrix_.set(k, j, this->room_value, args_...);
			}


			//通路を生成する処理
			//通路は２部屋間の細い道のことを指す。
			//通路を作るために２部屋をそれぞれ前(Before)と後(After)で分ける。
			//for文で全ての部屋をチェックし、前後の部屋を繋ぐ通路を作る。
			//まず、前の通路を作り、次に後の通路を作る。
			//最後に前と後の通路を繋げる。

			template <typename Matrix_, typename ...Args_>
			void createRoad(Random_Engine_& random_engine_, StartEnd& dungeon_road, const StartEnd& dungeon_room, const StartEnd& dungeon_division, Matrix_&& matrix_, const ::dtl::type::size mapDivCount, Args_&& ... args_) const noexcept {
				for (::dtl::type::size roomBefore{}, roomAfter{}; roomBefore < mapDivCount; ++roomBefore) {
					roomAfter = dungeon_road[roomBefore][0];
					//X座標の通路
					switch (dungeon_road[roomBefore][1]) {
					case RL_COUNT_X:
						dungeon_road[roomBefore][2] = static_cast<::dtl::type::size>(random_engine_.get(dungeon_room[roomBefore][1] - dungeon_room[roomBefore][3] - 1)); //前側の通路の位置
						dungeon_road[roomBefore][3] = static_cast<::dtl::type::size>(random_engine_.get(dungeon_room[roomAfter][1] - dungeon_room[roomAfter][3] - 1)); //後側の通路の位置
						//前の通路
						for (::dtl::type::size j{ dungeon_room[roomBefore][0] }; j < dungeon_division[roomBefore][0]; ++j)
							matrix_.set(dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3], j, this->road_value, args_...);
						//後の通路
						for (::dtl::type::size j{ dungeon_division[roomAfter][2] }; j < dungeon_room[roomAfter][2]; ++j)
							matrix_.set(dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3], j, this->road_value, args_...);
						//通路をつなぐ
						for (::dtl::type::size j{ dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3] }; j <= dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3]; ++j)
							matrix_.set(j, dungeon_division[roomBefore][0], this->road_value, args_...);
						for (::dtl::type::size j{ dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3] }; j <= dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3]; ++j)
							matrix_.set(j, dungeon_division[roomBefore][0], this->road_value, args_...);
						break;
					case RL_COUNT_Y:
						dungeon_road[roomBefore][2] = static_cast<::dtl::type::size>(random_engine_.get(dungeon_room[roomBefore][0] - dungeon_room[roomBefore][2] - 1)); //前側の通路の位置
						dungeon_road[roomBefore][3] = static_cast<::dtl::type::size>(random_engine_.get(dungeon_room[roomAfter][0] - dungeon_room[roomAfter][2] - 1)); //後側の通路の位置
						//前の通路
						for (::dtl::type::size j{ dungeon_room[roomBefore][1] }; j < dungeon_division[roomBefore][1]; ++j)
							matrix_.set(j, dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2], this->road_value, args_...);
						//後の通路
						for (::dtl::type::size j{ dungeon_division[roomAfter][3] }; j < dungeon_room[roomAfter][3]; ++j)
							matrix_.set(j, dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2], this->road_value, args_...);
						//通路をつなぐ
						for (::dtl::type::size j{ dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2] }; j <= dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2]; ++j)
							matrix_.set(dungeon_division[roomBefore][1], j, this->road_value, args_...);
						for (::dtl::type::size j{ dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2] }; j <= dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2]; ++j)
							matrix_.set(dungeon_division[roomBefore][1], j, this->road_value, args_...);
						break;
					}
				}
			}

			template<typename Matrix_, typename ...Args_>
			bool drawNormal(Matrix_&& matrix_, Random_Engine_&& random_engine_, Args_&& ... args_) const noexcept {
				const Index_Size end_x_{ this->calcEndX(matrix_.getX()) };
				const Index_Size end_y_{ this->calcEndY(matrix_.getY()) };

				//マップの区分け数 (部屋の個数) 0~nまでの部屋ID
				const ::dtl::type::size mapDivCount{ this->division_min + static_cast<::dtl::type::size>(random_engine_.get(this->division_rand_max)) }; //マップの区分け数 (部屋の個数) 0~yまでの部屋ID

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

				this->createDivision(random_engine_, dungeon_road, dungeon_division, mapDivCount);
				this->createRoom(random_engine_, dungeon_room, dungeon_division, mapDivCount);
				this->assignRoom(dungeon_room, matrix_, mapDivCount, args_...);
				this->createRoad(random_engine_, dungeon_road, dungeon_room, dungeon_division, matrix_, mapDivCount, args_...);
				return true;
			}

			//再描画
			template<typename Matrix_, typename ...Args_>
			bool redrawNormal(const Matrix_Var_& init_value_, Matrix_&& matrix_, Random_Engine_&& random_engine_, Args_&& ... args_) const noexcept {
				const Index_Size end_x_{ this->calcEndX(matrix_.getX()) }, end_y_{ this->calcEndY(matrix_.getY()) };
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						matrix_.set(col, row, init_value_, args_...);
				return this->drawNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), DTL_TYPE_FORWARD<Random_Engine_>(random_engine_), DTL_TYPE_FORWARD<Args_>(args_)...);
			}

		public:


			///// コンストラクタ (Constructor) /////

			using ShapeBase_t::ShapeBase_t;
		};

	}
}

#endif //Included Dungeon Template Library