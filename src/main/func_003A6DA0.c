#pragma cplusplus on
#include "types.h"
/* a member with a user-defined assignment makes the implicit Info copy memberwise (char arrays copied two bytes per step) */
struct W3A6DA0 { int v; void operator=(const W3A6DA0& o) { v = o.v; } };
struct Info3A6DA0 { int a; int b; char name[16]; char ext[8]; W3A6DA0 size; };
struct Buf3A6DA0 { Info3A6DA0 info; char sync[4]; };
extern "C" {
extern Buf3A6DA0 D_00542940;
static Buf3A6DA0* D_00493500 = &D_00542940;
extern int D_0053DC00;
extern int func_00118CD8(Info3A6DA0* out, char* name);
extern char* strncpy(char* d, const char* s, int n);
extern void SyncDCache(void* p, char* k);
extern void InvalidDCache(void* p, char* k);
extern int snd_SendIOPCommandAndWait(int cmd, int size, void* req);
}
#pragma push
#pragma opt_unroll_count 2
extern "C" int func_003A6DA0(Info3A6DA0* out, char* name)
{
    struct { Buf3A6DA0* buf; char path[0xFC]; } req;
    int r;
    char* k;
    if (D_0053DC00 == 0) return func_00118CD8(out, name);
    req.buf = D_00493500;
    strncpy(req.path, name, 0xFC);
    req.path[0xFB] = 0;
    k = D_00493500->sync;
    SyncDCache(D_00493500, k);
    r = snd_SendIOPCommandAndWait(0x69, 0x100, &req);
    if (r == 1) {
        InvalidDCache(D_00493500, k);
        *out = D_00493500->info;
    }
    return r;
}
#pragma pop
