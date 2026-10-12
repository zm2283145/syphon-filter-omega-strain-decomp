typedef struct { int f0; unsigned short f4; unsigned short f6; } Msg8C50;
typedef struct { char pad0[6]; unsigned short f6; char pad8[2]; unsigned short fA; } Obj8C50;
extern int D_005983FC;
extern int D_00598424;
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
