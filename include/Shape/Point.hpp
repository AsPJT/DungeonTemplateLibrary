/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_POINT_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_POINT_HPP

/* Character Code : UTF-8 (BOM) */
/* Bug Check : not checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <Macros/constexpr.hpp>
#include <Type/SizeT.hpp>

//STLデータ
namespace dtl {
	inline namespace shape {
		namespace stl {

			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createPoint(Matrix_& matrix_, const dtl::type::size set_x_, const dtl::type::size set_y_) noexcept {
				if (matrix_.size() <= set_y_ || matrix_[set_y_].size() <= set_x_) return;
				matrix_[set_y_][set_x_] = 1;
			}
			template<typename Matrix_Int_, typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createPoint(Matrix_& matrix_, const dtl::type::size set_x_, const dtl::type::size set_y_, const Matrix_Int_ value_) noexcept {
				if (matrix_.size() <= set_y_ || matrix_[set_y_].size() <= set_x_) return;
				matrix_[set_y_][set_x_] = value_;
			}

			template<typename Matrix_Int_>
			class PointUnique {
			private:
				dtl::type::size x{}, y{};
				Matrix_Int_ value{ 1 };
			public:
				constexpr explicit PointUnique(const dtl::type::size x_, const dtl::type::size y_) noexcept :x(x_), y(y_) {}
				constexpr explicit PointUnique(const dtl::type::size x_, const dtl::type::size y_, const Matrix_Int_ value_) noexcept :x(x_), y(y_), value(value_) {}

				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void draw(Matrix_& matrix_) const noexcept {
					dtl::shape::stl::createPoint(matrix_, x, y, value);
				}
			};
			template<typename Matrix_Int_>
			class Point {
			private:
			public:
				constexpr Point() noexcept = default;
				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void draw(Matrix_& matrix_, const dtl::type::size x_, const dtl::type::size y_) const noexcept {
					dtl::shape::stl::createPoint(matrix_, x_, y_);
				}
				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void draw(Matrix_& matrix_, const dtl::type::size x_, const dtl::type::size y_, const Matrix_Int_ value_) const noexcept {
					dtl::shape::stl::createPoint(matrix_, x_, y_, value_);
				}
			};

		} //namespace
	}
}

namespace dtl {
	inline namespace shape {
		namespace normal {

			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createPoint(Matrix_& matrix_, const dtl::type::size set_x_, const dtl::type::size set_y_) noexcept {
				matrix_[set_y_][set_x_] = 1;
			}
			template<typename Matrix_Int_, typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createPoint(Matrix_& matrix_, const dtl::type::size set_x_, const dtl::type::size set_y_, const Matrix_Int_ value_) noexcept {
				matrix_[set_y_][set_x_] = value_;
			}
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createPoint(Matrix_& matrix_, const dtl::type::size x_, const dtl::type::size y_, const dtl::type::size set_x_, const dtl::type::size set_y_) noexcept {
				if (x_ <= set_x_ || y_ <= set_y_) return;
				matrix_[set_y_][set_x_] = 1;
			}
			template<typename Matrix_Int_, typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createPoint(Matrix_& matrix_, const dtl::type::size x_, const dtl::type::size y_, const dtl::type::size set_x_, const dtl::type::size set_y_, const Matrix_Int_ value_) noexcept {
				if (x_ <= set_x_ || y_ <= set_y_) return;
				matrix_[set_y_][set_x_] = value_;
			}

			template<typename Matrix_Int_>
			class PointUnique {
			private:
				dtl::type::size x{}, y{};
				Matrix_Int_ value{ 1 };
			public:
				constexpr explicit PointUnique(const dtl::type::size x_, const dtl::type::size y_) noexcept :x(x_), y(y_) {}
				constexpr explicit PointUnique(const dtl::type::size x_, const dtl::type::size y_, const Matrix_Int_ value_) noexcept :x(x_), y(y_), value(value_) {}

				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void draw(Matrix_& matrix_) const noexcept {
					dtl::shape::normal::createPoint(matrix_, x, y, value);
				}
				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void draw(Matrix_& matrix_, const dtl::type::size size_x_, const dtl::type::size size_y_) const noexcept {
					dtl::shape::normal::createPoint(matrix_, size_x_, size_y_, x, y, value);
				}
				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void draw(Matrix_& matrix_, const dtl::type::size size_) const noexcept {
					dtl::shape::normal::createPoint(matrix_, size_, size_, x, y, value);
				}
			};
			template<typename Matrix_Int_>
			class Point {
			private:
			public:
				constexpr Point() noexcept = default;

			};

		}
	}
}

namespace  dtl {
	inline namespace shape {
		namespace array {

			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createPoint(Matrix_& matrix_, const dtl::type::size x_, const dtl::type::size y_, const dtl::type::size set_x_, const dtl::type::size set_y_) noexcept {
				if (x_ <= set_x_ || y_ <= set_y_) return;
				matrix_[set_y_*x_ + set_x_] = 1;
			}
			template<typename Matrix_Int_, typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createPoint(Matrix_& matrix_, const dtl::type::size x_, const dtl::type::size y_, const dtl::type::size set_x_, const dtl::type::size set_y_, const Matrix_Int_ value_) noexcept {
				if (x_ <= set_x_ || y_ <= set_y_) return;
				matrix_[set_y_*x_ + set_x_] = value_;
			}

			template<typename Matrix_Int_>
			class PointUnique {
			private:
				dtl::type::size x{}, y{};
				Matrix_Int_ value{ 1 };
			public:
				constexpr explicit PointUnique(const dtl::type::size x_, const dtl::type::size y_) noexcept :x(x_), y(y_) {}
				constexpr explicit PointUnique(const dtl::type::size x_, const dtl::type::size y_, const Matrix_Int_ value_) noexcept :x(x_), y(y_), value(value_) {}

				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void draw(Matrix_& matrix_, const dtl::type::size size_x_, const dtl::type::size size_y_) const noexcept {
					dtl::shape::array::createPoint(matrix_, size_x_, size_y_, x, y, value);
				}
				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void draw(Matrix_& matrix_, const dtl::type::size size_) const noexcept {
					dtl::shape::array::createPoint(matrix_, size_, size_, x, y, value);
				}
			};

		}
	}
}

namespace  dtl {
	inline namespace shape {
		namespace layer {
			namespace stl {

				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void createPoint(Matrix_& matrix_, const dtl::type::size layer_, dtl::type::size set_x_, const dtl::type::size set_y_) noexcept {
					if (matrix_.size() <= set_y_ || matrix_[set_y_].size() <= set_x_) return;
					matrix_[set_y_][set_x_][layer_] = 1;
				}
				template<typename Matrix_Int_, typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void createPoint(Matrix_ & matrix_, const dtl::type::size layer_, const dtl::type::size set_x_, const dtl::type::size set_y_, const Matrix_Int_ value_) noexcept {
					if (matrix_.size() <= set_y_ || matrix_[set_y_].size() <= set_x_) return;
					matrix_[set_y_][set_x_][layer_] = value_;
				}

				template<typename Matrix_Int_>
				class PointUnique {
				private:
					dtl::type::size x{}, y{};
					Matrix_Int_ value{ 1 };
				public:
					constexpr explicit PointUnique(const dtl::type::size x_, const dtl::type::size y_) noexcept :x(x_), y(y_) {}
					constexpr explicit PointUnique(const dtl::type::size x_, const dtl::type::size y_, const Matrix_Int_ value_) noexcept :x(x_), y(y_), value(value_) {}

					template<typename Matrix_>
					DTL_VERSIONING_CPP14_CONSTEXPR
						void draw(Matrix_& matrix_, const dtl::type::size layer_) const noexcept {
						dtl::shape::layer::stl::createPoint(matrix_, layer_, x, y, value);
					}
				};

			} //namespace
		}
	}
}

namespace  dtl {
	inline namespace shape {
		namespace layer {
			namespace normal {

				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void createPoint(Matrix_& matrix_, const dtl::type::size layer_, const dtl::type::size set_x_, const dtl::type::size set_y_) noexcept {
					matrix_[set_y_][set_x_][layer_] = 1;
				}
				template<typename Matrix_Int_, typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void createPoint(Matrix_& matrix_, const dtl::type::size layer_, const dtl::type::size set_x_, const dtl::type::size set_y_, const Matrix_Int_ value_) noexcept {
					matrix_[set_y_][set_x_][layer_] = value_;
				}
				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void createPoint(Matrix_& matrix_, const dtl::type::size layer_, const dtl::type::size x_, const dtl::type::size y_, const dtl::type::size set_x_, const dtl::type::size set_y_) noexcept {
					if (x_ <= set_x_ || y_ <= set_y_) return;
					matrix_[set_y_][set_x_][layer_] = 1;
				}
				template<typename Matrix_Int_, typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void createPoint(Matrix_ & matrix_, const dtl::type::size layer_, const dtl::type::size x_, const dtl::type::size y_, const dtl::type::size set_x_, const dtl::type::size set_y_, const Matrix_Int_ value_) noexcept {
					if (x_ <= set_x_ || y_ <= set_y_) return;
					matrix_[set_y_][set_x_][layer_] = value_;
				}

				template<typename Matrix_Int_>
				class PointUnique {
				private:
					dtl::type::size x{}, y{};
					Matrix_Int_ value{ 1 };
				public:
					constexpr explicit PointUnique(const dtl::type::size x_, const dtl::type::size y_) noexcept :x(x_), y(y_) {}
					constexpr explicit PointUnique(const dtl::type::size x_, const dtl::type::size y_, const Matrix_Int_ value_) noexcept :x(x_), y(y_), value(value_) {}

					template<typename Matrix_>
					DTL_VERSIONING_CPP14_CONSTEXPR
						void draw(Matrix_& matrix_, const dtl::type::size layer_) const noexcept {
						dtl::shape::layer::normal::createPoint(matrix_, layer_, x, y, value);
					}
					template<typename Matrix_>
					DTL_VERSIONING_CPP14_CONSTEXPR
						void draw(Matrix_& matrix_, const dtl::type::size layer_, const dtl::type::size size_x_, const dtl::type::size size_y_) const noexcept {
						dtl::shape::layer::normal::createPoint(matrix_, layer_, size_x_, size_y_, x, y, value);
					}
					template<typename Matrix_>
					DTL_VERSIONING_CPP14_CONSTEXPR
						void draw(Matrix_& matrix_, const dtl::type::size layer_, const dtl::type::size size_) const noexcept {
						dtl::shape::layer::normal::createPoint(matrix_, layer_, size_, size_, x, y, value);
					}
				};

			}
		}
	}
}

#endif //Included Dungeon Template Library