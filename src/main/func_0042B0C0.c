#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Vec42B { int a; };
/* the float member keeps the iterator in memory and makes copies go through an FPR, as in retail */
union It42B { char** p; float f; bool operator==(const It42B& o) const { return p == o.p; } bool operator!=(const It42B& o) const { return !(*this == o); } It42B& operator++() { p++; return *this; } char* operator*() const { return *p; } };
class Obj42B { public: VPAD32(a) VPAD16(b) VPAD8(c) VPAD4(d) VPAD1(e) virtual void Notify(int); };
extern "C" {
extern unsigned char D_005721D0;
void* func_0040CA20(void);
Vec42B* func_001339A0(void* arr);
void PtrVec_Begin(It42B* out, Vec42B* v);
void PtrVec_End(It42B* out, Vec42B* v);
void func_00133980(It42B* out, It42B* in);
}
static inline void GetBegin(It42B* o, Vec42B* v) { It42B tb; PtrVec_Begin(&tb, v); func_00133980(o, &tb); }
static inline void GetEnd(It42B* o, Vec42B* v) { It42B te; PtrVec_End(&te, v); func_00133980(o, &te); }

extern "C" void func_0042B0C0(void)
{
    void* arr;
    It42B it;
    It42B end;
    D_005721D0 = 1;
    arr = func_0040CA20();
    GetEnd(&end, func_001339A0(arr));
    {
        It42B b;
        GetBegin(&b, func_001339A0(arr));
        it = b;
    }
    for (; it != end; ++it)
        ((Obj42B*)*it)->Notify(0);
}
