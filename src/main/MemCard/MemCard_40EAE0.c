#include "types.h"
typedef struct { int h; char p0[0x10]; int size; char p1[4]; char name[0x1C]; } E40E5D0;
typedef struct {
    E40E5D0 ent[1]; char p0[0x3F4 - 0x38]; char path[0x14C];
    int busy; int state; int sub; int saveState; int saveSub; int p554; int arg; int p55C; int p560;
    int idx; int retries; int cnt; int x570; int res; int r; char p57C[0x20]; unsigned char flag;
} S40E5D0;
extern char* D_00494010;
extern char D_004BED60[];
extern char D_00571C50[];
extern int sprintf(char*, const char*, ...);
extern void func_002B5A08(int, char*, char*);
extern char* String_Copy(char*, const char*);

void func_0040EAE0(S40E5D0* s) {
    switch (s->sub) {
    case 0:
        sprintf(D_00571C50, D_004BED60, D_00494010, s->ent[s->idx].name);
        func_002B5A08(s->ent[0].h, D_00571C50, s->p57C);
        s->sub = 1;
        break;
    case 1:
        if (s->res) {
            if ((s->res & 0xFFFF) == 0x1C) {
                s->flag = 2;
                s->state = 0;
                s->sub = 0;
            } else if ((s->res & 0xFFFF) == 0x11) {
                s->flag = 3;
                s->state = 0;
                s->sub = 0;
            } else if ((s->res & 0xFFFF) == 0x16) {
                s->flag = 1;
                s->state = 0;
                s->sub = 0;
            } else if ((s->res & 0xFFFF) == 2) {
                s->flag = 1;
                s->state = 0;
                s->sub = 0;
            } else {
                s->flag = 1;
                s->saveState = s->state;
                s->saveSub = 0;
                s->retries++;
                if (s->retries > 3) {
                    s->state = 0;
                    s->sub = 0;
                } else {
                    s->cnt = 0;
                    s->state = 7;
                    s->sub = 0;
                }
            }
        } else {
            s->flag = 0;
            s->state = 0;
            s->sub = 0;
            String_Copy(s->ent[s->idx].name, s->p57C);
        }
        break;
    }
}

