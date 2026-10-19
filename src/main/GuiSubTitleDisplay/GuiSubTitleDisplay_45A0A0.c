/*
 * main/GuiSubTitleDisplay: 3 files, 0045A0A0-0045A2A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0045A0A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "guarded_new.h"

/* Factory: allocate and construct. */
extern "C" { char D_004C1F28[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_CTOR(func_0045A0A0, 0x7C, D_004C1F28, GuiSubTitleDisplay_ctor)
#pragma pop /* merge_units */
/* merge_units: end func_0045A0A0 */

/* merge_units: begin func_0045A150 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Msg {
    int a;
    unsigned char b0, b1, b2, b3;
    float x, y, z;
    int d;
    unsigned char e0, e1;
    float f;
    int g;
    Msg() {}
};
struct Obj { char pad[0x59D]; unsigned char ready; };
struct Net { Obj* obj; unsigned char busy; };
extern "C" {
extern Net g_MemCard;
extern int D_004979A0;
extern Msg* Options_SetDefaults(Msg*);
extern int MemCardWrap_GetSize(Net*, int);
extern int MemCardWrap_Read(Net*, int, void*, int);
extern int GameOptions_Diff(Msg*, Msg*);
extern void GameOptions_Apply(Msg*, int);
int Options_Load(Msg* s);
}

int Options_Load(Msg* s)
{
    Net* n = &g_MemCard;
    Msg m;
    Options_SetDefaults(&m);
    if (((n->busy != 0) ^ 1) && n->obj->ready) {
        if (MemCardWrap_GetSize(n, D_004979A0) != sizeof(Msg)) {
            return 0;
        }
        if (MemCardWrap_Read(n, D_004979A0, &m, sizeof(Msg))) {
            int r;
            if (m.a != 1) {
                return 0;
            }
            r = GameOptions_Diff(s, &m);
            *s = m;
            GameOptions_Apply(s, r);
            return 1;
        }
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0045A150 */

/* merge_units: begin func_0045A2A0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
extern int MemCardWrap_Write(Net*, int, void*, int, int);
int GameOptions_WriteConfigFile(Msg* src);
}
int GameOptions_WriteConfigFile(Msg* src)
{
    Net* n = &g_MemCard;
    if (((n->busy != 0) ^ 1) && n->obj->ready) {
        Msg m(*src);
        int saved = m.g;
        int r;
        m.g = 0;
        r = MemCardWrap_Write(n, D_004979A0, &m, sizeof(Msg), 1);
        m.g = saved;
        return r != 0;
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0045A2A0 */
