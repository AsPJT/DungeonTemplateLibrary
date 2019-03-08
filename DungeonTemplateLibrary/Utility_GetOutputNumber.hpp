#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_GET_OUTPUT_NUMBER
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_GET_OUTPUT_NUMBER
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

/* Bug Check : not checked */
/* Android NDK Compile (Clang 5.0) : already checked */

//共有データ
namespace dtl::utility::tool {

	template<typename Matrix_Int_>
	[[nodiscard]] constexpr auto getOutputNumber(const Matrix_Int_ value_) noexcept {
		return value_;
	}
	template<>
	[[nodiscard]] constexpr auto getOutputNumber<char>(const char value_) noexcept {
		return static_cast<int>(value_);
	}
	template<>
	[[nodiscard]] constexpr auto getOutputNumber<signed char>(const signed char value_) noexcept {
		return static_cast<int>(value_);
	}
	template<>
	[[nodiscard]] constexpr auto getOutputNumber<unsigned char>(const unsigned char value_) noexcept {
		return static_cast<int>(value_);
	}

}

#endif //Included Dungeon Template Library