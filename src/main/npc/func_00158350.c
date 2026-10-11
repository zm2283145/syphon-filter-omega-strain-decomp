#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "vslot_pad.h"
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
extern char D_0049B670[];
extern char D_0051EE58[];
extern char D_004DE110[];
extern unsigned char D_005721C8;
void Event_Construct(void* p, char* name);
void func_001584B0(void* p);
int func_0012F2B0(void* p);
int func_001584A0(int v);
void func_00148B50(void* p, void* npc);
void func_00158490(void* p, int v);
}
class Snd_8350 { public: VPAD16(a) VPAD4(b) virtual void Stop(); };
typedef struct { char pad[0x58]; Snd_8350* snd; } Ctl_8350;
typedef struct { char pad[0x30]; Ctl_8350* ctl; } NPC_8350;
typedef struct { void* vt; char pad[0x20]; int x24; } Ev_8350;
#pragma opt_common_subs off
static inline void Ev_Init(Ev_8350* p, Ctl_8350* c)
{
    Event_Construct(p, D_0051EE58);
    p->vt = D_004DE110;
    func_001584B0((char*)p + 0x30);
    p->x24 = func_001584A0(func_0012F2B0(c));
}
extern "C" Ev_8350* func_00158350(NPC_8350* self)
{
    Snd_8350* s = self->ctl->snd;
    if (s)
        s->Stop();
    if (D_005721C8) {
        Ev_8350* p;
        {
            AllocGuard g;
            p = (Ev_8350*)Mem_Alloc(0, 0x310, D_0049B670, 0x80C);
        }
        if (p) {
            Ev_Init(p, self->ctl);
            func_00148B50((char*)p + 0x30, self);
            func_00158490(p, 0x40);
        }
        return p;
    }
    return 0;
}
#pragma opt_common_subs reset
