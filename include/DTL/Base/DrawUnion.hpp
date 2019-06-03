/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_BASE_DRAW_UNION_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_BASE_DRAW_UNION_HPP

#include <DTL/Type/SizeT.hpp>

namespace dtl {
	inline namespace base { //"dtl::base"名前空間に属する

		union BaseDrawMatrixType {
			::dtl::type::size layer;
			::dtl::type::size max_x;

			BaseDrawMatrixType() = default;
			BaseDrawMatrixType(const ::dtl::type::size layer_) :layer(layer_) {}
		};

		enum eDrawMatrixType {
			draw_type_empty,
			draw_type_normal,
			draw_type_array,
			draw_type_layer
		};

		struct DrawMatrixType {
			::dtl::type::size type{};
			BaseDrawMatrixType bdmt{};

			DrawMatrixType() = default;
			DrawMatrixType(const ::dtl::type::size type_) :type(type_) {}
			DrawMatrixType(const ::dtl::type::size type_, const ::dtl::type::size value_) :type(type_), bdmt(value_) {}
		};

		template<typename Matrix_Int_>
		class DrawMatrixNormal {
		private:

			DrawMatrixType drawMatrixType{};

		public:

			template<typename Matrix_>
			void set(Matrix_& matrix_, const ::dtl::type::size row_, const ::dtl::type::size col_, const Matrix_Int_& value_) const noexcept {
				matrix_[row_][col_] = value_;
			}

			template<typename Matrix_>
			Matrix_Int_ get(const Matrix_& matrix_, const ::dtl::type::size row_, const ::dtl::type::size col_) const noexcept {
				return matrix_[row_][col_];
			}

			DrawMatrixNormal() :drawMatrixType(draw_type_normal) {}
			DrawMatrixNormal(const ::dtl::type::size value_) :drawMatrixType(draw_type_normal, value_) {}
		};

		template<typename Matrix_Int_>
		class DrawMatrixArray {
		private:

			DrawMatrixType drawMatrixType{};

		public:

			template<typename Matrix_>
			void set(Matrix_& matrix_, const ::dtl::type::size row_, const ::dtl::type::size col_, const Matrix_Int_& value_) const noexcept {
				matrix_[row_ * drawMatrixType.bdmt.max_x + col_] = value_;
			}

			template<typename Matrix_>
			Matrix_Int_ get(const Matrix_& matrix_, const ::dtl::type::size row_, const ::dtl::type::size col_) const noexcept {
				return matrix_[row_ * drawMatrixType.bdmt.max_x + col_];
			}

			DrawMatrixArray() :drawMatrixType(draw_type_array, 0) {}
			DrawMatrixArray(const ::dtl::type::size value_) :drawMatrixType(draw_type_array, value_) {}
		};

		template<typename Matrix_Int_>
		class DrawMatrixLayer {
		private:

			DrawMatrixType drawMatrixType{};

		public:

			template<typename Matrix_>
			void set(Matrix_& matrix_, const ::dtl::type::size row_, const ::dtl::type::size col_, const Matrix_Int_& value_) const noexcept {
				matrix_[row_][col_][drawMatrixType.bdmt.layer] = value_;
			}

			template<typename Matrix_>
			Matrix_Int_ get(const Matrix_& matrix_, const ::dtl::type::size row_, const ::dtl::type::size col_) const noexcept {
				return matrix_[row_][col_][drawMatrixType.bdmt.layer];
			}

			DrawMatrixLayer() :drawMatrixType(draw_type_layer, 0) {}
			DrawMatrixLayer(const ::dtl::type::size value_) :drawMatrixType(draw_type_layer, value_) {}
		};

	}
}

#endif //Included Dungeon Template Library