#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Vec42B { int a; };
/* the float member keeps the iterator in memory and makes copies go through an FPR, as in retail */
union It42B { char** p; float f; bool operator==(const It42B& o) const { return p == o.p; } bool operator!=(const It42B& o) const { return !(*this == o); } It42B& operator++() { p++; return *this; } char* operator*() const { return *p; } };
class Obj42B { public: VPAD32(a) VPAD16(b) VPAD8(c) VPAD4(d) VPAD1(e) virtual void Notify(int); };
extern "C" {
extern unsigned char D_005721D0;
void* nGobjManager_GetGOBJAndNodeList(void);
Vec42B* cObjList_cGOBJPtr_GetList(void* arr);
void PtrVec_Begin(It42B* out, Vec42B* v);
void PtrVec_End(It42B* out, Vec42B* v);
void cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(It42B* out, It42B* in);
}
static inline void GetBegin(It42B* o, Vec42B* v) { It42B tb; PtrVec_Begin(&tb, v); cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(o, &tb); }
static inline void GetEnd(It42B* o, Vec42B* v) { It42B te; PtrVec_End(&te, v); cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(o, &te); }

extern "C" void cDME_SetNetReady(void)
{
    void* arr;
    It42B it;
    It42B end;
    D_005721D0 = 1;
    arr = nGobjManager_GetGOBJAndNodeList();
    GetEnd(&end, cObjList_cGOBJPtr_GetList(arr));
    {
        It42B b;
        GetBegin(&b, cObjList_cGOBJPtr_GetList(arr));
        it = b;
    }
    for (; it != end; ++it)
        ((Obj42B*)*it)->Notify(0);
}
