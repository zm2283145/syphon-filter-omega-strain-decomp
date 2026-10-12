#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class LP_8290 {
public:
    VPAD2(a)
    virtual void SetSource(void* src);
};
extern "C" {
LP_8290* LosProvider_Get(void);
void LosProvider_ClearExclusions(LP_8290* lp, int a);
void LosProvider_AddExclusion(LP_8290* lp, void* obj);
void Los_TraceImmediate(void* a, void* b, void* c, void* d, LP_8290* lp, int g, unsigned char h, unsigned char i, int j, unsigned char k);
}
extern "C" void LosMgr_TraceBullet(void* unused, void* a, void* b, void* c, void* d, void* e1, void* e2, int g, unsigned char h, unsigned char i, int j, unsigned char k)
{
    LP_8290* lp = LosProvider_Get();
    lp->SetSource(c);
    LosProvider_ClearExclusions(lp, 0);
    if (e1)
        LosProvider_AddExclusion(lp, e1);
    if (e2)
        LosProvider_AddExclusion(lp, e2);
    Los_TraceImmediate(a, b, c, d, lp, g, h, i, j, k);
}