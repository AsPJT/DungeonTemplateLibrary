/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_OUTPUT_NUMBER
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_OUTPUT_NUMBER

/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <iostream>
#include <string>

namespace dtl::console {

	//四角形の生成
	template<typename Matrix_Int_>
	class OutputNumber {
	private:


		///// エイリアス /////

		using Index_Size = std::size_t;
		using PairSize = std::pair<Index_Size, Index_Size>;


		///// メンバ変数 /////

		const std::string& before_draw_string{};
		const std::string& draw_string{};
		Index_Size point_x{};
		Index_Size point_y{};
		Index_Size width{};
		Index_Size height{};

		///// キャスト判定 /////

		template<typename Int_>
		[[nodiscard]] constexpr bool isCast() const noexcept {
			return false;
		}
		template<>
		[[nodiscard]] constexpr bool isCast<char>() const noexcept {
			return true;
		}
		template<>
		[[nodiscard]] constexpr bool isCast<signed char>() const noexcept {
			return true;
		}
		template<>
		[[nodiscard]] constexpr bool isCast<unsigned char>() const noexcept {
			return true;
		}


		///// 代入処理 /////

		template<typename Matrix_>
		inline void outputSTL(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			std::cout << before_draw_string << ((isCast<Matrix_Int_>()) ? static_cast<int>(matrix_[point_y_][point_x_]) : matrix_[point_y_][point_x_]) << draw_string;
		}
		template<typename Matrix_>
		inline void outputArray(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
			std::cout << before_draw_string << ((isCast<Matrix_Int_>()) ? static_cast<int>(matrix_[point_y_ * max_x_ + point_x_]) : matrix_[point_y_ * max_x_ + point_x_]) << draw_string;
		}
		template<typename Matrix_>
		inline void outputLayer(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			std::cout << before_draw_string << ((isCast<Matrix_Int_>()) ? static_cast<int>(matrix_[point_y_][point_x_][layer_]) : matrix_[point_y_][point_x_][layer_]) << draw_string;
		}


		///// 基本処理 /////

