/*
 * SFOGame/Source/Loader: 1 file, 001C3510
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C3510 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
/* cLoader_LoadGOBJs: reads the "GOB:" block of a pop file and creates one game
 * object per record (kind 1/4 generic, 2 path, 3 lift, 5 interact, 6 kind-6
 * GOBJ), registering each; same reader/allocator shape as cLoader_LoadHotboxes. */
struct PopReader_3510 { int version; int size; unsigned int base; char* cur; };
extern "C" {
extern char D_0049EE88[];
void* cMemMan_Allocate(int heap, int size, char* file, int line);
void* GetMachine(void);
void cMachine_ShowLoadingScreen(void* app, const char* text, int n);
int cPopulation_SeekBlock(PopReader_3510* r, int tag);
void nGobjManager_AddGOBJ(void* p);
void* cGameGOBJ_ctor(void* p, int h, PopReader_3510* r, int kind);
void* cPathedGOBJ_ctor(void* p, int h, PopReader_3510* r);
void* cElevatorGOBJ_ctor(void* p, int h, PopReader_3510* r);
void* cFacingGOBJ_ctor(void* p, int h, PopReader_3510* r);
void* cInteractGOBJ_ctor(void* p, int h, PopReader_3510* r);
}

static inline void* GAlloc(int size, int line)
{
    void* p;
    {
        AllocGuard g;
        p = cMemMan_Allocate(0, size, D_0049EE88, line);
    }
    return p;
}

extern "C" void cLoader_LoadGOBJs(void* l, PopReader_3510* r, int h)
{
    if ((unsigned char)cPopulation_SeekBlock(r, 0x3A424F47)) {
        int n;
        int i;
        int mis;
        n = *(int*)r->cur;
        r->cur += 4;
        if (n) {
            cMachine_ShowLoadingScreen(GetMachine(), "Initializing GOBJs...", 0);
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
                            t = cPathedGOBJ_ctor(t, h, r);
                        p = t;
                    }
                    break;
                case 3:
                    {
                        void* t = GAlloc(0x7A0, 0x187);
                        if (t)
                            t = cElevatorGOBJ_ctor(t, h, r);
                        p = t;
                    }
                    break;
                case 6:
                    {
                        void* t = GAlloc(0x94, 0x18B);
                        if (t)
                            t = cFacingGOBJ_ctor(t, h, r);
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
                nGobjManager_AddGOBJ(p);
            }
            mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
            if (mis)
                r->cur += 4 - mis;
        }
    }
}
static inline void merge_flush_func_001C3510(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C3510 */
