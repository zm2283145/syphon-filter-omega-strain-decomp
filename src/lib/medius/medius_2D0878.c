/*
 * lib/medius: 12 files, 002D0878-002D0EB8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D0878 */
extern short D_0048C414;
extern int D_0048C3D8;
extern int func_002D0EB8(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);extern int D_0048C3A0;
int func_002D0878(char *a)
{
    func_002D0EB8(a, 0x15);
    return Net_SendLocked(0x40, D_0048C3D8, 0xFFFF, 3, D_0048C3A0, 0x1C, a) ? -5 : 0;
}
/* merge_units: end func_002D0878 */

/* merge_units: begin func_002D08D8 */
extern int D_0048C3A8;
int func_002D08D8(char *a)
{
    func_002D0EB8(a, 0x15);
    func_002D0EB8(a + 0x16, 0x11);
    if (D_0048C414 != 1) return -0xC;
    return Net_SendLocked(0x40, D_0048C3D8, 0xFFFF, 3, D_0048C3A8, 0x68, a) ? -5 : 0;
}
/* merge_units: end func_002D08D8 */

/* merge_units: begin func_002D0958 */
extern int D_0048C3B0;
int func_002D0958(char *a)
{
    func_002D0EB8(a, 0x15);
    return Net_SendLocked(0x40, D_0048C3D8, 0xFFFF, 3, D_0048C3B0, 0x16, a) ? -5 : 0;
}
/* merge_units: end func_002D0958 */

/* merge_units: begin func_002D09B8 */
int D_0048C3B8 = 0;
int func_002D09B8(char *a)
{
    func_002D0EB8(a, 0x15);
    if (*(int *)(a + 0x20) < 0) return -0xC;
    if (D_0048C414 != 1) return -0xC;
    return Net_SendLocked(0x40, D_0048C3D8, 0xFFFF, 3, D_0048C3B8, 0x28, a) ? -5 : 0;
}
/* merge_units: end func_002D09B8 */

/* merge_units: begin func_002D0A38 */
typedef struct { char pad[0x19C]; int f19C; int f1A0; char pad1a4[0x14]; int f1B8; } Msg_0A38;
extern int D_0048C3BC;
extern int D_0048C3F8;
#if 0 /* merge_units */
extern int func_002D0EB8(void *, int);
#endif /* merge_units */
#define func_002D0EB8(a0, a1) (func_002D0EB8((char *)(a0), (a1))) /* merge_units */

extern int func_002CEBC0(void);
extern void func_002CE840(int *);
int func_002D0A38(Msg_0A38 *a, int b)
{
    int r;
    func_002D0EB8(a, 0x15);
    func_002D0EB8((char *)a + 0x15, 0x40);
    func_002D0EB8((char *)a + 0x155, 0x20);
    func_002D0EB8((char *)a + 0x55, 0x100);
    a->f19C = func_002CEBC0();
    if (D_0048C414 != 1) return -0xC;
    if (func_002CEBC0() == 1 || func_002CEBC0() == 2) {
        func_002CE840(&a->f1A0);
    } else if (func_002CEBC0() == 0 || func_002CEBC0() == 4) {
        a->f1A0 = 0;
        a->f1B8 = 0;
    } else {
        return -0xD;
    }
    r = Net_SendLocked(0x40, D_0048C3D8, 0xFFFF, 3, D_0048C3BC, 0x1D4, a);
    D_0048C3F8 = b;
    return r ? -5 : 0;
}
#undef func_002D0EB8 /* merge_units */
/* merge_units: end func_002D0A38 */

/* merge_units: begin func_002D0B58 */
extern int D_0048C3C4;
extern int D_0048C3FC;
int func_002D0B58(char *a, int b)
{
    int r;
    func_002D0EB8(a, 0x15);
    if (D_0048C414 != 1) return -0xC;
    r = Net_SendLocked(0x40, D_0048C3D8, 0xFFFF, 3, D_0048C3C4, 0x1C, a);
    D_0048C3FC = b;
    return r ? -5 : 0;
}
/* merge_units: end func_002D0B58 */

