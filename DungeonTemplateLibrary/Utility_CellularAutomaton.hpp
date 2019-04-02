/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_CELLULAR_AUTOMATON
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_CELLULAR_AUTOMATON

/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include "Random_MersenneTwister32bit.hpp"

namespace dtl::utility {

	//マスを指定した数値で埋める
	template<typename Matrix_Int_>
	class CellularAutomation {
	private:


		///// エイリアス /////

		using Index_Size = std::size_t;
		using PairSize = std::pair<Index_Size, Index_Size>;


		///// メンバ変数 /////

		Index_Size point_x{};
		Index_Size point_y{};
		Index_Size width{};
		Index_Size height{};

		template<typename Matrix_>
		constexpr inline void switchSTL(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			switch (dtl::random::mt32bit_4.get()) {
			case 0:matrix_[point_y_][point_x_] = matrix_[point_y_][point_x_ - 1]; break;
			case 1:matrix_[point_y_][point_x_] = matrix_[point_y_][point_x_ + 1]; break;
			case 2:matrix_[point_y_][point_x_] = matrix_[point_y_ - 1][point_x_]; break;
			case 3:matrix_[point_y_][point_x_] = matrix_[point_y_ + 1][point_x_]; break;
			}
		}
		template<typename Matrix_>
		constexpr inline void switchArray(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
			switch (dtl::random::mt32bit_4.get()) {
			case 0:matrix_[point_y_ * max_x_ + point_x_] = matrix_[point_y_ * max_x_ + point_x_ - 1]; break;
			case 1:matrix_[point_y_ * max_x_ + point_x_] = matrix_[point_y_ * max_x_ + point_x_ + 1]; break;
			case 2:matrix_[point_y_ * max_x_ + point_x_] = matrix_[point_y_ - 1 * max_x_ + point_x_]; break;
			case 3:matrix_[point_y_ * max_x_ + point_x_] = matrix_[point_y_ + 1 * max_x_ + point_x_]; break;
			}
		}
		template<typename Matrix_>
		constexpr inline void switchLayer(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			switch (dtl::random::mt32bit_4.get()) {
			case 0:matrix_[point_y_][point_x_][layer_] = matrix_[point_y_][point_x_ - 1][layer_]; break;
			case 1:matrix_[point_y_][point_x_][layer_] = matrix_[point_y_][point_x_ + 1][layer_]; break;
			case 2:matrix_[point_y_][point_x_][layer_] = matrix_[point_y_ - 1][point_x_][layer_]; break;
			case 3:matrix_[point_y_][point_x_][layer_] = matrix_[point_y_ + 1][point_x_][layer_]; break;
			}
		}


		///// 代入処理 /////

