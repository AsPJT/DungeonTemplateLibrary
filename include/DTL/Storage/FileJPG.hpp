/*#######################################################################################
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

#include <DTL/Base/Struct.hpp>
#include <DTL/Storage/FileBaseBin.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Type/UniquePtr.hpp>

#ifndef STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <DTL/ThirdParty/STB/stb_image_write.h>
#endif

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace storage { //"dtl::storage"名前空間に属する

/*#######################################################################################
	[概要] FileJPGとは "JPG形式の画像ファイルを出力する" 機能を持つクラスである。
#######################################################################################*/
		template<typename Matrix_Var_, typename UniquePtr_ = DTL_TYPE_UNIQUE_PTR<unsigned char[]>>
		class FileJPG : public ::dtl::storage::FileBaseBin<FileJPG<Matrix_Var_, UniquePtr_>, Matrix_Var_, UniquePtr_> {


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using FileBase_t = ::dtl::storage::FileBaseBin<FileJPG, Matrix_Var_, UniquePtr_>;

			friend FileBase_t;


			///// メンバ変数 (Member Variable) /////

			int quality{ 100 };


			///// 基本処理 /////

			int writeFile(char const* filename, int width, int height, int color_num, const void* data) const {
				return ::stbi_write_jpg(filename, width, height, color_num, data, this->quality);
			}

		public:


			///// コンストラクタ (Constructor) /////

			using FileBase_t::FileBase_t;

			constexpr FileJPG(const ::std::string & write_value_, const ::dtl::type::size color_num_, const int quality_)
				:FileBase_t(write_value_, color_num_), quality(quality_) {}

			constexpr FileJPG(const ::dtl::base::MatrixRange & matrix_range_, const ::std::string & write_value_, const ::dtl::type::size color_num_, const int quality_)
				:FileBase_t(matrix_range_, write_value_, color_num_), quality(quality_) {}

			constexpr FileJPG(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_, const ::std::string & write_value_, const ::dtl::type::size color_num_, const int quality_)
				:FileBase_t(end_x_, end_y_, width_, height_, write_value_, color_num_), quality(quality_) {}
		};
	}
}

#endif //Included Dungeon Template Library
