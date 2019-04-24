/*#######################################################################################
	Made by Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_MATRIX
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_MATRIX

/* Character Code : UTF-8 (BOM) */
/* Bug Check : not checked */

#include <cstddef>

//共有データ
namespace dtl {
	inline namespace utility {
		namespace tool {

#ifdef __cplusplus
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr bool isMatrixEmpty(const std::size_t xy_) noexcept {
				return (xy_ == 0);
			}
#ifdef __cplusplus
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr bool isMatrixEmpty(const std::size_t x_, const std::size_t y_) noexcept {
				return (y_ == 0 || x_ == 0);
			}
			template<typename Matrix_>
#ifdef __cplusplus
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr bool isMatrixEmpty(const Matrix_ & matrix_) noexcept {
				return (matrix_.size() == 0 || matrix_[0].size() == 0);
			}

			//配列の要素数を取得
			template<typename Matrix_>
#ifdef __cplusplus
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr std::size_t getMatrixSize(const Matrix_ & matrix_) noexcept {
				return ((matrix_.size() == 0) ? 0 : (matrix_.size() * matrix_[0].size()));
			}
			template<typename Matrix_>
#ifdef __cplusplus
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr std::size_t getMatrixSizeX(const Matrix_ & matrix_) noexcept {
				return ((matrix_.size() == 0) ? 0 : matrix_[0].size());
			}
			template<typename Matrix_>
#ifdef __cplusplus
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr std::size_t getMatrixSizeY(const Matrix_ & matrix_) noexcept {
				return matrix_.size();
			}

			template<typename Matrix_>
#ifdef __cplusplus
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr bool isMatrixLessThan(const Matrix_ & matrix_, const std::size_t num_) noexcept {
				return (matrix_.size() < num_ || matrix_[0].size() < num_);
			}

			//指定位置に値を代入する
			template<typename Matrix_Int_, typename Matrix_>
			constexpr void setMatrixValue(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
				matrix_[y_][x_] = value_;
			}
			template<typename Matrix_>
			constexpr void setMatrixValue(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_) noexcept {
				matrix_[y_][x_] = 0;
			}
			//指定位置の値を取得する
			template<typename Matrix_Int_, typename Matrix_>
			constexpr auto getMatrixValue(const Matrix_ & matrix_, const std::size_t x_, const std::size_t y_, Matrix_Int_ & value_) noexcept {
				return value_ = matrix_[y_][x_];
			}
			template<typename Matrix_>
#ifdef __cplusplus
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr auto getMatrixValue(const Matrix_ & matrix_, const std::size_t x_, const std::size_t y_) noexcept {
				return matrix_[y_][x_];
			}

		}
	}
}

#endif //Included Dungeon Template Library