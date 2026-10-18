#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct Raw_8E20 { int p; };
struct Ent_8E20 { int key; unsigned char lo : 4; unsigned char hi : 4; char pad[3]; };
extern "C" {
void Mem_Free(int, void*, char*, int);
void List_Erase(int*, char*, int*);
Raw_8E20 List_Begin(void*);
Raw_8E20 func_00438E00(void*);
void func_00438E10(char**, const Raw_8E20&);
void func_00438DF0(char**, const Raw_8E20&);
void func_0015AF40(int*, char**);
void func_0043B190(int*);
extern char D_005838B8;
extern char D_004BFD60[];
}
#define Begin_8E20(o) func_00438E10(o, List_Begin(&D_005838B8))
#define End_8E20(o) func_00438DF0(o, func_00438E00(&D_005838B8))
extern "C" void func_00438E20(Ent_8E20* tbl) {
    int ctx;
    char* end;
    {
        char* e; Ent_8E20* t; char* n; char* cur; char* it;
        Begin_8E20(&it);
        n = it;
        while ((End_8E20(&end), n != end)) {
            int i;
            e = F_(n, 0x8, char*);
            cur = n;
            n = F_(n, 0x4, char*);
            {
                /* t is not reset per entry: retail keeps the previous entry's match when the key is absent */
                { i = 0; do { if (tbl[i].key == F_(e, 0x0, int)) { t = &tbl[i]; break; } } while (++i != 55); }
                if (!t) {
                    func_0043B190(&ctx);
                    {
                        int key = ((Ent_8E20*)e)->key;
                        unsigned char lo = ((Ent_8E20*)e)->lo;
                        int j;
                        for (j = 0; j < 55; j++) if (tbl[j].key == -1) break;
                        if (j < 55) { Ent_8E20* u = &tbl[j]; u->key = key; u->lo = lo; }
                    }
                }
            }
            {
                AllocGuard g;
                Mem_Free(0, e, D_004BFD60, 0x2FD);
            }
            {
                char* c;
                int res;
                int pos;
                c = cur;
                func_0015AF40(&pos, &c);
                List_Erase(&res, &D_005838B8, &pos);
            }
        }
    }
}