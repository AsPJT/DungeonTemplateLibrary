/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_STORAGE_FILE_TERRAIN_OBJ_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_STORAGE_FILE_TERRAIN_OBJ_HPP

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <fstream>
#include <string>
#include <utility>
#include <Base/Struct.hpp>
#include <Macros/constexpr.hpp>
#include <Macros/nodiscard.hpp>
#include <Type/SizeT.hpp>
#include <Utility/IsOutputCast.hpp>

namespace dtl {
	inline namespace storage {

		//マスを指定した数値で埋める
		template<typename Matrix_Int_, typename Value_Int_ = Matrix_Int_, typename Ofstream_ = std::ofstream>
		class FileTerrainOBJ {
		private:


			///// エイリアス /////

			using Index_Size = dtl::type::size;
			


			///// メンバ変数 /////

			Index_Size start_x{};
			Index_Size start_y{};
			Index_Size width{};
			Index_Size height{};
			std::string str{};
			Value_Int_ value_x{ 1 };
			Value_Int_ value_y{ 1 };
			Value_Int_ value_z{ 1 };


			///// 出力処理 /////

			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void mountain(const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Ofstream_& ofs_) const noexcept {
				ofs_ << "f " << (end_y_ * max_x_ + end_x_) << " " << ((end_y_ - 1) * max_x_ + end_x_) << " " << ((end_y_ - 1) * max_x_ + (end_x_ - 1)) << '\n';
				ofs_ << "f " << (end_y_ * max_x_ + (end_x_ - 1)) << " " << (end_y_ * max_x_ + end_x_) << " " << ((end_y_ - 1) * max_x_ + (end_x_ - 1)) << '\n';
			}

			template<typename Matrix_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void baseSTL(const Matrix_ & matrix_, const Index_Size end_x_, const Index_Size end_y_, Ofstream_ & ofs_) const noexcept {
				ofs_ << "v " << end_x_ * value_x << " " << ((dtl::utility::isOutputCast<Matrix_Int_>()) ? static_cast<int>(matrix_[end_y_][end_x_]) : matrix_[end_y_][end_x_]) * value_z << " " << end_y_ * value_y << '\n';
			}
			template<typename Matrix_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void baseArray(const Matrix_ & matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Ofstream_ & ofs_) const noexcept {
				ofs_ << "v " << end_x_ * value_x << " " << ((dtl::utility::isOutputCast<Matrix_Int_>()) ? static_cast<int>(matrix_[end_y_ * max_x_ + end_x_]) : matrix_[end_y_ * max_x_ + end_x_]) * value_z << " " << end_y_ * value_y << '\n';
			}
			template<typename Matrix_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void baseLayer(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Ofstream_ & ofs_) const noexcept {
				ofs_ << "v " << end_x_ * value_x << " " << ((dtl::utility::isOutputCast<Matrix_Int_>()) ? static_cast<int>(matrix_[end_y_][end_x_][layer_]) : matrix_[end_y_][end_x_][layer_]) * value_z << " " << end_y_ * value_y << '\n';
			}


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename ...Args_>
			bool writeSTL(const Matrix_ & matrix_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				Ofstream_ ofs(str);
				if (ofs.fail()) return false;
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < matrix_[row].size(); ++col)
						this->baseSTL(matrix_, col, row, ofs, args_...);

				for (dtl::type::size row{ this->start_y + 1 }; row < end_y_; ++row)
					for (dtl::type::size col{ start_x + 2 }; col <= matrix_[row].size(); ++col)
						this->mountain(col, row, matrix_[row].size(), ofs);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			bool writeWidthSTL(const Matrix_ & matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				Ofstream_ ofs(str);
				if (ofs.fail()) return false;
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < matrix_[row].size() && col < end_x_; ++col)
						this->baseSTL(matrix_, col, row, ofs, args_...);

				for (dtl::type::size row{ this->start_y + 1 }; row < end_y_; ++row)
					for (dtl::type::size col{ start_x + 2 }; col < matrix_[row].size() && col < end_x_; ++col)
						this->mountain(col, row, (matrix_[row].size() < end_x_) ? matrix_[row].size() : end_x_, ofs);
				return true;
			}

			//LayerSTL
			template<typename Matrix_, typename ...Args_>
			bool writeLayerSTL(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				Ofstream_ ofs(str);
				if (ofs.fail()) return false;
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < matrix_[row].size(); ++col)
						this->baseLayer(matrix_, layer_, col, row, ofs, args_...);

				for (dtl::type::size row{ this->start_y + 1 }; row < end_y_; ++row)
					for (dtl::type::size col{ start_x + 2 }; col <= matrix_[row].size(); ++col)
						this->mountain(col, row, matrix_[row].size(), ofs);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			bool writeLayerWidthSTL(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				Ofstream_ ofs(str);
				if (ofs.fail()) return false;
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < matrix_[row].size() && col < end_x_; ++col)
						this->baseLayer(matrix_, layer_, col, row, ofs, args_...);

				for (dtl::type::size row{ this->start_y + 1 }; row < end_y_; ++row)
					for (dtl::type::size col{ start_x + 2 }; col < matrix_[row].size() && col < end_x_; ++col)
						this->mountain(col, row, (matrix_[row].size() < end_x_) ? matrix_[row].size() : end_x_, ofs);
				return true;
			}

