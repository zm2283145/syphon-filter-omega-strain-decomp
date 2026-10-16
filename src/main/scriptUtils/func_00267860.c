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
extern char* D_004FFC2C;
char* Loc_LookupText(char* s);
int Loc_FindKeyThunk(char* s);
void HudTimer_Start(char* t, char* text, float time);
}
#pragma opt_propagation off
extern "C" void Global_SetPersonalTimer(Obj_7860* obj, char* text, float time)
{
    unsigned char net = 0;
    if (obj->net && obj->net->IsActive()) net = 1;
    if (net) {
        if (obj->local) {
            HudTimer_Start(D_004FFC2C + 0x6AC, text ? Loc_LookupText(text) : 0, time + *(float*)(D_004FFC2C + 0x6DC));
        } else {
            TimerMsg_7860 m;
            TimerMsg_7860* p = &m;
            Event_Construct(p, D_004F8580);
            m.vtable = D_004DCB90;
            m.secs = time;
            p->key = Loc_FindKeyThunk(text);
            m.kind = 8;
            m.flags = 0x40;
            Event_Send(p, obj, 0);
            m.vtable = D_004DCF10;
            cMessage_dtor(p, 0);
        }
    }
}



