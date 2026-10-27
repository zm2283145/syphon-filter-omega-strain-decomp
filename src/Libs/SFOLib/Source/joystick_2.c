/*
 * Libs/SFOLib/Source/joystick: 7 files, 00369C50-0036A2B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00369C50 */
#pragma push /* merge_units */
#include "types.h"
typedef struct {
    unsigned char hi;
    unsigned char lo;
    unsigned char rx;
    unsigned char ry;
    unsigned char lx;
    unsigned char ly;
    unsigned char pr[12];
    char pad[0x2C - 0x12];
} PadRaw369C50;
typedef struct {
    char pad0[0x100];
    int port;
    unsigned int held;
    int pressed;
    int cur;
    int x110;
    int x114;
    int prev;
    char pad11C[0x10];
    float stick[4];
    float delta[4];
    int pr[12];
    int prDelta[12];
    int state;
    unsigned char connected;
} Pad369C50;
int scePad2Read(int, PadRaw369C50*);
void scePad2GetButtonProfile(int, unsigned char*);
int scePad2GetState(int);
extern int D_004BBE20[];

static inline float PadAxis_369C50(unsigned int v)
{
    return (float)v - 127.5f;
}

void cJoyPad_Read(Pad369C50* p)
{
    PadRaw369C50 b;
    if (!p->connected) {
        unsigned char st[4];
        scePad2GetButtonProfile(p->port, st);
        if (st[2] != 0xFF) {
            p->state = 0;
            return;
        }
        p->connected = 1;
    }
    p->state = scePad2GetState(p->port);
    if (p->state == 0) {
        p->connected = 0;
        return;
    }
    if (p->state == 1) {
        if (scePad2Read(p->port, &b) == 0x12) {
            int bits;
            float lx, ly, rx, ry;
            int i;
            p->prev = p->cur;
            bits = (b.hi << 8) | b.lo;
            p->held |= bits;
            bits ^= 0xFFFF;
            bits &= p->held;
            p->pressed = bits & ~p->cur;
            p->cur = bits;
            p->x110 |= p->cur;
            p->x114 ^= p->pressed;
            lx = PadAxis_369C50(b.lx);
            ly = PadAxis_369C50(b.ly);
            rx = PadAxis_369C50(b.rx);
            ry = PadAxis_369C50(b.ry);
            p->delta[0] = lx - p->stick[0];
            p->delta[1] = ly - p->stick[1];
            p->delta[2] = rx - p->stick[2];
            p->delta[3] = ry - p->stick[3];
            p->stick[0] = lx;
            p->stick[1] = ly;
            p->stick[2] = rx;
            p->stick[3] = ry;
            for (i = 0; i < 12; i++) {
                int v = b.pr[i];
                if (!(p->held & D_004BBE20[i]))
                    v = 0;
                p->prDelta[i] = v - p->pr[i];
                p->pr[i] = v;
            }
        }
    }
}
static inline void merge_flush_func_00369C50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00369C50 */

/* merge_units: begin func_00369EE0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
void cJoyPad_Clear(char * arg0, int arg1) {
    int var_a2;
    char * var_a0;
    int temp_a1;

    var_a0 = arg0;
    F_(var_a0, 0x12C, int) = 0;
    temp_a1 = ~arg1;
    F_(var_a0, 0x130, int) = 0;
    var_a2 = 0;
    F_(var_a0, 0x134, int) = 0;
    F_(var_a0, 0x138, int) = 0;
    F_(var_a0, 0x13C, int) = 0;
    F_(var_a0, 0x140, int) = 0;
    F_(var_a0, 0x144, int) = 0;
    F_(var_a0, 0x148, int) = 0;
    F_(var_a0, 0x10C, int) = (int) (F_(var_a0, 0x10C, int) & temp_a1);
    F_(var_a0, 0x110, int) = (int) (F_(var_a0, 0x110, int) & temp_a1);
    F_(var_a0, 0x114, int) = (int) (F_(var_a0, 0x114, int) & temp_a1);
    F_(var_a0, 0x118, int) = (int) (F_(var_a0, 0x118, int) & temp_a1);
    F_(var_a0, 0x104, int) = (int) (F_(var_a0, 0x104, int) & temp_a1);
    do {
        F_(var_a0, 0x17C, int) = 0;
        F_(var_a0, 0x14C, int) = 0;
        var_a2 += 6;
        F_(var_a0, 0x180, int) = 0;
        F_(var_a0, 0x150, int) = 0;
        F_(var_a0, 0x184, int) = 0;
        F_(var_a0, 0x154, int) = 0;
        F_(var_a0, 0x188, int) = 0;
        F_(var_a0, 0x158, int) = 0;
        F_(var_a0, 0x18C, int) = 0;
        F_(var_a0, 0x15C, int) = 0;
        F_(var_a0, 0x190, int) = 0;
        F_(var_a0, 0x160, int) = 0;
        var_a0 += 0x18;
    } while (var_a2 < 0xC);
}
static inline void merge_flush_func_00369EE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00369EE0 */

