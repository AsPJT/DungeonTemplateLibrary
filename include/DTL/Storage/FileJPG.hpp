﻿/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_STORAGE_FILE_JPG_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_STORAGE_FILE_JPG_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::storage::FileJPG-(ストレージクラス)/
#######################################################################################*/

#include <DTL/Workaround/cstdioGets.hpp> //Support Clang 3.4.2

#include <fstream>
#include <string>
#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/New.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Type/UniquePtr.hpp>
#include <DTL/Utility/IsOutputCast.hpp>

#ifndef STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <DTL/ThirdParty/STB/stb_image_write.h>
#endif

namespace dtl {
	inline namespace storage {

/*#######################################################################################
	[概要] FileJPGとは "JPG形式の画像ファイルを出力する" 機能を持つクラスである。
#######################################################################################*/
		template<typename Matrix_Int_, typename UniquePtr_ = DTL_TYPE_UNIQUE_PTR<unsigned char[]>>
		class FileJPG {
		private:


			///// エイリアス /////

			using Index_Size = ::dtl::type::size;



			///// メンバ変数 /////

			Index_Size start_x{};
			Index_Size start_y{};
			Index_Size width{};
			Index_Size height{};
			::std::string str{};
			::dtl::type::size color_num{ 3 };
			int quality{ 100 };


			///// 代入処理 /////

			template<typename Matrix_, typename Function_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				inline void assignSTL(const ::dtl::type::size point_max_x_, UniquePtr_& data_, const Matrix_& matrix_, const Index_Size end_x_, const Index_Size end_y_, Function_&& function_) const noexcept {
				function_(matrix_[end_y_][end_x_], &data_[((end_y_ - this->start_y) * (point_max_x_ - this->start_x) + (end_x_ - this->start_x)) * this->color_num]);
			}
			template<typename Matrix_, typename Function_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				inline void assignArray(const ::dtl::type::size point_max_x_, UniquePtr_ & data_, const Matrix_ & matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Function_ && function_) const noexcept {
				function_(matrix_[end_y_ * max_x_ + end_x_], &data_[((end_y_ - this->start_y) * (point_max_x_ - this->start_x) + (end_x_ - this->start_x)) * this->color_num]);
			}
			template<typename Matrix_, typename Function_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				inline void assignLayer(const ::dtl::type::size point_max_x_, UniquePtr_ & data_, const Matrix_ & matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Function_ && function_) const noexcept {
				function_(matrix_[end_y_][end_x_][layer_], &data_[((end_y_ - this->start_y) * (point_max_x_ - this->start_x) + (end_x_ - this->start_x)) * this->color_num]);
			}

			///// 基本処理 /////

			//Normal
			template<typename Matrix_, typename ...Args_>
				bool writeNormal(const Matrix_ & matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				UniquePtr_ data(DTL_TYPE_NEW unsigned char[(end_x_ - this->start_x) * (end_y_ - this->start_y) * this->color_num]);
				if (!data) return false;
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						this->assignSTL(end_x_, data, matrix_, col, row, args_...);
				::stbi_write_jpg(this->str.c_str(), static_cast<int>(end_x_ - this->start_x), static_cast<int>(end_y_ - this->start_y), static_cast<int>(this->color_num), data.get(), quality);
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
				bool writeLayerNormal(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				UniquePtr_ data(DTL_TYPE_NEW unsigned char[(end_x_ - this->start_x) * (end_y_ - this->start_y) * this->color_num]);
				if (!data) return false;
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						this->assignLayer(end_x_, data, matrix_, layer_, col, row, args_...);
				::stbi_write_jpg(this->str.c_str(), static_cast<int>(end_x_ - this->start_x), static_cast<int>(end_y_ - this->start_y), static_cast<int>(this->color_num), data.get(), quality);
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
				bool writeArray(const Matrix_ & matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Args_ && ... args_) const noexcept {
				UniquePtr_ data(DTL_TYPE_NEW unsigned char[(end_x_ - this->start_x) * (end_y_ - this->start_y) * this->color_num]);
				if (!data) return false;
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						this->assignArray(end_x_, data, matrix_, col, row, max_x_, args_...);
				::stbi_write_jpg(this->str.c_str(), static_cast<int>(end_x_ - this->start_x), static_cast<int>(end_y_ - this->start_y), static_cast<int>(this->color_num), data.get(), quality);
				return true;
			}

		public:


			///// 情報取得 /////

			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Index_Size getPointX() const noexcept {
				return this->start_x;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Index_Size getPointY() const noexcept {
				return this->start_y;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Index_Size getWidth() const noexcept {
				return this->width;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Index_Size getHeight() const noexcept {
				return this->height;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				::std::string getString() const noexcept {
				return this->str;
			}


			///// 生成呼び出し /////

			//STL
			template<typename Matrix_, typename Function_>
			constexpr bool write(const Matrix_ & matrix_, Function_ && function_) const noexcept {
				return this->writeNormal(matrix_, (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//LayerSTL
			template<typename Matrix_, typename Function_>
			constexpr bool write(const Matrix_ & matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
				return this->writeLayerNormal(matrix_, layer_, (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//Normal
			template<typename Matrix_, typename Function_>
			constexpr bool write(const Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->writeNormal(matrix_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//LayerNormal
			template<typename Matrix_, typename Function_>
			constexpr bool write(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->writeLayerNormal(matrix_, layer_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//Array
			template<typename Matrix_, typename Function_>
			constexpr bool writeArray(const Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->writeArray(matrix_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, max_x_, function_);
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(const Matrix_ & matrix_, Args_ && ... args_) const noexcept {
				return this->write(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& create(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->write(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& createArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->writeArray(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}


			///// 消去 /////

			//始点座標Xを初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				FileJPG& clearPointX() noexcept {
				this->start_x = 0;
				return *this;
			}
			//始点座標Yを初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				FileJPG& clearPointY() noexcept {
				this->start_y = 0;
				return *this;
			}
			//範囲の大きさ(X軸方向)を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				FileJPG& clearWidth() noexcept {
				this->width = 0;
				return *this;
			}
			//範囲の大きさ(Y軸方向)を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				FileJPG& clearHeight() noexcept {
				this->height = 0;
				return *this;
			}
			//始点座標(X,Y)を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				FileJPG& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
			//描画範囲を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				FileJPG& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			//全ての値を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				FileJPG& clear() noexcept {
				this->clearRange();
				return *this;
			}


			///// 代入 /////

			DTL_VERSIONING_CPP14_CONSTEXPR
				FileJPG& setPointX(const Index_Size end_x_) noexcept {
				this->start_x = end_x_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				FileJPG& setPointY(const Index_Size end_y_) noexcept {
				this->start_y = end_y_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				FileJPG& setWidth(const Index_Size width_) noexcept {
				this->width = width_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				FileJPG& setHeight(const Index_Size height_) noexcept {
				this->height = height_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				FileJPG& setPoint(const Index_Size point_) noexcept {
				this->start_x = point_;
				this->start_y = point_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				FileJPG& setPoint(const Index_Size end_x_, const Index_Size end_y_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				FileJPG& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size length_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				this->width = length_;
				this->height = length_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				FileJPG& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				this->width = width_;
				this->height = height_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				FileJPG& setRange(const ::dtl::base::MatrixRange & matrix_range_) noexcept {
				this->start_x = matrix_range_.x;
				this->start_y = matrix_range_.y;
				this->width = matrix_range_.w;
				this->height = matrix_range_.h;
				return *this;
			}


			///// コンストラクタ /////

			constexpr FileJPG() = default;
			constexpr explicit FileJPG(const ::std::string & write_value_) noexcept
				:str(write_value_) {}
			constexpr explicit FileJPG(const ::std::string & write_value_, const ::dtl::type::size color_num_) noexcept
				:str(write_value_), color_num(color_num_) {}
			constexpr explicit FileJPG(const ::std::string & write_value_, const ::dtl::type::size color_num_, const int quality_) noexcept
				:str(write_value_), color_num(color_num_), quality(quality_) {}

			constexpr explicit FileJPG(const ::dtl::base::MatrixRange & matrix_range_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}
			constexpr explicit FileJPG(const ::dtl::base::MatrixRange & matrix_range_, const ::std::string & write_value_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				str(write_value_) {}
			constexpr explicit FileJPG(const ::dtl::base::MatrixRange & matrix_range_, const ::std::string & write_value_, const ::dtl::type::size color_num_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				str(write_value_), color_num(color_num_) {}
			constexpr explicit FileJPG(const ::dtl::base::MatrixRange & matrix_range_, const ::std::string & write_value_, const ::dtl::type::size color_num_, const int quality_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				str(write_value_), color_num(color_num_), quality(quality_) {}

			constexpr explicit FileJPG(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_) {}
			constexpr explicit FileJPG(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_, const ::std::string & write_value_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_),
				str(write_value_) {}
			constexpr explicit FileJPG(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_, const ::std::string & write_value_, const ::dtl::type::size color_num_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_),
				str(write_value_), color_num(color_num_) {}
			constexpr explicit FileJPG(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_, const ::std::string & write_value_, const ::dtl::type::size color_num_, const int quality_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_),
				str(write_value_), color_num(color_num_), quality(quality_) {}
		};
	}
}

#endif //Included Dungeon Template Library