/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_STORAGE_FILE_TXT_0_9_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_STORAGE_FILE_TXT_0_9_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::storage::FileTXT_0_9-(ストレージクラス)/
#######################################################################################*/

#include <DTL/Workaround/cstdioGets.hpp> //Support Clang 3.4.2

#include <algorithm>
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

		//マスを指定した数値で埋める
		template<typename Matrix_Var_, typename Ofstream_ = ::std::ofstream>
		class FileTXT_0_9 : public ::dtl::storage::FileBaseTxt<FileTXT_0_9<Matrix_Var_, Ofstream_>, Matrix_Var_, Ofstream_> {


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using FileBase_t = ::dtl::storage::FileBaseTxt<FileTXT_0_9, Matrix_Var_, Ofstream_>;

			friend FileBase_t;


			///// 出力処理 /////

			template<typename Matrix_>
			static void writeRow(Ofstream_& ofs, const Matrix_& matrix, const Index_Size row, const Index_Size start_x, const Index_Size end_x) {
				for (Index_Size col{ start_x }; col < end_x; ++col)
					ofs << ::dtl::utility::CastForOutput<Matrix_Var_>((::std::min)((::std::max)(matrix(col, row), 0), 9));
				ofs << '\n';
			}


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename... Args_>
			bool writeFileJagged(Ofstream_& ofs, const Index_Size end_y, const Matrix_& matrix, Args_&&...) const {
				for (Index_Size row{ this->start_y }; row < end_y; ++row) {
					const Index_Size end_x = this->calcEndX(matrix.getX(row));
					writeRow(ofs, matrix, row, this->start_x, end_x);
				}
				return true;
			}

			//Normal
			template<typename Matrix_, typename... Args_>
			bool writeFile(Ofstream_& ofs, const Index_Size end_x, const Index_Size end_y, const Matrix_& matrix, Args_&&...) const {
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
