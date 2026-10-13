#include "types.h"
typedef struct { char d[0x9C]; } Str_FB90;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Str_FB90 s78;
    Str_FB90 s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) Snd_FB90;
typedef struct {
    char pad0[0x48];
    Str_FB90 s48;
    Str_FB90 sE4;
    char pad180[0x10];
} __attribute__((aligned(16))) Req_FB90;
typedef struct { int f0; int id; int clip; int reserve; } Ent_FB90;
typedef struct {
    char pad0[4];
    Ent_FB90 ent[7];
    char pad74[0x10];
    unsigned char cur;
    char pad85[3];
    void* owner;
    char pad8C[0xD];
    unsigned char f99;
} W_FB90;
typedef struct { char pad0[0x20]; char snd[0x50]; int clipSize; char pad74[0x98]; int f10C; } Db_FB90;
extern int D_004FFD30;
extern char D_004FFB50[];
extern char D_004DAE30[];
Db_FB90* WeaponDb_Get(int db, int id);
int Weapon_TransferSpareRounds(W_FB90* w, int n, int kind);
void SoundRequest_Ctor(Req_FB90* r, int a, void* preset, int b, int c);
void SoundEvent_CtorFromPreset(Snd_FB90* e, Req_FB90* r, void* owner);
void Event_Send(void* msg, void* target, int immediate);
void cMessage_dtor(void* msg, int flags);
void func_0036E220(Str_FB90* s, int flag);

void Weapon_StartReload(W_FB90* self)
{
    Ent_FB90* e;
    Db_FB90* db;
    int need;
    int extra;
    if (self->cur == 6)
        return;
    e = &self->ent[self->cur];
    if (e->id == -1)
        return;
    db = WeaponDb_Get(D_004FFD30, e->id);
    need = db->clipSize - e->clip;
    extra = 0;
    if (e->reserve < need) {
        extra = Weapon_TransferSpareRounds(self, need - e->reserve, db->f10C);
        need = e->reserve;
    }
    e->clip += need + extra;
    if (!self->f99)
        e->reserve -= need;
    if (self->cur == 0) { unsigned char v = self->ent[1].id == -1; if (v ^ 1) {
        self->ent[1].clip = e->clip;
        self->ent[1].reserve = e->reserve;
    }}
    {
        Req_FB90 req;
        Snd_FB90 snd;
        SoundRequest_Ctor(&req, 1, db->snd, 0, 0);
        SoundEvent_CtorFromPreset(&snd, &req, self->owner);
        snd.flag = 1;
        Event_Send(&snd, D_004FFB50, 0);
        snd.vt = D_004DAE30;
        func_0036E220(&snd.s114, -1);
        func_0036E220(&snd.s78, -1);
        cMessage_dtor(&snd, 0);
        func_0036E220(&req.sE4, -1);
        func_0036E220(&req.s48, -1);
    }
}




