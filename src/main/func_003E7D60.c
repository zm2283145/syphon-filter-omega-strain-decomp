#include "types.h"
typedef struct { unsigned int word; unsigned int length; char* data; } Str_E7D60;
typedef struct {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    char pad3[5];
    int w8;
    int wC;
    char pad10[8];
    Str_E7D60 lines[0x16];
    Str_E7D60 more[0x14];
    char pad210[8];
    int w218;
    int w21C;
    int w220;
} Con_E7D60;
extern char D_004BDF30[];
extern char D_004BDF50[];
extern void __construct_array(void* arr, void (*ctor)(void*), void (*dtor)(void*), int size, int count);
extern void func_00298690(void*);
extern void func_00138350(void*);
extern void String_Reserve(Str_E7D60* s, int n);
extern void String_CtorCStr_13B480(Str_E7D60* s, char* c);
extern void func_0013D680(Str_E7D60* d, Str_E7D60* s);
extern void func_00209620(Str_E7D60* d, Str_E7D60* s);
extern void func_00138B70(Str_E7D60* s, int f);

Con_E7D60* func_003E7D60(Con_E7D60* self, char* name, int x)
{
    int i;
    int off;
    self->b0 = 1;
    self->b1 = 0;
    self->b2 = 0;
    self->w8 = 0;
    __construct_array(self->lines, func_00298690, func_00138350, 0xC, 0x16);
    __construct_array(self->more, func_00298690, func_00138350, 0xC, 0x14);
    self->w21C = 0;
    self->w220 = x;
    for (i = 0, off = 0; i < 0x16; i++, off += 0xC)
        String_Reserve(((Con_E7D60*)((unsigned)self + off))->lines, 100);
    {
        Str_E7D60 t;
        String_CtorCStr_13B480(&t, D_004BDF30);
        func_0013D680(&self->lines[0], &t);
        func_00138B70(&t, 0);
    }
    {
        Str_E7D60 t;
        String_CtorCStr_13B480(&t, name);
        func_00209620(&self->lines[0], &t);
        func_00138B70(&t, 0);
    }
    {
        Str_E7D60 t;
        String_CtorCStr_13B480(&t, D_004BDF50);
        func_0013D680(&self->lines[1], &t);
        func_00138B70(&t, 0);
    }
    self->wC = 2;
    self->w218 = 0;
    return self;
}


