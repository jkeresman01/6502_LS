#pragma once

#ifdef __cplusplus
#if __cplusplus >= 201103L
#define STATIC_ASSERT(expr) static_assert(expr, "static asssert failed: " #expr)
#else
template <bool>
class TStaticAssert;
template <>
class TStaticAssert<true>
{
};

#define STATIC_ASSERT(expr)                                                     \
    enum                                                                        \
    {                                                                           \
        ASSERT_GLUE(g_assert_fail_, __LINE__) = sizeof(TStaticAssert<!!(expr)>) \
    }
#endif
#endif
