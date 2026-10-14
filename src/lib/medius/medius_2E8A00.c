/*
 * lib/medius: 2 files, 002E8A00-002E8C50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002E8A00 */
extern int NetMsg_RegisterTypeInner(void *, int, void *);
extern int D_005983E8;
extern void func_002E6BC0(void);
extern int D_005983DC;
extern void func_002E7118(void);
extern int D_005983EC;
extern void func_002E7328(void);
extern int D_005983F0;
extern void func_002E7B60(void);
extern int D_005983F4;
extern void func_002E76D0(void);
extern int D_005983F8;
extern void func_002E80D0(void);
extern int D_005983FC;
extern void func_002E6F40(void);
extern int D_00598400;
extern void func_002E74C0(void);
extern int D_00598404;
extern void func_002E74E8(void);
extern int D_005983E0;
extern void func_002E7608(void);
extern int D_00598408;
extern void func_002E7670(void);
extern int D_0059840C;
extern void func_002E7DC8(void);
extern int D_00598410;
extern void func_002E6C78(void);
extern int D_00598414;
extern void func_002E6AA8(void);
extern int D_00598418;
extern void func_002E6C30(void);
extern int D_0059841C;
extern void func_002E6DC8(void);
extern int D_005983D8;
extern void func_002E6ED8(void);
extern int D_005983E4;
extern void func_002E8228(void);
extern int D_00598420;
extern void func_002E8338(void);
extern int D_00598424;
extern void func_002E85B8(void);
extern int D_00598428;
extern void func_002E86A8(void);

void func_002E8A00(void)
{
    int local;

    NetMsg_RegisterTypeInner(&D_005983E8, 0, func_002E6BC0);
    NetMsg_RegisterTypeInner(&D_005983DC, 0, func_002E7118);
    NetMsg_RegisterTypeInner(&D_005983EC, 0, func_002E7328);
    NetMsg_RegisterTypeInner(&D_005983F0, 0, func_002E7B60);
    NetMsg_RegisterTypeInner(&D_005983F4, 0, func_002E76D0);
    NetMsg_RegisterTypeInner(&D_005983F8, 0, func_002E80D0);
    NetMsg_RegisterTypeInner(&local, 0, 0);
    NetMsg_RegisterTypeInner(&local, 0, 0);
    NetMsg_RegisterTypeInner(&local, 0, 0);
    NetMsg_RegisterTypeInner(&D_005983FC, 0, func_002E6F40);
    NetMsg_RegisterTypeInner(&D_00598400, 0, func_002E74C0);
    NetMsg_RegisterTypeInner(&D_00598404, 0, func_002E74E8);
    NetMsg_RegisterTypeInner(&D_005983E0, 0, func_002E7608);
    NetMsg_RegisterTypeInner(&D_00598408, 0, func_002E7670);
    NetMsg_RegisterTypeInner(&D_0059840C, 0, func_002E7DC8);
    NetMsg_RegisterTypeInner(&D_00598410, 0, func_002E6C78);
    NetMsg_RegisterTypeInner(&D_00598414, 0, func_002E6AA8);
    NetMsg_RegisterTypeInner(&local, 0, 0);
    NetMsg_RegisterTypeInner(&D_00598418, 0, func_002E6C30);
    NetMsg_RegisterTypeInner(&D_0059841C, 0, func_002E6DC8);
    NetMsg_RegisterTypeInner(&D_005983D8, 0, func_002E6ED8);
    NetMsg_RegisterTypeInner(&D_005983E4, 0, func_002E8228);
    NetMsg_RegisterTypeInner(&D_00598420, 0, func_002E8338);
    NetMsg_RegisterTypeInner(&D_00598424, 0, func_002E85B8);
    NetMsg_RegisterTypeInner(&D_00598428, 0, func_002E86A8);
}
/* merge_units: end func_002E8A00 */

/* merge_units: begin func_002E8C50 */
typedef struct { int f0; unsigned short f4; unsigned short f6; } Msg8C50;
typedef struct { char pad0[6]; unsigned short f6; char pad8[2]; unsigned short fA; } Obj8C50;
extern int D_0058806C;
extern int func_002E6088(int);
extern int func_002DDB30(unsigned int*, unsigned int);
extern int func_002E51B8(unsigned int, char**);
extern int func_002E52D8(unsigned int, int, char**);
extern int func_002DB188(Obj8C50**, unsigned int, int);
extern Obj8C50* func_002DB270(unsigned int, int);
extern unsigned short func_002E68C0(int);
extern unsigned short func_002E69B8(int);
extern void func_002DE880(int, unsigned int, int, int, int, void*);
extern void func_002E8E40(unsigned int, int*);
extern void func_002E1D50(int);

void func_002E8C50(unsigned int a0, int a1, int a2, int a3)
{
    Msg8C50 msg;
    unsigned int sz;
    char* p1;
    char* p2;
    Obj8C50* o;
    int x;

    p1 = 0;
    p2 = 0;
    if (a0 >= 4) return;
    if (func_002E6088(a1) != 1) return;
    func_002DDB30(&sz, a0);
    if (sz == 0x100) return;
    if (sz >= 0x100) return;
    if (func_002E51B8(a0, &p1) != 0) return;
    if (p1 == 0) return;
    if (func_002E52D8(a0, a1, &p2) != 0) return;
    if (p2 == 0) return;
    if (*(unsigned int*)(p1 + 0x400) != sz) return;
    o = 0;
    func_002DB188(&o, a0, a1);
    if (o != 0) return;
    o = func_002DB270(a0, a1);
    if (o == 0) return;
    if (a2 != 0) o->f6 = func_002E68C0(a2);
    if (a3 != 0) o->fA = func_002E69B8(a3);
    msg.f0 = D_0058806C;
    msg.f4 = o->f6;
    msg.f6 = o->fA;
    func_002DE880(0x50, a0, a1, D_005983FC, 8, &msg);
    func_002E8E40(a0, &x);
    if (func_002E52D8(a0, a1, &p2) == 0 && p2 != 0) *(int*)(p2 + 0x24) = x;
    func_002DE880(0x50, a0, a1, D_00598424, 4, &x);
    func_002E1D50(a1);
    func_002E1D50(a1);
    func_002E1D50(a1);
}
/* merge_units: end func_002E8C50 */
