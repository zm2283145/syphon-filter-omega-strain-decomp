#include "types.h"
typedef struct { __int128 a; __int128 b; } H2E_Pair;
typedef struct { __int128 slot0; __int128 slot1; __int128 q20; __int128 q30; H2E_Pair pairs[32]; } H2E_Pack;
typedef struct { char name[16]; } H2E_Name;
typedef struct { unsigned int count; H2E_Name e[24]; } H2E_Presets;
extern H2E_Presets D_00571300;
extern __int128 D_005609B0[];
extern __int128 D_005699B0[];
extern __int128 D_005716E0;
extern __int128* D_005712F8[];
extern int D_005712F0[];
extern char D_004BE950[];
extern char D_004BE960[];
extern void Appearance_RegistryKey(H2E_Pack* p, int n, char* name);
extern void String_Copy(void* d, char* s);
extern int func_004067E0(H2E_Pack* p);
/* inline-asm block copy (hand-written in the original) */
static inline void H2E_Copy(void* d0, void* s0, int n0)
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
/* inline-asm quad clear (hand-written in the original) */
static inline void H2E_QZero(void* dd, int nn)
{
    int n = nn; void* d = dd;
    asm {
        .set noreorder
    lp:
        nop
        addi n, n, -1
        sq $zero, 0(d)
        bgtz n, lp
        addiu d, d, 0x10
        .set reorder
    }
}
#pragma opt_propagation off
/* Decodes a packed manifest: each slot is a table index or -1 followed by 16 raw bytes. */
void func_00406EC0(H2E_Pack* dst, short* p)
{
    int n;
    int i;
    int c;
    char* raw;
    int c1;
    n = *p++;
    if (n <= 0 || n >= 0x20) n = 1;
    raw = (char*)(p + (n * 2 + 6));
    c = *p++;
    if (c == -1) {
        H2E_Copy(dst, raw, 0x10);
        raw += 0x10;
    } else {
        if ((unsigned int)c >= D_00571300.count) c = 0;
        Appearance_RegistryKey(dst, 0xF, D_00571300.e[c].name);
    }
    c1 = *p++;
    if (c1 == -1) {
        H2E_Copy(&dst->slot1, raw, 0x10);
        raw += 0x10;
    }
    c = *p++;
    if (c == -1) {
        H2E_Copy(&dst->q20, raw, 0x10);
        raw += 0x10;
    } else {
        dst->q20 = D_005609B0[c];
    }
    c = *p++;
    if (c == -1) {
        H2E_Copy(&dst->q30, raw, 0x10);
        raw += 0x10;
    } else {
        dst->q30 = D_005716E0;
        if (c == 1) String_Copy(&dst->q30, D_004BE950);
        else String_Copy(&dst->q30, D_004BE960);
    }
    for (i = 0; i <= n; i++) {
        c = *p++;
        if (c != -1) {
            dst->pairs[i].a = D_005609B0[c];
        } else {
            H2E_Copy(&dst->pairs[i].a, raw, 0x10);
            raw += 0x10;
        }
        c = *p++;
        if (c != -1) {
            dst->pairs[i].b = D_005699B0[c];
        } else {
            H2E_Copy(&dst->pairs[i].b, raw, 0x10);
            raw += 0x10;
        }
    }
    H2E_QZero(&dst->pairs[i], 2);
    if (c1 != -1) {
        int k = func_004067E0(dst);
        __int128* tbl = D_005712F8[k];
        if (c1 >= D_005712F0[k]) c1 = 0;
        dst->slot1 = tbl[c1];
    }
}
