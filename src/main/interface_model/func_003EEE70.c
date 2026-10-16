#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct VC_EE70 { virtual int v0(int); };
struct Raw_EE70 { int p; };
extern "C" {
void Mem_Free(int, void*, char*, int);
void List_Erase(int*, char*, int*);
Raw_EE70 List_Begin(void*);
Raw_EE70 func_003ED850(void*);
void func_003EF000(char**, const Raw_EE70&);
void func_003ED860(char**, const Raw_EE70&);
void func_0015AF40(int*, char**);
}
extern "C" void func_003EEE70(char* self, VC_EE70* obj) {
    char* end;
    {
        VC_EE70* e;
        char* n;
        char* cur;
        char* it;
        func_003EF000(&it, List_Begin(self + 0x8C));
        n = it;
        while ((func_003ED860(&end, func_003ED850(self + 0x8C)), n != end)) {
            e = F_(n, 0x8, VC_EE70*);
            if (e == obj) {
                cur = n;
                n = F_(n, 0x4, char*);
                {
                    AllocGuard g;
                    e->v0(-1);
                    Mem_Free(0, e, "interface_model.cc", 0x218);
                }
                {
                    char* c;
                    int res;
                    int pos;
                    c = cur;
                    func_0015AF40(&pos, &c);
                    List_Erase(&res, self + 0x8C, &pos);
                }
            } else {
                n = F_(n, 0x4, char*);
            }
        }
    }
    if (F_(self, 0x8C, int) == 0) F_(self, 0x60, unsigned char) = 0;
}