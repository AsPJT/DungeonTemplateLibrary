/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_ENTITY_MOB_MANAGER_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_ENTITY_MOB_MANAGER_HPP

#include <bitset>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/IntX.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace entity { //"dtl::entity"名前空間に属する

		//プレイヤーの向き
		enum : ::dtl::type::uint_fast8 {
			player_status_stay,
			player_status_1,
			player_status_2
		};

		//方向(配列型)
		enum : ::dtl::type::uint_fast8 {
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
		enum : ::dtl::type::uint_fast8 {
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
		constexpr inline ::dtl::type::uint_fast64 getMicroseconds(const double m_fps_, const double fps_ = 60.0) noexcept {
			return ((fps_ == 0.0) ? 0 : static_cast<::dtl::type::uint_fast64>(m_fps_ / fps_ * 1000000.0 + 0.5));
		}

		class MobManager {
		private:

			::dtl::type::int_fast32 x{}, y{};
			double small_x{}, small_y{}, walk_speed{ 0.1 };
			::dtl::type::uint_fast8 status_x{ player_status_stay }, status_y{ player_status_stay };
			//向いている方角
			::dtl::type::uint_fast8 direction_array{ direction_array_down };
			//動くことの出来る方向
			::std::bitset<8> can_walk_direction{ {} };

		public:
			constexpr explicit MobManager() noexcept :can_walk_direction(0xFF) {}
			constexpr MobManager(const ::dtl::type::int_fast32 x_, const ::dtl::type::int_fast32 y_) noexcept :x(x_), y(y_), can_walk_direction(0xFF) {}
			constexpr MobManager(const ::dtl::type::int_fast32 x_, const ::dtl::type::int_fast32 y_, const double walk_speed_) noexcept
				:x(x_), y(y_), walk_speed((walk_speed_ <= 0.0) ? 0.1 : (1.0 / static_cast<double>(static_cast<int>(1.0 / walk_speed_)))), can_walk_direction(0xFF) {}

			DTL_VERSIONING_CPP14_CONSTEXPR
				void setInit(const ::dtl::type::int_fast32 x_, const ::dtl::type::int_fast32 y_, const double walk_speed_) noexcept {
				this->x = x_;
				this->y = y_;
				this->walk_speed = (walk_speed_ <= 0.0) ? 0.1 : (1.0 / static_cast<double>(static_cast<int>(1.0 / walk_speed_)));
			}

			DTL_VERSIONING_CPP14_CONSTEXPR
				void setWalkSpeed(const double walk_speed_) noexcept {
				this->walk_speed = (walk_speed_ <= 0.0) ? 0.1 : (1.0 / static_cast<double>(static_cast<int>(1.0 / walk_speed_)));
			}

			template<typename Pair_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void setPosition(const Pair_ & pair_) noexcept {
				this->x = static_cast< ::dtl::type::int_fast32>(pair_.first);
				this->y = static_cast< ::dtl::type::int_fast32>(pair_.second);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				void setPosition(const ::dtl::type::int_fast32 x_, const ::dtl::type::int_fast32 y_) noexcept {
				this->x = x_;
				this->y = y_;
			}

			DTL_VERSIONING_CPP17_NODISCARD
			constexpr bool isWalk() const noexcept {
				return (this->status_x != player_status_stay || this->status_y != player_status_stay);
			}

			DTL_VERSIONING_CPP14_CONSTEXPR
				void setInner(const ::dtl::type::int_fast32 x_, const ::dtl::type::int_fast32 y_) noexcept {
				while (this->x < 0) this->x += x_;
				while (this->y < 0) this->y += x_;
				if (this->x >= x_) this->x %= x_;
				if (this->y >= y_) this->y %= y_;
			}

			DTL_VERSIONING_CPP14_CONSTEXPR
				bool moveX() noexcept {
				if (this->status_x == player_status_stay) return false;
				this->small_x += this->walk_speed;
				if (this->small_x < 1.0) return false;

				if (this->status_x == player_status_1) --(this->x);
				else ++(this->x);
				this->small_x = 0.0;
				this->status_x = player_status_stay;
				return true;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool moveY() noexcept {
				if (this->status_y == player_status_stay) return false;
				this->small_y += this->walk_speed;
				if (this->small_y < 1.0) return false;

				if (this->status_y == player_status_1) --(this->y);
				else ++(this->y);
				this->small_y = 0.0;
				this->status_y = player_status_stay;
				return true;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR //C++14
				bool move() noexcept {
				return (moveX() | moveY());
			}

			//方向
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr ::dtl::type::uint_fast8 walkDirectionY(const bool is_up_touch_, const bool is_down_touch_) const noexcept {
				return (is_up_touch_) ? ((is_down_touch_) ? direction_empty : direction_up) : ((is_down_touch_) ? direction_down : direction_empty);
			}
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr ::dtl::type::uint_fast8 walkDirectionX(const bool is_left_touch_, const bool is_right_touch_) const noexcept {
				return (is_left_touch_) ? ((is_right_touch_) ? direction_empty : direction_left) : ((is_right_touch_) ? direction_right : direction_empty);
			}
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr ::dtl::type::uint_fast8 walkDirection(const bool is_up_touch_, const bool is_down_touch_, const bool is_left_touch_, const bool is_right_touch_) const noexcept {
				return (walkDirectionX(is_left_touch_, is_right_touch_)) ? (walkDirectionY(is_up_touch_, is_down_touch_) * 2 + walkDirectionX(is_left_touch_, is_right_touch_)) : (walkDirectionY(is_up_touch_, is_down_touch_));
			}
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr bool isWalkDirection(const bool is_up_touch_, const bool is_down_touch_, const bool is_left_touch_, const bool is_right_touch_) const noexcept {
				return (walkDirection(is_up_touch_, is_down_touch_, is_left_touch_, is_right_touch_) == 0) ? false :
					((this->can_walk_direction[walkDirection(is_up_touch_, is_down_touch_, is_left_touch_, is_right_touch_) - 1] == false) ? false : true);
			}
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr bool isWalkDirection(const ::dtl::type::uint_fast8 walk_direction_) const noexcept {
				return (walk_direction_ == 0) ? false : ((this->can_walk_direction[walk_direction_ - 1] == false) ? false : true);
			}

			//あたり判定
			template<typename Matrix_, typename Set_>
			void setCanWalkDirection(Matrix_ && matrix_, const ::dtl::type::int_fast32 x_, const ::dtl::type::int_fast32 y_, Set_ && set_) noexcept {
				set_(matrix_, x_, y_, this->can_walk_direction, this->x, this->y);
			}
			template<typename Matrix_, typename Set_>
			void setCanWalkDirection(Matrix_ && matrix_, Set_ && set_) noexcept {
				set_(matrix_, this->can_walk_direction, this->x, this->y);
			}
			template<typename Matrix_, typename Set_>
			void setCanWalkDirection(Set_ && set_) noexcept {
				set_(this->can_walk_direction, this->x, this->y);
			}

			DTL_VERSIONING_CPP17_NODISCARD
			DTL_VERSIONING_CPP14_CONSTEXPR
				::dtl::type::uint_fast8 getWalkDirectionOblique(const bool is_up_touch_, const bool is_down_touch_, const bool is_left_touch_, const bool is_right_touch_) const noexcept {
				::dtl::type::uint_fast8 walk_direction{ walkDirection(is_up_touch_, is_down_touch_, is_left_touch_, is_right_touch_) };
				if (walk_direction == 0) return 0;
				if (this->can_walk_direction[walk_direction - 1] == false) {
					if (walk_direction <= direction_right) return 0;
					//todo (this->can_walk_direction[walk_direction - 1] && this->can_walk_direction[walk_direction - 1])
					else if (this->can_walk_direction[walk_direction - 1]) return 0;
					switch (walk_direction) {
					case direction_up_left:
						if (this->can_walk_direction[direction_array_up] && this->can_walk_direction[direction_array_left]) return 0;
						else if (!(this->can_walk_direction[direction_array_up]) && !(this->can_walk_direction[direction_array_left])) return 0;
						else if (this->can_walk_direction[direction_array_up])
							walk_direction = direction_up;
						else if (this->can_walk_direction[direction_array_left])
							walk_direction = direction_left;
						break;
					case direction_up_right:
						if (this->can_walk_direction[direction_array_up] && this->can_walk_direction[direction_array_right]) return 0;
						else if (!(this->can_walk_direction[direction_array_up]) && !(this->can_walk_direction[direction_array_right])) return 0;
						else if (this->can_walk_direction[direction_array_up])
							walk_direction = direction_up;
						else if (this->can_walk_direction[direction_array_right])
							walk_direction = direction_right;
						break;
					case direction_down_left:
						if (this->can_walk_direction[direction_array_down] && this->can_walk_direction[direction_array_left]) return 0;
						else if (!(this->can_walk_direction[direction_array_down]) && !(this->can_walk_direction[direction_array_left])) return 0;
						else if (this->can_walk_direction[direction_array_down])
							walk_direction = direction_down;
						else if (this->can_walk_direction[direction_array_left])
							walk_direction = direction_left;
						break;
					case direction_down_right:
						if (this->can_walk_direction[direction_array_down] && this->can_walk_direction[direction_array_right]) return 0;
						else if (!(this->can_walk_direction[direction_array_down]) && !(this->can_walk_direction[direction_array_right])) return 0;
						else if (this->can_walk_direction[direction_array_down])
							walk_direction = direction_down;
						else if (this->can_walk_direction[direction_array_right])
							walk_direction = direction_right;
						break;
					}
				}
				return walk_direction;
			}

			void manualWalk(const bool is_up_touch_, const bool is_down_touch_, const bool is_left_touch_, const bool is_right_touch_) noexcept {
				if (isWalk()) return;
				const ::dtl::type::uint_fast8 walk_direction{ getWalkDirectionOblique(is_up_touch_, is_down_touch_, is_left_touch_, is_right_touch_) };
				if (walk_direction == 0) return;

				switch (walk_direction) {
				case direction_up:
					this->status_y = player_status_1;
					this->small_y += this->walk_speed;
					return;
				case direction_down:
					this->status_y = player_status_2;
					this->small_y += this->walk_speed;
					return;
				case direction_left:
					this->status_x = player_status_1;
					this->small_x += this->walk_speed;
					return;
				case direction_right:
					this->status_x = player_status_2;
					this->small_x += this->walk_speed;
					return;
				case direction_up_left:
					this->status_x = player_status_1;
					this->small_x += this->walk_speed;
					this->status_y = player_status_1;
					this->small_y += this->walk_speed;
					return;
				case direction_up_right:
					this->status_x = player_status_2;
					this->small_x += this->walk_speed;
					this->status_y = player_status_1;
					this->small_y += this->walk_speed;
					return;
				case direction_down_left:
					this->status_x = player_status_1;
					this->small_x += this->walk_speed;
					this->status_y = player_status_2;
					this->small_y += this->walk_speed;
					return;
				case direction_down_right:
					this->status_x = player_status_2;
					this->small_x += this->walk_speed;
					this->status_y = player_status_2;
					this->small_y += this->walk_speed;
					return;
				}
			}
			DTL_VERSIONING_CPP17_NODISCARD
			::dtl::type::int_fast32 getX() const noexcept {
				return this->x;
			}
			DTL_VERSIONING_CPP17_NODISCARD
			::dtl::type::int_fast32 getY() const noexcept {
				return this->y;
			}
			DTL_VERSIONING_CPP17_NODISCARD
			double getPositionX() const noexcept {
				return this->x + 0.5 + ((this->status_x == player_status_1) ? (-(this->small_x)) : (this->small_x));
			}
			DTL_VERSIONING_CPP17_NODISCARD
			double getPositionY() const noexcept {
				return this->y + 0.5 + ((this->status_y == player_status_1) ? (-(this->small_y)) : (this->small_y));
			}
			DTL_VERSIONING_CPP17_NODISCARD
			::dtl::type::int_fast32 getDirection() const noexcept {
				return this->direction_array;
			}

		};

		class CollisionDetectionTrue {
		public:
			template<typename Matrix_> //maybe_unused
			void operator()(const Matrix_&, const ::dtl::type::int_fast32, const ::dtl::type::int_fast32, ::std::bitset<8>& dir_, const ::dtl::type::int_fast32, const ::dtl::type::int_fast32) const noexcept {
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
			void operator()(const Matrix_& matrix_, const ::dtl::type::int_fast32 x_, const ::dtl::type::int_fast32 y_, ::std::bitset<8>& dir_, const ::dtl::type::int_fast32 mob_x_, const ::dtl::type::int_fast32 mob_y_) const noexcept {
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
			void operator()(const Matrix_& matrix_, const ::dtl::type::int_fast32 x_, const ::dtl::type::int_fast32 y_, ::std::bitset<8>& dir_, const ::dtl::type::int_fast32 mob_x_, const ::dtl::type::int_fast32 mob_y_) const noexcept {
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