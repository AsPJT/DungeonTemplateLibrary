/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_RECT
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_RECT

/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>

namespace dtl::shape {

	//四角形の生成
	template<typename Matrix_Int_>
	class Rect {
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

		//Normal
		template<typename Matrix_>
		constexpr bool drawNormal(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < point_x_; ++col)
					this->substitutionSTL(matrix_, col, row);
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

		//Array
		template<typename Matrix_>
		constexpr bool drawArray(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < point_x_; ++col)
					this->substitutionArray(matrix_, col, row, max_x_);
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
			return (width == 0) ? this->drawSTL(matrix_, (height == 0 || point_y+height >= matrix_.size()) ? matrix_.size() : point_y+height) : this->drawWidthSTL(matrix_, point_x + width, (height == 0 || point_y+height >= matrix_.size()) ? matrix_.size() : point_y+height);
		}

		//LayerSTL
		template<typename Matrix_>
		constexpr bool draw(Matrix_&& matrix_, const Index_Size layer_) const noexcept {
			return (width == 0) ? this->drawLayerSTL(matrix_, layer_, (height == 0 || point_y+height >= matrix_.size()) ? matrix_.size() : point_y + height) : this->drawLayerWidthSTL(matrix_, layer_, point_x + width, (height == 0 || point_y+height >= matrix_.size()) ? matrix_.size() : point_y + height);
		}

		//Normal
		template<typename Matrix_>
		constexpr bool draw(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawNormal(matrix_, (width == 0 || point_x+width >= max_x_) ? max_x_ : point_x+width, (height == 0 || point_y+height >= max_y_) ? max_y_ : point_y+height);
		}

		//LayerNormal
		template<typename Matrix_>
		constexpr bool draw(Matrix_&& matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawLayerNormal(matrix_, layer_, (width == 0 || point_x+width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y+height >= max_y_) ? max_y_ : point_y + height);
		}

		//Array
		template<typename Matrix_>
		constexpr bool drawArray(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawArray(matrix_, (width == 0 || point_x+width >= max_x_) ? max_x_ : point_x+width, (height == 0 || point_y+height >= max_y_) ? max_y_ : point_y+height, max_x_);
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


		///// コンストラクタ /////

		constexpr Rect() noexcept = default;
		constexpr explicit Rect(const Matrix_Int_& draw_value_) noexcept
			:draw_value(draw_value_) {}
		constexpr explicit Rect(const PairSize& length_) noexcept
			:width(length_.first), height(length_.second) {}
		constexpr explicit Rect(const PairSize& length_, const Matrix_Int_& draw_value_) noexcept
			:width(length_.first), height(length_.second),
			draw_value(draw_value_) {}
		constexpr explicit Rect(const PairSize& position_, const PairSize& length_) noexcept
			:point_x(position_.first), point_y(position_.second),
			width(length_.first), height(length_.second) {}
		constexpr explicit Rect(const PairSize& position_, const PairSize& length_, const Matrix_Int_& draw_value_) noexcept
			:point_x(position_.first), point_y(position_.second),
			width(length_.first), height(length_.second),
			draw_value(draw_value_) {}
		constexpr explicit Rect(const Index_Size width_, const Index_Size height_) noexcept
			:width(width_), height(height_) {}
		constexpr explicit Rect(const Index_Size width_, const Index_Size height_, const Matrix_Int_& draw_value_) noexcept
			:width(width_), height(height_),
			draw_value(draw_value_) {}
		constexpr explicit Rect(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
			:point_x(point_x_), point_y(point_y_),
			width(width_), height(height_) {}
		constexpr explicit Rect(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_& draw_value_) noexcept
			:point_x(point_x_), point_y(point_y_),
			width(width_), height(height_),
			draw_value(draw_value_) {}
	};
}





//総合データ
namespace dtl::generator::common::data {

	//----------   DungeonInit   ----------
	//1.全てのマスを0で埋める
	//2.全てのマスを指定した数値で埋める

