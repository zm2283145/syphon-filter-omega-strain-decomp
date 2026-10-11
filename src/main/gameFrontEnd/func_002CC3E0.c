#include "types.h"
typedef struct { char pad[0x2C]; unsigned char b2C; char pad2[0x2AC - 0x2D]; char name[0x40]; } ObjC3E0;
typedef struct { char pad[0x250]; unsigned char mode; } HudC3E0;
extern unsigned char D_0048C248;
extern void* D_004FFD2C;
extern char D_004ACFA8[];
extern int D_005383D4;
extern void func_0045A150(void* p);
extern void func_002CC980(void);
extern char* func_003CBA90(char* key);
extern char* strncpy(char* d, const char* s, int n);
extern void func_002CB3D0(ObjC3E0* o, int a);
extern HudC3E0* func_001698C0(void);
void func_002CC3E0(ObjC3E0* o)
{
    if (D_0048C248) {
        char* s;
        func_0045A150(D_004FFD2C);
        o->b2C = 0;
        func_002CC980();
        s = func_003CBA90(D_004ACFA8);
        if (s)
            strncpy(o->name, s, 0x40);
        D_0048C248 = 0;
    }
    func_002CB3D0(o, 0);
    D_005383D4 = (func_001698C0()->mode == 2) ? 0x32 : 0x3C;
}