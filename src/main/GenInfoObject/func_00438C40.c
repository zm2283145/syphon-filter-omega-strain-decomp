#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct Raw_8C40 { int p; };
struct Ent_8C40 { int key; unsigned char lo : 4; unsigned char hi : 4; char pad[3]; };
extern "C" {
void Mem_Free(int, void*, char*, int);
void List_Erase(int*, char*, int*);
Raw_8C40 List_Begin(void*);
Raw_8C40 std_list_tGenInfoPtr_end(void*);
void std_list_tGenInfoPtr_generic_iterator_ctor(char**, const Raw_8C40&);
void cLListIterator_tGenInfoPtr_ctor(char**, const Raw_8C40&);
void std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(int*, char**);
extern char D_005838D8;
}
#define Begin_8C40(o) std_list_tGenInfoPtr_generic_iterator_ctor(o, List_Begin(&D_005838D8))
#define End_8C40(o) cLListIterator_tGenInfoPtr_ctor(o, std_list_tGenInfoPtr_end(&D_005838D8))
extern "C" void cGenInfoObject_DoPendingOwner(Ent_8C40* tbl) {
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
                Mem_Free(0, e, "GenInfoObject.cc", 0x32A);
            }
            {
                char* c;
                int res;
                int pos;
                c = cur;
                std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&pos, &c);
                List_Erase(&res, &D_005838D8, &pos);
            }
        }
    }
}