/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_STORAGE_FILE_SANDBOX_OBJ_3D_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_STORAGE_FILE_SANDBOX_OBJ_3D_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::storage::FileSandboxOBJ_3D-(ストレージクラス)/
#######################################################################################*/

#include <DTL/Workaround/cstdioGets.hpp> //Support Clang 3.4.2

#include <fstream>
#include <string>

#include <DTL/Type/SizeT.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace storage { //"dtl::storage"名前空間に属する

		//マスを指定した数値で埋める
		template<typename Matrix_Int_>
		class FileSandboxOBJ_3D {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;



			///// メンバ変数 (Member Variable) /////

			::std::string str{};

			void write_objOutputId( ::std::ofstream& ofs_, const ::std::size_t id_ = 0) const noexcept {
				ofs_ << "f " << (1 + id_ * 8) << " " << (3 + id_ * 8) << " " << (4 + id_ * 8) << " " << (2 + id_ * 8) << '\n';
				ofs_ << "f " << (1 + id_ * 8) << " " << (5 + id_ * 8) << " " << (7 + id_ * 8) << " " << (3 + id_ * 8) << '\n';
				ofs_ << "f " << (2 + id_ * 8) << " " << (4 + id_ * 8) << " " << (8 + id_ * 8) << " " << (6 + id_ * 8) << '\n';
				ofs_ << "f " << (1 + id_ * 8) << " " << (2 + id_ * 8) << " " << (6 + id_ * 8) << " " << (5 + id_ * 8) << '\n';
				ofs_ << "f " << (3 + id_ * 8) << " " << (7 + id_ * 8) << " " << (8 + id_ * 8) << " " << (4 + id_ * 8) << '\n';
				ofs_ << "f " << (5 + id_ * 8) << " " << (6 + id_ * 8) << " " << (8 + id_ * 8) << " " << (7 + id_ * 8) << '\n';
			}
			void write_objOutputCube( ::std::ofstream& ofs_, ::std::int_fast32_t start_x, ::std::int_fast32_t start_y, ::std::int_fast32_t start_z, ::std::int_fast32_t size_x, ::std::int_fast32_t size_y, ::std::int_fast32_t size_z, ::std::size_t id_ = 0) const noexcept {
				ofs_ << "v " << start_x << " " << start_y << " " << start_z << " " << '\n';
				ofs_ << "v " << start_x + size_x << " " << start_y << " " << start_z << " " << '\n';
				ofs_ << "v " << start_x << " " << start_y + size_y << " " << start_z << " " << '\n';
				ofs_ << "v " << start_x + size_x << " " << start_y + size_y << " " << start_z << " " << '\n';
				ofs_ << "v " << start_x << " " << start_y << " " << start_z + size_z << " " << '\n';
				ofs_ << "v " << start_x + size_x << " " << start_y << " " << start_z + size_z << " " << '\n';
				ofs_ << "v " << start_x << " " << start_y + size_y << " " << start_z + size_z << " " << '\n';
				ofs_ << "v " << start_x + size_x << " " << start_y + size_y << " " << start_z + size_z << " " << '\n';
				this->write_objOutputId(ofs_, id_);
			}

		public:

			template<typename Matrix_>
			bool draw(const Matrix_& matrix_) const noexcept {
				if (matrix_.size() == 0 || matrix_[0].size() == 0 || matrix_[0][0].size() == 0) return false;
				::std::ofstream ofs(this->str);
				if (ofs.fail()) return false;

				for ( ::std::size_t square_count{}, z{}; z < matrix_.size(); ++z)
					for ( ::std::size_t y{}; y < matrix_[z].size(); ++y)
						for ( ::std::size_t x{}; x < matrix_[z][y].size(); ++x) {
							if (!matrix_[z][y][x]) continue;
							this->write_objOutputCube(ofs, ( ::std::int_fast32_t)x, ( ::std::int_fast32_t)z, ( ::std::int_fast32_t)y, 1, 1, 1, square_count);
							++square_count;
						}
				return true;
			}

			///// コンストラクタ (Constructor) /////

			constexpr FileSandboxOBJ_3D() = default;
			constexpr explicit FileSandboxOBJ_3D(const ::std::string & write_value_) noexcept
				:str(write_value_) {}

		};
	}
}

#endif //Included Dungeon Template Library