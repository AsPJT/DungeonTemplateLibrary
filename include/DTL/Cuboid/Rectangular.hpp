/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_CUBOID_RECTANGULAR_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_CUBOID_RECTANGULAR_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::cuboid::Rectangular-(立体クラス)/
#######################################################################################*/

#include <array>
#include <vector>
#include <DTL/Base/Struct.hpp>
#include <DTL/Random/MersenneTwister32bit.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Type/SSizeT.hpp>
#include <DTL/Range/RectangularBaseWithValue.hpp>
#include <DTL/Type/Min.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace cuboid { //"dtl::cuboid"名前空間に属する

		template<class Matrix_Var_>
		class Rectangular : public ::dtl::range::RectangularBaseWithValue< ::dtl::cuboid::Rectangular<Matrix_Var_>, Matrix_Var_> {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using ShapeBase_t = ::dtl::range::RectangularBaseWithValue< ::dtl::cuboid::Rectangular<Matrix_Var_>, Matrix_Var_>;

			::std::size_t getLoopMaxValue(const ::std::size_t start_, const ::std::size_t size_, const ::std::size_t msize_) const noexcept {
				return ((size_ <= 0) ? msize_ : DTL_TYPE_MIN(start_ + size_, msize_));
			}

		public:

			template<typename Matrix_>
			bool draw(Matrix_& matrix_) const {
				for ( ::std::size_t z{ this->start_z }, max_z{ this->getLoopMaxValue(this->start_z , this->size_z , matrix_.size()) }; z < max_z; ++z)
					for ( ::std::size_t y{ this->start_y }, max_y{ this->getLoopMaxValue(this->start_y , this->size_y , matrix_[z].size()) }; y < max_y; ++y)
						for ( ::std::size_t x{ this->start_x }, max_x{ this->getLoopMaxValue(this->start_x , this->size_x , matrix_[z][y].size()) }; x < max_x; ++x)
							matrix_[z][y][x] = this->draw_value;
				return true;
			}
			template<typename Matrix_>
			bool draw(Matrix_& matrix_, const ::std::size_t size_x_, const ::std::size_t size_y_, const ::std::size_t size_z_) const {
				const ::std::size_t max_x{ this->getLoopMaxValue(this->start_x , this->size_x , size_x_) };
				const ::std::size_t max_y{ this->getLoopMaxValue(this->start_y , this->size_y , size_y_) };
				const ::std::size_t max_z{ this->getLoopMaxValue(this->start_z , this->size_z , size_z_) };
				if (this->start_x >= max_x || this->start_y >= max_y || this->start_z >= max_z) return false;
				for ( ::std::size_t z{ this->start_z }; z < max_z; ++z)
					for ( ::std::size_t y{ this->start_y }; y < max_y; ++y)
						for ( ::std::size_t x{ this->start_x }; x < max_x; ++x)
							matrix_[z][y][x] = this->draw_value;
				return true;
			}


			///// コンストラクタ (Constructor) /////

			using ShapeBase_t::ShapeBase_t;
		};
	}
}

#endif //Included Dungeon Template Library