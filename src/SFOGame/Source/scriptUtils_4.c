/*
 * SFOGame/Source/scriptUtils: 1 file, 00267860
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00267860 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "cmessage.h"
class Net_7860 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual int IsActive();
};
struct Obj_7860 { char pad[0x14]; unsigned char local; char pad15[0x58 - 0x15]; Net_7860* net; };
struct TimerMsg_7860 { CMSG_HEADER; float secs; int key; };
extern "C" {
extern char D_004F8580[];
extern char D_004DCB90[];
extern char D_004DCF10[];
extern char* g_Hud;
char* nGlobalization_GetString_charP(char* s);
int nGlobalization_GetStringIndex(char* s);
void cHud_cHudTimer_ScheduleExpiration(char* t, char* text, float time);
}
#pragma opt_propagation off
extern "C" void Global_SetPersonalTimer(Obj_7860* obj, char* text, float time)
{
    unsigned char net = 0;
    if (obj->net && obj->net->IsActive()) net = 1;
    if (net) {
        if (obj->local) {
            cHud_cHudTimer_ScheduleExpiration(g_Hud + 0x6AC, text ? nGlobalization_GetString_charP(text) : 0, time + *(float*)(g_Hud + 0x6DC));
        } else {
            TimerMsg_7860 m;
            TimerMsg_7860* p = &m;
            cMessage_ctor_cMessageNameR(p, D_004F8580);
            m.vtable = D_004DCB90;
            m.secs = time;
            p->key = nGlobalization_GetStringIndex(text);
            m.kind = 8;
            m.flags = 0x40;
            QueueMessage_cMessageR_cSystemP_int(p, obj, 0);
            m.vtable = D_004DCF10;
            cMessage_dtor(p, 0);
        }
    }
}
static inline void merge_flush_func_00267860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00267860 */