/* merge_units: begin func_002D0BE0 */
extern int D_0048C3CC;
int func_002D0BE0(char *a)
{
    func_002D0EB8(a, 0x15);
    func_002D0EB8(a + 0x15, 0x40);
    func_002D0EB8(a + 0x155, 0x20);
    func_002D0EB8(a + 0x55, 0x100);
    if (D_0048C414 != 1) return -0xC;
    return Net_SendLocked(0x40, D_0048C3D8, 0xFFFF, 3, D_0048C3CC, 0x1A8, a) ? -5 : 0;
}
/* merge_units: end func_002D0BE0 */

/* merge_units: begin func_002D0C78 */
extern int D_0048C3D0;
extern int D_0048C400;
#if 0 /* merge_units */
extern void func_002CE840(char *);
#endif /* merge_units */
#define func_002CE840(a0) (func_002CE840((int *)(a0))) /* merge_units */

int func_002D0C78(char *a, int b)
{
    int r;
    func_002D0EB8(a, 0x15);
    if (*(int *)(a + 0x1C) < 0) return -0xD;
    if (D_0048C414 != 1) return -0xC;
    if (func_002CEBC0() == 1 || func_002CEBC0() == 2) {
        func_002CE840(a + 0x20);
    } else if (func_002CEBC0() == 0 || func_002CEBC0() == 4) {
        *(int *)(a + 0x20) = 0;
        *(int *)(a + 0x38) = 0;
    } else {
        return -0xD;
    }
    r = Net_SendLocked(0x40, D_0048C3D8, 0xFFFF, 3, D_0048C3D0, 0x50, a);
    D_0048C400 = b;
    return r ? -5 : 0;
}
#undef func_002CE840 /* merge_units */
/* merge_units: end func_002D0C78 */

/* merge_units: begin func_002D0D70 */
extern void *memset(void *, int, unsigned int);
int func_002D0D70(int *p)
{
    if (p == 0) return -0xD;
    memset(p, 0, 0xA0);
    p[0] = 0;
    p[0x27] = 0;
    return 0;
}
/* merge_units: end func_002D0D70 */

/* merge_units: begin func_002D0DB0 */
#include "types.h"
typedef struct { int a; int b; char name[0x10]; int x18; char pad[0x18]; int x34; char pad2[0x64]; int x9C; } Rec0DB0;
extern char* strncpy(char* d, const char* s, int n);
int func_002D0DB0(Rec0DB0* r, const char* name, int x18, int x34, int x9C)
{
    if (!r)
        return -13;
    r->a = 1;
    r->b = 1;
    strncpy(r->name, name, 0x14);
    r->x18 = x18;
    r->x34 = x34;
    if (x9C)
        r->x9C = x9C;
    return 0;
}
/* merge_units: end func_002D0DB0 */

/* merge_units: begin func_002D0E28 */
typedef void (*CB0E28)(int, int);
typedef struct { int f0; int f4; int f8; int fC; } A0E28;
extern char D_004AD480[];
extern void printf(char *, ...);
extern CB0E28 func_002CEBB0(void);
void func_002D0E28(A0E28 *a)
{
    int r;
    if (a->f4 == 1) {
        D_0048C3D8 = a->f0;
        r = 0;
    } else {
        D_0048C3D8 = a->f0;
        r = -2;
        printf(D_004AD480, a->fC, a->f8);
    }
    if (func_002CEBB0() != 0) func_002CEBB0()(D_0048C3D8, r);
}
/* merge_units: end func_002D0E28 */

/* merge_units: begin func_002D0EB8 */
int func_002D0EB8(char *s, int n)
{
    if (s == 0) return -1;
    if (n > 0) s[n - 1] = 0;
    else *s = 0;
    return 0;
}
/* merge_units: end func_002D0EB8 */
