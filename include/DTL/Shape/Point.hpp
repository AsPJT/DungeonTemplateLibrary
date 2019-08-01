/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_POINT_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_POINT_HPP

#include <DTL/Macros/constexpr.hpp>
#include <DTL/Type/SizeT.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace shape { //"dtl::shape"名前空間に属する
		namespace stl {

			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createPoint(Matrix_& matrix_, const ::dtl::type::size set_x_, const ::dtl::type::size set_y_) noexcept {
				if (matrix_.size() <= set_y_ || matrix_[set_y_].size() <= set_x_) return;
				matrix_[set_y_][set_x_] = 1;
			}
			template<typename Matrix_Var_, typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createPoint(Matrix_& matrix_, const ::dtl::type::size set_x_, const ::dtl::type::size set_y_, const Matrix_Var_ value_) noexcept {
				if (matrix_.size() <= set_y_ || matrix_[set_y_].size() <= set_x_) return;
				matrix_[set_y_][set_x_] = value_;
			}

			template<typename Matrix_Var_>
			class PointUnique {
			private:
				::dtl::type::size x{}, y{};
				Matrix_Var_ value{ 1 };
			public:
				constexpr PointUnique(const ::dtl::type::size x_, const ::dtl::type::size y_) noexcept :x(x_), y(y_) {}
				constexpr PointUnique(const ::dtl::type::size x_, const ::dtl::type::size y_, const Matrix_Var_ value_) noexcept :x(x_), y(y_), value(value_) {}

				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void draw(Matrix_& matrix_) const noexcept {
					::dtl::shape::stl::createPoint(matrix_, x, y, value);
				}
			};
			template<typename Matrix_Var_>
			class Point {
			private:
			public:
				Point() = default;
				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void draw(Matrix_& matrix_, const ::dtl::type::size x_, const ::dtl::type::size y_) const noexcept {
					::dtl::shape::stl::createPoint(matrix_, x_, y_);
				}
				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void draw(Matrix_& matrix_, const ::dtl::type::size x_, const ::dtl::type::size y_, const Matrix_Var_ value_) const noexcept {
					::dtl::shape::stl::createPoint(matrix_, x_, y_, value_);
				}
			};

		} //namespace
	}
}

namespace dtl {
	inline namespace shape { //"dtl::shape"名前空間に属する
		namespace normal {

			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createPoint(Matrix_& matrix_, const ::dtl::type::size set_x_, const ::dtl::type::size set_y_) noexcept {
				matrix_[set_y_][set_x_] = 1;
			}
			template<typename Matrix_Var_, typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createPoint(Matrix_& matrix_, const ::dtl::type::size set_x_, const ::dtl::type::size set_y_, const Matrix_Var_ value_) noexcept {
				matrix_[set_y_][set_x_] = value_;
			}
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createPoint(Matrix_& matrix_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size set_x_, const ::dtl::type::size set_y_) noexcept {
				if (x_ <= set_x_ || y_ <= set_y_) return;
				matrix_[set_y_][set_x_] = 1;
			}
			template<typename Matrix_Var_, typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createPoint(Matrix_& matrix_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size set_x_, const ::dtl::type::size set_y_, const Matrix_Var_ value_) noexcept {
				if (x_ <= set_x_ || y_ <= set_y_) return;
				matrix_[set_y_][set_x_] = value_;
			}

			template<typename Matrix_Var_>
			class PointUnique {
			private:
				::dtl::type::size x{}, y{};
				Matrix_Var_ value{ 1 };
			public:
				constexpr PointUnique(const ::dtl::type::size x_, const ::dtl::type::size y_) noexcept :x(x_), y(y_) {}
				constexpr PointUnique(const ::dtl::type::size x_, const ::dtl::type::size y_, const Matrix_Var_ value_) noexcept :x(x_), y(y_), value(value_) {}

				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void draw(Matrix_& matrix_) const noexcept {
					::dtl::shape::normal::createPoint(matrix_, x, y, value);
				}
				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void draw(Matrix_& matrix_, const ::dtl::type::size size_x_, const ::dtl::type::size size_y_) const noexcept {
					::dtl::shape::normal::createPoint(matrix_, size_x_, size_y_, x, y, value);
				}
				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void draw(Matrix_& matrix_, const ::dtl::type::size size_) const noexcept {
					::dtl::shape::normal::createPoint(matrix_, size_, size_, x, y, value);
				}
			};
			template<typename Matrix_Var_>
			class Point {
			private:
			public:
				Point() = default;

			};

		}
	}
}

namespace  dtl {
	inline namespace shape { //"dtl::shape"名前空間に属する
		namespace array {

			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createPoint(Matrix_& matrix_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size set_x_, const ::dtl::type::size set_y_) noexcept {
				if (x_ <= set_x_ || y_ <= set_y_) return;
				matrix_[set_y_*x_ + set_x_] = 1;
			}
			template<typename Matrix_Var_, typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createPoint(Matrix_& matrix_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size set_x_, const ::dtl::type::size set_y_, const Matrix_Var_ value_) noexcept {
				if (x_ <= set_x_ || y_ <= set_y_) return;
				matrix_[set_y_*x_ + set_x_] = value_;
			}

			template<typename Matrix_Var_>
			class PointUnique {
			private:
				::dtl::type::size x{}, y{};
				Matrix_Var_ value{ 1 };
			public:
				constexpr PointUnique(const ::dtl::type::size x_, const ::dtl::type::size y_) noexcept :x(x_), y(y_) {}
				constexpr PointUnique(const ::dtl::type::size x_, const ::dtl::type::size y_, const Matrix_Var_ value_) noexcept :x(x_), y(y_), value(value_) {}

				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void draw(Matrix_& matrix_, const ::dtl::type::size size_x_, const ::dtl::type::size size_y_) const noexcept {
					::dtl::shape::array::createPoint(matrix_, size_x_, size_y_, x, y, value);
				}
				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void draw(Matrix_& matrix_, const ::dtl::type::size size_) const noexcept {
					::dtl::shape::array::createPoint(matrix_, size_, size_, x, y, value);
				}
			};

		}
	}
}

