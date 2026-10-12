#include "types.h"
typedef struct { int h; char p0[0x10]; int size; char p1[4]; char name[0x1C]; } E40E5D0;
typedef struct {
    E40E5D0 ent[1]; char p0[0x3F4 - 0x38]; char path[0x14C];
    int busy; int state; int sub; int saveState; int saveSub; int p554; int arg; int p55C; int p560;
    int idx; int retries; int cnt; int x570; int res; int r; char p57C[0x20]; unsigned char flag;
} S40E5D0;
extern char* D_00494010;
extern int sprintf(char*, const char*, ...);
extern void func_002B57D0(int, char*);

void func_0040EED0(S40E5D0* s) {
    char buf[0x80];
    switch (s->sub) {
    case 0:
        sprintf(buf, "/%s", D_00494010);
        func_002B57D0(s->ent[0].h, buf);
        s->sub = 1;
        break;
    case 1:
        if ((s->res & 0xFFFF) == 0x1C) {
            s->flag = 2;
        } else if ((s->res & 0xFFFF) == 0x11) {
            s->flag = 3;
        } else if (s->res) {
            s->flag = 1;
        } else {
            s->flag = 0;
        }
        s->state = 0;
        s->sub = 0;
        break;
    }
}

