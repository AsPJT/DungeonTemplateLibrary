#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SIMPLE_VORONOI_ISLAND
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SIMPLE_VORONOI_ISLAND
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//:::::----------::::::::::----------::::://

#include <cstddef>
#include <cstdint>
#include <vector>
#include <utility>
#include "DungeonRandom.hpp"

//Dungeon Template Library Namespace
namespace dtl {

	template<typename Point_>
	constexpr std::int_fast32_t distanceSqrd(const Point_& point_, std::int_fast32_t x_, std::int_fast32_t y_) noexcept {
		x_ -= (std::int_fast32_t)point_.first;
		y_ -= (std::int_fast32_t)point_.second;
		return (x_ * x_) + (y_ * y_);
	}

	template<typename Int_>
	class SimpleVoronoiIsland {
	public:
		//コンストラクタ
		constexpr SimpleVoronoiIsland() noexcept = default;
		template<typename STL_>
		constexpr explicit SimpleVoronoiIsland(STL_& stl_, const std::size_t count_ = 100, const double rbool_ = 0.4, const Int_ land_ = 1, const Int_ sea_ = 0) noexcept {
			create(stl_, count_, rbool_, land_, sea_);
		}
		template<typename STL_>
		constexpr void operator()(STL_& stl_, const std::size_t count_ = 100, const double rbool_ = 0.4, const Int_ land_ = 1, const Int_ sea_ = 0) const noexcept {
			create(stl_, count_, rbool_, land_, sea_);
		}

		//ボロノイ図を作る
		template<typename STL_>
		constexpr void create(STL_& stl_, const std::size_t count_ = 100, const double rbool_ = 0.4, const Int_ land_ = 1, const Int_ sea_ = 0) noexcept {
			for (std::size_t i{}; i < count_; ++i) {
				createPoint((stl_.empty()) ? 0 : stl_.front().size(), stl_.size(), rbool_, land_, sea_);
			}
			createSites(stl_, (stl_.empty()) ? 0 : stl_.front().size(), stl_.size());
		}
		constexpr void init() noexcept {
			point.clear();
			color.clear();
		}
	private:
		std::vector<std::pair<std::size_t, std::size_t>> point;
		std::vector<Int_> color;

		constexpr bool isMakeIsland(const std::size_t w_, const std::size_t h_, const std::size_t numerator_, const std::size_t denominator_) const noexcept {
			return (point.back().first > (w_ * numerator_ / denominator_) && point.back().first < (w_ * (denominator_ - numerator_) / denominator_)) && (point.back().second > (h_ * numerator_ / denominator_) && point.back().second < (h_ * (denominator_ - numerator_) / denominator_));
		}
		//原点の場所と陸地を決定する
		constexpr void createPoint(const std::size_t w_, const std::size_t h_, const double rbool_, const Int_ land_, const Int_ sea_) noexcept {
			point.emplace_back((std::size_t)rnd(static_cast<std::int_fast32_t>(w_)), (std::size_t)rnd(static_cast<std::int_fast32_t>(h_)));
			if (isMakeIsland(w_, h_, 2, 5) || (rnd.randBool(rbool_) && isMakeIsland(w_, h_, 1, 5)))
				color.emplace_back(land_);
			else color.emplace_back(sea_);
		}
		//図形を線画
		template<typename STL_>
		constexpr void createSites(STL_& stl_, const std::size_t w_, const std::size_t h_) const noexcept {
			std::int_fast32_t ds{}, dist{};
			for (std::size_t hh{}, ind{}; hh < h_; ++hh)
				for (std::size_t ww{}; ww < w_; ++ww) {
					ind = std::numeric_limits<std::size_t>::max();
					dist = std::numeric_limits<std::int_fast32_t>::max();
					for (std::size_t it{}; it < point.size(); ++it) {
						const std::pair<std::size_t, std::size_t>& p{ point[it] };
						if ((ds = distanceSqrd(p, static_cast<std::int_fast32_t>(ww), static_cast<std::int_fast32_t>(hh))) >= dist) continue;
						dist = ds;
						ind = it;
					}
					if (ind != std::numeric_limits<std::size_t>::max()) stl_[hh][ww] = color[ind];
				}
		}
	};

}

#endif //Included Dungeon Template Library