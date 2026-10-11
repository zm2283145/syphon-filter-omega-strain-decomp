#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
extern char D_004ACF10[];
extern char D_004ACF60[];
extern char D_0048B2F8[];
char* func_002CCA30(void);
int sprintf(char* buf, const char* fmt, ...);
void* func_0036D630(void* p);
void func_0036D5D0(void* p, int flags);
int Hog_Load(void* hog, char* path, int mode, int flags);
}
struct Obj9EE0 { char pad[0x25C]; void* hog; };
extern "C" bool func_002C9EE0(Obj9EE0* o)
{
    if (!o->hog) {
        char path[0x100];
        void* p;
        sprintf(path, D_004ACF60, D_0048B2F8, func_002CCA30());
        {
            AllocGuard guard;
            p = Mem_Alloc(0, 0x16C, D_004ACF10, 0x628);
        }
        if (p)
            p = func_0036D630(p);
        o->hog = p;
        if (Hog_Load(o->hog, path, 2, 0)) {
            void* q = o->hog;
            {
                AllocGuard guard;
                func_0036D5D0(q, -1);
                Mem_Free(0, q, D_004ACF10, 0x62C);
            }
            o->hog = 0;
        }
    }
    return o->hog != 0;
}