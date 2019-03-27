/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_BINARIZATION
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_BINARIZATION

#include <cstddef>
#include <cstdint>
#include <utility>

namespace dtl::shape {

	//マスを指定した数値で埋める
	template<typename Matrix_Int_>
	class Binarization {
	private:


		///// エイリアス /////

		using Index_Size = std::size_t;
		using PairSize = std::pair<Index_Size, Index_Size>;
		using PairMatrixInt = std::pair<Matrix_Int_, Matrix_Int_>;


		///// メンバ変数 /////

		Index_Size point_x{};
		Index_Size point_y{};
		Index_Size width{};
		Index_Size height{};
		Matrix_Int_ true_value{};
		Matrix_Int_ false_value{};


		///// 代入処理 /////

		template<typename Matrix_>
		constexpr inline void substitutionSTL(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			(matrix_[point_y_][point_x_]) ? matrix_[point_y_][point_x_] = true_value : matrix_[point_y_][point_x_] = false_value;
		}
		template<typename Matrix_>
		constexpr inline void substitutionArray(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
			(matrix_[point_y_ * max_x_ + point_x_]) ? matrix_[point_y_ * max_x_ + point_x_] = true_value : matrix_[point_y_ * max_x_ + point_x_] = false_value;
		}
		template<typename Matrix_>
		constexpr inline void substitutionLayer(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			(matrix_[point_y_][point_x_][layer_]) ? matrix_[point_y_][point_x_][layer_] = true_value : matrix_[point_y_][point_x_][layer_] = false_value;
		}

		template<typename Matrix_, typename Function_>
		constexpr inline void substitutionSTL(Function_&& function_,Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			(function_(matrix_[point_y_][point_x_])) ? matrix_[point_y_][point_x_] = true_value : matrix_[point_y_][point_x_] = false_value;
		}
		template<typename Matrix_, typename Function_>
		constexpr inline void substitutionArray(Function_&& function_,Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
			(function_(matrix_[point_y_ * max_x_ + point_x_])) ? matrix_[point_y_ * max_x_ + point_x_] = true_value : matrix_[point_y_ * max_x_ + point_x_] = false_value;
		}
		template<typename Matrix_, typename Function_>
		constexpr inline void substitutionLayer(Function_&& function_, Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			(function_(matrix_[point_y_][point_x_][layer_])) ? matrix_[point_y_][point_x_][layer_] = true_value : matrix_[point_y_][point_x_][layer_] = false_value;
		}


		///// 基本処理 /////

