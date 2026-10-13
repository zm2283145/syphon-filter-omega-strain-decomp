#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

class Actor_4460 {
public:
    VPAD16(p) VPAD4(q) VPAD2(r)
    virtual void SetActive(int on);
    char pad4[0x2C - 4];
    unsigned char x2C;
    unsigned char x2D;
    unsigned char x2E;
};

struct Empty_4460 { char c; };
class cNPC_4460;
struct Pred_4460 {
    Empty_4460 e;
    cNPC_4460** self;
    Pred_4460(const Empty_4460& c, cNPC_4460** s) : e(c), self(s) {}
};

class cNPC_4460 {
public:
    VPAD8(p) VPAD4(q) VPAD2(r) VPAD1(s)
    virtual int IsLocal();
    char pad4[0x2C];
    Actor_4460* actor;
    char pad34[0x141 - 0x34];
    unsigned char b1 : 7;
    unsigned char net : 1;
    char pad142[0x150 - 0x142];
    unsigned short id;
    char pad152[0x159 - 0x152];
    unsigned char done;
};

typedef struct {
    void* vtable; void* type; unsigned int magic; unsigned int time; int unk10; void* target;
    unsigned int stampKind; int flags; unsigned char kind; unsigned char pad21[3];
    Actor_4460* actor;
    unsigned char flag;
} Msg_4460;

typedef struct { char pad[4]; unsigned int magic; } Obj_4460;

extern "C" {
extern char D_004A4A68[];
extern char D_004DB600[];
extern char D_004DB660[];
extern char D_004EA370[];
void NpcThinkList_RemoveActor(Actor_4460* a);
void ActiveList_EraseMatching(void* v, Pred_4460 p);
Obj_4460* Object_LookupById(unsigned short* id);
void Event_Construct(void* msg, void* type);
void Event_Send(void* msg, void* target, int immediate);
void cMessage_dtor(void* msg, int flags);
void func_00436C00(int* t);
int func_00434440(int* t, void* id);
void func_0042D910(Actor_4460* a);
void func_00436BA0(int* t, int f);
}

static inline bool IsAlive_4460(Actor_4460* a) { return a->x2D && a->x2C && !a->x2E; }

extern "C" void func_002D4460(cNPC_4460* self)
{
    int t;
    Empty_4460 e;
    if (!self->done) {
        Actor_4460* a = self->actor;
        if (a && IsAlive_4460(a)) {
            a->SetActive(1);
            return;
        }
        NpcThinkList_RemoveActor(a);
            ActiveList_EraseMatching(D_004EA370, Pred_4460(e, &self));
        if (self->id) {
            Obj_4460* o = Object_LookupById(&self->id);
            if (o && o->magic == 0xBEBAAFDE) {
                Msg_4460 m;
                Actor_4460* act = self->actor;
                Event_Construct(&m, D_004A4A68);
                m.vtable = D_004DB600;
                m.flag = 1;
                m.actor = act;
                Event_Send(&m, o, 0);
                m.vtable = D_004DB660;
                cMessage_dtor(&m, 0);
            }
        } else if (self->IsLocal()) {
            func_00436C00(&t);
            func_00434440(&t, (char*)self->actor + 0xC);
            if (self->net) func_0042D910(self->actor);
            func_00436BA0(&t, -1);
        }
        self->done = 1;
    }
}

