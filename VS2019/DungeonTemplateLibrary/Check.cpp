#include <DTL.hpp>
#include <cstddef>
#include <cstdint>
#include <array>
#include <bitset>

using shape_t = std::uint_fast8_t;
constexpr std::size_t width{ 16 };
constexpr std::size_t height{ 8 };
constexpr std::size_t layer_max{ 2 };
constexpr std::size_t draw_layer{ 1 };

constexpr dtl::base::MatrixRange mr(width / 2, height / 2, width, height);
constexpr dtl::base::MatrixRange mr2(width / 3, height / 3, width * 2 / 3, height * 2 / 3);

class Tester {
private:
	//bool
	std::array<std::bitset<width>, height> matrix_bool{ {} };
	std::array<std::array<std::bitset<layer_max>, width>, height> matrix_bool_layer{ {} };
	std::array<std::bitset<width>, height> matrix_bool_normal{ {} };
	std::array<std::array<std::bitset<layer_max>, width>, height> matrix_bool_layer_normal{ {} };
	std::bitset<width* height> matrix_bool_array{ {} };
	//array
	std::array<std::array<shape_t, width>, height> matrix_stl{ {} };
	std::array<std::array<std::array<shape_t, layer_max>, width>, height> matrix_layer_stl{ {} };
	shape_t matrix_normal[height][width]{};
	shape_t matrix_layer_normal[height][width][layer_max]{};
	shape_t matrix_array[height * width]{};
public:

	template<typename Shape_>
	void create(const Shape_& shape_) noexcept {
		shape_.draw(matrix_stl);
		shape_.draw(matrix_layer_stl, draw_layer);
		shape_.draw(matrix_normal, width, height);
		shape_.draw(matrix_layer_normal, draw_layer, width, height);
		shape_.drawArray(matrix_array, width, height);
	}
	template<typename Shape_>
	void createBool(const Shape_& shape_) noexcept {
		shape_.draw(matrix_bool);
		shape_.draw(matrix_bool_layer, draw_layer);
		shape_.draw(matrix_bool_normal, width, height);
		shape_.draw(matrix_bool_layer_normal, draw_layer, width, height);
		shape_.drawArray(matrix_bool_array, width, height);
	}
	template<typename Shape_>
	void output(const Shape_& shape_) noexcept {
		std::cout << "\n--------- Output ----------\n";
		std::cout << "\n[STL]\n";
		shape_.draw(matrix_stl);
		std::cout << "\n[Layer-STL]\n";
		shape_.draw(matrix_layer_stl, draw_layer);
		std::cout << "\n[Normal]\n";
		shape_.draw(matrix_normal, width, height);
		std::cout << "\n[Layer-Normal]\n";
		shape_.draw(matrix_layer_normal, draw_layer, width, height);
		std::cout << "\n[Array]\n";
		shape_.drawArray(matrix_array, width, height);
	}
	template<typename Shape_>
	void outputBool(const Shape_& shape_) noexcept {
		std::cout << "\n--------- Bool ----------\n";
		std::cout << "\n[STL]\n";
		shape_.draw(matrix_bool);
		std::cout << "\n[Layer-STL]\n";
		shape_.draw(matrix_bool_layer, draw_layer);
		std::cout << "\n[Normal]\n";
		shape_.draw(matrix_bool, width, height);
		std::cout << "\n[Layer-Normal]\n";
		shape_.draw(matrix_bool_layer, draw_layer, width, height);
		std::cout << "\n[Array]\n";
		shape_.drawArray(matrix_bool_array, width, height);
	}

};



int main() {

	Tester t{};

#define RECT PointGrid
	t.create(dtl::utility::Init<shape_t>(0));
	t.createBool(dtl::utility::Init<bool>(0));
	t.create(dtl::shape::RECT<shape_t>(1));
	t.createBool(dtl::shape::RECT<bool>(1));
	t.output(dtl::console::OutputStringBool<shape_t>("#", "/"));
	t.outputBool(dtl::console::OutputStringBool<shape_t>("#", "/"));
	t.create(dtl::utility::Init<shape_t>(0));
	t.createBool(dtl::utility::Init<bool>(0));
	t.create(dtl::shape::RECT<shape_t>(mr, 1));
	t.createBool(dtl::shape::RECT<bool>(mr, 1));
	t.output(dtl::console::OutputStringBool<shape_t>("#", "/"));
	t.outputBool(dtl::console::OutputStringBool<shape_t>("#", "/"));
	t.create(dtl::utility::Init<shape_t>(0));
	t.createBool(dtl::utility::Init<bool>(0));
	t.create(dtl::shape::RECT<shape_t>(mr2, 1));
	t.createBool(dtl::shape::RECT<bool>(mr2, 1));
	t.output(dtl::console::OutputStringBool<shape_t>("#", "/"));
	t.outputBool(dtl::console::OutputStringBool<shape_t>("#", "/"));

}