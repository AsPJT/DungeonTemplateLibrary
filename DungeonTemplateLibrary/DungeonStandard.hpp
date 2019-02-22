#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_STANDARD
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_STANDARD
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>
#include "DungeonRandom.hpp"
#include "DungeonMatrix.hpp"

//Dungeon Template Library Namespace
namespace dtl {
	namespace generator {
		namespace common {
			namespace data {


				//----------   DungeonInit   ----------
				//1.全てのマスを0で埋める
				//2.全てのマスを指定した数値で埋める

				enum eDungeonInit {
					dungeon_init_empty_id,
					dungeon_init_enum_num
				};
				constexpr bool dungeon_init_bool{ (dungeon_init_enum_num <= 2) ? true : false };


			} //namespace
		}
	}
}
namespace dtl {
	namespace generator {
		namespace common {
			namespace stl {


				//(1)
				template<typename Matrix_>
				constexpr void initDungeon(Matrix_& matrix_) noexcept {
					for (std::size_t row{}; row < matrix_.size(); ++row)
						for (std::size_t col{}; col < matrix_[row].size(); ++col)
							matrix_[row][col] = 0;
				}
				//(2)
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void initDungeon(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
					for (std::size_t row{}; row < matrix_.size(); ++row)
						for (std::size_t col{}; col < matrix_[row].size(); ++col)
							matrix_[row][col] = value_;
				}
				//クラス版
				template<typename Matrix_Int_>
				class DungeonInit {
				public:
					//コンストラクタ
					constexpr DungeonInit() noexcept = default;
					template<typename Matrix_>
					constexpr explicit DungeonInit(Matrix_& matrix_, const Matrix_Int_ value_ = 0) noexcept {
						create(matrix_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 0) noexcept {
						dtl::generator::common::stl::initDungeon(matrix_, value_);
					}
				};


			} //namespace
		}
	}
}
namespace dtl {
	namespace generator {
		namespace common {
			namespace normal {


				//(1)
				template<typename Matrix_>
				constexpr void initDungeon(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
					for (std::size_t row{}; row < y_; ++row)
						for (std::size_t col{}; col < x_; ++col)
							matrix_[row][col] = 0;
				}
				//(2)
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void initDungeon(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
					for (std::size_t row{}; row < y_; ++row)
						for (std::size_t col{}; col < x_; ++col)
							matrix_[row][col] = value_;
				}
				template<typename Matrix_>
				constexpr void initDungeon(Matrix_& matrix_, const std::size_t start_x_, const std::size_t start_y_, const std::size_t end_x_, const std::size_t end_y_) noexcept {
					for (std::size_t row{ start_y_ }; row < end_y_; ++row)
						for (std::size_t col{ start_x_ }; col < end_x_; ++col)
							matrix_[row][col] = 0;
				}
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void initDungeon(Matrix_& matrix_, const std::size_t start_x_, const std::size_t start_y_, const std::size_t end_x_, const std::size_t end_y_, const Matrix_Int_ value_) noexcept {
					for (std::size_t row{ start_y_ }; row < end_y_; ++row)
						for (std::size_t col{ start_x_ }; col < end_x_; ++col)
							matrix_[row][col] = value_;
				}
				//クラス版
				template<typename Matrix_Int_>
				class DungeonInit {
				public:
					//コンストラクタ
					constexpr DungeonInit() noexcept = default;
					template<typename Matrix_>
					constexpr explicit DungeonInit(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 0) noexcept {
						create(matrix_, x_, y_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 0) noexcept {
						dtl::generator::common::normal::initDungeon(matrix_, x_, y_, value_);
					}
				};


			} //namespace
		}
	}
}
namespace dtl {
	namespace generator {
		namespace common {
			namespace array {


				//(1)
				template<typename Matrix_>
				constexpr void initDungeon(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
					for (std::size_t row{}; row < y_; ++row)
						for (std::size_t col{}; col < x_; ++col)
							matrix_[row * x_ + col] = 0;
				}
				//(2)
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void initDungeon(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
					for (std::size_t row{}; row < y_; ++row)
						for (std::size_t col{}; col < x_; ++col)
							matrix_[row * x_ + col] = value_;
				}
				template<typename Matrix_>
				constexpr void initDungeon(Matrix_& matrix_, const std::size_t start_x_, const std::size_t start_y_, const std::size_t end_x_, const std::size_t end_y_) noexcept {
					for (std::size_t row{ start_y_ }; row < end_y_; ++row)
						for (std::size_t col{ start_x_ }; col < end_x_; ++col)
							matrix_[row * end_x_ + col] = 0;
				}
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void initDungeon(Matrix_& matrix_, const std::size_t start_x_, const std::size_t start_y_, const std::size_t end_x_, const std::size_t end_y_, const Matrix_Int_ value_) noexcept {
					for (std::size_t row{ start_y_ }; row < end_y_; ++row)
						for (std::size_t col{ start_x_ }; col < end_x_; ++col)
							matrix_[row * end_x_ + col] = value_;
				}

				template<typename Matrix_Int_>
				class DungeonInit {
				public:
					//コンストラクタ
					constexpr DungeonInit() noexcept = default;
					template<typename Matrix_>
					constexpr explicit DungeonInit(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 0) noexcept {
						create(matrix_, x_, y_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 0) noexcept {
						dtl::generator::common::array::initDungeon(matrix_, x_, y_, value_);
					}
				};


			} //namespace
		}
	}
}
namespace dtl {
	namespace generator {
		namespace common {
			namespace rangeBasedFor {


				//(1)
				template<typename Matrix_>
				constexpr void initDungeon(Matrix_& matrix_) noexcept {
					for (auto&& row : matrix_)
						for (auto&& col : row)
							col = 0;
				}
				//(2)
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void initDungeon(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
					for (auto&& row : matrix_)
						for (auto&& col : row)
							col = value_;
				}


			} //namespace
		}
	}
}
namespace dtl {
	namespace generator {
		namespace common {
			namespace layer {


				//Layer----------

				namespace stl {
					//(1)
					template<typename Matrix_>
					constexpr void initDungeon(Matrix_& matrix_, std::size_t layer_) noexcept {
						for (std::size_t row{}; row < matrix_.size(); ++row)
							for (std::size_t col{}; col < matrix_[row].size(); ++col)
								matrix_[row][col][layer_] = 0;
					}
					//(2)
					template<typename Matrix_Int_, typename Matrix_>
					constexpr void initDungeon(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_) noexcept {
						for (std::size_t row{}; row < matrix_.size(); ++row)
							for (std::size_t col{}; col < matrix_[row].size(); ++col)
								matrix_[row][col][layer_] = value_;
					}
					//クラス版
					template<typename Matrix_Int_>
					class DungeonInit {
					public:
						//コンストラクタ
						constexpr DungeonInit() noexcept = default;
						template<typename Matrix_>
						constexpr explicit DungeonInit(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_ = 0) noexcept {
							create(matrix_, layer_, value_);
						}
						template<typename Matrix_>
						constexpr void create(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_ = 0) noexcept {
							dtl::generator::common::layer::stl::initDungeon(matrix_, layer_, value_);
						}
					};
				}

