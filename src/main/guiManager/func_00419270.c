#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct VC_9270 { virtual int v0(int); };
struct Raw_9270 { int p; };
extern "C" {
void Mem_Free(int, void*, char*, int);
void ObjectList_EraseRange(int*, char*, char**, char**);
Raw_9270 func_0013B180(void*);
Raw_9270 func_0028C0A0(void*);
void func_0028C0B0(char**, const Raw_9270&);
void func_0028C090(char**, const Raw_9270&);
void func_004193D0(char*, VC_9270*);
extern char D_004BF138;
}
#pragma opt_common_subs off
extern "C" void func_00419270(char* self) {
    if (F_(self, 0x20, int) != 0) {
        char* end;
        {
            char* n;
            char* it;
            func_0028C0B0(&it, func_0013B180(self + 0x20));
            n = it;
            while ((func_0028C090(&end, func_0028C0A0(self + 0x20)), n != end)) {
                VC_9270* e;
                func_004193D0(self, F_(n, 0x8, VC_9270*));
                e = F_(n, 0x8, VC_9270*);
                {
                    AllocGuard g;
                    e->v0(-1);
                    Mem_Free(0, e, &D_004BF138, 0x53);
                }
                n = F_(n, 0x4, char*);
            }
        }
        {
            int res;
            char* first;
            char* last;
            last = self + 0x24;
            first = F_(self, 0x28, char*);
            ObjectList_EraseRange(&res, self + 0x20, &first, &last);
        }
    }
}