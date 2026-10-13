#include "types.h"
typedef struct { char d[0x10]; } Str;
typedef struct { char pad[0x268]; int f268; } Ui;
typedef struct { char pad[0x98]; int f98; } S;
extern Ui* D_004FFC04;
extern char D_004AB808[];
extern int func_0033CE30(S* self, int a, int b, int c, int d, int e);
extern void FrontEnd_OpenPopup(void* ui, int a, char* b, int c, S* d, int e);
extern void String_CtorCStr_13B480(Str* s, int c);
extern int String_CStr(Str* s);
extern void func_00138B70(Str* s, int flags);
extern int func_0033C320(S* self, int v);
void func_002A96A0(S* self, int flag)
{
    if (flag && self->f98 == -1) {
        Str a;
        Str b;
        int t;
        String_CtorCStr_13B480(&a, func_0033CE30(self, 0x73, 0, 0, 0, 0));
        String_CtorCStr_13B480(&b, func_0033CE30(self, 0x74, 0, 0, 0, 0));
        t = String_CStr(&b);
        FrontEnd_OpenPopup(D_004FFC04, 2, (char*)String_CStr(&a), t, 0, 0);
        func_00138B70(&b, 0);
        func_00138B70(&a, 0);
    } else if (!func_0033C320(self, D_004FFC04->f268)) {
        Ui* ui = D_004FFC04;
        FrontEnd_OpenPopup(ui, 2, D_004AB808, func_0033CE30(self, 0x71, 0, 0, 0, 0), 0, 0);
        D_004FFC04->f268 = 1;
    }
}


