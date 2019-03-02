#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_INIT
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_INIT
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>

namespace dtl::utility::stl {

	//ダンジョン内の値を初期化する
	template<typename Matrix_>
	constexpr void init(Matrix_& matrix_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				matrix_[row][col] = 0;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void init(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				matrix_[row][col] = value_;
	}
	//クラス版
	class Init {
	public:
		template<typename Matrix_>
		constexpr explicit Init(Matrix_& matrix_) noexcept {
			for (std::size_t row{}; row < matrix_.size(); ++row)
				for (std::size_t col{}; col < matrix_[row].size(); ++col)
					matrix_[row][col] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr explicit Init(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
			for (std::size_t row{}; row < matrix_.size(); ++row)
				for (std::size_t col{}; col < matrix_[row].size(); ++col)
					matrix_[row][col] = value_;
		}
		template<typename Matrix_>
		constexpr void operator()(Matrix_& matrix_) const noexcept {
			for (std::size_t row{}; row < matrix_.size(); ++row)
				for (std::size_t col{}; col < matrix_[row].size(); ++col)
					matrix_[row][col] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr void operator()(Matrix_& matrix_, const Matrix_Int_ value_) const noexcept {
			for (std::size_t row{}; row < matrix_.size(); ++row)
				for (std::size_t col{}; col < matrix_[row].size(); ++col)
					matrix_[row][col] = value_;
		}
	};

} //namespace

namespace dtl::utility::normal {

	template<typename Matrix_>
	constexpr void init(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row][col] = 0;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void init(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row][col] = value_;
	}

	//クラス版
	class Init {
	public:
		template<typename Matrix_>
		constexpr explicit Init(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row][col] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr explicit Init(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row][col] = value_;
		}
		template<typename Matrix_>
		constexpr void operator()(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) const noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row][col] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr void operator()(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) const noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row][col] = value_;
		}
	};

} //namespace

namespace dtl::utility::array {

	template<typename Matrix_>
	constexpr void init(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row*x_ + col] = 0;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void init(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row*x_ + col] = value_;
	}

	//クラス版
	class Init {
	public:
		template<typename Matrix_>
		constexpr explicit Init(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row*x_ + col] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr explicit Init(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row*x_ + col] = value_;
		}
		template<typename Matrix_>
		constexpr void operator()(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) const noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row*x_ + col] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr void operator()(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) const noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row*x_ + col] = value_;
		}
	};

} //namespace

namespace dtl::utility::layer::stl {

	//ダンジョン内の値を初期化する
	template<typename Matrix_>
	constexpr void init(Matrix_& matrix_, std::size_t layer_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				matrix_[row][col][layer_] = 0;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void init(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				matrix_[row][col][layer_] = value_;
	}
	//クラス版
	class Init {
	public:
		template<typename Matrix_>
		constexpr explicit Init(Matrix_& matrix_, std::size_t layer_) noexcept {
			for (std::size_t row{}; row < matrix_.size(); ++row)
				for (std::size_t col{}; col < matrix_[row].size(); ++col)
					matrix_[row][col][layer_] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr explicit Init(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_) noexcept {
			for (std::size_t row{}; row < matrix_.size(); ++row)
				for (std::size_t col{}; col < matrix_[row].size(); ++col)
					matrix_[row][col][layer_] = value_;
		}
		template<typename Matrix_>
		constexpr void operator()(Matrix_& matrix_, std::size_t layer_) const noexcept {
			for (std::size_t row{}; row < matrix_.size(); ++row)
				for (std::size_t col{}; col < matrix_[row].size(); ++col)
					matrix_[row][col][layer_] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr void operator()(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_) const noexcept {
			for (std::size_t row{}; row < matrix_.size(); ++row)
				for (std::size_t col{}; col < matrix_[row].size(); ++col)
					matrix_[row][col][layer_] = value_;
		}
	};


} //namespace

namespace dtl::utility::layer::normal {

	template<typename Matrix_>
	constexpr void init(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row][col][layer_] = 0;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void init(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row][col][layer_] = value_;
	}
	//クラス版
	class Init {
	public:
		template<typename Matrix_>
		constexpr explicit Init(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row][col][layer_] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr explicit Init(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row][col][layer_] = value_;
		}
		template<typename Matrix_>
		constexpr void operator()(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_) const noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row][col][layer_] = 0;
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr void operator()(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) const noexcept {
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					matrix_[row][col][layer_] = value_;
		}
	};

} //namespace

#endif //Included Dungeon Template Library