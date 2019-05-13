#include <DTL.hpp>
#include <array>
#include <string>

int main() {

	std::array<std::array<int, 10>, 10> matrix{ {} };

	dtl::Border<int>(1).draw(matrix);

	std::string str{};
	dtl::board::WriteNumber<int>("\n", "(", "), ").draw(matrix, str);

	std::cout << str;

}