	enum eDungeonInit {
		dungeon_init_empty_id,
		dungeon_init_enum_num
	};
	constexpr bool dungeon_init_bool{ (dungeon_init_enum_num <= 2) ? true : false };

} //namespace

//STLデータ
namespace dtl::generator::common::stl {

	//全てのマスを0で埋める
	template<typename Matrix_>
	[[deprecated("please use dtl::shape::Rect class")]] constexpr void createDungeonInit(Matrix_& matrix_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				matrix_[row][col] = 0;
	}
	//全てのマスを指定した数値で埋める
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::shape::Rect class")]] constexpr void createDungeonInit(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				matrix_[row][col] = value_;
	}
	//クラス版
	template<typename Matrix_Int_>
	class DungeonInit {
	public:
		//コンストラクタ
		[[deprecated("please use dtl::shape::Rect class")]] constexpr DungeonInit() noexcept = default;
		template<typename Matrix_>
		constexpr explicit DungeonInit(Matrix_& matrix_, const Matrix_Int_ value_ = 0) noexcept {
			create(matrix_, value_);
		}
		template<typename Matrix_>
		[[deprecated("please use dtl::shape::Rect class")]] constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 0) noexcept {
			dtl::generator::common::stl::createDungeonInit(matrix_, value_);
		}
	};

} //namespace

//通常データ
namespace dtl::generator::common::normal {

	//全てのマスを0で埋める
	template<typename Matrix_>
	[[deprecated("please use dtl::shape::Rect class")]] constexpr void createDungeonInit(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row][col] = 0;
	}
	//全てのマスを指定した数値で埋める
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::shape::Rect class")]] constexpr void createDungeonInit(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row][col] = value_;
	}
	template<typename Matrix_>
	[[deprecated("please use dtl::shape::Rect class")]] constexpr void createDungeonInit(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t w_, const std::size_t h_) noexcept {
		for (std::size_t row{ y_ }; row < h_; ++row)
			for (std::size_t col{ x_ }; col < w_; ++col)
				matrix_[row][col] = 0;
	}
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::shape::Rect class")]] constexpr void createDungeonInit(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t w_, const std::size_t h_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{ y_ }; row < h_; ++row)
			for (std::size_t col{ x_ }; col < w_; ++col)
				matrix_[row][col] = value_;
	}
	//クラス版
	template<typename Matrix_Int_>
	class DungeonInit {
	public:
		//コンストラクタ
		[[deprecated("please use dtl::shape::Rect class")]] constexpr DungeonInit() noexcept = default;
		template<typename Matrix_>
		constexpr explicit DungeonInit(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 0) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		[[deprecated("please use dtl::shape::Rect class")]] constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 0) const noexcept {
			dtl::generator::common::normal::createDungeonInit(matrix_, x_, y_, value_);
		}
	};

} //namespace

//配列データ
namespace dtl::generator::common::array {

	//全てのマスを0で埋める
	template<typename Matrix_>
	[[deprecated("please use dtl::shape::Rect class")]] constexpr void createDungeonInit(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row * x_ + col] = 0;
	}
	//全てのマスを指定した数値で埋める
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::shape::Rect class")]] constexpr void createDungeonInit(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row * x_ + col] = value_;
	}
	template<typename Matrix_>
	[[deprecated("please use dtl::shape::Rect class")]] constexpr void createDungeonInit(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t w_, const std::size_t h_) noexcept {
		for (std::size_t row{ y_ }; row < h_; ++row)
			for (std::size_t col{ x_ }; col < w_; ++col)
				matrix_[row * w_ + col] = 0;
	}
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::shape::Rect class")]] constexpr void createDungeonInit(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t w_, const std::size_t h_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{ y_ }; row < h_; ++row)
			for (std::size_t col{ x_ }; col < w_; ++col)
				matrix_[row * w_ + col] = value_;
	}

	template<typename Matrix_Int_>
	class DungeonInit {
	public:
		//コンストラクタ
		[[deprecated("please use dtl::shape::Rect class")]] constexpr DungeonInit() noexcept = default;
		template<typename Matrix_>
		constexpr explicit DungeonInit(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 0) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		[[deprecated("please use dtl::shape::Rect class")]] constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 0) const noexcept {
			dtl::generator::common::array::createDungeonInit(matrix_, x_, y_, value_);
		}
	};

} //namespace

