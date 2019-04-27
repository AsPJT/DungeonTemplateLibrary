#include <DTL.hpp>
#include <chrono>

template<typename Generator_, typename Matrix_Int_>
class Tester {
private:

	using Var = std::vector<Matrix_Int_>;
	using VVar = std::vector<Var>;
	using VVVar = std::vector<std::vector<Var>>;

	Generator_ generator{};
	std::uint_fast64_t stl_time{};
	std::uint_fast64_t stl_layer_time{};
	std::uint_fast64_t normal_time{};
	std::uint_fast64_t normal_layer_time{};
	std::uint_fast64_t array_time{};

	VVar matrix_stl{};
	VVVar matrix_stl_layer{};
	VVar matrix_normal{};
	VVVar matrix_normal_layer{};
	Var matrix_array{};

public:

	template<typename ...Args_>
	constexpr explicit Tester(Args_&& ... args_) noexcept :generator(std::forward<Args_>(args_)...) {}

	template<typename ...Args_>
	DTL_CONSTEXPR_CPP14
	Tester& draw(const std::size_t max_layer_, const std::size_t select_layer_, const std::size_t width_, const std::size_t height_, Args_&& ... args_) noexcept {

		std::chrono::system_clock::time_point  start{}, end{};

		matrix_stl = VVar(height_, Var(width_, 0));
		matrix_stl_layer = VVVar(height_, VVar(width_, Var(max_layer_, 0)));
		matrix_normal = VVar(height_, Var(width_, 0));
		matrix_normal_layer = VVVar(height_, VVar(width_, Var(max_layer_, 0)));
		matrix_array = Var(height_ * width_, 0);

		start = std::chrono::system_clock::now();
		generator.draw(matrix_stl, std::forward<Args_>(args_)...);
		end = std::chrono::system_clock::now();
		stl_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		
		start = std::chrono::system_clock::now();
		generator.draw(matrix_stl_layer, select_layer_, std::forward<Args_>(args_)...);
		end = std::chrono::system_clock::now();
		stl_layer_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

		start = std::chrono::system_clock::now();
		generator.draw(matrix_normal, width_, height_, std::forward<Args_>(args_)...);
		end = std::chrono::system_clock::now();
		normal_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

		start = std::chrono::system_clock::now();
		generator.draw(matrix_normal_layer, select_layer_, width_, height_, std::forward<Args_>(args_)...);
		end = std::chrono::system_clock::now();
		normal_layer_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

		start = std::chrono::system_clock::now();
		generator.drawArray(matrix_array, width_, height_, std::forward<Args_>(args_)...);
		end = std::chrono::system_clock::now();
		array_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		return *this;
	}
	Tester& OutputTime() noexcept {
		std::cout << "\n[Time]\n";
		std::cout << "STL: " << this->stl_time << '\n';
		std::cout << "STL-Layer: " << this->stl_layer_time << '\n';
		std::cout << "Normal: " << this->normal_time << '\n';
		std::cout << "Normal-Layer: " << this->normal_layer_time << '\n';
		std::cout << "Array: " << this->array_time << '\n';
		return *this;
	}
	template<typename ...Args_>
	Tester& OutputMatrix(const std::size_t select_layer_, const std::size_t width_, const std::size_t height_, Args_&& ... args_) noexcept {
		std::cout << "\n[Matrix]\n";
		dtl::OutputString<Matrix_Int_>(args_...).draw(this->matrix_stl);
		std::cout << '\n';
		dtl::OutputString<Matrix_Int_>(args_...).draw(this->matrix_stl_layer, select_layer_);
		std::cout << '\n';
		dtl::OutputString<Matrix_Int_>(args_...).draw(this->matrix_normal, width_, height_);
		std::cout << '\n';
		dtl::OutputString<Matrix_Int_>(args_...).draw(this->matrix_normal_layer, select_layer_, width_, height_);
		std::cout << '\n';
		dtl::OutputString<Matrix_Int_>(args_...).drawArray(this->matrix_array, width_, height_);
		std::cout << '\n';
		return *this;
	}

};

int main() {

	using shape_t = std::uint_fast8_t;
	constexpr std::size_t width{ 128 };
	constexpr std::size_t height{ 64 };
	std::array<std::array<shape_t, width>, height> matrix{ {} };

	//Tester<dtl::PointGridAndSomeBlocksWithBorder<shape_t>, shape_t>((shape_t)1, (shape_t)2, (shape_t)3, 0.8).
	//	draw(2, 0, width, height).OutputTime().OutputMatrix(0, width, height, "  ", "##", "%%", "//");

	dtl::WhiteNoise<shape_t>(1).draw(matrix);
	dtl::OutputString<shape_t>(" ", "#").draw(matrix);

}