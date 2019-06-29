/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_ROGUE_LIKE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_ROGUE_LIKE_HPP

#include <cstdint>
#include <DTL/Random/MersenneTwister32bit.hpp>
#include <DTL/Utility/Binarization.hpp>
#include <DTL/Utility/NoiseShoreBool.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Type/SizeT.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace generator {
		namespace dungeon {
			namespace stl {

				//四角形の位置と大きさ
				template<typename Matrix_Int_>
				struct RogueLikeOutputNumber {
					RogueLikeOutputNumber() = default;
					//位置
					Matrix_Int_ x{}, y{};
					//大きさ
					Matrix_Int_ w{}, h{};
				};
				//タイルID
				enum : ::dtl::type::size {
					outside_wall_id,
					inside_wall_id,
					room_id,
					entrance_id,
					way_id,
				};
				//方角
				enum : ::dtl::type::size {
					direction_north,
					direction_south,
					direction_west,
					direction_east,
					direction_count,
				};
				//ローグライク生成クラス
				template<typename Matrix_Int_>
				class RogueLike {
				public:
					//コンストラクタ
					RogueLike() = default;
					template<typename Matrix_>
					DTL_VERSIONING_CPP14_CONSTEXPR
						explicit RogueLike(Matrix_& matrix_, const ::dtl::type::size way_max_ = 20) noexcept {
						create(matrix_, way_max_);
					}
					//マップ生成
					template<typename Matrix_>
					void create(Matrix_& matrix_, const ::dtl::type::size way_max_ = 20) const noexcept {

						using ::dtl::random::mersenne_twister_32bit;

						//部屋の位置情報
						::std::vector<RogueLikeOutputNumber< ::std::int_fast32_t>> room_rect;
						//部屋または通路の生成可能な面の位置情報
						::std::vector<RogueLikeOutputNumber< ::std::int_fast32_t>> branch_point;
						//最初の部屋を生成
						if (!makeRoom(matrix_, room_rect, branch_point, ( ::std::int_fast32_t)((matrix_.size() == 0) ? 0 : matrix_[0].size()) / 2, ( ::std::int_fast32_t)(matrix_.size()) / 2, (::dtl::type::size)mersenne_twister_32bit(4))) return;
						//機能配置
						for (::dtl::type::size i{ 1 }; i < way_max_; ++i)
							if (!createNext(matrix_, room_rect, branch_point)) break;

					}

				private:
					//タイルを取得
					template<typename Matrix_>
					DTL_VERSIONING_CPP14_CONSTEXPR
						Matrix_Int_ getTileType(const Matrix_ & matrix_, const ::std::int_fast32_t x_, const ::std::int_fast32_t y_) const noexcept {
						if (static_cast<::dtl::type::size>(x_) >= ((matrix_.size() == 0) ? static_cast<::dtl::type::size>(0) : matrix_[0].size()) || static_cast<::dtl::type::size>(y_) >= (matrix_.size())) return (Matrix_Int_)outside_wall_id;
						return matrix_[y_][x_];
					}
					//タイルを置く
					template<typename Matrix_>
					DTL_VERSIONING_CPP14_CONSTEXPR
						void setTileType(Matrix_ & matrix_, const ::dtl::type::size x_, const ::dtl::type::size y_, const Matrix_Int_ tile_) const noexcept {
						matrix_[y_][x_] = tile_;
					}
					template<typename Matrix_>
					DTL_VERSIONING_CPP14_CONSTEXPR
						bool createNext(Matrix_ & matrix_, ::std::vector<RogueLikeOutputNumber< ::std::int_fast32_t>> & room_rect_, ::std::vector<RogueLikeOutputNumber< ::std::int_fast32_t>> & branch_point) const noexcept {

						using ::dtl::random::mersenne_twister_32bit;

						for (::dtl::type::size i{}, r{}; i < (::dtl::type::size)0xffff; ++i) {
							if (branch_point.empty()) break;

							//部屋か通路の乱数面を選択
							r = (::dtl::type::size)mersenne_twister_32bit(( ::std::int_fast32_t)branch_point.size());
							const auto& x{ mersenne_twister_32bit(branch_point[r].x, branch_point[r].x + branch_point[r].w - 1) };
							const auto& y{ mersenne_twister_32bit(branch_point[r].y, branch_point[r].y + branch_point[r].h - 1) };

							//方角カウンタ
							for (::dtl::type::size j{}; j < direction_count; ++j) {
								if (!createNext(matrix_, room_rect_, branch_point, x, y, j)) continue;
								branch_point.erase(branch_point.begin() + r);
								return true;
							}
						}
						return false;
					}
					template<typename Matrix_>
					DTL_VERSIONING_CPP14_CONSTEXPR
						bool createNext(Matrix_ & matrix_, ::std::vector<RogueLikeOutputNumber< ::std::int_fast32_t>> & room_rect_, ::std::vector<RogueLikeOutputNumber< ::std::int_fast32_t>> & branch_point, const ::std::int_fast32_t x, const ::std::int_fast32_t y, const ::dtl::type::size dir_) const noexcept {

						using ::dtl::random::mersenne_twister_32bit;

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
						if (getTileType(matrix_, x + dx, y + dy) != room_id && getTileType(matrix_, x + dx, y + dy) != way_id) return false;

						//2分の1の確率
						if (mersenne_twister_32bit.probability()) {
							//部屋を生成
							if (!makeRoom(matrix_, room_rect_, branch_point, x, y, dir_)) return false;
							setTileType(matrix_, x, y, entrance_id);
							return true;
						}
						else {
							//通路を生成
							if (!makeWay(matrix_, branch_point, x, y, dir_)) return false;
							if (getTileType(matrix_, x + dx, y + dy) == room_id) setTileType(matrix_, x, y, entrance_id);
							else setTileType(matrix_, x, y, way_id);
							return true;
						}
						return false;
					}
					template<typename Matrix_>
					DTL_VERSIONING_CPP14_CONSTEXPR
						bool makeRoom(Matrix_ & matrix_, ::std::vector<RogueLikeOutputNumber< ::std::int_fast32_t>> & room_rect_, ::std::vector<RogueLikeOutputNumber< ::std::int_fast32_t>> & branch_point, const ::std::int_fast32_t x_, const ::std::int_fast32_t y_, const ::dtl::type::size dir_, const bool firstRoom_ = false) const noexcept {

						using ::dtl::random::mersenne_twister_32bit;

						constexpr ::std::int_fast32_t minRoomSize{ 3 };
						constexpr ::std::int_fast32_t maxRoomSize{ 6 };

						RogueLikeOutputNumber< ::std::int_fast32_t> room;
						room.w = mersenne_twister_32bit(minRoomSize, maxRoomSize);
						room.h = mersenne_twister_32bit(minRoomSize, maxRoomSize);

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
						if (placeOutputNumber(matrix_, room, room_id)) {
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
						bool makeWay(Matrix_ & matrix_, ::std::vector<RogueLikeOutputNumber< ::std::int_fast32_t>> & branch_point, const ::std::int_fast32_t x_, const ::std::int_fast32_t y_, const ::dtl::type::size dir_) const noexcept {

						using ::dtl::random::mersenne_twister_32bit;

						constexpr ::std::int_fast32_t minWayLength{ 3 };
						constexpr ::std::int_fast32_t maxWayLength{ 15 };

						RogueLikeOutputNumber< ::std::int_fast32_t> way;
						way.x = x_;
						way.y = y_;

						//左右
						if (mersenne_twister_32bit.probability()) {
							way.w = mersenne_twister_32bit(minWayLength, maxWayLength);
							way.h = 1;
							switch (dir_)
							{
							case direction_north:
								way.y = y_ - 1;
								if (mersenne_twister_32bit.probability()) way.x = x_ - way.w + 1;
								break;
							case direction_south:
								way.y = y_ + 1;
								if (mersenne_twister_32bit.probability()) way.x = x_ - way.w + 1;
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
							way.h = mersenne_twister_32bit(minWayLength, maxWayLength);
							if (dir_ == direction_north)
								way.y = y_ - way.h;
							else if (dir_ == direction_south)
								way.y = y_ + 1;
							else if (dir_ == direction_west) {
								way.x = x_ - 1;
								if (mersenne_twister_32bit.probability())
									way.y = y_ - way.h + 1;
							}
							else if (dir_ == direction_east) {
								way.x = x_ + 1;
								if (mersenne_twister_32bit.probability())
									way.y = y_ - way.h + 1;
							}
						}
						if (!placeOutputNumber(matrix_, way, way_id)) return false;
						if (dir_ != direction_south && way.w != 1)//上
							branch_point.emplace_back(RogueLikeOutputNumber< ::std::int_fast32_t>{ way.x, way.y - 1, way.w, 1 });
						if (dir_ != direction_north && way.w != 1)//下
							branch_point.emplace_back(RogueLikeOutputNumber< ::std::int_fast32_t>{ way.x, way.y + way.h, way.w, 1 });
						if (dir_ != direction_east && way.h != 1)//左
							branch_point.emplace_back(RogueLikeOutputNumber< ::std::int_fast32_t>{ way.x - 1, way.y, 1, way.h });
						if (dir_ != direction_west && way.h != 1)//右
							branch_point.emplace_back(RogueLikeOutputNumber< ::std::int_fast32_t>{ way.x + way.w, way.y, 1, way.h });
						return true;
					}
					template<typename Matrix_>
					DTL_VERSIONING_CPP14_CONSTEXPR
						bool placeOutputNumber(Matrix_& matrix_, const RogueLikeOutputNumber< ::std::int_fast32_t>& rect, const Matrix_Int_ tile_) const noexcept {
						if (rect.x < 1 || rect.y < 1 || rect.x + rect.w >( ::std::int_fast32_t)((matrix_.size() == 0) ? 0 : matrix_[0].size()) - 1 || rect.y + rect.h >( ::std::int_fast32_t)(matrix_.size()) - 1)
							return false;
						for ( ::std::int_fast32_t y = rect.y; y < rect.y + rect.h; ++y)
							for ( ::std::int_fast32_t x = rect.x; x < rect.x + rect.w; ++x)
								if (getTileType(matrix_, x, y) != outside_wall_id) return false;
						for ( ::std::int_fast32_t y = rect.y - 1; y < rect.y + rect.h + 1; ++y)
							for ( ::std::int_fast32_t x = rect.x - 1; x < rect.x + rect.w + 1; ++x) {
								if (x == rect.x - 1 || y == rect.y - 1 || x == rect.x + rect.w || y == rect.y + rect.h)
									setTileType(matrix_, x, y, inside_wall_id);
								else setTileType(matrix_, x, y, tile_);
							}
						return true;
					}

				};

				//ローグライク洞窟
				template<typename Matrix_Int_>
				class RogueLikeCave {
				public:
					//コンストラクタ
					RogueLikeCave() = default;
					template<typename Matrix_>
					DTL_VERSIONING_CPP14_CONSTEXPR
						explicit RogueLikeCave(Matrix_& matrix_, const ::dtl::type::size way_max_ = 20) noexcept {
						create(matrix_, way_max_);
					}
					//ワールドマップ生成
					template<typename Matrix_>
					DTL_VERSIONING_CPP14_CONSTEXPR
						void create(Matrix_& matrix_, const ::dtl::type::size way_max_ = 20) const noexcept {
						::dtl::generator::dungeon::stl::RogueLike<Matrix_Int_> fractal_island_stl2(matrix_, way_max_);
						//::dtl::utility::stl::binarizationOver(matrix_, 1);

						::dtl::utility::Binarization<Matrix_Int_>(1, 0).drawOperator(matrix_, [](const Matrix_Int_ & value_) {return value_ >= 1; });

						::dtl::utility::stl::noiseShoreBothBool(matrix_, 0.1);
					}
				};

			} //namespace
		}
	}
}

#endif //Included Dungeon Template Library