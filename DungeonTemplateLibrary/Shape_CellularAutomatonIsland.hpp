#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_CELLULAR_AUTOMATON_ISLAND
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_CELLULAR_AUTOMATON_ISLAND
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
#include "Shape_Border.hpp"
#include "Shape_RandomRect.hpp"
#include "Utility_CellularAutomaton.hpp"
#include "Base_Struct.hpp"

namespace dtl::shape {

	//マップの外枠を指定した数値で埋め、偶数マスを指定した数値で埋める
	template<typename Matrix_Int_>
	class CellularAutomatonIsland {
	private:


		///// エイリアス /////

		using Index_Size = std::size_t;
		using PairSize = std::pair<Index_Size, Index_Size>;
		using PairMatrixInt = std::pair<Matrix_Int_, Matrix_Int_>;


		///// メンバ変数 /////

		dtl::shape::Border<Matrix_Int_> border{};
		dtl::shape::RandomRect<Matrix_Int_> randomRect{};
		dtl::utility::CellularAutomation<Matrix_Int_> cellularAutomation{};
		Index_Size loop_num{1};

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
			randomRect.draw(matrix_, std::forward<Args_>(args_)...);
			border.draw(matrix_, std::forward<Args_>(args_)...);
			for (Index_Size i{}; i < loop_num; ++i)
				cellularAutomation.draw(matrix_, std::forward<Args_>(args_)...);
			return true;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawOperator(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			randomRect.drawOperator(matrix_, std::forward<Args_>(args_)...);
			border.drawOperator(matrix_, std::forward<Args_>(args_)...);
			for (Index_Size i{}; i < loop_num; ++i)
				cellularAutomation.draw(matrix_, std::forward<Args_>(args_)...);
			return true;
		}

		//Array
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawArray(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			randomRect.drawArray(matrix_, std::forward<Args_>(args_)...);
			border.drawArray(matrix_, std::forward<Args_>(args_)...);
			for (Index_Size i{}; i < loop_num; ++i)
				cellularAutomation.draw(matrix_, std::forward<Args_>(args_)...);
			return true;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawOperatorArray(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			randomRect.drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
			border.drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
			for (Index_Size i{}; i < loop_num; ++i)
				cellularAutomation.draw(matrix_, std::forward<Args_>(args_)...);
			return true;
		}


		///// ダンジョン行列生成 /////

		template<typename Matrix_, typename ...Args_>
		constexpr auto create(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			this->draw(matrix_, std::forward<Args_>(args_)...);
			return matrix_;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr auto createArray(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			this->drawArray(matrix_, std::forward<Args_>(args_)...);
			return matrix_;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr auto createOperator(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			this->drawOperator(matrix_, std::forward<Args_>(args_)...);
			return matrix_;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr auto createOperatorArray(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			this->drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
			return matrix_;
		}


		///// コンストラクタ /////

		constexpr CellularAutomatonIsland() noexcept = default;
		constexpr explicit CellularAutomatonIsland(const Matrix_Int_& draw_value_) noexcept
			:border(draw_value_), randomRect(draw_value_) {}
		constexpr explicit CellularAutomatonIsland(const PairMatrixInt& pair_value_) noexcept
			:border(pair_value_.second), randomRect(pair_value_.first) {}
		constexpr explicit CellularAutomatonIsland(const PairSize& length_) noexcept
			:border(length_), randomRect(length_) {}
		constexpr explicit CellularAutomatonIsland(const PairSize& length_, const Matrix_Int_& draw_value_) noexcept
			:border(length_, draw_value_), randomRect(length_, draw_value_) {}
		constexpr explicit CellularAutomatonIsland(const PairSize& length_, const PairMatrixInt& pair_value_) noexcept
			:border(length_, pair_value_.second), randomRect(length_, pair_value_.first) {}
		constexpr explicit CellularAutomatonIsland(const PairSize& position_, const PairSize& length_) noexcept
			:border(position_, length_), randomRect(position_, length_) {}
		constexpr explicit CellularAutomatonIsland(const PairSize& position_, const PairSize& length_, const Matrix_Int_& draw_value_) noexcept
			:border(position_, length_, draw_value_), randomRect(position_, length_, draw_value_) {}
		constexpr explicit CellularAutomatonIsland(const PairSize& position_, const PairSize& length_, const PairMatrixInt& pair_value_) noexcept
			:border(position_, length_, pair_value_.second), randomRect(position_, length_, pair_value_.first) {}


		constexpr explicit CellularAutomatonIsland(const Matrix_Int_& draw_value_, const Matrix_Int_& draw_value2_) noexcept
			:border(draw_value2_), randomRect(draw_value_) {}
		constexpr explicit CellularAutomatonIsland(const Matrix_Int_& draw_value_, const Matrix_Int_& draw_value2_, const Index_Size& loop_num_) noexcept
			:border(draw_value2_), randomRect(draw_value_),loop_num(loop_num_) {}
		constexpr explicit CellularAutomatonIsland(const Matrix_Int_& draw_value_, const Matrix_Int_& draw_value2_, const Index_Size& loop_num_,const double probability_) noexcept
			:border(draw_value2_), randomRect(draw_value_, probability_), loop_num(loop_num_) {}
		
		
		constexpr explicit CellularAutomatonIsland(const Index_Size width_, const Index_Size height_, const PairMatrixInt& pair_value_) noexcept
			:border(width_, height_, pair_value_.second), randomRect(width_, height_, pair_value_.first) {}
		constexpr explicit CellularAutomatonIsland(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
			:border(point_x_, point_y_, width_, height_), randomRect(point_x_, point_y_, width_, height_) {}
		constexpr explicit CellularAutomatonIsland(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_& draw_value_) noexcept
			:border(point_x_, point_y_, width_, height_, draw_value_), randomRect(point_x_, point_y_, width_, height_, draw_value_) {}
		constexpr explicit CellularAutomatonIsland(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const PairMatrixInt& pair_value_) noexcept
			:border(point_x_, point_y_, width_, height_, pair_value_.second), randomRect(point_x_, point_y_, width_, height_, pair_value_.first) {}

	};
}

#include <cstdint>
#include "Utility_CellularAutomaton.hpp"
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
				dtl::utility::stl::cellularAutomation(matrix_);
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
				dtl::utility::normal::cellularAutomation(matrix_, x_, y_);
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
				dtl::utility::array::cellularAutomation(matrix_, x_, y_);
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
				dtl::utility::layer::stl::cellularAutomation(matrix_, layer_);
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
				dtl::utility::layer::normal::cellularAutomation(matrix_, layer_, x_, y_);
		}
	};

} //namespace

#endif //Included Dungeon Template Library