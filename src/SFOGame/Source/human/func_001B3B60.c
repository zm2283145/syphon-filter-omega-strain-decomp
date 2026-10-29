#pragma cplusplus on
extern "C" {
typedef struct Ev {
    void* vt;
    char pad4[0x8];
    int xC;
    char pad10[0x14];
    int x24;
    unsigned int x28;
    int x2C;
    int x30;
    unsigned char x34;
    char pad35[3];
    int x38;
} Ev;

struct Ev;struct Npc;struct Player;
struct Sub {
    virtual void v8();
    virtual void vC();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void f64(int);

};
struct Ctl {
    virtual void v8();
    virtual int Handle(Ev*);
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual int f44();
    virtual void f48();
    virtual void v4C();
    virtual void v50();
    virtual int IsPlayer();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual unsigned char State();
    char pad4[0x30 - 4];
    Sub* x30;
    char pad34[0x141 - 0x34];
    unsigned char b141l : 7;
    unsigned char b141h : 1;
    char pad142[0x150 - 0x142];
    int x150;
};
struct Node {
    virtual void v8();
    virtual void vC();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void Update();
    char pad4[0xC];
    char mtx[0x30];
    char pos[0x10];
    Node* x50;
};
struct Xf {
    virtual void v8();
    virtual void SetMtx(void*);
    virtual void v10();
    virtual void SetPos(void*);

};
struct Npc {
    virtual void v8();
    virtual void vC();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void Activate(int);
    virtual void Deactivate(int);
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual int f7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void vD4();
    virtual void vD8();
    virtual void vDC();
    virtual void vE0();
    virtual void vE4();
    virtual void vE8();
    virtual void vEC();
    virtual void vF0();
    virtual void vF4();
    virtual void vF8();
    virtual void vFC();
    virtual void PlayAnim(int, int, int, int, int, int, float);
    char pad4[0x14 - 4];
    unsigned char b14;
    char pad15[0x2C - 0x15];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x40 - 0x2F];
    float x40;
    char pad44[0x58 - 0x44];
    Ctl* ctl;
    char pad5C[0x60 - 0x5C];
    char x60[0x31B1 - 0x60];
    unsigned char b31B1;
    char pad31B2[0x31F0 - 0x31B2];
    int x31F0;
    char pad31F4[0x3210 - 0x31F4];
    int x3210;
    char pad3214[0x33A0 - 0x3214];
    int x33A0;
    char pad33A4[0x33F0 - 0x33A4];
    char x33F0[0x3440 - 0x33F0];
    Xf* xf;
    char pad3444[0x3450 - 0x3444];
    int x3450;
    char pad3454[4];
    int x3458;
    char pad345C[0x3524 - 0x345C];
    void* inv;
    char pad3528[0x3584 - 0x3528];
    void* x3584;
    char pad3588[0x3594 - 0x3588];
    int x3594;
};

struct Player { char pad[0xC]; void* p; };

extern int* cMessage_Name(Ev*);
extern int D_0052ACB0, g_CasEventMsgClass, D_004EE550, D_00588038, D_004EE698, D_00582680, D_00582730;
extern int g_ActorActionMsgClass, D_004F82F0, D_00542B60, D_00542B68, D_0055D4D8, g_TeleportMsgClass;
extern int g_cEnableMsgClass, g_cDisableMsgClass, D_004F7930, D_004F7940, D_004F80B8, D_004F80A8;
extern int D_0051F0C0, D_0052ACC8, D_004F53F8, D_0052AF10, D_004A0318, D_004EE960;
extern int D_004E0840, D_0049D8D0;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern unsigned char g_IsMultiplayer, D_005721C0;

