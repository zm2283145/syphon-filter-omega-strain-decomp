#include "types.h"
typedef struct { int cap; int count; int f8; int fC; int f10; int f14; unsigned char dirty; } L450B30;
typedef struct {
    char p0[0xA8]; L450B30 list; char pC4[0x17C - 0xC4]; unsigned char f17C;
    char p17D[0x24C - 0x17D]; int f24C; char p250[0x1E9C - 0x250]; int f1E9C;
    char p1EA0[0x2418 - 0x1EA0]; char name[0x11];
} S450B30;
extern int D_00585FA8;
extern int D_004977A0;
extern int D_00497938;
extern char D_004C0F68[];
extern char func_00447790[];
extern void func_00450060(S450B30*);
extern int func_00443E70(void);
extern void String_Copy(char*, char*);
extern int func_00476998(void);
extern int func_00469DC8(void*, void*);
extern void func_0044F7E0(void*);
extern void func_0044F160(void*, int);
extern void func_0044F280(void*, int);
extern void* memset(void*, int, int);

static inline int Off450B30(S450B30* self)
{
    return D_00585FA8 != 0 && !self->f17C;
}

void func_00450B30(S450B30* s)
{
    struct { char f0[0x15]; char f15[0x13]; int f28; short f2C; short f2E; } req;
    int dt;

    if (Off450B30(s)) {
        func_00450060(s);
        return;
    }
    dt = func_00443E70() - s->f1E9C;
    if (D_004977A0 < dt) {
        memset(&req, 0, sizeof(req));
        String_Copy(req.f0, D_004C0F68);
        String_Copy(req.f15, s->name);
        req.f28 = func_00476998();
        req.f2C = 1;
        req.f2E = D_00497938;
        s->f24C = func_00469DC8(&req, func_00447790);
        if (s->f24C != 0) return;
        s->f1E9C = func_00443E70();
        func_0044F7E0(&s->list);
        func_0044F160(&s->list, 1);
    }
    if (s->list.dirty && s->list.count > 0)
        func_0044F280(&s->list, 1);
}


