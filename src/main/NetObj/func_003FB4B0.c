#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct Ctrl {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual unsigned char GetState();
};
struct NObj { char pad[0x49]; unsigned char type; char pad4A[0xE]; Ctrl* ctrl; };
struct NMap { int unk0; int unk4; };

extern "C" {
NMap* NetMap_Lookup(void);
NObj* Object_LookupById(int* id);
void* Mem_Alloc(int, int, char*, int);
void* func_00436C00(void* p);
void func_004344A0(void* mgr, int id, int val);
extern void* D_0055C988;
extern char D_004BE228[];
}

extern "C" void func_003FB4B0(int id, int val) {
    NMap* m = NetMap_Lookup();
    int key = id;
    NObj* o = Object_LookupById(&key);
    if (m) {
        if (o && o->ctrl && o->type == 2) {
            if (o->ctrl->GetState() == 2 || o->ctrl->GetState() == 1) {
            if (!D_0055C988) {
                void* p;
                {
                    AllocGuard g;
                    p = Mem_Alloc(0, 1, D_004BE228, 0x20C);
                }
                if (p) p = func_00436C00(p);
                D_0055C988 = p;
            }
            func_004344A0(D_0055C988, id, val);
            } else {
                m->unk4 = val;
            }
        } else {
            m->unk4 = val;
        }
    }
}
