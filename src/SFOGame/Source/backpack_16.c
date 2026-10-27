/*
 * SFOGame/Source/backpack: 13 files, 00257A40-002589E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00257A40 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"

struct Owner_7A40 { char pad0[0xC]; int id; };

struct BP_7A40 {
    char pad00[0x60];
    unsigned char b60;
    char pad61[0x2F2 - 0x61];
    unsigned char b2F2;
    char pad2F3[0x2FC - 0x2F3];
    void* fx;
    Owner_7A40* holder;
    int holderId;
    int owner;
    int level;
    float dist;
    float timer;
    bool NoHolder() { return !Holder(); }
    Owner_7A40* Holder() { bool n = !holder; return (n || holder->id == holderId) ? holder : 0; }
};

struct List_7A40 { int pad0; int count; BP_7A40** items; };

extern "C" {
extern List_7A40* g_BackpackList;
extern int D_0048AF10;
extern int D_00494178;
extern int D_005721A8;
extern unsigned char g_IsMultiplayer;
extern int g_HotboxTracker;
int cHuman_CanPackBeDeleted(Owner_7A40* o);
int NetGetMyClientIndex(int*, int);
void cHotboxMan_RemoveHotbox(int, void*);
int nGobjManager_RemoveGOBJ(void*);
int cSystem_ActualScheduleDelete(void*, float);
}

static inline bool HolderReady(BP_7A40* bp) {
    bool r = true;
    if (!bp->NoHolder() && !cHuman_CanPackBeDeleted(bp->Holder())) r = false;
    return r;
}

#pragma opt_strength_reduction off
extern "C" void cBackpack_GarbageCollect(void) {
    List_7A40* list = g_BackpackList;
    int n;
    int cnt;
    int i;
    if (!list) return;
    n = list->count;
    cnt = 0;
    for (i = 0; i < n; i++) {
        BP_7A40* bp = list->items[i];
        if (bp->b60 == 0 && bp->level > 1) {
            if (HolderReady(bp)) cnt++;
        }
    }
    if (cnt > D_0048AF10) {
        int best = 0;
        int me;
        {
            int a = D_005721A8;
            if (g_IsMultiplayer) {
                if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, a);
                me = D_00494178;
            } else me = 0;
        }
        int j;
        for (j = 0; j < n; j++) {
            BP_7A40* bp = list->items[j];
            if (!g_IsMultiplayer || bp->owner == me) {
                if (HolderReady(bp)) {
                    if (bp->level > best && !bp->b2F2 && bp->timer < 0.0f) best = bp->level;
                }
            }
        }
        if (best > 1) {
            BP_7A40* sel = 0;
            float bestd = 1e7f;
            int k;
            for (k = 0; k < n; k++) {
                BP_7A40* bp = list->items[k];
                if (!g_IsMultiplayer || bp->owner == me) {
                    if (HolderReady(bp) && bp->level == best && !bp->b2F2 && bp->timer < 0.0f) {
                        if (bp->dist < bestd) {
                            bestd = bp->dist;
                            sel = bp;
                        }
                    }
                }
            }
            sel->b2F2 = 1;
            sel->timer = 0.0f;
            if (sel->fx) {
                cHotboxMan_RemoveHotbox(g_HotboxTracker, sel->fx);
                nGobjManager_RemoveGOBJ(sel->fx);
                cSystem_ActualScheduleDelete(sel->fx, 0.1f);
                sel->fx = 0;
            }
        }
    }
}
static inline void merge_flush_func_00257A40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00257A40 */

/* merge_units: begin func_00257E90 */
#pragma push /* merge_units */
#include "vslot_pad.h"

typedef struct Backpack{void*vt;char pad[0x2F8];void*actor;}Backpack;
extern char D_004DC350[];
#if 0 /* merge_units */
extern void*g_HotboxTracker;
#endif /* merge_units */
#define g_HotboxTracker (*(void **)&g_HotboxTracker) /* merge_units */

