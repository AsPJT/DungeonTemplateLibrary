#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_MACROS_NODISCARD_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_MACROS_NODISCARD_HPP

#ifndef DTL_NODISCARD
#ifdef __has_cpp_attribute
#if __has_cpp_attribute(nodiscard)
#define DTL_NODISCARD [[nodiscard]]
#endif
#elif defined(__clang__)
#define DTL_NODISCARD __attribute__((warn_unused_result))
#elif defined(_MSC_VER)
// _Must_inspect_result_ expands into this
#define DTL_NODISCARD                                                                                                                                                                                                                                                                                                \
  __declspec("SAL_name"                                                                                                                                                                                                                                                                                                        \
             "("                                                                                                                                                                                                                                                                                                               \
             "\"_Must_inspect_result_\""                                                                                                                                                                                                                                                                                       \
             ","                                                                                                                                                                                                                                                                                                               \
             "\"\""                                                                                                                                                                                                                                                                                                            \
             ","                                                                                                                                                                                                                                                                                                               \
             "\"2\""                                                                                                                                                                                                                                                                                                           \
             ")") __declspec("SAL_begin") __declspec("SAL_post") __declspec("SAL_mustInspect") __declspec("SAL_post") __declspec("SAL_checkReturn") __declspec("SAL_end")
#endif
#endif
#ifndef DTL_NODISCARD
#define DTL_NODISCARD
#endif

#endif
