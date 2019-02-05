#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BOARD_GAME
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BOARD_GAME
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>
#include <cstdint>
#include <array>
#include <limits>

//Dungeon Template Library Namespace
namespace dtl {

	namespace ai {

		namespace reversi {

			//指定した場所に駒を置く
			template<typename Matrix_Int_, typename Matrix_>
			std::size_t putPiece(Matrix_& matrix_, const std::size_t  col_, const std::size_t row_, const Matrix_Int_ turn_, const bool is_put_) noexcept {
				if (matrix_.size() == 0) return 0;
				std::size_t piece_turn_num{};
				if (matrix_[row_][col_] > 0) return 0;

				std::unique_ptr<std::int_fast32_t[]> stl_tmp_x{ std::make_unique<std::int_fast32_t[]>(matrix_[0].size()) };
				std::unique_ptr<std::int_fast32_t[]> stl_tmp_y{ std::make_unique<std::int_fast32_t[]>(matrix_.size()) };

				for (std::int_fast32_t y{ -1 }; y <= 1; ++y)
					for (std::int_fast32_t x{ -1 }; x <= 1; ++x) {
						for (std::size_t i{}; i < matrix_[0].size(); ++i) stl_tmp_x[i] = 0;
						for (std::size_t i{}; i < matrix_.size(); ++i) stl_tmp_y[i] = 0;
						for (std::size_t turn_tmp_id{};; ++turn_tmp_id) {
							std::int_fast32_t turn_x{ static_cast<std::int_fast32_t>(col_) + x * (static_cast<std::int_fast32_t>(turn_tmp_id) + 1) };
							std::int_fast32_t turn_y{ static_cast<std::int_fast32_t>(row_) + y * (static_cast<std::int_fast32_t>(turn_tmp_id) + 1) };
							if (turn_x < 0 || turn_x >= matrix_[0].size() || turn_y < 0 || turn_y >= matrix_.size() || matrix_[turn_y][turn_x] == 0) break;
							if (matrix_[turn_y][turn_x] == turn_) {
								if (is_put_)
									for (std::size_t i{}; i < turn_tmp_id; ++i)
										matrix_[static_cast<std::size_t>(stl_tmp_y[i])][static_cast<std::size_t>(stl_tmp_x[i])] = turn_;
								piece_turn_num += turn_tmp_id;
								break;
							}
							stl_tmp_x[turn_tmp_id] = turn_x; stl_tmp_y[turn_tmp_id] = turn_y;
						}
					}
				if (piece_turn_num > 0 && is_put_) matrix_[row_][col_] = turn_;
				return piece_turn_num;
			}

