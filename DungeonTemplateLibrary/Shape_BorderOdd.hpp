/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_BORDER_ODD
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_BORDER_ODD

/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>

namespace dtl::shape {

	//四角形の生成
	template<typename Matrix_Int_>
	class BorderOdd {
	private:


		///// エイリアス /////

		using Index_Size = std::size_t;
		using PairSize = std::pair<Index_Size, Index_Size>;


		///// メンバ変数 /////

		Index_Size point_x{};
		Index_Size point_y{};
		Index_Size width{};
		Index_Size height{};
		Matrix_Int_ draw_value{};


		///// 代入処理 /////

		template<typename Matrix_>
		constexpr inline void substitutionSTL(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			matrix_[point_y_][point_x_] = draw_value;
		}
		template<typename Matrix_>
		constexpr inline void substitutionArray(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
			matrix_[point_y_ * max_x_ + point_x_] = draw_value;
		}
		template<typename Matrix_>
		constexpr inline void substitutionLayer(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			matrix_[point_y_][point_x_][layer_] = draw_value;
		}

		template<typename Matrix_, typename Function_>
		constexpr inline void substitutionSTL(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, Function_&& function_) const noexcept {
			if (function_(matrix_[point_y_][point_x_])) matrix_[point_y_][point_x_] = draw_value;
		}
		template<typename Matrix_, typename Function_>
		constexpr inline void substitutionArray(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Function_&& function_) const noexcept {
			if (function_(matrix_[point_y_ * max_x_ + point_x_])) matrix_[point_y_ * max_x_ + point_x_] = draw_value;
		}
		template<typename Matrix_, typename Function_>
		constexpr inline void substitutionLayer(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Function_&& function_) const noexcept {
			if (function_(matrix_[point_y_][point_x_][layer_])) matrix_[point_y_][point_x_][layer_] = draw_value;
		}


		///// 基本処理 /////

		//STL
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawSTL(Matrix_&& matrix_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			if (point_y_ == 0) return true;
			for (Index_Size col{ point_x }; col < matrix_[point_y].size(); ++col)
				this->substitutionSTL(matrix_, col, point_y, std::forward<Args_>(args_)...);
			for (Index_Size col{ point_x }; col < matrix_[point_y_ - 1].size(); ++col) {
				if ((point_y_ - point_y) % 2 == 0) this->substitutionSTL(matrix_, col, point_y_ - 2, std::forward<Args_>(args_)...);
				this->substitutionSTL(matrix_, col, point_y_ - 1, std::forward<Args_>(args_)...);
			}
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				if (matrix_[row].size() == 0) continue;
				this->substitutionSTL(matrix_, point_x, row, std::forward<Args_>(args_)...);
				if ((matrix_[row].size() - point_x) % 2 == 0) this->substitutionSTL(matrix_, matrix_[row].size() - 2, row, std::forward<Args_>(args_)...);
				this->substitutionSTL(matrix_, matrix_[row].size() - 1, row, std::forward<Args_>(args_)...);
			}
			return true;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawWidthSTL(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			if (point_y_ < 2) return true;
			for (Index_Size col{ point_x }; col < point_x_&&col < matrix_[point_y].size(); ++col)
				this->substitutionSTL(matrix_, col, point_y, std::forward<Args_>(args_)...);
			for (Index_Size col{ point_x }; col < point_x_&&col < matrix_[point_y_ - 1].size(); ++col) {
				if ((point_y_ - point_y) % 2 == 0) this->substitutionSTL(matrix_, col, point_y_ - 2, std::forward<Args_>(args_)...);
				this->substitutionSTL(matrix_, col, point_y_ - 1, std::forward<Args_>(args_)...);
			}
			if (point_x_ < 2) return true;
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				if (matrix_[row].size() == 0) continue;
				this->substitutionSTL(matrix_, point_x, row, std::forward<Args_>(args_)...);
				if (matrix_[row].size() <= point_x_) {
					if ((matrix_[row].size() - point_x) % 2 == 0) this->substitutionSTL(matrix_, matrix_[row].size() - 2, row, std::forward<Args_>(args_)...);
					this->substitutionSTL(matrix_, matrix_[row].size() - 1, row, std::forward<Args_>(args_)...);
				}
				else {
					if ((point_x_ - point_x) % 2 == 0) this->substitutionSTL(matrix_, point_x_ - 2, row, std::forward<Args_>(args_)...);
					this->substitutionSTL(matrix_, point_x_ - 1, row, std::forward<Args_>(args_)...);
				}
			}
			return true;
		}

