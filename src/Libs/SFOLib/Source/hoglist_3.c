/*
 * Libs/SFOLib/Source/hoglist: 1 file, 003F96E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F96E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
extern "C" {
typedef struct { char pad[0x14C]; unsigned char active; char pad2[0x168 - 0x14D]; unsigned char keep; char pad3[3]; } O96E0;
typedef struct N96E0 { struct N96E0* prev; struct N96E0* next; O96E0 obj; } N96E0;
typedef struct { int m0; N96E0* list; } T96E0;
extern N96E0* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(void* list);
extern void* std_list_deleter_cHogFile_tail(void* self);
extern void std_list_deleter_cHogFile_generic_iterator_ctor(N96E0** out, void* v);
extern int String_CompareNoCase(const char* a, const char* b);
extern int cHogFile_OpenHog(O96E0* o, const char* name, unsigned char stream, int pool);
extern void cHogFile_ctor(O96E0* o);
extern void cHogFile_dtor(O96E0* o, int f);
extern void std_list_deleter_cHogFile_insert(N96E0** out, T96E0* self, void* pos, O96E0* v);
}
/* the enum ternary into the unsigned char parameter gives li/movz/andi */
enum ArchiveLoadMode { ARCHIVE_RESIDENT, ARCHIVE_STREAMED };

/*
 * Find the archive called name (case-insensitive) in the list; (re)load it
 * when it is not loaded in the requested mode. Otherwise append a new entry
 * at the front of the list, load it and clear its keep flag.
 */
extern "C" O96E0* cHogList_Open(T96E0* self, const char* name, int stream, int pool)
{
    N96E0* e;
    N96E0* n;
    O96E0 tmp;
    N96E0* r;
    void* pos;
    O96E0* o;
    for (n = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(&self->list)->next; std_list_deleter_cHogFile_generic_iterator_ctor(&e, std_list_deleter_cHogFile_tail(self)), n != e; n = n->next) {
        if (!String_CompareNoCase((char*)&n->obj, name)) {
            if (stream ? !(n->obj.active == 2) : !(n->obj.active != 0))
                cHogFile_OpenHog(&n->obj, name, stream ? ARCHIVE_STREAMED : ARCHIVE_RESIDENT, pool);
            return &n->obj;
        }
    }
    cHogFile_ctor(&tmp);
    pos = &self->list;
    std_list_deleter_cHogFile_insert(&r, self, &pos, &tmp);
    cHogFile_dtor(&tmp, -1);
    o = &self->list->obj;
    cHogFile_OpenHog(o, name, stream ? ARCHIVE_STREAMED : ARCHIVE_RESIDENT, pool);
    o->keep = 0;
    return o;
}
static inline void merge_flush_func_003F96E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F96E0 */