			//パスの有無
			template<typename Matrix_Int_, typename Matrix_>
			constexpr bool isPass(Matrix_& matrix_, const Matrix_Int_ turn_) noexcept {
				for (std::size_t row{}; row < matrix_.size(); ++row)
					for (std::size_t col{}; col < matrix_[row].size(); ++col)
						if (dtl::ai::reversi::putPiece(matrix_, col, row, turn_, false)) return false;
				return true;
			}
			//最初に見つけた置ける場所を選ぶ
			template<typename Matrix_Int_, typename Matrix_>
			constexpr bool simple(Matrix_& matrix_, const Matrix_Int_ turn_) noexcept {
				for (std::size_t row{}; row < matrix_.size(); ++row)
					for (std::size_t col{}; col < matrix_[row].size(); ++col)
						if (dtl::ai::reversi::putPiece(matrix_, col, row, turn_, true)) return true;
				return true;
			}
			//最も多くの駒が取れる場所を選ぶ
			template<typename Matrix_Int_, typename Matrix_>
			constexpr bool greed(Matrix_& matrix_, const Matrix_Int_ turn_) noexcept {
				std::size_t piece_turn_max{};
				std::size_t put_piece_x{}, put_piece_y{};
				for (std::size_t row{}; row < matrix_.size(); ++row)
					for (std::size_t col{}; col < matrix_[row].size(); ++col) {
						const auto& num{ dtl::ai::reversi::putPiece(matrix_, col,row, turn_, false) };
						if (piece_turn_max < num || (piece_turn_max == num && dtl::random::rnd.randBool())) {
							piece_turn_max = num;
							put_piece_x = col;
							put_piece_y = row;
						}
					}
				dtl::ai::reversi::putPiece(matrix_, put_piece_x, put_piece_y, turn_, true);
				return true;
			}
			//最も少なく駒が取れる場所を選ぶ
			template<typename Matrix_Int_, typename Matrix_>
			constexpr bool unselfishness(Matrix_& matrix_, const Matrix_Int_ turn_) noexcept {
				std::size_t piece_turn_min{ (std::numeric_limits<std::size_t>::max)() };
				std::size_t put_piece_x{}, put_piece_y{};
				for (std::size_t row{}; row < matrix_.size(); ++row)
					for (std::size_t col{}; col < matrix_[row].size(); ++col) {
						const auto& num{ dtl::ai::reversi::putPiece(matrix_, col,row, turn_, false) };
						if (num > 0 && (piece_turn_min > num || (piece_turn_min == num && dtl::random::rnd.randBool()))) {
							piece_turn_min = num;
							put_piece_x = col;
							put_piece_y = row;
						}
					}
				dtl::ai::reversi::putPiece(matrix_, put_piece_x, put_piece_y, turn_, true);
				return true;
			}
			//優先順位
			constexpr std::int_fast32_t checkPriority(std::int_fast32_t x_, std::int_fast32_t y_, const std::int_fast32_t x_max_, const std::int_fast32_t y_max_) noexcept {
				if (x_ == x_max_) x_ = 0;
				else if (x_ == x_max_ - 1) x_ = 1;
				else if (x_ == x_max_ - 2) x_ = 2;
				else if (x_ >= 4) x_ = 3;

				if (y_ == y_max_) y_ = 0;
				else if (y_ == y_max_ - 1) y_ = 1;
				else if (y_ == y_max_ - 2) y_ = 2;
				else if (y_ >= 4) x_ = 3;

				switch (x_)
				{
				case 0:
					switch (y_)
					{
					case 0:return 0;
					case 1:return 6;
					case 2:return 2;
					default:return 1;
					}
				case 1:
					switch (y_)
					{
					case 0:return 6;
					case 1:return 6;
					case 2:return 6;
					default:return 4;
					}
				case 2:
					switch (y_)
					{
					case 0:return 2;
					case 1:return 5;
					case 2:return 2;
					default:return 3;
					}
				}
				switch (y_)
				{
				case 0:return 1;
				case 1:return 4;
				case 2:return 3;
				default:return 3;
				}
				return 0;
			}
			//優先順位の高い場所を選ぶ
			template<typename Matrix_Int_, typename Matrix_>
			constexpr bool priority(Matrix_& matrix_, const Matrix_Int_ turn_) noexcept {
				std::size_t piece_turn_max{};
				std::size_t put_piece_x{}, put_piece_y{};
				for (std::uint_fast8_t piece_priority{}; piece_priority < 7 && piece_turn_max == 0; ++piece_priority)
					for (std::size_t row{}; row < matrix_.size(); ++row)
						for (std::size_t col{}; col < matrix_[row].size(); ++col) {
							if (dtl::ai::reversi::checkPriority(static_cast<std::int_fast32_t>(col), static_cast<std::int_fast32_t>(row), static_cast<std::int_fast32_t>(matrix_[row].size()) - 1, static_cast<std::int_fast32_t>(matrix_.size()) - 1) != piece_priority) continue;
							const auto& num{ dtl::ai::reversi::putPiece(matrix_, col, row, turn_, false) };
							if (piece_turn_max < num || (piece_turn_max == num && dtl::random::rnd.randBool())) {
								piece_turn_max = num;
								put_piece_x = col;
								put_piece_y = row;
							}
						}
				dtl::ai::reversi::putPiece(matrix_, put_piece_x, put_piece_y, turn_, true);
				return true;
			}
			//AI同士をまとめる関数
			template<typename Matrix_Int_, typename Matrix_>
			constexpr bool reversiAI(Matrix_& matrix_, const Matrix_Int_ turn_, bool(*black_ai_)(Matrix_&, const Matrix_Int_), bool(*white_ai_)(Matrix_&, const Matrix_Int_), const bool is_black_ai_) noexcept {
				return (is_black_ai_) ? black_ai_(matrix_, turn_) : white_ai_(matrix_, turn_);
			}

