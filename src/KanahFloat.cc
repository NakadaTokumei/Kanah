#include <KanahType.h>

namespace kanah
{

// ========================== 32 Bit Float Type ==========================
void 
Float<FloatBit::FLOAT_32>::SetValue(const float& val)
{
    this->val = WasmEdge_ValueGenF32(val);
}

void 
Float<FloatBit::FLOAT_32>::SetValue(float&& val) 
{
    this->val = WasmEdge_ValueGenF32(val);
}

WasmEdge_Value
Float<FloatBit::FLOAT_32>::GetValue(void) const
{
    return val;
}
// =======================================================================

// ========================== 64 Bit Float Type ==========================
void 
Float<FloatBit::FLOAT_64>::SetValue(const double& val)
{
    this->val = WasmEdge_ValueGenF64(val);
}

void 
Float<FloatBit::FLOAT_64>::SetValue(double&& val) 
{
    this->val = WasmEdge_ValueGenF64(val);
}

WasmEdge_Value
Float<FloatBit::FLOAT_64>::GetValue(void) const
{
    return val;
}
// =======================================================================

};