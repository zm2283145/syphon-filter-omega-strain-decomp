/*
 * SFOGame/Source/backpack: 14 files, 00255290-00255650
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00255290 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x2F0]; unsigned char b2f0; } P255;
extern int g_WeaponDatabase;
extern int g_Hud;
extern char D_004A7B18[];
#if 0 /* merge_units */
extern int cBackpack_GetWeaponDbs(P255*, int*, int, int);
#endif /* merge_units */
int cBackpack_GetWeaponDbs(); /* merge_units */


#if 0 /* merge_units */
extern void cBackpack_GetAmmoCounts(P255*, int, int*, int*, int*);
#endif /* merge_units */
void cBackpack_GetAmmoCounts(); /* merge_units */


extern char* cWeaponDB_GetEntry(int, int);
extern int cWeapon_PickupAmmo_tWDBDataP_int(int, char*, int);
extern char* nGlobalization_GetString_charP(char*);
#if 0 /* merge_units */
extern void cBackpack_TakeAmmo(P255*, int, int);
#endif /* merge_units */
int cBackpack_TakeAmmo(); /* merge_units */

extern int sprintf(char*, const char*, ...);
extern void cHud_Message(int, char*);
unsigned char cBackpack_AutoTakeAmmo(P255* p, int arg) {
    int x[1];
    int y[1];
    int z[1];
    int ids[10];
    char buf[0x80];
    unsigned char any = 0;
    if (p->b2f0) {
        int db = g_WeaponDatabase;
        int n = cBackpack_GetWeaponDbs(p, ids, arg, 10);
        int i;
        for (i = 0; i < n; i++) {
            char* w;
            int amt;
            cBackpack_GetAmmoCounts(p, ids[i], x, y, z);
            w = cWeaponDB_GetEntry(db, ids[i]);
            amt = cWeapon_PickupAmmo_tWDBDataP_int(arg, w, z[0]);
            if (amt) {
                char* nm = nGlobalization_GetString_charP(w + 0x80);
                cBackpack_TakeAmmo(p, ids[i], amt);
                sprintf(buf, D_004A7B18, nm, nGlobalization_GetString_charP("PickupAmmo"));
                cHud_Message(g_Hud, buf);
                any = 1;
            }
        }
    }
    return any;
}
static inline void merge_flush_func_00255290(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00255290 */

/* merge_units: begin func_002553E0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int cWeapon_GetWeaponSlot(int);                             

int cBackpack_GetWeaponDbs(int self, int *output, char * table) {
    char *slot;
    int count;
    int deferred;
    int index;
    int item;
    int fallback;

    slot = (char *)(self + 0x64);
    count = 0;
    deferred = -1;
    index = 0;
    do {
        if (F_(slot, 0xCC, int) != 0) {
            item = F_(slot, 0x24, int);
            if ((cWeapon_GetWeaponSlot(item) & 0xFF) == 6) {
                deferred = item;
            } else {
                *output = item;
                output += 1;
                count += 1;
            }
        } else if (F_(slot, 0xD0, unsigned char) != 0) {
            fallback = F_((table + (F_(slot, 0x0, unsigned char) * 0x10)), 0x8, int);
            if (fallback != -1) {
                *output = fallback;
                count += 1;
                output += 1;
            }
        }
        index += 1;
        slot += 0xD4;
    } while (index < 3);
    if (deferred >= 0) {
        if (count != 0) {
            if (deferred != F_(table, 0x68, int)) {
                goto append_deferred;
            }
        } else {
append_deferred:
            *output = deferred;
            count += 1;
        }
    }
    return count;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002553E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002553E0 */

/* merge_units: begin func_00255500 */
#pragma push /* merge_units */
#pragma opt_unroll_loops off
#pragma opt_strength_reduction off
typedef struct AmmoEntry{int primary[4];int secondary[4];int item,count;}AmmoEntry;
typedef struct AmmoSlot{unsigned char kind;char pad[3];AmmoEntry entries[5];int count;unsigned char active;char padD1[3];}AmmoSlot;
typedef struct BackpackQuery{char pad[0x64];AmmoSlot slots[3];}BackpackQuery;
void cBackpack_GetAmmoCounts(BackpackQuery*self,int item,int*lastPrimary,int*lastSecondary,int*total){
 AmmoSlot*slot;int i;AmmoEntry*entry;int j;int k;int kind;
 kind=cWeapon_GetWeaponSlot(item);slot=self->slots;i=0;kind=(unsigned char)kind;goto outer_test;
 outer_body:
 if(slot->kind==kind){entry=slot->entries;for(j=0;j<slot->count;j++,entry++){
  if(entry->item==item){*total=0;*lastPrimary=entry->primary[entry->count-1];*lastSecondary=entry->secondary[entry->count-1];k=0;if(k<entry->count){int*p=entry->primary;do{*total+=p[0];if(kind!=4)*total+=p[4];k++;p++;}while(k<entry->count);}}
 }}
 i++;slot++;
 outer_test:if(i<3)goto outer_body;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00255500(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00255500 */

/* merge_units: begin func_00255650 */
#pragma push /* merge_units */
typedef struct AmmoPair{int primary[4];int secondary[4];}AmmoPair;
typedef struct AmmoEntry_00255650{AmmoPair v;int item,count;}AmmoEntry_00255650;
typedef struct AmmoSlot_00255650{unsigned char kind;char pad[3];AmmoEntry_00255650 entries[5];int count;unsigned char active;char padD1[3];}AmmoSlot_00255650;
typedef struct BackpackQuery_00255650{char pad[0x64];AmmoSlot_00255650 slots[3];}BackpackQuery_00255650;
#if 0 /* merge_units */
unsigned char* cWeaponDB_GetEntry(int, int);
#endif /* merge_units */
#define cWeaponDB_GetEntry(a0, a1) ((unsigned char *)cWeaponDB_GetEntry((a0), (a1))) /* merge_units */

static inline int Min(int a, int b) {
    if (b < a) return b;
    return a;
}
int cBackpack_TakeAmmo(BackpackQuery_00255650* self, int item, int amount) {
    AmmoSlot_00255650* slot;
    AmmoEntry_00255650* entry;
    int total;
    unsigned char* w;
    int k;
    int take;
    int i;
    int j;
    int kind;
    kind = cWeapon_GetWeaponSlot(item);
    slot = self->slots;
    i = 0;
    goto outer_test;
outer_body:
    if (slot->kind == (unsigned char)kind) {
        entry = slot->entries;
        for (j = 0; j < slot->count; j++, entry++) {
            if (entry->item == item) {
                total = 0;
                w = cWeaponDB_GetEntry(g_WeaponDatabase, item);
                for (k = 0; ((amount != 0) ^ 1) == 0 && k < entry->count; k++) {
                    take = Min(entry->v.primary[k], amount);
                    amount -= take;
                    entry->v.primary[k] -= take;
                    total += take;
                    if (w[0xF0] == 1 || w[0xF0] == 7) {
                        if (entry->v.primary[k] == 0) {
                            if (--entry->count == 0) {
                                AmmoEntry_00255650* src = &slot->entries[--slot->count];
                                entry->v = src->v;
                                entry->item = src->item;
                                entry->count = src->count;
                                break;
                            }
                        }
                    } else {
                        take = Min(entry->v.secondary[k], amount);
                        amount -= take;
                        total += take;
                        entry->v.secondary[k] -= take;
                    }
                }
                return total;
            }
        }
    }
    i++;
    slot++;
outer_test:
    if (i < 3) goto outer_body;
    return 0;
}
#undef cWeaponDB_GetEntry /* merge_units */
static inline void merge_flush_func_00255650(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00255650 */

/* merge_units: begin func_00255860 */
#pragma push /* merge_units */
typedef struct { char pad[0x2E4]; int pending; int a; int b; } Q255;
int cBackpack_TakeFlakJacket(Q255* s, int* a, int* b) {
    if (s->pending) {
        s->pending--;
        *a = s->a;
        *b = s->b;
        return 1;
    }
    *a = 0;
    *b = 0;
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00255860(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00255860 */

/* merge_units: begin func_002558A0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } V4_558A0;
typedef struct { V4_558A0 a; V4_558A0 b; int id; int ref; } Ent_558A0;
typedef struct { unsigned char type; char pad[3]; Ent_558A0 ents[5]; int count; unsigned char flag; char pad2[3]; } Slot_558A0;
typedef struct { char pad[0x64]; Slot_558A0 slots[3]; } Pack_558A0;
#if 0 /* merge_units */
extern int cWeapon_GetWeaponSlot(int key);
#endif /* merge_units */
#define cWeapon_GetWeaponSlot(a0) (cWeapon_GetWeaponSlot((a0))) /* merge_units */


static inline void Cp_558A0(Ent_558A0* d, Ent_558A0* s) { d->a = s->a; d->b = s->b; d->id = s->id; d->ref = s->ref; }
#pragma opt_rotateloops off
int cBackpack_TakeWeapon(Pack_558A0* s, int id, int keep)
{
    Slot_558A0* p; int i;
    int t;
    t = cWeapon_GetWeaponSlot(id); p = s->slots;
    i = 0;
    for (; i < 3; i++, p++) {
        if (p->type == (unsigned char)t) {
            Ent_558A0* e = p->ents;
            int j = 0;
            if (j < p->count) {
                do {
                    if ((void*)e->id == (void*)id) {
                        if (!keep) {
                            if (--e->ref == 0) {
                                int n = --p->count;
                                Cp_558A0(e, (Ent_558A0*)((char*)p + n * 40 + 4));
                            }
                        }
                        return 1;
                    }
                    j++;
                    e++;
                } while (j < p->count);
            }
        }
    }
    return 0;
}
#pragma opt_rotateloops reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002558A0(void) {}
#undef cWeapon_GetWeaponSlot /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002558A0 */

/* merge_units: begin func_002559D0 */
#pragma push /* merge_units */
typedef struct { unsigned char type; char pad[0xCF]; unsigned char flag; char pad2[3]; } Slot2559;
typedef struct { char pad[0x64]; Slot2559 slots[3]; } Pack2559;
#pragma opt_rotateloops off
unsigned char cBackpack_SlotIsReplaceable(Pack2559* s, int key) {
    Slot2559* p; int i;
    int t;
    t = cWeapon_GetWeaponSlot(key); p = s->slots;
    i = 0;
    for (; i < 3; i++, p++) {
        if (p->type == (unsigned char)t) return p->flag;
    }
    return 0;
}
#pragma opt_rotateloops reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002559D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002559D0 */

/* merge_units: begin func_00255A40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cBackpack flag setter.
 */

#include "backpack_types.h"

void cBackpack_SetHasTakenPlayerItems(cBackpack* backpack) {
    backpack->unk30C = 1;
}
static inline void merge_flush_func_00255A40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00255A40 */

/* merge_units: begin func_00255A50 */
#pragma push /* merge_units */
#include "vslot_pad.h"

#pragma cplusplus on
/* cBackpack_AddFlakJacket: count a spawn request; on first activation register the object and create its proxy */
struct Pt1SpProxy { char pad[0x94]; int id; };
struct Pt1SpObj {
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void SetActive(int on);
    char pad4[0xC - 4];
    int id;
    char pad10[0x2E4 - 0x10];
    int requests;
    int reqA;
    int reqB;
    char pad2F0[0x2FC - 0x2F0];
    Pt1SpProxy* proxy;
};
extern "C" {
extern void* g_HotboxTracker;
void nGobjManager_AddGOBJ(Pt1SpObj* o);
Pt1SpProxy* cHotboxMan_CreateInteractBox(void* mgr, Pt1SpObj* o, int a, int b);
}
extern "C" void cBackpack_AddFlakJacket(Pt1SpObj* o, int a, int b)
{
    if (!a)
        return;
    if (o->requests++ == 0) {
        o->reqA = a;
        o->reqB = b;
    }
    if (o->proxy)
        return;
    o->SetActive(1);
    nGobjManager_AddGOBJ(o);
    if (o->proxy)
        return;
    o->proxy = cHotboxMan_CreateInteractBox(g_HotboxTracker, o, 0, 1);
    o->proxy->id = o->id;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00255A50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00255A50 */

/* merge_units: begin func_00255AF0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Link {
    char pad00[0x94];
    int owner;
};

struct Entry {
    int amount[4];
    int extra[4];
    int item;
    int n;
};

struct Slot {
    unsigned char kind;
    Entry e[5];
    int count;
    unsigned char flag;
};

struct BP {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void Method5C(int a); /* +0x5C */
    char pad04[0x0C - 0x04];
    int unk0C;
    char pad10[0x64 - 0x10];
    Slot slots[3];
    char pad2E0[0x2FC - 0x2E0];
    Link* link;
};

extern "C" {
#if 0 /* merge_units */
extern int g_HotboxTracker;
#endif /* merge_units */
#define g_HotboxTracker (*(int*)&g_HotboxTracker) /* merge_units */



#if 0 /* merge_units */
int cWeapon_GetWeaponSlot(int id);
#endif /* merge_units */
#define cWeapon_GetWeaponSlot(a0) (cWeapon_GetWeaponSlot((a0))) /* merge_units */


#if 0 /* merge_units */
void nGobjManager_AddGOBJ(BP* self);
#endif /* merge_units */
#define nGobjManager_AddGOBJ(a0) (nGobjManager_AddGOBJ((Pt1SpObj *)(a0))) /* merge_units */



#if 0 /* merge_units */
Link* cHotboxMan_CreateInteractBox(int manager, BP* bp, int a2, int a3);
#endif /* merge_units */
#define cHotboxMan_CreateInteractBox(a0, a1, a2, a3) ((Link *)cHotboxMan_CreateInteractBox((void *)(a0), (Pt1SpObj *)(a1), (a2), (a3))) /* merge_units */



}

static inline void CreateLink(BP* bp) {
    if (bp->link == 0) {
        bp->link = cHotboxMan_CreateInteractBox(g_HotboxTracker, bp, 0, 1);
        bp->link->owner = bp->unk0C;
    }
}

extern "C" void cBackpack_AddWeapon(BP* bp, int item, int amount, int extra, unsigned char flag) {
    int kind = cWeapon_GetWeaponSlot(item);
    unsigned char k = kind;
    int found = -1;
    int i;
    if (k == 4 && amount == 0)
        return;
    for (i = 0; i < 3; i++) {
        if (bp->slots[i].count || bp->slots[i].flag) {
            if (bp->slots[i].kind == k) {
                found = i;
                break;
            }
        } else if (found < 0) {
            found = i;
        }
    }
    if (found >= 0) {
        Slot* s = &bp->slots[found];
        bool done = false;
        Entry* e = s->e;
        int j = 0;
        for (; !done && j < s->count; j++, e++) {
            if (e->item == item) {
                if (k == 4) {
                    e->amount[0] += amount;
                } else {
                    e->amount[e->n] = amount;
                    e->extra[e->n] = extra;
                    e->n++;
                }
                done = true;
            }
        }
        if (!done) {
            e->item = item;
            e->extra[0] = extra;
            e->amount[0] = amount;
            e->n = 1;
            s->kind = kind;
            s->count++;
            if (flag)
                s->flag = flag;
        }
    }
    if (bp->link == 0) {
        bp->Method5C(1);
        nGobjManager_AddGOBJ(bp);
        CreateLink(bp);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00255AF0(void) {}
#undef g_HotboxTracker /* merge_units */
#undef cWeapon_GetWeaponSlot /* merge_units */
#undef nGobjManager_AddGOBJ /* merge_units */
#undef cHotboxMan_CreateInteractBox /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00255AF0 */

/* merge_units: begin func_00255CF0 */
#pragma push /* merge_units */
#pragma cplusplus on


struct BP_00255CF0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void Method5C(int a); /* +0x5C */
    char pad04[0x0C - 0x04];
    int unk0C;
    char pad10[0x64 - 0x10];
    signed char slot;
    char pad65[0x134 - 0x65];
    unsigned char unk134;
    char pad135[0x2F1 - 0x135];
    unsigned char unk2F1;
    char pad2F2[0x2FC - 0x2F2];
    Link* link;
    char pad300[0x30C - 0x300];
    int unk30C;
};

extern "C" {
#if 0 /* merge_units */
extern int g_HotboxTracker;
#endif /* merge_units */
#define g_HotboxTracker (*(int*)&g_HotboxTracker) /* merge_units */



#if 0 /* merge_units */
void nGobjManager_AddGOBJ(BP_00255CF0* self);
#endif /* merge_units */
#define nGobjManager_AddGOBJ(a0) (nGobjManager_AddGOBJ((Pt1SpObj *)(a0))) /* merge_units */



#if 0 /* merge_units */
Link* cHotboxMan_CreateInteractBox(int manager, BP_00255CF0* bp, int a2, int a3);
#endif /* merge_units */
#define cHotboxMan_CreateInteractBox(a0, a1, a2, a3) ((Link *)cHotboxMan_CreateInteractBox((void *)(a0), (Pt1SpObj *)(a1), (a2), (a3))) /* merge_units */



}

static inline void CreateLink_00255CF0(BP_00255CF0* bp) {
    if (bp->link == 0) {
        bp->link = cHotboxMan_CreateInteractBox(g_HotboxTracker, bp, 0, 1);
        bp->link->owner = bp->unk0C;
    }
}

extern "C" void cBackpack_InitForDropping(BP_00255CF0* bp, int item) {
    signed char s = cWeapon_GetWeaponSlot(item);
    bp->unk134 = 1;
    bp->slot = s;
    if (bp->link == 0) {
        bp->Method5C(1);
        nGobjManager_AddGOBJ(bp);
        CreateLink_00255CF0(bp);
    }
    bp->unk2F1 = 1;
    bp->unk30C = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00255CF0(void) {}
#undef g_HotboxTracker /* merge_units */
#undef nGobjManager_AddGOBJ /* merge_units */
#undef cHotboxMan_CreateInteractBox /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00255CF0 */

/* merge_units: begin func_00255D90 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Tgt {
    char pad0[0xC];
    int serial;
    char pad10[0x2C - 0x10];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x3469 - 0x2F];
    unsigned char b3469;
};
struct Hnd {
    Tgt* target;
    int serial;
    Tgt* Get() { Tgt* t = target; bool ok = !t || t->serial == serial; return ok ? t : 0; }
};
struct Obj {
    char pad0[0x300];
    Hnd h;
};
extern "C" bool cBackpack_BodyHasDisguise(Obj* o)
{
    bool r = 0;
    if (o->h.Get()) {
        Tgt* t = o->h.Get();
        bool v = t->b2D && t->b2C && !t->b2E && t->b3469;
        if (v)
            r = 1;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00255D90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00255D90 */

/* merge_units: begin func_00255E50 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Tgt_00255E50 {
    char pad0[0xC];
    int serial;
    char pad10[0x2C - 0x10];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x3468 - 0x2F];
    unsigned char b3469;
};
struct Hnd_00255E50 {
    Tgt_00255E50* target;
    int serial;
    Tgt_00255E50* Get() { Tgt_00255E50* t = target; bool ok = !t || t->serial == serial; return ok ? t : 0; }
};
struct Obj_00255E50 {
    char pad0[0x300];
    Hnd_00255E50 h;
};
extern "C" bool cBackpack_BodyIsPickupable(Obj_00255E50* o)
{
    bool r = 0;
    if (o->h.Get()) {
        Tgt_00255E50* t = o->h.Get();
        bool v = t->b2D && t->b2C && !t->b2E && t->b3469;
        if (v)
            r = 1;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00255E50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00255E50 */

/* merge_units: begin func_00255F10 */
#pragma push /* merge_units */
typedef struct { char pad[0x134]; unsigned char b134; char pad2[0x2F1 - 0x135]; unsigned char b2F1; unsigned char b2F2; } Obj255F;
extern void Backpack_UpdateBoxPriority(Obj255F* s);
extern void cBackpack_CheckForRemoval(Obj255F* s);
void cBackpack_Unlock(Obj255F* s) {
    Backpack_UpdateBoxPriority(s);
    cBackpack_CheckForRemoval(s);
    s->b2F2 = 0;
    if (s->b2F1) {
        s->b134 = 0;
        s->b2F1 = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00255F10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00255F10 */
