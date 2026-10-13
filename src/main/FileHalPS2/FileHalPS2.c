/*
 * main/FileHalPS2: 5 files, 00368F60-003694D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00368F60 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { unsigned char retries; unsigned char speed; unsigned char pattern; unsigned char pad; } M368F60;
typedef struct { int pad0; int lsn; char pad8[0x20]; int status; int pad2C; int a30; int a34; int a38; int cap; char pad40[0x84]; void* buf; } S368F60;
extern int g_FrameCounter;
extern int D_00533860;
extern int func_003A6F70(int mode);
extern int func_003A7060(int lsn, int sectors, void* buf, M368F60* mode);
extern void func_003A6D50(void* cb);
extern void func_003698A0(void);
int func_00368F60(S368F60* o, int pos)
{
    M368F60 mode;
    int sector;
    int i;
    mode.retries = 0xFF;
    mode.pattern = 0;
    sector = pos / 2048;
    mode.speed = 1;
    i = 0;
    while (func_003A6F70(0) && i++ < 10000) ;
    func_003A7060(o->lsn + sector, o->cap / 2048, o->buf, &mode);
    func_003A6D50(func_003698A0);
    o->a30 = o->a34 = g_FrameCounter;
    o->a38 = 200;
    D_00533860 = -1;
    if (o->status != 0x8000) func_003A6F70(0);
    return o->cap;
}
#pragma pop /* merge_units */
/* merge_units: end func_00368F60 */