extern void cHuman_CreateGobjController(Npc*, int, void*, void*);
extern void Alloc_Lock(int);
extern void EnableIntc(int);
extern void* cMemMan_Allocate(int, int, void*, int);
extern void* cNetNPC_ctor(void*, int, Npc*);
extern void cNetHuman_Deactivate(void*);
extern int cHuman_HandleActionRequest(Npc*, Ev*);
extern void cMessage_ctor_cMessageNameR(void*, void*);
extern void QueueMessage_cMessageR_cSystemP_int(void*, void*, int);
extern void cMessage_dtor(void*, int);
extern int Actor_HandleEmbeddedEvent(Npc*, Ev*);
extern int AnimToken_Handle(Npc*, Ev*);
extern int cHuman_HandleMoveMessage_cMoveMsgTemplateR(Npc*, Ev*);
extern int cHuman_HandleMoveMessage_cMoveMsgTemplateR_2(Npc*, Ev*);
extern Player* cNetObj_GetPlayer(int);
extern int cNetObj_GetOwner(void*);
extern void cNPC_Activate_cGOBJP(Ctl*, Player*);
extern void cNPC_Deactivate_cGOBJP(Ctl*, Player*);
extern void cNode_GetLoc(void*, Node*);
extern void cNode_GetNodeMatrix(void*, Node*);
extern void cCheckpoint_SetString(void*, int);
extern void Actor_Revive(Npc*);
extern void Actor_EnterDeadState(Npc*);
extern char* nGobjManager_LookupGOBJ_cObjectIdR(int*);
extern void cMan_AddCostume(void*, void*);
extern void cMan_RemoveCostume(void*);
extern void cWeapon_RemoveWeapon(void*, int, int, int, int);
extern void cWeapon_RemoveAmmo(void*, int, int, int, int);
extern void cWeapon_Add(void*, int, bool, int, bool, int);
extern void cWeapon_PickupClip(void*, int, int, int);
extern void cWeapon_PickupAmmo_eWpnSlot_int_bool(void*, int, int, int);
extern void cWeapon_EqualizeDualWieldAmmo(void*);
extern void cHuman_TurnOnWeaponPickup(Npc*);
extern int cGOBJ_HandleMessage(Npc*, Ev*);

}
typedef struct Msg { void* vt; char pad[0x20]; int x24; unsigned char x28; char pad29[0x30 - 0x29]; } Msg;

struct IA { int* p; int q; IA(int* a, int b) { p = a; q = b; } };
static inline char* Lookup(int id) { return nGobjManager_LookupGOBJ_cObjectIdR(&id); }
#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct ActMsg { void* vt; char pad[0x20]; int x24; unsigned char x28; char pad29[7];
    ActMsg(int k) { cMessage_ctor_cMessageNameR(this, &g_ActorActionMsgClass); vt = &D_004E0840; x24 = k; x28 = 0; }
    __declspec(weak) __declspec(MSG_DTOR) ~ActMsg() { vt = &D_004E0840; cMessage_dtor(this, 0); } };
static inline void SendTo(const ActMsg& m, void* to) { QueueMessage_cMessageR_cSystemP_int((void*)&m, to, 1); }
static inline bool IsPl(Npc* a) { bool r = 0; if (a->ctl && a->ctl->IsPlayer()) r = 1; return r; }
static inline bool Active(Npc* a) { return a->b2D && a->b2C && !a->b2E; }

static inline Player* FindPlayer(Ev* e) {
    Player* found = 0;
    int i;
    if (g_IsMultiplayer ? D_005721C0 : 1) {
        for (i = 0; i < 4; i++) {
            Player* p = cNetObj_GetPlayer(i);
            if (p && e->x24 == cNetObj_GetOwner(p->p)) {
                found = p;
                break;
            }
        }
    }
    return found;
}

