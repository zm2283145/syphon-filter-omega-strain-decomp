/*
 * main/tank: 3 files, 002822F0-002824D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002822F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
typedef struct { int kind; int id; short len; short idx; unsigned char data[1]; } Pk2822F0;
typedef void (*Fn2822F0)(void*);
typedef struct { int a; int b; Fn2822F0* data; } Vec2822F0;
extern "C" {
extern unsigned char D_005721D0;
extern int D_005061D8;
extern unsigned char* D_005061D0;
void** NetMap_Lookup(int);
Vec2822F0* cNetMsg_GetFuncList(void);
}
#pragma push
#pragma opt_propagation off
extern "C" int cNetMsg_Callback(int a0, int a1, int a2, Pk2822F0* arg) {
    NetRecvGuard g;
    Pk2822F0* p = arg;
    if (D_005721D0) {
        void** e = NetMap_Lookup(p->id);
        void* obj;
        short idx;
        obj = 0; if (e) obj = *e;
        idx = p->idx;
        if (idx < D_005061D8 && idx >= 0) {
            Fn2822F0 fn = cNetMsg_GetFuncList()->data[(short)idx];
            unsigned char* save = D_005061D0;
            D_005061D0 = p->data;
            fn(obj);
            D_005061D0 = save;
        }
    }
    return p->len + 0xC;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_002822F0 */

/* merge_units: begin func_002823E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
struct Msg2823E0 {
    VPAD4(a) virtual void Write(); virtual short Kind();
};
typedef struct { char pad[8]; short len; short kind; unsigned char data[1]; } Buf2823E0;
extern "C" {
extern int D_005061C8;
void Event_PackHeader(Msg2823E0* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf);
void printf(const char* format, ...);
}
#pragma push
#pragma opt_propagation off
extern "C" int cNetMsg_Pack(Msg2823E0* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf) {
    int r = -1;
    if (size >= 0x10C && buf) {
        Buf2823E0* b = (Buf2823E0*)buf;
        unsigned char* save;
        int n;
        Event_PackHeader(e, a1, type, a3, a4, size, buf);
        b->kind = e->Kind();
        save = D_005061D0;
        D_005061D0 = b->data;
        e->Write();
        n = D_005061D0 - b->data;
        D_005061D0 = save;
b->len = n;
        if (type) {
            r = n + 0xC;
            *type = D_005061C8;
        }
    }
    if ((unsigned int)r > 0x10C) printf("size = %d\n", r);
    return r;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_002823E0 */

/* merge_units: begin func_002824D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

extern int PtrVec_Insert(PtrVec*, int*, int, int*);
extern int PtrVec_PushBack_282530(PtrVec*, int*);
#if 0 /* merge_units */
extern PtrVec* cNetMsg_GetFuncList(void);
#endif /* merge_units */
#define cNetMsg_GetFuncList() ((PtrVec *)cNetMsg_GetFuncList()) /* merge_units */


/* Appends a value to the list from cNetMsg_GetFuncList and hands out the next id from D_005061D8. */
int NetMsgTable_Add(int value, int* outId) {
    int tmp;

    tmp = value;
    PtrVec_PushBack_282530(cNetMsg_GetFuncList(), &tmp);
    *outId = D_005061D8;
    D_005061D8 = D_005061D8 + 1;
    return *outId;
}

/* push_back */
int PtrVec_PushBack_282530(PtrVec* v, int* value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}
#undef cNetMsg_GetFuncList /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002824D0 */
