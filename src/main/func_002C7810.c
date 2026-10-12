#pragma opt_propagation off
#pragma cplusplus on
#include "alloc_guard.h"

extern "C" {
extern void* Mem_Alloc(int pool, int size, char* file, int line);
extern char D_004AC980[];
extern char D_004DE148[];
extern char D_004DE168[];
extern unsigned char D_005721D0;
extern unsigned char D_005723C8;
extern void func_002C6B70(void* msg, int target);
extern void func_003FA8C0(int target, int id, void* msg, int flag);
}

struct V6 { float f[6]; };

struct MsgBase {
    void* vt;
    MsgBase(const MsgBase&) { vt = D_004DE168; }
};

struct MsgMid : MsgBase {
    MsgMid(const MsgMid& o) : MsgBase(o) { vt = D_004DE148; }
};

struct Msg7810 : MsgMid {
    int id;
    V6 v;
    int x20;
    short arr[6];
    char data[0x400];
    static void* operator new(unsigned int size) {
        AllocGuard guard;
        return Mem_Alloc(0, size, D_004AC980, 0x11);
    }
};

extern "C" int func_002C7810(void* self, int unused, int target, Msg7810* src)
{
    if (!D_005723C8) {
        D_005723C8 = 1;
    }
    Msg7810* s = src;
    if (D_005721D0) {
        func_002C6B70(s, target);
    } else {
        Msg7810* p = new Msg7810(*s);
        func_003FA8C0(target, s->id, p, 1);
    }
    D_005723C8 = 0;
    return 0x430;
}