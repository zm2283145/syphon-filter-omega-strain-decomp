#include "types.h"
typedef struct { char c[16]; } Name27A8;
typedef struct { Name27A8 name; int x10; } Entry27A8;
typedef struct Node27A8 { int prev; struct Node27A8 *next; Entry27A8 *e; } Node27A8;
typedef struct { Node27A8 *p; } It27A8;
typedef struct {
    char pad[0x2C]; int count; char pad30[8]; int sel; int mode;
    Name27A8 name; int x50; unsigned char b54; unsigned char b55;
} Menu27A8;
extern unsigned char D_00504040;
extern void func_0013B180(It27A8 *r, void *l);
extern void func_0027AA80(It27A8 *r, It27A8 *s);
extern char *func_0027AA90(void *l);
extern void func_0027AB60(Menu27A8 *s);

void func_0027A8B0(Menu27A8 *s)
{
    if (s->mode == 0) {
        if (s->sel == 1) {
            if (D_00504040 == 0) {
                s->mode = 1;
                func_0027AB60(s);
            } else if (s->count != 0) {
                Entry27A8 *e;
                s->b54 = 1;
                s->b55 = 0;
                e = *(Entry27A8 **)func_0027AA90(&s->count);
                s->name = e->name;
                s->x50 = e->x10;
            }
        } else if (s->sel == 0) {
            s->b54 = 1;
            s->b55 = 1;
        }
    } else if (s->mode == 1) {
        if (s->count > s->sel) {
            It27A8 it, t;
            Node27A8 *n;
            Entry27A8 *e;
            int i;
            func_0013B180(&t, &s->count);
            func_0027AA80(&it, &t);
            n = it.p;
            for (i = 0; i < s->sel; i++) n = n->next;
            s->b54 = 1;
            s->b55 = 0;
            e = n->e;
            s->name = e->name;
            s->x50 = e->x10;
        }
    }
}

