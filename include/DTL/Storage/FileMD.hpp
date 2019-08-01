/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_STORAGE_FILE_MD_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_STORAGE_FILE_MD_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::storage::FileMD-(ストレージクラス)/
#######################################################################################*/

#include <DTL/Workaround/cstdioGets.hpp> //Support Clang 3.4.2

#include <fstream>
#include <DTL/Storage/FileBaseTxt.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Utility/IsOutputCast.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace storage { //"dtl::storage"名前空間に属する

/*#######################################################################################
	[概要] FileMDとは "Markdown形式のテキストファイルを出力する" 機能を持つクラスである。
#######################################################################################*/
		template<typename Matrix_Var_, typename Ofstream_ = ::std::ofstream>
		class FileMD : public ::dtl::storage::FileBaseTxt<FileMD<Matrix_Var_, Ofstream_>, Matrix_Var_, Ofstream_> {


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using FileBase_t = ::dtl::storage::FileBaseTxt<FileMD, Matrix_Var_, Ofstream_>;

			friend FileBase_t;


			///// 出力処理 /////

			static void writeHeader(Ofstream_& ofs, const Index_Size start_x, const Index_Size end_x) {
				for (::dtl::type::size col{ start_x }; col < end_x; ++col)
					ofs << '|' << col;
				ofs << "|\n|";
				for (::dtl::type::size col{ start_x }; col < end_x; ++col)
					ofs << ":---|";
				ofs << '\n';
			}

			template<typename Matrix_>
			static void writeRow(Ofstream_& ofs, const Matrix_& matrix, const Index_Size row, const Index_Size start_x, const Index_Size end_x) {
				for (Index_Size col{ start_x }; col < end_x; ++col)
					ofs << '|'
						 << ::dtl::utility::CastForOutput<Matrix_Var_>(matrix(col, row));
				ofs << "|\n";
			}


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename... Args_>
			bool writeFileJagged(Ofstream_& ofs, const Index_Size end_y, const Matrix_& matrix, Args_&&...) const {
				writeHeader(ofs, this->start_x, this->calcEndX(matrix.getX()));

				for (Index_Size row{ this->start_y }; row < end_y; ++row) {
					const Index_Size end_x = this->calcEndX(matrix.getX(row));
					writeRow(ofs, matrix, row, this->start_x, end_x);
				}
				return true;
			}

			//Normal
			template<typename Matrix_, typename... Args_>
			bool writeFile(Ofstream_& ofs, const Index_Size end_x, const Index_Size end_y, const Matrix_& matrix, Args_&&...) const {
				writeHeader(ofs, this->start_x, end_x);

				for (Index_Size row{ this->start_y }; row < end_y; ++row) {
					writeRow(ofs, matrix, row, this->start_x, end_x);
				}
				return true;
			}

		public:


			///// コンストラクタ (Constructor) /////

			using FileBase_t::FileBase_t;
		};
	}
}

#endif //Included Dungeon Template Library