/* merge_units: begin func_00369050 */
#pragma push /* merge_units */
typedef struct { int f0; char f4[4]; int f8; char pad[0x1C]; int f28; int f2c; char pad2[0xC]; int f3c; char f40; char path[0x83]; int fc4; } F369;
extern int sprintf(char*, const char*, ...);
extern char func_0012B290(int);
extern int func_00119708(int);
extern int func_003A6DA0(char*, char*);
int func_00369050(F369* f, char* name, int mode) {
    int i, r;
    f->f28 = mode;
    f->fc4 = 0;
    f->f3c = 0;
    f->f2c = 0;
    sprintf(f->path, "\\%s;1", name);
    for (i = 0; f->path[i]; i++) f->path[i] = func_0012B290(f->path[i]);
    i = 0;
    r = 0;
    while (i++ < 0xFF && r != 2) r = func_00119708(0);
    f->f0 = func_003A6DA0(f->f4, f->path);
    f->f2c = f->f8;
    if (!f->f0) f->f0 = -1;
    if (f->f0 < 0) {
        f->f2c = 0;
        return 0;
    }
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00369050 */

/* merge_units: begin func_00369160 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; int a30; int a34; int a38; } S369160;
char D_004BBDE8[] = "CD Timeout";
char D_004BBDF8[] __attribute__((aligned(8))) = "%s\n"; /* 8-aligned in the original data */
char D_004BBE00[] = "CD ERROR: 0%x";
extern int func_003A6ED0(void);
extern void func_003A6F10(void);
extern int sprintf(char* buf, const char* fmt, ...);
extern void printf(char* tag, char* msg);
int func_00369160(S369160* o)
{
    char msg2[128];
    char msg1[128];
    int r = 1;
    int err = func_003A6ED0();
    int busy = func_003A6F70(r);
    o->a34 = g_FrameCounter;
    if (busy) {
        if (g_FrameCounter - o->a30 > o->a38) {
            sprintf(msg2, D_004BBDE8);
            printf(D_004BBDF8, msg2);
            r = -1;
        } else {
            r = 0;
        }
    } else if (err) {
        sprintf(msg1, D_004BBE00, err);
        printf(D_004BBDF8, msg1);
        r = -1;
    }
    if (r == -1) {
        func_003A6F10();
        func_003A6F70(0);
    }
    if (r) D_00533860 = 0;
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_00369160 */

/* merge_units: begin func_00369270 */
#pragma push /* merge_units */
#pragma inline_depth(8)
#pragma opt_propagation off
#pragma cplusplus on
#include "alloc_guard.h"
typedef struct {
    char pad0[0x28];
    int unk28;
    int unk2C;
    char pad30[0xC];
    int unk3C;
    unsigned char unk40;
    char pad41[0x83];
    void* unkC4;
} Strm369270;
extern "C" {
void* Mem_Alloc(int, int, char*, int);
void Mem_Free(int, void*, char*, int);
#if 0 /* merge_units */
int func_00368F60(Strm369270*, int);
#endif /* merge_units */
#define func_00368F60(a0, a1) (func_00368F60((S368F60 *)(a0), (a1))) /* merge_units */

extern char D_004BBDD0[];
}

static inline void Copy_369270(void* d0, void* s0, int n0)
{
    int n = n0;
    __int128 u;
    int t;
    void* d = d0;
    void* s = s0;
    asm {
        .set noreorder
        blez n, done
        andi t, s, 0xF
        andi u, d, 0xF
        or t, t, u
        andi u, n, 0xF
        or t, t, u
        nop
        bgtz t, bytes
    quads:
        lq u, 0(s)
        addiu d, d, 0x10
        addi n, n, -0x10
        addiu s, s, 0x10
        bgtz n, quads
        sq u, -0x10(d)
        b done
        nop
    bytes:
        lb u, 0(s)
        addiu d, d, 1
        addi n, n, -1
        addiu s, s, 1
        bgtz n, bytes
        sb u, -1(d)
        .set reorder
    done:
    }
}

static inline int RoundUp_369270(int n)
{
    if (n % 2048 == 0)
        return n;
    n = (n / 2048) * 2048 + 0x800;
    asm { .set reorder }
    return n;
}

static inline int Read_369270(Strm369270* o, void* dst, int size, int arg3)
{
    int ret = 0;
    int r;
    if (!o->unk2C)
        return ret;
    r = RoundUp_369270(size);
    if (size < r && o->unk28 != 0x8000) {
        void* p;
        o->unk3C = r;
        {
            int n = o->unk3C;
            AllocGuard g;
            p = Mem_Alloc(0, n, D_004BBDD0, 0xAA);
        }
        o->unkC4 = p;
        ret = func_00368F60(o, arg3);
        if (ret) {
            Copy_369270(dst, o->unkC4, size);
            ret = size;
        }
        {
            void* q = o->unkC4;
            AllocGuard g;
            Mem_Free(0, q, D_004BBDD0, 0xB3);
        }
        o->unk3C = 0;
    } else {
        o->unk3C = size;
        o->unkC4 = dst;
        ret = func_00368F60(o, arg3);
    }
    return ret;
}

extern "C" int func_00369270(Strm369270* o, void* dst, int size, int arg3)
{
    int ret = Read_369270(o, dst, size, arg3);
    o->unk40 = 0;
    return ret;
}
#undef func_00368F60 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00369270 */

/* merge_units: begin func_003694D0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Allocate the stream buffer (size rounded up to a 2 KB multiple) and start it. */
extern "C" {
#if 0 /* merge_units */
void* Mem_Alloc(int pool, int size, char* file, int line);
#endif /* merge_units */
#define Mem_Alloc(a0, a1, a2, a3) (Mem_Alloc((a0), (a1), (a2), (a3))) /* merge_units */

}
struct S3694D0 { char pad[0x2C]; int size; char pad30[0xC]; int cap; unsigned char active; char pad41[0x83]; void* buf; };
extern "C" {
#if 0 /* merge_units */
int func_00368F60(S3694D0* o, int a);
#endif /* merge_units */
#define func_00368F60(a0, a1) (func_00368F60((S368F60 *)(a0), (a1))) /* merge_units */

int func_003694D0(S3694D0* o);
}
int func_003694D0(S3694D0* o)
{
    void* p;
    int cap;
    if (o->size != 0) {
        o->cap = o->size / 2048 * 2048 + 2048;
        cap = o->cap;
        {
            AllocGuard guard;
            p = Mem_Alloc(0, cap, D_004BBDD0, 0x87);
        }
        o->buf = p;
        o->active = 1;
        return func_00368F60(o, 0);
    }
    return 0;
}
#undef Mem_Alloc /* merge_units */
#undef func_00368F60 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003694D0 */
