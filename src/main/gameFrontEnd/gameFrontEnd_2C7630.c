#pragma opt_propagation off
#pragma cplusplus on
#include "alloc_guard.h"

extern "C" {
extern void* Mem_Alloc(int pool, int size, char* file, int line);
extern char D_004AC960[];
extern char D_004DE158[];
extern char D_004DE168[];
extern unsigned char D_005721D0;
extern unsigned char D_005723C8;
extern void func_002C6690(void* msg, int target);
extern void func_003FA8C0(int target, int id, void* msg, int flag);
}

struct V6 { float f[6]; };

struct MsgBase {
    void* vt;
    MsgBase(const MsgBase&) { vt = D_004DE168; }
};

struct MsgMid : MsgBase {
    MsgMid(const MsgMid& o) : MsgBase(o) { vt = D_004DE158; }
};

struct Msg7630 : MsgMid {
    int id;
    V6 v;
    short arr[6];
    char name[0x20];
    unsigned char c1;
    unsigned char c2;
    short slot;
    static void* operator new(unsigned int size) {
        AllocGuard guard;
        return Mem_Alloc(0, size, D_004AC960, 0x2D);
    }
};

extern "C" int func_002C7630(void* self, int unused, int target, Msg7630* src)
{
    if (!D_005723C8) {
        D_005723C8 = 1;
    }
    Msg7630* s = src;
    if (D_005721D0) {
        if (D_005721D0) {
            func_002C6690(s, target);
        } else {
            Msg7630* p = new Msg7630(*s);
            func_003FA8C0(target, s->id, p, 0);
        }
    }
    D_005723C8 = 0;
    return 0x50;
}
