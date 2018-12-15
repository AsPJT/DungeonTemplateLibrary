#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_ROGUE_LIKE
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_ROGUE_LIKE
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//:::::----------::::::::::----------::::://

#include <cstddef>
#include <cstdint>
#include "DungeonRandom.hpp"

//Dungeon Template Library Namespace
namespace dtl {
	//四角形の位置と大きさ
	template<typename Int_>
	struct Rect {
		Rect() = default;
		//位置
		Int_ x{}, y{};
		//大きさ
		Int_ w{}, h{};
	};
	//タイルID
	enum TileType :std::size_t {
		outside_wall_id,
		inside_wall_id,
		room_id,
		entrance_id,
		way_id,
	};
	//方角
	enum DirectionType :std::size_t {
		direction_north,
		direction_south,
		direction_west,
		direction_east,
		direction_count,
	};
	//ローグライク生成クラス
	template<typename int_map_t>
	class RogueLike {
	public:
		//コンストラクタ
		RogueLike() = default;
		template<typename vArray>
		constexpr RogueLike(vArray& vec_, const std::size_t way_max_) {
			create(vec_, way_max_);
		}
		//マップ生成
		template<typename vArray>
		constexpr void create(vArray& vec_, const std::size_t way_max_) {
			room_rect.clear();
			branch_point.clear();
			//最初の部屋を生成
			if (!makeRoom(vec_, (std::int_fast32_t)((vec_.empty()) ? 0 : vec_.front().size()) / 2, (std::int_fast32_t)(vec_.size()) / 2, (DirectionType)rnd(4))) return;
			//機能配置
			for (std::size_t i = 1; i < way_max_; ++i)
				if (!createNext(vec_)) break;
		}

	private:
		//部屋の位置情報
		std::vector<Rect<std::int_fast32_t>> room_rect;
		//部屋または通路の生成可能な面の位置情報
		std::vector<Rect<std::int_fast32_t>> branch_point;