		//LayerSTL
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawLayerSTL(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			if (point_y_ < 2) return true;
			for (Index_Size col{ point_x }; col < matrix_[point_y].size(); ++col)
				this->substitutionLayer(matrix_, layer_, col, point_y, std::forward<Args_>(args_)...);
			for (Index_Size col{ point_x }; col < matrix_[point_y_ - 1].size(); ++col) {
				if ((point_y_ - point_y) % 2 == 0) this->substitutionLayer(matrix_, layer_, col, point_y_ - 2, std::forward<Args_>(args_)...);
				this->substitutionLayer(matrix_, layer_, col, point_y_ - 1, std::forward<Args_>(args_)...);
			}
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				if (matrix_[row].size() < 2) continue;
				this->substitutionLayer(matrix_, layer_, point_x, row, std::forward<Args_>(args_)...);
				if ((matrix_[row].size() - point_x) % 2 == 0) this->substitutionLayer(matrix_, layer_, matrix_[row].size() - 2, row, std::forward<Args_>(args_)...);
				this->substitutionLayer(matrix_, layer_, matrix_[row].size() - 1, row, std::forward<Args_>(args_)...);
			}
			return true;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawLayerWidthSTL(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			if (point_y_ < 2) return true;
			for (Index_Size col{ point_x }; col < point_x_&&col < matrix_[point_y].size(); ++col)
				this->substitutionLayer(matrix_, layer_, col, point_y, std::forward<Args_>(args_)...);
			for (Index_Size col{ point_x }; col < point_x_&&col < matrix_[point_y_ - 1].size(); ++col) {
				if ((point_y_ - point_y) % 2 == 0) this->substitutionLayer(matrix_, layer_, col, point_y_ - 2, std::forward<Args_>(args_)...);
				this->substitutionLayer(matrix_, layer_, col, point_y_ - 1, std::forward<Args_>(args_)...);
			}
			if (point_x_ < 2) return true;
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				if (matrix_[row].size() == 0) continue;
				this->substitutionLayer(matrix_, layer_, point_x, row, std::forward<Args_>(args_)...);
				if (matrix_[row].size() <= point_x_) {
					if ((matrix_[row].size() - point_x) % 2 == 0) this->substitutionLayer(matrix_, layer_, matrix_[row].size() - 2, row, std::forward<Args_>(args_)...);
					this->substitutionLayer(matrix_, layer_, matrix_[row].size() - 1, row, std::forward<Args_>(args_)...);
				}
				else {
					if ((point_x_ - point_x) % 2 == 0) this->substitutionLayer(matrix_, layer_, point_x_ - 2, row, std::forward<Args_>(args_)...);
					this->substitutionLayer(matrix_, layer_, point_x_ - 1, row, std::forward<Args_>(args_)...);
				}
			}
			return true;
		}

		//Normal
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawNormal(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			if (point_x_ < 2 || point_y_ < 2) return true;
			for (Index_Size col{ point_x }; col < point_x_; ++col) {
				this->substitutionSTL(matrix_, col, point_y, std::forward<Args_>(args_)...);
				if ((point_y_ - point_y) % 2 == 0) this->substitutionSTL(matrix_, col, point_y_ - 2, std::forward<Args_>(args_)...);
				this->substitutionSTL(matrix_, col, point_y_ - 1, std::forward<Args_>(args_)...);
			}
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				this->substitutionSTL(matrix_, point_x, row, std::forward<Args_>(args_)...);
				if ((point_x_ - point_x) % 2 == 0) this->substitutionSTL(matrix_, point_x_ - 2, row, std::forward<Args_>(args_)...);
				this->substitutionSTL(matrix_, point_x_ - 1, row, std::forward<Args_>(args_)...);
			}
			return true;
		}

		//LayerNormal
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawLayerNormal(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_&&... args_) const noexcept {
			if (point_x_ < 2 || point_y_ < 2) return true;
			for (Index_Size col{ point_x }; col < point_x_; ++col) {
				this->substitutionLayer(matrix_, layer_, col, point_y, std::forward<Args_>(args_)...);
				if ((point_y_ - point_y) % 2 == 0) this->substitutionLayer(matrix_, layer_, col, point_y_ - 2, std::forward<Args_>(args_)...);
				this->substitutionLayer(matrix_, layer_, col, point_y_ - 1, std::forward<Args_>(args_)...);
			}
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				this->substitutionLayer(matrix_, layer_, point_x, row, std::forward<Args_>(args_)...);
				if ((point_y_ - point_y) % 2 == 0) this->substitutionLayer(matrix_, layer_, point_x_ - 2, row, std::forward<Args_>(args_)...);
				this->substitutionLayer(matrix_, layer_, point_x_ - 1, row, std::forward<Args_>(args_)...);
			}
			return true;
		}

		//Array
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawArray(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Args_&&... args_) const noexcept {
			if (point_x_ < 2 || point_y_ < 2) return true;
			for (Index_Size col{ point_x }; col < point_x_; ++col) {
				this->substitutionArray(matrix_, col, point_y, max_x_, std::forward<Args_>(args_)...);
				if ((point_y_ - point_y) % 2 == 0) this->substitutionArray(matrix_, col, point_y_ - 2, max_x_, std::forward<Args_>(args_)...);
				this->substitutionArray(matrix_, col, point_y_ - 1, max_x_, std::forward<Args_>(args_)...);
			}
			for (Index_Size row{ point_y }; row < point_y_; ++row) {
				this->substitutionArray(matrix_, point_x, row, max_x_, std::forward<Args_>(args_)...);
				if ((point_y_ - point_y) % 2 == 0) this->substitutionArray(matrix_, point_x_ - 2, row, max_x_, std::forward<Args_>(args_)...);
				this->substitutionArray(matrix_, point_x_ - 1, row, max_x_, std::forward<Args_>(args_)...);
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
			return this->draw_value;
		}


		///// 生成呼び出し /////

		//STL
		template<typename Matrix_>
		constexpr bool draw(Matrix_&& matrix_) const noexcept {
			return (width == 0) ? this->drawSTL(matrix_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height) : this->drawWidthSTL(matrix_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperator(Matrix_&& matrix_, Function_&& function_) const noexcept {
			return (width == 0) ? this->drawSTL(matrix_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_) : this->drawWidthSTL(matrix_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_);
		}

		//LayerSTL
		template<typename Matrix_>
		constexpr bool draw(Matrix_&& matrix_, const Index_Size layer_) const noexcept {
			return (width == 0) ? this->drawLayerSTL(matrix_, layer_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height) : this->drawLayerWidthSTL(matrix_, layer_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperator(Matrix_&& matrix_, const Index_Size layer_, Function_&& function_) const noexcept {
			return (width == 0) ? this->drawLayerSTL(matrix_, layer_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_) : this->drawLayerWidthSTL(matrix_, layer_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_);
		}

		//Normal
		template<typename Matrix_>
		constexpr bool draw(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawNormal(matrix_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperator(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_&& function_) const noexcept {
			return this->drawNormal(matrix_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, function_);
		}

		//LayerNormal
		template<typename Matrix_>
		constexpr bool draw(Matrix_&& matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawLayerNormal(matrix_, layer_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperator(Matrix_&& matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_&& function_) const noexcept {
			return this->drawLayerNormal(matrix_, layer_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, function_);
		}

		//Array
		template<typename Matrix_>
		constexpr bool drawArray(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawArray(matrix_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, max_x_);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperatorArray(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_&& function_) const noexcept {
			return this->drawArray(matrix_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, max_x_, function_);
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

		constexpr BorderOdd() noexcept = default;
		constexpr explicit BorderOdd(const Matrix_Int_& draw_value_) noexcept
			:draw_value(draw_value_) {}
		constexpr explicit BorderOdd(const PairSize& length_) noexcept
			:width(length_.first), height(length_.second) {}
		constexpr explicit BorderOdd(const PairSize& length_, const Matrix_Int_& draw_value_) noexcept
			:width(length_.first), height(length_.second),
			draw_value(draw_value_) {}
		constexpr explicit BorderOdd(const PairSize& position_, const PairSize& length_) noexcept
			:point_x(position_.first), point_y(position_.second),
			width(length_.first), height(length_.second) {}
		constexpr explicit BorderOdd(const PairSize& position_, const PairSize& length_, const Matrix_Int_& draw_value_) noexcept
			:point_x(position_.first), point_y(position_.second),
			width(length_.first), height(length_.second),
			draw_value(draw_value_) {}
		constexpr explicit BorderOdd(const Index_Size width_, const Index_Size height_) noexcept
			:width(width_), height(height_) {}
		constexpr explicit BorderOdd(const Index_Size width_, const Index_Size height_, const Matrix_Int_& draw_value_) noexcept
			:width(width_), height(height_),
			draw_value(draw_value_) {}
		constexpr explicit BorderOdd(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
			:point_x(point_x_), point_y(point_y_),
			width(width_), height(height_) {}
		constexpr explicit BorderOdd(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_& draw_value_) noexcept
			:point_x(point_x_), point_y(point_y_),
			width(width_), height(height_),
			draw_value(draw_value_) {}
	};
	using BorderOddU8 = dtl::shape::BorderOdd<std::uint_fast8_t>;
	using BorderOddU16 = dtl::shape::BorderOdd<std::uint_fast16_t>;
	using BorderOddU32 = dtl::shape::BorderOdd<std::uint_fast32_t>;
	using BorderOddU64 = dtl::shape::BorderOdd<std::uint_fast64_t>;
	using BorderOddI8 = dtl::shape::BorderOdd<std::int_fast8_t>;
	using BorderOddI16 = dtl::shape::BorderOdd<std::int_fast16_t>;
	using BorderOddI32 = dtl::shape::BorderOdd<std::int_fast32_t>;
	using BorderOddI64 = dtl::shape::BorderOdd<std::int_fast64_t>;
}





//総合データ
namespace dtl::generator::common::data {

	enum eBorderOdd {
		border_odd_empty_id,
		border_odd_wall_id,
		border_odd_enum_num
	};
	constexpr bool border_odd_bool{ (border_odd_enum_num <= 2) ? true : false };

} //namespace

//STLデータ
namespace dtl::generator::common::stl {

	//マップの外枠を1で埋める(枠の内部を奇数マスにする)
	template<typename Matrix_>
	[[deprecated("please use dtl::shape::BorderOdd class")]] constexpr void createBorderOdd(Matrix_& matrix_) noexcept {
		if (matrix_.size() < 2) return;
		for (std::size_t col{}; col < matrix_[0].size(); ++col)
			matrix_[0][col] = 1;
		if (matrix_.size() % 2 == 1) {
			for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
				matrix_[matrix_.size() - 1][col] = 1;
		}
		else for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col) {
			matrix_[matrix_.size() - 2][col] = 1;
			matrix_[matrix_.size() - 1][col] = 1;
		}
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() < 2) continue;
			matrix_[row][0] = 1;
			if (matrix_[row].size() % 2 == 0) matrix_[row][matrix_[row].size() - 2] = 1;
			matrix_[row][matrix_[row].size() - 1] = 1;
		}
	}
	//マップの外枠を指定した数値で埋める(枠の内部を奇数マスにする)
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::shape::BorderOdd class")]] constexpr void createBorderOdd(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		if (matrix_.size() < 2) return;
		for (std::size_t col{}; col < matrix_[0].size(); ++col)
			matrix_[0][col] = value_;
		if (matrix_.size() % 2 == 1) {
			for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
				matrix_[matrix_.size() - 1][col] = value_;
		}
		else for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col) {
			matrix_[matrix_.size() - 2][col] = value_;
			matrix_[matrix_.size() - 1][col] = value_;
		}
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() < 2) continue;
			matrix_[row][0] = value_;
			if (matrix_[row].size() % 2 == 0) matrix_[row][matrix_[row].size() - 2] = value_;
			matrix_[row][matrix_[row].size() - 1] = value_;
		}
	}
	//クラス版
	template<typename Matrix_Int_>
	class BorderOdd {
	public:
		//コンストラクタ
		[[deprecated("please use dtl::shape::BorderOdd class")]] constexpr BorderOdd() noexcept = default;
		template<typename Matrix_>
		constexpr explicit BorderOdd(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, value_);
		}
		template<typename Matrix_>
		[[deprecated("please use dtl::shape::BorderOdd class")]] constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::stl::createBorderOdd(matrix_, value_);
		}
	};

} //namespace

//通常データ
namespace dtl::generator::common::normal {

	//マップの外枠を1で埋める(枠の内部を奇数マスにする)
	template<typename Matrix_>
	[[deprecated("please use dtl::shape::BorderOdd class")]] constexpr void createBorderOdd(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (y_ < 2) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[0][col] = 1;
		if (y_ % 2 == 1) {
			for (std::size_t col{}; col < x_; ++col)
				matrix_[y_ - 1][col] = 1;
		}
		else for (std::size_t col{}; col < x_; ++col) {
			matrix_[y_ - 2][col] = 1;
			matrix_[y_ - 1][col] = 1;
		}
		if (x_ < 2) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row][0] = 1;
			if (x_ % 2 == 0) matrix_[row][x_ - 2] = 1;
			matrix_[row][x_ - 1] = 1;
		}
	}
	//マップの外枠を指定した数値で埋める(枠の内部を奇数マスにする)
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::shape::BorderOdd class")]] constexpr void createBorderOdd(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (y_ < 2) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[0][col] = value_;
		if (y_ % 2 == 1) {
			for (std::size_t col{}; col < x_; ++col)
				matrix_[y_ - 1][col] = value_;
		}
		else for (std::size_t col{}; col < x_; ++col) {
			matrix_[y_ - 2][col] = value_;
			matrix_[y_ - 1][col] = value_;
		}
		if (x_ < 2) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row][0] = value_;
			if (x_ % 2 == 0) matrix_[row][x_ - 2] = value_;
			matrix_[row][x_ - 1] = value_;
		}
	}
	//クラス版
	template<typename Matrix_Int_>
	class BorderOdd {
	public:
		//コンストラクタ
		[[deprecated("please use dtl::shape::BorderOdd class")]] constexpr BorderOdd() noexcept = default;
		template<typename Matrix_>
		constexpr explicit BorderOdd(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		[[deprecated("please use dtl::shape::BorderOdd class")]] constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::normal::createBorderOdd(matrix_, x_, y_, value_);
		}
	};

} //namespace

