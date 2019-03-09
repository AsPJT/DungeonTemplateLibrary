#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_GENERATOR_TERRAIN_SIMPLE_BIOME_ISLAND
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_GENERATOR_TERRAIN_SIMPLE_BIOME_ISLAND
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

/* Bug Check : not checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstdint>
#include "Utility_CellularAutomaton.hpp"
#include "Utility_RandomInnerRandomValue.hpp"

namespace dtl::generator::terrain::stl {

	//セルオートマトン法
	template<typename Matrix_Int_>
	class SimpleBiomeIsland {
	public:
		//コンストラクタ
		constexpr SimpleBiomeIsland() noexcept = default;
		template<typename Matrix_>
		constexpr explicit SimpleBiomeIsland(Matrix_& matrix_, const std::size_t max_value_ = 2, const std::int_fast32_t type_ = 4) noexcept {
			create(matrix_, max_value_, type_);
		}
		//ワールドマップ生成
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t max_value_ = 2, const std::int_fast32_t type_ = 4) const noexcept {
			dtl::utility::stl::randomInnerRandomValue(matrix_, 0, type_ - 1);
			for (std::size_t i{}; i < max_value_; ++i)
				dtl::utility::stl::cellularAutomation(matrix_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t max_value_, const std::int_fast32_t type_min_, const std::int_fast32_t type_max_) const noexcept {
			dtl::utility::stl::randomInnerRandomValue(matrix_, type_min_, type_max_);
			for (std::size_t i{}; i < max_value_; ++i)
				dtl::utility::stl::cellularAutomation(matrix_);
		}
	};

} //namespace

namespace dtl::generator::terrain::normal {

	//セルオートマトン法
	template<typename Matrix_Int_>
	class SimpleBiomeIsland {
	public:
		//コンストラクタ
		constexpr SimpleBiomeIsland() noexcept = default;
		template<typename Matrix_>
		constexpr explicit SimpleBiomeIsland(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t max_value_ = 2, const std::int_fast32_t type_ = 4) noexcept {
			create(matrix_, x_, y_, max_value_, type_);
		}
		//ワールドマップ生成
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t max_value_ = 2, const std::int_fast32_t type_ = 4) const noexcept {
			dtl::utility::normal::randomInnerRandomValue(matrix_, x_, y_, 0, type_ - 1);
			for (std::size_t i{}; i < max_value_; ++i)
				dtl::utility::normal::cellularAutomation(matrix_, x_, y_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t max_value_, const std::int_fast32_t type_min_, const std::int_fast32_t type_max_) const noexcept {
			dtl::utility::normal::randomInnerRandomValue(matrix_, x_, y_, type_min_, type_max_);
			for (std::size_t i{}; i < max_value_; ++i)
				dtl::utility::normal::cellularAutomation(matrix_, x_, y_);
		}
	};

} //namespace

namespace dtl::generator::terrain::array {

	//セルオートマトン法
	template<typename Matrix_Int_>
	class SimpleBiomeIsland {
	public:
		//コンストラクタ
		constexpr SimpleBiomeIsland() noexcept = default;
		template<typename Matrix_>
		constexpr explicit SimpleBiomeIsland(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t max_value_ = 2, const std::int_fast32_t type_ = 4) noexcept {
			create(matrix_, x_, y_, max_value_, type_);
		}
		//ワールドマップ生成
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t max_value_ = 2, const std::int_fast32_t type_ = 4) const noexcept {
			dtl::utility::array::randomInnerRandomValue(matrix_, x_, y_, 0, type_ - 1);
			for (std::size_t i{}; i < max_value_; ++i)
				dtl::utility::array::cellularAutomation(matrix_, x_, y_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t max_value_, const std::int_fast32_t type_min_, const std::int_fast32_t type_max_) const noexcept {
			dtl::utility::array::randomInnerRandomValue(matrix_, x_, y_, type_min_, type_max_);
			for (std::size_t i{}; i < max_value_; ++i)
				dtl::utility::array::cellularAutomation(matrix_, x_, y_);
		}
	};

} //namespace

namespace dtl::generator::terrain::layer::stl {

	//セルオートマトン法
	template<typename Matrix_Int_>
	class SimpleBiomeIsland {
	public:
		//コンストラクタ
		constexpr SimpleBiomeIsland() noexcept = default;
		template<typename Matrix_>
		constexpr explicit SimpleBiomeIsland(Matrix_& matrix_, const std::size_t layer_, const std::size_t max_value_ = 2, const std::int_fast32_t type_ = 4) noexcept {
			create(matrix_, layer_, max_value_, type_);
		}
		//ワールドマップ生成
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t layer_, const std::size_t max_value_ = 2, const std::int_fast32_t type_ = 4) const noexcept {
			dtl::utility::layer::stl::randomInnerRandomValue(matrix_, layer_, 0, type_ - 1);
			for (std::size_t i{}; i < max_value_; ++i)
				dtl::utility::layer::stl::cellularAutomation(matrix_, layer_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t layer_, const std::size_t max_value_, const std::int_fast32_t type_min_, const std::int_fast32_t type_max_) const noexcept {
			dtl::utility::layer::stl::randomInnerRandomValue(matrix_, layer_, type_min_, type_max_);
			for (std::size_t i{}; i < max_value_; ++i)
				dtl::utility::layer::stl::cellularAutomation(matrix_, layer_);
		}
	};

} //namespace

namespace dtl::generator::terrain::layer::normal {

	//セルオートマトン法
	template<typename Matrix_Int_>
	class SimpleBiomeIsland {
	public:
		//コンストラクタ
		constexpr SimpleBiomeIsland() noexcept = default;
		template<typename Matrix_>
		constexpr explicit SimpleBiomeIsland(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const std::size_t max_value_ = 2, const std::int_fast32_t type_ = 4) noexcept {
			create(matrix_, layer_, x_, y_, max_value_, type_);
		}
		//ワールドマップ生成
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const std::size_t max_value_ = 2, const std::int_fast32_t type_ = 4) const noexcept {
			dtl::utility::layer::normal::randomInnerRandomValue(matrix_, layer_, x_, y_, 0, type_ - 1);
			for (std::size_t i{}; i < max_value_; ++i)
				dtl::utility::layer::normal::cellularAutomation(matrix_, layer_, x_, y_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const std::size_t max_value_, const std::int_fast32_t type_min_, const std::int_fast32_t type_max_) const noexcept {
			dtl::utility::layer::normal::randomInnerRandomValue(matrix_, layer_, x_, y_, type_min_, type_max_);
			for (std::size_t i{}; i < max_value_; ++i)
				dtl::utility::layer::normal::cellularAutomation(matrix_, layer_, x_, y_);
		}
	};

} //namespace

#endif //Included Dungeon Template Library