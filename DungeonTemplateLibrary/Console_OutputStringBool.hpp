/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_OUTPUT_STRING_BOOL
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_OUTPUT_STRING_BOOL

/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <iostream>
#include <string>

namespace dtl::console {

	//四角形の生成
	template<typename Matrix_Int_, typename OutputString_ = std::string>
	class OutputStringBool {
	private:


		///// エイリアス /////

		using Index_Size = std::size_t;
		using PairSize = std::pair<Index_Size, Index_Size>;


		///// メンバ変数 /////

		Index_Size point_x{};
		Index_Size point_y{};
		Index_Size width{};
		Index_Size height{};
		OutputString_ false_string{};
		OutputString_ true_string{};


		///// 代入処理 /////

		template<typename Matrix_>
		[[nodiscard]] constexpr inline auto outputSTL(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			return matrix_[point_y_][point_x_];
		}
		template<typename Matrix_>
		[[nodiscard]] constexpr inline auto outputArray(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
			return matrix_[point_y_ * max_x_ + point_x_];
		}
		template<typename Matrix_>
		[[nodiscard]] constexpr inline auto outputLayer(const Matrix_& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			return matrix_[point_y_][point_x_][layer_];
		}


		///// 基本処理 /////

		//STL
		template<typename Matrix_>
		bool drawSTL(const Matrix_& matrix_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				for (Index_Size col{ point_x }; col < matrix_[row].size(); ++col)
					std::cout << ((this->outputSTL(matrix_, col, row)) ? true_string : false_string);
				std::cout << '\n';
			}
			return true;
		}
		template<typename Matrix_>
		bool drawWidthSTL(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				for (Index_Size col{ point_x }; col < matrix_[row].size() && col < point_x_; ++col)
					std::cout << ((this->outputSTL(matrix_, col, row)) ? true_string : false_string);
				std::cout << '\n';
			}
			return true;
		}

		//LayerSTL
		template<typename Matrix_>
		bool drawLayerSTL(const Matrix_& matrix_, const Index_Size layer_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				for (Index_Size col{ point_x }; col < matrix_[row].size(); ++col)
					std::cout << ((this->outputLayer(matrix_, layer_, col, row)) ? true_string : false_string);
				std::cout << '\n';
			}
			return true;
		}
		template<typename Matrix_>
		bool drawLayerWidthSTL(const Matrix_& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				for (Index_Size col{ point_x }; col < matrix_[row].size() && col < point_x_; ++col)
					std::cout << ((this->outputLayer(matrix_, layer_, col, row)) ? true_string : false_string);
				std::cout << '\n';
			}
			return true;
		}

		//Normal
		template<typename Matrix_>
		bool drawNormal(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				for (Index_Size col{ point_x }; col < point_x_; ++col)
					std::cout << ((this->outputSTL(matrix_, col, row)) ? true_string : false_string);
				std::cout << '\n';
			}
			return true;
		}

		//LayerNormal
		template<typename Matrix_>
		bool drawLayerNormal(const Matrix_& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				for (Index_Size col{ point_x }; col < point_x_; ++col)
					std::cout << ((this->outputLayer(matrix_, layer_, col, row)) ? true_string : false_string);
				std::cout << '\n';
			}
			return true;
		}

		//Array
		template<typename Matrix_>
		bool drawArray(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				for (Index_Size col{ point_x }; col < point_x_; ++col)
					std::cout << ((this->outputArray(matrix_, col, row, max_x_)) ? true_string : false_string);
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


		///// 生成呼び出し /////

		//STL
		template<typename Matrix_>
		bool draw(const Matrix_& matrix_) const noexcept {
			return (width == 0) ? this->drawSTL(matrix_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height) : this->drawWidthSTL(matrix_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height);
		}

		//LayerSTL
		template<typename Matrix_>
		bool draw(const Matrix_& matrix_, const Index_Size layer_) const noexcept {
			return (width == 0) ? this->drawLayerSTL(matrix_, layer_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height) : this->drawLayerWidthSTL(matrix_, layer_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height);
		}

		//Normal
		template<typename Matrix_>
		bool draw(const Matrix_& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawNormal(matrix_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height);
		}

		//LayerNormal
		template<typename Matrix_>
		bool draw(const Matrix_& matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawLayerNormal(matrix_, layer_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height);
		}

		//Array
		template<typename Matrix_>
		bool drawArray(const Matrix_& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
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

		constexpr OutputStringBool() noexcept = default;
		constexpr explicit OutputStringBool(const OutputString_& true_string_) noexcept
			:true_string(true_string_) {}
		constexpr explicit OutputStringBool(const OutputString_& true_string_, const OutputString_& false_string_) noexcept
			:false_string(false_string_), true_string(true_string_) {}
		constexpr explicit OutputStringBool(const PairSize& length_) noexcept
			:width(length_.first), height(length_.second) {}
		constexpr explicit OutputStringBool(const PairSize& length_, const OutputString_& true_string_) noexcept
			:width(length_.first), height(length_.second),
			true_string(true_string_) {}
		constexpr explicit OutputStringBool(const PairSize& length_, const OutputString_& true_string_, const OutputString_& false_string_) noexcept
			:width(length_.first), height(length_.second),
			false_string(false_string_), true_string(true_string_) {}
		constexpr explicit OutputStringBool(const PairSize& position_, const PairSize& length_) noexcept
			:point_x(position_.first), point_y(position_.second),
			width(length_.first), height(length_.second) {}
		constexpr explicit OutputStringBool(const PairSize& position_, const PairSize& length_, const OutputString_& true_string_) noexcept
			:point_x(position_.first), point_y(position_.second),
			width(length_.first), height(length_.second),
			true_string(true_string_) {}
		constexpr explicit OutputStringBool(const PairSize& position_, const PairSize& length_, const OutputString_& true_string_, const OutputString_& false_string_) noexcept
			:point_x(position_.first), point_y(position_.second),
			width(length_.first), height(length_.second),
			false_string(false_string_), true_string(true_string_) {}
		constexpr explicit OutputStringBool(const Index_Size width_, const Index_Size height_) noexcept
			:width(width_), height(height_) {}
		constexpr explicit OutputStringBool(const Index_Size width_, const Index_Size height_, const OutputString_& true_string_) noexcept
			:width(width_), height(height_),
			true_string(true_string_) {}
		constexpr explicit OutputStringBool(const Index_Size width_, const Index_Size height_, const OutputString_& true_string_, const OutputString_& false_string_) noexcept
			:width(width_), height(height_),
			false_string(false_string_), true_string(true_string_) {}
		constexpr explicit OutputStringBool(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
			:point_x(point_x_), point_y(point_y_),
			width(width_), height(height_) {}
		constexpr explicit OutputStringBool(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const OutputString_& true_string_) noexcept
			:point_x(point_x_), point_y(point_y_),
			width(width_), height(height_),
			true_string(true_string_) {}
		constexpr explicit OutputStringBool(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const OutputString_& true_string_, const OutputString_& false_string_) noexcept
			:point_x(point_x_), point_y(point_y_),
			width(width_), height(height_),
			false_string(false_string_), true_string(true_string_) {}
	};
	template<typename Matrix_Int_>
	using OutputStringBoolS16 = OutputStringBool<Matrix_Int_, std::u16string>;
	template<typename Matrix_Int_>
	using OutputStringBoolS32 = OutputStringBool<Matrix_Int_, std::u32string>;
}





//STLデータ
namespace dtl::console::output::stl {

	template<typename Matrix_>
	constexpr void stringBool(const Matrix_& matrix_, const std::string& true_, const std::string& false_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (matrix_[row][col]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << '\n';
		}
	}

	template<typename Matrix_>
	constexpr void stringBool(const Matrix_& matrix_, const std::string& true_, const std::string& false_, const std::size_t loop_num_) noexcept {
		if (loop_num_ == 0) return;
		for (std::size_t row{}; row < (matrix_.size()*loop_num_); ++row) {
			for (std::size_t col{}; col < (matrix_[row].size()*loop_num_); ++col) {
				if (matrix_[row / loop_num_][col / loop_num_]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << '\n';
		}
	}

} //namespace

//通常データ
namespace dtl::console::output::normal {

	template<typename Matrix_>
	constexpr void stringBool(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::string& true_, const std::string& false_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col) {
				if (matrix_[row][col]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << '\n';
		}
	}

	template<typename Matrix_>
	constexpr void stringBool(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::string& true_, const std::string& false_, const std::size_t loop_num_) noexcept {
		if (loop_num_ == 0) return;
		for (std::size_t row{}; row < (y_*loop_num_); ++row) {
			for (std::size_t col{}; col < (x_*loop_num_); ++col) {
				if (matrix_[row / loop_num_][col / loop_num_]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << '\n';
		}
	}

} //namespace

//配列データ
namespace dtl::console::output::array {

	template<typename Matrix_>
	constexpr void stringBool(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::string& true_, const std::string& false_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col) {
				if (matrix_[row * x_ + col]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << '\n';
		}
	}

	template<typename Matrix_>
	constexpr void stringBool(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::string& true_, const std::string& false_, const std::size_t loop_num_) noexcept {
		if (loop_num_ == 0) return;
		for (std::size_t row{}; row < (y_*loop_num_); ++row) {
			for (std::size_t col{}; col < (x_*loop_num_); ++col) {
				if (matrix_[row / loop_num_ * x_ + col / loop_num_]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << '\n';
		}
	}

} //namespace

//範囲forデータ
namespace dtl::console::output::rangeBasedFor {

	template<typename Matrix_>
	constexpr void stringBool(const Matrix_& matrix_, const std::string& true_, const std::string& false_) noexcept {
		for (const auto& row : matrix_) {
			for (const auto& col : row) {
				if (col) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << '\n';
		}
	}

} //namespace

//レイヤーSTLデータ
namespace dtl::console::output::layer::stl {

	template<typename Matrix_>
	constexpr void stringBool(const Matrix_& matrix_, const std::size_t layer_, const std::string& true_, const std::string& false_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (matrix_[row][col][layer_]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << '\n';
		}
	}

	template<typename Matrix_>
	constexpr void stringBool(const Matrix_& matrix_, const std::size_t layer_, const std::string& true_, const std::string& false_, const std::size_t loop_num_) noexcept {
		if (loop_num_ == 0) return;
		for (std::size_t row{}; row < (matrix_.size()*loop_num_); ++row) {
			for (std::size_t col{}; col < (matrix_[row].size()*loop_num_); ++col) {
				if (matrix_[row / loop_num_][col / loop_num_][layer_]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << '\n';
		}
	}

} //namespace

//レイヤー通常データ
namespace dtl::console::output::layer::normal {

	template<typename Matrix_>
	constexpr void stringBool(const Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const std::string& true_, const std::string& false_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col) {
				if (matrix_[row][col][layer_]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << '\n';
		}
	}

	template<typename Matrix_>
	constexpr void stringBool(const Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const std::string& true_, const std::string& false_, const std::size_t loop_num_) noexcept {
		if (loop_num_ == 0) return;
		for (std::size_t row{}; row < (y_*loop_num_); ++row) {
			for (std::size_t col{}; col < (x_*loop_num_); ++col) {
				if (matrix_[row / loop_num_][col / loop_num_][layer_]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << '\n';
		}
	}

} //namespace

#endif //Included Dungeon Template Library