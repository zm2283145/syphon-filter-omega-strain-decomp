#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct Raw_8C40 { int p; };
struct Ent_8C40 { int key; unsigned char lo : 4; unsigned char hi : 4; char pad[3]; };
extern "C" {
void Mem_Free(int, void*, char*, int);
void func_00138DA0(int*, char*, int*);
Raw_8C40 func_0013B180(void*);
Raw_8C40 func_00438E00(void*);
void func_00438E10(char**, const Raw_8C40&);
void func_00438DF0(char**, const Raw_8C40&);
void func_0015AF40(int*, char**);
extern char D_004BFD60;
extern char D_005838D8;
}
#define Begin_8C40(o) func_00438E10(o, func_0013B180(&D_005838D8))
#define End_8C40(o) func_00438DF0(o, func_00438E00(&D_005838D8))
extern "C" void func_00438C40(Ent_8C40* tbl) {
    char* end;
    {
        char* e;
        char* n;
        char* cur;
        char* it;
        Begin_8C40(&it);
        n = it;
        while ((End_8C40(&end), n != end)) {
            int i;
            e = F_(n, 0x8, char*);
            cur = n;
            n = F_(n, 0x4, char*);
            for (i = 0; i < 55; i++) if (F_(e, 0x0, int) == tbl[i].key) break;
            if (i < 55) { Ent_8C40* t = &tbl[i]; t->lo = ((Ent_8C40*)e)->lo; }
            {
                AllocGuard g;
                Mem_Free(0, e, &D_004BFD60, 0x32A);
            }
            {
                char* c;
                int res;
                int pos;
                c = cur;
                func_0015AF40(&pos, &c);
                func_00138DA0(&res, &D_005838D8, &pos);
            }
        }
    }
}