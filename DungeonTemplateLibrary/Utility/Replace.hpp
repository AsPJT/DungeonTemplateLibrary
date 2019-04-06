/*#######################################################################################
	Made by Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_REPLACE
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_REPLACE

/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <Utility/Copy.hpp>

namespace dtl::utility::stl {

	//ダンジョン配列内にある"before_value_"値を"after_value_"値に置き換える。
	template<typename After_Value_Int_, typename Before_Value_Int_, typename Matrix_>
	constexpr void replace(Matrix_& matrix_, const After_Value_Int_ after_value_, const Before_Value_Int_ before_value_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				if (matrix_[row][col] == before_value_) dtl::utility::tool::castCopyValue(matrix_[row][col], after_value_);
	}

}

namespace dtl::utility::normal {

	//ダンジョン配列内にある"before_value_"値を"after_value_"値に置き換える。
	template<typename After_Value_Int_, typename Before_Value_Int_, typename Matrix_>
	constexpr void replace(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const After_Value_Int_ after_value_, const Before_Value_Int_ before_value_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				if (matrix_[row][col] == before_value_) dtl::utility::tool::castCopyValue(matrix_[row][col], after_value_);
	}

}

namespace dtl::utility::array {

	//ダンジョン配列内にある"before_value_"値を"after_value_"値に置き換える。
	template<typename After_Value_Int_, typename Before_Value_Int_, typename Matrix_>
	constexpr void replace(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const After_Value_Int_ after_value_, const Before_Value_Int_ before_value_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				if (matrix_[row*x_ + col] == before_value_) dtl::utility::tool::castCopyValue(matrix_[row*x_ + col], after_value_);
	}

}

namespace dtl::utility::rangeBasedFor {

	//ダンジョン配列内にある"before_value_"値を"after_value_"値に置き換える。
	template<typename After_Value_Int_, typename Before_Value_Int_, typename Matrix_>
	constexpr void replace(Matrix_& matrix_, const After_Value_Int_ after_value_, const Before_Value_Int_ before_value_) noexcept {
		for (auto&& row : matrix_)
			for (auto&& col : row)
				if (col == before_value_) dtl::utility::tool::castCopyValue(col, after_value_);
	}

}

namespace dtl::utility::layer::stl {

	//ダンジョン配列内にある"before_value_"値を"after_value_"値に置き換える。
	template<typename After_Value_Int_, typename Before_Value_Int_, typename Matrix_>
	constexpr void replace(Matrix_& matrix_, const std::size_t layer_, const After_Value_Int_ after_value_, const Before_Value_Int_ before_value_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				if (matrix_[row][col][layer_] == before_value_) dtl::utility::tool::castCopyValue(matrix_[row][col][layer_], after_value_);
	}

}

namespace dtl::utility::layer::normal {

	//ダンジョン配列内にある"before_value_"値を"after_value_"値に置き換える。
	template<typename After_Value_Int_, typename Before_Value_Int_, typename Matrix_>
	constexpr void replace(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const After_Value_Int_ after_value_, const Before_Value_Int_ before_value_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				if (matrix_[row][col][layer_] == before_value_) dtl::utility::tool::castCopyValue(matrix_[row][col][layer_], after_value_);
	}

}

#endif //Included Dungeon Template Library