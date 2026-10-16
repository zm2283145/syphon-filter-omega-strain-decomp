/*
 * main/gameFrontEnd: 2 files, 002C7560-002C7630
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C7560 */
#pragma push /* merge_units */
#include "types.h"
typedef struct {
    void* vtable;
    int version;
    int header[6];
    int count;
    short ids[6];
    char data[0x400];
} Save7560;
extern char D_004DE148[];
extern int D_0051EE70;
extern void func_002E9A10(void);
extern int func_002E9A98(void* f, void* buf, int size, int count);
extern int func_002E9F08(int* out, void* fn);
extern void func_002C7810(void);
void func_002C7560(void)
{
    int handle;
    Save7560 f;
    f.vtable = D_004DE148;
    func_002E9A10();
    if (func_002E9A98(&f, &f.version, 4, 1) == 0 &&
        func_002E9A98(&f, f.header, 4, 6) == 0 &&
        func_002E9A98(&f, &f.count, 4, 1) == 0 &&
        func_002E9A98(&f, f.ids, 2, 6) == 0 &&
        func_002E9A98(&f, f.data, 1, 0x400) == 0 &&
        func_002E9F08(&handle, func_002C7810) == 0)
        D_0051EE70 = handle;
}
#pragma pop /* merge_units */
/* merge_units: end func_002C7560 */

/* merge_units: begin func_002C7630 */
#pragma push /* merge_units */
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
#pragma pop /* merge_units */
/* merge_units: end func_002C7630 */
