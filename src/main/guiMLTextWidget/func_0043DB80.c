#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct Raw_DB80 { int p; };
extern "C" {
void Mem_Free(int, void*, char*, int);
void ObjectList_EraseRange(int*, void*, char**, char**);
Raw_DB80 func_0013B180(void*);
Raw_DB80 func_0043DB60(void*);
void func_0043DB70(char**, const Raw_DB80&);
void func_0043DB50(char**, const Raw_DB80&);
void func_0043BC70(void*, int, int, int, int);
extern char D_004C0110;
}
struct S_DB80 { char pad[0x64]; int f64; int f68; int f6C; int f70; int f74; int f78; void* f7C; };
static inline void Upd_DB80(S_DB80* s) { func_0043BC70(s->f7C, 0, s->f68, 0, s->f70 - s->f64); }
extern "C" void func_0043DB80(char* self) {
    {
        char* end;
        {
            char* n;
            char* it;
            func_0043DB70(&it, func_0013B180(self + 0x70));
            n = it;
            while ((func_0043DB50(&end, func_0043DB60(self + 0x70)), n != end)) {
                void* e = F_(n, 0x8, void*);
                {
                    AllocGuard g;
                    Mem_Free(0, e, &D_004C0110, 0xCB);
                }
                n = F_(n, 0x4, char*);
            }
        }
        {
            int res;
            char* first;
            char* last;
            last = self + 0x74;
            first = F_(self, 0x78, char*);
            ObjectList_EraseRange(&res, self + 0x70, &first, &last);
        }
    }
    S_DB80* s = (S_DB80*)self;
    s->f68 = 0;
    if (s->f7C) func_0043BC70(s->f7C, 0, s->f68, 0, s->f70 - s->f64);
}