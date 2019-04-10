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
	constexpr void createDiamondSquareAverageSTL(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, std::size_t size_, const Matrix_Int_ t1_, const Matrix_Int_ t2_, const Matrix_Int_ t3_, const Matrix_Int_ t4_, const Matrix_Int_ max_value_) noexcept {
		//再起の終了処理
		if (size_ == 0) return;
		const Matrix_Int_& vertex_rand{ dtl::random::mt32bit.rand<Matrix_Int_>(size_) };
		//頂点の高さを決める
		const Matrix_Int_& vertex_height{ static_cast<Matrix_Int_>((t1_ / 4 + t2_ / 4 + t3_ / 4 + t4_ / 4)) };
		matrix_[y_][x_] = ((vertex_height > max_value_ - vertex_rand) ? max_value_ : (vertex_height + vertex_rand));
		//四角形の2点同士の中点の高さを決定
		const Matrix_Int_& s1{ static_cast<Matrix_Int_>((t1_ / 2 + t2_ / 2)) };
		const Matrix_Int_& s2{ static_cast<Matrix_Int_>((t1_ / 2 + t3_ / 2)) };
		const Matrix_Int_& s3{ static_cast<Matrix_Int_>((t2_ / 2 + t4_ / 2)) };
		const Matrix_Int_& s4{ static_cast<Matrix_Int_>((t3_ / 2 + t4_ / 2)) };
		//4つの地点の座標を決める
		matrix_[y_ + size_][x_] = s3;
		matrix_[y_ - size_][x_] = s2;
		matrix_[y_][x_ + size_] = s4;
		matrix_[y_][x_ - size_] = s1;
		//分割サイズを半分にする
		size_ /= 2;
		//4つに分割
		createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, x_ - size_, y_ - size_, size_, t1_, s1, s2, matrix_[y_][x_], max_value_);
		createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, x_ - size_, y_ + size_, size_, s1, t2_, matrix_[y_][x_], s3, max_value_);
		createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, x_ + size_, y_ - size_, size_, s2, matrix_[y_][x_], t3_, s4, max_value_);
		createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, x_ + size_, y_ + size_, size_, matrix_[y_][x_], s3, s4, t4_, max_value_);
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
			matrix_[0][0] = matrix_[map_size_ / 2][0] = dtl::random::mt32bit.rand<Matrix_Int_>(max_value_ / 2);
			matrix_[0][map_size_] = matrix_[0][map_size_ / 2] = dtl::random::mt32bit.rand<Matrix_Int_>(max_value_ / 2);
			matrix_[map_size_][0] = matrix_[map_size_][map_size_ / 2] = dtl::random::mt32bit.rand<Matrix_Int_>(max_value_ / 2);
			matrix_[map_size_][map_size_] = matrix_[map_size_][map_size_ / 2] = dtl::random::mt32bit.rand<Matrix_Int_>(max_value_ / 2);
			matrix_[map_size_ / 2][map_size_ / 2] = max_value_;
			createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, map_size_ / 4, map_size_ / 4, map_size_ / 4, matrix_[0][0], matrix_[map_size_ / 2][0], matrix_[0][map_size_ / 2], matrix_[map_size_ / 2][map_size_ / 2], max_value_);
			createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, map_size_ / 4, map_size_ * 3 / 4, map_size_ / 4, matrix_[map_size_ / 2][0], matrix_[map_size_][0], matrix_[map_size_ / 2][map_size_ / 2], matrix_[map_size_][map_size_ / 2], max_value_);
			createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, map_size_ * 3 / 4, map_size_ / 4, map_size_ / 4, matrix_[0][map_size_ / 2], matrix_[map_size_ / 2][map_size_ / 2], matrix_[0][map_size_], matrix_[map_size_ / 2][map_size_], max_value_);
			createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, map_size_ * 3 / 4, map_size_ * 3 / 4, map_size_ / 4, matrix_[map_size_ / 2][map_size_ / 2], matrix_[map_size_][map_size_ / 2], matrix_[map_size_ / 2][map_size_], matrix_[map_size_][map_size_], max_value_);
		}
		template<typename Matrix_>
		constexpr void createLayer(Matrix_& matrix_, const std::size_t& layer_, const std::size_t map_size_, const Matrix_Int_ max_value_ = 255) const noexcept {
			matrix_[0][0][layer_] = matrix_[map_size_ / 2][0][layer_] = dtl::random::mt32bit.rand<Matrix_Int_>(max_value_ / 2);
			matrix_[0][map_size_][layer_] = matrix_[0][map_size_ / 2][layer_] = dtl::random::mt32bit.rand<Matrix_Int_>(max_value_ / 2);
			matrix_[map_size_][0][layer_] = matrix_[map_size_][map_size_ / 2][layer_] = dtl::random::mt32bit.rand<Matrix_Int_>(max_value_ / 2);
			matrix_[map_size_][map_size_][layer_] = matrix_[map_size_][map_size_ / 2][layer_] = dtl::random::mt32bit.rand<Matrix_Int_>(max_value_ / 2);
			matrix_[map_size_ / 2][map_size_ / 2][layer_] = max_value_;
			createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, map_size_ / 4, map_size_ / 4, map_size_ / 4, matrix_[0][0][layer_], matrix_[map_size_ / 2][0][layer_], matrix_[0][map_size_ / 2][layer_], matrix_[map_size_ / 2][map_size_ / 2][layer_], max_value_);
			createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, map_size_ / 4, map_size_ * 3 / 4, map_size_ / 4, matrix_[map_size_ / 2][0][layer_], matrix_[map_size_][0][layer_], matrix_[map_size_ / 2][map_size_ / 2][layer_], matrix_[map_size_][map_size_ / 2][layer_], max_value_);
			createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, map_size_ * 3 / 4, map_size_ / 4, map_size_ / 4, matrix_[0][map_size_ / 2][layer_], matrix_[map_size_ / 2][map_size_ / 2][layer_], matrix_[0][map_size_][layer_], matrix_[map_size_ / 2][map_size_][layer_], max_value_);
			createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, map_size_ * 3 / 4, map_size_ * 3 / 4, map_size_ / 4, matrix_[map_size_ / 2][map_size_ / 2][layer_], matrix_[map_size_][map_size_ / 2][layer_], matrix_[map_size_ / 2][map_size_][layer_], matrix_[map_size_][map_size_][layer_], max_value_);
		}

		//ワールドマップ生成
		template<typename Matrix_>
		constexpr void draw(Matrix_& matrix_, const Matrix_Int_ max_value_) const noexcept {
			if (matrix_.size() == 0 || matrix_[0].size() == 0) return;
			createSTL<Matrix_>(matrix_, getDiamondSquareMatrixSize((matrix_.size() > matrix_[0].size()) ? matrix_[0].size() : matrix_.size()), max_value_);
		}

	};

} //namespace

#endif //Included Dungeon Template Library