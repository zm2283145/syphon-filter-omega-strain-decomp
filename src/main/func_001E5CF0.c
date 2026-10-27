#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class Ctl5CF0 {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int Check54();
    virtual int Check58(void* o);
};
typedef struct { char pad[0x4C]; int kind; char pad50[0x58 - 0x50]; Ctl5CF0* ctl; char pad5C[0x346D - 0x5C]; unsigned char inWater; } O_5CF0;
typedef struct { char pad[0x38]; float level; } W_5CF0;
typedef struct { int pad0; O_5CF0* obj; char pad8[0xE4 - 8]; float depth; char padE8[0x170 - 0xE8]; W_5CF0 water; } A_5CF0;
extern "C" {
void cWaterFx_AddBody_cGOBJP_float(float, int, O_5CF0*);
void cWaterFx_RemoveBody(int, O_5CF0*);
void cWaterFx_ChangeWaterHeight(float, int, O_5CF0*);
}
extern float g_NegFltMax;
extern int D_004FFC34;
extern int g_HumanActorClassKey;
static inline unsigned char C54(O_5CF0* o) { unsigned char r = 0; Ctl5CF0* c = o->ctl; if (c && c->Check54()) r = 1; return r; }
#pragma opt_common_subs off
static inline unsigned char IsDeep(A_5CF0* a, float d) {
    unsigned char r = 0;
    float k = g_NegFltMax;
    if (d != g_NegFltMax) {
        W_5CF0* w = (d != k) ? &a->water : 0;
        if (!(w->level <= 0.974f)) r = 1;
    }
    return r;
}
static inline unsigned char Left(int was, int is) { unsigned char r = 0; if (was) { int ok = (is != 0) ^ 1; if (ok) r = 1; } return r; }
static inline unsigned char Moved(int was, int is, float p, float d) { unsigned char r = 0; int ok = was != 0; ok = ok ? is != 0 : ok; if (ok && p != d) r = 1; return r; }
extern "C" void cHumanCollisionRoutine_HandleWaterCollisionIfDetected(A_5CF0* a, float prev)
{
    float d = a->depth;
    int wasIn, isIn; unsigned char left, moved;
    O_5CF0* o;
    d = IsDeep(a, d) ? d : -3.4028235e38f;
    wasIn = prev != -3.4028235e38f;
    isIn = d != -3.4028235e38f;
    left = Left(wasIn, isIn);
    moved = Moved(wasIn, isIn, prev, d);
    o = 0;
    { O_5CF0* ob = a->obj; if (ob->kind == g_HumanActorClassKey) { unsigned char ok = 0; Ctl5CF0* c = ob->ctl; if (c && c->Check58(ob)) ok = 1; if (ok || C54(a->obj)) o = a->obj; } }
    if (o) o->inWater = isIn;
    if (isIn) {
        cWaterFx_AddBody_cGOBJP_float(d, D_004FFC34, a->obj);
        if (moved) cWaterFx_ChangeWaterHeight(d, D_004FFC34, a->obj);
    } else if (left) {
        cWaterFx_RemoveBody(D_004FFC34, a->obj);
    }
}





