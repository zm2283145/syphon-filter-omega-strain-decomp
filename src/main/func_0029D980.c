#include "types.h"
typedef struct { int a[4]; } Str_D980;
typedef struct { char pad[0x88]; int x88; char pad8c[0x11C - 0x8C]; int x11C; } O_D980;
extern int D_004FFC04;
extern char D_004AAC10[];
extern void func_0029F340(void*, char*, char*, char*);
extern void String_CtorCStr_13B480(Str_D980*, char*);
extern char* String_CStr(Str_D980*);
extern void func_00209620(Str_D980*, Str_D980*);
extern void func_00138B70(Str_D980*, int);
extern void FrontEnd_OpenPopup(int, int, char*, char*, O_D980*, int);
extern void FrontEnd_ClosePopup(int, int);

static inline void Zero(char* q, int n)
{
    if (q) {
        do {
            *q++ = 0;
        } while (--n);
    }
}

#pragma opt_propagation off
#pragma optimize_for_size on
void func_0029D980(O_D980* o, void* src) {
    Str_D980 s;
    Str_D980 t;
    Str_D980 u;
    char title[0x80];
    char body[0x100];
    char extra[0x80];
    int flags;
    Zero(title, 0x80);
    Zero(body, 0x100);
    Zero(extra, 0x80);
    func_0029F340(src, title, body, extra);
    String_CtorCStr_13B480(&s, body);
    if (extra[0]) {
        String_CtorCStr_13B480(&t, D_004AAC10);
        func_00209620(&s, &t);
        func_00138B70(&t, 0);
        String_CtorCStr_13B480(&u, extra);
        func_00209620(&s, &u);
        func_00138B70(&u, 0);
    }
    flags = 0;
    if (o->x88 != 4) flags = 0x20;
    FrontEnd_OpenPopup(D_004FFC04, 2, title, String_CStr(&s), o, flags);
    FrontEnd_ClosePopup(D_004FFC04, o->x11C);
    func_00138B70(&s, 0);
}