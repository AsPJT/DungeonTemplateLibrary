/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_OUTPUT_STRING
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_OUTPUT_STRING

/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <iostream>
#include <vector>
#include <string>

namespace dtl::console {

	//四角形の生成
	template<typename Matrix_Int_, typename OutputStringName_ = std::string>
	class OutputString {
	private:


		///// エイリアス /////

		using Index_Size = std::size_t;
		using PairSize = std::pair<Index_Size, Index_Size>;


		///// メンバ変数 /////

		Index_Size point_x{};
		Index_Size point_y{};
		Index_Size width{};
		Index_Size height{};
		std::vector<OutputStringName_> string_vector{};


		//

		constexpr void string_String() const noexcept {}
		template<typename ...Args_>
		constexpr void string_String(const OutputStringName_& first_, const Args_&... args_) noexcept {
			string_vector.emplace_back(first_);
			this->string_String(args_...);
		}


		///// 代入処理 /////

		template<typename Matrix_>
		[[nodiscard]] constexpr inline std::size_t outputSTL(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			return static_cast<std::size_t>(matrix_[point_y_][point_x_]);
		}
		template<typename Matrix_>
		[[nodiscard]] constexpr inline std::size_t outputArray(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
			return static_cast<std::size_t>(matrix_[point_y_ * max_x_ + point_x_]);
		}
		template<typename Matrix_>
		[[nodiscard]] constexpr inline std::size_t outputLayer(const Matrix_& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			return static_cast<std::size_t>(matrix_[point_y_][point_x_][layer_]);
		}


		///// 基本処理 /////

		//STL
		template<typename Matrix_>
		bool drawSTL(const Matrix_& matrix_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				for (Index_Size col{ point_x }; col < matrix_[row].size(); ++col) {
					if (this->outputSTL(matrix_, col, row) >= string_vector.size()) continue;
					std::cout << string_vector[this->outputSTL(matrix_, col, row)];
				}
				std::cout << '\n';
			}
			return true;
		}
		template<typename Matrix_>
		bool drawWidthSTL(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				for (Index_Size col{ point_x }; col < matrix_[row].size() && col < point_x_; ++col) {
					if (this->outputSTL(matrix_, col, row) >= string_vector.size()) continue;
					std::cout << string_vector[this->outputSTL(matrix_, col, row)];
				}
				std::cout << '\n';
			}
			return true;
		}

		//LayerSTL
		template<typename Matrix_>
		bool drawLayerSTL(const Matrix_& matrix_, const Index_Size layer_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				for (Index_Size col{ point_x }; col < matrix_[row].size(); ++col) {
					if (this->outputLayer(matrix_, layer_, col, row) >= string_vector.size()) continue;
					std::cout << string_vector[this->outputLayer(matrix_, layer_, col, row)];
				}
				std::cout << '\n';
			}
			return true;
		}
		template<typename Matrix_>
		bool drawLayerWidthSTL(const Matrix_& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				for (Index_Size col{ point_x }; col < matrix_[row].size() && col < point_x_; ++col) {
					if (this->outputLayer(matrix_, layer_, col, row) >= string_vector.size()) continue;
					std::cout << string_vector[this->outputLayer(matrix_, layer_, col, row)];
				}
				std::cout << '\n';
			}
			return true;
		}

		//Normal
		template<typename Matrix_>
		bool drawNormal(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				for (Index_Size col{ point_x }; col < point_x_; ++col) {
					if (this->outputSTL(matrix_, col, row) >= string_vector.size()) continue;
					std::cout << string_vector[this->outputSTL(matrix_, col, row)];
				}
				std::cout << '\n';
			}
			return true;
		}

		//LayerNormal
		template<typename Matrix_>
		bool drawLayerNormal(const Matrix_& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				for (Index_Size col{ point_x }; col < point_x_; ++col) {
					if (this->outputLayer(matrix_, layer_, col, row) >= string_vector.size()) continue;
					std::cout << string_vector[this->outputLayer(matrix_, layer_, col, row)];
				}
				std::cout << '\n';
			}
			return true;
		}

		//Array
		template<typename Matrix_>
		bool drawArray(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				for (Index_Size col{ point_x }; col < point_x_; ++col) {
					if (this->outputArray(matrix_, col, row, max_x_) >= string_vector.size()) continue;
					std::cout << string_vector[this->outputArray(matrix_, col, row, max_x_)];
				}
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

		template<typename ...Args_>
		explicit OutputString(const OutputStringName_& first_, const Args_&... args_) noexcept {
			this->string_String(first_, args_...);
		}
		template<typename ...Args_>
		explicit OutputString(const PairSize& length_, const OutputStringName_& first_, const Args_&... args_) noexcept
			:width(length_.first), height(length_.second) {
			this->string_String(first_, args_...);
		}
		template<typename ...Args_>
		explicit OutputString(const PairSize& position_, const PairSize& length_, const OutputStringName_& first_, const Args_&... args_) noexcept
			:point_x(position_.first), point_y(position_.second),
			width(length_.first), height(length_.second) {
			this->string_String(first_, args_...);
		}
		template<typename ...Args_>
		explicit OutputString(const Index_Size width_, const Index_Size height_, const OutputStringName_& first_, const Args_&... args_) noexcept
			:width(width_), height(height_) {
			this->string_String(first_, args_...);
		}
		template<typename ...Args_>
		explicit OutputString(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const OutputStringName_& first_, const Args_&... args_) noexcept
			:point_x(point_x_), point_y(point_y_),
			width(width_), height(height_) {
			this->string_String(first_, args_...);
		}
	};
	template<typename Matrix_Int_>
	using OutputStringS16 = OutputString<Matrix_Int_, std::u16string>;
	template<typename Matrix_Int_>
	using OutputStringS32 = OutputString<Matrix_Int_, std::u32string>;
}





