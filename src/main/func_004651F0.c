#pragma cplusplus on
#include "types.h"
struct VO_4651F0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual char* Name();
};
typedef struct { int prev; int next; VO_4651F0* obj; } N_4651F0;
typedef struct { int n; N_4651F0* head; } L_4651F0;
typedef struct { char pad[0x28]; L_4651F0 l; } M_4651F0;
typedef struct { char pad[0x6A4]; void* f6A4; unsigned char b6A8; unsigned char b6A9; unsigned char b6AA; } G_4651F0;
typedef struct { char pad[0x178]; int f178; } P_4651F0;
typedef struct { char pad[0x6C]; unsigned char b6C; unsigned char b6D; char pad6E[2]; int f70; VO_4651F0* f74; } O_4651F0;
extern "C" {
extern unsigned int D_00497BF0[2];
extern unsigned char D_004FFC29;
extern void* D_004FFC04;
extern G_4651F0* D_004FFC2C;
extern P_4651F0* D_004FFC0C;
extern char D_004C2910[];
extern char D_004C2930[];
extern char D_004C2948[];
int String_CompareNoCase(char* a, char* b);
int func_002CAB70(void* p);
int func_0045BD00(void* p);
M_4651F0* Gui_GetScreenStack(void);
}
static inline bool NotBusy(void) { return !D_004FFC2C->b6AA && !func_0045BD00(D_004FFC2C->f6A4); }
extern "C" unsigned char func_004651F0(O_4651F0* o)
{
    unsigned char r;
    M_4651F0* m = Gui_GetScreenStack();
    L_4651F0* l = &m->l;
    r = 0;
    if (l->n) {
        VO_4651F0* obj = l->head->obj;
        if (obj == o->f74) {
            if (D_004FFC29) {
                if (!String_CompareNoCase(obj->Name(), D_004C2910) || !String_CompareNoCase(l->head->obj->Name(), D_004C2930))
                    r = 1;
            } else if (!String_CompareNoCase(obj->Name(), D_004C2948)) {
                r = NotBusy() && !D_004FFC0C->f178;
            } else if (!func_002CAB70(D_004FFC04)) {
                r = D_004FFC2C->b6A9 || D_004FFC2C->b6A8;
            }
        } else {
            *(int*)D_00497BF0 = -1;
            o->b6C = 0;
            o->f70 = 0;
            o->b6D = 0;
        }
    }
    return r;
}








