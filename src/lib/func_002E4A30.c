typedef struct { char pad[0x400]; int f400; char p404[0x34]; int f438; char p43C[8]; int f444; } Obj2E4A30;
typedef struct { char pad[0x28]; unsigned char f28; } Ent2E4A30;
extern int D_0048C450;
extern unsigned char D_0048C454;
extern int D_0048C458;
extern unsigned int D_0048C45C;
extern int D_0048C498;
extern unsigned int D_0058806C;
extern void func_00306018(int *t);
extern int func_002E6010(void);
extern int func_002E47B0(int a);
extern int func_002E51B8(int a, Obj2E4A30 **out);
extern int func_002E52D8(int a, int i, Ent2E4A30 **out);
extern void func_002E1D50(int i);
extern void func_002E4550(void);
extern void func_002E4228(void);
extern int func_002E55A0(void);
extern int func_002E5860(int a);
extern int func_002E5D68(void);
extern int func_002E9200(void);
extern int func_002E5ED8(void);
int func_002E4A30(void)
{
    int t0;
    int t1;
    Obj2E4A30 *obj;
    Ent2E4A30 *ent;
    int i;
    if (!D_0048C458)
        return 0x11;
    func_00306018(&t0);
    { int e = func_002E6010(); if (e) return e; }
    { int e = func_002E47B0(1); if (e) return e; }
    func_00306018(&t1);
    D_0058806C += t1 - D_0048C498;
    D_0048C498 = t1;
    if (D_0048C450 < 4) {
        obj = 0;
        ent = 0;
        { int e = func_002E51B8(D_0048C450, &obj); if (e) return e; }
        if (!obj)
            return 0;
        if (D_0048C45C + 3000 < D_0058806C) {
            if (obj->f438 != 1)
                goto tail;
            if (obj->f400 < obj->f444) {
                for (i = 0; i < obj->f444; i++) {
                    { int e = func_002E52D8(D_0048C450, i, &ent); if (e) return e; }
                    if (ent && i != obj->f400 && ent->f28 == 1)
                        func_002E1D50(i);
                }
                D_0048C45C = D_0058806C;
            }
        }
        if (obj->f438 == 1 && obj->f400 < obj->f444 && D_0048C454 == 1) {
            func_002E4550();
            func_002E4228();
        }
    }
tail:
    { int e = func_002E55A0(); if (e) return e; }
    { int e = func_002E5860(1); if (e) return e; }
    { int e = func_002E5D68(); if (e) return e; }
    { int e = func_002E9200(); if (e) return e; }
    return func_002E5ED8();
}