extern "C" int cHuman_HandleMessage(Npc* self, Ev* e) {
    int t;
    if ((t = *cMessage_Name(e), t == D_0052ACB0)) {
        Ctl* c = self->ctl;
        if (c && c->State() == 4) return c->Handle(e);
    } else if ((t = *cMessage_Name(e), t == g_CasEventMsgClass) || (t = *cMessage_Name(e), t == D_004EE550) || (t = *cMessage_Name(e), t == D_00588038)) {
        Ctl* c = self->ctl;
        if (c && c->State() != 2 && c->State() != 4) return c->Handle(e);
    } else if ((t = *cMessage_Name(e), t == D_004EE698)) {
        switch (e->x28 - 8) {
        case 8 - 8: case 9 - 8: case 12 - 8: case 13 - 8: case 14 - 8: case 15 - 8: case 16 - 8: case 18 - 8:
            if (self->ctl) return self->ctl->Handle(e);
        case 10 - 8: case 11 - 8: case 17 - 8:
        default:
            return 0;
        }
    } else if ((t = *cMessage_Name(e), t == D_00582680)) {
        if (self->ctl->State() == 2) cHuman_CreateGobjController(self, 2, 0, 0);
        self->Activate(0);
    } else if ((t = *cMessage_Name(e), t == D_00582730)) {
        switch ((unsigned char)e->x24) {
        case 2: {
            Ctl* c = self->ctl;
            void* p;
            if (!c || (c && c->State() != 2)) {
                if (g_ProfileLockEnabled) Alloc_Lock(9);
                g_ProfileLockDepth++;
                p = cMemMan_Allocate(0, 0x220, &D_0049D8D0, 0x543);
                if (g_ProfileLockEnabled) EnableIntc(9);
                g_ProfileLockDepth--;
                if (p) p = cNetNPC_ctor(p, 0, self);
                cHuman_CreateGobjController(self, 4, 0, p);
                if (Active(self)) self->ctl->f48();
            }
            if (self->x3584) cNetHuman_Deactivate(self->x3584);
            break;
        }
        case 1: {
            Ctl* c = self->ctl;
            if (c && c->State() != 1) {
                if (self->f7C()) {
                    int w = self->x31F0;
                    int v = self->ctl->x150;
                    IA arg(&v, w);
                    cHuman_CreateGobjController(self, 2, &arg, 0);
                } else {
                    cHuman_CreateGobjController(self, 2, 0, 0);
                }
                if (Active(self)) self->ctl->f48();
            }
            break;
        }
        }
    } else if ((t = *cMessage_Name(e), t == g_ActorActionMsgClass)) {
        return cHuman_HandleActionRequest(self, e);
    } else if ((t = *cMessage_Name(e), t == D_004F82F0)) {
        if (self->b14) {
            switch ((signed char)e->x24) {
            case 0: {
                SendTo(ActMsg(6), self);
                break;
            }
            case 1:
                self->PlayAnim(e->x28, 2, 2, 0, 0, 0, (int)self->x40);
                break;
            case 2:
                self->PlayAnim(e->x28, 1, 14, 0, 0, 0, (int)self->x40);
                break;
            }
            return 1;
        }
    } else if ((t = *cMessage_Name(e), t == D_00542B60)) {
        return Actor_HandleEmbeddedEvent(self, e);
    } else if ((t = *cMessage_Name(e), t == D_00542B68)) {
        return AnimToken_Handle(self, e);
    } else if ((t = *cMessage_Name(e), t == D_0055D4D8)) {
        return cHuman_HandleMoveMessage_cMoveMsgTemplateR(self, e);
    } else if ((t = *cMessage_Name(e), t == g_TeleportMsgClass)) {
        return cHuman_HandleMoveMessage_cMoveMsgTemplateR_2(self, e);
    } else if ((t = *cMessage_Name(e), t == g_cEnableMsgClass)) {
        Ctl* c = self->ctl;
        if (g_IsMultiplayer) {
            if (e->x24 >= 0) {
                Player* p = FindPlayer(e);
                self->ctl->x30->f64(-1);
                if (p && (g_IsMultiplayer ? D_005721C0 : 1) && c->f44())
                    cNPC_Activate_cGOBJP(c, p);
            }
        } else if (!Active(self) && c->f44()) {
            self->Activate(1);
        }
        return 1;
    } else if ((t = *cMessage_Name(e), t == g_cDisableMsgClass)) {
        if (g_IsMultiplayer) {
            if (e->x24 >= 0) {
                Player* p = FindPlayer(e);
                Ctl* c = self->ctl;
                if (p && (g_IsMultiplayer ? D_005721C0 : 1)) cNPC_Deactivate_cGOBJP(c, p);
            }
        } else if (Active(self) && !self->ctl->b141h) {
            self->Deactivate(1);
        }
        return 1;
    } else if ((t = *cMessage_Name(e), t == D_004F7930)) {
        Node* n = (Node*)e->x24;
        if (n) {
            char pos[0x10];
            char mtx[0x40];
            Xf* x = self->xf;
            cNode_GetLoc(pos, n);
            x->SetPos(pos);
            x = self->xf;
            cNode_GetNodeMatrix(mtx, n);
            x->SetMtx(mtx);
        } else {
            Xf* x;
            Node* m = n->x50;
            x = self->xf;
            if (((unsigned char*)m)[0x50]) m->Update();
            x->SetPos(m->pos);
            {
            Xf* x2;
            Node* m2 = n->x50;
            x2 = self->xf;
            if (((unsigned char*)m2)[0x50]) m2->Update();
            x2->SetMtx(m2->mtx);
            }
        }
        self->x3450 = (int)self->x40;
        self->x3458 = self->x33A0;
        cCheckpoint_SetString(self->x33F0, e->x28);
        return 1;
    } else if ((t = *cMessage_Name(e), t == D_004F7940)) {
        self->x3594 = e->xC;
        if (!IsPl(self) || !self->b14 || (self->x3210 >> 31) & 1)
            Actor_Revive(self);
        else
            Actor_EnterDeadState(self);
    } else if ((t = *cMessage_Name(e), t == D_004F80B8)) {
        int id0, id1, id2;
        char* o;
        { int* z = &id0; if (!z) return 0; }
        id1 = e->x30;
        o = nGobjManager_LookupGOBJ_cObjectIdR(&id1);
        id2 = e->x2C;
        nGobjManager_LookupGOBJ_cObjectIdR(&id2);
        cMan_AddCostume(self->x60, o + 0xA0);
    } else if ((t = *cMessage_Name(e), t == D_004F80A8)) {
        cMan_RemoveCostume(self->x60);
    } else if ((t = *cMessage_Name(e), t == D_0051F0C0)) {
        self->ctl->Handle(e);
    } else if ((t = *cMessage_Name(e), t == D_0052ACC8)) {
        unsigned char k = e->x2C;
        switch (k) {
        case 0:
            if (!((self->x3210 >> 27) & 1))
                cWeapon_RemoveWeapon(self->inv, e->x34, 0, e->x38 != 0, 1);
            break;
        case 1:
            cWeapon_RemoveAmmo(self->inv, e->x34, e->x38, 1, 1);
            break;
        case 5:
            cWeapon_Add(self->inv, e->x34, e->x38 & 1, 0, (e->x38 >> 1) & 1, 1);
            break;
        case 3:
            cWeapon_PickupClip(self->inv, e->x34, e->x38, 1);
            break;
        case 4:
            cWeapon_PickupAmmo_eWpnSlot_int_bool(self->inv, e->x34, e->x38, 1);
            cWeapon_EqualizeDualWieldAmmo(self->inv);
            break;
        }
    } else if ((t = *cMessage_Name(e), t == D_004F53F8)) {
        Ctl* c = self->ctl;
        int r = 0;
        if (c) r = c->Handle(e);
        return r;
    } else if ((t = *cMessage_Name(e), t == D_0052AF10)) {
        self->b31B1 = *(unsigned char*)&e->x24;
    } else if ((t = *cMessage_Name(e), t == D_004A0318)) {
        QueueMessage_cMessageR_cSystemP_int(e, self->ctl, 1);
    } else if ((t = *cMessage_Name(e), t == D_004EE960)) {
        cHuman_TurnOnWeaponPickup(self);
    } else {
        return cGOBJ_HandleMessage(self, e);
    }
    return 0;
}
