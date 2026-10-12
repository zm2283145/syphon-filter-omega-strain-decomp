#include "types.h"
typedef struct { int h; char p0[0x10]; int size; char p1[4]; char name[0x1C]; } E40E5D0;
typedef struct {
    E40E5D0 ent[1]; char p0[0x3F4 - 0x38]; char path[0x14C];
    int busy; int state; int sub; int saveState; int saveSub; int p554; int arg; int p55C; int p560;
    int idx; int retries; int cnt; int x570; int res; int r; char p57C[0x20]; unsigned char flag;
} S40E5D0;
extern char* D_00494010;
extern char D_00571C50[];
extern int sprintf(char*, const char*, ...);
extern int func_002B5F48(int*, int*);
extern void func_0040EFA0(S40E5D0*);
extern void func_0040EED0(S40E5D0*);
extern void func_0040EC80(S40E5D0*);
extern void func_0040E980(S40E5D0*);
extern void func_0040EAE0(S40E5D0*);
extern void func_002B50E0(int);
extern void func_002B53B0(int, char*, int, int, int);
extern void func_002B5628(int, char*);
extern void func_002B51E0(int, char*);
int func_0040E5D0(S40E5D0* s) {
    s->r = func_002B5F48(&s->x570, &s->res);
    if (s->r == 0) {
        return s->busy ? s->busy : s->state;
    }
    switch (s->state) {
    case 0:
        func_0040EFA0(s);
        break;
    case 1:
        switch (s->sub) {
        case 0:
            func_002B50E0(s->ent[0].h);
            s->sub = 1;
            break;
        case 1:
            if (s->res == 0) {
                s->flag = 0;
                s->state = 0;
                s->sub = 0;
            } else {
                s->flag = 1;
                s->state = 0;
                s->sub = 0;
            }
            break;
        }
        break;
    case 2:
        func_0040EED0(s);
        break;
    case 3:
        func_0040EC80(s);
        break;
    case 4:
        func_0040E980(s);
        break;
    case 5:
        switch (s->sub) {
        case 0:
            sprintf(D_00571C50, "/%s/%s", D_00494010, s->ent[s->idx].name);
            func_002B53B0(s->ent[0].h, D_00571C50, s->arg, 0, s->ent[s->idx].size);
            s->sub = 2;
            break;
        case 2:
            if (s->res < 0) {
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
            } else {
                s->flag = 0;
                s->state = 0;
                s->sub = 0;
            }
            break;
        }
        break;
    case 6:
        switch (s->sub) {
        case 0:
            sprintf(D_00571C50, "/%s/%s", D_00494010, s->ent[s->idx].name);
            func_002B5628(s->ent[0].h, D_00571C50);
            s->sub = 2;
            break;
        case 2:
            if (s->res < 0) {
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
            } else {
                s->flag = 0;
                s->state = 0;
                s->sub = 0;
            }
            break;
        }
        break;
    case 7:
        switch (s->sub) {
        case 0:
            func_002B51E0(s->ent[0].h, s->path);
            s->sub = 1;
            break;
        case 1:
            if (s->res < 0) {
                if (++s->cnt > 3) {
                    s->state = 0;
                    s->sub = 0;
                } else {
                    s->sub = 0;
                }
            } else {
                s->state = s->saveState;
                s->sub = s->saveSub;
            }
            break;
        }
        break;
    case 9:
        func_0040EAE0(s);
        break;
    }
    return s->state;
}