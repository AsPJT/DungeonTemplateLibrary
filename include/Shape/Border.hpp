/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_BORDER_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_BORDER_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::Border-(形状クラス)/
#######################################################################################*/

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <Base/Struct.hpp>
#include <Macros/constexpr.hpp>
#include <Macros/nodiscard.hpp>
#include <Utility/RectBaseWithValue.hpp>

namespace dtl {
	inline namespace shape {

		//マップの外枠を指定した数値で埋める
		template<typename Matrix_Int_>
		class Border : public RectBaseWithValue<Border<Matrix_Int_>, Matrix_Int_> {
		private:


			///// エイリアス /////

			using Index_Size = std::size_t;
			using ShapeBase_t = RectBaseWithValue<Border<Matrix_Int_>, Matrix_Int_>;


			///// 代入処理 /////

			template<typename Matrix_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionSTL(Matrix_&& matrix_, const Index_Size end_x_, const Index_Size end_y_) const noexcept {
				matrix_[end_y_][end_x_] = this->draw_value;
			}
			template<typename Matrix_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionArray(Matrix_&& matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_) const noexcept {
				matrix_[end_y_ * max_x_ + end_x_] = this->draw_value;
			}
			template<typename Matrix_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionLayer(Matrix_&& matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_) const noexcept {
				matrix_[end_y_][end_x_][layer_] = this->draw_value;
			}

			template<typename Matrix_, typename Function_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionSTL(Matrix_&& matrix_, const Index_Size end_x_, const Index_Size end_y_, Function_&& function_) const noexcept {
				if (function_(matrix_[end_y_][end_x_])) matrix_[end_y_][end_x_] = this->draw_value;
			}
			template<typename Matrix_, typename Function_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionArray(Matrix_&& matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Function_&& function_) const noexcept {
				if (function_(matrix_[end_y_ * max_x_ + end_x_])) matrix_[end_y_ * max_x_ + end_x_] = this->draw_value;
			}
			template<typename Matrix_, typename Function_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionLayer(Matrix_ && matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Function_ && function_) const noexcept {
				if (function_(matrix_[end_y_][end_x_][layer_])) matrix_[end_y_][end_x_][layer_] = this->draw_value;
			}


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawSTL(Matrix_ && matrix_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				if (end_y_ == 0) return true;
				for (Index_Size col{ this->start_x }; col < matrix_[this->start_y].size(); ++col)
					this->substitutionSTL(matrix_, col, this->start_y, args_...);
				for (Index_Size col{ this->start_x }; col < matrix_[end_y_ - 1].size(); ++col)
					this->substitutionSTL(matrix_, col, end_y_ - 1, args_...);
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					if (matrix_[row].size() == 0) continue;
					this->substitutionSTL(matrix_, this->start_x, row, args_...);
					this->substitutionSTL(matrix_, matrix_[row].size() - 1, row, std::forward<Args_>(args_)...);
				}
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawWidthSTL(Matrix_ && matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				if (end_y_ == 0) return true;
				for (Index_Size col{ this->start_x }; col < end_x_ && col < matrix_[this->start_y].size(); ++col)
					this->substitutionSTL(matrix_, col, this->start_y, args_...);
				for (Index_Size col{ this->start_x }; col < end_x_ && col < matrix_[end_y_ - 1].size(); ++col)
					this->substitutionSTL(matrix_, col, end_y_ - 1, args_...);
				if (end_x_ == 0) return true;
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					if (matrix_[row].size() == 0) continue;
					this->substitutionSTL(matrix_, this->start_x, row, args_...);
					if (matrix_[row].size() <= end_x_) this->substitutionSTL(matrix_, matrix_[row].size() - 1, row, args_...);
					else this->substitutionSTL(matrix_, end_x_ - 1, row, std::forward<Args_>(args_)...);
				}
				return true;
			}

			//LayerSTL
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawLayerSTL(Matrix_ && matrix_, const Index_Size layer_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				if (end_y_ == 0) return true;
				for (Index_Size col{ this->start_x }; col < matrix_[this->start_y].size(); ++col)
					this->substitutionLayer(matrix_, layer_, col, this->start_y, args_...);
				for (Index_Size col{ this->start_x }; col < matrix_[end_y_ - 1].size(); ++col)
					this->substitutionLayer(matrix_, layer_, col, end_y_ - 1, args_...);
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					if (matrix_[row].size() == 0) continue;
					this->substitutionLayer(matrix_, layer_, this->start_x, row, args_...);
					this->substitutionLayer(matrix_, layer_, matrix_[row].size() - 1, row, std::forward<Args_>(args_)...);
				}
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawLayerWidthSTL(Matrix_ && matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				if (end_y_ == 0) return true;
				for (Index_Size col{ this->start_x }; col < end_x_ && col < matrix_[this->start_y].size(); ++col)
					this->substitutionLayer(matrix_, layer_, col, this->start_y, args_...);
				for (Index_Size col{ this->start_x }; col < end_x_ && col < matrix_[end_y_ - 1].size(); ++col)
					this->substitutionLayer(matrix_, layer_, col, end_y_ - 1, args_...);
				if (end_x_ == 0) return true;
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					if (matrix_[row].size() == 0) continue;
					this->substitutionLayer(matrix_, layer_, this->start_x, row, args_...);
					if (matrix_[row].size() <= end_x_) this->substitutionLayer(matrix_, layer_, matrix_[row].size() - 1, row, args_...);
					else this->substitutionLayer(matrix_, layer_, end_x_ - 1, row, std::forward<Args_>(args_)...);
				}
				return true;
			}

