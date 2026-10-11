#include "types.h"
typedef struct {
    void* vtable;
    char base[0x1C];
    unsigned char b20;  /* 0x20 */
    char pad21[3];
    int action;         /* 0x24 */
    unsigned char b28;  /* 0x28 */
} NavDirMsg_h5;
extern char D_0055D480[];
extern char D_004E0840[];
extern void Event_Construct(NavDirMsg_h5* msg, void* name);
extern void Event_Send(NavDirMsg_h5* msg, void* target, int flags);
extern void cMessage_dtor(NavDirMsg_h5* msg, int flags);

static inline float h5_fabs(float x) { float r; asm { abs.s r, x } return r; }
int func_00476490(void* actor, float* dir)
{
    float x = dir[0];
    signed char action = -1;
    if (h5_fabs(x) < 0.5f) {
        if (dir[2] < 0.0f) {
            action = 0x1F;
        } else if (!(dir[2] <= 0.0f)) {
            action = 0x20;
        }
    } else if (x < 0.0f) {
        action = 0x21;
    } else {
        action = 0x22;
    }
    if (action != -1) {
        NavDirMsg_h5 msg;
        Event_Construct(&msg, D_0055D480);
        msg.vtable = D_004E0840;
        msg.action = action;
        msg.b20 = 1;
        msg.b28 = 0;
        Event_Send(&msg, actor, 1);
        msg.vtable = D_004E0840;
        cMessage_dtor(&msg, 0);
        return 1;
    }
    return 0;
}