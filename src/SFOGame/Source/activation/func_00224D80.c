#pragma cplusplus on
#include "types.h"
/* nActivation_GetFirstTerrainPieceOnGobjList: first entry of the global list, or 0 when empty */
struct Pt1FlIt {
    int* p;
    bool operator==(const Pt1FlIt& o) const { return p == o.p; }
    bool operator!=(const Pt1FlIt& o) const { return !(*this == o); }
};
extern "C" {
extern void* D_004FFD48;
void* cObjList_cTerrainPtr_GetList(void* list);
void cArray_cTerrainPtr_Begin(Pt1FlIt* it, void* node);
void cArray_cTerrainPtr_End(Pt1FlIt* it, void* node);
}
extern "C" int nActivation_GetFirstTerrainPieceOnGobjList(void)
{
    void* list = D_004FFD48;
    Pt1FlIt b;
    Pt1FlIt e;
    int r;
    cArray_cTerrainPtr_Begin(&b, cObjList_cTerrainPtr_GetList(list));
    r = 0;
    cArray_cTerrainPtr_End(&e, cObjList_cTerrainPtr_GetList(list));
    if (b != e)
        r = *b.p;
    return r;
}