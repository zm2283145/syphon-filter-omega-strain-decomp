/*
 * SFOGame/Source/GuiSaveAgentWidget: 2 files, 004422D0-00442450
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004422D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_strength_reduction off
#include "types.h"
struct Vec_4422D0 { int m0; int size; char** data; unsigned char owns; int Size() const { return size; } };
struct Mc_4422D0 { char pad[0x59D]; unsigned char a; unsigned char b; unsigned char c; };
struct Wrap_4422D0 { Mc_4422D0* p; };
extern "C" {
extern Wrap_4422D0 g_MemCard;
extern char D_00499C70[];
Vec_4422D0* std_vector_charPtr_ctor_void_2(Vec_4422D0* v);
void std_vector_charPtr_dtor_void_2(Vec_4422D0* v, short del);
void cMemCard_GetFilenames(Wrap_4422D0* o, Vec_4422D0* v);
char** std_vector_charPtr_opIndex_uint_2(Vec_4422D0* v, int i);
char* strchr(const char* s, int c);
int AgentFile_DecodeName(const unsigned char* in, char* out, int* digit, int max);
int strcmp(const char* a, const char* b);
void Libc_Strcpy(char* d, const char* s);
}
extern "C" int SaveAgentWidget_FindSlotFile(int slot, const char* want, char* out)
{
    Vec_4422D0 v;
    char name[16];
    int digit;
    int i;
    std_vector_charPtr_ctor_void_2(&v);
    v.owns = 1;
    cMemCard_GetFilenames(&g_MemCard, &v);
    for (i = 0; i < v.Size(); i++) {
        if (!strchr(v.data[i], '.') && ((D_00499C70 + 1)[**std_vector_charPtr_opIndex_uint_2(&v, i)] & 4) &&
            AgentFile_DecodeName((unsigned char*)v.data[i], name, &digit, 0x10)) {
            if ((!want || strcmp(name, want)) && slot == digit) {
                if (out) Libc_Strcpy(out, v.data[i]);
                std_vector_charPtr_dtor_void_2(&v, -1);
                return 1;
            }
        }
    }
    std_vector_charPtr_dtor_void_2(&v, -1);
    return 0;
}
static inline void merge_flush_func_004422D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004422D0 */

/* merge_units: begin func_00442450 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_new.h"

/* Factory: allocate, run the base constructor, set the vtable and mode. */
extern "C" { char D_004C0588[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_VT_INT(ConcreteWidgetClassRep_GuiSaveAgentWidget_Create, 0x78, D_004C0588, GuiWidget_ctor, D_004E1220, 0x48, -2)
static inline void merge_flush_func_00442450(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00442450 */
