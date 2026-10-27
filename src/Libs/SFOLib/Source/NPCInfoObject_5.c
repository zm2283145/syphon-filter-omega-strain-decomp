/*
 * Libs/SFOLib/Source/NPCInfoObject: 1 file, 00432B10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00432B10 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct Raw_2B10 { int p; };
struct Ent_2B10 { int key; unsigned char b4, b5, b6, b7, b8, b9; char pad[6]; };
extern "C" {
void cMemMan_Deallocate(int, void*, char*, int);
void std_list_deleter_voidPtr_erase_listdeleter(int*, char*, int*);
Raw_2B10 std_list_deleter_voidPtr_begin_void(void*);
Raw_2B10 std_list_tNPCInfoPtr_end(void*);
void std_list_tNPCInfoPtr_generic_iterator_ctor(char**, const Raw_2B10&);
void cLListIterator_tNPCInfoPtr_ctor(char**, const Raw_2B10&);
void std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(int*, char**);
int cNPCInfoObject_Find(int*, int);
extern char D_004BFCA0;
extern char D_00582AF0;
}
#define Begin_2B10(o) std_list_tNPCInfoPtr_generic_iterator_ctor(o, std_list_deleter_voidPtr_begin_void(&D_00582AF0))
#define End_2B10(o) cLListIterator_tNPCInfoPtr_ctor(o, std_list_tNPCInfoPtr_end(&D_00582AF0))
extern "C" void cNPCInfoObject_DoPendingAdds(int d0, Ent_2B10* tbl) {
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
            if (!cNPCInfoObject_Find(k, 0)) {
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
                        cMemMan_Deallocate(0, e, &D_004BFCA0, 0x6EC);
                    }
                    {
                        char* c;
                        int res;
                        int pos;
                        c = cur;
                        std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&pos, &c);
                        std_list_deleter_voidPtr_erase_listdeleter(&res, &D_00582AF0, &pos);
                    }
                }
            }
        }
    }
}
static inline void merge_flush_func_00432B10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00432B10 */