//隠ぺいデータ
namespace dtl::console::output::hiding {

	constexpr void string_String([[maybe_unused]] const std::vector<std::string>&) noexcept {}

	template<typename ...Args_>
	constexpr void string_String(std::vector<std::string>& string_vector_, const std::string& first_, const Args_&... args_) noexcept {
		string_vector_.emplace_back(std::move(first_));
		string_String(string_vector_, args_...);
	}
	template<typename ...Args_>
	void string_Split(std::vector<std::string>& string_vector_, const Args_&... args_) noexcept {
		string_String(string_vector_, args_...);
	}

} //namespace

//STLデータ
namespace dtl::console::output::stl {

	template<typename Matrix_, typename ...Args_>
	void string(const Matrix_& matrix_, const Args_&... args_) noexcept {

		using dtl::console::output::hiding::string_Split;

		std::vector<std::string> string_vector;
		string_Split(string_vector, args_...);

		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (static_cast<std::size_t>(matrix_[row][col]) >= string_vector.size()) continue;
				std::cout << string_vector[static_cast<std::size_t>(matrix_[row][col])];
			}
			std::cout << '\n';
		}
	}

} //namespace

//通常データ
namespace dtl::console::output::normal {

	template<typename Matrix_, typename ...Args_>
	void string(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Args_&... args_) noexcept {

		using dtl::console::output::hiding::string_Split;

		std::vector<std::string> string_vector;
		string_Split(string_vector, args_...);

		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col) {
				if (static_cast<std::size_t>(matrix_[row][col]) >= string_vector.size()) continue;
				std::cout << string_vector[static_cast<std::size_t>(matrix_[row][col])];
			}
			std::cout << '\n';
		}
	}

} //namespace

//配列データ
namespace dtl::console::output::array {

	template<typename Matrix_, typename ...Args_>
	void string(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Args_&... args_) noexcept {

		using dtl::console::output::hiding::string_Split;

		std::vector<std::string> string_vector;
		string_Split(string_vector, args_...);

		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col) {
				if (static_cast<std::size_t>(matrix_[row*x_ + col]) >= string_vector.size()) continue;
				std::cout << string_vector[static_cast<std::size_t>(matrix_[row*x_ + col])];
			}
			std::cout << '\n';
		}
	}

} //namespace

//範囲forデータ
namespace dtl::console::output::rangeBasedFor {

	template<typename Matrix_, typename ...Args_>
	void string(const Matrix_& matrix_, const Args_&... args_) noexcept {

		using dtl::console::output::hiding::string_Split;

		std::vector<std::string> string_vector;
		string_Split(string_vector, args_...);

		for (const auto& row : matrix_) {
			for (const auto& col : row) {
				if (static_cast<std::size_t>(col) >= string_vector.size()) continue;
				std::cout << string_vector[static_cast<std::size_t>(col)];
			}
			std::cout << '\n';
		}
	}

} //namespace

//レイヤーSTLデータ
namespace dtl::console::output::layer::stl {

	template<typename Matrix_, typename ...Args_>
	void string(const Matrix_& matrix_, const std::size_t layer_, const Args_&... args_) noexcept {

		using dtl::console::output::hiding::string_Split;

		std::vector<std::string> string_vector;
		string_Split(string_vector, args_...);

		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (static_cast<std::size_t>(matrix_[row][col][layer_]) >= string_vector.size()) continue;
				std::cout << string_vector[static_cast<std::size_t>(matrix_[row][col][layer_])];
			}
			std::cout << '\n';
		}
	}

} //namespace

//レイヤー通常データ
namespace dtl::console::output::layer::normal {

	template<typename Matrix_, typename ...Args_>
	void string(const Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Args_&... args_) noexcept {

		using dtl::console::output::hiding::string_Split;

		std::vector<std::string> string_vector;
		string_Split(string_vector, args_...);

		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col) {
				if (static_cast<std::size_t>(matrix_[row][col][layer_]) >= string_vector.size()) continue;
				std::cout << string_vector[static_cast<std::size_t>(matrix_[row][col][layer_])];
			}
			std::cout << '\n';
		}
	}

} //namespace

#endif //Included Dungeon Template Library