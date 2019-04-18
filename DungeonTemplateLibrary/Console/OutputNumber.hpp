/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_OUTPUT_NUMBER
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_OUTPUT_NUMBER

/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <iostream>
#include <string>
#include <Utility/IsOutputCast.hpp>

namespace dtl {
	inline namespace console {

		//四角形の生成
		template<typename Matrix_Int_, typename OutputString_ = std::string>
		class OutputNumber {
		private:


			///// エイリアス /////

			using Index_Size = std::size_t;
			using PairSize = std::pair<Index_Size, Index_Size>;


			///// メンバ変数 /////

			Index_Size point_x{};
			Index_Size point_y{};
			Index_Size width{};
			Index_Size height{};
			OutputString_ draw_string{};
			OutputString_ before_draw_string{};


			///// 代入処理 /////

			template<typename Matrix_>
			[[nodiscard]] constexpr inline auto outputSTL(const Matrix_& matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				return ((dtl::utility::isOutputCast<Matrix_Int_>()) ? static_cast<int>(matrix_[point_y_][point_x_]) : matrix_[point_y_][point_x_]);
			}
			template<typename Matrix_>
			[[nodiscard]] constexpr inline auto outputArray(const Matrix_ & matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
				return ((dtl::utility::isOutputCast<Matrix_Int_>()) ? static_cast<int>(matrix_[point_y_ * max_x_ + point_x_]) : matrix_[point_y_ * max_x_ + point_x_]);
			}
			template<typename Matrix_>
			[[nodiscard]] constexpr inline auto outputLayer(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				return ((dtl::utility::isOutputCast<Matrix_Int_>()) ? static_cast<int>(matrix_[point_y_][point_x_][layer_]) : matrix_[point_y_][point_x_][layer_]);
			}


			///// 基本処理 /////

			//STL
			template<typename Matrix_>
			bool drawSTL(const Matrix_ & matrix_, const Index_Size point_y_) const noexcept {
				for (Index_Size row{ point_y }; row < point_y_; ++row) {
					for (Index_Size col{ point_x }; col < matrix_[row].size(); ++col)
						std::cout << before_draw_string << this->outputSTL(matrix_, col, row) << draw_string;
					std::cout << '\n';
				}
				return true;
			}
			template<typename Matrix_>
			bool drawWidthSTL(const Matrix_ & matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				for (Index_Size row{ point_y }; row < point_y_; ++row) {
					for (Index_Size col{ point_x }; col < matrix_[row].size() && col < point_x_; ++col)
						std::cout << before_draw_string << this->outputSTL(matrix_, col, row) << draw_string;
					std::cout << '\n';
				}
				return true;
			}

			//LayerSTL
			template<typename Matrix_>
			bool drawLayerSTL(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size point_y_) const noexcept {
				for (Index_Size row{ point_y }; row < point_y_; ++row) {
					for (Index_Size col{ point_x }; col < matrix_[row].size(); ++col)
						std::cout << before_draw_string << this->outputLayer(matrix_, layer_, col, row) << draw_string;
					std::cout << '\n';
				}
				return true;
			}
			template<typename Matrix_>
			bool drawLayerWidthSTL(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				for (Index_Size row{ point_y }; row < point_y_; ++row) {
					for (Index_Size col{ point_x }; col < matrix_[row].size() && col < point_x_; ++col)
						std::cout << before_draw_string << this->outputLayer(matrix_, layer_, col, row) << draw_string;
					std::cout << '\n';
				}
				return true;
			}

			//Normal
			template<typename Matrix_>
			bool drawNormal(const Matrix_ & matrix_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				for (Index_Size row{ point_y }; row < point_y_; ++row) {
					for (Index_Size col{ point_x }; col < point_x_; ++col)
						std::cout << before_draw_string << this->outputSTL(matrix_, col, row) << draw_string;
					std::cout << '\n';
				}
				return true;
			}

			//LayerNormal
			template<typename Matrix_>
			bool drawLayerNormal(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_) const noexcept {
				for (Index_Size row{ point_y }; row < point_y_; ++row) {
					for (Index_Size col{ point_x }; col < point_x_; ++col)
						std::cout << before_draw_string << this->outputLayer(matrix_, layer_, col, row) << draw_string;
					std::cout << '\n';
				}
				return true;
			}

			//Array
			template<typename Matrix_>
			bool drawArray(const Matrix_ & matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_) const noexcept {
				for (Index_Size row{ point_y }; row < point_y_; ++row) {
					for (Index_Size col{ point_x }; col < point_x_; ++col)
						std::cout << before_draw_string << this->outputArray(matrix_, col, row, max_x_) << draw_string;
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


			///// コンストラクタ /////

			constexpr OutputNumber() noexcept = default;
			constexpr explicit OutputNumber(const OutputString_ & draw_string_) noexcept
				:draw_string(draw_string_) {}
			constexpr explicit OutputNumber(const OutputString_ & before_draw_string_, const OutputString_ & draw_string_) noexcept
				:draw_string(draw_string_), before_draw_string(before_draw_string_) {}
			constexpr explicit OutputNumber(const PairSize & length_) noexcept
				:width(length_.first), height(length_.second) {}
			constexpr explicit OutputNumber(const PairSize & length_, const OutputString_ & draw_string_) noexcept
				:width(length_.first), height(length_.second),
				draw_string(draw_string_) {}
			constexpr explicit OutputNumber(const PairSize & length_, const OutputString_ & before_draw_string_, const OutputString_ & draw_string_) noexcept
				:width(length_.first), height(length_.second),
				draw_string(draw_string_), before_draw_string(before_draw_string_) {}
			constexpr explicit OutputNumber(const PairSize & position_, const PairSize & length_) noexcept
				:point_x(position_.first), point_y(position_.second),
				width(length_.first), height(length_.second) {}
			constexpr explicit OutputNumber(const PairSize & position_, const PairSize & length_, const OutputString_ & draw_string_) noexcept
				:point_x(position_.first), point_y(position_.second),
				width(length_.first), height(length_.second),
				draw_string(draw_string_) {}
			constexpr explicit OutputNumber(const PairSize & position_, const PairSize & length_, const OutputString_ & before_draw_string_, const OutputString_ & draw_string_) noexcept
				:point_x(position_.first), point_y(position_.second),
				width(length_.first), height(length_.second),
				draw_string(draw_string_), before_draw_string(before_draw_string_) {}
			constexpr explicit OutputNumber(const Index_Size width_, const Index_Size height_) noexcept
				:width(width_), height(height_) {}
			constexpr explicit OutputNumber(const Index_Size width_, const Index_Size height_, const OutputString_ & draw_string_) noexcept
				:width(width_), height(height_),
				draw_string(draw_string_) {}
			constexpr explicit OutputNumber(const Index_Size width_, const Index_Size height_, const OutputString_ & before_draw_string_, const OutputString_ & draw_string_) noexcept
				:width(width_), height(height_),
				draw_string(draw_string_), before_draw_string(before_draw_string_) {}
			constexpr explicit OutputNumber(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
				:point_x(point_x_), point_y(point_y_),
				width(width_), height(height_) {}
			constexpr explicit OutputNumber(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const OutputString_ & draw_string_) noexcept
				:point_x(point_x_), point_y(point_y_),
				width(width_), height(height_),
				draw_string(draw_string_) {}
			constexpr explicit OutputNumber(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const OutputString_ & before_draw_string_, const OutputString_ & draw_string_) noexcept
				:point_x(point_x_), point_y(point_y_),
				width(width_), height(height_),
				draw_string(draw_string_), before_draw_string(before_draw_string_) {}
		};
	}
}

#endif //Included Dungeon Template Library