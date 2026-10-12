#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct PopReader_1C1770 { int version; int size; unsigned int base; char* cur; };
struct Light_1C1770 { void* vt; char pad[0x64]; };
extern "C" {
extern char D_0049EE88[];
extern char D_004DA0B0[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void Object_Register(void* o);
int Pop_FindTag(PopReader_1C1770* r, int tag);
void* cGameSceneLight_ctor(void* p, PopReader_1C1770* r);
void* cGameDirectionalLight_ctor(void* p, PopReader_1C1770* r);
void cGameLight_dtor(void* p, int f);
void func_00165E60(void* a, char* name, int x);
void* func_001698C0(void);
}
extern "C" void Loader_InitLights(void* a0, PopReader_1C1770* r)
{
    if (r->cur) {
        int mis;
        func_00165E60(func_001698C0(), "Initializing Lights...", 0);
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
        if ((unsigned char)Pop_FindTag(r, 0x3A544E50)) {
            {
                int n;
                int i = 0;
                n = *(int*)r->cur;
                r->cur += 4;
                for (; i < n; i++) {
                    void* p;
                    {
                        AllocGuard g;
                        p = Mem_Alloc(0, 0x68, D_0049EE88, 0x441);
                    }
                    if (p)
                        p = cGameSceneLight_ctor(p, r);
                    Object_Register(p);
                }
            }
            mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
            if (mis)
                r->cur += 4 - mis;
            if ((unsigned char)Pop_FindTag(r, 0x3A524944)) {
                int n;
                int i = 0;
                n = *(int*)r->cur;
                r->cur += 4;
                for (; i < n; i++) {
                    if (i < 4) {
                        void* p;
                        {
                            AllocGuard g;
                            p = Mem_Alloc(0, 0x68, D_0049EE88, 0x484);
                        }
                        if (p)
                            p = cGameDirectionalLight_ctor(p, r);
                        Object_Register(p);
                    } else {
                        Light_1C1770 tmp;
                        cGameDirectionalLight_ctor(&tmp, r);
                        tmp.vt = D_004DA0B0;
                        cGameLight_dtor(&tmp, 0);
                    }
                }
            }
        }
    }
}