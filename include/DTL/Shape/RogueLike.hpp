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
#include <DTL/Type/IntX.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Random/RandomEngine.hpp>
#include <DTL/Range/RectBaseRogueLike.hpp>
#include <DTL/Utility/DrawJaggedRandom.hpp>

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

		/*#######################################################################################
			[概要] RogueLikeとは "Matrixの描画範囲に描画値を設置する" 機能を持つクラスである。
			[Summary] RogueLike is a class that sets drawing values in the drawing range of Matrix.
		#######################################################################################*/
		template<typename Matrix_Var_, typename Random_Engine_ = DTL_RANDOM_DEFAULT_RANDOM>
		class RogueLike : public ::dtl::range::RectBaseRogueLike<RogueLike<Matrix_Var_>, Matrix_Var_>,
			public ::dtl::utility::DrawJaggedRandom<RogueLike<Matrix_Var_>, Matrix_Var_, Random_Engine_> {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using ShapeBase_t = ::dtl::range::RectBaseRogueLike<RogueLike, Matrix_Var_>;
			using DrawBase_t = ::dtl::utility::DrawJaggedRandom<RogueLike, Matrix_Var_, Random_Engine_>;

			using Range_ = RogueLikeOutputNumber< ::dtl::type::int_fast32>;
			using VRange_ = ::std::vector<Range_>;

			using VBool_ = ::std::vector<bool>;

			friend DrawBase_t;

			//方角
			enum : ::dtl::type::size {
				direction_north,
				direction_south,
				direction_west,
				direction_east,
				direction_count,
			};

			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool createNext2(Matrix_& matrix_, Random_Engine_& random_engine_, const Index_Size size_x, const Index_Size size_y, VRange_& room_rect_, VRange_& branch_point, VBool_& is_way_, Args_&& ... args_) const noexcept {

				for (::dtl::type::size i{}, r{}; i < (::dtl::type::size)0xffff; ++i) {
					if (branch_point.empty()) break;

					//部屋か通路の乱数面を選択
					r = static_cast<::dtl::type::size>(random_engine_.get(branch_point.size()));
					const ::dtl::type::int_fast32 x{ static_cast<::dtl::type::int_fast32>(random_engine_.get(branch_point[r].x, branch_point[r].x + branch_point[r].w - 1)) };
					const ::dtl::type::int_fast32 y{ static_cast<::dtl::type::int_fast32>(random_engine_.get(branch_point[r].y, branch_point[r].y + branch_point[r].h - 1)) };

					//方角カウンタ
					for (::dtl::type::size j{}; j < direction_count; ++j) {
						if (!this->createNext(matrix_, random_engine_, size_x, size_y, room_rect_, branch_point, is_way_, is_way_[r], x, y, j, args_...)) continue;
						branch_point.erase(branch_point.begin() + r);
						is_way_.erase(is_way_.begin() + r);
						return true;
					}
				}
				return false;
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool createNext(Matrix_& matrix_, Random_Engine_& random_engine_, const Index_Size size_x, const Index_Size size_y, VRange_& room_rect_, VRange_& branch_point, VBool_& is_v_way_, const bool is_way_, const ::dtl::type::int_fast32 x, const ::dtl::type::int_fast32 y, const ::dtl::type::size dir_, Args_&& ... args_) const noexcept {

				::dtl::type::int_fast32 dx{};
				::dtl::type::int_fast32 dy{};
				switch (dir_)
				{
				case direction_north:dy = 1; break;
				case direction_south:dy = -1; break;
				case direction_west:dx = 1; break;
				case direction_east:dx = -1; break;
				}
				if (this->start_x + x + dx < 0 || this->start_x + x + dx >= this->calcEndX(matrix_.getX())) return false;
				if (this->start_y + y + dy < 0 || this->start_y + y + dy >= this->calcEndY(matrix_.getY())) return false;
				//エラー
				if (matrix_.get(this->start_x + x + dx, this->start_y + y + dy) != this->rogueLikeList.room_id && matrix_.get(this->start_x + x + dx, this->start_y + y + dy) != this->rogueLikeList.way_id) return false;

				if (!is_way_) {
					//通路を生成
					if (!makeWay(matrix_, random_engine_, size_x, size_y, branch_point, is_v_way_, x, y, dir_)) return false;
					if (matrix_.get(this->start_x + x + dx, this->start_y + y + dy) == this->rogueLikeList.room_id) matrix_.set(this->start_x + x, this->start_y + y, this->rogueLikeList.entrance_id, args_...);
					else matrix_.set(this->start_x + x, this->start_y + y, this->rogueLikeList.way_id, args_...);
					return true;
				}

				//2分の1の確率
				if (random_engine_.probability()) {
					//部屋を生成
					if (!makeRoom(matrix_, random_engine_, size_x, size_y, room_rect_, branch_point, is_v_way_, x, y, dir_)) return false;
					matrix_.set(this->start_x + x, this->start_y + y, this->rogueLikeList.entrance_id, args_...);
					return true;
				}
				//通路を生成
				if (!makeWay(matrix_, random_engine_, size_x, size_y, branch_point, is_v_way_, x, y, dir_)) return false;
				if (matrix_.get(this->start_x + x + dx, this->start_y + y + dy) == this->rogueLikeList.room_id) matrix_.set(this->start_x + x, this->start_y + y, this->rogueLikeList.entrance_id, args_...);
				else matrix_.set(this->start_x + x, this->start_y + y, this->rogueLikeList.way_id, args_...);
				return true;
			}

			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool makeRoom(Matrix_& matrix_, Random_Engine_& random_engine_, const Index_Size size_x, const Index_Size size_y, VRange_& room_rect_, VRange_& branch_point, VBool_& is_way_, const ::dtl::type::int_fast32 x_, const ::dtl::type::int_fast32 y_, const ::dtl::type::size dir_, const bool firstRoom_ = false) const noexcept {

				Range_ room;
				room.w = static_cast<::dtl::type::int_fast32>(random_engine_.get(this->roomRange.x, this->roomRange.x + this->roomRange.w - 1));
				room.h = static_cast<::dtl::type::int_fast32>(random_engine_.get(this->roomRange.y, this->roomRange.y + this->roomRange.h - 1));

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
				if (this->placeOutputNumber(matrix_, size_x, size_y, room, this->rogueLikeList.room_id)) {
					room_rect_.emplace_back(room);
					if (dir_ != direction_south || firstRoom_) { //上
						branch_point.emplace_back(Range_{ room.x, room.y - 1, room.w, 1 });
						is_way_.push_back(false);
					}
					if (dir_ != direction_north || firstRoom_) { //下
						branch_point.emplace_back(Range_{ room.x, room.y + room.h, room.w, 1 });
						is_way_.push_back(false);
					}
					if (dir_ != direction_east || firstRoom_) { //左
						branch_point.emplace_back(Range_{ room.x - 1, room.y, 1, room.h });
						is_way_.push_back(false);
					}
					if (dir_ != direction_west || firstRoom_) { //右
						branch_point.emplace_back(Range_{ room.x + room.w, room.y, 1, room.h });
						is_way_.push_back(false);
					}
					return true;
				}
				return false;
			}
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool makeWay(Matrix_& matrix_, Random_Engine_& random_engine_, const Index_Size size_x, const Index_Size size_y, VRange_& branch_point, VBool_& is_way_, const ::dtl::type::int_fast32 x_, const ::dtl::type::int_fast32 y_, const ::dtl::type::size dir_) const noexcept {

				Range_ way{};
				way.x = x_;
				way.y = y_;

				//左右
				if (random_engine_.probability()) {
					way.w = static_cast<::dtl::type::int_fast32>(random_engine_.get(this->wayRange.x, this->wayRange.x + this->wayRange.w - 1));
					way.h = 1;
					switch (dir_)
					{
					case direction_north:
						way.y = y_ - 1;
						if (random_engine_.probability()) way.x = x_ - way.w + 1;
						break;
					case direction_south:
						way.y = y_ + 1;
						if (random_engine_.probability()) way.x = x_ - way.w + 1;
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
					way.h = static_cast<::dtl::type::int_fast32>(random_engine_.get(this->wayRange.y, this->wayRange.y + this->wayRange.h - 1));
					if (dir_ == direction_north)
						way.y = y_ - way.h;
					else if (dir_ == direction_south)
						way.y = y_ + 1;
					else if (dir_ == direction_west) {
						way.x = x_ - 1;
						if (random_engine_.probability())
							way.y = y_ - way.h + 1;
					}
					else if (dir_ == direction_east) {
						way.x = x_ + 1;
						if (random_engine_.probability())
							way.y = y_ - way.h + 1;
					}
				}
				if (!this->placeOutputNumber(matrix_, size_x, size_y, way, this->rogueLikeList.way_id)) return false;
				if (dir_ != direction_south && way.w != 1) {//上
					branch_point.emplace_back(way.x, way.y - 1, way.w, 1);
					is_way_.push_back(true);
				}
				if (dir_ != direction_north && way.w != 1) {//下
					branch_point.emplace_back(way.x, way.y + way.h, way.w, 1);
					is_way_.push_back(true);
				}
				if (dir_ != direction_east && way.h != 1) {//左
					branch_point.emplace_back(way.x - 1, way.y, 1, way.h);
					is_way_.push_back(true);
				}
				if (dir_ != direction_west && way.h != 1) {//右
					branch_point.emplace_back(way.x + way.w, way.y, 1, way.h);
					is_way_.push_back(true);
				}
				return true;
			}
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool placeOutputNumber(Matrix_& matrix_, const Index_Size size_x, const Index_Size size_y, const Range_& rect, const Matrix_Var_ tile_) const noexcept {
				if (rect.x < 1 || rect.y < 1 ||
					rect.x + rect.w >(::dtl::type::int_fast32)(size_x) - 1 ||
					rect.y + rect.h >(::dtl::type::int_fast32)(size_y) - 1)
					return false;
				for (::dtl::type::int_fast32 y = rect.y; y < rect.y + rect.h; ++y)
					for (::dtl::type::int_fast32 x = rect.x; x < rect.x + rect.w; ++x)
						if (matrix_.get(this->start_x + x, this->start_y + y) != this->rogueLikeList.outside_wall_id) return false;
				for (::dtl::type::int_fast32 y = rect.y - 1; y < rect.y + rect.h + 1; ++y)
					for (::dtl::type::int_fast32 x = rect.x - 1; x < rect.x + rect.w + 1; ++x) {
						if (x == rect.x - 1 || y == rect.y - 1 || x == rect.x + rect.w || y == rect.y + rect.h)
							matrix_.set(this->start_x + x, this->start_y + y, this->rogueLikeList.inside_wall_id);
						else matrix_.set(this->start_x + x, this->start_y + y, tile_);
					}
				return true;
			}


			///// 基本処理 /////

			template<typename Matrix_, typename ...Args_>
			//DTL_VERSIONING_CPP14_CONSTEXPR
			bool drawNormal(Matrix_&& matrix_, Random_Engine_&& random_engine_, Args_&& ... args_) const noexcept {
				if (this->roomRange.w < 1 || this->roomRange.h < 1 || this->wayRange.w < 1 || this->wayRange.h < 1) return false;
				const Index_Size end_x_{ this->calcEndX(matrix_.getX()) };
				const Index_Size end_y_{ this->calcEndY(matrix_.getY()) };

				const Index_Size size_x{ end_x_ - this->start_x };
				const Index_Size size_y{ end_y_ - this->start_y };

				//部屋の位置情報
				VRange_ room_rect{};
				//部屋または通路の生成可能な面の位置情報
				VRange_ branch_point{};

				VBool_ is_way{};

				//最初の部屋を生成
				if (!this->makeRoom(matrix_, random_engine_, size_x, size_y, room_rect, branch_point, is_way, (::dtl::type::int_fast32)(size_x) / 2, (::dtl::type::int_fast32)(size_y) / 2, static_cast<::dtl::type::size>(random_engine_.getBit2()))) return false;
				//機能配置
				for (::dtl::type::size i{ 1 }; i < this->max_way; ++i)
					if (!this->createNext2(matrix_, random_engine_, size_x, size_y, room_rect, branch_point, is_way, args_...)) break;


				return true;
			}

		public:


			///// コンストラクタ (Constructor) /////

			using ShapeBase_t::ShapeBase_t;
		};
	}
}

#endif //Included Dungeon Template Library
