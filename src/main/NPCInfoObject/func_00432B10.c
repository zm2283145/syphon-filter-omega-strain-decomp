#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct Raw_2B10 { int p; };
struct Ent_2B10 { int key; unsigned char b4, b5, b6, b7, b8, b9; char pad[6]; };
extern "C" {
void Mem_Free(int, void*, char*, int);
void func_00138DA0(int*, char*, int*);
Raw_2B10 func_0013B180(void*);
Raw_2B10 func_00432730(void*);
void func_00432740(char**, const Raw_2B10&);
void func_00432720(char**, const Raw_2B10&);
void func_0015AF40(int*, char**);
int func_004361C0(int*, int);
extern char D_004BFCA0;
extern char D_00582AF0;
}
#define Begin_2B10(o) func_00432740(o, func_0013B180(&D_00582AF0))
#define End_2B10(o) func_00432720(o, func_00432730(&D_00582AF0))
extern "C" void func_00432B10(int d0, Ent_2B10* tbl) {
    int k[1];
    char* end;
    {
        Ent_2B10* e;
        char* n;
        char* cur;
        char* it;
        Begin_2B10(&it);
        n = it;
        while ((End_2B10(&end), n != end)) {
            e = F_(n, 0x8, Ent_2B10*);
            cur = n;
            n = F_(n, 0x4, char*);
            k[0] = e->key;
            if (!func_004361C0(k, 0)) {
                int i;
                for (i = 0; i < 29; i++) if (tbl[i].key == -1) break;
                if (i < 29) {
                    Ent_2B10* t = &tbl[i];
                    t->key = e->key;
                    t->b4 = e->b4;
                    t->b5 = e->b5;
                    t->b6 = e->b6;
                    t->b7 = e->b7;
                    t->b8 = e->b8;
                    t->b9 = e->b9;
                    {
                        AllocGuard g;
                        Mem_Free(0, e, &D_004BFCA0, 0x6EC);
                    }
                    {
                        char* c;
                        int res;
                        int pos;
                        c = cur;
                        func_0015AF40(&pos, &c);
                        func_00138DA0(&res, &D_00582AF0, &pos);
                    }
                }
            }
        }
    }
}