#include "types.h"
typedef struct { char pad[0x1C]; int f1C; } P_433A60;
extern unsigned char D_005721D0;
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern char D_004BFCC8[];
extern int D_00582A70;
extern int D_00582A78; extern int D_00582A80; extern int D_00582A88; extern int D_00582A90; extern int D_00582A98;
extern int D_005827F0; extern int D_005827F8; extern int D_00582800; extern int D_00582808; extern int D_00582810;
int func_002EAF28(int* key, int a, int b, int c, int d, int e, int f, int g, char* h, int i);
int func_002EB650(P_433A60** out, int key);

static inline void Reg_433A60(int* key, int* out)
{
    P_433A60* p;
    if (!func_002EAF28(key, 2, 4, 0, 0, 0, 0, *out, D_004BFCC8, D_00582A70) && !func_002EB650(&p, *key)) *out = p->f1C;
}

void func_00433A60(void)
{
    if (D_005721D0 && (D_005721C8 ? D_005721C0 : 1)) {
        Reg_433A60(&D_00582A78, &D_005827F0);
        Reg_433A60(&D_00582A80, &D_005827F8);
        Reg_433A60(&D_00582A88, &D_00582800);
        Reg_433A60(&D_00582A90, &D_00582808);
        Reg_433A60(&D_00582A98, &D_00582810);
    }
}