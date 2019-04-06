#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_CELLULAR_AUTOMATON_MIX_ISLAND
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_CELLULAR_AUTOMATON_MIX_ISLAND
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <Shape/Border.hpp>
#include <Shape/HalfMixRect.hpp>
#include <Utility/CellularAutomaton.hpp>
#include <Base/Struct.hpp>

namespace dtl::shape {

	//マップの外枠を指定した数値で埋め、偶数マスを指定した数値で埋める
	template<typename Matrix_Int_>
	class CellularAutomatonMixIsland {
	private:


		///// エイリアス /////

		using Index_Size = std::size_t;
		using PairSize = std::pair<Index_Size, Index_Size>;
		using PairMatrixInt = std::pair<Matrix_Int_, Matrix_Int_>;


		///// メンバ変数 /////

		dtl::shape::Border<Matrix_Int_> border{};
		dtl::shape::HalfMixRect<Matrix_Int_> mixRect{};
		dtl::utility::CellularAutomation<Matrix_Int_> cellularAutomation{};
		Index_Size loop_num{ 1 };

	public:


		///// 情報取得 /////

		[[nodiscard]] constexpr Index_Size getPointX() const noexcept {
			return this->border.getPointX();
		}
		[[nodiscard]] constexpr Index_Size getPointY() const noexcept {
			return this->border.getPointY();
		}
		[[nodiscard]] constexpr Index_Size getWidth() const noexcept {
			return this->border.getWidth();
		}
		[[nodiscard]] constexpr Index_Size getHeight() const noexcept {
			return this->border.getHeight();
		}
		[[nodiscard]] constexpr Matrix_Int_ getValue() const noexcept {
			return this->border.getValue();
		}


		///// 生成呼び出し /////

		template<typename Matrix_, typename ...Args_>
		constexpr bool draw(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			mixRect.draw(matrix_, args_...);
			border.draw(matrix_, args_...);
			for (Index_Size i{}; i < loop_num; ++i)
				cellularAutomation.draw(matrix_, args_...);
			return true;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawOperator(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			mixRect.drawOperator(matrix_, args_...);
			border.drawOperator(matrix_, args_...);
			for (Index_Size i{}; i < loop_num; ++i)
				cellularAutomation.draw(matrix_, args_...);
			return true;
		}

		//Array
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawArray(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			mixRect.drawArray(matrix_, args_...);
			border.drawArray(matrix_, args_...);
			for (Index_Size i{}; i < loop_num; ++i)
				cellularAutomation.draw(matrix_, args_...);
			return true;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawOperatorArray(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			mixRect.drawOperatorArray(matrix_, args_...);
			border.drawOperatorArray(matrix_, args_...);
			for (Index_Size i{}; i < loop_num; ++i)
				cellularAutomation.draw(matrix_, args_...);
			return true;
		}


		///// ダンジョン行列生成 /////

		template<typename Matrix_, typename ...Args_>
		constexpr auto create(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			this->draw(matrix_, std::forward<Args_>(args_)...);
			return std::forward<Matrix_>(matrix_);
		}
		template<typename Matrix_, typename ...Args_>
		constexpr auto createArray(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			this->drawArray(matrix_, std::forward<Args_>(args_)...);
			return std::forward<Matrix_>(matrix_);
		}
		template<typename Matrix_, typename ...Args_>
		constexpr auto createOperator(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			this->drawOperator(matrix_, std::forward<Args_>(args_)...);
			return std::forward<Matrix_>(matrix_);
		}
		template<typename Matrix_, typename ...Args_>
		constexpr auto createOperatorArray(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			this->drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
			return std::forward<Matrix_>(matrix_);
		}


		///// コンストラクタ /////

		constexpr CellularAutomatonMixIsland() noexcept = default;
		template<typename ...Args_>
		explicit CellularAutomatonMixIsland(const Index_Size& loop_num_, const Matrix_Int_& first_, const Args_&... args_) noexcept
			:border(first_), mixRect(first_, args_...), loop_num(loop_num_) {}
		template<typename ...Args_>
		constexpr explicit CellularAutomatonMixIsland(const dtl::base::MatrixRange& matrix_range_, const Index_Size& loop_num_, const Matrix_Int_& first_, const Args_&... args_) noexcept
			:border(matrix_range_, first_), mixRect(matrix_range_, first_, args_...), cellularAutomation(matrix_range_), loop_num(loop_num_) {}
	};
}

#include <cstdint>
#include <Utility/CellularAutomaton.hpp>
#include <Utility/RandomInnerRandomValue.hpp>

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