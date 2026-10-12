#pragma cplusplus on
#include "types.h"
#include "vu0_ops.h"
typedef struct { void* vtable; char pad[0x20]; int kind; unsigned char b; char pad2[3]; } QtMsg;
typedef struct { char pad[0x38]; int state; char pad3C[0x24]; float v60[4]; char pad70[0xA4]; float t; unsigned char flag; } QtState;
typedef struct { float x; float y; } QtIn;
typedef struct { char pad[0xDC]; unsigned char busy; } QtSub;
typedef struct { char pad[0x320C]; int mode; char pad3210[0x100]; QtSub* sub; } QtPl;
extern char D_0055D480[];
extern char D_004E0840[];
extern float D_004A7580;
extern "C" void Event_Construct(QtMsg* m, void* type);
extern "C" void Event_Send(QtMsg* m, void* target, int immediate);
extern "C" void cMessage_dtor(QtMsg* m, int flags);
extern "C" void Curve_Retime1s(void* c, float f);
extern "C" void VecCurve_SetDuration(void* c, float f);
static inline bool QtBusy(QtPl* pl) {
    bool b = 0;
    if (pl->sub && pl->sub->busy) b = 1;
    return b;
}
extern "C" void Player_UpdateQuickTurn(QtState* q, QtIn* in, float dt, QtPl* pl, char* c)
{
    if ((q->state == 0 || q->state == 4) && !QtBusy(pl)) {
        if (in->y < 0.0f) {
            if (!(q->t <= 0.0f) || VU0_IsZero4(q->v60)) {
                q->t += dt;
                if (in->y < -0.75f)
                    q->flag = 1;
            } else {
                q->t = 0.0f;
                q->flag = 0;
            }
        } else if (!(in->y < 0.0f) && in->y < 0.5f) {
            if (!(q->t <= 0.0f) && q->t <= D_004A7580 && q->flag && pl->mode != 3) {
                QtMsg msg;
                Event_Construct(&msg, D_0055D480);
                msg.vtable = D_004E0840;
                msg.kind = 0xE;
                msg.b = 0;
                Event_Send(&msg, pl, 0);
                msg.vtable = D_004E0840;
                cMessage_dtor(&msg, 0);
                Curve_Retime1s(c + 0x210, 1.0f);
                VecCurve_SetDuration(c + 0x2E0, -1.0f);
                VecCurve_SetDuration(c + 0x3A0, -1.0f);
                Curve_Retime1s(c + 0x780, -1.0f);
                VecCurve_SetDuration(c + 0x910, -1.0f);
            }
            q->t = 0.0f;
            q->flag = 0;
        } else {
            q->t = 0.0f;
            q->flag = 0;
        }
    } else {
        q->t = 0.0f;
        q->flag = 0;
    }
}

