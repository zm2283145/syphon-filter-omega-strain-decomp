#pragma cplusplus on
struct NpcV {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual int s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62(int);
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84();
    virtual void s85();
    virtual void s86();
    virtual void s87();
    virtual void s88();
    virtual void s89();
    virtual void s90();
    virtual void s91();
    virtual void s92();
    virtual void s93();
    virtual void s94();
    virtual void s95();
    virtual void s96();
    virtual void s97();
    virtual void s98();
    virtual void s99();
    virtual void s100();
    virtual void s101();
    virtual void s102();
    virtual int s103();
    virtual void s104();
    virtual void s105(int);
    virtual void s106();
};
struct ActV {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21(int);
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual int s29();
};
typedef struct { char pad[0x14]; unsigned char used; char pad15[3]; } LookSlot;
typedef struct Actor : ActV {
    char pad4[0x8];
    int id;
    char pad10[0x1C];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x3524 - 0x2F];
    int inv;
} Actor;
typedef struct Npc : NpcV {
    char pad4[0x2C];
    Actor *actor;
    char pad34[0x68 - 0x34];
    int u68;
    char pad6C[0x84 - 0x6C];
    int u84;
    int u88;
    float u8C;
    char pad90[0xA4 - 0x90];
    int burst;
    int uA8;
    char padAC[4];
    int uB0;
    int uB4;
    char padB8[0xE8 - 0xB8];
    int uE8;
    char padEC[0x138 - 0xEC];
    int node;
    char pad13C[5];
    unsigned char f0 : 1;
    unsigned char f1 : 1;
    unsigned char f2 : 1;
    unsigned char f3 : 1;
    unsigned char f4 : 1;
    unsigned char f5 : 1;
    unsigned char f6 : 1;
    unsigned char f7 : 1;
    char pad142[0x158 - 0x142];
    unsigned char u158;
    unsigned char active;
    char pad15A[0x166 - 0x15A];
    unsigned char u166;
    char pad167[0x1AC - 0x167];
    int view;
    int path;
    char pad1B4[4];
    LookSlot *slot;
    int u1BC;
    float u1C0;
    int u1C4;
    char pad1C8[0x1D0 - 0x1C8];
    int u1D0;
} Npc;
typedef struct {
    void *vt;
    char pad4[0x20];
    int id;
    signed char b28;
    char pad29[0x30 - 0x29];
} Msg;

extern "C" {
extern LookSlot D_004EA1D0[16];
extern char D_004EA370[];
extern unsigned char D_0055C780[4];
extern unsigned char D_005721C8;
extern int D_005721A8;
extern int D_00494178;
extern char D_00582760[];
extern char D_004E0F00[];

int Actor_IsArmed(Actor *a);
void Event_Construct(Msg *m, void *type);
void LookSlot_Clear(LookSlot *s);
void NpcAi_AddToDeadList(void *list, Npc **npc);
int NpcPath_GetNode(int n);
void NpcPath_Start(int p);
void NpcPerception_ResetView(int v);
void NpcThinkList_Add(Actor *a);
int Random_Next(void);
void Transport_Send(int id, Msg *m, int a, int b);
int WeaponInv_GetClipSize(int inv, int w);
int WeaponInv_IsFullAuto(int inv);
void cAI_v10(Npc *npc);
void cMessage_dtor(Msg *m, int f);
int func_002EBAF8(int *id, int session);
}

#define LOCALID(X) { int ld_a = D_005721A8; if (D_005721C8) { if (D_00494178 == -1) func_002EBAF8(&D_00494178, ld_a); X = D_00494178; } else X = 0; }

extern "C" void cNPC_v10(Npc *self)
{
bool ok;
    int i;
    int v;

    if (self->active) {
        Actor *a = self->actor;
        ok = a->b2D != 0 && a->b2C != 0 && !(a->b2E != 0);
        if (!ok) {
            if (self->s15()) {
                Actor *b = self->actor;
                b->s21(1);
            }
        } else {
            if (self->s15())
                NpcThinkList_Add(self->actor);
            else
                NpcAi_AddToDeadList(D_004EA370, &self);
            self->slot = D_004EA1D0;
            for (i = 0; i < 16; i++) {
                if (!D_004EA1D0[i].used) {
                    D_004EA1D0[i].used = 1;
                    self->slot = &D_004EA1D0[i];
                    break;
                }
            }
            LookSlot_Clear(self->slot);
            self->u166 = 0;
            if (self->uE8 < 0)
                self->uE8 = 0;
            cAI_v10(self);
            NpcPerception_ResetView(self->view);
            NpcPath_Start(self->path);
            if (self->node >= 0) {
                self->s62(NpcPath_GetNode(self->node));
                self->node = -1;
            }
            {
                Actor *a2 = self->actor;
                if (Actor_IsArmed(a2)) {
                    int inv = a2->inv;
                    int n;
                    self->burst = (self->actor->id & 7) + 3;
                    if (Random_Next() & 1)
                        self->burst++;
                    n = self->burst;
                    if (WeaponInv_GetClipSize(inv, 6) < n) {
                        v = WeaponInv_GetClipSize(inv, 6) / 2;
                        self->burst = v <= 0 ? 1 : v;
                    }
                } else {
                    self->burst = 0;
                }
            }
            self->uA8 = 0;
            self->u158 = 1;
            self->u1BC = 0;
            self->u68 = 0;
            self->u84 = 0;
            self->u88 = 0;
            self->u1C0 = 999999.0f;
            self->u1C4 = 0;
            self->u1D0 = 0;
            if (!WeaponInv_IsFullAuto(self->actor->inv))
                self->u8C = 0.2f + 0.01f * (float)(unsigned int)(self->actor->id & 0xF);
            else
                self->u8C = 0.0f;
            if (self->f5) {
                self->f5 = 0;
                self->uB0 = self->s103();
                self->s106();
                self->uB4 = self->s103();
                self->s105(self->uB0);
            }
            {
                Actor *a3 = self->actor;
                if (!a3->s29()) {
                    int j;
                    unsigned char *p = D_0055C780;
                    for (j = 0; j < 4; j++, p++) {
                        if (*p == 2) {
                            int me;
                            LOCALID(me);
                            if (j != me) {
                                int id;
                                Msg m;
                                LOCALID(id);
                                Event_Construct(&m, D_00582760);
                                m.vt = D_004E0F00;
                                m.id = id;
                                m.b28 = 0;
                                Transport_Send(self->actor->id, &m, -1, j);
                                m.vt = D_004E0F00;
                                cMessage_dtor(&m, 0);
                            }
                        }
                    }
                }
            }
            self->active = 0;
        }
    }
}
