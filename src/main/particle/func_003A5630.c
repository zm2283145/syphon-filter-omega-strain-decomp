#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma opt_loop_invariants off
#pragma opt_propagation off

extern "C" {
void* Mem_Alloc(int, int, char*, int);
void* Ptr_Identity(void*);
int func_0012AC20(char*, char**);
float SoftFloat_DoubleToFloat(int);
char* strchr(const char*, int);
int func_0012B1F0(char*, char**, int);
void func_003A5890(void*);
void func_003A43A0(void*, float, char*, int);
extern char D_004BC5D0[];
extern char D_004DFB90[];
extern char D_004DFB70[];
}

struct Elem3A5630 {
    int d[4];
};

struct Obj3A5630 {
    void* vt;
    unsigned char type;
    char pad5[0x900 - 5];
    Elem3A5630 e[1];
};

inline void* Alloc3A5630(int size, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, D_004BC5D0, line);
}

inline Obj3A5630* Ctor3A5630(Obj3A5630* r, char* vt, int end)
{
    if (r) {
        Elem3A5630* e;
        func_003A5890(r);
        r->vt = vt;
        e = r->e;
        do {
            Ptr_Identity(e);
            e++;
        } while (e != (Elem3A5630*)((char*)r + end));
    }
    return r;
}

extern "C" Obj3A5630* func_003A5630(void* self, char* str, int arg, Obj3A5630* obj)
{
    char* s = str;
    Obj3A5630* r = 0;
    float ver;
    unsigned char type;

    ver = SoftFloat_DoubleToFloat(func_0012AC20(s, &s));
    if (ver <= 2.1f) {
        s = strchr(s, '\n') + 1;
        type = func_0012B1F0(s, &s, 10);
        s = strchr(s, '\n') + 1;
        if (obj) {
            r = obj;
        } else if (type == 0) {
            r = Ctor3A5630((Obj3A5630*)Alloc3A5630(0x9D0, 0x1AB), D_004DFB90, 0x990);
        } else if (type == 1) {
            r = Ctor3A5630((Obj3A5630*)Alloc3A5630(0xA70, 0x1AF), D_004DFB70, 0xA20);
        }
        r->type = type;
        func_003A43A0(r, ver, s, arg);
    }
    return r;
}


