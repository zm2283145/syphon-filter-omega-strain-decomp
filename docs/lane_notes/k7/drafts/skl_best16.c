
#include "types.h"
typedef struct { __int128 a; __int128 b; } H2E_Pair;
typedef struct { __int128 slot0; __int128 slot1; __int128 q20; __int128 q30; H2E_Pair pairs[32]; } H2E_Pack;
typedef struct { char name[16]; } H2E_Name;
typedef struct { short n; short v[1]; } H2E_Hdr;
typedef struct { unsigned int count; H2E_Name e[24]; } H2E_Presets;
extern H2E_Presets D_00571300;
extern __int128 D_005609B0[];
extern __int128 D_005699B0[];
extern __int128 D_0055DE20;
extern unsigned int D_0055DE60;
extern unsigned int D_0055DE68;
extern unsigned int D_0055DE6C;
extern unsigned int D_0055DE70;
extern __int128* D_005712F8[];
extern int D_005712F0[];
extern char D_004BE950[];
extern char D_004BE960[];
extern int strcmp(const void* a, const void* b);
extern int Libc_Strncmp(void* a, char* b, int n);
extern int SKL_FindSex(H2E_Pack* p);
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
static inline __int128 PAnd(__int128 a, __int128 b) { __int128 r; asm { pand r, a, b } return r; }
static inline int PEq(__int128 a, __int128 b) { long long r; asm { pceqw a, a, b
        ppach r, a, a } return r == -1; }
static inline int PEq1(__int128 a, __int128 b) { long long r; long long m1 = -1; asm { pceqw a, a, b
        ppach r, a, a } return r == m1; }
static inline int FindBoneScale(char* s)
{
    unsigned int i;
    for (i = 0; i < D_00571300.count; i++)
        if (strcmp(s, D_00571300.e[i].name) == 0) return i;
    return -1;
}
static inline int FindFace(int sex, char* s)
{
    __int128* tbl = D_005712F8[sex];
    int n = D_005712F0[sex];
    int i;
    for (i = 0; i < n; tbl++, i++)
        if (strcmp(tbl, s) == 0) return i;
    return -1;
}
static inline int FindPart(__int128 v)
{
    unsigned int i;
    __int128 m = D_0055DE20;
    __int128 k = PAnd(m, v);
    for (i = 0; i < D_0055DE60; i++)
        if (PEq(PAnd(m, D_005609B0[i]), k)) return i;
    return -1;
}
static inline int FindPart1(__int128 v)
{
    unsigned int i = 0;
    __int128 m = D_0055DE20;
    __int128 k = PAnd(m, v);
    __int128* t = D_005609B0;
    for (; i < D_0055DE60; i++)
        if (PEq1(PAnd(m, t[i]), k)) return i;
    return -1;
}
static inline int FindTex(__int128 v)
{
    unsigned int i;
    for (i = 0; i < D_0055DE6C; i++)
        if (PEq(v, D_005699B0[i])) return i;
    return -1;
}
static inline int Valid(int p, unsigned int n)
{
    if ((unsigned int)p < n) return p;
    return -1;
}
static inline int ValidR(int p, unsigned int n) { int r; if ((unsigned int)p < n) r = p; else r = -1; return r; }
#pragma opt_propagation off
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
#pragma opt_lifetimes off
char* SKL_CompressSKL(H2E_Pack* skl, int* dataSize)
{
    char* SPAD = (char*)0x70000000;
    short* data = (short*)SPAD;
    int count;
    int part;
    int sex;
    int i;
    short* data2;
    char* dataEnd;
    sex = SKL_FindSex(skl);
    for (count = 0; (long long)*(__int128*)((count << 5) + (int)skl + 0x40) != 0; count++) ;
    *data++ = count;
    part = FindBoneScale((char*)&skl->slot0);
    *data++ = part;
    part = FindFace(sex, (char*)&skl->slot1);
    *data++ = part;
    part = FindPart1(skl->q20);
    if ((unsigned int)part < D_0055DE68) { asm { nop } } else part = -1;
    *data++ = part;
    part = -1;
    if (Libc_Strncmp(&skl->q30, D_004BE950, 9) == 0) part = 1;
    else if (Libc_Strncmp(&skl->q30, D_004BE960, 0xB) == 0) part = 0;
    *data++ = part;
    for (i = 0; i <= count; i++) {
        part = FindPart(*(__int128*)((i << 5) + (int)skl + 0x40));
        if ((unsigned int)part < D_0055DE68) { asm { nop } } else part = -1;
        *data++ = part;
        part = FindTex(((H2E_Pair*)(((unsigned int)i << 5) + (int)skl + 0x40))->b);
        if ((unsigned int)part < D_0055DE70) { asm { nop } } else part = -1;
        *data++ = part;
    }
    dataEnd = (char*)data;
    for (data2 = (short*)0x70000000, data2++; data2 < data; data2++, skl = (H2E_Pack*)((char*)skl + 0x10)) {
        if (*data2 == -1) {
            H2E_Copy(dataEnd, skl, 0x10);
            dataEnd += 0x10;
        }
    }
    *dataSize = dataEnd - SPAD;
    return SPAD;
}