//範囲forデータ
namespace dtl::generator::common::rangeBasedFor {

	//全てのマスを0で埋める
	template<typename Matrix_>
	[[deprecated("please use dtl::shape::Rect class")]] constexpr void createDungeonInit(Matrix_& matrix_) noexcept {
		for (auto&& row : matrix_)
			for (auto&& col : row)
				col = 0;
	}
	//全てのマスを指定した数値で埋める
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::shape::Rect class")]] constexpr void createDungeonInit(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		for (auto&& row : matrix_)
			for (auto&& col : row)
				col = value_;
	}

} //namespace

//レイヤーSTLデータ
namespace dtl::generator::common::layer::stl {

	//全てのマスを0で埋める
	template<typename Matrix_>
	[[deprecated("please use dtl::shape::Rect class")]] constexpr void createDungeonInit(Matrix_& matrix_, const std::size_t layer_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				matrix_[row][col][layer_] = 0;
	}
	//全てのマスを指定した数値で埋める
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::shape::Rect class")]] constexpr void createDungeonInit(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				matrix_[row][col][layer_] = value_;
	}
	//クラス版
	template<typename Matrix_Int_>
	class DungeonInit {
	public:
		//コンストラクタ
		[[deprecated("please use dtl::shape::Rect class")]] constexpr DungeonInit() noexcept = default;
		template<typename Matrix_>
		constexpr explicit DungeonInit(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_ = 0) noexcept {
			create(matrix_, layer_, value_);
		}
		template<typename Matrix_>
		[[deprecated("please use dtl::shape::Rect class")]] constexpr void create(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_ = 0) const noexcept {
			dtl::generator::common::layer::stl::createDungeonInit(matrix_, layer_, value_);
		}
	};

} //namespace

//レイヤー通常データ
namespace dtl::generator::common::layer::normal {

	//全てのマスを0で埋める
	template<typename Matrix_>
	[[deprecated("please use dtl::shape::Rect class")]] constexpr void createDungeonInit(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row][col][layer_] = 0;
	}
	//全てのマスを指定した数値で埋める
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::shape::Rect class")]] constexpr void createDungeonInit(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row][col][layer_] = value_;
	}
	template<typename Matrix_>
	[[deprecated("please use dtl::shape::Rect class")]] constexpr void createDungeonInit(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const std::size_t w_, const std::size_t h_) noexcept {
		for (std::size_t row{ y_ }; row < h_; ++row)
			for (std::size_t col{ x_ }; col < w_; ++col)
				matrix_[row][col][layer_] = 0;
	}
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::shape::Rect class")]] constexpr void createDungeonInit(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const std::size_t w_, const std::size_t h_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{ y_ }; row < h_; ++row)
			for (std::size_t col{ x_ }; col < w_; ++col)
				matrix_[row][col][layer_] = value_;
	}
	//クラス版
	template<typename Matrix_Int_>
	class DungeonInit {
	public:
		//コンストラクタ
		[[deprecated("please use dtl::shape::Rect class")]] constexpr DungeonInit() noexcept = default;
		template<typename Matrix_>
		constexpr explicit DungeonInit(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 0) noexcept {
			create(matrix_, layer_, x_, y_, value_);
		}
		template<typename Matrix_>
		[[deprecated("please use dtl::shape::Rect class")]] constexpr void create(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 0) const noexcept {
			dtl::generator::common::layer::normal::createDungeonInit(matrix_, layer_, x_, y_, value_);
		}
	};

} //namespace

#endif //Included Dungeon Template Library