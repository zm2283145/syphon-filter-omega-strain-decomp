#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct Raw_2750 { int p; };
struct Ent_2750 { int key; unsigned char b4; unsigned char b5; unsigned char arr[10]; };
extern "C" {
void Mem_Free(int, void*, char*, int);
void func_00138DA0(int*, char*, int*);
Raw_2750 func_0013B180(void*);
Raw_2750 func_00432730(void*);
void func_00432740(char**, const Raw_2750&);
void func_00432720(char**, const Raw_2750&);
void func_0015AF40(int*, char**);
extern char D_00582B30;
extern unsigned char D_005721C0;
extern unsigned char D_005721C8;
}
#define Begin_2750(o) func_00432740(o, func_0013B180(&D_00582B30))
#define End_2750(o) func_00432720(o, func_00432730(&D_00582B30))
static inline unsigned char IsHost_2510() { if (D_005721C8) return D_005721C0; return 1; }
extern "C" void func_00432510(int d0, Ent_2750* tbl, int key) {
  if (IsHost_2510() && *(int*)&D_00582B30) {
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
                    if (f->b4 != 0xFF) { f->b4 = F_(e, 0x4, unsigned char); f->b5 = 0xFF; }
                    else f->b5 = F_(e, 0x4, unsigned char);
                    f->arr[F_(e, 0x5, unsigned char)] = 0;
                }
                {
                    AllocGuard g;
                    Mem_Free(0, e, "NPCInfoObject.cc", 0x78B);
                }
                {
                    char* c;
                    int res;
                    int pos;
                    c = cur;
                    func_0015AF40(&pos, &c);
                    func_00138DA0(&res, &D_00582B30, &pos);
                }
            }
        }
    }
}
}
