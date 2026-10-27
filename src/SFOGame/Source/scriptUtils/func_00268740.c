#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "alloc_guard.h"
/* Global_RemoveArray: unlink a script array from the global array list and free it */
struct It_68740 { void* n; };
extern "C" {
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
extern char D_004A82B8[];
}
/* script array: frees its data buffer */
struct Arr_68740 {
    void* data;
    void Destroy() { void* d = data; AllocGuard g2; cMemMan_Deallocate(0, d, D_004A82B8, 0x12D); }
};
extern "C" {
extern char D_004F83E0[];
void cLListIterator_ArrayPtr_ctor_void(It_68740* it);
void cLList_ArrayPtr_Begin(It_68740* out, void* l);
void cLListIterator_ArrayPtr_opAssign(It_68740* d, It_68740* s);
void cLList_ArrayPtr_End(It_68740* out, void* l);
int opNe_cLListIteratorR_cLListIteratorR_4(It_68740* a, It_68740* b);
Arr_68740** cLListIterator_ArrayPtr_opMul(It_68740* it);
void cLListIterator_ArrayPtr_opInc(It_68740* it);
void cLListIterator_ArrayPtr_ctor_cLListIteratorR(It_68740* d, It_68740* s);
void std_list_ArrayPtr_end(It_68740* out, void* l);
void cLListIterator_ArrayPtr_ctor_listR(It_68740* d, It_68740* s);
void std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(It_68740* out, It_68740* in);
void std_list_deleter_voidPtr_erase_listdeleter(It_68740* out, void* l, It_68740* pos);
}
static inline void Find(It_68740* out, void* l, Arr_68740* a)
{
    It_68740 it;
    It_68740 t;
    It_68740 e;
    cLListIterator_ArrayPtr_ctor_void(&it);
    cLList_ArrayPtr_Begin(&t, l);
    cLListIterator_ArrayPtr_opAssign(&it, &t);
    while (cLList_ArrayPtr_End(&e, l), opNe_cLListIteratorR_cLListIteratorR_4(&it, &e)) {
        if (*cLListIterator_ArrayPtr_opMul(&it) == a) break;
        cLListIterator_ArrayPtr_opInc(&it);
    }
    cLListIterator_ArrayPtr_ctor_cLListIteratorR(out, &it);
}
static inline void EndL(It_68740* out, void* l) { It_68740 e2; std_list_ArrayPtr_end(&e2, l); cLListIterator_ArrayPtr_ctor_listR(out, &e2); }
static inline void EraseAt(void* l, It_68740* c) { It_68740 o; It_68740 p; std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&p, c); std_list_deleter_voidPtr_erase_listdeleter(&o, l, &p); }
/* pass-through layers: keep the find/end iterators below the erase temporaries (slot order) */
static inline void Find2(It_68740* out, void* l, Arr_68740* a) { Find(out, l, a); }
static inline void EndL2(It_68740* out, void* l) { EndL(out, l); }
extern "C" void Global_RemoveArray(Arr_68740* a)
{
    if (a) {
        It_68740 r;
        It_68740 e3;
        Find2(&r, D_004F83E0, a);
        EndL2(&e3, D_004F83E0);
        if (r.n != e3.n) {
            It_68740 c;
            c.n = r.n;
            EraseAt(D_004F83E0, &c);
        }
        {
            AllocGuard g;
            if (a) a->Destroy();
            cMemMan_Deallocate(0, a, D_004A82B8, 0x1AD);
        }
    }
}
