#ifndef __KANAHTYPE_H__
#define __KANAHTYPE_H__

#include <cstdint>
#include <type_traits>
#include <wasmedge/wasmedge.h>

namespace kanah
{

enum class IntBit
{
    INTEGER_NONE,
    INTEGER_32,
    INTEGER_64,
    INTEGER_128 // For SIMD
};

template<IntBit bit = IntBit::INTEGER_NONE, typename = void>
class Int;

template<>
class Int<IntBit::INTEGER_NONE>
{
public:
    void SetValue(const uint32_t&);
    void SetValue(uint32_t&&);

    const uint32_t GetValue(void);
};

template<IntBit BIT>
class Int<BIT, std::enable_if_t<(BIT == IntBit::INTEGER_32)>>
{
    WasmEdge_Value val;
public:
    void SetValue(const int32_t& val);
    void SetValue(int32_t&& val);

    WasmEdge_Value GetValue(void) const;
};

template<IntBit BIT>
class Int<BIT, std::enable_if_t<(BIT == IntBit::INTEGER_64)>>
{
    WasmEdge_Value val;
public:
    void SetValue(const int64_t& val);
    void SetValue(int64_t&& val);

    WasmEdge_Value GetValue(void) const;
};

}

#endif