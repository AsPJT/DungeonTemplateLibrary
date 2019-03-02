#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_GENERATOR_COMMON_DUNGEON_INIT
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_GENERATOR_COMMON_DUNGEON_INIT
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>

//総合データ
namespace dtl::generator::common::data {

	//----------   DungeonInit   ----------
	//1.全てのマスを0で埋める
	//2.全てのマスを指定した数値で埋める

	enum eDungeonInit {
		dungeon_init_empty_id,
		dungeon_init_enum_num
	};
	constexpr bool dungeon_init_bool{ (dungeon_init_enum_num <= 2) ? true : false };

} //namespace

//STLデータ
namespace dtl::generator::common::stl {

	//全てのマスを0で埋める
	template<typename Matrix_>
	constexpr void createDungeonInit(Matrix_& matrix_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				matrix_[row][col] = 0;
	}
	//全てのマスを指定した数値で埋める
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createDungeonInit(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
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
			dtl::generator::common::stl::createDungeonInit(matrix_, value_);
		}
	};

} //namespace

//通常データ
namespace dtl::generator::common::normal {

	//全てのマスを0で埋める
	template<typename Matrix_>
	constexpr void createDungeonInit(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row][col] = 0;
	}
	//全てのマスを指定した数値で埋める
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createDungeonInit(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row][col] = value_;
	}
	template<typename Matrix_>
	constexpr void createDungeonInit(Matrix_& matrix_, const std::size_t start_x_, const std::size_t start_y_, const std::size_t end_x_, const std::size_t end_y_) noexcept {
		for (std::size_t row{ start_y_ }; row < end_y_; ++row)
			for (std::size_t col{ start_x_ }; col < end_x_; ++col)
				matrix_[row][col] = 0;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createDungeonInit(Matrix_& matrix_, const std::size_t start_x_, const std::size_t start_y_, const std::size_t end_x_, const std::size_t end_y_, const Matrix_Int_ value_) noexcept {
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
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 0) const noexcept {
			dtl::generator::common::normal::createDungeonInit(matrix_, x_, y_, value_);
		}
	};

} //namespace

//配列データ
namespace dtl::generator::common::array {

	//全てのマスを0で埋める
	template<typename Matrix_>
	constexpr void createDungeonInit(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row * x_ + col] = 0;
	}
	//全てのマスを指定した数値で埋める
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createDungeonInit(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row * x_ + col] = value_;
	}
	template<typename Matrix_>
	constexpr void createDungeonInit(Matrix_& matrix_, const std::size_t start_x_, const std::size_t start_y_, const std::size_t end_x_, const std::size_t end_y_) noexcept {
		for (std::size_t row{ start_y_ }; row < end_y_; ++row)
			for (std::size_t col{ start_x_ }; col < end_x_; ++col)
				matrix_[row * end_x_ + col] = 0;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createDungeonInit(Matrix_& matrix_, const std::size_t start_x_, const std::size_t start_y_, const std::size_t end_x_, const std::size_t end_y_, const Matrix_Int_ value_) noexcept {
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
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 0) const noexcept {
			dtl::generator::common::array::createDungeonInit(matrix_, x_, y_, value_);
		}
	};

} //namespace

//範囲forデータ
namespace dtl::generator::common::rangeBasedFor {

	//全てのマスを0で埋める
	template<typename Matrix_>
	constexpr void createDungeonInit(Matrix_& matrix_) noexcept {
		for (auto&& row : matrix_)
			for (auto&& col : row)
				col = 0;
	}
	//全てのマスを指定した数値で埋める
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createDungeonInit(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		for (auto&& row : matrix_)
			for (auto&& col : row)
				col = value_;
	}

} //namespace

//レイヤーSTLデータ
namespace dtl::generator::common::layer::stl {

	//全てのマスを0で埋める
	template<typename Matrix_>
	constexpr void createDungeonInit(Matrix_& matrix_, std::size_t layer_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				matrix_[row][col][layer_] = 0;
	}
	//全てのマスを指定した数値で埋める
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createDungeonInit(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_) noexcept {
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
		constexpr void create(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_ = 0) const noexcept {
			dtl::generator::common::layer::stl::createDungeonInit(matrix_, layer_, value_);
		}
	};

} //namespace

//レイヤー通常データ
namespace dtl::generator::common::layer::normal {

	//全てのマスを0で埋める
	template<typename Matrix_>
	constexpr void createDungeonInit(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row][col][layer_] = 0;
	}
	//全てのマスを指定した数値で埋める
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createDungeonInit(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row][col][layer_] = value_;
	}
	template<typename Matrix_>
	constexpr void createDungeonInit(Matrix_& matrix_, std::size_t layer_, const std::size_t start_x_, const std::size_t start_y_, const std::size_t end_x_, const std::size_t end_y_) noexcept {
		for (std::size_t row{ start_y_ }; row < end_y_; ++row)
			for (std::size_t col{ start_x_ }; col < end_x_; ++col)
				matrix_[row][col][layer_] = 0;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createDungeonInit(Matrix_& matrix_, std::size_t layer_, const std::size_t start_x_, const std::size_t start_y_, const std::size_t end_x_, const std::size_t end_y_, const Matrix_Int_ value_) noexcept {
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
		constexpr void create(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 0) const noexcept {
			dtl::generator::common::layer::normal::createDungeonInit(matrix_, layer_, x_, y_, value_);
		}
	};

} //namespace

#endif //Included Dungeon Template Library