/*
 * main/hotbox: range (2 files, 00171ED0-00172360)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00171ED0 */
#pragma push /* merge_units */
void* func_00172360(char* obj, int n); /* gsynth: defined below */
#pragma cplusplus on
struct V171 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(); virtual int v25(); };
typedef struct { void* vt; char pad[0x18]; int f1c; unsigned char b20; char p21[3]; int f24; int f28; int f2c; } MA171;
typedef struct { void* vt; char pad[0x18]; int f1c; unsigned char b20; char p21[3]; int f24; int f28; int f2c; int f30; char p34[0xC]; } MB171;
typedef struct { char pad[0x49]; unsigned char b49; } T171;
typedef struct { char pad[0xC]; int fc; } E171;
typedef struct { char pad[0x64]; int n; T171** items; char pad2[0x24]; int type; int f94; } O171;
extern "C" {
extern unsigned char g_IsMultiplayer;
extern char g_cDisableMsgClass[];
extern char D_004E0860[];
extern char D_004EE698[];
extern char D_004D9940[];
extern char g_Game[];
extern void* D_004FFBD4;
extern int Player_GetIndex(int);
extern void Event_Construct(void*, char*);
extern void Event_Send(void*, void*, int);
extern void cMessage_dtor(void*, int);
extern int func_001723F0(void*);
#if 0 /* merge_units */
extern int* func_00172360(void*, int);
#endif /* merge_units */
#define func_00172360(a0, a1) ((int *)func_00172360((char *)(a0), (a1))) /* merge_units */

extern void EnvController_ActivateFirst(void*, int);
extern void ActiveList_RemoveObject(char*, T171*);
}
#define BCAST171(o, ev, mi, me) \
    if (((V171*)(o))->v25()) { \
        int i; \
        for (i = 0; i < (o)->n; i++) { \
            if (g_IsMultiplayer) { \
                int id = -1; \
                if (ev) id = Player_GetIndex((ev)->fc); \
                Event_Construct(&mi, g_cDisableMsgClass); \
                mi.vt = D_004E0860; \
                mi.f24 = id; \
                mi.f1c = 0x40; \
                mi.b20 = 2; \
                Event_Send(&mi, (o)->items[i], 0); \
                mi.vt = D_004E0860; \
                cMessage_dtor(&mi, 0); \
            } else { \
                Event_Construct(&me, g_cDisableMsgClass); \
                me.vt = D_004E0860; \
                me.f24 = -1; \
                me.f1c = 0x40; \
                Event_Send(&me, (o)->items[i], 0); \
                me.vt = D_004E0860; \
                cMessage_dtor(&me, 0); \
            } \
        } \
    }
#pragma opt_strength_reduction off
extern "C" void Hotbox_SendLinkMessages(O171* o, E171* ev) {
    MA171 m1i;
    MA171 m7i;
    MB171 m9;
    MA171 m1e;
    MA171 m7e;
    MB171 m8;
    int type = o->type;
    switch (type) {
    case 1:
        BCAST171(o, ev, m1i, m1e)
        break;
    case 7:
        BCAST171(o, ev, m7i, m7e)
        break;
    case 5: {
        void* g = D_004FFBD4;
        EnvController_ActivateFirst(g, func_001723F0(g) ? 0 : *func_00172360(g, 0));
        break;
    }
    case 8: case 12: case 13: case 14: case 18: {
        int x = o->f94;
        Event_Construct(&m8, D_004EE698);
        m8.vt = D_004D9940;
        m8.f24 = 2;
        m8.f28 = type;
        m8.f2c = x;
        m8.f30 = (int)ev;
        Event_Send(&m8, ev, 0);
        m8.vt = D_004D9940;
        cMessage_dtor(&m8, 0);
        break;
    }
    case 9: case 15: case 16: {
        int x = o->f94;
        Event_Construct(&m9, D_004EE698);
        m9.f30 = (int)ev;
        m9.vt = D_004D9940;
        m9.f28 = type;
        m9.f24 = 2;
        m9.f2c = x;
        m9.b20 = 8;
        m9.f1c = 0x40;
        Event_Send(&m9, ev, 0);
        m9.vt = D_004D9940;
        cMessage_dtor(&m9, 0);
        break;
    }
    case 11:
        if (o->n && o->items[0]->b49 == 9) ActiveList_RemoveObject(g_Game, o->items[0]);
        break;
    case 0: case 2: case 3: case 4: case 6: case 10: case 17:
        break;
    }
}
#undef func_00172360 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00171ED0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00171ED0 */

/* merge_units: begin func_00172360 */
#pragma push /* merge_units */
typedef struct G7N2 { struct G7N2* prev; struct G7N2* next; } G7N2;
extern G7N2* func_0013ADF0(void* p);
void* func_00172360(char* obj, int n)
{
    G7N2* node = func_0013ADF0(obj + 4)->next;
    if (n >= 0) {
        while (n > 0) { node = node->next; n--; }
    } else {
        while (n < 0) { node = node->prev; n++; }
    }
    return (char*)node + 8;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00172360(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00172360 */
