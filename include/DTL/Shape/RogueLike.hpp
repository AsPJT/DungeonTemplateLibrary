/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_ROGUE_LIKE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_ROGUE_LIKE_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::RogueLike-(形状クラス)/
#######################################################################################*/

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Random/MersenneTwister32bit.hpp>
#include <DTL/Range/RectBaseRogueLike.hpp>
#include <DTL/Utility/DrawJagged.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace shape { //"dtl::shape"名前空間に属する

						//四角形の位置と大きさ
		template<typename Matrix_Var_>
		struct RogueLikeOutputNumber {
			RogueLikeOutputNumber() = default;
			//位置
			Matrix_Var_ x{}, y{};
			//大きさ
			Matrix_Var_ w{}, h{};

			constexpr RogueLikeOutputNumber(
				const Matrix_Var_ x_,
				const Matrix_Var_ y_,
				const Matrix_Var_ w_,
				const Matrix_Var_ h_) noexcept :x(x_), y(y_), w(w_), h(h_) {}
		};
		//方角
		enum : ::dtl::type::size {
			direction_north,
			direction_south,
			direction_west,
			direction_east,
			direction_count,
		};

		/*#######################################################################################
			[概要] RogueLikeとは "Matrixの描画範囲に描画値を設置する" 機能を持つクラスである。
			[Summary] RogueLike is a class that sets drawing values in the drawing range of Matrix.
		#######################################################################################*/
		template<typename Matrix_Var_>
		class RogueLike : public ::dtl::range::RectBaseRogueLike<RogueLike<Matrix_Var_>, Matrix_Var_>,
			public ::dtl::utility::DrawJagged<RogueLike<Matrix_Var_>, Matrix_Var_> {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using ShapeBase_t = ::dtl::range::RectBaseRogueLike<RogueLike, Matrix_Var_>;
			using DrawBase_t = ::dtl::utility::DrawJagged<RogueLike, Matrix_Var_>;

			friend DrawBase_t;

			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool createNext(Matrix_& matrix_, const Index_Size size_x, const Index_Size size_y, ::std::vector<RogueLikeOutputNumber< ::std::int_fast32_t>>& room_rect_, ::std::vector<RogueLikeOutputNumber< ::std::int_fast32_t>>& branch_point) const noexcept {

				for (::dtl::type::size i{}, r{}; i < (::dtl::type::size)0xffff; ++i) {
					if (branch_point.empty()) break;

					//部屋か通路の乱数面を選択
					r = DTL_RANDOM_ENGINE.get<::dtl::type::size>((::std::int_fast32_t)branch_point.size());
					const ::std::int_fast32_t x{ DTL_RANDOM_ENGINE.get<::std::int_fast32_t>(branch_point[r].x, branch_point[r].x + branch_point[r].w - 1) };
					const ::std::int_fast32_t y{ DTL_RANDOM_ENGINE.get<::std::int_fast32_t>(branch_point[r].y, branch_point[r].y + branch_point[r].h - 1) };

					//方角カウンタ
					for (::dtl::type::size j{}; j < direction_count; ++j) {
						if (!this->createNext(matrix_, size_x, size_y, room_rect_, branch_point, x, y, j)) continue;
						branch_point.erase(branch_point.begin() + r);
						return true;
					}
				}
				return false;
			}
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool createNext(Matrix_& matrix_, const Index_Size size_x, const Index_Size size_y, ::std::vector<RogueLikeOutputNumber< ::std::int_fast32_t>>& room_rect_, ::std::vector<RogueLikeOutputNumber< ::std::int_fast32_t>>& branch_point, const ::std::int_fast32_t x, const ::std::int_fast32_t y, const ::dtl::type::size dir_) const noexcept {

				::std::int_fast32_t dx{};
				::std::int_fast32_t dy{};
				switch (dir_)
				{
				case direction_north:dy = 1; break;
				case direction_south:dy = -1; break;
				case direction_west:dx = 1; break;
				case direction_east:dx = -1; break;
				}
				//エラー
				if (matrix_.get(this->start_x + x + dx, this->start_y + y + dy) != this->rogueLikeList.room_id && matrix_.get(this->start_x + x + dx, this->start_y + y + dy) != this->rogueLikeList.way_id) return false;

				//2分の1の確率
				if (DTL_RANDOM_ENGINE.probability()) {
					//部屋を生成
					if (!makeRoom(matrix_, size_x, size_y, room_rect_, branch_point, x, y, dir_)) return false;
					matrix_.set(x, y, this->rogueLikeList.entrance_id);
					return true;
				}
				else {
					//通路を生成
					if (!makeWay(matrix_, size_x, size_y, branch_point, x, y, dir_)) return false;
					if (matrix_.get(this->start_x + x + dx, this->start_y + y + dy) == this->rogueLikeList.room_id) matrix_.set(x, y, this->rogueLikeList.entrance_id);
					else matrix_.set(x, y, this->rogueLikeList.way_id);
					return true;
				}
				return false;
			}
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool makeRoom(Matrix_& matrix_, const Index_Size size_x, const Index_Size size_y, ::std::vector<RogueLikeOutputNumber< ::std::int_fast32_t>>& room_rect_, ::std::vector<RogueLikeOutputNumber< ::std::int_fast32_t>>& branch_point, const ::std::int_fast32_t x_, const ::std::int_fast32_t y_, const ::dtl::type::size dir_, const bool firstRoom_ = false) const noexcept {

				constexpr ::std::int_fast32_t minRoomSize{ 3 };
				constexpr ::std::int_fast32_t maxRoomSize{ 6 };

				RogueLikeOutputNumber< ::std::int_fast32_t> room;
				room.w = DTL_RANDOM_ENGINE.get<::std::int_fast32_t>(minRoomSize, maxRoomSize);
				room.h = DTL_RANDOM_ENGINE.get<::std::int_fast32_t>(minRoomSize, maxRoomSize);

				switch (dir_)
				{
				case direction_north:
					room.x = x_ - room.w / 2;
					room.y = y_ - room.h;
					break;
				case direction_south:
					room.x = x_ - room.w / 2;
					room.y = y_ + 1;
					break;
				case direction_west:
					room.x = x_ - room.w;
					room.y = y_ - room.h / 2;
					break;
				case direction_east:
					room.x = x_ + 1;
					room.y = y_ - room.h / 2;
					break;
				}
				if (placeOutputNumber(matrix_, size_x, size_y, room, this->rogueLikeList.room_id)) {
					room_rect_.emplace_back(room);
					if (dir_ != direction_south || firstRoom_) //上
						branch_point.emplace_back(RogueLikeOutputNumber< ::std::int_fast32_t>{ room.x, room.y - 1, room.w, 1 });
					if (dir_ != direction_north || firstRoom_) //下
						branch_point.emplace_back(RogueLikeOutputNumber< ::std::int_fast32_t>{ room.x, room.y + room.h, room.w, 1 });
					if (dir_ != direction_east || firstRoom_) //左
						branch_point.emplace_back(RogueLikeOutputNumber< ::std::int_fast32_t>{ room.x - 1, room.y, 1, room.h });
					if (dir_ != direction_west || firstRoom_) //右
						branch_point.emplace_back(RogueLikeOutputNumber< ::std::int_fast32_t>{ room.x + room.w, room.y, 1, room.h });
					return true;
				}
				return false;
			}
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool makeWay(Matrix_& matrix_, const Index_Size size_x, const Index_Size size_y, ::std::vector<RogueLikeOutputNumber< ::std::int_fast32_t>>& branch_point, const ::std::int_fast32_t x_, const ::std::int_fast32_t y_, const ::dtl::type::size dir_) const noexcept {

				constexpr ::std::int_fast32_t minWayLength{ 3 };
				constexpr ::std::int_fast32_t maxWayLength{ 15 };

				RogueLikeOutputNumber< ::std::int_fast32_t> way;
				way.x = x_;
				way.y = y_;

				//左右
				if (DTL_RANDOM_ENGINE.probability()) {
					way.w = DTL_RANDOM_ENGINE.get<::std::int_fast32_t>(minWayLength, maxWayLength);
					way.h = 1;
					switch (dir_)
					{
					case direction_north:
						way.y = y_ - 1;
						if (DTL_RANDOM_ENGINE.probability()) way.x = x_ - way.w + 1;
						break;
					case direction_south:
						way.y = y_ + 1;
						if (DTL_RANDOM_ENGINE.probability()) way.x = x_ - way.w + 1;
						break;
					case direction_west:
						way.x = x_ - way.w;
						break;
					case direction_east:
						way.x = x_ + 1;
						break;
					}
				}
				//上下
				else {
					way.w = 1;
					way.h = DTL_RANDOM_ENGINE.get<::std::int_fast32_t>(minWayLength, maxWayLength);
					if (dir_ == direction_north)
						way.y = y_ - way.h;
					else if (dir_ == direction_south)
						way.y = y_ + 1;
					else if (dir_ == direction_west) {
						way.x = x_ - 1;
						if (DTL_RANDOM_ENGINE.probability())
							way.y = y_ - way.h + 1;
					}
					else if (dir_ == direction_east) {
						way.x = x_ + 1;
						if (DTL_RANDOM_ENGINE.probability())
							way.y = y_ - way.h + 1;
					}
				}
				if (!placeOutputNumber(matrix_, size_x, size_y, way, this->rogueLikeList.way_id)) return false;
				if (dir_ != direction_south && way.w != 1)//上
					branch_point.emplace_back( way.x, way.y - 1, way.w, 1 );
				if (dir_ != direction_north && way.w != 1)//下
					branch_point.emplace_back( way.x, way.y + way.h, way.w, 1 );
				if (dir_ != direction_east && way.h != 1)//左
					branch_point.emplace_back( way.x - 1, way.y, 1, way.h );
				if (dir_ != direction_west && way.h != 1)//右
					branch_point.emplace_back( way.x + way.w, way.y, 1, way.h );
				return true;
			}
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool placeOutputNumber(Matrix_& matrix_, const Index_Size size_x, const Index_Size size_y, const RogueLikeOutputNumber< ::std::int_fast32_t>& rect, const Matrix_Var_ tile_) const noexcept {
				if (rect.x < 1 || rect.y < 1 || rect.x + rect.w >(::std::int_fast32_t)(size_x) - 1 || rect.y + rect.h >(::std::int_fast32_t)(size_y) - 1)
					return false;
				for (::std::int_fast32_t y = rect.y; y < rect.y + rect.h; ++y)
					for (::std::int_fast32_t x = rect.x; x < rect.x + rect.w; ++x)
						if (matrix_.get(this->start_x + x, this->start_y + y) != this->rogueLikeList.outside_wall_id) return false;
				for (::std::int_fast32_t y = rect.y - 1; y < rect.y + rect.h + 1; ++y)
					for (::std::int_fast32_t x = rect.x - 1; x < rect.x + rect.w + 1; ++x) {
						if (x == rect.x - 1 || y == rect.y - 1 || x == rect.x + rect.w || y == rect.y + rect.h)
							matrix_.set(x, y, this->rogueLikeList.inside_wall_id);
						else matrix_.set(x, y, tile_);
					}
				return true;
			}


			///// 基本処理 /////

			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawNormal(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				const Index_Size end_x_{ this->calcEndX(matrix_.getX()) };
				const Index_Size end_y_{ this->calcEndY(matrix_.getY()) };

				//for (Index_Size row{ this->start_y }; row < end_y_; ++row)
				//	for (Index_Size col{ this->start_x }; col < end_x_; ++col)
				//		matrix_.set(col, row, this->rogueLikeList.this->rogueLikeList.outside_wall_id, args_...);

				const Index_Size size_x{ end_x_ - this->start_x };
				const Index_Size size_y{ end_y_ - this->start_y };

				//部屋の位置情報
				::std::vector<RogueLikeOutputNumber< ::std::int_fast32_t>> room_rect;
				//部屋または通路の生成可能な面の位置情報
				::std::vector<RogueLikeOutputNumber< ::std::int_fast32_t>> branch_point;
				//最初の部屋を生成
				if (!this->makeRoom(matrix_, size_x, size_y, room_rect, branch_point, (::std::int_fast32_t)(size_x) / 2, (::std::int_fast32_t)(size_y) / 2, DTL_RANDOM_ENGINE.getBit2<::dtl::type::size>())) return false;
				//機能配置
				for (::dtl::type::size i{ 1 }; i < this->max_way; ++i)
					if (!this->createNext(matrix_, size_x, size_y, room_rect, branch_point)) break;


				return true;
			}

		public:


			///// コンストラクタ (Constructor) /////

			using ShapeBase_t::ShapeBase_t;
		};
	}
}

#endif //Included Dungeon Template Library