		//STL
		template<typename Matrix_>
		bool drawSTL(Matrix_&& matrix_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				for (Index_Size col{ point_x }; col < matrix_[row].size(); ++col)
					this->outputSTL(matrix_, col, row);
				std::cout << '\n';
			}
			return true;
		}
		template<typename Matrix_>
		bool drawWidthSTL(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				for (Index_Size col{ point_x }; col < matrix_[row].size() && col < point_x_; ++col)
					this->outputSTL(matrix_, col, row);
				std::cout << '\n';
			}
			return true;
		}

		//LayerSTL
		template<typename Matrix_>
		bool drawLayerSTL(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				for (Index_Size col{ point_x }; col < matrix_[row].size(); ++col)
					this->outputLayer(matrix_, layer_, col, row);
				std::cout << '\n';
			}
			return true;
		}
		template<typename Matrix_>
		bool drawLayerWidthSTL(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				for (Index_Size col{ point_x }; col < matrix_[row].size() && col < point_x_; ++col)
					this->outputLayer(matrix_, layer_, col, row);
				std::cout << '\n';
			}
			return true;
		}

		//Normal
		template<typename Matrix_>
		bool drawNormal(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				for (Index_Size col{ point_x }; col < point_x_; ++col)
					this->outputSTL(matrix_, col, row);
				std::cout << '\n';
			}
			return true;
		}

		//LayerNormal
		template<typename Matrix_>
		bool drawLayerNormal(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				for (Index_Size col{ point_x }; col < point_x_; ++col)
					this->outputLayer(matrix_, layer_, col, row);
				std::cout << '\n';
			}
			return true;
		}

		//Array
		template<typename Matrix_>
		bool drawArray(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				for (Index_Size col{ point_x }; col < point_x_; ++col)
					this->outputArray(matrix_, col, row, max_x_);
				std::cout << '\n';
			}
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
			return this->draw_string;
		}


		///// 生成呼び出し /////

		//STL
		template<typename Matrix_>
		bool draw(Matrix_&& matrix_) const noexcept {
			return (width == 0) ? this->drawSTL(matrix_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height) : this->drawWidthSTL(matrix_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height);
		}

		//LayerSTL
		template<typename Matrix_>
		bool draw(Matrix_&& matrix_, const Index_Size layer_) const noexcept {
			return (width == 0) ? this->drawLayerSTL(matrix_, layer_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height) : this->drawLayerWidthSTL(matrix_, layer_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height);
		}

		//Normal
		template<typename Matrix_>
		bool draw(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawNormal(matrix_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height);
		}

		//LayerNormal
		template<typename Matrix_>
		bool draw(Matrix_&& matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawLayerNormal(matrix_, layer_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height);
		}

		//Array
		template<typename Matrix_>
		bool drawArray(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawArray(matrix_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, max_x_);
		}


		///// ダンジョン行列生成 /////

		//STL
		template<typename Matrix_>
		auto create(Matrix_&& matrix_) const noexcept {
			this->draw(matrix_);
			return matrix_;
		}
		template<typename Matrix_>
		auto create(Matrix_&& matrix_, bool& return_value_) const noexcept {
			return_value_ = this->draw(matrix_);
			return matrix_;
		}

		//LayerSTL
		template<typename Matrix_>
		auto create(Matrix_&& matrix_, const Index_Size layer_) const noexcept {
			this->draw(matrix_, layer_);
			return matrix_;
		}
		template<typename Matrix_>
		auto create(Matrix_&& matrix_, const Index_Size layer_, bool& return_value_) const noexcept {
			return_value_ = this->draw(matrix_, layer_);
			return matrix_;
		}

		//Normal
		template<typename Matrix_>
		auto create(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			this->draw(matrix_, max_x_, max_y_);
			return matrix_;
		}
		template<typename Matrix_>
		auto create(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_, bool& return_value_) const noexcept {
			return_value_ = this->draw(matrix_, max_x_, max_y_);
			return matrix_;
		}

		//LayerNormal
		template<typename Matrix_>
		auto create(Matrix_&& matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			this->draw(matrix_, layer_, max_x_, max_y_);
			return matrix_;
		}
		template<typename Matrix_>
		auto create(Matrix_&& matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, bool& return_value_) const noexcept {
			return_value_ = this->draw(matrix_, layer_, max_x_, max_y_);
			return matrix_;
		}

		//Array
		template<typename Matrix_>
		auto createArray(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			this->drawArray(matrix_, max_x_, max_y_);
			return matrix_;
		}
		template<typename Matrix_>
		auto createArray(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_, bool& return_value_) const noexcept {
			return_value_ = this->drawArray(matrix_, max_x_, max_y_);
			return matrix_;
		}


		///// コンストラクタ /////

		constexpr OutputNumber() noexcept = default;
		constexpr explicit OutputNumber(const std::string& draw_string_) noexcept
			:draw_string(draw_string_) {}
		constexpr explicit OutputNumber(const std::string& before_draw_string_, const std::string& draw_string_) noexcept
			:draw_string(draw_string_), before_draw_string(before_draw_string_) {}
		constexpr explicit OutputNumber(const PairSize& length_) noexcept
			:width(length_.first), height(length_.second) {}
		constexpr explicit OutputNumber(const PairSize& length_, const std::string& draw_string_) noexcept
			:width(length_.first), height(length_.second),
			draw_string(draw_string_) {}
		constexpr explicit OutputNumber(const PairSize& length_, const std::string& before_draw_string_, const std::string& draw_string_) noexcept
			:width(length_.first), height(length_.second),
			draw_string(draw_string_), before_draw_string(before_draw_string_) {}
		constexpr explicit OutputNumber(const PairSize& position_, const PairSize& length_) noexcept
			:point_x(position_.first), point_y(position_.second),
			width(length_.first), height(length_.second) {}
		constexpr explicit OutputNumber(const PairSize& position_, const PairSize& length_, const std::string& draw_string_) noexcept
			:point_x(position_.first), point_y(position_.second),
			width(length_.first), height(length_.second),
			draw_string(draw_string_) {}
		constexpr explicit OutputNumber(const PairSize& position_, const PairSize& length_, const std::string& before_draw_string_, const std::string& draw_string_) noexcept
			:point_x(position_.first), point_y(position_.second),
			width(length_.first), height(length_.second),
			draw_string(draw_string_), before_draw_string(before_draw_string_) {}
		constexpr explicit OutputNumber(const Index_Size width_, const Index_Size height_) noexcept
			:width(width_), height(height_) {}
		constexpr explicit OutputNumber(const Index_Size width_, const Index_Size height_, const std::string& draw_string_) noexcept
			:width(width_), height(height_),
			draw_string(draw_string_) {}
		constexpr explicit OutputNumber(const Index_Size width_, const Index_Size height_, const std::string& before_draw_string_, const std::string& draw_string_) noexcept
			:width(width_), height(height_),
			draw_string(draw_string_), before_draw_string(before_draw_string_) {}
		constexpr explicit OutputNumber(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
			:point_x(point_x_), point_y(point_y_),
			width(width_), height(height_) {}
		constexpr explicit OutputNumber(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const std::string& draw_string_) noexcept
			:point_x(point_x_), point_y(point_y_),
			width(width_), height(height_),
			draw_string(draw_string_) {}
		constexpr explicit OutputNumber(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const std::string& before_draw_string_, const std::string& draw_string_) noexcept
			:point_x(point_x_), point_y(point_y_),
			width(width_), height(height_),
			draw_string(draw_string_), before_draw_string(before_draw_string_) {}
	};
}


