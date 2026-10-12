#include "types.h"
typedef struct { int h; char p0[0x10]; int size; char p1[4]; char name[0x1C]; } E40E5D0;
typedef struct {
    E40E5D0 ent[1]; char p0[0x3F4 - 0x38]; int t0; int t1; int t2; char path[0x140];
    int busy; int state; int sub; int saveState; int saveSub; int p554; int arg; int p55C; int p560;
    int idx; int retries; int cnt; int x570; int res; int r; char p57C[0x20]; unsigned char flag;
    unsigned char f59D; unsigned char f59E; unsigned char f59F; unsigned char f5A0; char p5A1[3];
    int x5A4; int x5A8;
} S40E5D0;
extern char* D_00494010;
extern char D_004BED60[];
extern char D_00571C50[];
extern int sprintf(char*, const char*, ...);
extern void func_002B51E0(int, int*);
extern void func_002B56E0(int, char*, int, int, void*, int*);
extern int func_00121BC8(char*);

void func_0040EFA0(S40E5D0* s) {
    int i;
    if (s->busy) {
        s->state = s->busy;
        s->busy = 0;
        s->sub = 0;
        return;
    }
    switch (s->sub) {
    case 0:
        func_002B51E0(s->ent[0].h, &s->t0);
        s->sub = 1;
        break;
    case 1:
        s->f59D = s->t0 == 2;
        s->f59E = s->t1 == 1;
        if (s->res < 0) {
            s->x5A8 = -1;
            s->p560 = 0;
            s->x5A4 = 0;
            s->f59F = 0;
            s->f59E = 0;
            if (++s->retries > 6) {
                s->f5A0 = 1;
                s->retries = 0;
            }
            if (*(unsigned short*)&s->res != 0x2F)
                s->f59D = 0;
            s->sub = 0;
        } else {
            s->x5A4 = s->t2;
            sprintf(D_00571C50, D_004BED60, D_00494010, "*");
            func_002B56E0(s->ent[0].h, D_00571C50, 0, 0x12, s->ent[0].p0, &s->p560);
            s->sub = 2;
        }
        break;
    case 2:
        s->x5A8 = -1;
        if (s->res < 0) {
            s->p560 = 0;
            s->f59F = 0;
        } else {
            s->f59F = 1;
            for (i = 0; i < s->p560; i++) {
                if (s->ent[i].name[0] == '#')
                    s->x5A8 = func_00121BC8(s->ent[i].name + 1);
            }
        }
        s->retries = 0;
        s->f5A0 = 1;
        s->sub = 0;
        break;
    }
}

