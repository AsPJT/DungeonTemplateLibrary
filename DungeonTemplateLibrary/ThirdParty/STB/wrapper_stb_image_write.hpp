/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_THIRD_PARTY_STB_WRAPPER_STB_IMAGE_WRITE
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_THIRD_PARTY_STB_WRAPPER_STB_IMAGE_WRITE

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <memory>
#include <new>
#include <string>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <ThirdParty/STB/stb_image_write.hpp>

namespace dtl::thirdParty::stb {

	enum :std::size_t {
		primary_color_empty,
		primary_color_one,
		primary_colors_two,
		primary_colors_rgb,
		primary_colors_rgba
	};

	enum :std::size_t {
		image_red,
		image_green,
		image_blue,
		image_alpha,
	};
	using Image_Palette = unsigned char;

	template<typename Matrix_Int_, std::size_t Width_, std::size_t Height_, std::size_t Color_Num_ = dtl::thirdParty::stb::primary_colors_rgb>
	class FileSTB {
	private:
		//std::unique_ptr<unsigned char[][Width_][Color_Num_]> data;
		std::unique_ptr<unsigned char[]> data;

	public:
		template<typename Matrix_, typename Function_>
		FileSTB(Matrix_&& matrix_, Function_&& function_) noexcept :data(new(std::nothrow) unsigned char[Height_*Width_*Color_Num_]) {
			for (std::size_t row{}; row < Height_; ++row)
				for (std::size_t col{}; col < Width_; ++col)
					function_(matrix_[row][col], &data[(row * Width_ + col) * Color_Num_]);
		}
		//FileSTB() noexcept :data(new(std::nothrow) unsigned char[Height_][Width_][Color_Num_]) {}
		//template<typename Matrix_,typename Function_>
		//FileSTB(Matrix_&& matrix_, Function_&& function_) noexcept :data(new(std::nothrow) unsigned char[Height_][Width_][Color_Num_]) {
		//	for (std::size_t row{}; row < Height_; ++row)
		//		for (std::size_t col{}; col < Width_; ++col)
		//			function_(matrix_[row][col], &data[row][col][0]);
		//}
		//template<typename Matrix_, typename Function_>
		//FileSTB(Matrix_&& matrix_, const Matrix_Int_& layer_, Function_&& function_) noexcept :data(new(std::nothrow) unsigned char[Height_][Width_][Color_Num_]) {
		//	for (std::size_t row{}; row < Height_; ++row)
		//		for (std::size_t col{}; col < Width_; ++col)
		//			function_(matrix_[row][col][layer_], &data[row][col][0]);
		//}

		auto writePNG(const std::string& string_, const int stride_in_bytes_ = 0) const noexcept {
			return stbi_write_png(string_, static_cast<int>(Width_), static_cast<int>(Height_), static_cast<int>(Color_Num_), data.get(), stride_in_bytes_);
		}
		auto writeBMP(const std::string& string_) const noexcept {
			return stbi_write_bmp(string_, static_cast<int>(Width_), static_cast<int>(Height_), static_cast<int>(Color_Num_), data.get());
		}
		auto writeTGA(const std::string& string_) const noexcept {
			return stbi_write_tga(string_, static_cast<int>(Width_), static_cast<int>(Height_), static_cast<int>(Color_Num_), data.get());
		}
		auto writeHDR(const std::string& string_) const noexcept {
			return stbi_write_hdr(string_, static_cast<int>(Width_), static_cast<int>(Height_), static_cast<int>(Color_Num_), data.get());
		}
		auto writeJPG(const std::string& string_, const int quality_ = 100) const noexcept {
			return stbi_write_jpg(string_, static_cast<int>(Width_), static_cast<int>(Height_), static_cast<int>(Color_Num_), data.get(), quality_);
		}
	};

} //namespace

namespace dtl::storage {

	enum :std::size_t {
		primary_color_empty,
		primary_color_one,
		primary_colors_two,
		primary_colors_rgb,
		primary_colors_rgba
	};

	enum :std::size_t {
		image_red,
		image_green,
		image_blue,
		image_alpha,
	};
	using Image_Palette = unsigned char;

	template<typename Matrix_Int_, std::size_t Width_, std::size_t Height_, std::size_t Color_Num_ = 3>
	using FileImage = dtl::thirdParty::stb::FileSTB<Matrix_Int_, Width_, Height_, Color_Num_>;

} //namespace

#endif //Included Dungeon Template Library