				namespace normal {
					//(1)
					template<typename Matrix_>
					constexpr void initDungeon(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
						for (std::size_t row{}; row < y_; ++row)
							for (std::size_t col{}; col < x_; ++col)
								matrix_[row][col][layer_] = 0;
					}
					//(2)
					template<typename Matrix_Int_, typename Matrix_>
					constexpr void initDungeon(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
						for (std::size_t row{}; row < y_; ++row)
							for (std::size_t col{}; col < x_; ++col)
								matrix_[row][col][layer_] = value_;
					}
					template<typename Matrix_>
					constexpr void initDungeon(Matrix_& matrix_, std::size_t layer_, const std::size_t start_x_, const std::size_t start_y_, const std::size_t end_x_, const std::size_t end_y_) noexcept {
						for (std::size_t row{ start_y_ }; row < end_y_; ++row)
							for (std::size_t col{ start_x_ }; col < end_x_; ++col)
								matrix_[row][col][layer_] = 0;
					}
					template<typename Matrix_Int_, typename Matrix_>
					constexpr void initDungeon(Matrix_& matrix_, std::size_t layer_, const std::size_t start_x_, const std::size_t start_y_, const std::size_t end_x_, const std::size_t end_y_, const Matrix_Int_ value_) noexcept {
						for (std::size_t row{ start_y_ }; row < end_y_; ++row)
							for (std::size_t col{ start_x_ }; col < end_x_; ++col)
								matrix_[row][col][layer_] = value_;
					}
					//クラス版
					template<typename Matrix_Int_>
					class DungeonInit {
					public:
						//コンストラクタ
						constexpr DungeonInit() noexcept = default;
						template<typename Matrix_>
						constexpr explicit DungeonInit(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 0) noexcept {
							create(matrix_, layer_, x_, y_, value_);
						}
						template<typename Matrix_>
						constexpr void create(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 0) noexcept {
							dtl::generator::common::layer::normal::initDungeon(matrix_, layer_, x_, y_, value_);
						}
					};

				}

			}

			//----------   PointGrid   ----------
			//1.偶数マスを1で埋める
			//2.偶数マスを指定した数値で埋める

			namespace data {

				enum ePointGrid {
					point_grid_empty_id,
					point_grid_wall_id,
					point_grid_enum_num
				};
				constexpr bool point_grid_bool{ (point_grid_enum_num <= 2) ? true : false };

			}

			namespace array {
				//Array版
				template<typename Matrix_>
				constexpr void createPointGrid(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
					for (std::size_t row{}; row < y_; row += 2)
						for (std::size_t col{}; col < x_; col += 2)
							matrix_[row * x_ + col] = 1;
				}
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createPointGrid(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
					for (std::size_t row{}; row < y_; row += 2)
						for (std::size_t col{}; col < x_; col += 2)
							matrix_[row * x_ + col] = value_;
				}
				template<typename Matrix_Int_>
				class PointGrid {
				public:
					//コンストラクタ
					constexpr PointGrid() noexcept = default;
					template<typename Matrix_>
					constexpr explicit PointGrid(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, x_, y_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						createPointGrid(matrix_, x_, y_, value_);
					}
				};
			}

			namespace normal {
				//Default版
				template<typename Matrix_>
				constexpr void createPointGrid(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
					for (std::size_t row{}; row < y_; row += 2)
						for (std::size_t col{}; col < x_; col += 2)
							matrix_[row][col] = 1;
				}
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createPointGrid(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
					for (std::size_t row{}; row < y_; row += 2)
						for (std::size_t col{}; col < x_; col += 2)
							matrix_[row][col] = value_;
				}
				//クラス版
				template<typename Matrix_Int_>
				class PointGrid {
				public:
					//コンストラクタ
					constexpr PointGrid() noexcept = default;
					template<typename Matrix_>
					constexpr explicit PointGrid(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, x_, y_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						createPointGrid(matrix_, x_, y_, value_);
					}
				};
			}

			namespace stl {
				//STL版(1)
				template<typename Matrix_>
				constexpr void createPointGrid(Matrix_& matrix_) noexcept {
					for (std::size_t row{}; row < matrix_.size(); row += 2)
						for (std::size_t col{}; col < matrix_[row].size(); col += 2)
							matrix_[row][col] = 1;
				}
				//STL版(2)
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createPointGrid(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
					for (std::size_t row{}; row < matrix_.size(); row += 2)
						for (std::size_t col{}; col < matrix_[row].size(); col += 2)
							matrix_[row][col] = value_;
				}
				//クラス版
				template<typename Matrix_Int_>
				class PointGrid {
				public:
					//コンストラクタ
					constexpr PointGrid() noexcept = default;
					template<typename Matrix_>
					constexpr explicit PointGrid(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
						createPointGrid(matrix_, value_);
					}
				};
			}


			namespace layer {
				namespace normal {
					//Default版
					template<typename Matrix_>
					constexpr void createPointGrid(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
						for (std::size_t row{}; row < y_; row += 2)
							for (std::size_t col{}; col < x_; col += 2)
								matrix_[row][col][layer_] = 1;
					}
					template<typename Matrix_Int_, typename Matrix_>
					constexpr void createPointGrid(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
						for (std::size_t row{}; row < y_; row += 2)
							for (std::size_t col{}; col < x_; col += 2)
								matrix_[row][col][layer_] = value_;
					}
					//クラス版
					template<typename Matrix_Int_>
					class PointGrid {
					public:
						//コンストラクタ
						constexpr PointGrid() noexcept = default;
						template<typename Matrix_>
						constexpr explicit PointGrid(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
							create(matrix_, layer_, x_, y_, value_);
						}
						template<typename Matrix_>
						constexpr void create(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
							createPointGrid(matrix_, layer_, x_, y_, value_);
						}
					};
				}

				namespace stl {
					//STL版(1)
					template<typename Matrix_>
					constexpr void createPointGrid(Matrix_& matrix_, std::size_t layer_) noexcept {
						for (std::size_t row{}; row < matrix_.size(); row += 2)
							for (std::size_t col{}; col < matrix_[row].size(); col += 2)
								matrix_[row][col][layer_] = 1;
					}
					//STL版(2)
					template<typename Matrix_Int_, typename Matrix_>
					constexpr void createPointGrid(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_) noexcept {
						for (std::size_t row{}; row < matrix_.size(); row += 2)
							for (std::size_t col{}; col < matrix_[row].size(); col += 2)
								matrix_[row][col][layer_] = value_;
					}
					//クラス版
					template<typename Matrix_Int_>
					class PointGrid {
					public:
						//コンストラクタ
						constexpr PointGrid() noexcept = default;
						template<typename Matrix_>
						constexpr explicit PointGrid(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_ = 1) noexcept {
							create(matrix_, layer_, value_);
						}
						template<typename Matrix_>
						constexpr void create(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_ = 1) noexcept {
							createPointGrid(matrix_, layer_, value_);
						}
					};
				}

			}


