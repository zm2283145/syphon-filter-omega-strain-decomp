/* cNPC_CriticalNextFrame: compiled as C++ (virtual calls through $t9; vtable slot = (offset-8)/4).
 * bool fields + bool local give the sltu/xori chain without andi.
 * List-walk helpers are nested inlines: MW gives inline locals stack slots by inline depth,
 * which reproduces retail's end/begin/raw slot order. */
#pragma cplusplus on
#include "types.h"

struct Npc_A440;
struct NpcObj_A440 {
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual int V5C(int);
    virtual int V60(int);
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual int V7C();
    char pad4[0x8];
    int id;
    char pad10[4];
    unsigned char b14;
    char pad15[0x17];
    bool b2C;
    bool b2D;
    bool b2E;
    char pad2F[0x29];
    struct Npc_A440* npc58;
};
typedef struct Flags_A440 { unsigned char rest : 7; unsigned char top : 1; } Flags_A440;
struct Npc_A440 {
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual int V90();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
    virtual void VC0();
    virtual void v31();
    virtual void VC8(int);
    char pad4[0x2C];
    NpcObj_A440* obj;
    char pad34[0x64];
    float range;
    char pad9C[0xA5];
    Flags_A440 f141;
    char pad142[0x27];
    unsigned char b169;
    char pad16A[0x6A];
    unsigned char b1D4;
    unsigned char b1D5;
};
typedef struct Rec_A440 { int id; unsigned int mask; float t; } Rec_A440;
typedef struct Node_A440 { struct Node_A440* prev; struct Node_A440* next; Rec_A440* rec; } Node_A440;
typedef struct Msg_A440 { void* vtable; char pad[0x20]; unsigned char kind; char pad2[0xB]; } Msg_A440;
typedef struct Big_A440 { char a[0xF0]; char b[0x20]; char c[0x30]; char d[0x70]; char e[0x20]; char f[0x10]; char g[4][0x40]; } Big_A440;
typedef struct Lock_A440 { int v; } Lock_A440;
typedef struct Raw_A440 { int p; } Raw_A440;

extern "C" {

extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern int g_VideoFrameCounter;
extern float g_LevelFarDistance;
extern int D_004EA380;
extern int D_00494178;
extern int D_005721A8;
extern char D_004EA1B0[];
extern char D_00582730[];
extern char D_004D9300[];
extern char D_0049B6D0[];
extern char D_0049B730[];
extern char D_0049B780[];

void func_00436C00(Lock_A440*);
void func_00436BA0(Lock_A440*, int);
int func_004340C0(Lock_A440*, int*);
int func_00434440(Lock_A440*, int*);
int func_00434380(Lock_A440*, int*);
int func_00434190(Lock_A440*, int*, int);
int func_00433EC0(Lock_A440*, int*, int);
void func_00435D80(Lock_A440*, int*, int);
NpcObj_A440* Object_ClosestPlayerDistSq(NpcObj_A440*, float*);
void List_Begin(Raw_A440*, void*);
void func_0015AD60(Node_A440**, Raw_A440*);
void func_0015AD50(Raw_A440*, void*);
void func_0015AD40(Node_A440**, Raw_A440*);
void func_0015AD10(void*);
void func_0015ACD0(void*);
void func_0015ACC0(void*);
void func_0015ACB0(void*);
void func_0015ACA0(void*);
void func_0015AC90(void*, int);
void func_0015AC70(void*);
void func_00148B50(void*, Npc_A440*);
void func_00148CD0(Npc_A440*, void*);
void Event_Construct(Msg_A440*, void*);
void Event_Send(Msg_A440*, NpcObj_A440*, int);
void cMessage_dtor(Msg_A440*, int);
void printf(char*, ...);
int PlayerSlots_Get(int);
int Net_GetClock(int);
void func_0042D310(int*, int);
void func_0042DA30(NpcObj_A440*, int, int);
void NetGame_InitLocalSlot(int*, int);

}

static inline void MkBegin(Node_A440** t)
{
    Raw_A440 b;
    List_Begin(&b, D_004EA1B0);
    func_0015AD60(t, &b);
}
static inline Node_A440* Begin()
{
    Node_A440* t;
    MkBegin(&t);
    return t;
}
static inline void MkEnd(Node_A440** en)
{
    Raw_A440 e;
    func_0015AD50(&e, D_004EA1B0);
    func_0015AD40(en, &e);
}
static inline void MkEnd1(Node_A440** en)
{
    MkEnd(en);
}

static inline int LocalSlot(int a)
{
    if (g_IsMultiplayer) {
        if (D_00494178 == -1)
            NetGame_InitLocalSlot(&D_00494178, a);
        return D_00494178;
    }
    return 0;
}

