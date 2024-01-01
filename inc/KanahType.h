#ifndef __KANAHTYPE_H__
#define __KANAHTYPE_H__

#include <cstdint>
#include <type_traits>
#include <wasmedge/wasmedge.h>

namespace kanah
{

// Start Integer Type
enum class IntBit
{
    INTEGER_NONE,
    INTEGER_32,
    INTEGER_64,
    INTEGER_128 // For SIMD(Reserved)
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
// End Integer Type

// Start Float Type
enum class FloatBit
{
    FLOAT_NONE,
    FLOAT_32,
    FLOAT_64
};

template<FloatBit bit = FloatBit::FLOAT_NONE, typename = void>
class Float;

template<>
class Float<FloatBit::FLOAT_NONE>
{
public:
    void SetValue(float &);
    void SetValue(float&&);

    const float GetValue(void);
};

template<FloatBit BIT>
class Float<BIT, std::enable_if_t<(BIT == FloatBit::FLOAT_32)>>
{
    WasmEdge_Value val;
public:
    void SetValue(const float& val);
    void SetValue(float&& val);

    WasmEdge_Value GetValue(void) const;
};

template<FloatBit BIT>
class Float<BIT, std::enable_if_t<(BIT == FloatBit::FLOAT_64)>>
{
    WasmEdge_Value val;
public:
    void SetValue(const double& val);
    void SetValue(double&& val);

    WasmEdge_Value GetValue(void) const;
};
// End Float Type

}

#endif