		template<typename Matrix_>
		constexpr inline void substitutionSTL(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			if (matrix_[point_y_][point_x_ - 1] == matrix_[point_y_][point_x_ + 1] && matrix_[point_y_][point_x_ + 1] == matrix_[point_y_ - 1][point_x_] && matrix_[point_y_ - 1][point_x_] == matrix_[point_y_ + 1][point_x_])
				matrix_[point_y_][point_x_] = matrix_[point_y_][point_x_ + 1];
			else this->switchSTL(matrix_, point_x_, point_y_);
		}
		template<typename Matrix_>
		constexpr inline void substitutionArray(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {		
			if (matrix_[point_y_ * max_x_ + point_x_ - 1] == matrix_[point_y_ * max_x_ + point_x_ + 1] && matrix_[point_y_ * max_x_ + point_x_ + 1] == matrix_[point_y_ - 1 * max_x_ + point_x_] && matrix_[point_y_ - 1 * max_x_ + point_x_] == matrix_[point_y_ + 1 * max_x_ + point_x_])
				matrix_[point_y_ * max_x_ + point_x_] = matrix_[point_y_ * max_x_ + point_x_ + 1];
			else this->switchArray(matrix_, point_x_, point_y_, max_x_);
		}
		template<typename Matrix_>
		constexpr inline void substitutionLayer(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			if (matrix_[point_y_][point_x_ - 1][layer_] == matrix_[point_y_][point_x_ + 1][layer_] && matrix_[point_y_][point_x_ + 1][layer_] == matrix_[point_y_ - 1][point_x_][layer_] && matrix_[point_y_ - 1][point_x_][layer_] == matrix_[point_y_ + 1][point_x_][layer_])
				matrix_[point_y_][point_x_][layer_] = matrix_[point_y_][point_x_ + 1][layer_];
			else this->switchLayer(matrix_, layer_, point_x_, point_y_);
		}

		template<typename Matrix_, typename Function_>
		constexpr inline void substitutionSTL(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, Function_&& function_) const noexcept {
			if (matrix_[point_y_][point_x_ - 1] == matrix_[point_y_][point_x_ + 1] && matrix_[point_y_][point_x_ + 1] == matrix_[point_y_ - 1][point_x_] && matrix_[point_y_ - 1][point_x_] == matrix_[point_y_ + 1][point_x_] && function_(matrix_[point_y_][point_x_]))
				matrix_[point_y_][point_x_] = matrix_[point_y_][point_x_ + 1];
			else this->switchSTL(matrix_, point_x_, point_y_);
		}
		template<typename Matrix_, typename Function_>
		constexpr inline void substitutionArray(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Function_&& function_) const noexcept {
			if (matrix_[point_y_ * max_x_ + point_x_ - 1] == matrix_[point_y_ * max_x_ + point_x_ + 1] && matrix_[point_y_ * max_x_ + point_x_ + 1] == matrix_[point_y_ - 1 * max_x_ + point_x_] && matrix_[point_y_ - 1 * max_x_ + point_x_] == matrix_[point_y_ + 1 * max_x_ + point_x_]&& function_(matrix_[point_y_][point_x_]))
				matrix_[point_y_ * max_x_ + point_x_] = matrix_[point_y_ * max_x_ + point_x_ + 1];
			else this->switchArray(matrix_, point_x_, point_y_, max_x_);
		}
		template<typename Matrix_, typename Function_>
		constexpr inline void substitutionLayer(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Function_&& function_) const noexcept {
			if (matrix_[point_y_][point_x_ - 1][layer_] == matrix_[point_y_][point_x_ + 1][layer_] && matrix_[point_y_][point_x_ + 1][layer_] == matrix_[point_y_ - 1][point_x_][layer_] && matrix_[point_y_ - 1][point_x_][layer_] == matrix_[point_y_ + 1][point_x_][layer_]&& function_(matrix_[point_y_][point_x_]))
				matrix_[point_y_][point_x_][layer_] = matrix_[point_y_][point_x_ + 1][layer_];
			else this->switchLayer(matrix_, layer_, point_x_, point_y_);
		}


		///// 基本処理 /////

		//STL
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawSTL(Matrix_&& matrix_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			for (Index_Size row{ point_y+1 }; row < point_y_-1; ++row)
				for (Index_Size col{ point_x+1 }; col < matrix_[row].size()-1; ++col)
					this->substitutionSTL(matrix_, col, row, args_...);
			return true;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawWidthSTL(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			for (Index_Size row{ point_y+1 }; row < point_y_-1; ++row)
				for (Index_Size col{ point_x+1 }; col < matrix_[row].size()-1 && col < point_x_-1; ++col)
					this->substitutionSTL(matrix_, col, row, args_...);
			return true;
		}

		//LayerSTL
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawLayerSTL(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			for (Index_Size row{ point_y+1 }; row < point_y_-1; ++row)
				for (Index_Size col{ point_x+1 }; col < matrix_[row].size()-1; ++col)
					this->substitutionLayer(matrix_, layer_, col, row, args_...);
			return true;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawLayerWidthSTL(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			for (Index_Size row{ point_y+1 }; row < point_y_-1; ++row)
				for (Index_Size col{ point_x+1 }; col < matrix_[row].size()-1 && col < point_x_-1; ++col)
					this->substitutionLayer(matrix_, layer_, col, row, args_...);
			return true;
		}

		//Normal
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawNormal(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			for (Index_Size row{ point_y+1 }; row < point_y_-1; ++row)
				for (Index_Size col{ point_x+1 }; col < point_x_-1; ++col)
					this->substitutionSTL(matrix_, col, row, args_...);
			return true;
		}

		//LayerNormal
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawLayerNormal(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			for (Index_Size row{ point_y+1 }; row < point_y_-1; ++row)
				for (Index_Size col{ point_x+1 }; col < point_x_-1; ++col)
					this->substitutionLayer(matrix_, layer_, col, row, args_...);
			return true;
		}

		//Array
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawArray(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Args_&&... args_) const noexcept {
			for (Index_Size row{ point_y+1 }; row < point_y_-1; ++row)
				for (Index_Size col{ point_x+1 }; col < point_x_-1; ++col)
					this->substitutionArray(matrix_, col, row, max_x_, args_...);
			return true;
		}

	public:


		///// 情報取得 /////

		[[nodiscard]] constexpr Index_Size getPointX() const noexcept {
			return this->point_x;
		}
		[[nodiscard]] constexpr Index_Size getPointY() const noexcept {
			return this->point_y;
		}
		[[nodiscard]] constexpr Index_Size getWidth() const noexcept {
			return this->width;
		}
		[[nodiscard]] constexpr Index_Size getHeight() const noexcept {
			return this->height;
		}
		[[nodiscard]] constexpr Matrix_Int_ getValue() const noexcept {
			return this->draw_value;
		}


		///// 生成呼び出し /////

		//STL
		template<typename Matrix_>
		constexpr bool draw(Matrix_&& matrix_) const noexcept {
			return (width == 0) ? this->drawSTL(std::forward<Matrix_>(matrix_), (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height) : this->drawWidthSTL(matrix_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperator(Matrix_&& matrix_, Function_&& function_) const noexcept {
			return (width == 0) ? this->drawSTL(std::forward<Matrix_>(matrix_), (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_) : this->drawWidthSTL(matrix_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_);
		}

		//LayerSTL
		template<typename Matrix_>
		constexpr bool draw(Matrix_&& matrix_, const Index_Size layer_) const noexcept {
			return (width == 0) ? this->drawLayerSTL(std::forward<Matrix_>(matrix_), layer_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height) : this->drawLayerWidthSTL(matrix_, layer_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperator(Matrix_&& matrix_, const Index_Size layer_, Function_&& function_) const noexcept {
			return (width == 0) ? this->drawLayerSTL(std::forward<Matrix_>(matrix_), layer_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_) : this->drawLayerWidthSTL(matrix_, layer_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_);
		}

		//Normal
		template<typename Matrix_>
		constexpr bool draw(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawNormal(std::forward<Matrix_>(matrix_), (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperator(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_&& function_) const noexcept {
			return this->drawNormal(std::forward<Matrix_>(matrix_), (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, function_);
		}

		//LayerNormal
		template<typename Matrix_>
		constexpr bool draw(Matrix_&& matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperator(Matrix_&& matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_&& function_) const noexcept {
			return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, function_);
		}

		//Array
		template<typename Matrix_>
		constexpr bool drawArray(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawArray(std::forward<Matrix_>(matrix_), (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, max_x_);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperatorArray(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_&& function_) const noexcept {
			return this->drawArray(std::forward<Matrix_>(matrix_), (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, max_x_, function_);
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

		constexpr CellularAutomation() noexcept = default;
		constexpr explicit CellularAutomation(const PairSize& length_) noexcept
			:width(length_.first), height(length_.second) {}
		constexpr explicit CellularAutomation(const PairSize& position_, const PairSize& length_) noexcept
			:point_x(position_.first), point_y(position_.second),
			width(length_.first), height(length_.second) {}
		constexpr explicit CellularAutomation(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
			:point_x(point_x_), point_y(point_y_),
			width(width_), height(height_) {}
	};
	using CellularAutomationU8 = dtl::utility::CellularAutomation<std::uint_fast8_t>;
	using CellularAutomationU16 = dtl::utility::CellularAutomation<std::uint_fast16_t>;
	using CellularAutomationU32 = dtl::utility::CellularAutomation<std::uint_fast32_t>;
	using CellularAutomationU64 = dtl::utility::CellularAutomation<std::uint_fast64_t>;
	using CellularAutomationI8 = dtl::utility::CellularAutomation<std::int_fast8_t>;
	using CellularAutomationI16 = dtl::utility::CellularAutomation<std::int_fast16_t>;
	using CellularAutomationI32 = dtl::utility::CellularAutomation<std::int_fast32_t>;
	using CellularAutomationI64 = dtl::utility::CellularAutomation<std::int_fast64_t>;
}


#include <cstddef>
#include "Random_MersenneTwister32bit.hpp"
#include "Utility_Matrix.hpp"

//STLデータ
namespace dtl::utility::stl {

	template<typename Matrix_>
	constexpr void cellularAutomation(Matrix_& matrix_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(matrix_)) return;

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{ 1 }; row < matrix_.size() - 1; ++row)
			for (std::size_t col{ 1 }; col < matrix_[row].size() - 1; ++col) {
				if (matrix_[row][col - 1] == matrix_[row][col + 1] && matrix_[row][col + 1] == matrix_[row - 1][col] && matrix_[row - 1][col] == matrix_[row + 1][col])
					matrix_[row][col] = matrix_[row][col + 1];
				else switch (mersenne_twister_32bit(4)) {
				case 0:matrix_[row][col] = matrix_[row][col - 1]; break;
				case 1:matrix_[row][col] = matrix_[row][col + 1]; break;
				case 2:matrix_[row][col] = matrix_[row - 1][col]; break;
				case 3:matrix_[row][col] = matrix_[row + 1][col]; break;
				}
			}
	}

} //namespace

//通常データ
namespace dtl::utility::normal {

	template<typename Matrix_>
	constexpr void cellularAutomation(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{ 1 }; row < y_ - 1; ++row)
			for (std::size_t col{ 1 }; col < x_ - 1; ++col) {
				if (matrix_[row][col - 1] == matrix_[row][col + 1] && matrix_[row][col + 1] == matrix_[row - 1][col] && matrix_[row - 1][col] == matrix_[row + 1][col])
					matrix_[row][col] = matrix_[row][col + 1];
				else switch (mersenne_twister_32bit(4)) {
				case 0:matrix_[row][col] = matrix_[row][col - 1]; break;
				case 1:matrix_[row][col] = matrix_[row][col + 1]; break;
				case 2:matrix_[row][col] = matrix_[row - 1][col]; break;
				case 3:matrix_[row][col] = matrix_[row + 1][col]; break;
				}
			}
	}

} //namespace

//配列データ
namespace dtl::utility::array {

	template<typename Matrix_>
	constexpr void cellularAutomation(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{ 1 }; row < y_ - 1; ++row)
			for (std::size_t col{ 1 }; col < x_ - 1; ++col) {
				if (matrix_[(row)*x_ + (col - 1)] == matrix_[(row)*x_ + (col + 1)] && matrix_[(row)*x_ + (col + 1)] == matrix_[(row - 1)*x_ + (col)] && matrix_[(row - 1)*x_ + (col)] == matrix_[(row + 1)*x_ + (col)])
					matrix_[(row)*x_ + (col)] = matrix_[(row)*x_ + (col + 1)];
				else switch (mersenne_twister_32bit(4)) {
				case 0:matrix_[(row)*x_ + (col)] = matrix_[(row)*x_ + (col - 1)]; break;
				case 1:matrix_[(row)*x_ + (col)] = matrix_[(row)*x_ + (col + 1)]; break;
				case 2:matrix_[(row)*x_ + (col)] = matrix_[(row - 1)*x_ + (col)]; break;
				case 3:matrix_[(row)*x_ + (col)] = matrix_[(row + 1)*x_ + (col)]; break;
				}
			}
	}

} //namespace

//レイヤーSTLデータ
namespace dtl::utility::layer::stl {

	template<typename Matrix_>
	constexpr void cellularAutomation(Matrix_& matrix_, const std::size_t layer_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(matrix_)) return;

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{ 1 }; row < matrix_.size() - 1; ++row)
			for (std::size_t col{ 1 }; col < matrix_[row].size() - 1; ++col) {
				if (matrix_[row][col - 1][layer_] == matrix_[row][col + 1][layer_] && matrix_[row][col + 1][layer_] == matrix_[row - 1][col][layer_] && matrix_[row - 1][col][layer_] == matrix_[row + 1][col][layer_])
					matrix_[row][col][layer_] = matrix_[row][col + 1][layer_];
				else switch (mersenne_twister_32bit(4)) {
				case 0:matrix_[row][col][layer_] = matrix_[row][col - 1][layer_]; break;
				case 1:matrix_[row][col][layer_] = matrix_[row][col + 1][layer_]; break;
				case 2:matrix_[row][col][layer_] = matrix_[row - 1][col][layer_]; break;
				case 3:matrix_[row][col][layer_] = matrix_[row + 1][col][layer_]; break;
				}
			}
	}

} //namespace

//レイヤー通常データ
namespace dtl::utility::layer::normal {

	template<typename Matrix_>
	constexpr void cellularAutomation(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{ 1 }; row < y_ - 1; ++row)
			for (std::size_t col{ 1 }; col < x_ - 1; ++col) {
				if (matrix_[row][col - 1][layer_] == matrix_[row][col + 1][layer_] && matrix_[row][col + 1][layer_] == matrix_[row - 1][col][layer_] && matrix_[row - 1][col][layer_] == matrix_[row + 1][col][layer_])
					matrix_[row][col][layer_] = matrix_[row][col + 1][layer_];
				else switch (mersenne_twister_32bit(4)) {
				case 0:matrix_[row][col][layer_] = matrix_[row][col - 1][layer_]; break;
				case 1:matrix_[row][col][layer_] = matrix_[row][col + 1][layer_]; break;
				case 2:matrix_[row][col][layer_] = matrix_[row - 1][col][layer_]; break;
				case 3:matrix_[row][col][layer_] = matrix_[row + 1][col][layer_]; break;
				}
			}
	}

} //namespace

#endif //Included Dungeon Template Library