#include "types.h"
/* NpcAi_ModeAlert: alert-mode message handler (pick cover or firing position, react to route events) */
typedef union Pt1MaMode { struct { short state; short sub; } s; int w; } Pt1MaMode;
typedef struct Pt1MaMsg { char pad[0x24]; unsigned char kind; } Pt1MaMsg;
typedef struct Pt1MaRoute { char pad[0x5C]; int node; } Pt1MaRoute;
typedef struct Pt1MaOwner { char pad[0x3524]; void* weapons; } Pt1MaOwner;
typedef struct Pt1MaSelf {
    char pad0[0x30];
    Pt1MaOwner* owner;
    char pad34[0x44 - 0x34];
    char brain[0x6C - 0x44];
    float aggression;
    char pad70[0xE8 - 0x70];
    int alertTimer;
    char padEC[0x110 - 0xEC];
    Pt1MaMode mode;
    char pad114[0x158 - 0x114];
    unsigned char hasCover;
    char pad159[0x1AC - 0x159];
    void* target;
    Pt1MaRoute* route;
} Pt1MaSelf;
extern int D_004EE550;
extern int D_004ED9B8;
extern int* Event_GetType(void* ev);
extern int func_00142B50(void* weapons);
extern void* func_00156F50(void* target);
extern float func_0016C730(void* target, void* other);
extern unsigned char func_00150150(Pt1MaSelf* self);
extern unsigned char func_0014FEC0(Pt1MaSelf* self);
extern int func_001552B0(Pt1MaSelf* self);
extern void func_0016E170(void* brain, int event, int arg);

static inline Pt1MaMode Pt1Ma_Mode(short state, short sub)
{
    Pt1MaMode m;
    m.s.state = state;
    m.s.sub = sub;
    return m;
}
static inline float Pt1Ma_TargetDist(void* target)
{
    float d;
    if (func_00156F50(target) == 0)
        d = 0.0f;
    else
        d = func_0016C730(target, func_00156F50(target));
    return d;
}
static inline unsigned char Pt1Ma_HasCover(Pt1MaSelf* self)
{
    unsigned char r = 1;
    if (!self->hasCover)
        r = 0;
    return r;
}

unsigned char func_00156D00(Pt1MaSelf* self, Pt1MaMsg* msg)
{
    unsigned char handled = 0;
    int type = *Event_GetType(msg);
    if (type == D_004EE550) {
        unsigned char k = msg->kind;
        if (k == 0 || k == 3) {
            if (self->route->node >= 0) {
                void* target;
                float reach;
                float dist;
                reach = self->aggression * (float)func_00142B50(self->owner->weapons);
                target = self->target;
                dist = Pt1Ma_TargetDist(target);
                if (!(dist <= reach)) {
                    func_00150150(self);
                    { Pt1MaMode m; m.s.state = 1; m.s.sub = 2; self->mode.w = m.w; }
                } else if (self->aggression < 0.9f) {
                    func_0014FEC0(self);
                    { Pt1MaMode m; m.s.state = 1; m.s.sub = 3; self->mode.w = m.w; }
                } else if (Pt1Ma_HasCover(self)) {
                    func_0016E170(self->brain, 4, 0);
                }
            }
            handled = 1;
        }
    } else {
      type = *Event_GetType(msg);
      if (type == D_004ED9B8) {
        unsigned char k = msg->kind;
        if (k == 2) {
            if (self->mode.s.state == 1)
                func_0016E170(self->brain, self->mode.s.sub, 0);
        } else if (k == 1 || k == 3) {
            if (func_001552B0(self))
                func_0016E170(self->brain, 5, 0);
            else
                self->alertTimer = 0x3C;
        } else if (k == 5 || k == 6) {
            self->alertTimer = 1;
        }
      }
    }
    return handled;
}