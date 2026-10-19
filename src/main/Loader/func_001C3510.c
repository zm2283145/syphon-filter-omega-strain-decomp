#pragma cplusplus on
#include "alloc_guard.h"
/* Pop_LoadGOB: reads the "GOB:" block of a pop file and creates one game
 * object per record (kind 1/4 generic, 2 path, 3 lift, 5 interact, 6 kind-6
 * GOBJ), registering each; same reader/allocator shape as Loader_InitHotboxes. */
struct PopReader_3510 { int version; int size; unsigned int base; char* cur; };
extern "C" {
extern char D_0049EE88[];
void* Mem_Alloc(int heap, int size, char* file, int line);
void* App_GetInstance(void);
void Loader_UpdateLoadingScreen(void* app, const char* text, int n);
int Pop_FindTag(PopReader_3510* r, int tag);
void Object_Register(void* p);
void* cGameGOBJ_ctor(void* p, int h, PopReader_3510* r, int kind);
void* PathObj_Ctor(void* p, int h, PopReader_3510* r);
void* Lift_Ctor(void* p, int h, PopReader_3510* r);
void* cGameGOBJ_CtorKind6(void* p, int h, PopReader_3510* r);
void* cInteractGOBJ_ctor(void* p, int h, PopReader_3510* r);
}

static inline void* GAlloc(int size, int line)
{
    void* p;
    {
        AllocGuard g;
        p = Mem_Alloc(0, size, D_0049EE88, line);
    }
    return p;
}

extern "C" void Pop_LoadGOB(void* l, PopReader_3510* r, int h)
{
    if ((unsigned char)Pop_FindTag(r, 0x3A424F47)) {
        int n;
        int i;
        int mis;
        n = *(int*)r->cur;
        r->cur += 4;
        if (n) {
            Loader_UpdateLoadingScreen(App_GetInstance(), "Initializing GOBJs...", 0);
            for (i = 0; i < n; i++) {
                int type = *(int*)r->cur;
                void* p;
                r->cur += 4;
                switch (type) {
                case 1:
                case 4:
                    {
                        void* t = GAlloc(0x94, 0x17F);
                        if (t)
                            t = cGameGOBJ_ctor(t, h, r, type);
                        p = t;
                    }
                    break;
                case 2:
                    {
                        void* t = GAlloc(0xE8, 0x183);
                        if (t)
                            t = PathObj_Ctor(t, h, r);
                        p = t;
                    }
                    break;
                case 3:
                    {
                        void* t = GAlloc(0x7A0, 0x187);
                        if (t)
                            t = Lift_Ctor(t, h, r);
                        p = t;
                    }
                    break;
                case 6:
                    {
                        void* t = GAlloc(0x94, 0x18B);
                        if (t)
                            t = cGameGOBJ_CtorKind6(t, h, r);
                        p = t;
                    }
                    break;
                case 5:
                    {
                        void* t = GAlloc(0xC0, 0x18F);
                        if (t)
                            t = cInteractGOBJ_ctor(t, h, r);
                        p = t;
                    }
                    break;
                default:
                    return;
                }
                Object_Register(p);
            }
            mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
            if (mis)
                r->cur += 4 - mis;
        }
    }
}
