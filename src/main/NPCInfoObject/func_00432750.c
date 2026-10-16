#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct Raw_2750 { int p; };
struct Ent_2750 { int key; unsigned char b4; unsigned char b5; char pad[10]; };
extern "C" {
void Mem_Free(int, void*, char*, int);
void List_Erase(int*, char*, int*);
Raw_2750 List_Begin(void*);
Raw_2750 func_00432730(void*);
void func_00432740(char**, const Raw_2750&);
void func_00432720(char**, const Raw_2750&);
void func_0015AF40(int*, char**);
extern char D_004BFCA0;
extern char D_00582B10;
}
#define Begin_2750(o) func_00432740(o, List_Begin(&D_00582B10))
#define End_2750(o) func_00432720(o, func_00432730(&D_00582B10))
extern "C" void func_00432750(int d0, Ent_2750* tbl, int key) {
    char* end;
    {
        char* e;
        char* n;
        char* cur;
        char* it;
        Begin_2750(&it);
        n = it;
        while ((End_2750(&end), n != end)) {
            Ent_2750* f;
            e = F_(n, 0x8, char*);
            cur = n;
            n = F_(n, 0x4, char*);
            f = 0;
            if (key == F_(e, 0x10, int)) {
                int i; for (i = 0; i != 29; i++) if (tbl[i].key == F_(e, 0x0, int)) { f = &tbl[i]; break; }
                if (f) {
                    f->b4 = F_(e, 0x4, unsigned char);
                    f->b5 = F_(e, 0x5, unsigned char);
                }
                {
                    AllocGuard g;
                    Mem_Free(0, e, &D_004BFCA0, 0x74F);
                }
                {
                    char* c;
                    int res;
                    int pos;
                    c = cur;
                    func_0015AF40(&pos, &c);
                    List_Erase(&res, &D_00582B10, &pos);
                }
            }
        }
    }
}