			template<typename Matrix_Int_, typename Matrix_>
			constexpr std::int_fast32_t checkResult(Matrix_& matrix_) noexcept {
				std::array<std::int_fast32_t, 2> piece_num{ {} };
				std::int_fast32_t result{};
				for (std::size_t row{}; row < matrix_.size(); ++row)
					for (std::size_t col{}; col < matrix_[row].size(); ++col)
						if (matrix_[row][col] > 0) ++piece_num[matrix_[row][col] - 1];
				if (dtl::ai::reversi::isPass(matrix_, (Matrix_Int_)1) && dtl::ai::reversi::isPass(matrix_, (Matrix_Int_)2)) {
					if (piece_num[0] > piece_num[1]) result = 1;
					else if (piece_num[0] < piece_num[1]) result = 2;
					else result = 3;
				}
				return result;
			}

		}

	}

	//地形生成
	namespace generator {

		enum :std::size_t {
			reversi_empty,
			reversi_white,
			reversi_black
		};
		//リバーシを初期化する
		template<typename Matrix_Int_, typename Matrix_>
		constexpr void createReversi(Matrix_& matrix_, const Matrix_Int_ black_ = 2, const Matrix_Int_ white_ = 1) noexcept {
			if (matrix_.size() < 2 || matrix_[0].size() < 2) return;
			const std::size_t& set_y{ matrix_.size() / 2 };
			const std::size_t& set_x{ matrix_[0].size() / 2 };
			matrix_[set_y - 1][set_x - 1] = white_;
			matrix_[set_y - 1][set_x] = black_;
			matrix_[set_y][set_x - 1] = black_;
			matrix_[set_y][set_x] = white_;
		}
		template<typename Matrix_Int_>
		class Reversi {
		public:
			//コンストラクタ
			constexpr Reversi() noexcept = default;
			template<typename Matrix_>
			constexpr explicit Reversi(Matrix_& matrix_, const Matrix_Int_ black_ = 2, const Matrix_Int_ white_ = 1) noexcept {
				create(matrix_, black_, white_);
			}
			template<typename Matrix_>
			constexpr void create(Matrix_& matrix_, const Matrix_Int_ black_ = 2, const Matrix_Int_ white_ = 1) noexcept {
				createReversi(matrix_, black_, white_);
			}
		};

		enum :std::size_t {
			shogi_empty,
			shogi_next_place1,
			shogi_next_place2,
			//王将&玉将
			shogi_osho,
			shogi_gyokusho,
			//金将
			shogi_kinsho1,
			shogi_kinsho2,

			//ここより先は成る。----------------------------------------

			//飛車
			shogi_hisha1,
			shogi_ryuo1,
			shogi_hisha2,
			shogi_ryuo2,
			//角行
			shogi_kakugyo1,
			shogi_ryuma1,
			shogi_kakugyo2,
			shogi_ryuma2,

			//ここより先は成ると金と同じ動きになる。--------------------

			//銀将
			shogi_ginsho1,
			shogi_narigin1,
			shogi_ginsho2,
			shogi_narigin2,
			//桂馬
			shogi_keima1,
			shogi_narikei1,
			shogi_keima2,
			shogi_narikei2,
			//香車
			shogi_kyosha1,
			shogi_narikyo1,
			shogi_kyosha2,
			shogi_narikyo2,
			//歩兵
			shogi_fuhyo1,
			shogi_tokin1,
			shogi_fuhyo2,
			shogi_tokin2
		};

		template<typename Matrix_Int_>
		constexpr bool isShogiNarikin(const Matrix_Int_ koma_) noexcept {
			if (koma_ >= shogi_ginsho1 && shogi_narigin1 % 2 == koma_ % 2) return true;
			return false;
		}