			//----------   BorderOdd   ----------
			//1.マップの外枠を1で埋める(枠の内部を奇数マスにする)
			//2.マップの外枠を指定した数値で埋める(枠の内部を奇数マスにする)

			namespace data {

				enum eBorderOdd {
					border_odd_empty_id,
					border_odd_wall_id,
					border_odd_enum_num
				};
				constexpr bool border_odd_bool{ (border_odd_enum_num <= 2) ? true : false };

			}

			namespace array {
				//Array版
				template<typename Matrix_>
				constexpr void createBorderOdd(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
					if (y_ < 2) return;
					for (std::size_t row{}; row < x_; ++row)
						matrix_[row] = 1;
					if (y_ % 2 == 1) {
						for (std::size_t row{}; row < x_; ++row)
							matrix_[(y_ - 1) * x_ + row] = 1;
					}
					else for (std::size_t row{}; row < x_; ++row) {
						matrix_[(y_ - 2) * x_ + row] = 1;
						matrix_[(y_ - 1) * x_ + row] = 1;
					}
					if (x_ < 2) return;
					for (std::size_t row{}; row < y_; ++row) {
						matrix_[row*x_] = 1;
						if (x_ % 2 == 0) matrix_[row*x_ + x_ - 2] = 1;
						matrix_[row*x_ + x_ - 1] = 1;
					}
				}
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createBorderOdd(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
					if (y_ < 2) return;
					for (std::size_t col{}; col < x_; ++col)
						matrix_[col] = value_;
					if (y_ % 2 == 1) {
						for (std::size_t col{}; col < x_; ++col)
							matrix_[(y_ - 1) * x_ + col] = value_;
					}
					else for (std::size_t col{}; col < x_; ++col) {
						matrix_[(y_ - 2) * x_ + col] = value_;
						matrix_[(y_ - 1) * x_ + col] = value_;
					}
					if (x_ < 2) return;
					for (std::size_t row{}; row < y_; ++row) {
						matrix_[row*x_] = value_;
						if (x_ % 2 == 0) matrix_[row*x_ + x_ - 2] = value_;
						matrix_[row*x_ + x_ - 1] = value_;
					}
				}
				template<typename Matrix_Int_>
				class BorderOdd {
				public:
					//コンストラクタ
					constexpr BorderOdd() noexcept = default;
					template<typename Matrix_>
					constexpr explicit BorderOdd(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, x_, y_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						dtl::generator::common::array::createBorderOdd(matrix_, x_, y_, value_);
					}
				};

			}
			namespace normal {
				//Default版
				template<typename Matrix_>
				constexpr void createBorderOdd(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
					if (y_ < 2) return;
					for (std::size_t col{}; col < x_; ++col)
						matrix_[0][col] = 1;
					if (y_ % 2 == 1) {
						for (std::size_t col{}; col < x_; ++col)
							matrix_[y_ - 1][col] = 1;
					}
					else for (std::size_t col{}; col < x_; ++col) {
						matrix_[y_ - 2][col] = 1;
						matrix_[y_ - 1][col] = 1;
					}
					if (x_ < 2) return;
					for (std::size_t row{}; row < y_; ++row) {
						matrix_[row][0] = 1;
						if (x_ % 2 == 0) matrix_[row][x_ - 2] = 1;
						matrix_[row][x_ - 1] = 1;
					}
				}
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createBorderOdd(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
					if (y_ < 2) return;
					for (std::size_t col{}; col < x_; ++col)
						matrix_[0][col] = value_;
					if (y_ % 2 == 1) {
						for (std::size_t col{}; col < x_; ++col)
							matrix_[y_ - 1][col] = value_;
					}
					else for (std::size_t col{}; col < x_; ++col) {
						matrix_[y_ - 2][col] = value_;
						matrix_[y_ - 1][col] = value_;
					}
					if (x_ < 2) return;
					for (std::size_t row{}; row < y_; ++row) {
						matrix_[row][0] = value_;
						if (x_ % 2 == 0) matrix_[row][x_ - 2] = value_;
						matrix_[row][x_ - 1] = value_;
					}
				}
				//クラス版
				template<typename Matrix_Int_>
				class BorderOdd {
				public:
					//コンストラクタ
					constexpr BorderOdd() noexcept = default;
					template<typename Matrix_>
					constexpr explicit BorderOdd(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, x_, y_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						dtl::generator::common::normal::createBorderOdd(matrix_, x_, y_, value_);
					}
				};
			}
			namespace stl {
				//STL版(1)
				template<typename Matrix_>
				constexpr void createBorderOdd(Matrix_& matrix_) noexcept {
					if (matrix_.size() < 2) return;
					for (std::size_t col{}; col < matrix_[0].size(); ++col)
						matrix_[0][col] = 1;
					if (matrix_.size() % 2 == 1) {
						for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
							matrix_[matrix_.size() - 1][col] = 1;
					}
					else for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col) {
						matrix_[matrix_.size() - 2][col] = 1;
						matrix_[matrix_.size() - 1][col] = 1;
					}
					for (std::size_t row{}; row < matrix_.size(); ++row) {
						if (matrix_[row].size() < 2) continue;
						matrix_[row][0] = 1;
						if (matrix_[row].size() % 2 == 0) matrix_[row][matrix_[row].size() - 2] = 1;
						matrix_[row][matrix_[row].size() - 1] = 1;
					}
				}
				//STL版(2)
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createBorderOdd(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
					if (matrix_.size() < 2) return;
					for (std::size_t col{}; col < matrix_[0].size(); ++col)
						matrix_[0][col] = value_;
					if (matrix_.size() % 2 == 1) {
						for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
							matrix_[matrix_.size() - 1][col] = value_;
					}
					else for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col) {
						matrix_[matrix_.size() - 2][col] = value_;
						matrix_[matrix_.size() - 1][col] = value_;
					}
					for (std::size_t row{}; row < matrix_.size(); ++row) {
						if (matrix_[row].size() < 2) continue;
						matrix_[row][0] = value_;
						if (matrix_[row].size() % 2 == 0) matrix_[row][matrix_[row].size() - 2] = value_;
						matrix_[row][matrix_[row].size() - 1] = value_;
					}
				}
				//クラス版
				template<typename Matrix_Int_>
				class BorderOdd {
				public:
					//コンストラクタ
					constexpr BorderOdd() noexcept = default;
					template<typename Matrix_>
					constexpr explicit BorderOdd(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
						dtl::generator::common::stl::createBorderOdd(matrix_, value_);
					}
				};
			}