extern "C" void cNPC_CriticalNextFrame(Npc_A440* self, float dt)
{
    int id;
    int act;
    unsigned char on;

    if (g_IsMultiplayer)
        on = D_005721C0;
    else
        on = 1;
    if (!on)
        return;
    if (!self->obj)
        return;
    id = self->obj->id;
    act = -1;
    if (self->f141.top && self->obj->V7C() == 0 && !(((unsigned short)id + g_VideoFrameCounter) & 7)) {
        Lock_A440 lk;
        bool busy;
        NpcObj_A440* o;
        func_00436C00(&lk);
        o = self->obj;
        busy = o->b2D && o->b2C && !o->b2E;
        if (!busy && !func_004340C0(&lk, &id)) {
            if (!self->b1D5) {
                float d;
                NpcObj_A440* pl = Object_ClosestPlayerDistSq(self->obj, &d);
                if (pl) {
                    float r = self->range;
                    r = (r < 0.00001f) ? g_LevelFarDistance * g_LevelFarDistance : r;
                    if (d < r) {
                        if (g_IsMultiplayer)
                            act = (((unsigned int)pl->id & 0x7F000000) >> 24) - 1;
                        else
                            self->obj->V5C(1);
                        self->b1D5 = 1;
                    }
                }
            }
            self->b1D4 = 0;
        } else if (!self->b1D4) {
            float d;
            float r;
            Object_ClosestPlayerDistSq(self->obj, &d);
            r = self->range;
            r = (r < 0.00001f) ? g_LevelFarDistance * g_LevelFarDistance : r;
            if (!(d <= 625.0f + r)) {
                if (g_IsMultiplayer)
                    self->VC0();
                else
                    self->obj->V60(1);
                self->b1D4 = 1;
            }
            self->b1D5 = 0;
        }
        func_00436BA0(&lk, -1);
    }
    if (g_IsMultiplayer && self->obj->V7C() == 0) {
        Lock_A440 lk2;
        int slot;
        int alt;
        func_00436C00(&lk2);
        slot = func_00434440(&lk2, &id);
        alt = func_00434380(&lk2, &id);
        if (slot >= 0) {
            Rec_A440* rec = 0;
            Node_A440* it;
            Node_A440* en;
            for (it = Begin(); MkEnd1(&en), it != en; it = it->next) {
                if (it->rec->id == self->obj->id) {
                    rec = it->rec;
                    break;
                }
            }
            if (rec) {
                if (self->b169) {
                    if (slot == 0) {
                        if (!self->obj->b14) {
                            Big_A440 big;
                            Msg_A440 msg;
                            NpcObj_A440* o;
                            Npc_A440* n;
                            char* q = (char*)&big;
                            char* p;
                            func_0015AD10(q);
                            func_0015ACD0(big.b);
                            func_0015ACC0(q + 0x110);
                            func_0015ACB0(q + 0x140);
                            func_0015ACA0(q + 0x1B0);
                            func_0015AC90(q + 0x1D0, -1);
                            p = q + 0x1E0;
                            do {
                                func_0015AC70(p);
                                p += 0x40;
                            } while (p != q + 0x2E0);
                            func_00148B50(&big, self);
                            o = self->obj;
                            Event_Construct(&msg, D_00582730);
                            msg.vtable = D_004D9300;
                            msg.kind = 1;
                            Event_Send(&msg, o, 1);
                            msg.vtable = D_004D9300;
                            cMessage_dtor(&msg, 0);
                            n = o->npc58;
                            n->obj->b14 = 1;
                            func_00148CD0(n, &big);
                            n->b169 = 1;
                            printf(D_0049B6D0, id);
                        } else {
                            int who = 0;
                            int i;
                            for (i = 0; i < 4; i++) {
                                if (PlayerSlots_Get(i) && (rec->mask & (1 << i))) {
                                    who = i;
                                    if (func_00434190(&lk2, &self->obj->id, i) && func_00433EC0(&lk2, &self->obj->id, i))
                                        break;
                                }
                            }
                            if (who == 0 || D_004EA380 < Net_GetClock(1)) {
                                self->b169 = 0;
                                rec->t = 0.0f;
                                if (who > 0) {
                                    int* pid = &self->obj->id;
                                    func_0042D310(pid, self->V90());
                                    func_0042DA30(self->obj, 0, who);
                                    printf(D_0049B730);
                                    D_004EA380 = Net_GetClock(1) + 0xFA;
                                }
                            }
                        }
                    }
                } else if (!PlayerSlots_Get(slot) || (slot == -1 && !PlayerSlots_Get(alt))) {
                    printf(D_0049B780, slot, id);
                    func_00435D80(&lk2, &id, 0);
                    self->b169 = 1;
                    rec->mask &= ~(1 << slot);
                } else {
                    if (func_00434190(&lk2, &id, slot) && !func_00433EC0(&lk2, &id, slot))
                        rec->t += dt;
                    else
                        rec->t = 0.0f;
                    if (!(rec->t <= 2.0f)) {
                        int to;
                        int j;
                        int me;
                        rec->t = 0.0f;
                        to = -1;
                        for (j = 0; j < 4; j++) {
                            if (j != slot && PlayerSlots_Get(j) && func_00434190(&lk2, &self->obj->id, j) && func_00433EC0(&lk2, &self->obj->id, j)) {
                                to = j;
                                if (rec->mask & (1 << j))
                                    break;
                            }
                        }
                        if (to >= 0) {
                            me = LocalSlot(D_005721A8);
                            if (slot == me) {
                                int* pid = &self->obj->id;
                                func_0042D310(pid, self->V90());
                            }
                            func_0042DA30(self->obj, slot, to);
                        }
                    }
                }
            }
        }
        func_00436BA0(&lk2, -1);
    }
    if (act >= 0)
        self->VC8(act);
}