#if 0 /* merge_units */
void cHotboxMan_RemoveHotbox(void*,void*);
#endif /* merge_units */
#define cHotboxMan_RemoveHotbox(a0, a1) (cHotboxMan_RemoveHotbox((int)(a0), (a1))) /* merge_units */
#if 0 /* merge_units */
void nGobjManager_RemoveGOBJ(void*);
#endif /* merge_units */
#define nGobjManager_RemoveGOBJ(a0) ((void)nGobjManager_RemoveGOBJ((a0))) /* merge_units */
#if 0 /* merge_units */
void cSystem_ActualScheduleDelete(void*,float);
#endif /* merge_units */
#define cSystem_ActualScheduleDelete(a0, a1) ((void)cSystem_ActualScheduleDelete((a0), (a1))) /* merge_units */
void cGOBJ_dtor(Backpack*,int);void operator_delete(void*);
Backpack*cBackpack_dtor(Backpack*self,int flags){
 if(self){self->vt=D_004DC350;if(self->actor){cHotboxMan_RemoveHotbox(g_HotboxTracker,self->actor);nGobjManager_RemoveGOBJ(self->actor);cSystem_ActualScheduleDelete(self->actor,0.1f);self->actor=0;}
 cGOBJ_dtor(self,0);if((short)flags>0)operator_delete(self);}
 return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00257E90(void) {}
#undef g_HotboxTracker /* merge_units */
#undef cHotboxMan_RemoveHotbox /* merge_units */
#undef nGobjManager_RemoveGOBJ /* merge_units */
#undef cSystem_ActualScheduleDelete /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00257E90 */

/* merge_units: begin func_00257F30 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
extern "C" void cBackpack_Clear(void* self, int preserve); /* gsynth: defined below */
#pragma pop
#pragma cplusplus on
#pragma push
#pragma inline_depth(12)
#pragma opt_propagation off
struct V4 {float x,y,z,w;};
struct Transform {VPAD2(a) VPAD1(b) virtual void set(V4*);};
struct Link {char pad[0x94];int id;};
struct Backpack_00257F30 {
 VPAD16(a) VPAD4(b) VPAD1(c) virtual void active(int); VPAD8(d) VPAD4(e) virtual void attach(void*,int);
 char p4[8];int id;char p10[0x40];Transform* transform;char p54[0xC];unsigned char ready;char p61[0x283];int count,a2e8,a2ec;unsigned char dropped;char p2f1[7];int x2f8;Link* link;int x300,x304,x308,x30c;float timer;int x314;
};
struct Reader {int version;int a,b;char* cur;};
struct Weapon {char p0[0x70];int unit;char p74[0x7C];unsigned char kind;};
extern "C" {
extern char D_004F7F68[],D_004DC350[],g_IdentityMatrix[];
extern int g_WeaponDatabase;

void cGOBJ_ctor(Backpack_00257F30*,int*,int,void*);
#if 0 /* merge_units */
void cBackpack_Clear(Backpack_00257F30*,int);
#endif /* merge_units */
#define cBackpack_Clear(a0, a1) ((void)cBackpack_Clear((void *)(a0), (a1))) /* merge_units */


Weapon* cWeaponDB_GetEntry(int,int);
void cBackpack_AddWeapon(Backpack_00257F30*,int,int,int,int);
void nGobjManager_AddGOBJ(Backpack_00257F30*);
Link* cHotboxMan_CreateInteractBox(int,Backpack_00257F30*,int,int);
int nGobjManager_LookupGOBJ_int_int(int,int);
void cTerrain_AddActivation(int,Backpack_00257F30*,int,int);
}
static inline int Read(Reader* r) {int v=*(int*)r->cur;r->cur+=4;return v;}
static inline void ReadFloat(Reader* r,float* out) {*out=*(float*)r->cur;r->cur+=4;}
static inline void Ensure(Backpack_00257F30* obj) {if(!obj->link){obj->active(1);nGobjManager_AddGOBJ(obj);if(!obj->link){obj->link=cHotboxMan_CreateInteractBox(g_HotboxTracker,obj,0,1);obj->link->id=obj->id;}}}
extern "C" Backpack_00257F30* cBackpack_ctor(Backpack_00257F30* obj0,Reader* r0) {
 int flag; int weapon;int slot;int n;int amount;Weapon* w;int j;Backpack_00257F30* obj=obj0;Reader* r=r0;
 int id=-1;
 V4 pos;
 cGOBJ_ctor(obj,&id,0,D_004F7F68);
 *(void**)obj=D_004DC350;obj->x304=-2;obj->x300=0;
 cBackpack_Clear(obj,0);obj->attach(g_IdentityMatrix,0);
 int hi=Read(r);int lo=Read(r);obj->id=lo|(hi<<16);
 ReadFloat(r,&pos.x);ReadFloat(r,&pos.y);ReadFloat(r,&pos.z);pos.w=1.0f;
 obj->transform->set(&pos);
 slot=0;do {
  weapon=Read(r);n=Read(r);amount=Read(r);
  if(r->version>=0x39) {flag=*(unsigned char*)r->cur;r->cur++;
   int remainder;char* ptr=r->cur;remainder=(int)((unsigned long long)(unsigned int)ptr&3);
   if(remainder)r->cur=ptr+(4-(int)remainder);
  }
  if(weapon>=0) {
   w=cWeaponDB_GetEntry(g_WeaponDatabase,weapon);
   if(amount>0 || !w->unit) {
    if(w->kind==1 || w->kind==7) {amount*=n;n=1;}
    j=0;if(0<n){do {cBackpack_AddWeapon(obj,weapon,(amount-1)*w->unit,w->unit,flag);j++;}while(j<n);}
   }
  }
 slot++;}while(slot<3);
 int item=Read(r);int copies=Read(r);
 if(copies>0 && item) {if(obj->count++==0){obj->a2e8=item;obj->a2ec=item;}Ensure(obj);}
 int region=Read(r);int child=Read(r);
 if(child!=-1 && region!=-1){int found=nGobjManager_LookupGOBJ_int_int(region,child);if(found)cTerrain_AddActivation(found,obj,1,0);else obj->active(1);}
 obj->x2f8=0;obj->dropped=0;obj->ready=1;Ensure(obj);
 obj->x30c=0;obj->timer=0;
 return obj;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00257F30(void) {}
#undef cBackpack_Clear /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00257F30 */

/* merge_units: begin func_00258330 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_propagation off
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off
#define F(p,o,t) (*(t*)((char*)(p)+(o)))
struct WeaponInfo{int a,b;int flags;int c;};
struct Tables{char pad[0x3524];WeaponInfo*weapons;};
struct World{char pad[0x30];Tables*tables;};
extern "C" World*g_LocalPlayer;
struct Id{volatile int value;Id(int v):value(v){}}; static inline const Id* Identity(const Id*p){return p;} static inline void Assign(Id*d,const Id*s){d->value=s->value;}
extern "C" void cBackpack_Clear(void*self,int preserve){
 WeaponInfo*weapons=g_LocalPlayer->tables->weapons;int i=0;char*p=(char*)self;
 do{int flags=weapons[F(p,0x64,unsigned char)].flags;if(!preserve||flags>-1){F(p,0x130,int)=0;F(p,0x134,unsigned char)=0;}i++;p+=0xD4;}while(i<3);
 if(!preserve){F(self,0x2FC,int)=0;F(self,0x30C,int)=2;}
 F(self,0x2E0,int)=3;F(self,0x2E4,int)=0;F(self,0x2F2,unsigned char)=0;F(self,0x300,int)=0;
 Assign(&F(self,0x304,Id),Identity(&Id(-1)));
 F(self,0x2F1,unsigned char)=0;F(self,0x2F3,unsigned char)=0;F(self,0x314,int)=0xBF800000;F(self,0x308,int)=0;F(self,0x2F4,unsigned char)=0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00258330(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00258330 */

/* merge_units: begin func_002583F0 */
#pragma push /* merge_units */
#include "backpack_types.h"

/*
 * Matched functions (byte-identical with the retail executable).
 * cInventoryMsg script natives and script type registration.
 */


extern int D_004F7EF8;
extern int D_004F7F00;
extern int cGOBJ_SOBJ_toInt(int who);
extern int* cMessage_SOBJ_getClassId(void);
extern void cScriptBase_declareParent(int type, int baseType);

int Script_cInventoryMsg_Who(cItemMsg** msg) {
    return cGOBJ_SOBJ_toInt((*msg)->who);
}

/* Volatile locals mirror the original stack temporaries. */
int Script_cInventoryMsg_Count(cItemMsg** msg) {
    volatile int count = (*msg)->count;
    return count;
}

int Script_cInventoryMsg_Taken(cItemMsg** msg) {
    volatile int taken = (*msg)->taken;
    return taken;
}

void cInventoryMsg_SOBJ_init(void) {
    int* base = cMessage_SOBJ_getClassId();
    cScriptBase_declareParent(D_004F7F00, *base);
}

int cInventoryMsg_v03(void) {
    return D_004F7EF8;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002583F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002583F0 */

/* merge_units: begin func_00258480 */
#pragma push /* merge_units */
extern unsigned char* D_005061D0; /* network read cursor */

static inline short read16(void)
{
    unsigned char lo = *D_005061D0++;
    unsigned char hi = *D_005061D0++;
    return lo + (hi << 8);
}

static inline int read32(void)
{
    unsigned short lo = read16();
    return lo + ((unsigned short)read16() << 16);
}

typedef struct { char pad[0x20]; unsigned char received; char pad21[3]; int a; int b; char item[1]; } cInventoryMsg;
extern void cNetMsg_GetGOBJ(void* item);
extern void QueueMessage_cMessageR_cSystemP_int(cInventoryMsg* msg, void* target, int flags);

/* cInventoryMsg receive: reads the item and two 32-bit values, then dispatches to target. */
void cInventoryMsg_UnpackAndProcess(cInventoryMsg* self, void* target)
{
    cNetMsg_GetGOBJ(self->item);
    self->a = read32();
    self->b = read32();
    self->received = 1;
    QueueMessage_cMessageR_cSystemP_int(self, target, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00258480(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00258480 */

/* merge_units: begin func_00258600 */
#pragma push /* merge_units */
static inline void write16(int v)
{
    short s = v;
    *D_005061D0++ = s;
    *D_005061D0++ = s >> 8;
}

static inline void write32(int v)
{
    write16((unsigned short)v);
    write16(v >> 16);
}

typedef struct { char pad[0x24]; int a; int b; void* item; } cInventoryMsg_00258600;
extern void cNetMsg_PutGOBJ(void* item);

/* cInventoryMsg virtual 4: serializes the item, then writes two 32-bit values. */
void cInventoryMsg_Pack(cInventoryMsg_00258600* self)
{
    cNetMsg_PutGOBJ(self->item);
    write32(self->a);
    write32(self->b);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00258600(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00258600 */

/* merge_units: begin func_00258770 */
#pragma push /* merge_units */
typedef struct { void* vtable; char data[0x2C]; } Visitor; /* 0x30-byte stack object */
extern char D_004F7EE0[];
extern char D_004DC460[]; /* visitor vtable */
extern char D_004DCF10[]; /* base vtable */
extern void cMessage_ctor_cMessageNameR(Visitor* v, const char* name);
#if 0 /* merge_units */
extern void cInventoryMsg_UnpackAndProcess(Visitor* v, void* target);
#endif /* merge_units */
#define cInventoryMsg_UnpackAndProcess(a0, a1) (cInventoryMsg_UnpackAndProcess((cInventoryMsg *)(a0), (a1))) /* merge_units */


extern void cMessage_dtor(Visitor* v, int flags);

/* Runs a temporary visitor object over target. */
void cInventoryMsg_NetReceive(void* target)
{
    Visitor v;
    cMessage_ctor_cMessageNameR(&v, D_004F7EE0);
    v.vtable = D_004DC460;
    cInventoryMsg_UnpackAndProcess(&v, target);
    v.vtable = D_004DCF10;
    cMessage_dtor(&v, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00258770(void) {}
#undef cInventoryMsg_UnpackAndProcess /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00258770 */

/* merge_units: begin func_002587D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cCrateInteractMsg script natives and script type registration.
 */


extern int D_004F7EB8;
extern int D_004F7EC0;

int Script_cCrateInteractMsg_Who(cItemMsg** msg) {
    return cGOBJ_SOBJ_toInt((*msg)->who);
}

/* Volatile locals mirror the original stack temporaries. */
int Script_cCrateInteractMsg_Taken(cItemMsg** msg) {
    volatile int taken = (*msg)->taken;
    return taken;
}

int Script_cCrateInteractMsg_Given(cItemMsg** msg) {
    volatile int given = (*msg)->count;
    return given;
}

void cCrateInteractMsg_SOBJ_init(void) {
    int* base = cMessage_SOBJ_getClassId();
    cScriptBase_declareParent(D_004F7EC0, *base);
}

int cCrateInteractMsg_v03(void) {
    return D_004F7EB8;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002587D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002587D0 */

/* merge_units: begin func_00258860 */
#pragma push /* merge_units */
/* cInventoryMsg receive: reads the item and two 32-bit values, then dispatches to target. */
void cCrateInteractMsg_UnpackAndProcess(cInventoryMsg* self, void* target)
{
    cNetMsg_GetGOBJ(self->item);
    self->a = read32();
    self->b = read32();
    self->received = 1;
    QueueMessage_cMessageR_cSystemP_int(self, target, 0);
}
static inline void merge_flush_func_00258860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00258860 */

/* merge_units: begin func_002589E0 */
#pragma push /* merge_units */
static inline void writeFloat(float f)
{
    write32(*(int*)&f);
}

typedef struct { char pad[0x24]; int a; int b; void* crate; } cCrateInteractMsg;
#if 0 /* merge_units */
extern void cNetMsg_PutGOBJ(void* crate);
#endif /* merge_units */
#define cNetMsg_PutGOBJ(a0) (cNetMsg_PutGOBJ((a0))) /* merge_units */


/* cCrateInteractMsg virtual 4: serializes the crate, then writes both values little-endian. */
void cCrateInteractMsg_Pack(cCrateInteractMsg* self)
{
    cNetMsg_PutGOBJ(self->crate);
    write32(self->a);
    write32(self->b);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002589E0(void) {}
#undef cNetMsg_PutGOBJ /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002589E0 */

/* merge_units: begin func_00258B50 */
#pragma push /* merge_units */
/* Stack message object: vtable followed by the base message data. */
typedef struct Msg {
    void* vtable;
    char data[0x2C];
} Msg;

extern char D_004F7EA0[];
extern char D_004DC480[];        /* derived message vtable */
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Msg* msg, void* name);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((Visitor *)(a0), (const char *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void cCrateInteractMsg_UnpackAndProcess(Msg* msg, void* target);
#endif /* merge_units */
#define cCrateInteractMsg_UnpackAndProcess(a0, a1) (cCrateInteractMsg_UnpackAndProcess((cInventoryMsg *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Msg* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Visitor *)(a0), (a1))) /* merge_units */


/* Builds a temporary message, sends it to target, then destroys it. */
void cCrateInteractMsg_NetReceive(void* target) {
    Msg msg;
    cMessage_ctor_cMessageNameR(&msg, D_004F7EA0);
    msg.vtable = D_004DC480;
    cCrateInteractMsg_UnpackAndProcess(&msg, target);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00258B50(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cCrateInteractMsg_UnpackAndProcess /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00258B50 */

/* merge_units: begin func_00258BB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cInventoryMsg virtual slot.
 */


extern int D_004F7EE8;

int cInventoryMsg_v05(void) {
    return D_004F7EE8;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00258BB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00258BB0 */