			namespace layer {
				namespace normal {
					//Default版
					template<typename Matrix_>
					constexpr void createBorderOdd(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
						if (y_ < 2) return;
						for (std::size_t col{}; col < x_; ++col)
							matrix_[0][col][layer_] = 1;
						if (y_ % 2 == 1) {
							for (std::size_t col{}; col < x_; ++col)
								matrix_[y_ - 1][col][layer_] = 1;
						}
						else for (std::size_t col{}; col < x_; ++col) {
							matrix_[y_ - 2][col][layer_] = 1;
							matrix_[y_ - 1][col][layer_] = 1;
						}
						if (x_ < 2) return;
						for (std::size_t row{}; row < y_; ++row) {
							matrix_[row][0][layer_] = 1;
							if (x_ % 2 == 0) matrix_[row][x_ - 2][layer_] = 1;
							matrix_[row][x_ - 1][layer_] = 1;
						}
					}
					template<typename Matrix_Int_, typename Matrix_>
					constexpr void createBorderOdd(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
						if (y_ < 2) return;
						for (std::size_t col{}; col < x_; ++col)
							matrix_[0][col][layer_] = value_;
						if (y_ % 2 == 1) {
							for (std::size_t col{}; col < x_; ++col)
								matrix_[y_ - 1][col][layer_] = value_;
						}
						else for (std::size_t col{}; col < x_; ++col) {
							matrix_[y_ - 2][col][layer_] = value_;
							matrix_[y_ - 1][col][layer_] = value_;
						}
						if (x_ < 2) return;
						for (std::size_t row{}; row < y_; ++row) {
							matrix_[row][0][layer_] = value_;
							if (x_ % 2 == 0) matrix_[row][x_ - 2][layer_] = value_;
							matrix_[row][x_ - 1][layer_] = value_;
						}
					}
					//クラス版
					template<typename Matrix_Int_>
					class BorderOdd {
					public:
						//コンストラクタ
						constexpr BorderOdd() noexcept = default;
						template<typename Matrix_>
						constexpr explicit BorderOdd(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
							create(matrix_, layer_, x_, y_, value_);
						}
						template<typename Matrix_>
						constexpr void create(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
							dtl::generator::common::layer::normal::createBorderOdd(matrix_, layer_, x_, y_, value_);
						}
					};
				}
				namespace stl {
					//STL版(1)
					template<typename Matrix_>
					constexpr void createBorderOdd(Matrix_& matrix_, std::size_t layer_) noexcept {
						if (matrix_.size() < 2) return;
						for (std::size_t col{}; col < matrix_[0].size(); ++col)
							matrix_[0][col][layer_] = 1;
						if (matrix_.size() % 2 == 1) {
							for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
								matrix_[matrix_.size() - 1][col][layer_] = 1;
						}
						else for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col) {
							matrix_[matrix_.size() - 2][col][layer_] = 1;
							matrix_[matrix_.size() - 1][col][layer_] = 1;
						}
						for (std::size_t row{}; row < matrix_.size(); ++row) {
							if (matrix_[row].size() < 2) continue;
							matrix_[row][0][layer_] = 1;
							if (matrix_[row].size() % 2 == 0) matrix_[row][matrix_[row].size() - 2][layer_] = 1;
							matrix_[row][matrix_[row].size() - 1][layer_] = 1;
						}
					}
					//STL版(2)
					template<typename Matrix_Int_, typename Matrix_>
					constexpr void createBorderOdd(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_) noexcept {
						if (matrix_.size() < 2) return;
						for (std::size_t col{}; col < matrix_[0].size(); ++col)
							matrix_[0][col][layer_] = value_;
						if (matrix_.size() % 2 == 1) {
							for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
								matrix_[matrix_.size() - 1][col][layer_] = value_;
						}
						else for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col) {
							matrix_[matrix_.size() - 2][col][layer_] = value_;
							matrix_[matrix_.size() - 1][col][layer_] = value_;
						}
						for (std::size_t row{}; row < matrix_.size(); ++row) {
							if (matrix_[row].size() < 2) continue;
							matrix_[row][0][layer_] = value_;
							if (matrix_[row].size() % 2 == 0) matrix_[row][matrix_[row].size() - 2][layer_] = value_;
							matrix_[row][matrix_[row].size() - 1][layer_] = value_;
						}
					}
					//クラス版
					template<typename Matrix_Int_>
					class BorderOdd {
					public:
						//コンストラクタ
						constexpr BorderOdd() noexcept = default;
						template<typename Matrix_>
						constexpr explicit BorderOdd(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_ = 1) noexcept {
							create(matrix_, layer_, value_);
						}
						template<typename Matrix_>
						constexpr void create(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_ = 1) noexcept {
							dtl::generator::common::layer::stl::createBorderOdd(matrix_, layer_, value_);
						}
					};
				}
			}



			//----------   PointGridField   ----------
			//PointGrid + BorderOdd

			namespace data {

				enum ePointGridField {
					point_grid_field_empty_id,
					point_grid_field_wall_id,
					point_grid_field_enum_num
				};
				constexpr bool point_grid_field_bool{ (point_grid_field_enum_num <= 2) ? true : false };

			}

			namespace array {
				//Array版
				template<typename Matrix_>
				constexpr void createPointGridField(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
					dtl::generator::common::array::createPointGrid(matrix_, x_, y_);
					dtl::generator::common::array::createBorderOdd(matrix_, x_, y_);
				}
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createPointGridField(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
					dtl::generator::common::array::createPointGrid(matrix_, x_, y_, value_);
					dtl::generator::common::array::createBorderOdd(matrix_, x_, y_, value_);
				}
				template<typename Matrix_Int_>
				class PointGridField {
				public:
					//コンストラクタ
					constexpr PointGridField() noexcept = default;
					template<typename Matrix_>
					constexpr explicit PointGridField(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, x_, y_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						dtl::generator::common::array::createPointGrid(matrix_, x_, y_, value_);
						dtl::generator::common::array::createBorderOdd(matrix_, x_, y_, value_);
					}
				};
			}

			namespace normal {
				//Default版
				template<typename Matrix_>
				constexpr void createPointGridField(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
					dtl::generator::common::normal::createPointGrid(matrix_, x_, y_);
					dtl::generator::common::normal::createBorderOdd(matrix_, x_, y_);
				}
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createPointGridField(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
					dtl::generator::common::normal::createPointGrid(matrix_, x_, y_, value_);
					dtl::generator::common::normal::createBorderOdd(matrix_, x_, y_, value_);
				}
				//クラス版
				template<typename Matrix_Int_>
				class PointGridField {
				public:
					//コンストラクタ
					constexpr PointGridField() noexcept = default;
					template<typename Matrix_>
					constexpr explicit PointGridField(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, x_, y_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						dtl::generator::common::normal::createPointGrid(matrix_, x_, y_, value_);
						dtl::generator::common::normal::createBorderOdd(matrix_, x_, y_, value_);
					}
				};
			}
			namespace stl {
				//STL版(1)
				template<typename Matrix_>
				constexpr void createPointGridField(Matrix_& matrix_) noexcept {
					dtl::generator::common::stl::createPointGrid(matrix_);
					dtl::generator::common::stl::createBorderOdd(matrix_);
				}
				//STL版(2)
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createPointGridField(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
					dtl::generator::common::stl::createPointGrid(matrix_, value_);
					dtl::generator::common::stl::createBorderOdd(matrix_, value_);
				}
				//クラス版
				template<typename Matrix_Int_>
				class PointGridField {
				public:
					//コンストラクタ
					constexpr PointGridField() noexcept = default;
					template<typename Matrix_>
					constexpr explicit PointGridField(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
						dtl::generator::common::stl::createPointGrid(matrix_, value_);
						dtl::generator::common::stl::createBorderOdd(matrix_, value_);
					}
				};
			}

