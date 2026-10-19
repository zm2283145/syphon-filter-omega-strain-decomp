/*
 * lib/medius: 9 files, 0046C0B0-0046C560
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0046C0B0 */
typedef struct { char pad[0x18]; int f18; } P;
extern short D_00497CC0;
extern int D_00497CC4;
extern int D_00497CE8;
extern int D_00497CEC;
extern int D_00497CE4;
extern int D_00497DE4;
int D_00497DF0 = 0;
extern int D_005988E0;
extern int Medius_TerminateString(P *, int);
extern int Net_SendLocked(int, int, int, int, int, int, P *);
int func_0046C0B0(P *p, int b, int c)
{
    Medius_TerminateString(p, 0x15);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497CE8 = 0;
    D_00497CE4 = p->f18;
    D_00497CEC = D_00497CC0;
    D_00497DE4 = b;
    D_00497DF0 = c;
    if (Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 4, D_005988E0, 0x24, p)) return -5;
    return 0;
}
/* merge_units: end func_0046C0B0 */

/* merge_units: begin func_0046C170 */
extern int D_005987CC;
int D_00497DF4 = 0;
#if 0 /* merge_units */
extern int Medius_TerminateString(char *, int);
#endif /* merge_units */
#define Medius_TerminateString(a0, a1) (Medius_TerminateString((P *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int Net_SendLocked(int, int, int, int, int, int, void *);
#endif /* merge_units */
#define Net_SendLocked(a0, a1, a2, a3, a4, a5, a6) (Net_SendLocked((a0), (a1), (a2), (a3), (a4), (a5), (P *)(a6))) /* merge_units */

int func_0046C170(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497DF4 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005987CC, 0x15, a) ? -5 : 0;
}
#undef Medius_TerminateString /* merge_units */
#undef Net_SendLocked /* merge_units */
/* merge_units: end func_0046C170 */

/* merge_units: begin func_0046C200 */
extern int D_005987D4;
unsigned int D_00497DF8[1] = { 0x0 };
#if 0 /* merge_units */
extern int Medius_TerminateString(char *, int);
#endif /* merge_units */
#define Medius_TerminateString(a0, a1) (Medius_TerminateString((P *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int Net_SendLocked(int, int, int, int, int, int, void *);
#endif /* merge_units */
#define Net_SendLocked(a0, a1, a2, a3, a4, a5, a6) (Net_SendLocked((a0), (a1), (a2), (a3), (a4), (a5), (P *)(a6))) /* merge_units */

int func_0046C200(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497DF8) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005987D4, 0x1C, a) ? -5 : 0;
}
#undef Medius_TerminateString /* merge_units */
#undef Net_SendLocked /* merge_units */
/* merge_units: end func_0046C200 */

/* merge_units: begin func_0046C290 */
extern int D_005987DC;
int D_00497DFC = 0;
#if 0 /* merge_units */
extern int Medius_TerminateString(char *, int);
#endif /* merge_units */
#define Medius_TerminateString(a0, a1) (Medius_TerminateString((P *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int Net_SendLocked(int, int, int, int, int, int, void *);
#endif /* merge_units */
#define Net_SendLocked(a0, a1, a2, a3, a4, a5, a6) (Net_SendLocked((a0), (a1), (a2), (a3), (a4), (a5), (P *)(a6))) /* merge_units */

int func_0046C290(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497DFC = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005987DC, 0x1C, a) ? -5 : 0;
}
#undef Medius_TerminateString /* merge_units */
#undef Net_SendLocked /* merge_units */
/* merge_units: end func_0046C290 */

/* merge_units: begin func_0046C320 */
extern int D_005987EC;
unsigned int D_00497E00[1] = { 0x0 };
#if 0 /* merge_units */
extern int Medius_TerminateString(char *, int);
#endif /* merge_units */
#define Medius_TerminateString(a0, a1) (Medius_TerminateString((P *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int Net_SendLocked(int, int, int, int, int, int, void *);
#endif /* merge_units */
#define Net_SendLocked(a0, a1, a2, a3, a4, a5, a6) (Net_SendLocked((a0), (a1), (a2), (a3), (a4), (a5), (P *)(a6))) /* merge_units */

