/*
 * lib/medius: 6 files, 002ED570-002ED838
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002ED570 */
#include "types.h"
extern int D_0048C458;
extern int D_0058C138[];
extern int D_0058C0B8[];
extern int D_0058C0F8[];
int func_002ED570(unsigned int i, int b, int c, int d)
{
    if (!D_0048C458) return 0x11;
    if (i >= 16) return 0x17;
    D_0058C0B8[i] = b;
    D_0058C0F8[i] = c;
    D_0058C138[i] = d;
    return 0;
}
/* merge_units: end func_002ED570 */

/* merge_units: begin func_002ED5C0 */
extern int D_0048C4E8;
extern int func_002F5160(void);
int func_002ED5C0(void)
{
    if (D_0048C4E8 == 0) D_0048C4E8 = func_002F5160();
    D_0048C4E8 = D_0048C4E8 * 0x343FD + 0x269EC3;
    return (D_0048C4E8 >> 16) & 0x7FFF;
}
/* merge_units: end func_002ED5C0 */

/* merge_units: begin func_002ED620 */
void func_002ED620(unsigned int* p)
{
    p[4] = 0;
    p[2] = 0;
    p[1] = 0;
    p[3] = 0;
    p[0] = 0xFFFF;
}
/* merge_units: end func_002ED620 */

/* merge_units: begin func_002ED640 */
extern int func_002D9E88(int, int);
void func_002ED640(int a, int *p, int b, int c)
{
    p[2] = b;
    p[0] = c;
    p[1] = func_002D9E88(a, c);
    p[3] = func_002F5160();
    p[4] = 0;
}
/* merge_units: end func_002ED640 */

/* merge_units: begin func_002ED680 */
typedef struct { int a, b, c, time, e; } E2ED680;
typedef struct T2ED680 {
    struct T2ED680 *next; struct T2ED680 *prev; int a; int b; char c; char p11[0x47];
    int f58; int f5C; E2ED680 *arr; int f64; int f68; int now; int f70; int f74; int f78[3];
} T2ED680;
typedef struct { char p[0x50]; int f50; int f54; } X2ED680;
extern void Net_AllocZeroed(void *, unsigned long);
extern void *memset(void *, int, unsigned int);
T2ED680 *func_002ED680(int a, T2ED680 *list, int b, int cap)
{
    T2ED680 *p = 0;
    int now;
    int i;
    Net_AllocZeroed(&p, 0x84);
    if (p != 0) {
    now = func_002F5160();
    p->a = a;
    p->b = b;
    p->next = 0;
    p->prev = 0;
    p->f64 = 0;
    p->f70 = 0;
    p->now = now;
    p->f74 = 0;
    p->f68 = 0;
    p->c = 0;
    p->f58 = cap;
    p->f5C = p->f58 ? p->f58 : 0x20;
    Net_AllocZeroed(&p->arr, (unsigned int)(p->f5C * sizeof(E2ED680)));
    for (i = 0; i < p->f5C; i++)
        p->arr[i].time = now;
    memset(p->f78, 0, 12);
    ((X2ED680 *)p)->f54 = 0;
    ((X2ED680 *)p)->f50 = 0;
    if (list) {
        p->prev = list;
        p->next = list->next;
        p->prev->next = p;
        p->next->prev = p;
    } else {
        p->prev = p;
        p->next = p;
    }
    }
    return p;
}
/* merge_units: end func_002ED680 */

/* merge_units: begin func_002ED838 */
typedef struct { char pad[0x5C]; int x5C; void *x60; } S838;
extern void func_002F3450(void *);
extern int func_002FB3C0(void *pp);
void func_002ED838(S838 *s)
{
    if (s) {
        func_002F3450((char *)s + 0x50);
        if (s->x60) {
            func_002FB3C0(&s->x60);
            s->x60 = 0;
            s->x5C = 0;
        }
        func_002FB3C0(&s);
    }
}
/* merge_units: end func_002ED838 */