			//Normal
			template<typename Matrix_, typename ...Args_>
			bool writeNormal(const Matrix_ & matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				Ofstream_ ofs(str);
				if (ofs.fail()) return false;
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						this->baseSTL(matrix_, col, row, ofs, args_...);

				for (dtl::type::size row{ this->start_y + 1 }; row < end_y_; ++row)
					for (dtl::type::size col{ start_x + 2 }; col <= end_x_; ++col)
						this->mountain(col, row, end_x_, ofs);
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
			bool writeLayerNormal(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				Ofstream_ ofs(str);
				if (ofs.fail()) return false;
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						this->baseLayer(matrix_, layer_, col, row, ofs, args_...);

				for (dtl::type::size row{ this->start_y + 1 }; row < end_y_; ++row)
					for (dtl::type::size col{ start_x + 2 }; col <= end_x_; ++col)
						this->mountain(col, row, end_x_, ofs);
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			bool writeArray(const Matrix_ & matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Args_ && ... args_) const noexcept {
				Ofstream_ ofs(str);
				if (ofs.fail()) return false;
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						this->baseArray(matrix_, col, row, max_x_, ofs, args_...);

				for (dtl::type::size row{ this->start_y + 1 }; row < end_y_; ++row)
					for (dtl::type::size col{ start_x + 2 }; col <= end_x_; ++col)
						this->mountain(col, row, end_x_, ofs);
				return true;
			}

		public:


			///// 情報取得 /////

			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr Index_Size getPointX() const noexcept {
				return this->start_x;
			}
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr Index_Size getPointY() const noexcept {
				return this->start_y;
			}
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr Index_Size getWidth() const noexcept {
				return this->width;
			}
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr Index_Size getHeight() const noexcept {
				return this->height;
			}
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			std::string getString() const noexcept {
				return this->str;
			}


			///// 生成呼び出し /////

			//STL
			template<typename Matrix_>
			constexpr bool write(const Matrix_ & matrix_) const noexcept {
				return (this->width == 0) ? this->writeSTL(matrix_, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height) : this->writeWidthSTL(matrix_, this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool writeOperator(const Matrix_ & matrix_, Function_ && function_) const noexcept {
				return (this->width == 0) ? this->writeSTL(matrix_, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_) : this->writeWidthSTL(matrix_, this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//LayerSTL
			template<typename Matrix_>
			constexpr bool write(const Matrix_ & matrix_, const Index_Size layer_) const noexcept {
				return (this->width == 0) ? this->writeLayerSTL(matrix_, layer_, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height) : this->writeLayerWidthSTL(matrix_, layer_, this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool writeOperator(const Matrix_ & matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
				return (this->width == 0) ? this->writeLayerSTL(matrix_, layer_, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_) : this->writeLayerWidthSTL(matrix_, layer_, this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//Normal
			template<typename Matrix_>
			constexpr bool write(const Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->writeNormal(matrix_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool writeOperator(const Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->writeNormal(matrix_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//LayerNormal
			template<typename Matrix_>
			constexpr bool write(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->writeLayerNormal(matrix_, layer_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool writeOperator(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->writeLayerNormal(matrix_, layer_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//Array
			template<typename Matrix_>
			constexpr bool writeArray(const Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->writeArray(matrix_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, max_x_);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool writeOperatorArray(const Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->writeArray(matrix_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, max_x_, function_);
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(const Matrix_ & matrix_, Args_ && ... args_) const noexcept {
				return this->write(matrix_, std::forward<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& create(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->write(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& createArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->writeArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& createOperator(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->writeOperator(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& createOperatorArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->writeOperatorArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}


			///// 消去 /////

			//始点座標Xを初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				FileTerrainOBJ& clearPointX() noexcept {
				this->start_x = 0;
				return *this;
			}
			//始点座標Yを初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				FileTerrainOBJ& clearPointY() noexcept {
				this->start_y = 0;
				return *this;
			}
			//範囲の大きさ(X軸方向)を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				FileTerrainOBJ& clearWidth() noexcept {
				this->width = 0;
				return *this;
			}
			//範囲の大きさ(Y軸方向)を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				FileTerrainOBJ& clearHeight() noexcept {
				this->height = 0;
				return *this;
			}
			//始点座標(X,Y)を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				FileTerrainOBJ& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
			//描画範囲を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				FileTerrainOBJ& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			//全ての値を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				FileTerrainOBJ& clear() noexcept {
				this->clearRange();
				return *this;
			}


			///// 代入 /////

			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				FileTerrainOBJ& setPointX(const Index_Size end_x_) noexcept {
				this->start_x = end_x_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				FileTerrainOBJ& setPointY(const Index_Size end_y_) noexcept {
				this->start_y = end_y_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				FileTerrainOBJ& setWidth(const Index_Size width_) noexcept {
				this->width = width_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				FileTerrainOBJ& setHeight(const Index_Size height_) noexcept {
				this->height = height_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				FileTerrainOBJ& setPoint(const Index_Size point_) noexcept {
				this->start_x = point_;
				this->start_y = point_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				FileTerrainOBJ& setPoint(const Index_Size end_x_, const Index_Size end_y_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				FileTerrainOBJ& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size length_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				this->width = length_;
				this->height = length_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				FileTerrainOBJ& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				this->width = width_;
				this->height = height_;
				return *this;
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				FileTerrainOBJ& setRange(const dtl::base::MatrixRange & matrix_range_) noexcept {
				this->start_x = matrix_range_.x;
				this->start_y = matrix_range_.y;
				this->width = matrix_range_.w;
				this->height = matrix_range_.h;
				return *this;
			}


			///// コンストラクタ /////

			constexpr FileTerrainOBJ() noexcept = default;
			constexpr explicit FileTerrainOBJ(const std::string & write_value_) noexcept
				:str(write_value_) {}
			constexpr explicit FileTerrainOBJ(const dtl::base::MatrixRange & matrix_range_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}
			constexpr explicit FileTerrainOBJ(const dtl::base::MatrixRange & matrix_range_, const std::string & write_value_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				str(write_value_) {}

			constexpr explicit FileTerrainOBJ(const std::string & write_value_, const Value_Int_ & value_x_, const Value_Int_ & value_y_, const Value_Int_ & value_z_) noexcept
				:str(write_value_), value_x(value_x_), value_y(value_y_), value_z(value_z_) {}
			constexpr explicit FileTerrainOBJ(const dtl::base::MatrixRange & matrix_range_, const Value_Int_ & value_x_, const Value_Int_ & value_y_, const Value_Int_ & value_z_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				value_x(value_x_), value_y(value_y_), value_z(value_z_) {}
			constexpr explicit FileTerrainOBJ(const dtl::base::MatrixRange & matrix_range_, const std::string & write_value_, const Value_Int_ & value_x_, const Value_Int_ & value_y_, const Value_Int_ & value_z_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				str(write_value_),
				value_x(value_x_), value_y(value_y_), value_z(value_z_) {}

			constexpr explicit FileTerrainOBJ(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_) {}
			constexpr explicit FileTerrainOBJ(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_, const std::string & write_value_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_),
				str(write_value_) {}

			constexpr explicit FileTerrainOBJ(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_, const Value_Int_ & value_x_, const Value_Int_ & value_y_, const Value_Int_ & value_z_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_),
				value_x(value_x_), value_y(value_y_), value_z(value_z_) {}
			constexpr explicit FileTerrainOBJ(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_, const std::string & write_value_, const Value_Int_ & value_x_, const Value_Int_ & value_y_, const Value_Int_ & value_z_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_),
				str(write_value_),
				value_x(value_x_), value_y(value_y_), value_z(value_z_) {}
		};
	}
}

#endif //Included Dungeon Template Library