/*#######################################################################################
	Made by Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_MAZE_DIG_OLD
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_MAZE_DIG_OLD

/* Character Code : UTF-8 (BOM) */
/* [2019/03/08] Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <memory>
#include <new>
#include <Random/MersenneTwister32bit.hpp>

//Dungeon Template Library Namespace
namespace dtl::generator::dungeon::stl {
	template<typename Matrix_Int_>
	class MazeDig {
	public:
		//コンストラクタ
		constexpr MazeDig() noexcept = default;
	private:

		Matrix_Int_ wall_value{};
		Matrix_Int_ empty_value{};

		//穴掘り
		template<typename Matrix_>
		constexpr void mazeDig_Dig(Matrix_&& matrix_, const std::size_t j_max, const std::size_t i_max, std::size_t x_, std::size_t y_) const noexcept {
			std::int_fast32_t dx{}, dy{};
			for (std::size_t random{ dtl::random::mt32bit.get<std::size_t>() }, counter{}; counter < 4;) {
				switch ((random + counter) & 3) {
				case 0:dx = 0; dy = -2; break;
				case 1:dx = -2; dy = 0; break;
				case 2:dx = 0; dy = 2; break;
				case 3:dx = 2; dy = 0; break;
				default:dx = 0; dy = 0; break;
				}
				if (x_ + dx <= 0 || y_ + dy <= 0 || (x_ + dx) >= i_max || (y_ + dy) >= j_max || matrix_[x_ + dx][y_ + dy] == empty_value) {
					++counter;
				}
				else if (matrix_[x_ + dx][y_ + dy] == wall_value) {
					matrix_[x_ + (dx / 2)][y_ + (dy / 2)] = empty_value;
					matrix_[x_ + dx][y_ + dy] = empty_value;
					x_ += dx;
					y_ += dy;
					counter = 0;
					random = dtl::random::mt32bit.get<std::size_t>();
				}
			}
			return;
		}
		//迷路生成
		template<typename Matrix_>
		constexpr std::size_t mazeDig_CreateLoop(const Matrix_& matrix_, const std::size_t j_max, const std::size_t i_max, std::unique_ptr<std::size_t[]>& select_x, std::unique_ptr<std::size_t[]>& select_y) const noexcept {
			std::size_t select_id{};
			for (std::size_t i{ 1 }; i < i_max; i += 2)
				for (std::size_t j{ 1 }; j < j_max; j += 2) {
					if (matrix_[i][j] != empty_value) continue;
					if ((i >= 2 && matrix_[i - 2][j] == wall_value) || (j >= 2 && matrix_[i][j - 2] == wall_value)) {
						select_x[select_id] = i;
						select_y[select_id] = j;
						++select_id;
					}
					else if ((j == j_max - 1) && (i == i_max - 1)) break;
					else if ((i + 2 < (i_max + 1) && matrix_[i + 2][j] == wall_value) || (j + 2 < (j_max + 1) && matrix_[i][j + 2] == wall_value)) {
						select_x[select_id] = i;
						select_y[select_id] = j;
						++select_id;
					}
				}
			return select_id;
		}
		//穴掘り法の迷路を生成する
		template<typename Matrix_>
		void mazeDig_Create(Matrix_&& matrix_) const noexcept {

			if (matrix_.size() <= 2 || matrix_[1].size() <= 2) return;
			const std::size_t point_y_{ matrix_.size() };
			const std::size_t point_x_{ (point_y_ == 0) ? 0 : matrix_[0].size() };

			matrix_[1][1] = empty_value;

			std::unique_ptr<std::size_t[]> select_x{ new(std::nothrow) std::size_t[point_x_ * point_y_] };
			if (!select_x) return;
			std::unique_ptr<std::size_t[]> select_y{ new(std::nothrow) std::size_t[point_x_ * point_y_] };
			if (!select_y) return;

			const std::size_t i_max{ ((point_y_ & 1) == 0) ? point_y_ - 2 : point_y_ - 1 };
			const std::size_t j_max{ ((point_x_ & 1) == 0) ? point_x_ - 2 : point_x_ - 1 };

			//座標を選ぶ
			for (std::size_t select_id{};;) {
				select_id = mazeDig_CreateLoop(matrix_, j_max, i_max, select_x, select_y);
				if (select_id == 0) break;
				select_id = dtl::random::mt32bit.get<std::size_t>(select_id);
				mazeDig_Dig(matrix_, j_max, i_max, select_x[select_id], select_y[select_id]);
			}
			return;
		}

	public:
		template<typename Matrix_>
		constexpr void create(Matrix_&& matrix_, const Matrix_Int_ v1_, const Matrix_Int_ v2_) noexcept {
			wall_value = v1_;
			empty_value = v2_;
			mazeDig_Create(matrix_);
		}

	};



} //namespace

#endif //Included Dungeon Template Library