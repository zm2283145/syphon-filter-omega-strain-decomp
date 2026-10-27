/*
 * SFOGame/Source/hud_netlobby: 1 file, 0027B690
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0027B690 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct Raw_B690 { int p; };
extern "C" {
void cMemMan_Deallocate(int, void*, char*, int);
Raw_B690 std_list_deleter_voidPtr_begin_void(void*);
Raw_B690 std_list_GameInfoPtr_end(void*);
void std_list_GameInfoPtr_generic_iterator_ctor(char**, const Raw_B690&);
void cLListIterator_GameInfoPtr_ctor(char**, const Raw_B690&);
void cInterfaceElement_Destroy(void*);
void cInterface_dtor(void*, int);
void std_list_GameInfoPtr_dtor(void*, int);
void operator_delete(void*);
extern char D_004A9270;
}
extern "C" char* cHudNetLobby_dtor(char* self, short flag) {
    if (self) {
        char* end;
        {
            char* e;
            char* n;
            char* it;
            std_list_GameInfoPtr_generic_iterator_ctor(&it, std_list_deleter_voidPtr_begin_void(self + 0x2C));
            n = it;
            while ((cLListIterator_GameInfoPtr_ctor(&end, std_list_GameInfoPtr_end(self + 0x2C)), n != end)) {
                e = F_(n, 0x8, char*);
                {
                    AllocGuard g;
                    if (e) { if (F_(e, 0x14, void*)) cInterfaceElement_Destroy(F_(e, 0x14, void*)); }
                    cMemMan_Deallocate(0, e, &D_004A9270, 0x68);
                }
                n = F_(n, 0x4, char*);
            }
        }
        {
            char* p = F_(self, 0x0, char*);
            AllocGuard g;
            cInterface_dtor(p, -1);
            cMemMan_Deallocate(0, p, &D_004A9270, 0x6A);
        }
        if (self + 0x2C) std_list_GameInfoPtr_dtor(self + 0x2C, 0);
        if (flag > 0) operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_0027B690(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027B690 */
