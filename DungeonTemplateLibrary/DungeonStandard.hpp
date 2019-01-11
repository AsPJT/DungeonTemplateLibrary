#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_STANDARD
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_STANDARD
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>

//Dungeon Template Library Namespace
namespace dtl {

	template<typename STL_>
	constexpr void createPointGrid(STL_& stl_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t i{}; i < y_; i += 2)
			for (std::size_t j{}; j < x_; j += 2)
				stl_[i][j] = 1;
	}
	template<typename Int_, typename STL_>
	constexpr void createPointGrid(STL_& stl_, const std::size_t x_, const std::size_t y_, const Int_ value_) noexcept {
		for (std::size_t i{}; i < y_; i += 2)
			for (std::size_t j{}; j < x_; j += 2)
				stl_[i][j] = value_;
	}

	//
	template<typename STL_>
	constexpr void createPointGrid(STL_& stl_) noexcept {
		for (std::size_t i{}; i < stl_.size(); i += 2)
			for (std::size_t j{}; j < stl_[i].size(); j += 2)
				stl_[i][j] = 1;
	}
	template<typename Int_, typename STL_>
	constexpr void createPointGrid(STL_& stl_, const Int_ value_) noexcept {
		for (std::size_t i{}; i < stl_.size(); i += 2)
			for (std::size_t j{}; j < stl_[i].size(); j += 2)
				stl_[i][j] = value_;
	}
	//クラス版
	template<typename Int_>
	class PointGrid {
	public:
		//コンストラクタ
		constexpr PointGrid() noexcept = default;
		template<typename STL_>
		constexpr explicit PointGrid(STL_& stl_, const Int_ value_ = 1) noexcept {
			create(stl_, value_);
		}
		template<typename STL_>
		constexpr void create(STL_& stl_, const Int_ value_ = 1) noexcept {
			createPointGrid(stl_, value_);
		}
		template<typename STL_>
		constexpr explicit PointGrid(STL_& stl_, const std::size_t x_, const std::size_t y_, const Int_ value_ = 1) noexcept {
			create(stl_, x_, y_, value_);
		}
		template<typename STL_>
		constexpr void create(STL_& stl_, const std::size_t x_, const std::size_t y_, const Int_ value_ = 1) noexcept {
			createPointGrid(stl_, x_, y_, value_);
		}
	};

	//外枠(内部を奇数マスにする)
	template<typename STL_>
	constexpr void createBorderOdd(STL_& stl_, const std::size_t x_, const std::size_t y_) noexcept {
		if (y_ < 2) return;
		for (std::size_t i{}; i < x_; ++i)
			stl_[0][i] = 1;
		if (y_ % 2 == 1) {
			for (std::size_t i{}; i < x_; ++i)
				stl_[y_ - 1][i] = 1;
		}
		else for (std::size_t i{}; i < x_; ++i) {
			stl_[y_ - 2][i] = 1;
			stl_[y_ - 1][i] = 1;
		}
		if (x_ < 2) return;
		for (std::size_t i{}; i < y_; ++i) {
			stl_[i][0] = 1;
			if (x_ % 2 == 0) stl_[i][x_ - 2] = 1;
			stl_[i][x_ - 1] = 1;
		}
	}
	template<typename Int_, typename STL_>
	constexpr void createBorderOdd(STL_& stl_, const std::size_t x_, const std::size_t y_, const Int_ value_) noexcept {
		if (y_ < 2) return;
		for (std::size_t i{}; i < x_; ++i)
			stl_[0][i] = value_;
		if (y_ % 2 == 1) {
			for (std::size_t i{}; i < x_; ++i)
				stl_[y_ - 1][i] = value_;
		}
		else for (std::size_t i{}; i < x_; ++i) {
			stl_[y_ - 2][i] = value_;
			stl_[y_ - 1][i] = value_;
		}
		if (x_ < 2) return;
		for (std::size_t i{}; i < y_; ++i) {
			stl_[i][0] = value_;
			if (x_ % 2 == 0) stl_[i][x_ - 2] = value_;
			stl_[i][x_ - 1] = value_;
		}
	}

	//外枠(内部を奇数マスにする)
	template<typename STL_>
	constexpr void createBorderOdd(STL_& stl_) noexcept {
		if (stl_.size() < 2) return;
		for (std::size_t i{}; i < stl_[0].size(); ++i)
			stl_[0][i] = 1;
		if (stl_.size() % 2 == 1) {
			for (std::size_t i{}; i < stl_[stl_.size() - 1].size(); ++i)
				stl_[stl_.size() - 1][i] = 1;
		}
		else for (std::size_t i{}; i < stl_[stl_.size() - 1].size(); ++i) {
			stl_[stl_.size() - 2][i] = 1;
			stl_[stl_.size() - 1][i] = 1;
		}
		for (std::size_t i{}; i < stl_.size(); ++i) {
			if (stl_[i].size() < 2) continue;
			stl_[i][0] = 1;
			if (stl_[i].size() % 2 == 0) stl_[i][stl_[i].size() - 2] = 1;
			stl_[i][stl_[i].size() - 1] = 1;
		}
	}
	template<typename Int_, typename STL_>
	constexpr void createBorderOdd(STL_& stl_, const Int_ value_) noexcept {
		if (stl_.size() < 2) return;
		for (std::size_t i{}; i < stl_[0].size(); ++i)
			stl_[0][i] = value_;
		if (stl_.size() % 2 == 1) {
			for (std::size_t i{}; i < stl_[stl_.size() - 1].size(); ++i)
				stl_[stl_.size() - 1][i] = value_;
		}
		else for (std::size_t i{}; i < stl_[stl_.size() - 1].size(); ++i) {
			stl_[stl_.size() - 2][i] = value_;
			stl_[stl_.size() - 1][i] = value_;
		}
		for (std::size_t i{}; i < stl_.size(); ++i) {
			if (stl_[i].size() < 2) continue;
			stl_[i][0] = value_;
			if (stl_[i].size() % 2 == 0) stl_[i][stl_[i].size() - 2] = value_;
			stl_[i][stl_[i].size() - 1] = value_;
		}
	}
	//クラス版
	template<typename Int_>
	class BorderOdd {
	public:
		//コンストラクタ
		constexpr BorderOdd() noexcept = default;
		template<typename STL_>
		constexpr explicit BorderOdd(STL_& stl_, const Int_ value_ = 1) noexcept {
			create(stl_, value_);
		}
		template<typename STL_>
		constexpr void create(STL_& stl_, const Int_ value_ = 1) noexcept {
			createBorderOdd(stl_, value_);
		}
		template<typename STL_>
		constexpr explicit BorderOdd(STL_& stl_, const std::size_t x_, const std::size_t y_, const Int_ value_ = 1) noexcept {
			create(stl_, x_, y_, value_);
		}
		template<typename STL_>
		constexpr void create(STL_& stl_, const std::size_t x_, const std::size_t y_, const Int_ value_ = 1) noexcept {
			createBorderOdd(stl_, x_, y_, value_);
		}
	};

	template<typename Int_, typename STL_>
	constexpr void createPointGridField(STL_& stl_, const Int_ value_) noexcept {
		createPointGrid(stl_, value_);
		createBorderOdd(stl_, value_);
	}
	template<typename Int_, typename STL_>
	constexpr void createPointGridField(STL_& stl_, const std::size_t x_, const std::size_t y_, const Int_ value_) noexcept {
		createPointGrid(stl_, x_, y_, value_);
		createBorderOdd(stl_, x_, y_, value_);
	}
	template<typename STL_>
	constexpr void createPointGridField(STL_& stl_) noexcept {
		createPointGrid(stl_);
		createBorderOdd(stl_);
	}
	template<typename STL_>
	constexpr void createPointGridField(STL_& stl_, const std::size_t x_, const std::size_t y_) noexcept {
		createPointGrid(stl_, x_, y_);
		createBorderOdd(stl_, x_, y_);
	}

	//クラス版
	template<typename Int_>
	class PointGridField {
	public:
		//コンストラクタ
		constexpr PointGridField() noexcept = default;
		template<typename STL_>
		constexpr explicit PointGridField(STL_& stl_, const Int_ value_ = 1) noexcept {
			create(stl_, value_);
		}
		template<typename STL_>
		constexpr void create(STL_& stl_, const Int_ value_ = 1) noexcept {
			createPointGrid(stl_, value_);
			createBorderOdd(stl_, value_);
		}
		template<typename STL_>
		constexpr explicit PointGridField(STL_& stl_, const std::size_t x_, const std::size_t y_, const Int_ value_ = 1) noexcept {
			create(stl_, x_, y_, value_);
		}
		template<typename STL_>
		constexpr void create(STL_& stl_, const std::size_t x_, const std::size_t y_, const Int_ value_ = 1) noexcept {
			createPointGrid(stl_, x_, y_, value_);
			createBorderOdd(stl_, x_, y_, value_);
		}
	};

	//Border
	template<typename STL_>
	constexpr void createBorder(STL_& stl_) noexcept {
		if (stl_.size() == 0) return;
		for (std::size_t i{}; i < stl_[0].size(); ++i)
			stl_[0][i] = 1;
		for (std::size_t i{}; i < stl_[stl_.size() - 1].size(); ++i)
			stl_[stl_.size() - 1][i] = 1;
		for (std::size_t i{}; i < stl_.size(); ++i) {
			if (stl_[i].size() == 0) continue;
			stl_[i][0] = 1;
			stl_[i][stl_[i].size() - 1] = 1;
		}
	}
	template<typename Int_, typename STL_>
	constexpr void createBorder(STL_& stl_, const Int_ value_) noexcept {
		if (stl_.size() == 0) return;
		for (std::size_t i{}; i < stl_[0].size(); ++i)
			stl_[0][i] = value_;
		for (std::size_t i{}; i < stl_[stl_.size() - 1].size(); ++i)
			stl_[stl_.size() - 1][i] = value_;
		for (std::size_t i{}; i < stl_.size(); ++i) {
			if (stl_[i].size() == 0) continue;
			stl_[i][0] = value_;
			stl_[i][stl_[i].size() - 1] = value_;
		}
	}
	//クラス版
	template<typename Int_>
	class Border {
	public:
		//コンストラクタ
		constexpr Border() noexcept = default;
		template<typename STL_>
		constexpr explicit Border(STL_& stl_, const Int_ value_ = 1) noexcept {
			create(stl_, value_);
		}
		template<typename STL_>
		constexpr void create(STL_& stl_, const Int_ value_ = 1) noexcept {
			createBorder(stl_, value_);
		}
		template<typename STL_>
		constexpr explicit Border(STL_& stl_, const std::size_t x_, const std::size_t y_, const Int_ value_ = 1) noexcept {
			create(stl_, x_, y_, value_);
		}
		template<typename STL_>
		constexpr void create(STL_& stl_, const std::size_t x_, const std::size_t y_, const Int_ value_ = 1) noexcept {
			createBorder(stl_, x_, y_, value_);
		}
	};

	//----------*----------*----------*----------*----------*
	//初期化系
	//----------*----------*----------*----------*----------*

	//全てのマスを0で埋める
	template<typename STL_>
	constexpr void dungeonInit(STL_& stl_) noexcept {
		for (std::size_t i{}; i < stl_.size(); ++i)
			for (std::size_t j{}; j < stl_[i].size(); ++j)
				stl_[i][j] = 0;
	}
	template<typename STL_>
	constexpr void dungeonInit(STL_& stl_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t i{}; i < y_; ++i)
			for (std::size_t j{}; j < x_; ++j)
				stl_[i][j] = 0;
	}
	//全てのマスを指定した数値で埋める
	template<typename Int_, typename STL_>
	constexpr void dungeonInit(STL_& stl_, const Int_ value_) noexcept {
		for (std::size_t i{}; i < stl_.size(); ++i)
			for (std::size_t j{}; j < stl_[i].size(); ++j)
				stl_[i][j] = value_;
	}
	template<typename Int_, typename STL_>
	constexpr void dungeonInit(STL_& stl_, const std::size_t x_, const std::size_t y_, const Int_ value_) noexcept {
		for (std::size_t i{}; i < y_; ++i)
			for (std::size_t j{}; j < x_; ++j)
				stl_[i][j] = value_;
	}
	//クラス版
	template<typename Int_>
	class DungeonInit {
	public:
		//コンストラクタ
		constexpr DungeonInit() noexcept = default;
		template<typename STL_>
		constexpr explicit DungeonInit(STL_& stl_, const Int_ value_ = 0) noexcept {
			create(stl_, value_);
		}
		template<typename STL_>
		constexpr void create(STL_& stl_, const Int_ value_ = 0) noexcept {
			dungeonInit(stl_, value_);
		}
		template<typename STL_>
		constexpr explicit DungeonInit(STL_& stl_, const std::size_t x_, const std::size_t y_, const Int_ value_ = 0) noexcept {
			create(stl_, x_, y_, value_);
		}
		template<typename STL_>
		constexpr void create(STL_& stl_, const std::size_t x_, const std::size_t y_, const Int_ value_ = 0) noexcept {
			dungeonInit(stl_, x_, y_, value_);
		}
	};

	//全てのマスを0で埋める
	template<typename STL_>
	constexpr void dungeonInit_RangeBasedFor(STL_& stl_) noexcept {
		for (auto&& i : stl_)
			for (auto&& j : i)
				j = 0;
	}
	//全てのマスを指定した数値で埋める
	template<typename Int_, typename STL_>
	constexpr void dungeonInit_RangeBasedFor(STL_& stl_, const Int_ value_) noexcept {
		for (auto&& i : stl_)
			for (auto&& j : i)
				j = value_;
	}

	//----------*----------*----------*----------*----------*
	//初期化系
	//----------*----------*----------*----------*----------*

	template<typename STL_>
	constexpr bool dungeonArrayCheckBitset(const STL_& stl_) noexcept {
		if (stl_.size() < 1 || stl_[0].size() < 1) return false;
		const auto& stl_value{ stl_[0][0] };
		for (std::size_t i{}; i < stl_.size(); ++i)
			for (std::size_t j{}; j < stl_[i].size(); ++j)
				if (stl_value != stl_[i][j]) return false;
		return true;
	}

	//値が全て一致しているか確認する
	template<typename STL_>
	constexpr bool dungeonArrayCheck(const STL_& stl_) noexcept {
		if (stl_.size() == 0 || stl_.front().size() == 0) return false;
		const auto& stl_value{ stl_.front().front() };
		for (std::size_t i{}; i < stl_.size(); ++i)
			for (std::size_t j{}; j < stl_[i].size(); ++j)
				if (stl_value != stl_[i][j]) return false;
		return true;
	}

	template<typename STL_>
	constexpr bool dungeonArrayCheck_RangeBasedFor(const STL_& stl_) noexcept {
		if (stl_.size() == 0 || stl_.front().size() == 0) return false;
		const auto& stl_value{ stl_.front().front() };
		for (const auto& i : stl_)
			for (const auto& j : i)
				if (stl_value != j) return false;
		return true;
	}

}

#endif //Included Dungeon Template Library