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
extern int FrontEnd_FindPopup(int, int);
extern char* Loc_LookupText(char*);
extern void String_CtorCStr_13B480(S465*, char*);
extern char* String_CStr(S465*);
extern int FrontEnd_OpenPopup(int, int, char*, char*, int, int);
extern void Game_SetPaused(char*, int);
extern void String_Dtor(S465*, int);
extern void FrontEnd_ClosePopup(int, int);
extern void func_00415950(W465*, float);
static inline int st465(X465* x) { return x->f1ec; }
void func_00465870(W465* w, float t) {
    if (w->flags & 4) {
        X465* x = &D_0055A300;
        int ok = D_0055A4EC == 0 || x->f1ec == 3;
        if (ok) D_00587B20++;
        else D_00587B20 = 0;
        if (D_00587B20 >= 3) {
            if (D_00497BE8 == -1 || !FrontEnd_FindPopup(D_004FFC04, D_00497BE8)) {
                S465 a;
                S465 b;
                String_CtorCStr_13B480(&a, Loc_LookupText("NoCtrlTitle"));
                String_CtorCStr_13B480(&b, Loc_LookupText("NoCtrlMessage"));
                {
                    char* tb = String_CStr(&b);
                    D_00497BE8 = FrontEnd_OpenPopup(D_004FFC04, 1, String_CStr(&a), tb, 0, 0);
                }
                Game_SetPaused(D_004FFB50, 1);
                String_Dtor(&b, 0);
                String_Dtor(&a, 0);
            }
        } else if (D_00497BE8 != -1) {
            FrontEnd_ClosePopup(D_004FFC04, D_00497BE8);
            D_00497BE8 = -1;
            if (!D_004FFC2C || !D_004FFC2C->b6a8) Game_SetPaused(D_004FFB50, 0);
        }
    }
    func_00415950(w, t);
}
