/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_ENTITY_MOB_MANAGER
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_ENTITY_MOB_MANAGER

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <bitset>

namespace dtl {
	inline namespace entity {

		//プレイヤーの向き
		enum :std::uint_fast8_t {
			player_status_stay,
			player_status_1,
			player_status_2
		};

		//方向(配列型)
		enum :std::uint_fast8_t {
			direction_array_up,
			direction_array_down,
			direction_array_left,
			direction_array_right,
			direction_array_up_left,
			direction_array_up_right,
			direction_array_down_left,
			direction_array_down_right
		};

		//方向
		enum :std::uint_fast8_t {
			direction_empty,
			direction_up,
			direction_down,
			direction_left,
			direction_right,
			direction_up_left,
			direction_up_right,
			direction_down_left,
			direction_down_right
		};

		constexpr inline double getSeconds(const double m_fps_, const double fps_ = 60.0) noexcept {
			return ((fps_ == 0.0) ? 0.0 : m_fps_ / fps_);
		}
		constexpr inline double getDSeconds(const double fps_ = 60.0) noexcept {
			return ((fps_ == 0.0) ? 0.0 : 1.0 / fps_);
		}
		constexpr inline std::uint_fast64_t getMicroseconds(const double m_fps_, const double fps_ = 60.0) noexcept {
			return ((fps_ == 0.0) ? 0 : static_cast<std::uint_fast64_t>(m_fps_ / fps_ * 1'000'000.0 + 0.5));
		}

		class MobManager {
		private:

			std::int_fast32_t x{}, y{};
			double small_x{}, small_y{}, walk_speed{ 0.1 };
			std::uint_fast8_t status_x{ player_status_stay }, status_y{ player_status_stay };
			//向いている方角
			std::uint_fast8_t direction_array{ direction_array_down };
			//動くことの出来る方向
			std::bitset<8> can_walk_direction{ {} };

		public:
			constexpr explicit MobManager() noexcept :can_walk_direction(0b11111111) {}
			constexpr explicit MobManager(const std::int_fast32_t x_, const std::int_fast32_t y_) noexcept :x(x_), y(y_), can_walk_direction(0b11111111) {}
			constexpr explicit MobManager(const std::int_fast32_t x_, const std::int_fast32_t y_, const double walk_speed_) noexcept
				:x(x_), y(y_), walk_speed((walk_speed_ <= 0.0) ? 0.1 : (1.0 / static_cast<double>(static_cast<int>(1.0 / walk_speed_)))), can_walk_direction(0b11111111) {}

			constexpr void setInit(const std::int_fast32_t x_, const std::int_fast32_t y_, const double walk_speed_) noexcept {
				x = x_;
				y = y_;
				walk_speed = (walk_speed_ <= 0.0) ? 0.1 : (1.0 / static_cast<double>(static_cast<int>(1.0 / walk_speed_)));
			}

			constexpr void setWalkSpeed(const double walk_speed_) noexcept {
				walk_speed = (walk_speed_ <= 0.0) ? 0.1 : (1.0 / static_cast<double>(static_cast<int>(1.0 / walk_speed_)));
			}

			template<typename Pair_>
			constexpr void setPosition(const Pair_ & pair_) noexcept {
				x = static_cast<std::int_fast32_t>(pair_.first);
				y = static_cast<std::int_fast32_t>(pair_.second);
			}
			constexpr void setPosition(const std::int_fast32_t x_, const std::int_fast32_t y_) noexcept {
				x = x_;
				y = y_;
			}

#ifdef __cplusplus
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr bool isWalk() const noexcept {
				return (status_x != player_status_stay || status_y != player_status_stay);
			}

			constexpr void setInner(const std::int_fast32_t x_, const std::int_fast32_t y_) noexcept {
				while (x < 0) x += x_;
				while (y < 0) y += x_;
				if (x >= x_) x %= x_;
				if (y >= y_) y %= y_;
			}

			constexpr bool moveX() noexcept {
				if (status_x == player_status_stay) return false;
				small_x += walk_speed;
				if (small_x < 1.0) return false;

				if (status_x == player_status_1) --x;
				else ++x;
				small_x = 0.0;
				status_x = player_status_stay;
				return true;
			}
			constexpr bool moveY() noexcept {
				if (status_y == player_status_stay) return false;
				small_y += walk_speed;
				if (small_y < 1.0) return false;

				if (status_y == player_status_1) --y;
				else ++y;
				small_y = 0.0;
				status_y = player_status_stay;
				return true;
			}
			constexpr bool move() noexcept {
				return (moveX() | moveY());
			}

			//方向
#ifdef __cplusplus
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr std::uint_fast8_t walkDirectionY(const bool is_up_touch_, const bool is_down_touch_) const noexcept {
				return (is_up_touch_) ? ((is_down_touch_) ? direction_empty : direction_up) : ((is_down_touch_) ? direction_down : direction_empty);
			}
#ifdef __cplusplus
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr std::uint_fast8_t walkDirectionX(const bool is_left_touch_, const bool is_right_touch_) const noexcept {
				return (is_left_touch_) ? ((is_right_touch_) ? direction_empty : direction_left) : ((is_right_touch_) ? direction_right : direction_empty);
			}
#ifdef __cplusplus
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr std::uint_fast8_t walkDirection(const bool is_up_touch_, const bool is_down_touch_, const bool is_left_touch_, const bool is_right_touch_) const noexcept {
				return (walkDirectionX(is_left_touch_, is_right_touch_)) ? (walkDirectionY(is_up_touch_, is_down_touch_) * 2 + walkDirectionX(is_left_touch_, is_right_touch_)) : (walkDirectionY(is_up_touch_, is_down_touch_));
			}
#ifdef __cplusplus
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr bool isWalkDirection(const bool is_up_touch_, const bool is_down_touch_, const bool is_left_touch_, const bool is_right_touch_) const noexcept {
				return (walkDirection(is_up_touch_, is_down_touch_, is_left_touch_, is_right_touch_) == 0) ? false :
					((can_walk_direction[walkDirection(is_up_touch_, is_down_touch_, is_left_touch_, is_right_touch_) - 1] == false) ? false : true);
			}
#ifdef __cplusplus
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr bool isWalkDirection(const std::uint_fast8_t walk_direction_) const noexcept {
				return (walk_direction_ == 0) ? false : ((can_walk_direction[walk_direction_ - 1] == false) ? false : true);
			}

			//あたり判定
			template<typename Matrix_, typename Set_>
			void setCanWalkDirection(Matrix_ && matrix_, const std::int_fast32_t x_, const std::int_fast32_t y_, Set_ && set_) noexcept {
				set_(matrix_, x_, y_, can_walk_direction, x, y);
			}
			template<typename Matrix_, typename Set_>
			void setCanWalkDirection(Matrix_ && matrix_, Set_ && set_) noexcept {
				set_(matrix_, can_walk_direction, x, y);
			}
			template<typename Matrix_, typename Set_>
			void setCanWalkDirection(Set_ && set_) noexcept {
				set_(can_walk_direction, x, y);
			}

#ifdef __cplusplus
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr std::uint_fast8_t getWalkDirectionOblique(const bool is_up_touch_, const bool is_down_touch_, const bool is_left_touch_, const bool is_right_touch_) const noexcept {
				std::uint_fast8_t walk_direction{ walkDirection(is_up_touch_, is_down_touch_, is_left_touch_, is_right_touch_) };
				if (walk_direction == 0) return 0;
				if (can_walk_direction[walk_direction - 1] == false) {
					if (walk_direction <= direction_right) return 0;
					//todo
					else if (can_walk_direction[walk_direction - 1] && can_walk_direction[walk_direction - 1]) return 0;
					switch (walk_direction) {
					case direction_up_left:
						if (can_walk_direction[direction_array_up] && can_walk_direction[direction_array_left]) return 0;
						else if (!can_walk_direction[direction_array_up] && !can_walk_direction[direction_array_left]) return 0;
						else if (can_walk_direction[direction_array_up])
							walk_direction = direction_up;
						else if (can_walk_direction[direction_array_left])
							walk_direction = direction_left;
						break;
					case direction_up_right:
						if (can_walk_direction[direction_array_up] && can_walk_direction[direction_array_right]) return 0;
						else if (!can_walk_direction[direction_array_up] && !can_walk_direction[direction_array_right]) return 0;
						else if (can_walk_direction[direction_array_up])
							walk_direction = direction_up;
						else if (can_walk_direction[direction_array_right])
							walk_direction = direction_right;
						break;
					case direction_down_left:
						if (can_walk_direction[direction_array_down] && can_walk_direction[direction_array_left]) return 0;
						else if (!can_walk_direction[direction_array_down] && !can_walk_direction[direction_array_left]) return 0;
						else if (can_walk_direction[direction_array_down])
							walk_direction = direction_down;
						else if (can_walk_direction[direction_array_left])
							walk_direction = direction_left;
						break;
					case direction_down_right:
						if (can_walk_direction[direction_array_down] && can_walk_direction[direction_array_right]) return 0;
						else if (!can_walk_direction[direction_array_down] && !can_walk_direction[direction_array_right]) return 0;
						else if (can_walk_direction[direction_array_down])
							walk_direction = direction_down;
						else if (can_walk_direction[direction_array_right])
							walk_direction = direction_right;
						break;
					}
				}
				return walk_direction;
			}

			void manualWalk(const bool is_up_touch_, const bool is_down_touch_, const bool is_left_touch_, const bool is_right_touch_) noexcept {
				if (isWalk()) return;
				const std::uint_fast8_t walk_direction{ getWalkDirectionOblique(is_up_touch_, is_down_touch_, is_left_touch_, is_right_touch_) };
				if (walk_direction == 0) return;

				switch (walk_direction) {
				case direction_up:
					status_y = player_status_1;
					small_y += walk_speed;
					return;
				case direction_down:
					status_y = player_status_2;
					small_y += walk_speed;
					return;
				case direction_left:
					status_x = player_status_1;
					small_x += walk_speed;
					return;
				case direction_right:
					status_x = player_status_2;
					small_x += walk_speed;
					return;
				case direction_up_left:
					status_x = player_status_1;
					small_x += walk_speed;
					status_y = player_status_1;
					small_y += walk_speed;
					return;
				case direction_up_right:
					status_x = player_status_2;
					small_x += walk_speed;
					status_y = player_status_1;
					small_y += walk_speed;
					return;
				case direction_down_left:
					status_x = player_status_1;
					small_x += walk_speed;
					status_y = player_status_2;
					small_y += walk_speed;
					return;
				case direction_down_right:
					status_x = player_status_2;
					small_x += walk_speed;
					status_y = player_status_2;
					small_y += walk_speed;
					return;
				}
			}
#ifdef __cplusplus
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			std::int_fast32_t getX() const noexcept {
				return this->x;
			}
#ifdef __cplusplus
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			std::int_fast32_t getY() const noexcept {
				return this->y;
			}
#ifdef __cplusplus
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			double getPositionX() const noexcept {
				return this->x + 0.5 + ((this->status_x == player_status_1) ? (-small_x) : (small_x));
			}
#ifdef __cplusplus
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			double getPositionY() const noexcept {
				return this->y + 0.5 + ((this->status_y == player_status_1) ? (-small_y) : (small_y));
			}
#ifdef __cplusplus
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			std::int_fast32_t getDirection() const noexcept {
				return this->direction_array;
			}

		};

		class CollisionDetectionTrue {
		public:
			template<typename Matrix_> //maybe_unused
			void operator()(const Matrix_&, const std::int_fast32_t, const std::int_fast32_t, std::bitset<8>& dir_, const std::int_fast32_t, const std::int_fast32_t) const noexcept {
				dir_[direction_array_down] = true;
				dir_[direction_array_up] = true;
				dir_[direction_array_left] = true;
				dir_[direction_array_right] = true;
				dir_[direction_array_down_left] = true;
				dir_[direction_array_down_right] = true;
				dir_[direction_array_up_left] = true;
				dir_[direction_array_up_right] = true;
			}
		};

		class CollisionDetectionBinarization {
		public:
			template<typename Matrix_>
			void operator()(const Matrix_& matrix_, const std::int_fast32_t x_, const std::int_fast32_t y_, std::bitset<8>& dir_, const std::int_fast32_t mob_x_, const std::int_fast32_t mob_y_) const noexcept {
				if (x_ < 2 || y_ < 2) return;
				dir_[direction_array_down] = ((matrix_[(mob_y_ + 1) % y_][mob_x_]) ? true : false);
				dir_[direction_array_up] = ((matrix_[(mob_y_ - 1 + y_) % y_][mob_x_]) ? true : false);
				dir_[direction_array_left] = ((matrix_[mob_y_][(mob_x_ - 1 + x_) % x_]) ? true : false);
				dir_[direction_array_right] = ((matrix_[mob_y_][(mob_x_ + 1) % x_]) ? true : false);
				dir_[direction_array_down_left] = ((matrix_[(mob_y_ + 1) % y_][(mob_x_ - 1 + x_) % x_]) ? true : false);
				dir_[direction_array_down_right] = ((matrix_[(mob_y_ + 1) % y_][(mob_x_ + 1) % x_]) ? true : false);
				dir_[direction_array_up_left] = ((matrix_[(mob_y_ - 1 + y_) % y_][(mob_x_ - 1 + x_) % x_]) ? true : false);
				dir_[direction_array_up_right] = ((matrix_[(mob_y_ - 1 + y_) % y_][(mob_x_ + 1) % x_]) ? true : false);
			}
		};
		class CollisionDetectionBinarizationWall {
		public:
			template<typename Matrix_>
			void operator()(const Matrix_& matrix_, const std::int_fast32_t x_, const std::int_fast32_t y_, std::bitset<8>& dir_, const std::int_fast32_t mob_x_, const std::int_fast32_t mob_y_) const noexcept {
				if (x_ < 2 || y_ < 2) return;
				dir_[direction_array_down] = ((matrix_[(mob_y_ + 1) % y_][mob_x_]) ? true : false);
				dir_[direction_array_up] = ((matrix_[(mob_y_ - 1 + y_) % y_][mob_x_]) ? true : false);
				dir_[direction_array_left] = ((matrix_[mob_y_][(mob_x_ - 1 + x_) % x_]) ? true : false);
				dir_[direction_array_right] = ((matrix_[mob_y_][(mob_x_ + 1) % x_]) ? true : false);

				if (dir_[direction_array_down] && dir_[direction_array_left])
					dir_[direction_array_down_left] = ((matrix_[(mob_y_ + 1) % y_][(mob_x_ - 1 + x_) % x_]) ? true : false);
				else dir_[direction_array_down_left] = false;

				if (dir_[direction_array_down] && dir_[direction_array_right])
					dir_[direction_array_down_right] = ((matrix_[(mob_y_ + 1) % y_][(mob_x_ + 1) % x_]) ? true : false);
				else dir_[direction_array_down_right] = false;

				if (dir_[direction_array_up] && dir_[direction_array_left])
					dir_[direction_array_up_left] = ((matrix_[(mob_y_ - 1 + y_) % y_][(mob_x_ - 1 + x_) % x_]) ? true : false);
				else dir_[direction_array_up_left] = false;

				if (dir_[direction_array_up] && dir_[direction_array_right])
					dir_[direction_array_up_right] = ((matrix_[(mob_y_ - 1 + y_) % y_][(mob_x_ + 1) % x_]) ? true : false);
				else dir_[direction_array_up_right] = false;
			}
		};

	}
}

#endif //Included Dungeon Template Library