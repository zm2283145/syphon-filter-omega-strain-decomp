#include "types.h"
#pragma mpwc_relax on
int Alloc_Lock();
int Alloc_Unlock();
void* Mem_Alloc(int, int, char*, int);
int func_0036DFB0();
int func_0036E140();
int func_0036E220();
int func_0036E5D0();
short func_00380A40(int, void*);
int sprintf();
int strlen(const char*);
extern char D_004BC170;
extern char D_004BC180;
extern char D_004BC190;
extern unsigned char D_00533880;
extern int D_00533888;
extern int D_00539248;

typedef struct {
    int pad0;
    int flags;
    char p8[0x14 - 0x8];
    int count;
    char p18[0x70 - 0x18];
    char names[1];
} MdlDesc;

typedef struct {
    int pad0;
    MdlDesc* desc;
    short* ids;
    char pC[0x24 - 0xC];
    int flags;
} Mdl;

void Model_BindTextures(Mdl* self, int arg1) {
    char buf[0x50];
    int name[0x28];
    int size;
    short* ids;
    char* s;
    int i;

    size = self->desc->count * 2;
    if (D_00533880 != 0) {
        Alloc_Lock(9);
    }
    D_00533888 += 1;
    ids = Mem_Alloc(0, size, &D_004BC170, 0x131);
    if (D_00533880 != 0) {
        Alloc_Unlock(9);
    }
    D_00533888 -= 1;
    self->ids = ids;
    s = self->desc->names;
    for (i = 0; i < self->desc->count; i++) {
        func_0036E5D0(name);
        sprintf(buf, &D_004BC180, s);
        func_0036DFB0(name, buf, arg1);
        self->ids[i] = func_00380A40(D_00539248, name);
        if (self->ids[i] == -1) {
            func_0036E140(name, &D_004BC190, 0, 0);
            self->ids[i] = func_00380A40(D_00539248, name);
        }
        s += strlen(s) + 1;
        func_0036E220(name, -1);
    }
    if (self->desc->flags & 1) {
        self->flags |= 0x400000;
    } else if (self->desc->flags & 2) {
        self->flags |= 0x800000;
    } else {
        self->flags |= 0x200000;
    }
}

