#include "types.h"
typedef struct { int a[4]; } S465;
typedef struct { char pad[0x14]; unsigned short flags; } W465;
typedef struct { char pad[0x6A8]; unsigned char b6a8; } G465;
typedef struct { char pad[0x1EC]; int f1ec; } X465;
extern int D_0055A4EC;
extern X465 D_0055A300;
extern int D_00587B20;
extern int D_00497BE8;
extern int D_004FFC04;
extern G465* D_004FFC2C;
extern char D_004FFB50[];
extern int func_002CABA0(int, int);
extern char* Loc_LookupText(char*);
extern void String_CtorCStr_13B480(S465*, char*);
extern char* func_001692D0(S465*);
extern int func_002CAE30(int, int, char*, char*, int, int);
extern void func_00131470(char*, int);
extern void func_00138B70(S465*, int);
extern void func_002CAC80(int, int);
extern void func_00415950(W465*, float);
static inline int st465(X465* x) { return x->f1ec; }
void func_00465870(W465* w, float t) {
    if (w->flags & 4) {
        X465* x = &D_0055A300;
        int ok = D_0055A4EC == 0 || x->f1ec == 3;
        if (ok) D_00587B20++;
        else D_00587B20 = 0;
        if (D_00587B20 >= 3) {
            if (D_00497BE8 == -1 || !func_002CABA0(D_004FFC04, D_00497BE8)) {
                S465 a;
                S465 b;
                String_CtorCStr_13B480(&a, Loc_LookupText("NoCtrlTitle"));
                String_CtorCStr_13B480(&b, Loc_LookupText("NoCtrlMessage"));
                {
                    char* tb = func_001692D0(&b);
                    D_00497BE8 = func_002CAE30(D_004FFC04, 1, func_001692D0(&a), tb, 0, 0);
                }
                func_00131470(D_004FFB50, 1);
                func_00138B70(&b, 0);
                func_00138B70(&a, 0);
            }
        } else if (D_00497BE8 != -1) {
            func_002CAC80(D_004FFC04, D_00497BE8);
            D_00497BE8 = -1;
            if (!D_004FFC2C || !D_004FFC2C->b6a8) func_00131470(D_004FFB50, 0);
        }
    }
    func_00415950(w, t);
}
