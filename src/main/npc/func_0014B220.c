#pragma cplusplus on
#include "types.h"
struct E2Npc {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F();
    virtual unsigned char GetState(); /* +0x108 */
    char pad[8];
    int serial;
};
struct E2Handle { E2Npc* obj; int serial; };
struct E2Node { int f0; E2Node* next; E2Handle* handle; };
extern "C" void func_0013B180(int*, void*);
extern "C" void func_0014ABC0(E2Node**, int*);
extern "C" void func_0014AB80(int*, void*);
extern "C" void func_0014AB70(E2Node**, int*);
extern char D_004EA190[];
static inline void E2End(E2Node** e) {
    int tmp;
    func_0014AB80(&tmp, D_004EA190);
    func_0014AB70(e, &tmp);
}
static inline int E2NonNull(E2Npc* p) { return p != 0; }
static inline bool E2Idle(unsigned char s) { return s == 2 || s == 3; }
static inline E2Npc* E2Get(E2Handle* h) {
    bool ok = true;
    if ((E2NonNull(h->obj) ^ 1) == 0 && h->obj->serial != h->serial) ok = false;
    return ok ? h->obj : 0;
}
extern "C" int func_0014B220(void)
{
    E2Node* e;
    E2Node* it;
    int b;
    int count = 0;
    func_0013B180(&b, D_004EA190);
    func_0014ABC0(&it, &b);
    for (E2Node* n = it; E2End(&e), n != e; n = n->next) {
        if (!E2Idle(E2Get(n->handle)->GetState())) count++;
    }
    return count;
}