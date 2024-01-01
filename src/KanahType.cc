#include <KanahType.h>

namespace kanah
{

// ========================= 32 Bit Integer Type =========================
void 
Int<IntBit::INTEGER_32>::SetValue(const int32_t& val)
{
    this->val = WasmEdge_ValueGenI32(val);
}

void 
Int<IntBit::INTEGER_32>::SetValue(int32_t&& val) 
{
    this->val = WasmEdge_ValueGenI32(val);
}

WasmEdge_Value
Int<IntBit::INTEGER_32>::GetValue(void) const
{
    return val;
}
// =======================================================================

// ========================= 64 Bit Integer Type =========================
void 
Int<IntBit::INTEGER_64>::SetValue(const int64_t& val)
{
    this->val = WasmEdge_ValueGenI64(val);
}

void 
Int<IntBit::INTEGER_64>::SetValue(int64_t&& val)
{
    this->val = WasmEdge_ValueGenI64(val);
}

WasmEdge_Value
Int<IntBit::INTEGER_64>::GetValue(void) const
{
    return val;
}
// =======================================================================

};