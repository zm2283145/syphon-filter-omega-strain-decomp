#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct Raw_B690 { int p; };
extern "C" {
void Mem_Free(int, void*, char*, int);
Raw_B690 func_0013B180(void*);
Raw_B690 func_0027AC80(void*);
void func_0027AA80(char**, const Raw_B690&);
void func_0027AC70(char**, const Raw_B690&);
void func_003E8EB0(void*);
void func_003E79F0(void*, int);
void func_0027B880(void*, int);
void operator_delete(void*);
extern char D_004A9270;
}
extern "C" char* func_0027B690(char* self, short flag) {
    if (self) {
        char* end;
        {
            char* e;
            char* n;
            char* it;
            func_0027AA80(&it, func_0013B180(self + 0x2C));
            n = it;
            while ((func_0027AC70(&end, func_0027AC80(self + 0x2C)), n != end)) {
                e = F_(n, 0x8, char*);
                {
                    AllocGuard g;
                    if (e) { if (F_(e, 0x14, void*)) func_003E8EB0(F_(e, 0x14, void*)); }
                    Mem_Free(0, e, &D_004A9270, 0x68);
                }
                n = F_(n, 0x4, char*);
            }
        }
        {
            char* p = F_(self, 0x0, char*);
            AllocGuard g;
            func_003E79F0(p, -1);
            Mem_Free(0, p, &D_004A9270, 0x6A);
        }
        if (self + 0x2C) func_0027B880(self + 0x2C, 0);
        if (flag > 0) operator_delete(self);
    }
    return self;
}