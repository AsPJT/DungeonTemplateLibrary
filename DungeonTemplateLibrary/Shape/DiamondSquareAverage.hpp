/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_Diamond_Square_Average
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_Diamond_Square_Average

/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <Random/MersenneTwister32bit.hpp>

namespace dtl::shape {

	//Diamond Square (Average)
	//ダイヤモンド・スクエア法(平均値)
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createDiamondSquareAverageSTL(Matrix_& matrix_, const std::size_t start_x_, const std::size_t start_y_, const std::size_t x_, const std::size_t y_, std::size_t size_, const Matrix_Int_ t1_, const Matrix_Int_ t2_, const Matrix_Int_ t3_, const Matrix_Int_ t4_, const Matrix_Int_ max_value_) noexcept {
		//再起の終了処理
		if (size_ == 0) return;
		const Matrix_Int_ & vertex_rand{ dtl::random::mt32bit.rand<Matrix_Int_>(size_) };
		//頂点の高さを決める
		const Matrix_Int_ & vertex_height{ static_cast<Matrix_Int_>((t1_ / 4 + t2_ / 4 + t3_ / 4 + t4_ / 4)) };
		matrix_[start_y_ + y_][x_] = ((vertex_height > max_value_ - vertex_rand) ? max_value_ : (vertex_height + vertex_rand));
		//四角形の2点同士の中点の高さを決定
		const Matrix_Int_ & s1{ static_cast<Matrix_Int_>((t1_ / 2 + t2_ / 2)) };
		const Matrix_Int_ & s2{ static_cast<Matrix_Int_>((t1_ / 2 + t3_ / 2)) };
		const Matrix_Int_ & s3{ static_cast<Matrix_Int_>((t2_ / 2 + t4_ / 2)) };
		const Matrix_Int_ & s4{ static_cast<Matrix_Int_>((t3_ / 2 + t4_ / 2)) };
		//4つの地点の座標を決める
		matrix_[start_y_ + y_ + size_][start_x_ + x_] = s3;
		matrix_[start_y_ + y_ - size_][start_x_ + x_] = s2;
		matrix_[start_y_ + y_][start_x_ + x_ + size_] = s4;
		matrix_[start_y_ + y_][start_x_ + x_ - size_] = s1;
		//分割サイズを半分にする
		size_ /= 2;
		//4つに分割
		createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, start_x_, start_y_, x_ - size_, y_ - size_, size_, t1_, s1, s2, matrix_[y_][x_], max_value_);
		createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, start_x_, start_y_, x_ - size_, y_ + size_, size_, s1, t2_, matrix_[y_][x_], s3, max_value_);
		createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, start_x_, start_y_, x_ + size_, y_ - size_, size_, s2, matrix_[y_][x_], t3_, s4, max_value_);
		createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, start_x_, start_y_, x_ + size_, y_ + size_, size_, matrix_[y_][x_], s3, s4, t4_, max_value_);
	}

	[[nodiscard]] constexpr std::size_t getDiamondSquareMatrixSize(const std::size_t matrix_size) noexcept {
		std::size_t map_size{ 2 };
		while (true) {
			if ((map_size + 1) > matrix_size) return map_size >>= 1;
			map_size <<= 1;
		}
		return 0;
	}

	//ダイヤモンド・スクエア法(平均値)
	template<typename Matrix_Int_>
	class SimpleDiamondSquareAverageIsland {
	public:
		//コンストラクタ
		constexpr SimpleDiamondSquareAverageIsland() noexcept = default;

		template<typename Matrix_>
		constexpr void createSTL(Matrix_& matrix_, const std::size_t map_size_, const Matrix_Int_ max_value_ = 255) const noexcept {
			const std::size_t start_x_{};
			const std::size_t start_y_{};
			matrix_[0][0] = matrix_[map_size_ / 2][0] = dtl::random::mt32bit.rand<Matrix_Int_>(max_value_ / 2);
			matrix_[0][map_size_] = matrix_[0][map_size_ / 2] = dtl::random::mt32bit.rand<Matrix_Int_>(max_value_ / 2);
			matrix_[map_size_][0] = matrix_[map_size_][map_size_ / 2] = dtl::random::mt32bit.rand<Matrix_Int_>(max_value_ / 2);
			matrix_[map_size_][map_size_] = matrix_[map_size_][map_size_ / 2] = dtl::random::mt32bit.rand<Matrix_Int_>(max_value_ / 2);
			matrix_[map_size_ / 2][map_size_ / 2] = max_value_;
			createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, start_x_, start_y_, map_size_ / 4, map_size_ / 4, map_size_ / 4, matrix_[0][0], matrix_[map_size_ / 2][0], matrix_[0][map_size_ / 2], matrix_[map_size_ / 2][map_size_ / 2], max_value_);
			createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, start_x_, start_y_, map_size_ / 4, map_size_ * 3 / 4, map_size_ / 4, matrix_[map_size_ / 2][0], matrix_[map_size_][0], matrix_[map_size_ / 2][map_size_ / 2], matrix_[map_size_][map_size_ / 2], max_value_);
			createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, start_x_, start_y_, map_size_ * 3 / 4, map_size_ / 4, map_size_ / 4, matrix_[0][map_size_ / 2], matrix_[map_size_ / 2][map_size_ / 2], matrix_[0][map_size_], matrix_[map_size_ / 2][map_size_], max_value_);
			createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, start_x_, start_y_, map_size_ * 3 / 4, map_size_ * 3 / 4, map_size_ / 4, matrix_[map_size_ / 2][map_size_ / 2], matrix_[map_size_][map_size_ / 2], matrix_[map_size_ / 2][map_size_], matrix_[map_size_][map_size_], max_value_);
		}
		template<typename Matrix_>
		constexpr void createLayer(Matrix_& matrix_, const std::size_t& layer_, const std::size_t map_size_, const Matrix_Int_ max_value_ = 255) const noexcept {
			const std::size_t start_x_{};
			const std::size_t start_y_{};
			matrix_[0][0][layer_] = matrix_[map_size_ / 2][0][layer_] = dtl::random::mt32bit.rand<Matrix_Int_>(max_value_ / 2);
			matrix_[0][map_size_][layer_] = matrix_[0][map_size_ / 2][layer_] = dtl::random::mt32bit.rand<Matrix_Int_>(max_value_ / 2);
			matrix_[map_size_][0][layer_] = matrix_[map_size_][map_size_ / 2][layer_] = dtl::random::mt32bit.rand<Matrix_Int_>(max_value_ / 2);
			matrix_[map_size_][map_size_][layer_] = matrix_[map_size_][map_size_ / 2][layer_] = dtl::random::mt32bit.rand<Matrix_Int_>(max_value_ / 2);
			matrix_[map_size_ / 2][map_size_ / 2][layer_] = max_value_;
			createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, start_x_, start_y_, map_size_ / 4, map_size_ / 4, map_size_ / 4, matrix_[0][0][layer_], matrix_[map_size_ / 2][0][layer_], matrix_[0][map_size_ / 2][layer_], matrix_[map_size_ / 2][map_size_ / 2][layer_], max_value_);
			createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, start_x_, start_y_, map_size_ / 4, map_size_ * 3 / 4, map_size_ / 4, matrix_[map_size_ / 2][0][layer_], matrix_[map_size_][0][layer_], matrix_[map_size_ / 2][map_size_ / 2][layer_], matrix_[map_size_][map_size_ / 2][layer_], max_value_);
			createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, start_x_, start_y_, map_size_ * 3 / 4, map_size_ / 4, map_size_ / 4, matrix_[0][map_size_ / 2][layer_], matrix_[map_size_ / 2][map_size_ / 2][layer_], matrix_[0][map_size_][layer_], matrix_[map_size_ / 2][map_size_][layer_], max_value_);
			createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, start_x_, start_y_, map_size_ * 3 / 4, map_size_ * 3 / 4, map_size_ / 4, matrix_[map_size_ / 2][map_size_ / 2][layer_], matrix_[map_size_][map_size_ / 2][layer_], matrix_[map_size_ / 2][map_size_][layer_], matrix_[map_size_][map_size_][layer_], max_value_);
		}

		//ワールドマップ生成
		template<typename Matrix_>
		constexpr void draw(Matrix_& matrix_, const Matrix_Int_ max_value_) const noexcept {
			if (matrix_.size() == 0 || matrix_[0].size() == 0) return;
			createSTL<Matrix_>(matrix_, getDiamondSquareMatrixSize((matrix_.size() > matrix_[0].size()) ? matrix_[0].size() : matrix_.size()), max_value_);
		}

	};

	//マスを指定した数値で埋める
	template<typename Matrix_Int_>
	class DiamondSquareAverageIsland {
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
		constexpr inline void substitutionLayer(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Function_ && function_) const noexcept {
			if (function_(matrix_[point_y_][point_x_][layer_])) matrix_[point_y_][point_x_][layer_] = draw_value;
		}


		///// 基本処理 /////

		//STL
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawSTL(Matrix_ && matrix_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < matrix_[row].size(); ++col)
					this->substitutionSTL(matrix_, col, row, args_...);
			return true;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawWidthSTL(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < matrix_[row].size() && col < point_x_; ++col)
					this->substitutionSTL(matrix_, col, row, args_...);
			return true;
		}

		//LayerSTL
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawLayerSTL(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < matrix_[row].size(); ++col)
					this->substitutionLayer(matrix_, layer_, col, row, args_...);
			return true;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawLayerWidthSTL(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < matrix_[row].size() && col < point_x_; ++col)
					this->substitutionLayer(matrix_, layer_, col, row, args_...);
			return true;
		}

		//Normal
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawNormal(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < point_x_; ++col)
					this->substitutionSTL(matrix_, col, row, args_...);
			return true;
		}

		//LayerNormal
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawLayerNormal(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
			for (Index_Size row{ point_y }; row < point_y_; ++row)
				for (Index_Size col{ point_x }; col < point_x_; ++col)
					this->substitutionLayer(matrix_, layer_, col, row, args_...);
			return true;
		}

		//Array
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawArray(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Args_ && ... args_) const noexcept {
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
			return this->draw_value;
		}


		///// 生成呼び出し /////

		//STL
		template<typename Matrix_>
		constexpr bool draw(Matrix_ && matrix_) const noexcept {
			return (width == 0) ? this->drawSTL(std::forward<Matrix_>(matrix_), (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height) : this->drawWidthSTL(matrix_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperator(Matrix_ && matrix_, Function_ && function_) const noexcept {
			return (width == 0) ? this->drawSTL(std::forward<Matrix_>(matrix_), (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_) : this->drawWidthSTL(matrix_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_);
		}

		//LayerSTL
		template<typename Matrix_>
		constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_) const noexcept {
			return (width == 0) ? this->drawLayerSTL(std::forward<Matrix_>(matrix_), layer_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height) : this->drawLayerWidthSTL(matrix_, layer_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
			return (width == 0) ? this->drawLayerSTL(std::forward<Matrix_>(matrix_), layer_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_) : this->drawLayerWidthSTL(matrix_, layer_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_);
		}

		//Normal
		template<typename Matrix_>
		constexpr bool draw(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawNormal(std::forward<Matrix_>(matrix_), (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
			return this->drawNormal(std::forward<Matrix_>(matrix_), (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, function_);
		}

		//LayerNormal
		template<typename Matrix_>
		constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
			return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, function_);
		}

		//Array
		template<typename Matrix_>
		constexpr bool drawArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
			return this->drawArray(std::forward<Matrix_>(matrix_), (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, max_x_);
		}
		template<typename Matrix_, typename Function_>
		constexpr bool drawOperatorArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
			return this->drawArray(std::forward<Matrix_>(matrix_), (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, max_x_, function_);
		}


		///// ダンジョン行列生成 /////

		template<typename Matrix_, typename ...Args_>
		constexpr auto create(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
			this->draw(matrix_, std::forward<Args_>(args_)...);
			return std::forward<Matrix_>(matrix_);
		}
		template<typename Matrix_, typename ...Args_>
		constexpr auto createArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
			this->drawArray(matrix_, std::forward<Args_>(args_)...);
			return std::forward<Matrix_>(matrix_);
		}
		template<typename Matrix_, typename ...Args_>
		constexpr auto createOperator(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
			this->drawOperator(matrix_, std::forward<Args_>(args_)...);
			return std::forward<Matrix_>(matrix_);
		}
		template<typename Matrix_, typename ...Args_>
		constexpr auto createOperatorArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
			this->drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
			return std::forward<Matrix_>(matrix_);
		}


		///// コンストラクタ /////

		constexpr DiamondSquareAverageIsland() noexcept = default;
		constexpr explicit DiamondSquareAverageIsland(const Matrix_Int_ & draw_value_) noexcept
			:draw_value(draw_value_) {}
		constexpr explicit DiamondSquareAverageIsland(const dtl::base::MatrixRange & matrix_range_) noexcept
			:point_x(matrix_range_.x), point_y(matrix_range_.y),
			width(matrix_range_.w), height(matrix_range_.h) {}
		constexpr explicit DiamondSquareAverageIsland(const dtl::base::MatrixRange & matrix_range_, const Matrix_Int_ & draw_value_) noexcept
			:point_x(matrix_range_.x), point_y(matrix_range_.y),
			width(matrix_range_.w), height(matrix_range_.h),
			draw_value(draw_value_) {}
		constexpr explicit DiamondSquareAverageIsland(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
			:point_x(point_x_), point_y(point_y_),
			width(width_), height(height_) {}
		constexpr explicit DiamondSquareAverageIsland(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_ & draw_value_) noexcept
			:point_x(point_x_), point_y(point_y_),
			width(width_), height(height_),
			draw_value(draw_value_) {}
	};

} //namespace

#endif //Included Dungeon Template Library