//配列データ
namespace dtl::generator::common::array {

	//マップの外枠を1で埋める(枠の内部を奇数マスにする)
	template<typename Matrix_>
	[[deprecated("please use dtl::shape::BorderOdd class")]] constexpr void createBorderOdd(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (y_ < 2) return;
		for (std::size_t row{}; row < x_; ++row)
			matrix_[row] = 1;
		if (y_ % 2 == 1) {
			for (std::size_t row{}; row < x_; ++row)
				matrix_[(y_ - 1) * x_ + row] = 1;
		}
		else for (std::size_t row{}; row < x_; ++row) {
			matrix_[(y_ - 2) * x_ + row] = 1;
			matrix_[(y_ - 1) * x_ + row] = 1;
		}
		if (x_ < 2) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row*x_] = 1;
			if (x_ % 2 == 0) matrix_[row*x_ + x_ - 2] = 1;
			matrix_[row*x_ + x_ - 1] = 1;
		}
	}
	//マップの外枠を指定した数値で埋める(枠の内部を奇数マスにする)
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::shape::BorderOdd class")]] constexpr void createBorderOdd(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (y_ < 2) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[col] = value_;
		if (y_ % 2 == 1) {
			for (std::size_t col{}; col < x_; ++col)
				matrix_[(y_ - 1) * x_ + col] = value_;
		}
		else for (std::size_t col{}; col < x_; ++col) {
			matrix_[(y_ - 2) * x_ + col] = value_;
			matrix_[(y_ - 1) * x_ + col] = value_;
		}
		if (x_ < 2) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row*x_] = value_;
			if (x_ % 2 == 0) matrix_[row*x_ + x_ - 2] = value_;
			matrix_[row*x_ + x_ - 1] = value_;
		}
	}
	template<typename Matrix_Int_>
	class BorderOdd {
	public:
		//コンストラクタ
		[[deprecated("please use dtl::shape::BorderOdd class")]] constexpr BorderOdd() noexcept = default;
		template<typename Matrix_>
		constexpr explicit BorderOdd(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		[[deprecated("please use dtl::shape::BorderOdd class")]] constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::array::createBorderOdd(matrix_, x_, y_, value_);
		}
	};

} //namespace

