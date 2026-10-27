/*
 * SFOGame/Source/GuiOmegaStrain: 2 files, 0034EDF0-0034EF00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0034EDF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"

enum { MODE_0, MODE_1, MODE_2 };

typedef struct { int id; char pad4[4]; unsigned char state; char pad9[0x1C - 9]; } EEDF0;

struct LEDF0 {
    int a0;
    int count;
    EEDF0* data;
    unsigned char aC;
    int size() const { return count; }
};

typedef struct { char pad0[0x48]; void* tbl; } OEDF0;

extern "C" char g_Game[];
extern "C" void func_00296F20(LEDF0* l);
extern "C" void std_vector_deleter_tRequirementInfo_dtor(LEDF0* l, int flags);
extern "C" void* cGameSystem_GetAgentData(void* list, int idx);
extern "C" void cAgentData_GetRequirements(void* ag, int a, int b, LEDF0* l);
extern "C" int nGlobalization_GetString_charP(const char* key);
extern "C" void GuiTextListWidget_AddItem(void* t, int id, int i, int mode);

extern "C" void GuiOmegaStrain_PopulateList(OEDF0* self)
{
    void* ag = cGameSystem_GetAgentData(g_Game, -1);
    LEDF0 l;
    int text;
    int i;
    func_00296F20(&l);
    l.aC = 1;
    cAgentData_GetRequirements(ag, 4, 0, &l);
    text = nGlobalization_GetString_charP("Classified");
    for (i = 0; i < l.size(); i++) {
        EEDF0* e = (EEDF0*)((int)l.data + i * sizeof(EEDF0));
        int id = text;
        int mode;
        if (e->state == 0) {
            mode = MODE_2;
        } else {
            id = e->id;
            mode = e->state == 2 ? MODE_0 : MODE_1;
        }
        GuiTextListWidget_AddItem(self->tbl, id, i, mode);
    }
    std_vector_deleter_tRequirementInfo_dtor(&l, 0);
}
static inline void merge_flush_func_0034EDF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034EDF0 */

/* merge_units: begin func_0034EF00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiOmegaStrain message handler (vtable D_004DEDE0 slot 13).
 */

#include "loose03_types.h"

extern int GuiPersonnelScreen_onMessage(GuiPersonnelScreen* self, int a1, int msg, int value, int t0);

/* Forwards to the GuiPersonnelScreen handler. */
int GuiOmegaStrain_onMessage(GuiPersonnelScreen* self, int a1, int msg, int value, int t0) {
    return GuiPersonnelScreen_onMessage(self, a1, msg, value, t0);
}
static inline void merge_flush_func_0034EF00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034EF00 */
