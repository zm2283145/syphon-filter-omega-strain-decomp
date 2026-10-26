/*
 * main/tank: 2 files, 00288510-00288670
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00288510 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_strength_reduction off
#include "types.h"
struct Vec_288510 { int m0; int size; char** data; unsigned char owns; int Size() const { return size; } };
struct Mc_288510 { char pad[0x59D]; unsigned char a; unsigned char b; unsigned char c; };
struct Wrap_288510 { Mc_288510* p; };
extern "C" {
extern Wrap_288510 g_MemCard;
extern char D_00499C70[];
Vec_288510* std_vector_charPtr_ctor_void_2(Vec_288510* v);
void std_vector_charPtr_dtor_void_2(Vec_288510* v, short del);
void MemCardWrap_Enumerate(Wrap_288510* o, Vec_288510* v);
char** std_vector_charPtr_opIndex_uint_2(Vec_288510* v, int i);
char* strchr(const char* s, int c);
int AgentFile_DecodeName(const unsigned char* in, char* out, int* digit, int max);
}
extern "C" unsigned char GuiTitleScreen_SavedAgentExists(void)
{
    Wrap_288510* w = &g_MemCard;
    unsigned char ok = (w->p->a && w->p->b) && w->p->c;
    if (ok) {
        Vec_288510 v;
        char name[16];
        int digit;
        int i;
        ok = 0;
        std_vector_charPtr_ctor_void_2(&v);
        v.owns = 1;
        MemCardWrap_Enumerate(w, &v);
        for (i = 0; i < v.Size(); i++) {
            if (!strchr(v.data[i], '.') && ((D_00499C70 + 1)[**std_vector_charPtr_opIndex_uint_2(&v, i)] & 4) &&
                AgentFile_DecodeName((unsigned char*)v.data[i], name, &digit, 0x10)) {
                ok = 1;
                break;
            }
        }
        std_vector_charPtr_dtor_void_2(&v, -1);
    }
    return ok;
}
#pragma pop /* merge_units */
/* merge_units: end func_00288510 */

/* merge_units: begin func_00288670 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(cArray_charPtr_dtor_void_2, std_vector_imp_charPtr_1_dtor_void_2)
#pragma pop /* merge_units */
/* merge_units: end func_00288670 */
