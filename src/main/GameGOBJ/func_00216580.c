#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct Msg_216580 {
    virtual void Destroy(int f);
    virtual Msg_216580* Clone();
};
struct Obj_216580 { char pad0[0xC]; int id; };
struct Rel_216580 { int a; int n; void** c; };
struct cInteractGOBJ_216580 {
    void* vtable;
    char pad04[0x94];
    Rel_216580 x98;
    unsigned char xA4;
    char padA5[0xB];
    unsigned char xB0;
    char padB1[3];
    Obj_216580* riders[2];
    Msg_216580* xBC;
};
struct In_216580 {
    void* vtable;
    char pad04[0x20];
    unsigned char kind;
    char pad25[7];
    Obj_216580* who;
    int id;
};
struct In2_216580 {
    void* vtable;
    char pad04[0x20];
    int kind;
    char pad28[4];
    Obj_216580* who;
};
struct LiftMsg_216580 { void* vtable; char base[0x1C]; unsigned char b20; char pad21[3]; int kind; int floor; int from; int to; char pad34[0xC]; };
extern "C" {
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern int D_004F5440;
extern int D_0055A1D8;
extern char D_004DAF10[];
extern char D_004A4550[];
int* Event_GetType(void* ev);
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
Obj_216580* Object_LookupById(int* id);
int ObjectAction_SendKind7(Obj_216580* obj, int action, cInteractGOBJ_216580* target, int arg, float time);
void func_00216230(cInteractGOBJ_216580* self, In_216580* msg);
void Mem_Free(int heap, void* p, char* file, int line);
void func_003E6690(Obj_216580* o, int f);
int Object_HandleMessage(cInteractGOBJ_216580* self, void* ev);
}
static inline void* At_216580(Rel_216580* r, unsigned int i) { return r->c[i]; }
static inline int IsAuth_216580(void) { return D_005721C8 ? D_005721C0 : 1; }
static inline int ObjId_216580(Obj_216580* o) { return o ? o->id : 0; }
static inline void Free_216580(Msg_216580* p, int line)
{
    AllocGuard g;
    p->Destroy(-1);
    Mem_Free(0, p, D_004A4550, line);
}
extern "C" int cInteractGOBJ_v01(cInteractGOBJ_216580* self, In_216580* m)
{
    int t = *Event_GetType(m);
    if (t == D_004F5440) {
        if (!self->xBC) {
            int id = m->id;
            Obj_216580* o = Object_LookupById(&id);
            int k = m->kind;
            if (o) {
                switch (k) {
                case 7:
                    func_00216230(self, m);
                    break;
                case 3:
                case 2:
                    break;
                default:
                    ObjectAction_SendKind7(o, 0x25, self, 0, -1.0f);
                    self->xBC = ((Msg_216580*)m)->Clone();
                    break;
                }
            }
        }
        return 1;
    }
    t = *Event_GetType(m);
    if (t == D_0055A1D8) {
        In2_216580* m2 = (In2_216580*)m;
        switch (m2->kind) {
        case 14:
            if (self->xBC) {
                int i;
                for (i = 0; i < self->x98.n; i++)
                    Event_Send(self->xBC, At_216580(&self->x98, i), 0);
                Free_216580(self->xBC, 0x4ED);
                self->xBC = 0;
            }
            break;
        case 13: {
            Obj_216580* who;
            int i;
            if (self->xBC) {
                Free_216580(self->xBC, 0x4F7);
                self->xBC = 0;
            }
            who = m2->who;
            self->xB0 = 0;
            for (i = 0; i < 2; i++) {
                Obj_216580* r = self->riders[i];
                if (r && r != who)
                    func_003E6690(r, 1);
                self->riders[i] = 0;
            }
            if (IsAuth_216580()) {
                LiftMsg_216580 msg;
                Obj_216580* w = m2->who;
                LiftMsg_216580* p = &msg;
                Event_Construct(p, &D_004F5440);
                msg.floor = 0;
                msg.vtable = D_004DAF10;
                msg.kind = 3;
                p->to = ObjId_216580(w);
                p->from = ObjId_216580(0);
                msg.b20 = 1;
                Event_Send(&msg, self, 0);
                msg.vtable = D_004DAF10;
                cMessage_dtor(&msg, 0);
            }
            break;
        }
        case 15: {
            Obj_216580* who;
            unsigned char any;
            int i;
            if (self->xBC) {
                Free_216580(self->xBC, 0x526);
                self->xBC = 0;
            }
            who = m2->who;
            any = 0;
            for (i = 0; i < 2; i++) {
                Obj_216580* r = self->riders[i];
                if (r == who)
                    self->riders[i] = 0;
                else if (r)
                    any = 1;
            }
            if (!any)
                self->xB0 = 0;
            if (IsAuth_216580()) {
                LiftMsg_216580 msg;
                Obj_216580* w = m2->who;
                LiftMsg_216580* p = &msg;
                Event_Construct(p, &D_004F5440);
                msg.floor = 0;
                msg.vtable = D_004DAF10;
                msg.kind = 2;
                p->to = ObjId_216580(w);
                p->from = ObjId_216580(0);
                msg.b20 = 1;
                Event_Send(&msg, self, 0);
                msg.vtable = D_004DAF10;
                cMessage_dtor(&msg, 0);
            }
            break;
        }
        }
        return 1;
    }
    return Object_HandleMessage(self, m);
}