//レイヤーSTLデータ
namespace dtl::generator::common::layer::stl {

	//マップの外枠を1で埋める(枠の内部を奇数マスにする)
	template<typename Matrix_>
	[[deprecated("please use dtl::shape::BorderOdd class")]] constexpr void createBorderOdd(Matrix_& matrix_, const std::size_t layer_) noexcept {
		if (matrix_.size() < 2) return;
		for (std::size_t col{}; col < matrix_[0].size(); ++col)
			matrix_[0][col][layer_] = 1;
		if (matrix_.size() % 2 == 1) {
			for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
				matrix_[matrix_.size() - 1][col][layer_] = 1;
		}
		else for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col) {
			matrix_[matrix_.size() - 2][col][layer_] = 1;
			matrix_[matrix_.size() - 1][col][layer_] = 1;
		}
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() < 2) continue;
			matrix_[row][0][layer_] = 1;
			if (matrix_[row].size() % 2 == 0) matrix_[row][matrix_[row].size() - 2][layer_] = 1;
			matrix_[row][matrix_[row].size() - 1][layer_] = 1;
		}
	}
	//マップの外枠を指定した数値で埋める(枠の内部を奇数マスにする)
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::shape::BorderOdd class")]] constexpr void createBorderOdd(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_) noexcept {
		if (matrix_.size() < 2) return;
		for (std::size_t col{}; col < matrix_[0].size(); ++col)
			matrix_[0][col][layer_] = value_;
		if (matrix_.size() % 2 == 1) {
			for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
				matrix_[matrix_.size() - 1][col][layer_] = value_;
		}
		else for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col) {
			matrix_[matrix_.size() - 2][col][layer_] = value_;
			matrix_[matrix_.size() - 1][col][layer_] = value_;
		}
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() < 2) continue;
			matrix_[row][0][layer_] = value_;
			if (matrix_[row].size() % 2 == 0) matrix_[row][matrix_[row].size() - 2][layer_] = value_;
			matrix_[row][matrix_[row].size() - 1][layer_] = value_;
		}
	}
	//クラス版
	template<typename Matrix_Int_>
	class BorderOdd {
	public:
		//コンストラクタ
		[[deprecated("please use dtl::shape::BorderOdd class")]] constexpr BorderOdd() noexcept = default;
		template<typename Matrix_>
		constexpr explicit BorderOdd(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, layer_, value_);
		}
		template<typename Matrix_>
		[[deprecated("please use dtl::shape::BorderOdd class")]] constexpr void create(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::layer::stl::createBorderOdd(matrix_, layer_, value_);
		}
	};

} //namespace

