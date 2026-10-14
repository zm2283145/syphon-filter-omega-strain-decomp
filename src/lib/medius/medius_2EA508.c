/*
 * lib/medius: 65 files, 002EA508-002ECF08
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002EA508 */
extern unsigned char D_0048C4D7, D_0048C4DC;
extern char D_005253F0[];
extern int RecursiveLock_Acquire(void *, int);
extern int RecursiveLock_Release(void *, int);
extern int func_002DF680(void *, void *);
int func_002EA508(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DF680(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EA508 */

/* merge_units: begin func_002EA5B0 */
extern int func_002E0098(void *);
int func_002EA5B0(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E0098(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EA5B0 */

/* merge_units: begin func_002EA648 */
extern int func_002E0118(void *, void *);
int func_002EA648(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E0118(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EA648 */

/* merge_units: begin func_002EA6F0 */
extern int func_002E0BE0(void *);
int func_002EA6F0(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E0BE0(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EA6F0 */

/* merge_units: begin func_002EA788 */
extern int NetSession_InitLocal(void *, void *);
int NetGame_Create(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = NetSession_InitLocal(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EA788 */

/* merge_units: begin func_002EA830 */
extern int func_002E0F00(void *);
int func_002EA830(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E0F00(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EA830 */

/* merge_units: begin func_002EA8C8 */
extern int func_002E0F50(void *);
int func_002EA8C8(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E0F50(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EA8C8 */

/* merge_units: begin func_002EA960 */
extern int func_002E0F90(void *, void *);
int func_002EA960(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E0F90(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EA960 */

/* merge_units: begin func_002EAA08 */
extern int func_002E1118(void *);
int func_002EAA08(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E1118(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EAA08 */

/* merge_units: begin func_002EAAA0 */
extern int func_002E1158(void *, void *);
int func_002EAAA0(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E1158(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EAAA0 */

/* merge_units: begin func_002EAB48 */
extern int func_002E1470(void *, void *);
int func_002EAB48(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E1470(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EAB48 */

/* merge_units: begin func_002EABF0 */
extern int func_002E1500(void *);
int func_002EABF0(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E1500(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EABF0 */

/* merge_units: begin func_002EAC88 */
extern int func_002E1578(void *, void *);
int func_002EAC88(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E1578(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EAC88 */

/* merge_units: begin func_002EAD30 */
extern int func_002DF828(void *);
int func_002EAD30(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DF828(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EAD30 */

/* merge_units: begin func_002EADC8 */
extern int func_002E1EA8(void *, void *, void *);
int func_002EADC8(void *a, void *b, void *c)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E1EA8(a, b, c);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EADC8 */

/* merge_units: begin func_002EAE80 */
extern int func_002E2090(void *, void *);
int func_002EAE80(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E2090(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EAE80 */

/* merge_units: begin func_002EAF28 */
extern int func_002E2480(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
int func_002EAF28(void *a, void *b, void *c, void *d, void *e, void *f, void *g, void *h, void *i, void *j)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E2480(a, b, c, d, e, f, g, h, i, j);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EAF28 */

/* merge_units: begin func_002EB038 */
extern int func_002E2250(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
int func_002EB038(void *a, void *b, void *c, void *d, void *e, void *f, void *g, void *h, void *i, void *j, void *k)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E2250(a, b, c, d, e, f, g, h, i, j, k);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB038 */

/* merge_units: begin func_002EB150 */
extern int func_002E2878(void *, void *, void *, void *, void *, void *, void *, unsigned short, unsigned short);
int func_002EB150(void *a, void *b, void *c, void *d, void *e, void *f, void *g, unsigned short h, unsigned short i)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E2878(a, b, c, d, e, f, g, h, i);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB150 */

/* merge_units: begin func_002EB260 */
extern int func_002E3718(void *, void *, void *);
int func_002EB260(void *a, void *b, void *c)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E3718(a, b, c);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB260 */

/* merge_units: begin func_002EB318 */
extern int func_002E2B18(void *);
int func_002EB318(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E2B18(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB318 */

/* merge_units: begin func_002EB3B0 */
extern int func_002E3340(void *, void *);
int func_002EB3B0(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E3340(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB3B0 */

/* merge_units: begin func_002EB458 */
extern int func_002DB550(void *, void *);
int func_002EB458(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DB550(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB458 */

/* merge_units: begin func_002EB500 */
extern int func_002DD380(void *, void *);
int func_002EB500(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DD380(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB500 */

/* merge_units: begin func_002EB5A8 */
extern int func_002DD440(void *, void *);
int func_002EB5A8(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DD440(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB5A8 */

/* merge_units: begin func_002EB650 */
extern int func_002DD968(void *, void *);
int func_002EB650(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DD968(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB650 */

/* merge_units: begin func_002EB6F8 */
extern int func_002DD9B0(void *, void *);
int func_002EB6F8(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DD9B0(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB6F8 */

/* merge_units: begin func_002EB7A0 */
extern int func_002DB1F0(void *, void *, void *);
int func_002EB7A0(void *a, void *b, void *c)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DB1F0(a, b, c);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB7A0 */

/* merge_units: begin func_002EB858 */
extern int func_002DB188(void *, void *, void *);
int func_002EB858(void *a, void *b, void *c)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DB188(a, b, c);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB858 */

/* merge_units: begin func_002EB910 */
extern int func_002DD488(void *);
int func_002EB910(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DD488(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB910 */

/* merge_units: begin func_002EB9A8 */
extern int func_002DD4E8(void *, void *, void *);
int func_002EB9A8(void *a, void *b, void *c)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DD4E8(a, b, c);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB9A8 */

/* merge_units: begin func_002EBA60 */
extern int func_002DD938(void *);
int func_002EBA60(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DD938(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EBA60 */

/* merge_units: begin func_002EBAF8 */
extern int func_002DD178(void *, void *);
int NetGame_InitLocalSlot(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DD178(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EBAF8 */

/* merge_units: begin func_002EBBA0 */
extern int func_002DD1F8(void *, void *);
int func_002EBBA0(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DD1F8(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EBBA0 */

/* merge_units: begin func_002EBC48 */
extern int func_002DDAC8(void *);
int func_002EBC48(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DDAC8(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EBC48 */

/* merge_units: begin func_002EBCE0 */
extern int func_002DDB08(void *);
int func_002EBCE0(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DDB08(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EBCE0 */

/* merge_units: begin func_002EBD78 */
extern int func_002DDB30(void *, void *);
int func_002EBD78(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DDB30(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EBD78 */

/* merge_units: begin func_002EBE20 */
extern int func_002DDB98(void *, void *);
int func_002EBE20(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DDB98(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EBE20 */

/* merge_units: begin func_002EBEC8 */
extern int func_002DDC00(void *, void *);
int func_002EBEC8(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DDC00(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EBEC8 */

/* merge_units: begin func_002EBF70 */
extern int func_002DDCA0(void *, void *);
int func_002EBF70(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DDCA0(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EBF70 */

/* merge_units: begin func_002EC018 */
extern int func_002E4190(void *, void *);
int func_002EC018(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E4190(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC018 */

/* merge_units: begin func_002EC0C0 */
extern int func_002DDD50(void *, void *);
int func_002EC0C0(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DDD50(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC0C0 */

/* merge_units: begin func_002EC168 */
extern int func_002DCD30(void *, void *);
int func_002EC168(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DCD30(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC168 */

/* merge_units: begin func_002EC210 */
extern int func_002DB820(void *);
int func_002EC210(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DB820(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC210 */

/* merge_units: begin func_002EC2A8 */
extern int func_002DEC60(void *);
int func_002EC2A8(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DEC60(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC2A8 */

/* merge_units: begin func_002EC340 */
extern int func_002DF8E8(void);
int func_002EC340(void)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002DF8E8();
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC340 */

/* merge_units: begin func_002EC3C8 */
extern int func_002E2BB8(void *);
int func_002EC3C8(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E2BB8(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC3C8 */

/* merge_units: begin func_002EC460 */
extern int func_002E2CE0(void *);
int func_002EC460(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E2CE0(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC460 */

/* merge_units: begin func_002EC4F8 */
extern int func_002E4A30(void);
int func_002EC4F8(void)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E4A30();
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC4F8 */

/* merge_units: begin func_002EC580 */
extern int func_002E4C48(void *);
int func_002EC580(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E4C48(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC580 */

/* merge_units: begin func_002EC618 */
extern int func_002E4A00(void);
int func_002EC618(void)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E4A00();
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC618 */

/* merge_units: begin func_002EC6A0 */
extern int func_002E1A20(void *);
int func_002EC6A0(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E1A20(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC6A0 */

/* merge_units: begin func_002EC738 */
extern int func_002E4CA8(void *);
int func_002EC738(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E4CA8(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC738 */

/* merge_units: begin func_002EC7D0 */
extern int func_00313DB8(void *, void *);
int func_002EC7D0(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_00313DB8(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC7D0 */

/* merge_units: begin func_002EC878 */
extern int func_00313E70(void *, void *);
int func_002EC878(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_00313E70(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC878 */

/* merge_units: begin func_002EC920 */
extern int func_00313F18(void *, void *, void *);
int func_002EC920(void *a, void *b, void *c)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_00313F18(a, b, c);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC920 */

/* merge_units: begin func_002EC9D8 */
extern int func_00314028(void *, void *, void *);
int func_002EC9D8(void *a, void *b, void *c)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_00314028(a, b, c);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC9D8 */

/* merge_units: begin func_002ECA90 */
extern int func_00314180(void *, void *);
int func_002ECA90(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_00314180(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002ECA90 */

/* merge_units: begin func_002ECB38 */
extern int func_00314208(void *, void *);
int func_002ECB38(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_00314208(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002ECB38 */

/* merge_units: begin func_002ECBE0 */
extern void *memset(void *, int, unsigned int);
int func_002ECBE0(int *p)
{
    int r;
    unsigned char v;
    if (D_0048C4D7 != 1) return 0x11;
    v = D_0048C4DC;
    if (v != D_0048C4D7) return 0x2B;
    if (p == 0) return 0x17;
    r = RecursiveLock_Acquire(D_005253F0, 0);
    if (r) return 0x2B;
    memset(p, 0, 0x10);
    *p = v;
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002ECBE0 */

/* merge_units: begin func_002ECC98 */
extern int func_003142A0(void *);
int func_002ECC98(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_003142A0(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002ECC98 */

/* merge_units: begin func_002ECD30 */
extern int func_002E66F0(void *);
int func_002ECD30(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E66F0(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002ECD30 */

/* merge_units: begin func_002ECDC8 */
extern int func_002E6708(void *, void *);
int func_002ECDC8(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E6708(a, b);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002ECDC8 */

/* merge_units: begin func_002ECE70 */
extern int func_002E67E8(void *);
int func_002ECE70(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E67E8(a);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002ECE70 */

/* merge_units: begin func_002ECF08 */
extern int func_002E6808(void *, void *, void *, void *, void *, void *);
int func_002ECF08(void *a, void *b, void *c, void *d, void *e, void *f)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (RecursiveLock_Acquire(D_005253F0, 0)) return 0x2B;
    r = func_002E6808(a, b, c, d, e, f);
    if (RecursiveLock_Release(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002ECF08 */