#include "Utility_GetOutputNumber.hpp"

//STLデータ
namespace dtl::console::output::stl {

	//数値出力
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				std::cout << dtl::utility::tool::getOutputNumber(matrix_[row][col]);
			std::cout << '\n';
		}
	}
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::string& string_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				std::cout << dtl::utility::tool::getOutputNumber(matrix_[row][col]) << string_;
			std::cout << '\n';
		}
	}

} //namespace

//通常データ
namespace dtl::console::output::normal {

	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col)
				std::cout << dtl::utility::tool::getOutputNumber(matrix_[row][col]);
			std::cout << '\n';
		}
	}
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::string& string_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col)
				std::cout << dtl::utility::tool::getOutputNumber(matrix_[row][col]) << string_;
			std::cout << '\n';
		}
	}

} //namespace

//配列データ
namespace dtl::console::output::array {

	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col)
				std::cout << dtl::utility::tool::getOutputNumber(matrix_[row * x_ + col]);
			std::cout << '\n';
		}
	}
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::string& string_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col)
				std::cout << dtl::utility::tool::getOutputNumber(matrix_[row * x_ + col]) << string_;
			std::cout << '\n';
		}
	}

} //namespace

//範囲forデータ
namespace dtl::console::output::rangeBasedFor {

	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_) noexcept {
		for (const auto& row : matrix_) {
			for (const auto& col : row)
				std::cout << dtl::utility::tool::getOutputNumber(col);
			std::cout << '\n';
		}
	}
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::string& string_) noexcept {
		for (const auto& row : matrix_) {
			for (const auto& col : row)
				std::cout << dtl::utility::tool::getOutputNumber(col) << string_;
			std::cout << '\n';
		}
	}

} //namespace

//レイヤーSTLデータ
namespace dtl::console::output::layer::stl {

	//数値出力
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t layer_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				std::cout << dtl::utility::tool::getOutputNumber(matrix_[row][col][layer_]);
			std::cout << '\n';
		}
	}
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t layer_, const std::string& string_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				std::cout << dtl::utility::tool::getOutputNumber(matrix_[row][col][layer_]) << string_;
			std::cout << '\n';
		}
	}

} //namespace

//レイヤー通常データ
namespace dtl::console::output::layer::normal {

	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col)
				std::cout << dtl::utility::tool::getOutputNumber(matrix_[row][col][layer_]);
			std::cout << '\n';
		}
	}
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const std::string& string_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col)
				std::cout << dtl::utility::tool::getOutputNumber(matrix_[row][col][layer_]) << string_;
			std::cout << '\n';
		}
	}

} //namespace

#endif //Included Dungeon Template Library