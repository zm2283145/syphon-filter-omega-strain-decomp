/*
 * main/Generator: range (3 files, 0021CA30-0021CB90)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0021CA30 */
#pragma push /* merge_units */
typedef struct {
    void* vtable;
    char base[0x1C];
    unsigned char b20;
    char pad21[3];
    int value;
    unsigned char b28;
} E7Msg;
typedef struct { char pad[0xB8]; float minDistSq; } E7Gen;
extern unsigned char g_IsMultiplayer;
extern char D_004A4A78[];
extern char D_004DB5E0[];
extern void cMessage_ctor_cMessageNameR(E7Msg* msg, void* name);
extern void QueueMessage_cMessageR_cSystemP_int(E7Msg* msg, void* target, int flags);
extern void cMessage_dtor(E7Msg* msg, int flags);
int Script_cGenerator_SetMinSpawnDistance(int* args)
{
    volatile int iv = args[1];
    float d = *(float*)&iv;
    E7Gen* gen = (E7Gen*)args[0];
    gen->minDistSq = d * d;
    if (g_IsMultiplayer) {
        float v = gen->minDistSq;
        E7Msg msg;
        cMessage_ctor_cMessageNameR(&msg, D_004A4A78);
        msg.vtable = D_004DB5E0;
        msg.b28 = 1;
        msg.b20 = 4;
        msg.value = (int)v;
        QueueMessage_cMessageR_cSystemP_int(&msg, gen, 0);
        msg.vtable = D_004DB5E0;
        cMessage_dtor(&msg, 0);
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021CA30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021CA30 */

/* merge_units: begin func_0021CAF0 */
#pragma push /* merge_units */
typedef struct { void* vt; char pad04[0x1C]; signed char kind; char pad21[3]; int state; signed char b28; char pad29[3]; } Msg_21CAF0;
typedef struct { char pad[0xD1]; unsigned char paused; } Gen_21CAF0;
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Msg_21CAF0* m, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void QueueMessage_cMessageR_cSystemP_int(Msg_21CAF0* m, void* target, int x);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Msg_21CAF0* m, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

int Script_cGenerator_Unpause(Gen_21CAF0** args)
{
    unsigned char st;
    Gen_21CAF0* g;
    g = args[0];
    g->paused = 0;
    if (g_IsMultiplayer) {
        Msg_21CAF0 m;
        st = g->paused;
        cMessage_ctor_cMessageNameR(&m, D_004A4A78);
        m.state = st;
        m.b28 = 0;
        m.vt = D_004DB5E0;
        m.kind = 4;
        QueueMessage_cMessageR_cSystemP_int(&m, g, 0);
        m.vt = D_004DB5E0;
        cMessage_dtor(&m, 0);
    }
    return 0;
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021CAF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021CAF0 */

/* merge_units: begin func_0021CB90 */
#pragma push /* merge_units */
typedef struct { void* vt; char pad04[0x1C]; signed char kind; char pad21[3]; int state; signed char b28; char pad29[3]; } Msg_21CB90;
typedef struct { char pad[0xD1]; unsigned char paused; } Gen_21CB90;
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Msg_21CB90* m, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void QueueMessage_cMessageR_cSystemP_int(Msg_21CB90* m, void* target, int x);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Msg_21CB90* m, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

int Script_cGenerator_Pause(Gen_21CB90** args)
{
    unsigned char st;
    Gen_21CB90* g;
    g = args[0];
    g->paused = 1;
    if (g_IsMultiplayer) {
        Msg_21CB90 m;
        st = g->paused;
        cMessage_ctor_cMessageNameR(&m, D_004A4A78);
        m.state = st;
        m.b28 = 0;
        m.vt = D_004DB5E0;
        m.kind = 4;
        QueueMessage_cMessageR_cSystemP_int(&m, g, 0);
        m.vt = D_004DB5E0;
        cMessage_dtor(&m, 0);
    }
    return 0;
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021CB90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021CB90 */
