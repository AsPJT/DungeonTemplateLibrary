#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_PAINT
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_PAINT
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <memory>
#include <cstdint>
#include <cstddef>

//Dungeon Template Library Namespace
namespace dtl {

	struct BucketBuffer {
		std::int_fast32_t left_x{};
		std::int_fast32_t right_x{};
		std::int_fast32_t old_y{};
		std::int_fast32_t y{};
	};

	//塗りツール
	template<typename Int_>
	class Bucket {
	public:
		//コンストラクタ
		constexpr Bucket() noexcept = default;
		template<typename STL_>
		constexpr explicit Bucket(STL_& stl_, const std::int_fast32_t x_, const std::int_fast32_t y_, const Int_ paint_value_) noexcept {
			paint(stl_, x_, y_, paint_value_);
		}
	private:
		template<typename STL_>
		constexpr void setPoint(STL_& stl_, const std::size_t x_, const std::size_t y_, const Int_ value_) const noexcept {
			stl_[y_][x_] = value_;
		}
		template<typename STL_>
		constexpr Int_ getPoint(const STL_& stl_, const std::size_t x_, const std::size_t y_) const noexcept {
			return stl_[y_][x_];
		}

		template<typename STL_>
		constexpr void scanLine(const STL_& stl_, std::unique_ptr<BucketBuffer[]>& buffer_, std::size_t& end_n_, std::int_fast32_t left_x_, const std::int_fast32_t right_x_, const std::int_fast32_t y_, const std::int_fast32_t old_y_, const Int_ value_) const noexcept {
			while (left_x_ <= right_x_) {

				for (; left_x_ < right_x_; ++left_x_)
					if (getPoint(stl_, left_x_, y_) == value_) break;
				if (getPoint(stl_, left_x_, y_) != value_) break;

				buffer_[end_n_].left_x = left_x_;

				for (; left_x_ <= right_x_; ++left_x_)
					if (getPoint(stl_, left_x_, y_) != value_) break;

				buffer_[end_n_].right_x = left_x_ - 1;
				buffer_[end_n_].y = y_;
				buffer_[end_n_].old_y = old_y_;

				if (++end_n_ == stl_[0].size()) end_n_ = 0;
			}
		}

	public:
		template<typename STL_>
		void paint(STL_& stl_, const std::int_fast32_t x_, const std::int_fast32_t y_, const Int_ paint_value_) const noexcept {
			if (stl_.size() == 0 || stl_[0].size() == 0) return;
			std::int_fast32_t left_x{};
			std::int_fast32_t right_x{};
			std::int_fast32_t old_y{};
			std::int_fast32_t paint_y{};

			const Int_ value{ getPoint(stl_, x_, y_) };
			if (value == paint_value_) return;

			const std::int_fast32_t size_max_x{ static_cast<std::int_fast32_t>(stl_[0].size() - 1) };
			const std::int_fast32_t size_max_y{ static_cast<std::int_fast32_t>(stl_.size() - 1) };
			std::unique_ptr<BucketBuffer[]> buffer(new BucketBuffer[stl_[0].size()]);
			std::size_t start_n{};
			std::size_t end_n{ 1 };
			std::int_fast32_t left_x_sub_1{};
			std::int_fast32_t right_x_add_1{};
			buffer[start_n].left_x = buffer[start_n].right_x = x_;
			buffer[start_n].y = buffer[start_n].old_y = y_;

			do {
				left_x = buffer[start_n].left_x;
				right_x = buffer[start_n].right_x;
				paint_y = buffer[start_n].y;
				old_y = buffer[start_n].old_y;
				left_x_sub_1 = left_x - 1;
				right_x_add_1 = right_x + 1;
				if (++start_n == stl_[0].size()) start_n = 0;

				if (getPoint(stl_, left_x, paint_y) != value) continue;

				while (right_x < size_max_x) {
					if (getPoint(stl_, right_x + 1, paint_y) != value) break;
					++right_x;
				}

				while (left_x > 0) {
					if (getPoint(stl_, left_x - 1, paint_y) != value) break;
					--left_x;
				}

				for (std::int_fast32_t i{ left_x }; i <= right_x; ++i) setPoint(stl_, i, paint_y, paint_value_);

				if (paint_y - 1 >= 0) {
					if (paint_y - 1 == old_y) {
						scanLine(stl_, buffer, end_n, left_x, left_x_sub_1, paint_y - 1, paint_y, value);
						scanLine(stl_, buffer, end_n, right_x_add_1, right_x, paint_y - 1, paint_y, value);
					}
					else scanLine(stl_, buffer, end_n, left_x, right_x, paint_y - 1, paint_y, value);
				}

				if (paint_y + 1 <= size_max_y) {
					if (paint_y + 1 == old_y) {
						scanLine(stl_, buffer, end_n, left_x, left_x_sub_1, paint_y + 1, paint_y, value);
						scanLine(stl_, buffer, end_n, right_x_add_1, right_x, paint_y + 1, paint_y, value);
					}
					else scanLine(stl_, buffer, end_n, left_x, right_x, paint_y + 1, paint_y, value);
				}

			} while (start_n != end_n);

		}

	};

}

#endif //Included Dungeon Template Library