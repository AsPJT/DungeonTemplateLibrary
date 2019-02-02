#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SIMPLE_VORONOI_ISLAND
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SIMPLE_VORONOI_ISLAND
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>
#include <cstdint>
#include <utility>
#include <memory>
#include "DungeonRandom.hpp"
#include "DungeonMatrix.hpp"

//Dungeon Template Library Namespace
namespace dtl {

	template<typename Matrix_Int_>
	class SimpleVoronoiIsland {
	public:
		//コンストラクタ
		constexpr SimpleVoronoiIsland() noexcept = default;
		template<typename Matrix_>
		constexpr explicit SimpleVoronoiIsland(Matrix_& matrix_, const std::size_t count_ = 100, const double rbool_ = 0.4, const Matrix_Int_ land_ = 1, const Matrix_Int_ sea_ = 0) noexcept {
			create(matrix_, count_, rbool_, land_, sea_);
		}
		template<typename Matrix_>
		constexpr void operator()(Matrix_& matrix_, const std::size_t count_ = 100, const double rbool_ = 0.4, const Matrix_Int_ land_ = 1, const Matrix_Int_ sea_ = 0) const noexcept {
			create(matrix_, count_, rbool_, land_, sea_);
		}

		//ボロノイ図を作る
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t count_ = 100, const double rbool_ = 0.4, const Matrix_Int_ land_ = 1, const Matrix_Int_ sea_ = 0) const noexcept {
			//原点の座標と各面の色(もしくは地形データ)を記録する変数
			std::unique_ptr<Point_Pair_[]> point{ std::make_unique<Point_Pair_[]>(count_) };
			std::unique_ptr<Matrix_Int_[]> color{ std::make_unique<Matrix_Int_[]>(count_) };

			createPoint(point, color, count_, static_cast<std::int_fast32_t>(matrix::getSizeX(matrix_)), static_cast<std::int_fast32_t>(matrix::getSizeY(matrix_)), rbool_, land_, sea_);
			createSites(point, color, count_, matrix_, matrix::getSizeX(matrix_), matrix::getSizeY(matrix_));
		}
	private:

		using Point_Pair_ = std::pair<std::int_fast32_t, std::int_fast32_t>;

		//陸地であるか陸地でないか判別する
		constexpr bool isIsland(const std::unique_ptr<Point_Pair_[]>& point_, const std::size_t point_num_, const std::int_fast32_t w_, const std::int_fast32_t h_, const std::int_fast32_t numerator_, const std::int_fast32_t denominator_) const noexcept {
			return (point_[point_num_].first > (w_ * numerator_ / denominator_) && point_[point_num_].first < (w_ * (denominator_ - numerator_) / denominator_)) && (point_[point_num_].second > (h_ * numerator_ / denominator_) && point_[point_num_].second < (h_ * (denominator_ - numerator_) / denominator_));
		}
		//原点の場所と陸地を決定する
		constexpr void createPoint(std::unique_ptr<Point_Pair_[]>& point_, std::unique_ptr<Matrix_Int_[]>& color_, const std::size_t count_, const std::int_fast32_t w_, const std::int_fast32_t h_, const double rbool_, const Matrix_Int_ land_, const Matrix_Int_ sea_) const noexcept {
			for (std::size_t i{}, array_num{}; i < count_; ++i) {
				point_[array_num] = Point_Pair_(rnd(w_), rnd(h_));
				if (isIsland(point_, array_num, w_, h_, 2, 5) || (isIsland(point_, array_num, w_, h_, 1, 5) && rnd.randBool(rbool_)))
					color_[array_num] = land_;
				else color_[array_num] = sea_;
				++array_num;
			}
		}

		//2点間の距離を返す
		constexpr std::int_fast32_t distanceSqrd(const Point_Pair_& point_, std::int_fast32_t x_, std::int_fast32_t y_) const noexcept {
			return (x_ -= point_.first) * x_ + (y_ -= point_.second) * y_;
		}

		//図形を描画
		template<typename Matrix_>
		constexpr void createSites(const std::unique_ptr<Point_Pair_[]>& point_, const std::unique_ptr<Matrix_Int_[]>& color_, const std::size_t count_, Matrix_& matrix_, const std::size_t w_, const std::size_t h_) const noexcept {
			std::int_fast32_t ds{}, dist{};
			for (std::size_t hh{}, ind{}; hh < h_; ++hh)
				for (std::size_t ww{}; ww < w_; ++ww) {
					ind = (std::numeric_limits<std::size_t>::max)();
					dist = (std::numeric_limits<std::int_fast32_t>::max)();
					for (std::size_t it{}; it < count_; ++it) {
						if ((ds = distanceSqrd(point_[it], static_cast<std::int_fast32_t>(ww), static_cast<std::int_fast32_t>(hh))) >= dist) continue;
						dist = ds;
						ind = it;
					}
					if (ind != (std::numeric_limits<std::size_t>::max)()) matrix_[hh][ww] = color_[ind];
				}
		}
	};

}

#endif //Included Dungeon Template Library