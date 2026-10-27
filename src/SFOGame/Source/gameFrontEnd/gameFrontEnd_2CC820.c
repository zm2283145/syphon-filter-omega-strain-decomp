/*
 * main/gameFrontEnd: range (2 files, 002CC820-002CC8E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"

/* merge_units: begin func_002CC820 */
#pragma push /* merge_units */
typedef struct { char name[0x40]; char desc[0x80]; int text; int index; unsigned char a; unsigned char b; } LevelC820;
extern char* D_0048C160[];
static const unsigned int dat_004ACB60[20] = { 0x0, 0x1, 0x2, 0xFFFFFFFF, 0x3, 0x4, 0xFFFFFFFF, 0xFFFFFFFF, 0x5, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x6, 0x7, 0xFFFFFFFF, 0xFFFFFFFF, 0x8, 0xFFFFFFFF, 0x0, 0x0 };
static const unsigned int dat_004ACBB0[8] = { 0x1000000, 0x10000, 0x10000, 0x1000000, 0x0, 0x0, 0x0, 0x0 };
static const unsigned int dat_004ACBD0[6] = { 0x1000000, 0x10000, 0x10000, 0x1000000, 0x0, 0x0 };
extern int D_00494198;
void MissionSelectData_SelectMission(LevelC820* o, int i)
{
    if (i >= 0 && i < 0x12) {
        Libc_Strcpy(o->name, D_0048C160[i]);
        o->text = ((int*)dat_004ACB60)[i];
        o->index = i;
        o->a = ((unsigned char*)dat_004ACBB0)[i];
        o->b = ((unsigned char*)dat_004ACBD0)[i];
        D_00494198 = i;
    } else {
        o->name[0] = 0;
        o->desc[0] = 0;
        o->text = -1;
        o->index = -1;
        o->a = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CC820(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CC820 */

/* merge_units: begin func_002CC8E0 */
#pragma push /* merge_units */
extern int String_CompareNoCase(const char* a, const char* b);
#if 0 /* merge_units */
extern void MissionSelectData_SelectMission(void* o, int i);
#endif /* merge_units */
#define MissionSelectData_SelectMission(a0, a1) (MissionSelectData_SelectMission((void *)(a0), (a1))) /* merge_units */

void MissionSelectData_SelectMissionByName(void* o, const char* name)
{
    int i;
    for (i = 0; i < 0x12; i++) {
        if (String_CompareNoCase(D_0048C160[i], name) == 0) {
            MissionSelectData_SelectMission(o, i);
            return;
        }
    }
    MissionSelectData_SelectMission(o, -1);
}
#undef MissionSelectData_SelectMission /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CC8E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CC8E0 */
