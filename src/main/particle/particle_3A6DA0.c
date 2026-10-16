/*
 * main/particle: 4 files, 003A6DA0-003A6F70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003A6DA0 */
#pragma push /* merge_units */
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
extern int sceCdSearchFile_Thunk(Info3A6DA0* out, char* name);
extern char* strncpy(char* d, const char* s, int n);
extern void SyncDCache(void* p, char* k);
extern void InvalidDCache(void* p, char* k);
extern int snd_SendIOPCommandAndWait(int cmd, int size, void* req);
}
#pragma push
#pragma opt_unroll_count 2
extern "C" int Cd_SearchFile(Info3A6DA0* out, char* name)
{
    struct { Buf3A6DA0* buf; char path[0xFC]; } req;
    int r;
    char* k;
    if (D_0053DC00 == 0) return sceCdSearchFile_Thunk(out, name);
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
#pragma pop /* merge_units */
/* merge_units: end func_003A6DA0 */

/* merge_units: begin func_003A6ED0 */
#pragma push /* merge_units */
extern int D_00542810;
extern int sceCdGetError(void);
/* Return the cached value when enabled, otherwise query it. */
int Cd_GetError(void)
{
    if (D_0053DC00) {
        return D_00542810;
    }
    return sceCdGetError();
}
#pragma pop /* merge_units */
/* merge_units: end func_003A6ED0 */

/* merge_units: begin func_003A6F10 */
#pragma push /* merge_units */
/* Send IOP command 0x37 when the sound IOP is up, else fall back. */

extern int sceCdBreak(void);
extern void snd_SendIOPCommandNoWait(int cmd, int size, void* data, int a3, int t0);

int Cd_Break(void)
{
    if (D_0053DC00 == 0)
        return sceCdBreak();
    snd_SendIOPCommandNoWait(0x37, 0, 0, 0, 0);
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_003A6F10 */

/* merge_units: begin func_003A6F70 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void InvalidDCache(int*, char*);
#endif /* merge_units */
#define InvalidDCache(a0, a1) (InvalidDCache((void *)(a0), (a1))) /* merge_units */

extern int sceCdSync(void);
extern void snd_FlushSoundCommands(void);
extern int D_0053DC18;
extern int D_00542800;
extern char D_0054283F;
static inline unsigned char Done3A6F70(void) { return !D_00542800; }
static inline int Poll3A6F70(char* k) {
    int t;
    InvalidDCache(&D_00542800, k);
    t = Done3A6F70();
    D_0053DC18 = t;
    return t;
}
#pragma push
#pragma bool off
int Cd_Sync(int wait)
{
    char* k;
    if (D_0053DC00 == 0) return sceCdSync();
    k = &D_0054283F;
    if (Poll3A6F70(k) == 1) return 0;
    if (wait == 1) return 1;
    while (D_0053DC18 == 0) {
        snd_FlushSoundCommands();
        Poll3A6F70(k);
    }
    return 0;
}
#pragma pop
#undef InvalidDCache /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A6F70 */
