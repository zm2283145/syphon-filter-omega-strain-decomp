#include "types.h"
typedef struct { char pad0[0x244]; char flag; char pad245[3]; int* table; } Lobby_452A70;
typedef struct { char pad0[0x18]; int busy; char pad1C[0x44 - 0x1C]; int val; char name[0x8C - 0x48]; char kind; } Msg_452A70;
extern Lobby_452A70* D_00585E60;
extern int D_00585F90;
extern int func_004505C0(int a, int b, int c, Msg_452A70* s);
extern void String_Copy(char* d, char* s);
extern char* strrchr(char* s, int c);
extern int func_00121BC8(char* s);
void func_00452A70(int a, int b, int c, Msg_452A70* s) {
    char buf[0x40];
    char* p;
    int n;
    if (func_004505C0(a, b, c, s) || !D_00585E60->table) return;
    if (s->busy == 0) {
        String_Copy(buf, s->name);
        *strrchr(buf, ':') = 0;
        p = strrchr(buf, '_');
        if (p) {
            n = func_00121BC8(p + 1);
            if (n < D_00585F90) {
                D_00585E60->table[n] = s->val;
            }
        }
    }
    if (s->kind == 1) {
        D_00585E60->flag = 1;
    }
}