			//Normal
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawNormal(Matrix_ && matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				if (end_x_ == 0 || end_y_ == 0) return true;
				for (Index_Size col{ this->start_x }; col < end_x_; ++col) {
					this->substitutionSTL(matrix_, col, this->start_y, args_...);
					this->substitutionSTL(matrix_, col, end_y_ - 1, args_...);
				}
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					this->substitutionSTL(matrix_, this->start_x, row, args_...);
					this->substitutionSTL(matrix_, end_x_ - 1, row, std::forward<Args_>(args_)...);
				}
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawLayerNormal(Matrix_ && matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				if (end_x_ == 0 || end_y_ == 0) return true;
				for (Index_Size col{ this->start_x }; col < end_x_; ++col) {
					this->substitutionLayer(matrix_, layer_, col, this->start_y, args_...);
					this->substitutionLayer(matrix_, layer_, col, end_y_ - 1, args_...);
				}
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					this->substitutionLayer(matrix_, layer_, this->start_x, row, args_...);
					this->substitutionLayer(matrix_, layer_, end_x_ - 1, row, std::forward<Args_>(args_)...);
				}
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawArray(Matrix_ && matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Args_ && ... args_) const noexcept {
				if (end_x_ == 0 || end_y_ == 0) return true;
				for (Index_Size col{ this->start_x }; col < end_x_; ++col) {
					this->substitutionArray(matrix_, col, this->start_y, max_x_, args_...);
					this->substitutionArray(matrix_, col, end_y_ - 1, max_x_, args_...);
				}
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					this->substitutionArray(matrix_, this->start_x, row, max_x_, args_...);
					this->substitutionArray(matrix_, end_x_ - 1, row, max_x_, std::forward<Args_>(args_)...);
				}
				return true;
			}

		public:


			///// 生成呼び出し /////

			//STL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_) const noexcept {
				return (this->width == 0) ? this->drawSTL(std::forward<Matrix_>(matrix_), this->calcEndY(matrix_.size())) : this->drawWidthSTL(matrix_, this->start_x + this->width, this->calcEndY(matrix_.size()));
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, Function_ && function_) const noexcept {
				return (this->width == 0) ? this->drawSTL(std::forward<Matrix_>(matrix_), this->calcEndY(matrix_.size()), function_) : this->drawWidthSTL(matrix_, this->start_x + this->width, this->calcEndY(matrix_.size()), function_);
			}

			//LayerSTL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_) const noexcept {
				return (this->width == 0) ? this->drawLayerSTL(std::forward<Matrix_>(matrix_), layer_, this->calcEndY(matrix_.size())) : this->drawLayerWidthSTL(matrix_, layer_, this->start_x + this->width, this->calcEndY(matrix_.size()));
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
				return (this->width == 0) ? this->drawLayerSTL(std::forward<Matrix_>(matrix_), layer_, this->calcEndY(matrix_.size()), function_) : this->drawLayerWidthSTL(matrix_, layer_, this->start_x + this->width, this->calcEndY(matrix_.size()), function_);
			}

			//Normal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawNormal(std::forward<Matrix_>(matrix_), this->calcEndX(max_x_), this->calcEndY(max_y_));
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawNormal(std::forward<Matrix_>(matrix_), this->calcEndX(max_x_), this->calcEndY(max_y_), function_);
			}

			//LayerNormal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, this->calcEndX(max_x_), this->calcEndY(max_y_));
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, this->calcEndX(max_x_), this->calcEndY(max_y_), function_);
			}

			//Array
			template<typename Matrix_>
			constexpr bool drawArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawArray(std::forward<Matrix_>(matrix_), this->calcEndX(max_x_), this->calcEndY(max_y_), max_x_);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperatorArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawArray(std::forward<Matrix_>(matrix_), this->calcEndX(max_x_), this->calcEndY(max_y_), max_x_, function_);
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				return this->draw(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& create(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->draw(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& createArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& createOperator(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperator(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& createOperatorArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}


			///// コンストラクタ /////

			using ShapeBase_t::ShapeBase_t;
		};
	}
}

#endif //Included Dungeon Template Library
