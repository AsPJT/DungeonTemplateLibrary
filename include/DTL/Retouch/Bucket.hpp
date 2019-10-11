/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RETOUCH_BUCKET_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RETOUCH_BUCKET_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::retouch::Bucket-(修正クラス)/
#######################################################################################*/

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/IntX.hpp>
#include <DTL/Type/New.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Range/RectBaseWithValuePos.hpp>
#include <DTL/Utility/DrawJagged.hpp>

#include <memory>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace retouch { //"dtl::retouch"名前空間に属する

		struct BucketBuffer {
			::dtl::type::int_fast32 left_x{};
			::dtl::type::int_fast32 right_x{};
			::dtl::type::int_fast32 old_y{};
			::dtl::type::int_fast32 y{};
		};

/*#######################################################################################
	[概要] Bucketとは "Matrixの描画範囲を指定値で足し算する" 機能を持つクラスである。
	[Summary] Bucket is a class that adds the drawing range of Matrix.
#######################################################################################*/
		template<typename Matrix_Var_>
		class Bucket : public ::dtl::range::RectBaseWithValuePos<Bucket<Matrix_Var_>, Matrix_Var_>,
			public ::dtl::utility::DrawJagged<Bucket<Matrix_Var_>, Matrix_Var_> {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using ShapeBase_t = ::dtl::range::RectBaseWithValuePos<Bucket, Matrix_Var_>;
			using DrawBase_t = ::dtl::utility::DrawJagged<Bucket, Matrix_Var_>;

			friend DrawBase_t;

			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void scanLine(Matrix_& matrix_, const Index_Size size_x_, ::std::unique_ptr<BucketBuffer[]>& buffer_, ::dtl::type::size& end_n_, ::dtl::type::int_fast32 left_x_, const ::dtl::type::int_fast32 right_x_, const ::dtl::type::int_fast32 y_, const ::dtl::type::int_fast32 old_y_, const Matrix_Var_ value_) const noexcept {
				while (left_x_ <= right_x_) {

					for (; left_x_ < right_x_; ++left_x_)
						if (matrix_.get(this->start_x + left_x_, this->start_y + y_) == value_) break;
					if (matrix_.get(this->start_x + left_x_, this->start_y + y_) != value_) break;

					buffer_[end_n_].left_x = left_x_;

					for (; left_x_ <= right_x_; ++left_x_)
						if (matrix_.get(this->start_x + left_x_, this->start_y + y_) != value_) break;

					buffer_[end_n_].right_x = left_x_ - 1;
					buffer_[end_n_].y = y_;
					buffer_[end_n_].old_y = old_y_;

					if (++end_n_ == size_x_) end_n_ = 0;
				}
			}


			///// 基本処理 /////

			template<typename Matrix_, typename ...Args_>
			//DTL_VERSIONING_CPP14_CONSTEXPR
			bool drawNormal(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				const Index_Size end_x_{ this->calcEndX(matrix_.getX()) };
				const Index_Size end_y_{ this->calcEndY(matrix_.getY()) };

				const Index_Size size_x_{ end_x_ - this->start_x };
				const Index_Size size_y_{ end_y_ - this->start_y };

				::dtl::type::int_fast32 left_x{};
				::dtl::type::int_fast32 right_x{};
				::dtl::type::int_fast32 old_y{};
				::dtl::type::int_fast32 paint_y{};

				const Matrix_Var_ value{ matrix_.get(this->start_x + this->x_value, this->start_y + this->y_value) };
				if (value == this->draw_value) return true;

				const ::dtl::type::int_fast32 size_max_x{ static_cast<::dtl::type::int_fast32>(size_x_ - 1) };
				const ::dtl::type::int_fast32 size_max_y{ static_cast<::dtl::type::int_fast32>(size_y_ - 1) };

				::std::unique_ptr<BucketBuffer[]> buffer{ DTL_TYPE_NEW BucketBuffer[size_x_] };
				if (!buffer) return false;

				::dtl::type::size start_n{};
				::dtl::type::size end_n{ 1 };
				::dtl::type::int_fast32 left_x_sub_1{};
				::dtl::type::int_fast32 right_x_add_1{};
				buffer[start_n].left_x = buffer[start_n].right_x = static_cast<::dtl::type::int_fast32>(this->x_value);
				buffer[start_n].y = buffer[start_n].old_y = static_cast<::dtl::type::int_fast32>(this->y_value);

				do {
					left_x = buffer[start_n].left_x;
					right_x = buffer[start_n].right_x;
					paint_y = buffer[start_n].y;
					old_y = buffer[start_n].old_y;
					left_x_sub_1 = left_x - 1;
					right_x_add_1 = right_x + 1;
					if (++start_n == size_x_) start_n = 0;

					if (matrix_.get(this->start_x + left_x, this->start_y + paint_y) != value) continue;

					while (right_x < size_max_x) {
						if (matrix_.get(this->start_x + right_x + 1, this->start_y + paint_y) != value) break;
						++right_x;
					}

					while (left_x > 0) {
						if (matrix_.get(this->start_x + left_x - 1, this->start_y + paint_y) != value) break;
						--left_x;
					}

					for (::dtl::type::int_fast32 i{ left_x }; i <= right_x; ++i)
						matrix_.set(i, paint_y, this->draw_value, args_...);

					if (paint_y - 1 >= 0) {
						if (paint_y - 1 == old_y) {
							this->scanLine(matrix_, size_x_, buffer, end_n, left_x, left_x_sub_1, paint_y - 1, paint_y, value);
							this->scanLine(matrix_, size_x_, buffer, end_n, right_x_add_1, right_x, paint_y - 1, paint_y, value);
						}
						else this->scanLine(matrix_, size_x_, buffer, end_n, left_x, right_x, paint_y - 1, paint_y, value);
					}

					if (paint_y + 1 <= size_max_y) {
						if (paint_y + 1 == old_y) {
							this->scanLine(matrix_, size_x_, buffer, end_n, left_x, left_x_sub_1, paint_y + 1, paint_y, value);
							this->scanLine(matrix_, size_x_, buffer, end_n, right_x_add_1, right_x, paint_y + 1, paint_y, value);
						}
						else this->scanLine(matrix_, size_x_, buffer, end_n, left_x, right_x, paint_y + 1, paint_y, value);
					}

				} while (start_n != end_n);

				return true;
			}

		public:


			///// コンストラクタ (Constructor) /////

			using ShapeBase_t::ShapeBase_t;
		};
	}
}

#endif //Included Dungeon Template Library
