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

namespace dtl::utility {

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
		constexpr inline void substitutionSTL(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, Function_&& function_) const noexcept {
			(function_(matrix_[point_y_][point_x_])) ? matrix_[point_y_][point_x_] = true_value : matrix_[point_y_][point_x_] = false_value;
		}
		template<typename Matrix_, typename Function_>
		constexpr inline void substitutionArray(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Function_&& function_) const noexcept {
			(function_(matrix_[point_y_ * max_x_ + point_x_])) ? matrix_[point_y_ * max_x_ + point_x_] = true_value : matrix_[point_y_ * max_x_ + point_x_] = false_value;
		}
		template<typename Matrix_, typename Function_>
		constexpr inline void substitutionLayer(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Function_&& function_) const noexcept {
			(function_(matrix_[point_y_][point_x_][layer_])) ? matrix_[point_y_][point_x_][layer_] = true_value : matrix_[point_y_][point_x_][layer_] = false_value;
		}


		///// 基本処理 /////

		//STL
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawSTL(Matrix_&& matrix_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < matrix_[row].size(); ++col)
					this->substitutionSTL(matrix_, col, row, args_...);
			return true;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawWidthSTL(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < matrix_[row].size() && col < point_x_; ++col)
					this->substitutionSTL(matrix_, col, row, args_...);
			return true;
		}

		//LayerSTL
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawLayerSTL(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < matrix_[row].size(); ++col)
					this->substitutionLayer(matrix_, layer_, col, row, args_...);
			return true;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawLayerWidthSTL(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < matrix_[row].size() && col < point_x_; ++col)
					this->substitutionLayer(matrix_, layer_, col, row, args_...);
			return true;
		}

		//Normal
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawNormal(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < point_x_; ++col)
					this->substitutionSTL(matrix_, col, row, args_...);
			return true;
		}

		//LayerNormal
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawLayerNormal(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < point_x_; ++col)
					this->substitutionLayer(matrix_, layer_, col, row, args_...);
			return true;
		}

		//Array
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawArray(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Args_&&... args_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < point_x_; ++col)
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
			return this->true_value;
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
	using BinarizationU8 = dtl::utility::Binarization<std::uint_fast8_t>;
	using BinarizationU16 = dtl::utility::Binarization<std::uint_fast16_t>;
	using BinarizationU32 = dtl::utility::Binarization<std::uint_fast32_t>;
	using BinarizationU64 = dtl::utility::Binarization<std::uint_fast64_t>;
	using BinarizationI8 = dtl::utility::Binarization<std::int_fast8_t>;
	using BinarizationI16 = dtl::utility::Binarization<std::int_fast16_t>;
	using BinarizationI32 = dtl::utility::Binarization<std::int_fast32_t>;
	using BinarizationI64 = dtl::utility::Binarization<std::int_fast64_t>;
}





//STLデータ
namespace dtl::utility::stl {

	//2値化処理
	template<typename Matrix_>
	[[deprecated("please use dtl::utility::Binarization class")]] constexpr void binarization(Matrix_& matrix_) noexcept {
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
	[[deprecated("please use dtl::utility::Binarization class")]] constexpr void binarization(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
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
	[[deprecated("please use dtl::utility::Binarization class")]] constexpr void binarization(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
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
	[[deprecated("please use dtl::utility::Binarization class")]] constexpr void binarization(Matrix_& matrix_) noexcept {
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
	[[deprecated("please use dtl::utility::Binarization class")]] constexpr void binarization(Matrix_& matrix_, const std::size_t layer_) noexcept {
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
	[[deprecated("please use dtl::utility::Binarization class")]] constexpr void binarization(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col) {
				if (matrix_[row][col][layer_]) matrix_[row][col][layer_] = 1;
				else matrix_[row][col][layer_] = 0;
			}
	}

} //namespace

#endif //Included Dungeon Template Library