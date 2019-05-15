//#include <DTL/Shape/Ellipse.hpp>
#include <DTL.hpp>
#include <array>

//#include <DTL/Shape/Ellipse.hpp>

int main() {

	std::array<std::bitset<51>, 31> matrix{ {} };

	//dtl::Border<int>(1).draw(matrix);


	//dtl::shape::Ellipse<int>(1).draw(matrix, 51, 35);
	dtl::OutputStringBool<int>("■", "□").draw(matrix);

}