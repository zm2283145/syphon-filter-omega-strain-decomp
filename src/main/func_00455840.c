#include "types.h"
typedef struct { char pad0[0x60]; int f60; int f64; char pad68[8]; int f70; int f74; } Wpn_00455840;
typedef struct { char pad0[0x30]; int f30; } G_00455840;
extern G_00455840* D_004FFC0C;
extern int D_004FFD30;
extern char D_004C1A38[];
extern char D_004C1A50[];
extern char D_004C1A88[];
extern char D_004C1A98[];
int sprintf(char* d, const char* f, ...);
char* Loc_LookupText(char* key);
void func_00426510(void* list, int col, int row, char* text);
Wpn_00455840* WeaponDb_Get(int db, int id);
void String_Copy(char* d, char* s);
int func_002C9020(int a);
int func_002C8FD0(int a);
void func_002C8EC0(int a, char* buf, int n);
int WeaponInv_ClipsForActor(int actor, int a);
void func_00455840(void* list, int id)
{
    char key[0x10];
    char buf[0x20];
    int i;
    Wpn_00455840* w;
    for (i = 0; i < 4; i++) {
        char* t;
        sprintf(key, D_004C1A88, i);
        t = Loc_LookupText(key);
        func_00426510(list, 0, i, t ? t : D_004C1A38);
    }
    w = WeaponDb_Get(D_004FFD30, id);
    if (w) {
        int actor = D_004FFC0C->f30;
        for (i = 0; i < 4; i++) {
            String_Copy(buf, D_004C1A98);
            switch (i) {
            case 0:
                if (w->f60)
                    func_002C8EC0(func_002C9020(w->f60), buf, 0x20);
                break;
            case 1:
                if (w->f64)
                    func_002C8EC0(func_002C8FD0(w->f64), buf, 0x20);
                break;
            case 2:
                if (w->f70)
                    sprintf(buf, D_004C1A50, w->f70);
                break;
            case 3: {
                int n = w->f70 * WeaponInv_ClipsForActor(actor, w->f74);
                if (n)
                    sprintf(buf, D_004C1A50, n);
                break;
            }
            }
            func_00426510(list, 1, i, buf);
        }
    }
}

