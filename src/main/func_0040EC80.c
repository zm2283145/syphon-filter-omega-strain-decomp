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
extern void func_002B5570(int);
extern void func_002B5490(int, char*, int, int, int);

void func_0040EC80(S40E5D0* s) {
    char* buf;
    sprintf(D_00571C50, D_004BED60, D_00494010, s->ent[s->idx].name);
    buf = D_00571C50;
    switch (s->sub) {
    case 0:
        func_002B5570(s->ent[0].h);
        s->sub = 1;
        break;
    case 1:
        if ((s->res & 0xFFFF) == 0x1C) {
            if (s->p560 > 1)
                s->flag = 4;
            else
                s->flag = 2;
            s->state = 0;
            s->sub = 0;
            break;
        } else if ((s->res & 0xFFFF) == 0x11) {
            s->flag = 3;
            s->state = 0;
            s->sub = 0;
            break;
        } else if (s->res) {
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
            break;
        }
    case 2:
        func_002B5490(s->ent[0].h, buf, s->arg, 0, s->ent[s->idx].size);
        s->sub = 3;
        break;
    case 3:
        if (s->res < 0) {
            if ((s->res & 0xFFFF) == 0x1C) {
                if (s->p560 > 1)
                    s->flag = 4;
                else
                    s->flag = 2;
                s->state = 0;
                s->sub = 0;
            } else {
                s->saveState = s->state;
                s->saveSub = 2;
                s->retries++;
                if (s->retries > 3) {
                    s->state = 0;
                    s->sub = 0;
                } else {
                    s->cnt = 0;
                    s->state = 7;
                    s->sub = 0;
                }
                s->flag = 1;
            }
        } else {
            s->flag = 0;
            s->state = 0;
            s->sub = 0;
        }
        break;
    }
}


