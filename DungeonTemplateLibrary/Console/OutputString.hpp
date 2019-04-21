/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_OUTPUT_STRING
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_OUTPUT_STRING

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <iostream>
#include <vector>
#include <string>

namespace dtl {
	inline namespace console {

		//四角形の生成
		template<typename Matrix_Int_, typename OutputStringName_ = std::string>
		class OutputString {
		private:


			///// エイリアス /////

			using Index_Size = std::size_t;
			using PairSize = std::pair<Index_Size, Index_Size>;


			///// メンバ変数 /////

			Index_Size point_x{};
			Index_Size point_y{};
			Index_Size width{};
			Index_Size height{};
			std::vector<OutputStringName_> string_vector{};


			//

			constexpr void string_String() const noexcept {}
			template<typename ...Args_>
			constexpr void string_String(const OutputStringName_& first_, const Args_& ... args_) noexcept {
				string_vector.emplace_back(first_);
				this->string_String(args_...);
			}


			///// 代入処理 /////

			template<typename Matrix_>
			[[nodiscard]] constexpr inline std::size_t outputSTL(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				return static_cast<std::size_t>(matrix_[point_y_][point_x_]);
			}
			template<typename Matrix_>
			[[nodiscard]] constexpr inline std::size_t outputArray(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
				return static_cast<std::size_t>(matrix_[point_y_ * max_x_ + point_x_]);
			}
			template<typename Matrix_>
			[[nodiscard]] constexpr inline std::size_t outputLayer(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				return static_cast<std::size_t>(matrix_[point_y_][point_x_][layer_]);
			}


			///// 基本処理 /////

			//STL
			template<typename Matrix_>
			bool drawSTL(const Matrix_ & matrix_, const Index_Size point_y_) const noexcept {
				for (Index_Size row{ point_y }; row < point_y_; ++row) {
					for (Index_Size col{ point_x }; col < matrix_[row].size(); ++col) {
						if (this->outputSTL(matrix_, col, row) >= string_vector.size()) continue;
						std::cout << string_vector[this->outputSTL(matrix_, col, row)];
					}
					std::cout << '\n';
				}
				return true;
			}
			template<typename Matrix_>
			bool drawWidthSTL(const Matrix_ & matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				for (Index_Size row{ point_y }; row < point_y_; ++row) {
					for (Index_Size col{ point_x }; col < matrix_[row].size() && col < point_x_; ++col) {
						if (this->outputSTL(matrix_, col, row) >= string_vector.size()) continue;
						std::cout << string_vector[this->outputSTL(matrix_, col, row)];
					}
					std::cout << '\n';
				}
				return true;
			}

			//LayerSTL
			template<typename Matrix_>
			bool drawLayerSTL(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size point_y_) const noexcept {
				for (Index_Size row{ point_y }; row < point_y_; ++row) {
					for (Index_Size col{ point_x }; col < matrix_[row].size(); ++col) {
						if (this->outputLayer(matrix_, layer_, col, row) >= string_vector.size()) continue;
						std::cout << string_vector[this->outputLayer(matrix_, layer_, col, row)];
					}
					std::cout << '\n';
				}
				return true;
			}
			template<typename Matrix_>
			bool drawLayerWidthSTL(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				for (Index_Size row{ point_y }; row < point_y_; ++row) {
					for (Index_Size col{ point_x }; col < matrix_[row].size() && col < point_x_; ++col) {
						if (this->outputLayer(matrix_, layer_, col, row) >= string_vector.size()) continue;
						std::cout << string_vector[this->outputLayer(matrix_, layer_, col, row)];
					}
					std::cout << '\n';
				}
				return true;
			}

			//Normal
			template<typename Matrix_>
			bool drawNormal(const Matrix_ & matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				for (Index_Size row{ point_y }; row < point_y_; ++row) {
					for (Index_Size col{ point_x }; col < point_x_; ++col) {
						if (this->outputSTL(matrix_, col, row) >= string_vector.size()) continue;
						std::cout << string_vector[this->outputSTL(matrix_, col, row)];
					}
					std::cout << '\n';
				}
				return true;
			}

			//LayerNormal
			template<typename Matrix_>
			bool drawLayerNormal(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				for (Index_Size row{ point_y }; row < point_y_; ++row) {
					for (Index_Size col{ point_x }; col < point_x_; ++col) {
						if (this->outputLayer(matrix_, layer_, col, row) >= string_vector.size()) continue;
						std::cout << string_vector[this->outputLayer(matrix_, layer_, col, row)];
					}
					std::cout << '\n';
				}
				return true;
			}

			//Array
			template<typename Matrix_>
			bool drawArray(const Matrix_ & matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
				for (Index_Size row{ point_y }; row < point_y_; ++row) {
					for (Index_Size col{ point_x }; col < point_x_; ++col) {
						if (this->outputArray(matrix_, col, row, max_x_) >= string_vector.size()) continue;
						std::cout << string_vector[this->outputArray(matrix_, col, row, max_x_)];
					}
					std::cout << '\n';
				}
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


			///// 生成呼び出し /////

			//STL
			template<typename Matrix_>
			bool draw(const Matrix_ & matrix_) const noexcept {
				return (width == 0) ? this->drawSTL(matrix_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height) : this->drawWidthSTL(matrix_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height);
			}

			//LayerSTL
			template<typename Matrix_>
			bool draw(const Matrix_ & matrix_, const Index_Size layer_) const noexcept {
				return (width == 0) ? this->drawLayerSTL(matrix_, layer_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height) : this->drawLayerWidthSTL(matrix_, layer_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height);
			}

			//Normal
			template<typename Matrix_>
			bool draw(const Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawNormal(matrix_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height);
			}

			//LayerNormal
			template<typename Matrix_>
			bool draw(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawLayerNormal(matrix_, layer_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height);
			}

			//Array
			template<typename Matrix_>
			bool drawArray(const Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawArray(matrix_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, max_x_);
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr auto operator()(const Matrix_& matrix_, Args_&& ... args_) const noexcept {
				return this->draw(matrix_, std::forward<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

			template<typename Matrix_, typename ...Args_>
			constexpr auto create(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->draw(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr auto createArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}


			///// 消去 /////

			//始点座標Xを初期値に戻す
			constexpr auto clearPointX() noexcept {
				this->point_x = 0;
				return *this;
			}
			//始点座標Yを初期値に戻す
			constexpr auto clearPointY() noexcept {
				this->point_y = 0;
				return *this;
			}
			//範囲の大きさ(X軸方向)を初期値に戻す
			constexpr auto clearWidth() noexcept {
				this->width = 0;
				return *this;
			}
			//範囲の大きさ(Y軸方向)を初期値に戻す
			constexpr auto clearHeight() noexcept {
				this->height = 0;
				return *this;
			}
			//始点座標(X,Y)を初期値に戻す
			constexpr auto clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
			//描画範囲を初期値に戻す
			constexpr auto clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			//全ての値を初期値に戻す
			constexpr auto clear() noexcept {
				this->clearRange();
				return *this;
			}


			///// 代入 /////

			constexpr auto setPointX(const Index_Size point_x_) noexcept {
				this->point_x = point_x_;
				return *this;
			}
			constexpr auto setPointY(const Index_Size point_y_) noexcept {
				this->point_y = point_y_;
				return *this;
			}
			constexpr auto setWidth(const Index_Size width_) noexcept {
				this->width = width_;
				return *this;
			}
			constexpr auto setHeight(const Index_Size height_) noexcept {
				this->height = height_;
				return *this;
			}
			constexpr auto setPoint(const Index_Size point_) noexcept {
				this->point_x = point_;
				this->point_y = point_;
				return *this;
			}
			constexpr auto setPoint(const Index_Size point_x_, const Index_Size point_y_) noexcept {
				this->point_x = point_x_;
				this->point_y = point_y_;
				return *this;
			}
			constexpr auto setRange(const Index_Size point_x_, const Index_Size point_y_, const Index_Size length_) noexcept {
				this->point_x = point_x_;
				this->point_y = point_y_;
				this->width = length_;
				this->height = length_;
				return *this;
			}
			constexpr auto setRange(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->point_x = point_x_;
				this->point_y = point_y_;
				this->width = width_;
				this->height = height_;
				return *this;
			}
			constexpr auto setRange(const dtl::base::MatrixRange& matrix_range_) noexcept {
				this->point_x = matrix_range_.x;
				this->point_y = matrix_range_.y;
				this->width = matrix_range_.w;
				this->height = matrix_range_.h;
				return *this;
			}


			///// コンストラクタ /////

			template<typename ...Args_>
			explicit OutputString(const OutputStringName_ & first_, const Args_ & ... args_) noexcept {
				this->string_String(first_, args_...);
			}
			template<typename ...Args_>
			explicit OutputString(const PairSize & length_, const OutputStringName_ & first_, const Args_ & ... args_) noexcept
				:width(length_.first), height(length_.second) {
				this->string_String(first_, std::forward<Args_>(args_)...);
			}
			template<typename ...Args_>
			explicit OutputString(const PairSize & position_, const PairSize & length_, const OutputStringName_ & first_, const Args_ & ... args_) noexcept
				:point_x(position_.first), point_y(position_.second),
				width(length_.first), height(length_.second) {
				this->string_String(first_, args_...);
			}
			template<typename ...Args_>
			explicit OutputString(const Index_Size width_, const Index_Size height_, const OutputStringName_ & first_, const Args_ & ... args_) noexcept
				:width(width_), height(height_) {
				this->string_String(first_, std::forward<Args_>(args_)...);
			}
			template<typename ...Args_>
			explicit OutputString(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const OutputStringName_ & first_, const Args_ & ... args_) noexcept
				:point_x(point_x_), point_y(point_y_),
				width(width_), height(height_) {
				this->string_String(first_, std::forward<Args_>(args_)...);
			}
		};
	}
}

#endif //Included Dungeon Template Library