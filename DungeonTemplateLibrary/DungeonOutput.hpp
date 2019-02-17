#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_OUTPUT
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_OUTPUT
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

//Dungeon Template Library Namespace
namespace dtl {
	namespace console {
		namespace output {
			namespace stl {


				//数値出力
				template<typename Matrix_>
				constexpr void number(const Matrix_& matrix_) noexcept {
					for (std::size_t row{}; row < matrix_.size(); ++row) {
						for (std::size_t col{}; col < matrix_[row].size(); ++col)
							std::cout << matrix_[row][col];
						std::cout << std::endl;
					}
				}
				template<typename Matrix_>
				constexpr void number(const Matrix_& matrix_, const std::string& string_) noexcept {
					for (std::size_t row{}; row < matrix_.size(); ++row) {
						for (std::size_t col{}; col < matrix_[row].size(); ++col)
							std::cout << matrix_[row][col] << string_;
						std::cout << std::endl;
					}
				}


			} //namespace
		}
	}
}

namespace dtl {
	namespace console {
		namespace output {
			namespace normal {


				template<typename Matrix_>
				constexpr void number(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
					for (std::size_t row{}; row < y_; ++row) {
						for (std::size_t col{}; col < x_; ++col)
							std::cout << matrix_[row][col];
						std::cout << std::endl;
					}
				}
				template<typename Matrix_>
				constexpr void number(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::string& string_) noexcept {
					for (std::size_t row{}; row < y_; ++row) {
						for (std::size_t col{}; col < x_; ++col)
							std::cout << matrix_[row][col] << string_;
						std::cout << std::endl;
					}
				}


			} //namespace
		}
	}
}

namespace dtl {
	namespace console {
		namespace output {
			namespace layer {


				template<typename Matrix_>
				constexpr void number(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t layer_) noexcept {
					for (std::size_t row{}; row < y_; ++row) {
						for (std::size_t col{}; col < x_; ++col)
							std::cout << matrix_[row][col][layer_];
						std::cout << std::endl;
					}
				}
				template<typename Matrix_>
				constexpr void number(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t layer_, const std::string& string_) noexcept {
					for (std::size_t row{}; row < y_; ++row) {
						for (std::size_t col{}; col < x_; ++col)
							std::cout << matrix_[row][col][layer_] << string_;
						std::cout << std::endl;
					}
				}


			} //namespace
		}
	}
}

namespace dtl {
	namespace console {
		namespace output {
			namespace array {


				template<typename Matrix_>
				constexpr void number(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
					for (std::size_t row{}; row < y_; ++row) {
						for (std::size_t col{}; col < x_; ++col)
							std::cout << matrix_[row * x_ + col];
						std::cout << std::endl;
					}
				}
				template<typename Matrix_>
				constexpr void number(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::string& string_) noexcept {
					for (std::size_t row{}; row < y_; ++row) {
						for (std::size_t col{}; col < x_; ++col)
							std::cout << matrix_[row * x_ + col] << string_;
						std::cout << std::endl;
					}
				}


			} //namespace
		}
	}
}

namespace dtl {
	namespace console {
		namespace output {
			namespace rangeBasedFor {


				template<typename Matrix_>
				constexpr void number(const Matrix_& matrix_) noexcept {
					for (const auto& row : matrix_) {
						for (const auto& col : row)
							std::cout << col;
						std::cout << std::endl;
					}
				}
				template<typename Matrix_>
				constexpr void number(const Matrix_& matrix_, const std::string& string_) noexcept {
					for (const auto& row : matrix_) {
						for (const auto& col : row)
							std::cout << col << string_;
						std::cout << std::endl;
					}
				}


			} //namespace
		}
	}
}

namespace dtl {
	namespace console {
		namespace output {
			namespace stl {


