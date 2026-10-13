#include "types.h"
#include "fileman_entry.h"
extern int sprintf(char* buf, const char* fmt, ...);
extern void* func_0036E140(void* entry, const char* name, int a, int b);
extern int func_003EBA50(void);
extern int func_003EAA60(int mgr, void* entry, int flag);
extern void func_003813A0(int mgr, int handle, int flags);
extern int D_00539248;
typedef struct {
    char name[0x3C0];
    short cur[8];
    short prev[8];
    char pad3E0[0x40C - 0x3E0];
    unsigned char count;
    char pad40D[0x417 - 0x40D];
    signed char state;
    unsigned char dirty;
} Cc70Obj;
void func_0038CC70(Cc70Obj* self)
{
    if (self->dirty) {
        FileManEntry e;
        char path[0x100];
        func_0036E5D0(&e);
        sprintf(path, "%s.HOG", self);
        func_0036E140(&e, path, 0, 0);
        func_003EAA60(func_003EBA50(), &e, 1);
        self->dirty = 0;
        func_0036E220(&e, -1);
    }
    if (self->state < 0) {
        self->state = -2;
    } else {
        int mgr = D_00539248;
        int i;
        for (i = 0; i < self->count; i++) {
            if (self->cur[i] != self->prev[i]) func_003813A0(mgr, self->prev[i], 0);
            func_003813A0(mgr, self->cur[i], 0);
        }
        self->state = -3;
    }
}