namespace  dtl {
	inline namespace shape { //"dtl::shape"名前空間に属する
		namespace layer {
			namespace stl {

				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void createPoint(Matrix_& matrix_, const ::dtl::type::size layer_, ::dtl::type::size set_x_, const ::dtl::type::size set_y_) noexcept {
					if (matrix_.size() <= set_y_ || matrix_[set_y_].size() <= set_x_) return;
					matrix_[set_y_][set_x_][layer_] = 1;
				}
				template<typename Matrix_Var_, typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void createPoint(Matrix_ & matrix_, const ::dtl::type::size layer_, const ::dtl::type::size set_x_, const ::dtl::type::size set_y_, const Matrix_Var_ value_) noexcept {
					if (matrix_.size() <= set_y_ || matrix_[set_y_].size() <= set_x_) return;
					matrix_[set_y_][set_x_][layer_] = value_;
				}

				template<typename Matrix_Var_>
				class PointUnique {
				private:
					::dtl::type::size x{}, y{};
					Matrix_Var_ value{ 1 };
				public:
					constexpr PointUnique(const ::dtl::type::size x_, const ::dtl::type::size y_) noexcept :x(x_), y(y_) {}
					constexpr PointUnique(const ::dtl::type::size x_, const ::dtl::type::size y_, const Matrix_Var_ value_) noexcept :x(x_), y(y_), value(value_) {}

					template<typename Matrix_>
					DTL_VERSIONING_CPP14_CONSTEXPR
						void draw(Matrix_& matrix_, const ::dtl::type::size layer_) const noexcept {
						::dtl::shape::layer::stl::createPoint(matrix_, layer_, x, y, value);
					}
				};

			} //namespace
		}
	}
}

namespace  dtl {
	inline namespace shape { //"dtl::shape"名前空間に属する
		namespace layer {
			namespace normal {

				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void createPoint(Matrix_& matrix_, const ::dtl::type::size layer_, const ::dtl::type::size set_x_, const ::dtl::type::size set_y_) noexcept {
					matrix_[set_y_][set_x_][layer_] = 1;
				}
				template<typename Matrix_Var_, typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void createPoint(Matrix_& matrix_, const ::dtl::type::size layer_, const ::dtl::type::size set_x_, const ::dtl::type::size set_y_, const Matrix_Var_ value_) noexcept {
					matrix_[set_y_][set_x_][layer_] = value_;
				}
				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void createPoint(Matrix_& matrix_, const ::dtl::type::size layer_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size set_x_, const ::dtl::type::size set_y_) noexcept {
					if (x_ <= set_x_ || y_ <= set_y_) return;
					matrix_[set_y_][set_x_][layer_] = 1;
				}
				template<typename Matrix_Var_, typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void createPoint(Matrix_ & matrix_, const ::dtl::type::size layer_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size set_x_, const ::dtl::type::size set_y_, const Matrix_Var_ value_) noexcept {
					if (x_ <= set_x_ || y_ <= set_y_) return;
					matrix_[set_y_][set_x_][layer_] = value_;
				}

				template<typename Matrix_Var_>
				class PointUnique {
				private:
					::dtl::type::size x{}, y{};
					Matrix_Var_ value{ 1 };
				public:
					constexpr PointUnique(const ::dtl::type::size x_, const ::dtl::type::size y_) noexcept :x(x_), y(y_) {}
					constexpr PointUnique(const ::dtl::type::size x_, const ::dtl::type::size y_, const Matrix_Var_ value_) noexcept :x(x_), y(y_), value(value_) {}

					template<typename Matrix_>
					DTL_VERSIONING_CPP14_CONSTEXPR
						void draw(Matrix_& matrix_, const ::dtl::type::size layer_) const noexcept {
						::dtl::shape::layer::normal::createPoint(matrix_, layer_, x, y, value);
					}
					template<typename Matrix_>
					DTL_VERSIONING_CPP14_CONSTEXPR
						void draw(Matrix_& matrix_, const ::dtl::type::size layer_, const ::dtl::type::size size_x_, const ::dtl::type::size size_y_) const noexcept {
						::dtl::shape::layer::normal::createPoint(matrix_, layer_, size_x_, size_y_, x, y, value);
					}
					template<typename Matrix_>
					DTL_VERSIONING_CPP14_CONSTEXPR
						void draw(Matrix_& matrix_, const ::dtl::type::size layer_, const ::dtl::type::size size_) const noexcept {
						::dtl::shape::layer::normal::createPoint(matrix_, layer_, size_, size_, x, y, value);
					}
				};

			}
		}
	}
}

#endif //Included Dungeon Template Library