				//文字出力
				template<typename Matrix_>
				constexpr void stringMirrorBool(const Matrix_& matrix_, const std::string& true_, const std::string& false_) noexcept {
					for (std::size_t row{}; row < matrix_.size(); ++row) {
						for (std::size_t col{ matrix_[row].size() / 2 }; col < matrix_[row].size(); ++col) {
							if (matrix_[row][col]) std::cout << true_;
							else std::cout << false_;
						}
						for (std::size_t col{}; col < matrix_[row].size() / 2; ++col) {
							if (matrix_[row][col]) std::cout << true_;
							else std::cout << false_;
						}
						std::cout << std::endl;
					}
				}
				template<typename Matrix_>
				constexpr void stringBool(const Matrix_& matrix_, const std::string& true_, const std::string& false_) noexcept {
					for (std::size_t row{}; row < matrix_.size(); ++row) {
						for (std::size_t col{}; col < matrix_[row].size(); ++col) {
							if (matrix_[row][col]) std::cout << true_;
							else std::cout << false_;
						}
						std::cout << std::endl;
					}
				}


			} //namespace
		}
	}
}
namespace dtl {
	namespace console {
		namespace output {
			namespace normal {


				template<typename Matrix_>
				constexpr void stringBool(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::string& true_, const std::string& false_) noexcept {
					for (std::size_t row{}; row < y_; ++row) {
						for (std::size_t col{}; col < x_; ++col) {
							if (matrix_[row][col]) std::cout << true_;
							else std::cout << false_;
						}
						std::cout << std::endl;
					}
				}


			} //namespace
		}
	}
}
namespace dtl {
	namespace console {
		namespace output {
			namespace array {


				template<typename Matrix_>
				constexpr void stringBool(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::string& true_, const std::string& false_) noexcept {
					for (std::size_t row{}; row < y_; ++row) {
						for (std::size_t col{}; col < x_; ++col) {
							if (matrix_[row * x_ + col]) std::cout << true_;
							else std::cout << false_;
						}
						std::cout << std::endl;
					}
				}
			}
			namespace rangeBasedFor {
				template<typename Matrix_>
				constexpr void stringBool(const Matrix_& matrix_, const std::string& true_, const std::string& false_) noexcept {
					for (const auto& row : matrix_) {
						for (const auto& col : row) {
							if (col) std::cout << true_;
							else std::cout << false_;
						}
						std::cout << std::endl;
					}
				}


			} //namespace
		}
	}
}
namespace dtl {
	namespace console {
		namespace output {
			namespace hiding {

				//C++17_todo
				bool string_String(std::vector<std::string>& string_) noexcept { return string_.empty(); }
				template<typename First_, typename ...Args_>
				constexpr void string_String(std::vector<std::string>& string_vector_, const First_& first_, const Args_&... args_) noexcept {
					string_vector_.emplace_back(std::string(first_));
					string_String(string_vector_, args_...);
				}


			} //namespace
		}
	}
}
namespace dtl {
	namespace console {
		namespace output {
			namespace stl {


				template<typename Matrix_, typename First_, typename ...Args_>
				void string(const Matrix_& matrix_, const First_& first_, const Args_&... args_) noexcept {

					using dtl::console::output::hiding::string_String;

					std::vector<std::string> string_vector;
					string_vector.emplace_back(std::string(first_));
					string_String(string_vector, args_...);

					for (std::size_t row{}; row < matrix_.size(); ++row) {
						for (std::size_t col{}; col < matrix_[row].size(); ++col) {
							if (static_cast<std::size_t>(matrix_[row][col]) >= string_vector.size()) continue;
							std::cout << string_vector[static_cast<std::size_t>(matrix_[row][col])];
						}
						std::cout << std::endl;
					}
				}


			} //namespace
		}
	}
}
namespace dtl {
	namespace console {
		namespace output {
			namespace rangeBasedFor {


				template<typename Matrix_, typename First_, typename ...Args_>
				void string(const Matrix_& matrix_, const First_& first_, const Args_&... args_) noexcept {

					using dtl::console::output::hiding::string_String;

					std::vector<std::string> string_vector;
					string_vector.emplace_back(std::string(first_));
					string_String(string_vector, args_...);

					for (const auto& row : matrix_) {
						for (const auto& col : row) {
							if (static_cast<std::size_t>(col) >= string_vector.size()) continue;
							std::cout << string_vector[static_cast<std::size_t>(col)];
						}
						std::cout << std::endl;
					}
				}
			} //namespace
		}
	}
}
namespace dtl {
	namespace console {
		namespace output {
			namespace tool {


				void endl() noexcept {
					std::cout << std::endl;
				}
				void puts(const std::string& str_) noexcept {
					std::cout << str_ << std::endl;
				}


			} //namespace
		}
	}
}

#endif //Included Dungeon Template Library