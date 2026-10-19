/*
 * main/GameGOBJ: range (5 files, 00212AE0-002135C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "vslot_pad.h"

/* merge_units: begin func_00212AE0 */
#pragma push /* merge_units */
typedef struct { char d[0x9C]; } Str_00212AE0;
typedef struct {
    void* vt;
    char pad4[0x74];
    Str_00212AE0 s78;
    Str_00212AE0 s114;
    char pad1B0[0x20];
} __attribute__((aligned(16))) Snd2_00212AE0;
typedef struct SndObj_00212AE0 {
    char pad0[0x60]; char preset[0x1F0 - 0x60]; unsigned char playing; unsigned char active; unsigned char local;
} SndObj_00212AE0;
extern int g_LocalPlayer;
extern char g_Game[];
extern char D_004DADF0[];
extern int Event_Send(void* m, void* target, int immediate);
extern int cMessage_dtor(void* m, int flags);
extern void SoundStopMsg_Ctor(Snd2_00212AE0* e, void* preset, void* owner);
extern int FileMan_Release(Str_00212AE0* s, int flag);
extern void Object_Deactivate(SndObj_00212AE0* self, int arg);
void cSoundGOBJ_v16(SndObj_00212AE0* self, int arg)
{
    Snd2_00212AE0 c;
    if (self->active) {
        SndObj_00212AE0* owner;
        if (self->local)
            owner = self;
        else if (g_LocalPlayer)
            owner = 0;
        else
            owner = self;
        SoundStopMsg_Ctor(&c, self->preset, owner);
        Event_Send(&c, g_Game, 1);
        c.vt = D_004DADF0;
        FileMan_Release(&c.s114, -1);
        FileMan_Release(&c.s78, -1);
        cMessage_dtor(&c, 0);
        self->playing = 0;
    }
    Object_Deactivate(self, arg);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00212AE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00212AE0 */

/* merge_units: begin func_00212BB0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
#if 0 /* merge_units */
int Event_Send(char **, char *, int);
#endif /* merge_units */
#define Event_Send(a0, a1, a2) (Event_Send((void *)(a0), (void *)(a1), (a2))) /* merge_units */
                         
int Object_Activate(char * , int);                       
int SoundEvent_CtorFromPreset(char **, char * , char * );  
#if 0 /* merge_units */
int cMessage_dtor(char **, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */
                           
#if 0 /* merge_units */
int FileMan_Release(char *, int);
#endif /* merge_units */
#define FileMan_Release(a0, a1) (FileMan_Release((void *)(a0), (a1))) /* merge_units */
                            
extern char D_004DAE30;
#if 0 /* merge_units */
extern char g_Game;
#endif /* merge_units */
#define g_Game (*(char*)&g_Game) /* merge_units */

void func_001C6700(); /* gsynth: address taken */
#define func_001C6700 (*(char *)func_001C6700) /* merge_units */

#pragma opt_common_subs off
void cSoundGOBJ_v15(char * arg0, int arg1) {
    struct { char * f30[8]; signed char f50[88]; int fA8[39]; int f144[43]; } sl;
    char * var_a2;

    if (F_(arg0, 0x1F1, unsigned char) != 0) {
        var_a2 = NULL;
        if (F_(arg0, 0x1F2, unsigned char) != 0) {
            var_a2 = arg0;
        }
        if (F_(arg0, 0x1F0, unsigned char) == 0) {
            F_(arg0, 0x1F0, unsigned char) = 1U;
            SoundEvent_CtorFromPreset(sl.f30, arg0 + 0x60, var_a2);
            if (&func_001C6700 == NULL) {
                sl.f50[0] = 1;
            }
            Event_Send(sl.f30, &g_Game, 1);
            sl.f30[0] = &D_004DAE30;
            FileMan_Release(sl.f144, -1);
            FileMan_Release(sl.fA8, -1);
            cMessage_dtor(sl.f30, 0);
        }
    }
    Object_Activate(arg0, arg1);
}
#undef func_001C6700 /* merge_units */
#undef Event_Send /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef FileMan_Release /* merge_units */
#undef g_Game /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00212BB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00212BB0 */

/* merge_units: begin func_00212C80 */
#pragma push /* merge_units */
typedef struct { char d[0x9C]; } Str_00212C80;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Str_00212C80 s78;
    Str_00212C80 s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) Snd_00212C80;
typedef struct {
    void* vt;
    char pad4[0x74];
    Str_00212C80 s78;
    Str_00212C80 s114;
    char pad1B0[0x20];
} __attribute__((aligned(16))) Snd2_00212C80;
typedef struct SndObj_00212C80 {
    char pad0[0x60]; char preset[0x1F0 - 0x60]; unsigned char playing; char pad1F1; unsigned char local;
} SndObj_00212C80;
extern int g_TriggerMsgKey;
extern int g_cEnableMsgClass;
extern int g_cDisableMsgClass;
#if 0 /* merge_units */
extern char D_004DAE30[];
#endif /* merge_units */
#define D_004DAE30 ((char*)&D_004DAE30) /* merge_units */

extern int* Event_GetType(void* ev);
#if 0 /* merge_units */
extern int SoundEvent_CtorFromPreset(Snd_00212C80* e, void* preset, void* owner);
#endif /* merge_units */
#define SoundEvent_CtorFromPreset(a0, a1, a2) (SoundEvent_CtorFromPreset((void *)(a0), (void *)(a1), (void *)(a2))) /* merge_units */

#if 0 /* merge_units */
extern void SoundStopMsg_Ctor(Snd2_00212C80* e, void* preset, void* owner);
#endif /* merge_units */
#define SoundStopMsg_Ctor(a0, a1, a2) (SoundStopMsg_Ctor((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern int FileMan_Release(Str_00212C80* s, int flag);
#endif /* merge_units */
#define FileMan_Release(a0, a1) (FileMan_Release((void *)(a0), (a1))) /* merge_units */

extern void func_001C6700();
extern int Object_HandleMessage(SndObj_00212C80* self, void* ev);
static inline SndObj_00212C80* Owner_00212C80(SndObj_00212C80* o) { return o->local ? o : 0; }
static inline void Play_00212C80(SndObj_00212C80* self, Snd_00212C80* s)
{
    SndObj_00212C80* owner = Owner_00212C80(self);
    if (!self->playing) {
        self->playing = 1;
        SoundEvent_CtorFromPreset(s, self->preset, owner);
        if (!func_001C6700)
            s->flag = 1;
        Event_Send(s, g_Game, 1);
        s->vt = D_004DAE30;
        FileMan_Release(&s->s114, -1);
        FileMan_Release(&s->s78, -1);
        cMessage_dtor(s, 0);
    }
}
int cSoundGOBJ_v01(SndObj_00212C80* self, void* ev)
{
    Snd_00212C80 a;
    Snd_00212C80 b;
    Snd2_00212C80 c;
    int t = *Event_GetType(ev);
    if (t == g_TriggerMsgKey) {
        Play_00212C80(self, &a);
        return 1;
    }
    t = *Event_GetType(ev);
    if (t == g_cEnableMsgClass) {
        if (!self->local) {
            Play_00212C80(self, &b);
            return 1;
        }
    } else {
        t = *Event_GetType(ev);
        if (t == g_cDisableMsgClass && !self->local) {
            SndObj_00212C80* owner;
            if (self->local)
                owner = self;
            else if (g_LocalPlayer)
                owner = 0;
            else
                owner = self;
            SoundStopMsg_Ctor(&c, self->preset, owner);
            Event_Send(&c, g_Game, 1);
            c.vt = D_004DADF0;
            FileMan_Release(&c.s114, -1);
            FileMan_Release(&c.s78, -1);
            cMessage_dtor(&c, 0);
            self->playing = 0;
            return 1;
        }
    }
    return Object_HandleMessage(self, ev);
}
#undef D_004DAE30 /* merge_units */
#undef SoundEvent_CtorFromPreset /* merge_units */
#undef SoundStopMsg_Ctor /* merge_units */
#undef FileMan_Release /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00212C80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00212C80 */

/* merge_units: begin func_00212EE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma exceptions off
/* undocumented mwcc pragma: keeps the temp handle copy as addiu+lw 0(reg) like retail */
#pragma opt_prelinearize off
struct V4 { float x, y, z, w; };
struct Mtx { V4 r[4]; };
struct H_212EE0 { int v; };
struct HT_212EE0 { int v; HT_212EE0() { v = -1; } };
struct Act_212EE0 {
    int id;
    char pad04[0xC];
    __int128 mask;
    int w20;
    H_212EE0 h24;
    char pad28[8];
    int w30, w34, w38;
    char pad3C[0x0C];
    char memberA[0x9C];
    char memberB[0x9C];
    int w180;
    short h184;
    unsigned char b186;
    char pad187[9];
};
struct Node_212EE0 { int a; int b; int c; };
struct Reader { int version; int a, b; char* cur; };
struct SoundGOBJ {
    VPAD16(a) VPAD4(b) VPAD2(c) virtual void Enable(int); VPAD8(d) VPAD2(e) VPAD1(f) virtual void SetMatrix(Mtx*, int);
    char p4[8]; int id; char p10[8]; Node_212EE0* node; char p1c[0x60 - 0x1C];
    Act_212EE0 snd;
    unsigned char b1F0; unsigned char type; unsigned char b1F2;
};
extern "C" {
extern char D_004F54B8[], D_004DAF30[], D_0049C088[];
void cGOBJ_ctor(SoundGOBJ*, int*, int, void*);
void Resource_Construct(void* m);
void* Mem_Alloc(int, int, char*, int);
void Script_LookupResource(Node_212EE0* n, char* name);
void Mtx_SetBasis(Mtx* m, V4* a, V4* b, V4* c);
void Mtx_SetTranslation(Mtx* m, V4* t);
void SoundAction_CtorVoice(void* action, int kind, char* name, void* a, int b);
void Node_ClearLocalMatrix(SoundGOBJ*);
int IdMgr_FindCollision(int, int);
void ZoneMgr_Associate(int, SoundGOBJ*, int, int);
}
static inline int Read(Reader* r) { int v = *(int*)r->cur; r->cur += 4; return v; }
static inline void ReadInt(Reader* r, int* out) { *out = *(int*)r->cur; r->cur += 4; }
static inline float ReadF(Reader* r) { float v = *(float*)r->cur; r->cur += 4; return v; }
static inline void Align(Reader* r)
{
    int rem;
    char* ptr = r->cur;
    rem = (int)((unsigned long long)(unsigned int)ptr & 3);
    if (rem) r->cur = ptr + (4 - rem);
}
static inline void ReadV(Reader* r, V4* v, float w)
{
    float x = ReadF(r);
    float y = ReadF(r);
    float z = ReadF(r);
    v->x = x; v->y = y; v->z = z; v->w = w;
}
#pragma push
//#pragma opt_propagation off
extern "C" SoundGOBJ* cSoundGOBJ_ctor(SoundGOBJ* obj, Reader* r, unsigned char type)
{
    int regions[0x100];
    int ids[0x100];
    V4 r0, r1, r2, pos;
    Mtx m;
    int hi, lo, n, i, ver;
    char* name;
    char* tag;
    Act_212EE0* p;
    int gid = -1;
    cGOBJ_ctor(obj, &gid, 0xB, D_004F54B8);
    *(void**)obj = D_004DAF30;
    p = &obj->snd;
    obj->snd.h24.v = -2;
    obj->snd.w20 = 0;
    Resource_Construct(p->memberA);
    Resource_Construct(p->memberB);
    p->id = -1;
    p->mask = -1;
    p->w20 = 0;
    p->h24 = *(H_212EE0*)&HT_212EE0();
    p->w30 = 0;
    p->w34 = 0;
    p->w38 = 0;
    p->h184 = -1;
    p->w180 = 0;
    p->b186 = 0;
    ReadInt(r, &hi);
    ReadInt(r, &lo);
    name = r->cur;
    while (*r->cur++) ;
    Align(r);
    tag = r->cur;
    while (*r->cur++) ;
    if (tag) {
        if (!obj->node) {
            Node_212EE0* nd;
            {
                AllocGuard g;
                nd = (Node_212EE0*)Mem_Alloc(0, 12, D_0049C088, 0x49);
            }
            if (nd) { nd->a = 0; nd->b = 0; nd->c = -1; }
            obj->node = nd;
        }
        Script_LookupResource(obj->node, tag);
    }
    Align(r);
    ReadV(r, &pos, 1.0f);
    ReadV(r, &r0, 0.0f);
    ReadV(r, &r1, 0.0f);
    ReadV(r, &r2, 0.0f);
    Mtx_SetBasis(&m, &r0, &r1, &r2);
    Mtx_SetTranslation(&m, &pos);
    obj->id = lo | (hi << 16);
    n = Read(r);
    for (i = 0; i < n; i++) {
        ReadInt(r, &regions[i]);
        ReadInt(r, &ids[i]);
    }
    obj->type = type;
    obj->b1F2 = *(unsigned char*)r->cur;
    r->cur++;
    Align(r);
    ver = 0;
    if (r->version > 0x34) ver = Read(r);
    SoundAction_CtorVoice(&obj->snd, ver, name, obj, 0);
    Node_ClearLocalMatrix(obj);
    obj->SetMatrix(&m, 0);
    obj->Enable(1);
    for (i = 0; i < n; i++) {
        if (regions[i] != -1 && ids[i] != -1) {
            int c = IdMgr_FindCollision(regions[i], ids[i]);
            if (c) ZoneMgr_Associate(c, obj, 1, c);
        }
    }
    obj->b1F0 = 0;
    return obj;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00212EE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00212EE0 */

/* merge_units: begin func_002135C0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char d[0x9C]; } LuStr;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    LuStr s78;
    LuStr s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) LuSnd;
typedef struct { void* vtable; char base[0x20]; int kind; int arg; } LuMsg;
struct LuShm { int f0; int f4; };
struct LuSeg { char pad[0x1C]; LuShm* p1C; };
struct LuCtl { int f0; char pad4[0x1C]; int f20; char pad24[4]; int f28; };
struct LuQ { __int128 q; LuQ() {} LuQ(const LuQ& o) { const LuQ* s = &o; LuQ* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); } };
struct LuSub {
    VPAD16(a) VPAD4(b)
    virtual void Sync();
    char pad4[0x40 - 4];
    LuQ pos;
    unsigned char f50;
};
struct LuIt { void** p; };
struct LuVec;
struct Lift {
    VPAD32(a)
    virtual void Refresh();
    char pad4[8];
    int fC;
    char pad10[0x50 - 0x10];
    LuSub* sub;
    char pad54[0x70 - 0x54];
    int f70;
    char pad74[0xDC - 0x74];
    unsigned char fDC;
    char padDD[3];
    int fE0;
    char padE4[0x128 - 0xE4];
    LuCtl* ctl;
    int floors[5];
    int nFloors;
    char pad144[0x2E0 - 0x144];
    char preset2[0x470 - 0x2E0];
    char preset1[0x790 - 0x470];
    LuShm* shm;
};
extern "C" {
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern unsigned char D_005721D0;
extern int D_004F54A0;
extern int D_0048AAE8;
extern char D_004A44D0[];
extern char D_004A44F0[];
extern char D_004F5448[];
extern char D_004DAED0[];
#if 0 /* merge_units */
extern char D_004DAE30[];
#endif /* merge_units */
#define D_004DAE30 ((char*)&D_004DAE30) /* merge_units */

int Net_GetClock(int a);
int func_002EAF28(int* h, int a, int b, int c, int d, int e, int f, void* buf, char* name, int size);
int func_002EB650(LuSeg** o, int h);
void printf(char* s, int h, int n);
void func_002EC460(int h);
void* World_GetActorArray(void);
LuVec* func_001339A0(void* arr);
void PtrVec_End(LuIt* out, LuVec* v);
void func_00133980(LuIt* out, LuIt* in);
void PathObj_Update(Lift* l, float dt);
int cElevatorGOBJ_DoorsOpen(Lift* l);
int cElevatorGOBJ_DoorsClosed(Lift* l);
void Lift_CloseDoors(Lift* l);
void Lift_OpenDoors(Lift* l);
void Lift_FinishArrival(Lift* l);
void Lift_ActivateRecipients(Lift* l);
void Lift_SeekFloor(Lift* l, int floor, int a2, int a3);
void Event_Construct(LuMsg* m, void* type);
int Event_Send(void* m, void* target, int immediate);
int cMessage_dtor(void* m, int flags);
#if 0 /* merge_units */
int SoundEvent_CtorFromPreset(LuSnd* e, void* preset, Lift* l);
#endif /* merge_units */
#define SoundEvent_CtorFromPreset(a0, a1, a2) (SoundEvent_CtorFromPreset((char * *)(a0), (char *)(a1), (char *)(a2))) /* merge_units */

#if 0 /* merge_units */
int FileMan_Release(LuStr* s, int flag);
#endif /* merge_units */
#define FileMan_Release(a0, a1) (FileMan_Release((Str_00212AE0 *)(a0), (a1))) /* merge_units */

}
static inline bool LuIsHost(void) { unsigned char r; if (g_IsMultiplayer) r = D_005721C0; else r = true; return r; }
static inline LuShm* LuCreate(void)
{
    int h;
    LuSeg* seg;
    LuShm* r = 0;
    if (!LuIsHost() || !D_005721D0) return 0;
    {
        if (!func_002EAF28(&h, 2, 3, 0, 0, 0, 0, 0, D_004A44D0, D_0048AAE8)) {
            if (!func_002EB650(&seg, h)) {
                r = seg->p1C;
                r->f4 = h;
                printf(D_004A44F0, h, 8);
            }
        }
    }
    return r;
}
static inline void LuGetEnd(LuIt* o, LuVec* v) { LuIt te; PtrVec_End(&te, v); func_00133980(o, &te); }
extern "C" void Lift_Update(Lift* l, float dt)
{
    LuIt it;
    if (g_IsMultiplayer && LuIsHost()) {
        if (!l->shm && D_004F54A0 < Net_GetClock(1)) {
            l->shm = LuCreate();
            if (l->shm) {
                int id = l->fC;
                l->shm->f0 = id;
                func_002EC460(l->shm->f4);
            }
            D_004F54A0 = Net_GetClock(1) + 500;
        }
    }
    LuGetEnd(&it, func_001339A0(World_GetActorArray()));
    LuSub* s = l->sub;
    if (s->f50) s->Sync();
    LuQ p = s->pos;
    l->Refresh();
    PathObj_Update(l, dt);
    LuCtl* c = l->ctl;
    switch (c->f28) {
    case 0:
        if (c->f20 != c->f0) c->f28 = 1;
        break;
    case 1:
        if (!l->fDC) break;
        if (c->f20 != c->f0) {
            if (l->f70 > 0 && cElevatorGOBJ_DoorsOpen(l)) {
                Lift_CloseDoors(l);
                break;
            }
            if (!cElevatorGOBJ_DoorsClosed(l) && l->f70 > 0) break;
            {
                LuSnd ev1;
                LuSnd ev2;
                SoundEvent_CtorFromPreset(&ev1, l->preset1, l);
                ev1.flag = 1;
                SoundEvent_CtorFromPreset(&ev2, l->preset2, l);
                ev2.flag = 1;
                Event_Send(&ev1, g_Game, 1);
                Event_Send(&ev2, g_Game, 1);
                l->fDC = 0;
                l->fE0 = 0;
                ev2.vt = D_004DAE30;
                FileMan_Release(&ev2.s114, -1);
                FileMan_Release(&ev2.s78, -1);
                cMessage_dtor(&ev2, 0);
                ev1.vt = D_004DAE30;
                FileMan_Release(&ev1.s114, -1);
                FileMan_Release(&ev1.s78, -1);
                cMessage_dtor(&ev1, 0);
            }
            break;
        }
        if (l->f70 <= 0) Lift_FinishArrival(l);
        if (l->f70 > 0 && cElevatorGOBJ_DoorsClosed(l)) {
            if (!g_IsMultiplayer || LuIsHost()) {
                LuMsg msg;
                LuMsg* m = &msg;
                Event_Construct(m, D_004F5448);
                m->vtable = D_004DAED0;
                m->kind = 0;
                m->arg = 0;
                Event_Send(m, l, 0);
                msg.vtable = D_004DAED0;
                cMessage_dtor(m, 0);
            }
            Lift_OpenDoors(l);
            break;
        }
        if (!cElevatorGOBJ_DoorsOpen(l) && l->f70 > 0) break;
        l->ctl->f28 = 0;
        Lift_ActivateRecipients(l);
        {
            int f = -1;
            if (l->nFloors) {
                l->nFloors--;
                f = l->floors[l->nFloors];
            }
            if (f != -1) Lift_SeekFloor(l, f, 1, 0);
        }
        break;
    }
}
#undef D_004DAE30 /* merge_units */
#undef SoundEvent_CtorFromPreset /* merge_units */
#undef FileMan_Release /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002135C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002135C0 */
