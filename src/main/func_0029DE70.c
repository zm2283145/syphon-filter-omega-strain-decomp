#include "types.h"
typedef struct { int a[4]; } S29D;
typedef struct { char pad[0x94]; unsigned char b94; } O29D;
extern int func_00414790(void);
extern void* func_00418A80(int, char*, char*);
extern int func_004147A0(void);
extern void func_00414AC0(int, O29D*, void*);
extern int func_004294C0(void);
extern void func_0044C3C0(int);
extern int D_004FFC04;
extern void func_002CA640(int, int);
extern char* func_0033CE30(O29D*, int, int, int, int, int);
extern void String_CtorCStr_13B480(S29D*, char*);
extern char* func_001692D0(S29D*);
extern void func_002CAE30(int, int, char*, char*, int, int);
extern void func_00138B70(S29D*, int);
void func_0029DE70(O29D* o, int show) {
    void* w = func_00418A80(func_00414790(), "GuiOnlineOfflineSelect", "ONOFFSEL");
    func_00414AC0(func_004147A0(), o, w);
    if (o->b94) {
        if (func_004294C0()) func_0044C3C0(func_004294C0());
        o->b94 = 0;
    }
    func_002CA640(D_004FFC04, 1);
    if (show) {
        S29D a;
        S29D b;
        String_CtorCStr_13B480(&a, func_0033CE30(o, 0xB, 0, 0, 0, 0));
        String_CtorCStr_13B480(&b, func_0033CE30(o, 0x84, 0, 0, 0, 0));
        {
            char* tb = func_001692D0(&b);
            func_002CAE30(D_004FFC04, 2, func_001692D0(&a), tb, 0, 0);
        }
        func_00138B70(&b, 0);
        func_00138B70(&a, 0);
    }
}
