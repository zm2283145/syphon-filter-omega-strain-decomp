#include "types.h"
typedef struct { char pad[0x14]; unsigned short flags; } W45C;
typedef struct { char pad[0x94]; int f94; } M45C;
typedef struct { char pad[0xE0]; W45C* fe0; int fe4; M45C* fe8; int fec; int ff0; char pad2[0x1C]; unsigned char b110; } P45C;
extern void* func_004147A0(void);
extern void func_00414B30(void*, M45C*);
extern char* Loc_LookupText(char*);
extern void func_00421290(M45C*, char*, int, int);
extern void func_0041E0F0(W45C*, void*, int, int, int);
extern void func_0045BF80(P45C*);
void cPlayer_LaunchChooseMenu(P45C* p, int arg) {
    if (p->fe0) {
        if (p->fe8->f94) {
            p->fe0->flags |= 2;
            func_00414B30(func_004147A0(), p->fe8);
            func_00421290(p->fe8, Loc_LookupText("Cancel"), -1, 0);
            p->ff0 = arg;
            p->b110 = 0;
            func_0041E0F0(p->fe0, func_004147A0(), 0x10, 2, 0);
        } else {
            func_0045BF80(p);
        }
    }
}
