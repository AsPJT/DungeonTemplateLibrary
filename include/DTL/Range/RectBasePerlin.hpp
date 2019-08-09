/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANGE_RECT_BASE_WITH_PERLIN_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANGE_RECT_BASE_WITH_PERLIN_HPP

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Range/BasicRect.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace range { //"dtl::range"名前空間に属する

		//四角形クラス
		template<typename Derived_, typename Matrix_Var_>
		class RectBasePerlin : public ::dtl::range::BasicRect<Derived_> {
		private:

			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using RectBase_t = ::dtl::range::BasicRect<Derived_>;


		protected:


			///// メンバ変数 (Member Variable) /////

			double frequency{};
			Index_Size octaves{};
			Matrix_Var_ min_height{};
			Matrix_Var_ max_height{};


		public:


			///// メンバ変数の値を取得 (Get Value) /////

			DTL_VERSIONING_CPP17_NODISCARD
				constexpr double getValue() const noexcept {
				return this->frequency;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr double getFrequency() const noexcept {
				return this->frequency;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Index_Size getOctaves() const noexcept {
				return this->octaves;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getMinHeight() const noexcept {
				return this->min_height;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getMaxHeight() const noexcept {
				return this->max_height;
			}

			///// 消去 (Clear) /////


/*#######################################################################################
	[概要] 塗り値を初期値に戻す(描画値を消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing value to the initial value (deletes the drawing value).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearValue() noexcept {
				this->frequency = 0.0;
				this->octaves = 0;
				const Matrix_Var_ clear_max_height{};
				this->max_height = clear_max_height;
				const Matrix_Var_ clear_min_height{};
				this->min_height = clear_min_height;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearFrequency() noexcept {
				this->frequency = 0.0;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearOctaves() noexcept {
				this->octaves = 0;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearMinHeight() noexcept {
				const Matrix_Var_ clear_min_height{};
				this->min_height = clear_min_height;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearMaxHeight() noexcept {
				const Matrix_Var_ clear_max_height{};
				this->max_height = clear_max_height;
				return static_cast<Derived_&>(*this);
			}

			/*#######################################################################################
				[概要] 全ての値を初期値に戻す。
				[戻り値] 戻り値の型は 当クラスの参照値 である。
				[Summary] Reset all values to their initial values.
				[Return value] The return type is a reference value of this class.
			#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clear() noexcept {
				this->clearRange();
				this->clearValue();
				return static_cast<Derived_&>(*this);
			}


			///// 代入 /////

			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setValue(const double frequency_) noexcept {
				this->frequency = frequency_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setFrequency(const double frequency_) noexcept {
				this->frequency = frequency_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setOctaves(const Index_Size octaves_) noexcept {
				this->octaves = octaves_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setMinHeight(const Matrix_Var_& min_height_) noexcept {
				this->min_height = min_height_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setMaxHeight(const Matrix_Var_& max_height_) noexcept {
				this->max_height = max_height_;
				return static_cast<Derived_&>(*this);
			}


			///// コンストラクタ (Constructor) /////

			RectBasePerlin() = default;
			constexpr explicit RectBasePerlin(const ::dtl::base::MatrixRange& matrix_range_) noexcept
				:RectBase_t(matrix_range_) {}
			constexpr RectBasePerlin(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_) noexcept
				:RectBase_t(start_x_, start_y_, width_, height_) {}

			constexpr explicit RectBasePerlin(const double frequency_) noexcept
				:frequency(frequency_) {}
			constexpr RectBasePerlin(const double frequency_, const Index_Size octaves_) noexcept
				:frequency(frequency_), octaves(octaves_) {}
			constexpr RectBasePerlin(const double frequency_, const Index_Size octaves_, const Matrix_Var_& max_height_) noexcept
				:frequency(frequency_), octaves(octaves_), max_height(max_height_) {}
			constexpr RectBasePerlin(const double frequency_, const Index_Size octaves_, const Matrix_Var_& max_height_, const Matrix_Var_& min_height_) noexcept
				:frequency(frequency_), octaves(octaves_), min_height(min_height_), max_height(max_height_) {}

			constexpr RectBasePerlin(const ::dtl::base::MatrixRange& matrix_range_, const double frequency_) noexcept
				:RectBase_t(matrix_range_),
				frequency(frequency_) {}
			constexpr RectBasePerlin(const ::dtl::base::MatrixRange& matrix_range_, const double frequency_, const Index_Size octaves_) noexcept
				:RectBase_t(matrix_range_),
				frequency(frequency_), octaves(octaves_) {}
			constexpr RectBasePerlin(const ::dtl::base::MatrixRange& matrix_range_, const double frequency_, const Index_Size octaves_, const Matrix_Var_& max_height_) noexcept
				:RectBase_t(matrix_range_),
				frequency(frequency_), octaves(octaves_), max_height(max_height_) {}
			constexpr RectBasePerlin(const ::dtl::base::MatrixRange& matrix_range_, const double frequency_, const Index_Size octaves_, const Matrix_Var_& max_height_, const Matrix_Var_& min_height_) noexcept
				:RectBase_t(matrix_range_),
				frequency(frequency_), octaves(octaves_), min_height(min_height_), max_height(max_height_) {}

			constexpr RectBasePerlin(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_, const double frequency_) noexcept
				:RectBase_t(start_x_, start_y_, width_, height_),
				frequency(frequency_) {}
			constexpr RectBasePerlin(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_, const double frequency_, const Index_Size octaves_) noexcept
				:RectBase_t(start_x_, start_y_, width_, height_),
				frequency(frequency_), octaves(octaves_) {}
			constexpr RectBasePerlin(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_, const double frequency_, const Index_Size octaves_, const Matrix_Var_& max_height_) noexcept
				:RectBase_t(start_x_, start_y_, width_, height_),
				frequency(frequency_), octaves(octaves_), max_height(max_height_) {}
			constexpr RectBasePerlin(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_, const double frequency_, const Index_Size octaves_, const Matrix_Var_& max_height_, const Matrix_Var_& min_height_) noexcept
				:RectBase_t(start_x_, start_y_, width_, height_),
				frequency(frequency_), octaves(octaves_), min_height(min_height_), max_height(max_height_) {}
		};
	}
}

#endif //Included Dungeon Template Library
