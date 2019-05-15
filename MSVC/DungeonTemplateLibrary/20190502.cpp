#include <DTL.hpp>
#include <array>

int main() {

	std::array<std::bitset<10>, 10> matrix{ {} };

	dtl::Border<int>(1).draw(matrix);
	dtl::OutputNumber<int>(",").draw(matrix);

}