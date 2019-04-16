#include <DTL.hpp>
#include <array>
#include <bitset>

int main() {

	std::array<std::bitset<63>, 31> matrix{ {} };
	dtl::shape::PointGridWithBorder<bool>(1).draw(matrix);

	dtl::console::OutputStringBool<bool>("##", "  ").draw(matrix);

}