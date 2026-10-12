#include "types.h"
typedef struct { int type; } E2C8090;
typedef struct { int a; int count; } L2C8090;
typedef struct { char pad[0xB73]; unsigned char flag; } A2C8090;
extern char* func_004294C0(void);
extern A2C8090* Agent_GetSelected(void*, int);
extern char D_004FFB50;
extern int D_0052FE80;
extern E2C8090* func_0044F290(L2C8090*, int);
extern void func_00336EC0(A2C8090*, E2C8090*);
int func_002C8090(void) {
    char* g = func_004294C0();
    A2C8090* ag = Agent_GetSelected(&D_004FFB50, -1);
    int i;
    L2C8090* l;
    int n;
    if (!g || !ag) return 0;
    l = (L2C8090*)(g + 0x1C);
    if (!l) return 0;
    if (l->count != 0 || D_0052FE80 != 0) ag->flag = 1;
    D_0052FE80 = 0;
    n = l->count;
    if (n > 0x40) return 0;
    for (i = 0; i < n; i++) {
        E2C8090* e = func_0044F290(l, i);
        if (e) {
            switch (e->type) {
            case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 11:
                func_00336EC0(ag, e);
                break;
            }
        }
    }
    return 1;
}