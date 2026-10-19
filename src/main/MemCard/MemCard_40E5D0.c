/*
 * main/MemCard: 5 files, 0040E5D0-0040EED0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040E5D0 */
#pragma push /* merge_units */
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
extern void MemCard_InfoCycle(S40E5D0*);
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
        MemCard_InfoCycle(s);
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
#pragma pop /* merge_units */
/* merge_units: end func_0040E5D0 */

/* merge_units: begin func_0040E980 */
#pragma push /* merge_units */
extern char D_004BED60[];
extern void func_002B5490(int, char*, int, int, int);

void func_0040E980(S40E5D0* s) {
    switch (s->sub) {
    case 0:
        sprintf(D_00571C50, D_004BED60, D_00494010, s->ent[s->idx].name);
        func_002B5490(s->ent[0].h, D_00571C50, s->arg, 0, s->ent[s->idx].size);
        s->sub = 2;
        break;
    case 2:
        if (s->res < 0) {
            if ((unsigned short)s->res == 0x1C) {
                if (s->p560 > 1)
                    s->flag = 4;
                else
                    s->flag = 2;
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
        }
        break;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0040E980 */

/* merge_units: begin func_0040EAE0 */
#pragma push /* merge_units */
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
#pragma pop /* merge_units */
/* merge_units: end func_0040EAE0 */

/* merge_units: begin func_0040EC80 */
#pragma push /* merge_units */
extern void func_002B5570(int);

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
#pragma pop /* merge_units */
/* merge_units: end func_0040EC80 */

/* merge_units: begin func_0040EED0 */
#pragma push /* merge_units */
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
#pragma pop /* merge_units */
/* merge_units: end func_0040EED0 */
