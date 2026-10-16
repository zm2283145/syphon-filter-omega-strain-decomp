/*
 * main/gameFrontEnd: 5 files, 002C7810-002C7B30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C7810 */
#pragma push /* merge_units */
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
#pragma pop /* merge_units */
/* merge_units: end func_002C7810 */

/* merge_units: begin func_002C79E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_002C79E0(void) {
    return 0;
}

int func_002C79F0(void) {
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_002C79E0 */

/* merge_units: begin func_002C7A00 */
#pragma push /* merge_units */
typedef struct {
    int a[5];
    char pad0[0x12C - 0x14];
    int b[4];
    char pad1[0x258 - 0x13C];
    char c;
    char pad2[0x2A4 - 0x259];
} Data7A00;
typedef struct { int max; int ver; int flags; unsigned char mode; } Prm7A00;
extern int func_002E9B60(void);
extern int func_002E9BE8(int* db, int offset, int size, int count, int type, Prm7A00* prm);
extern int func_002E9CD0(int* table, char* name, int size);
extern int func_002E9D88(int table, void* a, void* b, void* c);
extern int D_0051EE80;
extern void func_002C7BA0(void);
extern void func_002C7B30(void);
extern void func_002C7B20(void);
unsigned char func_002C7A00(void)
{
    int db;
    int table;
    Prm7A00 prm;
    Data7A00 data;
    Data7A00* d;
    unsigned char ok;
    int err;
    ok = 0;
    prm.max = 0x64;
    prm.ver = 1;
    prm.mode = 0;
    prm.flags = 0;
    if (func_002E9B60() == 0 &&
        func_002E9BE8(&db, 0, 4, 5, 0x4B, &prm) == 0) {
        d = &data;
        if (func_002E9BE8(&db, (char*)data.b - (char*)d, 4, 4, 0x4B, &prm) == 0 &&
            (err = func_002E9BE8(&db, (char*)&data.c - (char*)d, 1, 0, 0x4B, &prm)) == 0 &&
            err == 0 &&
            func_002E9CD0(&table, "NetGenerator", 0x2A4) == 0 &&
            func_002E9D88(table, func_002C7BA0, func_002C7B30, func_002C7B20) == 0) {
            ok = 1;
            D_0051EE80 = table;
        }
    }
    return ok;
}
#pragma pop /* merge_units */
/* merge_units: end func_002C7A00 */

/* merge_units: begin func_002C7B20 */
#pragma push /* merge_units */
void func_002C7B20(void) {
}
#pragma pop /* merge_units */
/* merge_units: end func_002C7B20 */

/* merge_units: begin func_002C7B30 */
#pragma push /* merge_units */
extern char D_0051EE88[];
#if 0 /* merge_units */
extern char D_005723C8[];
#endif /* merge_units */
#define D_005723C8 ((char*)&D_005723C8) /* merge_units */

extern int func_002EB650(int, int);

void func_002C7B30(void) {
    int loc[2];
    int a0, a1, v0, v1;
    int cond;

    v1 = *(unsigned char*)(char*)D_005723C8;
    cond = v1 != 0;
    v1 = 0 + 1;
    if (cond) goto L002C7B50;
    *(char*)(char*)D_005723C8 = v1;
L002C7B50:;
    v1 = *(int*)(char*)D_0051EE88;
    cond = v1 != 0;
    a0 = (int)loc;
    if (cond) goto L002C7B80;
    v0 = func_002EB650(a0, a1);
    cond = v0 != 0;
    if (cond) goto L002C7B80;
    v1 = *(int*)(char*)loc;
    v1 = *(int*)((char*)v1 + 28);
    *(int*)(char*)D_0051EE88 = v1;
L002C7B80:;
    *(char*)(char*)D_005723C8 = 0;
    goto ret;
ret:;
}
#undef D_005723C8 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C7B30 */