			namespace layer {
				namespace normal {
					//Default版
					template<typename Matrix_>
					constexpr void createPointGridField(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
						dtl::generator::common::layer::normal::createPointGrid(matrix_, layer_, x_, y_);
						dtl::generator::common::layer::normal::createBorderOdd(matrix_, layer_, x_, y_);
					}
					template<typename Matrix_Int_, typename Matrix_>
					constexpr void createPointGridField(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
						dtl::generator::common::layer::normal::createPointGrid(matrix_, layer_, x_, y_, value_);
						dtl::generator::common::layer::normal::createBorderOdd(matrix_, layer_, x_, y_, value_);
					}
					//クラス版
					template<typename Matrix_Int_>
					class PointGridField {
					public:
						//コンストラクタ
						constexpr PointGridField() noexcept = default;
						template<typename Matrix_>
						constexpr explicit PointGridField(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
							create(matrix_, layer_, x_, y_, value_);
						}
						template<typename Matrix_>
						constexpr void create(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
							dtl::generator::common::layer::normal::createPointGrid(matrix_, layer_, x_, y_, value_);
							dtl::generator::common::layer::normal::createBorderOdd(matrix_, layer_, x_, y_, value_);
						}
					};
				}
				namespace stl {
					//STL版(1)
					template<typename Matrix_>
					constexpr void createPointGridField(Matrix_& matrix_, std::size_t layer_) noexcept {
						dtl::generator::common::layer::stl::createPointGrid(matrix_, layer_);
						dtl::generator::common::layer::stl::createBorderOdd(matrix_, layer_);
					}
					//STL版(2)
					template<typename Matrix_Int_, typename Matrix_>
					constexpr void createPointGridField(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_) noexcept {
						dtl::generator::common::layer::stl::createPointGrid(matrix_, layer_, value_);
						dtl::generator::common::layer::stl::createBorderOdd(matrix_, layer_, value_);
					}
					//クラス版
					template<typename Matrix_Int_>
					class PointGridField {
					public:
						//コンストラクタ
						constexpr PointGridField() noexcept = default;
						template<typename Matrix_>
						constexpr explicit PointGridField(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_ = 1) noexcept {
							create(matrix_, layer_, value_);
						}
						template<typename Matrix_>
						constexpr void create(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_ = 1) noexcept {
							dtl::generator::common::layer::stl::createPointGrid(matrix_, layer_, value_);
							dtl::generator::common::layer::stl::createBorderOdd(matrix_, layer_, value_);
						}
					};
				}
			}


			//----------   PointGridFieldPutBlock   ----------
			//PointGrid + BorderOdd + 枠の内部の空マスを指定した確率で埋める

			namespace data {

				enum ePointGridFieldPutBlock {
					point_grid_field_put_block_empty_id,
					point_grid_field_put_block_wall_id,
					point_grid_field_put_block_block_id,
					point_grid_field_put_block_enum_num
				};
				constexpr bool point_grid_field_put_block_bool{ (point_grid_field_put_block_enum_num <= 2) ? true : false };

			}

			//STL版
			namespace stl {
				template<typename Matrix_>
				constexpr void createPointGridFieldPlayerSpace(Matrix_& matrix_) noexcept {
					if (matrix_.size() < 3 || matrix_[1].size() < 3) return;
					const std::size_t y_end{ ((matrix_.size() % 2 == 0) ? (matrix_.size() - 2) : (matrix_.size() - 1)) };
					const std::size_t x_end{ ((matrix_[1].size() % 2 == 0) ? (matrix_[1].size() - 2) : (matrix_[1].size() - 1)) };

					matrix_[1][1] = 0;
					matrix_[1][2] = 0;
					matrix_[2][1] = 0;
					matrix_[y_end - 1][1] = 0;
					matrix_[y_end - 1][2] = 0;
					matrix_[y_end - 2][1] = 0;
					matrix_[1][x_end - 1] = 0;
					matrix_[1][x_end - 2] = 0;
					matrix_[2][x_end - 1] = 0;
					matrix_[y_end - 1][x_end - 1] = 0;
					matrix_[y_end - 1][x_end - 2] = 0;
					matrix_[y_end - 2][x_end - 1] = 0;
				}
				template<typename Matrix_Int_>
				class PointGridFieldPutBlock {
				public:
					//コンストラクタ
					constexpr PointGridFieldPutBlock() noexcept = default;
					template<typename Matrix_>
					constexpr explicit PointGridFieldPutBlock(Matrix_& matrix_, const double probability_ = 0.8, const Matrix_Int_ hard_value_ = 1, const Matrix_Int_ soft_value_ = 2) noexcept {
						create(matrix_, probability_, hard_value_, soft_value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const double probability_ = 0.8, const Matrix_Int_ hard_value_ = 1, const Matrix_Int_ soft_value_ = 2) noexcept {
						
						using dtl::random::mersenne_twister_32bit;
						
						dtl::generator::common::stl::createPointGrid(matrix_, hard_value_);
						dtl::generator::common::stl::createBorderOdd(matrix_, hard_value_);
						for (std::size_t row{}; row < matrix_.size(); ++row)
							for (std::size_t col{}; col < matrix_[row].size(); ++col)
								if (matrix_[row][col] == 0 && mersenne_twister_32bit.probability(probability_)) matrix_[row][col] = soft_value_;
						dtl::generator::common::stl::createPointGridFieldPlayerSpace(matrix_);
					}
				};
			}
			//Default版
			namespace normal {
				template<typename Matrix_>
				constexpr void createPointGridFieldPlayerSpace(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
					if (y_ < 3 || x_ < 3) return;
					const std::size_t y_end{ ((y_ % 2 == 0) ? (y_ - 2) : (y_ - 1)) };
					const std::size_t x_end{ ((x_ % 2 == 0) ? (x_ - 2) : (x_ - 1)) };

					matrix_[1][1] = 0;
					matrix_[1][2] = 0;
					matrix_[2][1] = 0;
					matrix_[y_end - 1][1] = 0;
					matrix_[y_end - 1][2] = 0;
					matrix_[y_end - 2][1] = 0;
					matrix_[1][x_end - 1] = 0;
					matrix_[1][x_end - 2] = 0;
					matrix_[2][x_end - 1] = 0;
					matrix_[y_end - 1][x_end - 1] = 0;
					matrix_[y_end - 1][x_end - 2] = 0;
					matrix_[y_end - 2][x_end - 1] = 0;
				}
				template<typename Matrix_Int_>
				class PointGridFieldPutBlock {
				public:
					//コンストラクタ
					constexpr PointGridFieldPutBlock() noexcept = default;
					template<typename Matrix_>
					constexpr explicit PointGridFieldPutBlock(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const double probability_ = 0.8, const Matrix_Int_ hard_value_ = 1, const Matrix_Int_ soft_value_ = 2) noexcept {
						create(matrix_, x_, y_, probability_, hard_value_, soft_value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const double probability_ = 0.8, const Matrix_Int_ hard_value_ = 1, const Matrix_Int_ soft_value_ = 2) noexcept {
						
						using dtl::random::mersenne_twister_32bit;
						
						dtl::generator::common::normal::createPointGrid(matrix_, x_, y_, hard_value_);
						dtl::generator::common::normal::createBorderOdd(matrix_, x_, y_, hard_value_);
						for (std::size_t row{}; row < y_; ++row)
							for (std::size_t col{}; col < x_; ++col)
								if (matrix_[row][col] == 0 && mersenne_twister_32bit.probability(probability_)) matrix_[row][col] = soft_value_;
						dtl::generator::common::normal::createPointGridFieldPlayerSpace(matrix_, x_, y_);
					}
				};
			}
			//Array版
			namespace array {
				template<typename Matrix_>
				constexpr void createPointGridFieldPlayerSpace(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
					if (y_ < 3 || x_ < 3) return;
					const std::size_t y_end{ ((y_ % 2 == 0) ? (y_ - 2) : (y_ - 1)) };
					const std::size_t x_end{ ((x_ % 2 == 0) ? (x_ - 2) : (x_ - 1)) };

					matrix_[x_ + 1] = 0;
					matrix_[x_ + 2] = 0;
					matrix_[2 * x_ + 1] = 0;
					matrix_[(y_end - 1) * x_ + 1] = 0;
					matrix_[(y_end - 1) * x_ + 2] = 0;
					matrix_[(y_end - 2) * x_ + 1] = 0;
					matrix_[x_ + x_end - 1] = 0;
					matrix_[x_ + x_end - 2] = 0;
					matrix_[2 * x_ + x_end - 1] = 0;
					matrix_[(y_end - 1) * x_ + x_end - 1] = 0;
					matrix_[(y_end - 1) * x_ + x_end - 2] = 0;
					matrix_[(y_end - 2) * x_ + x_end - 1] = 0;
				}
				template<typename Matrix_Int_>
				class PointGridFieldPutBlock {
				public:
					//コンストラクタ
					constexpr PointGridFieldPutBlock() noexcept = default;
					template<typename Matrix_>
					constexpr explicit PointGridFieldPutBlock(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const double probability_ = 0.8, const Matrix_Int_ hard_value_ = 1, const Matrix_Int_ soft_value_ = 2) noexcept {
						create(matrix_, x_, y_, probability_, hard_value_, soft_value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const double probability_ = 0.8, const Matrix_Int_ hard_value_ = 1, const Matrix_Int_ soft_value_ = 2) noexcept {
						
						using dtl::random::mersenne_twister_32bit;
						
						dtl::generator::common::array::createPointGrid(matrix_, x_, y_, hard_value_);
						dtl::generator::common::array::createBorderOdd(matrix_, x_, y_, hard_value_);
						for (std::size_t row{}; row < y_; ++row)
							for (std::size_t col{}; col < x_; ++col)
								if (matrix_[row * x_ + col] == 0 && mersenne_twister_32bit.probability(probability_)) matrix_[row * x_ + col] = soft_value_;
						dtl::generator::common::array::createPointGridFieldPlayerSpace(matrix_, x_, y_);
					}
				};
			}