/* merge_units: begin func_00369F90 */
#pragma push /* merge_units */
typedef struct {
    char pad0[0x40];
    char state[0x14C - 0x40];
    int busy;
    char pad150[0x16C - 0x150];
    char stickL[8];
    char stickR[8];
    char pad17C[0x1C0 - 0x17C];
} PadEntry;
typedef struct { int a0; int count; } PadSet;
extern void cJoyPad_ApplyDeadZone(float* out, void* state, void* stick, int flag);

int cJoystick_IsDormant(PadSet* self) {
    unsigned char active = 0;
    int i;
    for (i = 0; i < self->count; i++) {
        PadEntry* p = (PadEntry*)self + i;
        active = (active | p->busy) != 0;
        if (!active) {
            float l[2];
            float r[2];
            float lx, ly, rx, ry;
            cJoyPad_ApplyDeadZone(l, p->state, p->stickL, 0);
            lx = l[0]; ly = l[1];
            cJoyPad_ApplyDeadZone(r, p->state, p->stickR, 0);
            rx = r[0]; ry = r[1];
            { float z = 0.0f; active = lx != z || ly != z || rx != z || ry != z; }
        }
    }
    return !active;
}
static inline void merge_flush_func_00369F90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00369F90 */

/* merge_units: begin func_0036A0F0 */
#pragma push /* merge_units */
typedef struct { char pad[0x40]; char item[0x1C0]; } E36A;
typedef struct { int a; int count; char pad[0x38]; char items[1][0x1C0]; } H36A;
#if 0 /* merge_units */
extern void cJoyPad_Read(void* p);
#endif /* merge_units */
#define cJoyPad_Read(a0) (cJoyPad_Read((Pad369C50 *)(a0))) /* merge_units */

void cJoystick_Poll(H36A* h)
{
    int i;
    for (i = 0; i < h->count; i++) {
        cJoyPad_Read(h->items[i]);
    }
}
#undef cJoyPad_Read /* merge_units */
static inline void merge_flush_func_0036A0F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036A0F0 */

/* merge_units: begin func_0036A160 */
#pragma push /* merge_units */
typedef struct {
    char pad[0x100];
    int handle;
    char pad104[0x18];
    float deadzoneX;
    float deadzoneY;
    float scaleX;
    float scaleY;
    char pad12C[0x80];
    int state;
    unsigned char active;
    char pad1B1[0xF];
} Pad;
typedef struct { char pad[4]; int count; char pad8[0x38]; Pad pads[1]; } PadMgr;
typedef struct { int type; int analog; int flags; int reserved[2]; } PadDesc;
#if 0 /* merge_units */
extern void cJoyPad_Clear(Pad* pad, int port);
#endif /* merge_units */
#define cJoyPad_Clear(a0, a1) (cJoyPad_Clear((char *)(a0), (a1))) /* merge_units */

extern int scePad2CreateSocket(PadDesc* desc, Pad* pad);

/* Adds a pad to the manager with the given analog dead zone. */
void cJoystick_AddPad(PadMgr* mgr, int analog, int unused, int deadzone)
{
    PadDesc desc;
    Pad* pad = &mgr->pads[mgr->count];
    cJoyPad_Clear(pad, -1);
    pad->deadzoneX = deadzone;
    pad->deadzoneY = deadzone;
    pad->scaleX = 127.5f / (127.5f - pad->deadzoneX);
    pad->scaleY = 127.5f / (127.5f - pad->deadzoneY);
    desc.type = 2;
    desc.analog = analog != 0;
    desc.flags = 0;
    pad->state = 3;
    pad->active = 0;
    pad->handle = scePad2CreateSocket(&desc, pad);
    mgr->count++;
}
#undef cJoyPad_Clear /* merge_units */
static inline void merge_flush_func_0036A160(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036A160 */

/* merge_units: begin func_0036A240 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void cJoyPad_Clear(void*, int);
#endif /* merge_units */
#define cJoyPad_Clear(a0, a1) (cJoyPad_Clear((char *)(a0), (a1))) /* merge_units */

typedef struct { char d[0x1C0]; } G6E36A;
typedef struct { int a; int n; char pad[0x38]; G6E36A e[2]; int cur; } G6C36A;
void cJoystick_Debounce(G6C36A* p)
{
    int i;
    for (i = 0; i < p->n; i++)
        cJoyPad_Clear(&p->e[i], p->cur);
    p->cur = -1;
}
#undef cJoyPad_Clear /* merge_units */
static inline void merge_flush_func_0036A240(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036A240 */

/* merge_units: begin func_0036A2B0 */
#pragma push /* merge_units */
extern void sceDbcInit(void);
extern void scePad2Init(int a);

typedef struct { int state; int unk4; char pad[0x3B8]; int unk3C0; } Obj;

/* Initialises the controller subsystem and resets state. */
void cJoystick_Init(Obj* self)
{
    sceDbcInit();
    scePad2Init(0);
    self->state = 2;
    self->unk4 = 0;
    self->unk3C0 = -1;
}
static inline void merge_flush_func_0036A2B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036A2B0 */
