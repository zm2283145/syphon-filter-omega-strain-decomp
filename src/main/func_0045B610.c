#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
/* Flashlight_SetState: switch the flashlight on/off (sound, inventory notice, create/destroy its lights) */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) Pt1FsV4;
struct Pt1FsId { int a, b, c, d; Pt1FsId() {} } __attribute__((aligned(16)));
typedef struct { char d[0x9C]; } Pt1FsStr;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Pt1FsStr s78;
    Pt1FsStr s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) Pt1FsSnd;
struct Pt1FsLightBase { signed char kind; unsigned char flag1; };
struct Pt1FsLight : Pt1FsLightBase {
    virtual void Destroy(int flags);
    VPAD8(a)
    virtual void Enable();
    char pad8[4];
    float intensity;
    char pad10[8];
    int id;
    unsigned char enabled;
    unsigned char aux;
    unsigned char type;
    char pad1F;
    Pt1FsV4 pos;
    Pt1FsV4 dir;
    int extra;
};
struct Pt1FsActor {
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e)
    virtual Pt1FsId GetId();
    char pad4[0x3524 - 4];
    void* weapons;
};
typedef struct Pt1FsSelf {
    unsigned char on;
    char pad1[3];
    Pt1FsActor* owner;
    Pt1FsLight* beam;
    Pt1FsLight* glow;
    float level;
    char pad14[4];
    int visId;
} Pt1FsSelf;
extern char g_FlashlightClickSound[];
extern char D_004FFB50[];
extern char D_004DAE30[];
extern char D_00535D20[];
extern char D_004D9280[];
extern char D_004D9240[];
extern char D_004D9200[];
extern "C" void FlashGlare_GetCoronaFlag();
extern "C" void FlashGlare_GetCoronaSize();
extern "C" void FlashGlare_GetRange();
extern "C" void Flashlight_ReleaseGlare();
extern "C" void Light_Disable();
extern "C" void Light_SetPosition();
extern "C" void Light_Enable();
extern "C" void func_001479A0();
extern "C" void func_001479D0();
extern "C" void func_00147A00();
extern "C" void func_00147A10();
void * const D_004E15E0[16] = { (void*)0x0, (void*)0x0, (void*)Flashlight_ReleaseGlare, (void*)func_001479D0, (void*)0x1479E0, (void*)func_00147A00, (void*)func_00147A10, (void*)func_001479A0, (void*)FlashGlare_GetCoronaSize, (void*)FlashGlare_GetCoronaFlag, (void*)Light_SetPosition, (void*)Light_Enable, (void*)Light_Disable, (void*)FlashGlare_GetRange, (void*)0x0, (void*)0x0 };
extern char g_TargetVisMgr[];
extern signed char D_004979B0;
extern unsigned char D_00535D62;
extern "C" void SoundPosRequest_Ctor(Pt1FsSnd* e, void* preset, Pt1FsId* id);
extern "C" void Event_Send(void* msg, void* target, int immediate);
extern "C" void cMessage_dtor(void* msg, int flags);
extern "C" void func_0036E220(Pt1FsStr* s, int flag);
extern "C" void WeaponInv_SetSlotModelState(void* weapons, int item, int state);
extern "C" Pt1FsLight* LightMgr_AllocPoint(void* pool, int kind);
extern "C" Pt1FsV4* func_00426890(Pt1FsV4* out, float r, float g, float b, float a);
extern "C" Pt1FsV4* func_00132000(Pt1FsV4* out, float x, float y, float z, float w);
extern "C" void LevelLight_InitPoint(Pt1FsLight* l, int flags, Pt1FsV4* color, Pt1FsV4* pos, int range);
extern "C" void TargetVis_Register(void* reg, int id);
extern "C" void TargetVis_Unregister(void* reg, int id);

extern "C" void Flashlight_SetState(Pt1FsSelf* self, int on)
{
    if ((unsigned char)on == self->on)
        return;
    if (self->owner) {
        Pt1FsId id = self->owner->GetId();
        Pt1FsSnd snd;
        SoundPosRequest_Ctor(&snd, g_FlashlightClickSound, &id);
        snd.flag = 1;
        Event_Send(&snd, D_004FFB50, 0);
        WeaponInv_SetSlotModelState(self->owner->weapons, 7, on);
        snd.vt = D_004DAE30;
        func_0036E220(&snd.s114, -1);
        func_0036E220(&snd.s78, -1);
        cMessage_dtor(&snd, 0);
    }
    self->on = on;
    if (self->on) {
        Pt1FsLight* l = LightMgr_AllocPoint(D_00535D20, 4);
        if (l) {
            *(void**)((char*)l + 4) = D_004D9280;
            l->kind = D_004979B0;
            l->flag1 = 0;
            *(void**)((char*)l + 4) = D_004D9240;
            l->intensity = 0.0f;
            l->enabled = 0;
            l->aux = 3;
            l->type = 4;
            l->pos.x = 0.0f;
            l->pos.y = 0.0f;
            l->pos.z = 0.0f;
            l->pos.w = 0.0f;
            l->dir.x = 0.0f;
            l->dir.y = 0.0f;
            l->dir.z = 0.0f;
            l->dir.w = 1.0f;
            D_00535D62 = 1;
            l->id = 0;
            *(void**)((char*)l + 4) = D_004D9200;
        }
        self->beam = l;
        l = LightMgr_AllocPoint(D_00535D20, 4);
        if (l) {
            Pt1FsV4 color;
            Pt1FsV4 pos;
            LevelLight_InitPoint(l, 0x40, func_00426890(&color, 1.0f, 1.0f, 1.0f, 1.0f), func_00132000(&pos, 0.0f, 0.0f, 0.0f, 0.0f), 0x10);
            *(void**)((char*)l + 4) = ((char*)D_004E15E0);
            l->extra = 0;
        }
        self->glow = l;
        self->level = -1.0f;
        if (self->beam) {
            TargetVis_Register(g_TargetVisMgr, self->visId);
            self->beam->Enable();
        }
        if (self->glow)
            self->glow->Enable();
    } else {
        if (self->beam) {
            TargetVis_Unregister(g_TargetVisMgr, self->visId);
            if (self->beam)
                self->beam->Destroy(1);
            self->beam = 0;
        }
        if (self->glow) {
            if (self->glow)
                self->glow->Destroy(1);
            self->glow = 0;
        }
    }
}