		//タイルを取得
		template<typename vArray>
		constexpr int_map_t getTileType(const vArray& vec_, const std::int_fast32_t x_, const std::int_fast32_t y_) const {
			if ((std::size_t)x_ >= ((vec_.empty()) ? (std::size_t)0 : vec_.front().size()) || (std::size_t)y_ >= (vec_.size())) return (int_map_t)outside_wall_id;
			return vec_[y_][x_];
		}
		//タイルを置く
		template<typename vArray>
		constexpr void setTileType(vArray& vec_, const std::size_t x_, const std::size_t y_, const int_map_t tile_) const {
			vec_[y_][x_] = tile_;
		}
		template<typename vArray>
		constexpr bool createNext(vArray& vec_) {
			for (std::size_t i{}, r{}; i < (std::size_t)0xffff; ++i) {
				if (branch_point.empty()) break;

				//部屋か通路の乱数面を選択
				r = (std::size_t)rnd((std::int_fast32_t)branch_point.size());
				const auto& x{ rnd(branch_point[r].x, branch_point[r].x + branch_point[r].w - 1) };
				const auto& y{ rnd(branch_point[r].y, branch_point[r].y + branch_point[r].h - 1) };

				//方角カウンタ
				for (std::size_t j{}; j < direction_count; ++j) {
					if (!createNext(vec_, x, y, j)) continue;
					branch_point.erase(branch_point.begin() + r);
					return true;
				}
			}
			return false;
		}
		template<typename vArray>
		constexpr bool createNext(vArray& vec_, const std::int_fast32_t x, const std::int_fast32_t y, const std::size_t dir_) {
			std::int_fast32_t dx{};
			std::int_fast32_t dy{};
			switch (dir_)
			{
			case direction_north:dy = 1; break;
			case direction_south:dy = -1; break;
			case direction_west:dx = 1; break;
			case direction_east:dx = -1; break;
			}
			//エラー
			if (getTileType(vec_, x + dx, y + dy) != room_id && getTileType(vec_, x + dx, y + dy) != way_id) return false;

			//2分の1の確率
			if (rnd.randBool()) {
				//部屋を生成
				if (!makeRoom(vec_, x, y, dir_)) return false;
				setTileType(vec_, x, y, entrance_id);
				return true;
			}
			else {
				//通路を生成
				if (!makeWay(vec_, x, y, dir_)) return false;
				if (getTileType(vec_, x + dx, y + dy) == room_id) setTileType(vec_, x, y, entrance_id);
				else setTileType(vec_, x, y, way_id);
				return true;
			}
			return false;
		}
		template<typename vArray>
		constexpr bool makeRoom(vArray& vec_, const std::int_fast32_t x_, const std::int_fast32_t y_, const std::size_t dir_, const bool firstRoom_ = false) {
			constexpr std::int_fast32_t minRoomSize{ 3 };
			constexpr std::int_fast32_t maxRoomSize{ 6 };

			Rect<std::int_fast32_t> room;
			room.w = rnd(minRoomSize, maxRoomSize);
			room.h = rnd(minRoomSize, maxRoomSize);

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
			if (placeRect(vec_, room, room_id)) {
				room_rect.emplace_back(room);
				if (dir_ != direction_south || firstRoom_) //上
					branch_point.emplace_back(Rect<std::int_fast32_t>{ room.x, room.y - 1, room.w, 1 });
				if (dir_ != direction_north || firstRoom_) //下
					branch_point.emplace_back(Rect<std::int_fast32_t>{ room.x, room.y + room.h, room.w, 1 });
				if (dir_ != direction_east || firstRoom_) //左
					branch_point.emplace_back(Rect<std::int_fast32_t>{ room.x - 1, room.y, 1, room.h });
				if (dir_ != direction_west || firstRoom_) //右
					branch_point.emplace_back(Rect<std::int_fast32_t>{ room.x + room.w, room.y, 1, room.h });
				return true;
			}
			return false;
		}
		template<typename vArray>
		constexpr bool makeWay(vArray& vec_, const std::int_fast32_t x_, const std::int_fast32_t y_, const std::size_t dir_) {
			constexpr std::int_fast32_t minWayLength{ 3 };
			constexpr std::int_fast32_t maxWayLength{ 15 };

			Rect<std::int_fast32_t> way;
			way.x = x_;
			way.y = y_;

			//左右
			if (rnd.randBool()) {
				way.w = rnd(minWayLength, maxWayLength);
				way.h = 1;
				switch (dir_)
				{
				case direction_north:
					way.y = y_ - 1;
					if (rnd.randBool()) way.x = x_ - way.w + 1;
					break;
				case direction_south:
					way.y = y_ + 1;
					if (rnd.randBool()) way.x = x_ - way.w + 1;
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
				way.h = rnd(minWayLength, maxWayLength);
				if (dir_ == direction_north)
					way.y = y_ - way.h;
				else if (dir_ == direction_south)
					way.y = y_ + 1;
				else if (dir_ == direction_west) {
					way.x = x_ - 1;
					if (rnd.randBool())
						way.y = y_ - way.h + 1;
				}
				else if (dir_ == direction_east) {
					way.x = x_ + 1;
					if (rnd.randBool())
						way.y = y_ - way.h + 1;
				}
			}
			if (!placeRect(vec_, way, way_id)) return false;
			if (dir_ != direction_south && way.w != 1)//上
				branch_point.emplace_back(Rect<std::int_fast32_t>{ way.x, way.y - 1, way.w, 1 });
			if (dir_ != direction_north && way.w != 1)//下
				branch_point.emplace_back(Rect<std::int_fast32_t>{ way.x, way.y + way.h, way.w, 1 });
			if (dir_ != direction_east && way.h != 1)//左
				branch_point.emplace_back(Rect<std::int_fast32_t>{ way.x - 1, way.y, 1, way.h });
			if (dir_ != direction_west && way.h != 1)//右
				branch_point.emplace_back(Rect<std::int_fast32_t>{ way.x + way.w, way.y, 1, way.h });
			return true;
		}
		template<typename vArray>
		constexpr bool placeRect(vArray& vec_, const Rect<std::int_fast32_t>& rect, const int_map_t tile_) {
			if (rect.x < 1 || rect.y < 1 || rect.x + rect.w >(std::int_fast32_t)((vec_.empty()) ? 0 : vec_.front().size()) - 1 || rect.y + rect.h >(std::int_fast32_t)(vec_.size()) - 1)
				return false;
			for (std::int_fast32_t y = rect.y; y < rect.y + rect.h; ++y)
				for (std::int_fast32_t x = rect.x; x < rect.x + rect.w; ++x)
					if (getTileType(vec_, x, y) != outside_wall_id) return false;
			for (std::int_fast32_t y = rect.y - 1; y < rect.y + rect.h + 1; ++y)
				for (std::int_fast32_t x = rect.x - 1; x < rect.x + rect.w + 1; ++x) {
					if (x == rect.x - 1 || y == rect.y - 1 || x == rect.x + rect.w || y == rect.y + rect.h)
						setTileType(vec_, x, y, inside_wall_id);
					else setTileType(vec_, x, y, tile_);
				}
			return true;
		}

	};
}

#endif //Included Dungeon Template Library