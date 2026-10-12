#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct Raw_69C0 { int p; };
extern "C" {
void Mem_Free(int, void*, char*, int);
void ObjectList_EraseRange(int*, void*, char**, char**);
Raw_69C0 func_0013B180(void*);
Raw_69C0 func_00256B20(void*);
void func_00256B30(char**, const Raw_69C0&);
void func_00256B10(char**, const Raw_69C0&);
extern int D_004F7F48;
extern char D_004F7F4C;
extern char* D_004F7F50;
}
#pragma opt_common_subs off
extern "C" void func_002569C0(void) {
    if (D_004F7F48 > 0) {
        char* end;
        {
            char* n;
            char* it;
            func_00256B30(&it, func_0013B180(&D_004F7F48));
            n = it;
            while ((func_00256B10(&end, func_00256B20(&D_004F7F48)), n != end)) {
                void* e = F_(n, 0x8, void*);
                {
                    AllocGuard g;
                    Mem_Free(0, e, "backpack.cc", 0x202);
                }
                n = F_(n, 0x4, char*);
            }
        }
        {
            int res;
            char* first;
            char* last;
            last = &D_004F7F4C;
            first = D_004F7F50;
            ObjectList_EraseRange(&res, &D_004F7F48, &first, &last);
        }
    }
}