		//STL
		template<typename Matrix_>
		constexpr bool drawSTL(Matrix_&& matrix_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < matrix_[row].size(); ++col)
					this->substitutionSTL(matrix_, col, row);
			return true;
		}
		template<typename Matrix_>
		constexpr bool drawWidthSTL(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < matrix_[row].size() && col < point_x_; ++col)
					this->substitutionSTL(matrix_, col, row);
			return true;
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawSTL(Function_&& function_, Matrix_&& matrix_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < matrix_[row].size(); ++col)
					this->substitutionSTL(function_, matrix_, col, row);
			return true;
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawWidthSTL(Function_&& function_, Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < matrix_[row].size() && col < point_x_; ++col)
					this->substitutionSTL(function_, matrix_, col, row);
			return true;
		}

		//LayerSTL
		template<typename Matrix_>
		constexpr bool drawLayerSTL(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < matrix_[row].size(); ++col)
					this->substitutionLayer(matrix_, layer_, col, row);
			return true;
		}
		template<typename Matrix_>
		constexpr bool drawLayerWidthSTL(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < matrix_[row].size() && col < point_x_; ++col)
					this->substitutionLayer(matrix_, layer_, col, row);
			return true;
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawLayerSTL(Function_&& function_, Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < matrix_[row].size(); ++col)
					this->substitutionLayer(function_, matrix_, layer_, col, row);
			return true;
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawLayerWidthSTL(Function_&& function_, Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < matrix_[row].size() && col < point_x_; ++col)
					this->substitutionLayer(function_, matrix_, layer_, col, row);
			return true;
		}

		//Normal
		template<typename Matrix_>
		constexpr bool drawNormal(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < point_x_; ++col)
					this->substitutionSTL(matrix_, col, row);
			return true;
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawNormal(Function_&& function_, Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < point_x_; ++col)
					this->substitutionSTL(function_, matrix_, col, row);
			return true;
		}

		//LayerNormal
		template<typename Matrix_>
		constexpr bool drawLayerNormal(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < point_x_; ++col)
					this->substitutionLayer(matrix_, layer_, col, row);
			return true;
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawLayerNormal(Function_&& function_, Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < point_x_; ++col)
					this->substitutionLayer(function_, matrix_, layer_, col, row);
			return true;
		}

		//Array
		template<typename Matrix_>
		constexpr bool drawArray(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < point_x_; ++col)
					this->substitutionArray(matrix_, col, row, max_x_);
			return true;
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawArray(Function_&& function_, Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < point_x_; ++col)
					this->substitutionArray(function_, matrix_, col, row, max_x_);
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
			return this->true_value;
		}


		///// 生成呼び出し /////

		//STL
		template<typename Matrix_>
		constexpr bool draw(Matrix_&& matrix_) const noexcept {
			return (width == 0) ? this->drawSTL(matrix_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height) : this->drawWidthSTL(matrix_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool draw(Matrix_&& matrix_, Function_&& function_) const noexcept {
			return (width == 0) ? this->drawSTL(function_,matrix_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height) : this->drawWidthSTL(function_,matrix_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height);
		}

		//LayerSTL
		template<typename Matrix_>
		constexpr bool draw(Matrix_&& matrix_, const Index_Size layer_) const noexcept {
			return (width == 0) ? this->drawLayerSTL(matrix_, layer_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height) : this->drawLayerWidthSTL(matrix_, layer_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool draw(Matrix_&& matrix_, const Index_Size layer_, Function_&& function_) const noexcept {
			return (width == 0) ? this->drawLayerSTL(function_,matrix_, layer_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height) : this->drawLayerWidthSTL(function_,matrix_, layer_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height);
		}

		//Normal
		template<typename Matrix_>
		constexpr bool draw(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawNormal(matrix_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool draw(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_&& function_) const noexcept {
			return this->drawNormal(function_,matrix_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height);
		}

		//LayerNormal
		template<typename Matrix_>
		constexpr bool draw(Matrix_&& matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawLayerNormal(matrix_, layer_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool draw(Matrix_&& matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_&& function_) const noexcept {
			return this->drawLayerNormal(function_,matrix_, layer_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height);
		}

		//Array
		template<typename Matrix_>
		constexpr bool drawArray(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawArray(matrix_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, max_x_);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawArray(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_&& function_) const noexcept {
			return this->drawArray(function_,matrix_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, max_x_);
		}

		///// ダンジョン行列生成 /////

		//STL
		template<typename Matrix_>
		constexpr auto create(Matrix_&& matrix_) const noexcept {
			this->draw(matrix_);
			return matrix_;
		}
		template<typename Matrix_>
		constexpr auto create(Matrix_&& matrix_, bool& return_value_) const noexcept {
			return_value_ = this->draw(matrix_);
			return matrix_;
		}
		template<typename Matrix_, typename Function_>
		constexpr auto create(Matrix_&& matrix_, Function_&& function_) const noexcept {
			this->draw(matrix_, function_);
			return matrix_;
		}
		template<typename Matrix_, typename Function_>
		constexpr auto create(Matrix_&& matrix_, bool& return_value_, Function_&& function_) const noexcept {
			return_value_ = this->draw(matrix_, function_);
			return matrix_;
		}

		//LayerSTL
		template<typename Matrix_>
		constexpr auto create(Matrix_&& matrix_, const Index_Size layer_) const noexcept {
			this->draw(matrix_, layer_);
			return matrix_;
		}
		template<typename Matrix_>
		constexpr auto create(Matrix_&& matrix_, const Index_Size layer_, bool& return_value_) const noexcept {
			return_value_ = this->draw(matrix_, layer_);
			return matrix_;
		}
		template<typename Matrix_, typename Function_>
		constexpr auto create(Matrix_&& matrix_, const Index_Size layer_, Function_&& function_) const noexcept {
			this->draw(matrix_, layer_, function_);
			return matrix_;
		}
		template<typename Matrix_, typename Function_>
		constexpr auto create(Matrix_&& matrix_, const Index_Size layer_, bool& return_value_, Function_&& function_) const noexcept {
			return_value_ = this->draw(matrix_, layer_, function_);
			return matrix_;
		}

		//Normal
		template<typename Matrix_>
		constexpr auto create(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			this->draw(matrix_, max_x_, max_y_);
			return matrix_;
		}
		template<typename Matrix_>
		constexpr auto create(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_, bool& return_value_) const noexcept {
			return_value_ = this->draw(matrix_, max_x_, max_y_);
			return matrix_;
		}
		template<typename Matrix_, typename Function_>
		constexpr auto create(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_&& function_) const noexcept {
			this->draw(matrix_, max_x_, max_y_, function_);
			return matrix_;
		}
		template<typename Matrix_, typename Function_>
		constexpr auto create(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_, bool& return_value_, Function_&& function_) const noexcept {
			return_value_ = this->draw(matrix_, max_x_, max_y_, function_);
			return matrix_;
		}

		//LayerNormal
		template<typename Matrix_>
		constexpr auto create(Matrix_&& matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			this->draw(matrix_, layer_, max_x_, max_y_);
			return matrix_;
		}
		template<typename Matrix_>
		constexpr auto create(Matrix_&& matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, bool& return_value_) const noexcept {
			return_value_ = this->draw(matrix_, layer_, max_x_, max_y_);
			return matrix_;
		}
		template<typename Matrix_, typename Function_>
		constexpr auto create(Matrix_&& matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_&& function_) const noexcept {
			this->draw(matrix_, layer_, max_x_, max_y_, function_);
			return matrix_;
		}
		template<typename Matrix_, typename Function_>
		constexpr auto create(Matrix_&& matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, bool& return_value_, Function_&& function_) const noexcept {
			return_value_ = this->draw(matrix_, layer_, max_x_, max_y_, function_);
			return matrix_;
		}

		//Array
		template<typename Matrix_>
		constexpr auto createArray(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			this->drawArray(matrix_, max_x_, max_y_);
			return matrix_;
		}
		template<typename Matrix_>
		constexpr auto createArray(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_, bool& return_value_) const noexcept {
			return_value_ = this->drawArray(matrix_, max_x_, max_y_);
			return matrix_;
		}
		template<typename Matrix_, typename Function_>
		constexpr auto createArray(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_&& function_) const noexcept {
			this->drawArray(matrix_, max_x_, max_y_, function_);
			return matrix_;
		}
		template<typename Matrix_, typename Function_>
		constexpr auto createArray(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_, bool& return_value_, Function_&& function_) const noexcept {
			return_value_ = this->drawArray(matrix_, max_x_, max_y_, function_);
			return matrix_;
		}


		///// コンストラクタ /////

		constexpr Binarization() noexcept = default;
		constexpr explicit Binarization(const Matrix_Int_& true_value_) noexcept
			:true_value(true_value_) {}
		constexpr explicit Binarization(const PairMatrixInt& pair_matrix_) noexcept
			:true_value(pair_matrix_.first), false_value(pair_matrix_.second) {}
		constexpr explicit Binarization(const PairSize& length_) noexcept
			:width(length_.first), height(length_.second) {}
		constexpr explicit Binarization(const PairSize& length_, const Matrix_Int_& true_value_) noexcept
			:width(length_.first), height(length_.second),
			true_value(true_value_) {}
		constexpr explicit Binarization(const PairSize& length_, const PairMatrixInt& pair_matrix_) noexcept
			:width(length_.first), height(length_.second),
			true_value(pair_matrix_.first), false_value(pair_matrix_.second) {}
		constexpr explicit Binarization(const PairSize& position_, const PairSize& length_) noexcept
			:point_x(position_.first), point_y(position_.second),
			width(length_.first), height(length_.second) {}
		constexpr explicit Binarization(const PairSize& position_, const PairSize& length_, const Matrix_Int_& true_value_) noexcept
			:point_x(position_.first), point_y(position_.second),
			width(length_.first), height(length_.second),
			true_value(true_value_) {}
		constexpr explicit Binarization(const PairSize& position_, const PairSize& length_, const PairMatrixInt& pair_matrix_) noexcept
			:point_x(position_.first), point_y(position_.second),
			width(length_.first), height(length_.second),
			true_value(pair_matrix_.first), false_value(pair_matrix_.second) {}
		//constexpr explicit Binarization(const Index_Size width_, const Index_Size height_) noexcept
		//	:width(width_), height(height_) {}
		constexpr explicit Binarization(const Matrix_Int_& true_value_, const Matrix_Int_& false_value_) noexcept
			:true_value(true_value_), false_value(false_value_) {}
		constexpr explicit Binarization(const Index_Size width_, const Index_Size height_, const Matrix_Int_& true_value_) noexcept
			:width(width_), height(height_),
			true_value(true_value_) {}
		constexpr explicit Binarization(const Index_Size width_, const Index_Size height_, const PairMatrixInt& pair_matrix_) noexcept
			:width(width_), height(height_),
			true_value(pair_matrix_.first), false_value(pair_matrix_.second) {}
		constexpr explicit Binarization(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
			:point_x(point_x_), point_y(point_y_),
			width(width_), height(height_) {}
		constexpr explicit Binarization(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_& true_value_) noexcept
			:point_x(point_x_), point_y(point_y_),
			width(width_), height(height_),
			true_value(true_value_) {}
		constexpr explicit Binarization(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const PairMatrixInt& pair_matrix_) noexcept
			:point_x(point_x_), point_y(point_y_),
			width(width_), height(height_),
			true_value(pair_matrix_.first), false_value(pair_matrix_.second) {}
	};
	using BinarizationU8 = dtl::shape::Binarization<std::uint_fast8_t>;
	using BinarizationU16 = dtl::shape::Binarization<std::uint_fast16_t>;
	using BinarizationU32 = dtl::shape::Binarization<std::uint_fast32_t>;
	using BinarizationU64 = dtl::shape::Binarization<std::uint_fast64_t>;
	using BinarizationI8 = dtl::shape::Binarization<std::int_fast8_t>;
	using BinarizationI16 = dtl::shape::Binarization<std::int_fast16_t>;
	using BinarizationI32 = dtl::shape::Binarization<std::int_fast32_t>;
	using BinarizationI64 = dtl::shape::Binarization<std::int_fast64_t>;
}





//STLデータ
namespace dtl::utility::stl {

	//2値化処理
	template<typename Matrix_>
	constexpr void binarization(Matrix_& matrix_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (matrix_[row][col]) matrix_[row][col] = 1;
				else matrix_[row][col] = 0;
			}
	}

} //namespace

//通常データ
namespace dtl::utility::normal {

	//2値化処理
	template<typename Matrix_>
	constexpr void binarization(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col) {
				if (matrix_[row][col]) matrix_[row][col] = 1;
				else matrix_[row][col] = 0;
			}
	}

} //namespace

//配列データ
namespace dtl::utility::array {

	//2値化処理
	template<typename Matrix_>
	constexpr void binarization(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col) {
				if (matrix_[row*x_ + col]) matrix_[row*x_ + col] = 1;
				else matrix_[row*x_ + col] = 0;
			}
	}

} //namespace

//範囲forデータ
namespace dtl::utility::rangeBasedFor {

	//2値化処理
	template<typename Matrix_>
	constexpr void binarization(Matrix_& matrix_) noexcept {
		for (auto&& row : matrix_)
			for (auto&& col : row) {
				if (col) col = 1;
				else col = 0;
			}
	}

} //namespace

//レイヤーSTLデータ
namespace dtl::utility::layer::stl {

	//2値化処理
	template<typename Matrix_>
	constexpr void binarization(Matrix_& matrix_, const std::size_t layer_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (matrix_[row][col][layer_]) matrix_[row][col][layer_] = 1;
				else matrix_[row][col][layer_] = 0;
			}
	}

} //namespace

//レイヤー通常データ
namespace dtl::utility::layer::normal {

	//2値化処理
	template<typename Matrix_>
	constexpr void binarization(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col) {
				if (matrix_[row][col][layer_]) matrix_[row][col][layer_] = 1;
				else matrix_[row][col][layer_] = 0;
			}
	}

} //namespace

#endif //Included Dungeon Template Library