		enum :std::size_t {
			chess_empty,
			chess_king1,
			chess_king2,
			chess_queen1,
			chess_queen2,
			chess_rook1,
			chess_rook2,
			chess_bishop1,
			chess_bishop2,
			chess_knight1,
			chess_knight2,
			chess_pawn1,
			chess_pawn2,
			chess_next_place1,
			chess_next_place2
		};

		template<typename Matrix_>
		constexpr void createChess(Matrix_& matrix_) noexcept {
			if (matrix_.size() < 2) return;

			for (std::size_t i{}; i < matrix_[1].size(); ++i)
				matrix_[1][i] = chess_pawn2;
			for (std::size_t i{}; i < matrix_[matrix_.size() - 2].size(); ++i)
				matrix_[matrix_.size() - 2][i] = chess_pawn1;

			if (matrix_[0].size() < 4) return;
			matrix_[0][0] = chess_rook2;
			matrix_[0][matrix_[0].size() - 1] = chess_rook2;
			matrix_[0][1] = chess_knight2;
			matrix_[0][matrix_[0].size() - 2] = chess_knight2;
			matrix_[0][2] = chess_bishop2;
			matrix_[0][matrix_[0].size() - 3] = chess_bishop2;
			matrix_[0][3] = chess_queen2;
			matrix_[0][matrix_[0].size() - 4] = chess_king2;
			if (matrix_[matrix_.size() - 1].size() < 4) return;
			matrix_[matrix_.size() - 1][0] = chess_rook1;
			matrix_[matrix_.size() - 1][matrix_[matrix_.size() - 1].size() - 1] = chess_rook1;
			matrix_[matrix_.size() - 1][1] = chess_knight1;
			matrix_[matrix_.size() - 1][matrix_[matrix_.size() - 1].size() - 2] = chess_knight1;
			matrix_[matrix_.size() - 1][2] = chess_bishop1;
			matrix_[matrix_.size() - 1][matrix_[matrix_.size() - 1].size() - 3] = chess_bishop1;
			matrix_[matrix_.size() - 1][3] = chess_queen1;
			matrix_[matrix_.size() - 1][matrix_[matrix_.size() - 1].size() - 4] = chess_king1;
		}
		template<typename Matrix_>
		constexpr void createChess(Matrix_& matrix_, const std::size_t  x_, const std::size_t y_) noexcept {
			if (y_ < 2) return;

			for (std::size_t col{}; col < x_; ++col)
				matrix_[1][col] = chess_pawn2;
			for (std::size_t col{}; col < x_; ++col)
				matrix_[y_ - 2][col] = chess_pawn1;

			if (x_ < 4) return;
			matrix_[0][0] = chess_rook2;
			matrix_[0][x_ - 1] = chess_rook2;
			matrix_[0][1] = chess_knight2;
			matrix_[0][x_ - 2] = chess_knight2;
			matrix_[0][2] = chess_bishop2;
			matrix_[0][x_ - 3] = chess_bishop2;
			matrix_[0][3] = chess_queen2;
			matrix_[0][x_ - 4] = chess_king2;
			matrix_[y_ - 1][0] = chess_rook1;
			matrix_[y_ - 1][x_ - 1] = chess_rook1;
			matrix_[y_ - 1][1] = chess_knight1;
			matrix_[y_ - 1][x_ - 2] = chess_knight1;
			matrix_[y_ - 1][2] = chess_bishop1;
			matrix_[y_ - 1][x_ - 3] = chess_bishop1;
			matrix_[y_ - 1][3] = chess_queen1;
			matrix_[y_ - 1][x_ - 4] = chess_king1;
		}

		template<typename Matrix_Int_>
		class Chess {
		public:
			//コンストラクタ
			constexpr Chess() noexcept = default;
			template<typename Matrix_>
			constexpr explicit Chess(Matrix_& matrix_) noexcept {
				create(matrix_);
			}
			template<typename Matrix_>
			constexpr void create(Matrix_& matrix_) noexcept {
				createChess(matrix_);
			}
			template<typename Matrix_>
			constexpr explicit Chess(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
				create(matrix_, x_, y_);
			}
			template<typename Matrix_>
			constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
				createChess(matrix_, x_, y_);
			}
		};



	} //namespace
}

#endif //Included Dungeon Template Library