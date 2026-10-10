#include "types.h"
#pragma cplusplus on
class E7VC {
public:
    int pad0;
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void Disable();
};
struct E7Light { int pad0; void* vt; int id; };
extern "C" {
extern void* D_004D9200[];
extern void* D_004D9240[];
extern void* D_004D9280[];
extern unsigned char D_00535D62;
extern int D_00535D20;
extern void func_00373D70(void* pool, void* p);
E7Light* func_00144A60(E7Light* p, short flag) {
    if (p) {
        p->vt = D_004D9200;
        if (p) {
            p->vt = D_004D9240;
            p->id = -1;
            ((E7VC*)p)->Disable();
            D_00535D62 = 1;
            if (p) {
                p->vt = D_004D9280;
            }
        }
        if (flag > 0) {
            func_00373D70(&D_00535D20, p);
        }
    }
    return p;
}
}