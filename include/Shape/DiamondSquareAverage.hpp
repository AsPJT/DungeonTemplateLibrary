/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_Diamond_CREATE_DIAMOND_SQARE_AVERAGE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_Diamond_CREATE_DIAMOND_SQARE_AVERAGE_HPP

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <Random/MersenneTwister32bit.hpp>
#include <Macros/constexpr.hpp>

namespace dtl {
	inline namespace shape {

		//Diamond Square (Average)
		//ダイヤモンド・スクエア法(平均値)
		template<typename Matrix_Int_, typename Matrix_, typename Function_>
		DTL_CPP14_CONSTEXPR
			void createDiamondSquareAverageSTL(Matrix_&& matrix_, const std::size_t start_x_, const std::size_t start_y_, const std::size_t x_, const std::size_t y_, std::size_t size_, const Matrix_Int_& t1_, const Matrix_Int_& t2_, const Matrix_Int_& t3_, const Matrix_Int_& t4_, const Matrix_Int_& max_value_, const Matrix_Int_& add_altitude_, Function_&& func_) noexcept {
			//再起の終了処理
			if (size_ == 0) return;
			const Matrix_Int_ & vertex_rand{ dtl::random::mt32bit.get<Matrix_Int_>(add_altitude_) };
			//頂点の高さを決める
			const Matrix_Int_ & vertex_height{ static_cast<Matrix_Int_>((t1_ / 4 + t2_ / 4 + t3_ / 4 + t4_ / 4)) };
			//matrix_[start_y_ + y_][start_x_ + x_] = ((vertex_height > max_value_ - vertex_rand) ? max_value_ : (vertex_height + vertex_rand));
			matrix_[start_y_ + y_][start_x_ + x_] = vertex_height + vertex_rand;

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
			createDiamondSquareAverageSTL<Matrix_Int_, Matrix_, Function_>(matrix_, start_x_, start_y_, x_ - size_, y_ - size_, size_, t1_, s1, s2, matrix_[start_y_ + y_][start_x_ + x_], max_value_, static_cast<Matrix_Int_>(func_(add_altitude_)), func_);
			createDiamondSquareAverageSTL<Matrix_Int_, Matrix_, Function_>(matrix_, start_x_, start_y_, x_ - size_, y_ + size_, size_, s1, t2_, matrix_[start_y_ + y_][start_x_ + x_], s3, max_value_, static_cast<Matrix_Int_>(func_(add_altitude_)), func_);
			createDiamondSquareAverageSTL<Matrix_Int_, Matrix_, Function_>(matrix_, start_x_, start_y_, x_ + size_, y_ - size_, size_, s2, matrix_[start_y_ + y_][start_x_ + x_], t3_, s4, max_value_, static_cast<Matrix_Int_>(func_(add_altitude_)), func_);
			createDiamondSquareAverageSTL<Matrix_Int_, Matrix_, Function_>(matrix_, start_x_, start_y_, x_ + size_, y_ + size_, size_, matrix_[start_y_ + y_][start_x_ + x_], s3, s4, t4_, max_value_, static_cast<Matrix_Int_>(func_(add_altitude_)), func_);
		}
		template<typename Matrix_Int_, typename Matrix_, typename Function_>
		DTL_CPP14_CONSTEXPR
			void createDiamondSquareAverageArray(Matrix_ && matrix_, const std::size_t max_x_, const std::size_t start_x_, const std::size_t start_y_, const std::size_t x_, const std::size_t y_, std::size_t size_, const Matrix_Int_ & t1_, const Matrix_Int_ & t2_, const Matrix_Int_ & t3_, const Matrix_Int_ & t4_, const Matrix_Int_ & max_value_, const Matrix_Int_ & add_altitude_, Function_ && func_) noexcept {
			//再起の終了処理
			if (size_ == 0) return;
			const Matrix_Int_ & vertex_rand{ dtl::random::mt32bit.get<Matrix_Int_>(add_altitude_) };
			//頂点の高さを決める
			const Matrix_Int_ & vertex_height{ static_cast<Matrix_Int_>((t1_ / 4 + t2_ / 4 + t3_ / 4 + t4_ / 4)) };
			//matrix_[(start_y_ + y_) * max_x_ + (start_x_ + x_)] = ((vertex_height > max_value_ - vertex_rand) ? max_value_ : (vertex_height + vertex_rand));
			matrix_[(start_y_ + y_) * max_x_ + (start_x_ + x_)] = vertex_height + vertex_rand;

			//四角形の2点同士の中点の高さを決定
			const Matrix_Int_ & s1{ static_cast<Matrix_Int_>((t1_ / 2 + t2_ / 2)) };
			const Matrix_Int_ & s2{ static_cast<Matrix_Int_>((t1_ / 2 + t3_ / 2)) };
			const Matrix_Int_ & s3{ static_cast<Matrix_Int_>((t2_ / 2 + t4_ / 2)) };
			const Matrix_Int_ & s4{ static_cast<Matrix_Int_>((t3_ / 2 + t4_ / 2)) };
			//4つの地点の座標を決める
			matrix_[(start_y_ + y_ + size_) * max_x_ + (start_x_ + x_)] = s3;
			matrix_[(start_y_ + y_ - size_) * max_x_ + (start_x_ + x_)] = s2;
			matrix_[(start_y_ + y_) * max_x_ + (start_x_ + x_ + size_)] = s4;
			matrix_[(start_y_ + y_) * max_x_ + (start_x_ + x_ - size_)] = s1;
			//分割サイズを半分にする
			size_ /= 2;
			//4つに分割
			createDiamondSquareAverageArray<Matrix_Int_, Matrix_, Function_>(matrix_, max_x_, start_x_, start_y_, x_ - size_, y_ - size_, size_, t1_, s1, s2, matrix_[(start_y_ + y_) * max_x_ + (start_x_ + x_)], max_value_, static_cast<Matrix_Int_>(func_(add_altitude_)), func_);
			createDiamondSquareAverageArray<Matrix_Int_, Matrix_, Function_>(matrix_, max_x_, start_x_, start_y_, x_ - size_, y_ + size_, size_, s1, t2_, matrix_[(start_y_ + y_) * max_x_ + (start_x_ + x_)], s3, max_value_, static_cast<Matrix_Int_>(func_(add_altitude_)), func_);
			createDiamondSquareAverageArray<Matrix_Int_, Matrix_, Function_>(matrix_, max_x_, start_x_, start_y_, x_ + size_, y_ - size_, size_, s2, matrix_[(start_y_ + y_) * max_x_ + (start_x_ + x_)], t3_, s4, max_value_, static_cast<Matrix_Int_>(func_(add_altitude_)), func_);
			createDiamondSquareAverageArray<Matrix_Int_, Matrix_, Function_>(matrix_, max_x_, start_x_, start_y_, x_ + size_, y_ + size_, size_, matrix_[(start_y_ + y_) * max_x_ + (start_x_ + x_)], s3, s4, t4_, max_value_, static_cast<Matrix_Int_>(func_(add_altitude_)), func_);
		}
		template<typename Matrix_Int_, typename Matrix_, typename Function_>
		DTL_CPP14_CONSTEXPR
			void createDiamondSquareAverageLayer(Matrix_ && matrix_, const std::size_t layer_, const std::size_t start_x_, const std::size_t start_y_, const std::size_t x_, const std::size_t y_, std::size_t size_, const Matrix_Int_ & t1_, const Matrix_Int_ & t2_, const Matrix_Int_ & t3_, const Matrix_Int_ & t4_, const Matrix_Int_ & max_value_, const Matrix_Int_ & add_altitude_, Function_ && func_) noexcept {
			//再起の終了処理
			if (size_ == 0) return;
			const Matrix_Int_ & vertex_rand{ dtl::random::mt32bit.get<Matrix_Int_>(add_altitude_) };
			//頂点の高さを決める
			const Matrix_Int_ & vertex_height{ static_cast<Matrix_Int_>((t1_ / 4 + t2_ / 4 + t3_ / 4 + t4_ / 4)) };
			//matrix_[start_y_ + y_][start_x_ + x_][layer_] = ((vertex_height > max_value_ - vertex_rand) ? max_value_ : (vertex_height + vertex_rand));
			matrix_[start_y_ + y_][start_x_ + x_][layer_] = vertex_height + vertex_rand;

			//四角形の2点同士の中点の高さを決定
			const Matrix_Int_ & s1{ static_cast<Matrix_Int_>((t1_ / 2 + t2_ / 2)) };
			const Matrix_Int_ & s2{ static_cast<Matrix_Int_>((t1_ / 2 + t3_ / 2)) };
			const Matrix_Int_ & s3{ static_cast<Matrix_Int_>((t2_ / 2 + t4_ / 2)) };
			const Matrix_Int_ & s4{ static_cast<Matrix_Int_>((t3_ / 2 + t4_ / 2)) };
			//4つの地点の座標を決める
			matrix_[start_y_ + y_ + size_][start_x_ + x_][layer_] = s3;
			matrix_[start_y_ + y_ - size_][start_x_ + x_][layer_] = s2;
			matrix_[start_y_ + y_][start_x_ + x_ + size_][layer_] = s4;
			matrix_[start_y_ + y_][start_x_ + x_ - size_][layer_] = s1;
			//分割サイズを半分にする
			size_ /= 2;
			//4つに分割
			createDiamondSquareAverageLayer<Matrix_Int_, Matrix_, Function_>(matrix_, layer_, start_x_, start_y_, x_ - size_, y_ - size_, size_, t1_, s1, s2, matrix_[start_y_ + y_][start_x_ + x_][layer_], max_value_, static_cast<Matrix_Int_>(func_(add_altitude_)), func_);
			createDiamondSquareAverageLayer<Matrix_Int_, Matrix_, Function_>(matrix_, layer_, start_x_, start_y_, x_ - size_, y_ + size_, size_, s1, t2_, matrix_[start_y_ + y_][start_x_ + x_][layer_], s3, max_value_, static_cast<Matrix_Int_>(func_(add_altitude_)), func_);
			createDiamondSquareAverageLayer<Matrix_Int_, Matrix_, Function_>(matrix_, layer_, start_x_, start_y_, x_ + size_, y_ - size_, size_, s2, matrix_[start_y_ + y_][start_x_ + x_][layer_], t3_, s4, max_value_, static_cast<Matrix_Int_>(func_(add_altitude_)), func_);
			createDiamondSquareAverageLayer<Matrix_Int_, Matrix_, Function_>(matrix_, layer_, start_x_, start_y_, x_ + size_, y_ + size_, size_, matrix_[start_y_ + y_][start_x_ + x_][layer_], s3, s4, t4_, max_value_, static_cast<Matrix_Int_>(func_(add_altitude_)), func_);
		}

	} //namespace
}

#endif //Included Dungeon Template Library