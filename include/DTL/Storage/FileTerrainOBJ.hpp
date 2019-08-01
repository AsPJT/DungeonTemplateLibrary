/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_STORAGE_FILE_TERRAIN_OBJ_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_STORAGE_FILE_TERRAIN_OBJ_HPP

#include <DTL/Workaround/cstdioGets.hpp> //Support Clang 3.4.2

#include <fstream>
#include <string>
#include <DTL/Base/Struct.hpp>
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
		template<typename Matrix_Var_, typename Value_Int_ = Matrix_Var_, typename Ofstream_ = ::std::ofstream>
		class FileTerrainOBJ : public ::dtl::storage::FileBaseTxt<FileTerrainOBJ<Matrix_Var_, Value_Int_, Ofstream_>, Matrix_Var_, Ofstream_> {


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using FileBase_t = ::dtl::storage::FileBaseTxt<FileTerrainOBJ, Matrix_Var_, Ofstream_>;

			friend FileBase_t;


			///// メンバ変数 (Member Variable) /////

			Value_Int_ value_x{ 1 };
			Value_Int_ value_y{ 1 };
			Value_Int_ value_z{ 1 };


			///// 出力処理 /////

			static void writePolygon(Ofstream_& ofs, const Index_Size col, const Index_Size row, const Index_Size width) {
				const Index_Size lt = (row - 1) * width + col - 1;
				const Index_Size rt = (row - 1) * width + col    ;
				const Index_Size lb =  row      * width + col - 1;
				const Index_Size rb =  row      * width + col    ;
				ofs << "f " << rb << ' ' << rt << ' ' << lt << "\n"
				       "f " << lb << ' ' << rb << ' ' << lt << '\n';
			}

			template<typename Matrix_>
			void writeVertex(Ofstream_& ofs, const Matrix_& matrix, const Index_Size col, const Index_Size row) const {
				ofs << "v " << (this->value_x * col)
				    << ' '  << (this->value_z * ::dtl::utility::CastForOutput<Matrix_Var_>(matrix(col, row)))
				    << ' '  << (this->value_y * row) << '\n';
			}


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename... Args_>
			bool writeFileJagged(Ofstream_& ofs, const Index_Size end_y, const Matrix_& matrix, Args_&&...) const {
				for (Index_Size row{ this->start_y }; row < end_y; ++row) {
					const Index_Size end_x = this->calcEndX(matrix.getX());
					for (Index_Size col{ this->start_x }; col < end_x; ++col)
						this->writeVertex(ofs, matrix, col, row);
				}

				for (Index_Size row{ this->start_y + 1 }; row < end_y; ++row) {
					const Index_Size end_x = this->calcEndX(matrix.getX());
					const Index_Size width = end_x - this->start_x;
					for (Index_Size col{ this->start_x + 2 }; col <= end_x; ++col)
						writePolygon(ofs, col, row, width);
				}
				return true;
			}

			//Normal
			template<typename Matrix_, typename... Args_>
			bool writeFile(Ofstream_& ofs, const Index_Size end_x, const Index_Size end_y, const Matrix_& matrix, Args_&&...) const {
				for (Index_Size row{ this->start_y }; row < end_y; ++row)
					for (Index_Size col{ this->start_x }; col < end_x; ++col)
						this->writeVertex(ofs, matrix, col, row);

				const Index_Size width = end_x - this->start_x;
				for (Index_Size row{ this->start_y + 1 }; row < end_y; ++row)
					for (Index_Size col{ this->start_x + 2 }; col <= end_x; ++col)
						writePolygon(ofs, col, row, width);
				return true;
			}

		public:


			///// コンストラクタ (Constructor) /////

			using FileBase_t::FileBase_t;

			constexpr FileTerrainOBJ(const ::std::string & write_value_, const Value_Int_ & value_x_, const Value_Int_ & value_y_, const Value_Int_ & value_z_)
				:FileBase_t(write_value_), value_x(value_x_), value_y(value_y_), value_z(value_z_) {}

			constexpr FileTerrainOBJ(const ::dtl::base::MatrixRange & matrix_range_, const Value_Int_ & value_x_, const Value_Int_ & value_y_, const Value_Int_ & value_z_)
				:FileBase_t(matrix_range_), value_x(value_x_), value_y(value_y_), value_z(value_z_) {}
			constexpr FileTerrainOBJ(const ::dtl::base::MatrixRange & matrix_range_, const ::std::string & write_value_, const Value_Int_ & value_x_, const Value_Int_ & value_y_, const Value_Int_ & value_z_)
				:FileBase_t(matrix_range_, write_value_), value_x(value_x_), value_y(value_y_), value_z(value_z_) {}

			constexpr FileTerrainOBJ(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_, const Value_Int_ & value_x_, const Value_Int_ & value_y_, const Value_Int_ & value_z_)
				:FileBase_t(end_x_, end_y_, width_, height_), value_x(value_x_), value_y(value_y_), value_z(value_z_) {}
			constexpr FileTerrainOBJ(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_, const ::std::string & write_value_, const Value_Int_ & value_x_, const Value_Int_ & value_y_, const Value_Int_ & value_z_)
				:FileBase_t(end_x_, end_y_, width_, height_, write_value_), value_x(value_x_), value_y(value_y_), value_z(value_z_) {}
		};
	}
}

#endif //Included Dungeon Template Library