//レイヤー通常データ
namespace dtl::generator::common::layer::normal {

	//マップの外枠を1で埋める(枠の内部を奇数マスにする)
	template<typename Matrix_>
	[[deprecated("please use dtl::shape::BorderOdd class")]] constexpr void createBorderOdd(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		if (y_ < 2) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[0][col][layer_] = 1;
		if (y_ % 2 == 1) {
			for (std::size_t col{}; col < x_; ++col)
				matrix_[y_ - 1][col][layer_] = 1;
		}
		else for (std::size_t col{}; col < x_; ++col) {
			matrix_[y_ - 2][col][layer_] = 1;
			matrix_[y_ - 1][col][layer_] = 1;
		}
		if (x_ < 2) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row][0][layer_] = 1;
			if (x_ % 2 == 0) matrix_[row][x_ - 2][layer_] = 1;
			matrix_[row][x_ - 1][layer_] = 1;
		}
	}
	//マップの外枠を指定した数値で埋める(枠の内部を奇数マスにする)
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::shape::BorderOdd class")]] constexpr void createBorderOdd(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (y_ < 2) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[0][col][layer_] = value_;
		if (y_ % 2 == 1) {
			for (std::size_t col{}; col < x_; ++col)
				matrix_[y_ - 1][col][layer_] = value_;
		}
		else for (std::size_t col{}; col < x_; ++col) {
			matrix_[y_ - 2][col][layer_] = value_;
			matrix_[y_ - 1][col][layer_] = value_;
		}
		if (x_ < 2) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row][0][layer_] = value_;
			if (x_ % 2 == 0) matrix_[row][x_ - 2][layer_] = value_;
			matrix_[row][x_ - 1][layer_] = value_;
		}
	}
	//クラス版
	template<typename Matrix_Int_>
	class BorderOdd {
	public:
		//コンストラクタ
		[[deprecated("please use dtl::shape::BorderOdd class")]] constexpr BorderOdd() noexcept = default;
		template<typename Matrix_>
		constexpr explicit BorderOdd(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, layer_, x_, y_, value_);
		}
		template<typename Matrix_>
		[[deprecated("please use dtl::shape::BorderOdd class")]] constexpr void create(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::layer::normal::createBorderOdd(matrix_, layer_, x_, y_, value_);
		}
	};

} //namespace

#endif //Included Dungeon Template Library