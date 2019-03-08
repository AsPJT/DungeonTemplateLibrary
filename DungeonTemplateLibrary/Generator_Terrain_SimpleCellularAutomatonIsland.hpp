#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_GENERATOR_TERRAIN_SIMPLE_CELLULAR_AUTOMATON_ISLAND
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_GENERATOR_TERRAIN_SIMPLE_CELLULAR_AUTOMATON_ISLAND
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

/* Bug Check : not checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstdint>
#include "Utility_CellularAutomatonInner.hpp"
#include "Utility_RandomInnerBool.hpp"

namespace dtl::generator::terrain::stl {

	//セルオートマトン法
	template<typename Matrix_Int_>
	class SimpleCellularAutomatonIsland {
	public:
		//コンストラクタ
		constexpr SimpleCellularAutomatonIsland() noexcept = default;
		template<typename Matrix_>
		constexpr explicit SimpleCellularAutomatonIsland(Matrix_& matrix_, const std::size_t max_value_ = 2) noexcept {
			create(matrix_, max_value_);
		}
		//ワールドマップ生成
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t max_value_ = 2) const noexcept {
			dtl::utility::stl::randomInnerBool(matrix_);
			for (std::size_t i{}; i < max_value_; ++i)
				dtl::utility::stl::cellularAutomationInner(matrix_);
		}
	};

} //namespace

namespace dtl::generator::terrain::normal {

	//セルオートマトン法
	template<typename Matrix_Int_>
	class SimpleCellularAutomatonIsland {
	public:
		//コンストラクタ
		constexpr SimpleCellularAutomatonIsland() noexcept = default;
		template<typename Matrix_>
		constexpr explicit SimpleCellularAutomatonIsland(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t max_value_ = 2) noexcept {
			create(matrix_, x_, y_, max_value_);
		}
		//ワールドマップ生成
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t max_value_ = 2) const noexcept {
			dtl::utility::normal::randomInnerBool(matrix_, x_, y_);
			for (std::size_t i{}; i < max_value_; ++i)
				dtl::utility::normal::cellularAutomationInner(matrix_, x_, y_);
		}
	};

} //namespace

namespace dtl::generator::terrain::array {

	//セルオートマトン法
	template<typename Matrix_Int_>
	class SimpleCellularAutomatonIsland {
	public:
		//コンストラクタ
		constexpr SimpleCellularAutomatonIsland() noexcept = default;
		template<typename Matrix_>
		constexpr explicit SimpleCellularAutomatonIsland(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t max_value_ = 2) noexcept {
			create(matrix_, x_, y_, max_value_);
		}
		//ワールドマップ生成
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t max_value_ = 2) const noexcept {
			dtl::utility::array::randomInnerBool(matrix_, x_, y_);
			for (std::size_t i{}; i < max_value_; ++i)
				dtl::utility::array::cellularAutomationInner(matrix_, x_, y_);
		}
	};

} //namespace

namespace dtl::generator::terrain::layer::stl {

	//セルオートマトン法
	template<typename Matrix_Int_>
	class SimpleCellularAutomatonIsland {
	public:
		//コンストラクタ
		constexpr SimpleCellularAutomatonIsland() noexcept = default;
		template<typename Matrix_>
		constexpr explicit SimpleCellularAutomatonIsland(Matrix_& matrix_, const std::size_t layer_, const std::size_t max_value_ = 2) noexcept {
			create(matrix_, layer_, max_value_);
		}
		//ワールドマップ生成
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t layer_, const std::size_t max_value_ = 2) const noexcept {
			dtl::utility::layer::stl::randomInnerBool(matrix_, layer_);
			for (std::size_t i{}; i < max_value_; ++i)
				dtl::utility::layer::stl::cellularAutomationInner(matrix_, layer_);
		}
	};

} //namespace

namespace dtl::generator::terrain::layer::normal {

	//セルオートマトン法
	template<typename Matrix_Int_>
	class SimpleCellularAutomatonIsland {
	public:
		//コンストラクタ
		constexpr SimpleCellularAutomatonIsland() noexcept = default;
		template<typename Matrix_>
		constexpr explicit SimpleCellularAutomatonIsland(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const std::size_t max_value_ = 2) noexcept {
			create(matrix_, layer_, x_, y_, max_value_);
		}
		//ワールドマップ生成
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const std::size_t max_value_ = 2) const noexcept {
			dtl::utility::layer::normal::randomInnerBool(matrix_, layer_, x_, y_);
			for (std::size_t i{}; i < max_value_; ++i)
				dtl::utility::layer::normal::cellularAutomationInner(matrix_, layer_, x_, y_);
		}
	};

} //namespace

#endif //Included Dungeon Template Library