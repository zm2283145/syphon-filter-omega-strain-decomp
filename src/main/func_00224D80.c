#pragma cplusplus on
#include "types.h"
/* TerrainList_GetFirst: first entry of the global list, or 0 when empty */
struct Pt1FlIt {
    int* p;
    bool operator==(const Pt1FlIt& o) const { return p == o.p; }
    bool operator!=(const Pt1FlIt& o) const { return !(*this == o); }
};
extern "C" {
extern void* D_004FFD48;
void* func_00224AB0(void* list);
void func_00224A80(Pt1FlIt* it, void* node);
void func_00224A90(Pt1FlIt* it, void* node);
}
extern "C" int TerrainList_GetFirst(void)
{
    void* list = D_004FFD48;
    Pt1FlIt b;
    Pt1FlIt e;
    int r;
    func_00224A80(&b, func_00224AB0(list));
    r = 0;
    func_00224A90(&e, func_00224AB0(list));
    if (b != e)
        r = *b.p;
    return r;
}