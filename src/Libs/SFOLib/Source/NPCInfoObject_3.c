/*
 * Libs/SFOLib/Source/NPCInfoObject: 1 file, 00432750
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00432750 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct Raw_2750 { int p; };
struct Ent_2750 { int key; unsigned char b4; unsigned char b5; char pad[10]; };
extern "C" {
void cMemMan_Deallocate(int, void*, char*, int);
void std_list_deleter_voidPtr_erase_listdeleter(int*, char*, int*);
Raw_2750 std_list_deleter_voidPtr_begin_void(void*);
Raw_2750 std_list_tNPCInfoPtr_end(void*);
void std_list_tNPCInfoPtr_generic_iterator_ctor(char**, const Raw_2750&);
void cLListIterator_tNPCInfoPtr_ctor(char**, const Raw_2750&);
void std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(int*, char**);
extern char D_004BFCA0;
extern char D_00582B10;
}
#define Begin_2750(o) std_list_tNPCInfoPtr_generic_iterator_ctor(o, std_list_deleter_voidPtr_begin_void(&D_00582B10))
#define End_2750(o) cLListIterator_tNPCInfoPtr_ctor(o, std_list_tNPCInfoPtr_end(&D_00582B10))
extern "C" void cNPCInfoObject_DoPendingOwnership(int d0, Ent_2750* tbl, int key) {
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
                    cMemMan_Deallocate(0, e, &D_004BFCA0, 0x74F);
                }
                {
                    char* c;
                    int res;
                    int pos;
                    c = cur;
                    std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&pos, &c);
                    std_list_deleter_voidPtr_erase_listdeleter(&res, &D_00582B10, &pos);
                }
            }
        }
    }
}
static inline void merge_flush_func_00432750(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00432750 */