int func_0046C320(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497E00) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005987EC, 0x1A, a) ? -5 : 0;
}
#undef Medius_TerminateString /* merge_units */
#undef Net_SendLocked /* merge_units */
/* merge_units: end func_0046C320 */

/* merge_units: begin func_0046C3B0 */
extern int D_005987F4;
int D_00497E04 = 0;
#if 0 /* merge_units */
extern int Medius_TerminateString(char *, int);
#endif /* merge_units */
#define Medius_TerminateString(a0, a1) (Medius_TerminateString((P *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int Net_SendLocked(int, int, int, int, int, int, void *);
#endif /* merge_units */
#define Net_SendLocked(a0, a1, a2, a3, a4, a5, a6) (Net_SendLocked((a0), (a1), (a2), (a3), (a4), (a5), (P *)(a6))) /* merge_units */

int func_0046C3B0(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497E04 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005987F4, 0x1A, a) ? -5 : 0;
}
#undef Medius_TerminateString /* merge_units */
#undef Net_SendLocked /* merge_units */
/* merge_units: end func_0046C3B0 */

/* merge_units: begin func_0046C440 */
extern int D_00598800;
unsigned int D_00497E08[1] = { 0x0 };
#if 0 /* merge_units */
extern int Medius_TerminateString(char *, int);
#endif /* merge_units */
#define Medius_TerminateString(a0, a1) (Medius_TerminateString((P *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int Net_SendLocked(int, int, int, int, int, int, void *);
#endif /* merge_units */
#define Net_SendLocked(a0, a1, a2, a3, a4, a5, a6) (Net_SendLocked((a0), (a1), (a2), (a3), (a4), (a5), (P *)(a6))) /* merge_units */

int func_0046C440(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497E08) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 0x4, D_00598800, 0x28, a) ? -5 : 0;
}
#undef Medius_TerminateString /* merge_units */
#undef Net_SendLocked /* merge_units */
/* merge_units: end func_0046C440 */

/* merge_units: begin func_0046C4D0 */
extern int D_0059882C;
int D_00497E0C = 0;
#if 0 /* merge_units */
extern int Medius_TerminateString(char *, int);
#endif /* merge_units */
#define Medius_TerminateString(a0, a1) (Medius_TerminateString((P *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int Net_SendLocked(int, int, int, int, int, int, void *);
#endif /* merge_units */
#define Net_SendLocked(a0, a1, a2, a3, a4, a5, a6) (Net_SendLocked((a0), (a1), (a2), (a3), (a4), (a5), (P *)(a6))) /* merge_units */

int func_0046C4D0(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497E0C = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_0059882C, 0x24, a) ? -5 : 0;
}
#undef Medius_TerminateString /* merge_units */
#undef Net_SendLocked /* merge_units */
/* merge_units: end func_0046C4D0 */

/* merge_units: begin func_0046C560 */
extern int D_0059880C;
unsigned int D_00497E10[1] = { 0x0 };
#if 0 /* merge_units */
extern int Medius_TerminateString(char *, int);
#endif /* merge_units */
#define Medius_TerminateString(a0, a1) (Medius_TerminateString((P *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int Net_SendLocked(int, int, int, int, int, int, void *);
#endif /* merge_units */
#define Net_SendLocked(a0, a1, a2, a3, a4, a5, a6) (Net_SendLocked((a0), (a1), (a2), (a3), (a4), (a5), (P *)(a6))) /* merge_units */

int func_0046C560(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    (*(int*)D_00497E10) = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_0059880C, 0x58, a) ? -5 : 0;
}
#undef Medius_TerminateString /* merge_units */
#undef Net_SendLocked /* merge_units */
/* merge_units: end func_0046C560 */
