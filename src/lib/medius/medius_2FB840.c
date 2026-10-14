/*
 * lib/medius: 27 files, 002FB840-002FC928
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002FB840 */
extern unsigned char D_00490900;
extern short D_004908EE;
extern char D_005297F0[];
extern int RecursiveLock_Acquire(void *, int);
extern int RecursiveLock_Release(void *, int);
extern int func_00302218(void *);
extern int func_002FC7A0(void);
int func_002FB840(void)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FC7A0();
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    if (r == 0 && D_004908EE == 0) {
        if (func_00302218(D_005297F0)) return 0x1A;
        D_00490900 = 0;
    }
    return r;
}
/* merge_units: end func_002FB840 */

/* merge_units: begin func_002FB8F0 */
extern int func_002FC928(void);
int func_002FB8F0(void)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FC928();
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FB8F0 */

/* merge_units: begin func_002FB968 */
extern int func_002FC970(void *);
int func_002FB968(void *a)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FC970(a);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FB968 */

/* merge_units: begin func_002FB9F8 */
extern int NetSession_CreateSockets(void *, void *);
int func_002FB9F8(void *a, void *b)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = NetSession_CreateSockets(a, b);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FB9F8 */

/* merge_units: begin func_002FBA98 */
extern int func_002FCE88(unsigned short);
int func_002FBA98(unsigned short a)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FCE88(a);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FBA98 */

/* merge_units: begin func_002FBB28 */
extern int func_002FCFE8(void);
int func_002FBB28(void)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FCFE8();
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FBB28 */

/* merge_units: begin func_002FBBA0 */
extern int func_002FD088(unsigned short, unsigned char);
int func_002FBBA0(unsigned short a, unsigned char b)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FD088(a, b);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FBBA0 */

/* merge_units: begin func_002FBC40 */
extern int func_002FE168(void);
int func_002FBC40(void)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FE168();
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FBC40 */

/* merge_units: begin func_002FBCB8 */
extern int func_002FD0A8(unsigned char);
int func_002FBCB8(unsigned char a)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FD0A8(a);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FBCB8 */

/* merge_units: begin func_002FBD48 */
extern int func_002FD180(unsigned short, unsigned short, void *, void *, unsigned short);
int func_002FBD48(unsigned short a, unsigned short b, void *c, void *d, unsigned short e)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FD180(a, b, c, d, e);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FBD48 */

/* merge_units: begin func_002FBE18 */
extern int func_002FD280(unsigned short, unsigned short, unsigned short, void *, void *, void *, unsigned short);
int func_002FBE18(unsigned short a, unsigned short b, unsigned short c, void *d, void *e, void *f, unsigned short g)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FD280(a, b, c, d, e, f, g);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FBE18 */

/* merge_units: begin func_002FBF08 */
extern int func_002FD288(void *, void *, unsigned short);
int func_002FBF08(void *a, void *b, unsigned short c)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FD288(a, b, c);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FBF08 */

/* merge_units: begin func_002FBFB8 */
extern int func_002FD338(unsigned short, void *, void *, void *, void *);
int func_002FBFB8(unsigned short a, void *b, void *c, void *d, void *e)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FD338(a, b, c, d, e);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FBFB8 */

/* merge_units: begin func_002FC088 */
extern int func_002FD518(void *);
int func_002FC088(void *a)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FD518(a);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC088 */

/* merge_units: begin func_002FC118 */
extern int func_002FD560(void *);
int func_002FC118(void *a)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FD560(a);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC118 */

/* merge_units: begin func_002FC1A8 */
extern int func_002FD5A8(void *, void *);
int func_002FC1A8(void *a, void *b)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FD5A8(a, b);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC1A8 */

/* merge_units: begin func_002FC248 */
extern int func_002FD5F8(unsigned short, void *);
int func_002FC248(unsigned short a, void *b)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FD5F8(a, b);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC248 */

/* merge_units: begin func_002FC2E8 */
extern int func_002FD670(unsigned short, unsigned char);
int func_002FC2E8(unsigned short a, unsigned char b)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FD670(a, b);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC2E8 */

/* merge_units: begin func_002FC388 */
extern int func_002FD718(void *, void *);
int func_002FC388(void *a, void *b)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FD718(a, b);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC388 */

/* merge_units: begin func_002FC428 */
extern int func_002FD7D8(unsigned short, void *);
int func_002FC428(unsigned short a, void *b)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FD7D8(a, b);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC428 */

/* merge_units: begin func_002FC4C8 */
extern int func_002FD860(unsigned short, void *);
int func_002FC4C8(unsigned short a, void *b)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FD860(a, b);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC4C8 */

/* merge_units: begin func_002FC568 */
extern int func_002FD8F0(void *);
int func_002FC568(void *a)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FD8F0(a);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC568 */

/* merge_units: begin func_002FC5F8 */
extern int func_002FD968(void *);
int func_002FC5F8(void *a)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FD968(a);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC5F8 */

/* merge_units: begin func_002FC688 */
extern int func_002FD980(void);
int func_002FC688(void)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FD980();
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC688 */

/* merge_units: begin func_002FC700 */
extern int func_002FD9B8(unsigned short, void *);
int func_002FC700(unsigned short a, void *b)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = func_002FD9B8(a, b);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC700 */

/* merge_units: begin func_002FC7A0 */
extern unsigned char D_004908EC;
extern unsigned short D_004908F0;
extern int *D_004908F4;
extern int D_004908F8;
extern int D_004908FC;
extern unsigned char D_005297E0;
extern int func_002FE7C0(unsigned short);
extern int func_002FE5A8(unsigned short);
#if 0 /* merge_units */
extern void func_002FC928(void);
#endif /* merge_units */
#define func_002FC928() ((void)func_002FC928()) /* merge_units */

extern int func_002F5C10(void);
extern int func_003010C8(int);
extern int func_002FB3C0(void *);
extern void func_002F95F8(int);
int func_002FC7A0(void)
{
    unsigned short i = 0;
    int r;
    if (D_004908EE <= 0) return 5;
    if (D_004908EC != 1) return 5;
    if (D_004908EE == 1) {
        for (; i < D_004908F0; i++) {
            if (D_004908F4[i]) {
                if (func_002FE7C0(i) == 1) func_002FCE88(i);
                else func_002FE5A8(i);
            }
        }
        if (D_005297E0 == 1) func_002FC928();
        r = func_003010C8(func_002F5C10());
        if (r) return r;
        if (D_004908F4) func_002FB3C0(&D_004908F4);
        D_004908F4 = 0;
        D_004908F0 = 0;
        if (D_004908F8) {
            func_002FB3C0(&D_004908F8);
            D_004908FC = 0;
        }
        func_002F95F8(0);
        D_004908EC = 0;
    }
    D_004908EE--;
    return 0;
}
#undef func_002FC928 /* merge_units */
/* merge_units: end func_002FC7A0 */

/* merge_units: begin func_002FC928 */
typedef struct { unsigned char on; char pad[3]; int h; } S2FC928;
#if 0 /* merge_units */
extern S2FC928 D_005297E0;
#endif /* merge_units */
#define D_005297E0 (*(S2FC928*)&D_005297E0) /* merge_units */

extern void func_002F5DB0(int);
int func_002FC928(void)
{
    if (D_005297E0.on != 1) return 5;
    func_002F5DB0(D_005297E0.h);
    D_005297E0.on = 0;
    return 0;
}
#undef D_005297E0 /* merge_units */
/* merge_units: end func_002FC928 */