			//----------   Line   ----------
			//beta

			namespace stl {

				//STL版(1)
				template<typename Matrix_>
				constexpr void createLineDown(Matrix_& matrix_) noexcept {
					if (matrix_.size() == 0) return;
					for (std::size_t col{}; col < matrix_[0].size(); ++col)
						matrix_[0][col] = 1;
				}
				template<typename Matrix_>
				constexpr void createLineUp(Matrix_& matrix_) noexcept {
					if (matrix_.size() == 0) return;
					for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
						matrix_[matrix_.size() - 1][col] = 1;
				}
				template<typename Matrix_>
				constexpr void createLineLeft(Matrix_& matrix_) noexcept {
					if (matrix_.size() == 0) return;
					for (std::size_t row{}; row < matrix_.size(); ++row) {
						if (matrix_[row].size() == 0) continue;
						matrix_[row][0] = 1;
					}
				}
				template<typename Matrix_>
				constexpr void createLineRight(Matrix_& matrix_) noexcept {
					if (matrix_.size() == 0) return;
					for (std::size_t row{}; row < matrix_.size(); ++row) {
						if (matrix_[row].size() == 0) continue;
						matrix_[row][matrix_[row].size() - 1] = 1;
					}
				}

				//----------   OneLine   ----------

				//STL版(1)
				template<typename Matrix_>
				constexpr void createOneLineDown(Matrix_& matrix_) noexcept {
					if (matrix_.size() == 0) return;
					for (std::size_t col{}; col < matrix_[0].size(); ++col)
						matrix_[0][col] = 1;
				}
				template<typename Matrix_>
				constexpr void createOneLineUp(Matrix_& matrix_) noexcept {
					if (matrix_.size() == 0) return;
					for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
						matrix_[matrix_.size() - 1][col] = 1;
				}
				template<typename Matrix_>
				constexpr void createOneLineLeft(Matrix_& matrix_) noexcept {
					if (matrix_.size() == 0) return;
					for (std::size_t row{}; row < matrix_.size(); ++row) {
						if (matrix_[row].size() == 0) continue;
						matrix_[row][0] = 1;
					}
				}
				template<typename Matrix_>
				constexpr void createOneLineRight(Matrix_& matrix_) noexcept {
					if (matrix_.size() == 0) return;
					for (std::size_t row{}; row < matrix_.size(); ++row) {
						if (matrix_[row].size() == 0) continue;
						matrix_[row][matrix_[row].size() - 1] = 1;
					}
				}
				//STL版(2)
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createOneLineDown(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
					if (matrix_.size() == 0) return;
					for (std::size_t col{}; col < matrix_[0].size(); ++col)
						matrix_[0][col] = value_;
				}
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createOneLineUp(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
					if (matrix_.size() == 0) return;
					for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
						matrix_[matrix_.size() - 1][col] = value_;
				}
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createOneLineLeft(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
					if (matrix_.size() == 0) return;
					for (std::size_t row{}; row < matrix_.size(); ++row) {
						if (matrix_[row].size() == 0) continue;
						matrix_[row][0] = value_;
					}
				}
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createOneLineRight(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
					if (matrix_.size() == 0) return;
					for (std::size_t row{}; row < matrix_.size(); ++row) {
						if (matrix_[row].size() == 0) continue;
						matrix_[row][matrix_[row].size() - 1] = value_;
					}
				}
				//Default版
				template<typename Matrix_>
				constexpr void createOneLineDown(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
					if (y_ == 0) return;
					for (std::size_t col{}; col < x_; ++col)
						matrix_[0][col] = 1;
				}
				template<typename Matrix_>
				constexpr void createOneLineUp(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
					if (y_ == 0) return;
					for (std::size_t col{}; col < x_; ++col)
						matrix_[y_ - 1][col] = 1;
				}
				template<typename Matrix_>
				constexpr void createOneLineLeft(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
					if (dtl::utility::isEmpty(x_, y_)) return;
					for (std::size_t row{}; row < y_; ++row) {
						matrix_[row][0] = 1;
					}
				}
				template<typename Matrix_>
				constexpr void createOneLineRight(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
					if (dtl::utility::isEmpty(x_, y_)) return;
					for (std::size_t row{}; row < y_; ++row) {
						matrix_[row][x_ - 1] = 1;
					}
				}
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createOneLineDown(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
					if (y_ == 0) return;
					for (std::size_t col{}; col < x_; ++col)
						matrix_[0][col] = value_;
				}
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createOneLineUp(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
					if (y_ == 0) return;
					for (std::size_t col{}; col < x_; ++col)
						matrix_[y_ - 1][col] = value_;
				}
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createOneLineLeft(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
					if (dtl::utility::isEmpty(x_, y_)) return;
					for (std::size_t row{}; row < y_; ++row) {
						matrix_[row][0] = value_;
					}
				}
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createOneLineRight(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
					if (dtl::utility::isEmpty(x_, y_)) return;
					for (std::size_t row{}; row < y_; ++row) {
						matrix_[row][x_ - 1] = value_;
					}
				}
				//Array版
				template<typename Matrix_>
				constexpr void createOneLineDown_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
					if (y_ == 0) return;
					for (std::size_t col{}; col < x_; ++col)
						matrix_[col] = 1;
				}
				template<typename Matrix_>
				constexpr void createOneLineUp_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
					if (y_ == 0) return;
					for (std::size_t col{}; col < x_; ++col)
						matrix_[(y_ - 1)*x_ + col] = 1;
				}
				template<typename Matrix_>
				constexpr void createOneLineLeft_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
					if (dtl::utility::isEmpty(x_, y_)) return;
					for (std::size_t row{}; row < y_; ++row) {
						matrix_[row*x_] = 1;
					}
				}
				template<typename Matrix_>
				constexpr void createOneLineRight_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
					if (dtl::utility::isEmpty(x_, y_)) return;
					for (std::size_t row{}; row < y_; ++row) {
						matrix_[row*x_ + x_ - 1] = 1;
					}
				}
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createOneLineDown_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
					if (y_ == 0) return;
					for (std::size_t col{}; col < x_; ++col)
						matrix_[col] = value_;
				}
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createOneLineUp_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
					if (y_ == 0) return;
					for (std::size_t col{}; col < x_; ++col)
						matrix_[(y_ - 1)*x_ + col] = value_;
				}
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createOneLineLeft_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
					if (dtl::utility::isEmpty(x_, y_)) return;
					for (std::size_t row{}; row < y_; ++row) {
						matrix_[row*x_] = value_;
					}
				}
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createOneLineRight_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
					if (dtl::utility::isEmpty(x_, y_)) return;
					for (std::size_t row{}; row < y_; ++row) {
						matrix_[row*x_ + x_ - 1] = value_;
					}
				}
				//クラス版
				template<typename Matrix_Int_>
				class OneLineUp {
				public:
					//コンストラクタ
					constexpr OneLineUp() noexcept = default;
					template<typename Matrix_>
					constexpr explicit OneLineUp(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
						createOneLineUp(matrix_, value_);
					}
					template<typename Matrix_>
					constexpr explicit OneLineUp(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, x_, y_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						createOneLineUp(matrix_, x_, y_, value_);
					}
				};
				template<typename Matrix_Int_>
				class OneLineUp_Array {
				public:
					//コンストラクタ
					constexpr OneLineUp_Array() noexcept = default;
					template<typename Matrix_>
					constexpr explicit OneLineUp_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, x_, y_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						createOneLineUp_Array(matrix_, x_, y_, value_);
					}
				};
				//クラス版
				template<typename Matrix_Int_>
				class OneLineDown {
				public:
					//コンストラクタ
					constexpr OneLineDown() noexcept = default;
					template<typename Matrix_>
					constexpr explicit OneLineDown(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
						createOneLineDown(matrix_, value_);
					}
					template<typename Matrix_>
					constexpr explicit OneLineDown(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, x_, y_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						createOneLineDown(matrix_, x_, y_, value_);
					}
				};
				template<typename Matrix_Int_>
				class OneLineDown_Array {
				public:
					//コンストラクタ
					constexpr OneLineDown_Array() noexcept = default;
					template<typename Matrix_>
					constexpr explicit OneLineDown_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, x_, y_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						createOneLineDown_Array(matrix_, x_, y_, value_);
					}
				};
				//クラス版
				template<typename Matrix_Int_>
				class OneLineLeft {
				public:
					//コンストラクタ
					constexpr OneLineLeft() noexcept = default;
					template<typename Matrix_>
					constexpr explicit OneLineLeft(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
						createOneLineLeft(matrix_, value_);
					}
					template<typename Matrix_>
					constexpr explicit OneLineLeft(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, x_, y_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						createOneLineLeft(matrix_, x_, y_, value_);
					}
				};
				template<typename Matrix_Int_>
				class OneLineLeft_Array {
				public:
					//コンストラクタ
					constexpr OneLineLeft_Array() noexcept = default;
					template<typename Matrix_>
					constexpr explicit OneLineLeft_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, x_, y_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						createOneLineLeft_Array(matrix_, x_, y_, value_);
					}
				};
				//クラス版
				template<typename Matrix_Int_>
				class OneLineRight {
				public:
					//コンストラクタ
					constexpr OneLineRight() noexcept = default;
					template<typename Matrix_>
					constexpr explicit OneLineRight(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
						createOneLineRight(matrix_, value_);
					}
					template<typename Matrix_>
					constexpr explicit OneLineRight(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, x_, y_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						createOneLineRight(matrix_, x_, y_, value_);
					}
				};
				template<typename Matrix_Int_>
				class OneLineRight_Array {
				public:
					//コンストラクタ
					constexpr OneLineRight_Array() noexcept = default;
					template<typename Matrix_>
					constexpr explicit OneLineRight_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, x_, y_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						createOneLineRight_Array(matrix_, x_, y_, value_);
					}
				};

			}

			//----------   Border   ----------
			//1.マップの外枠を1で埋める
			//2.マップの外枠を指定した数値で埋める

			namespace data {

				enum eBorder {
					border_empty_id,
					border_wall_id,
					border_enum_num
				};
				constexpr bool border_bool{ (border_enum_num <= 2) ? true : false };

			}

			namespace stl {
				//STL版(1)
				template<typename Matrix_>
				constexpr void createBorder(Matrix_& matrix_) noexcept {
					if (matrix_.size() == 0) return;
					for (std::size_t col{}; col < matrix_[0].size(); ++col)
						matrix_[0][col] = 1;
					for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
						matrix_[matrix_.size() - 1][col] = 1;
					for (std::size_t row{}; row < matrix_.size(); ++row) {
						if (matrix_[row].size() == 0) continue;
						matrix_[row][0] = 1;
						matrix_[row][matrix_[row].size() - 1] = 1;
					}
				}
				//STL版(2)
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createBorder(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
					if (matrix_.size() == 0) return;
					for (std::size_t col{}; col < matrix_[0].size(); ++col)
						matrix_[0][col] = value_;
					for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
						matrix_[matrix_.size() - 1][col] = value_;
					for (std::size_t row{}; row < matrix_.size(); ++row) {
						if (matrix_[row].size() == 0) continue;
						matrix_[row][0] = value_;
						matrix_[row][matrix_[row].size() - 1] = value_;
					}
				}
				//クラス版
				template<typename Matrix_Int_>
				class Border {
				public:
					//コンストラクタ
					constexpr Border() noexcept = default;
					template<typename Matrix_>
					constexpr explicit Border(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
						dtl::generator::common::stl::createBorder(matrix_, value_);
					}
				};
			}
			namespace normal {
				//Default版
				template<typename Matrix_>
				constexpr void createBorder(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
					if (y_ == 0) return;
					for (std::size_t col{}; col < x_; ++col)
						matrix_[0][col] = 1;
					for (std::size_t col{}; col < x_; ++col)
						matrix_[y_ - 1][col] = 1;
					if (x_ == 0) return;
					for (std::size_t row{}; row < y_; ++row) {
						matrix_[row][0] = 1;
						matrix_[row][x_ - 1] = 1;
					}
				}
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createBorder(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
					if (y_ == 0) return;
					for (std::size_t col{}; col < x_; ++col)
						matrix_[0][col] = value_;
					for (std::size_t col{}; col < x_; ++col)
						matrix_[y_ - 1][col] = value_;
					if (x_ == 0) return;
					for (std::size_t row{}; row < y_; ++row) {
						matrix_[row][0] = value_;
						matrix_[row][x_ - 1] = value_;
					}
				}
				//クラス版
				template<typename Matrix_Int_>
				class Border {
				public:
					//コンストラクタ
					constexpr Border() noexcept = default;
					template<typename Matrix_>
					constexpr explicit Border(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, x_, y_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						dtl::generator::common::normal::createBorder(matrix_, x_, y_, value_);
					}
				};
			}
			namespace layer {
				namespace stl {
					//STL版(1)
					template<typename Matrix_>
					constexpr void createBorder(Matrix_& matrix_, std::size_t layer_) noexcept {
						if (matrix_.size() == 0) return;
						for (std::size_t col{}; col < matrix_[0].size(); ++col)
							matrix_[0][col][layer_] = 1;
						for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
							matrix_[matrix_.size() - 1][col][layer_] = 1;
						for (std::size_t row{}; row < matrix_.size(); ++row) {
							if (matrix_[row].size() == 0) continue;
							matrix_[row][0][layer_] = 1;
							matrix_[row][matrix_[row].size() - 1][layer_] = 1;
						}
					}
					//STL版(2)
					template<typename Matrix_Int_, typename Matrix_>
					constexpr void createBorder(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_) noexcept {
						if (matrix_.size() == 0) return;
						for (std::size_t col{}; col < matrix_[0].size(); ++col)
							matrix_[0][col][layer_] = value_;
						for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
							matrix_[matrix_.size() - 1][col][layer_] = value_;
						for (std::size_t row{}; row < matrix_.size(); ++row) {
							if (matrix_[row].size() == 0) continue;
							matrix_[row][0][layer_] = value_;
							matrix_[row][matrix_[row].size() - 1][layer_] = value_;
						}
					}
					//クラス版
					template<typename Matrix_Int_>
					class Border {
					public:
						//コンストラクタ
						constexpr Border() noexcept = default;
						template<typename Matrix_>
						constexpr explicit Border(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_ = 1) noexcept {
							create(matrix_, layer_, value_);
						}
						template<typename Matrix_>
						constexpr void create(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_ = 1) noexcept {
							dtl::generator::common::layer::stl::createBorder(matrix_, layer_, value_);
						}
					};
				}
				namespace normal {
					//Default版
					template<typename Matrix_>
					constexpr void createBorder(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
						if (y_ == 0) return;
						for (std::size_t col{}; col < x_; ++col)
							matrix_[0][col][layer_] = 1;
						for (std::size_t col{}; col < x_; ++col)
							matrix_[y_ - 1][col][layer_] = 1;
						if (x_ == 0) return;
						for (std::size_t row{}; row < y_; ++row) {
							matrix_[row][0][layer_] = 1;
							matrix_[row][x_ - 1][layer_] = 1;
						}
					}
					template<typename Matrix_Int_, typename Matrix_>
					constexpr void createBorder(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
						if (y_ == 0) return;
						for (std::size_t col{}; col < x_; ++col)
							matrix_[0][col][layer_] = value_;
						for (std::size_t col{}; col < x_; ++col)
							matrix_[y_ - 1][col][layer_] = value_;
						if (x_ == 0) return;
						for (std::size_t row{}; row < y_; ++row) {
							matrix_[row][0][layer_] = value_;
							matrix_[row][x_ - 1][layer_] = value_;
						}
					}
					//クラス版
					template<typename Matrix_Int_>
					class Border {
					public:
						//コンストラクタ
						constexpr Border() noexcept = default;
						template<typename Matrix_>
						constexpr explicit Border(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
							create(matrix_, layer_, x_, y_, value_);
						}
						template<typename Matrix_>
						constexpr void create(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
							dtl::generator::common::layer::normal::createBorder(matrix_, layer_, x_, y_, value_);
						}
					};
				}
			}
			namespace array {
				//Array版
				template<typename Matrix_>
				constexpr void createBorder(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
					if (y_ == 0) return;
					for (std::size_t col{}; col < x_; ++col)
						matrix_[col] = 1;
					for (std::size_t col{}; col < x_; ++col)
						matrix_[(y_ - 1) * x_ + col] = 1;
					if (x_ == 0) return;
					for (std::size_t row{}; row < y_; ++row) {
						matrix_[row * x_] = 1;
						matrix_[row * x_ + x_ - 1] = 1;
					}
				}
				template<typename Matrix_Int_, typename Matrix_>
				constexpr void createBorder(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
					if (y_ == 0) return;
					for (std::size_t col{}; col < x_; ++col)
						matrix_[col] = value_;
					for (std::size_t col{}; col < x_; ++col)
						matrix_[(y_ - 1) * x_ + col] = value_;
					if (x_ == 0) return;
					for (std::size_t row{}; row < y_; ++row) {
						matrix_[row * x_] = value_;
						matrix_[row * x_ + x_ - 1] = value_;
					}
				}
				template<typename Matrix_Int_>
				class Border {
				public:
					//コンストラクタ
					constexpr Border() noexcept = default;
					template<typename Matrix_>
					constexpr explicit Border(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						create(matrix_, x_, y_, value_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
						dtl::generator::common::array::createBorder(matrix_, x_, y_, value_);
					}
				};
			}

		} //namespace
	}
}

#endif //Included Dungeon Template Library