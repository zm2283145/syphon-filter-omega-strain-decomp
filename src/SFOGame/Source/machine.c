/*
 * SFOGame/Source/machine: 4 files, 001653C0-00165610
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001653C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int g_InterfaceFont; /* current interface font */
extern int Global_SetInterfaceFont(int font);
extern FontOwner* GetMachine(void);

/* Script native: SetInterfaceFont(byte index). */
int Script_SetInterfaceFont(unsigned char* args) {
    unsigned char font;

    font = args[0];
    Global_SetInterfaceFont(font);
    return 0;
}

int Global_SetInterfaceFont(int font) {
    FontOwner* owner;
    int handle;

    owner = GetMachine();
    handle = owner->fonts[font & 255];
    g_InterfaceFont = handle;
    return (int)owner;
}
static inline void merge_flush_func_001653C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001653C0 */

/* merge_units: begin func_00165420 */
#pragma push /* merge_units */
typedef struct { char pad[0x250]; unsigned char mode; char pad2[3]; int width; int height; int pad3; int rate; } Disp_16;
typedef struct { char pad[0x1C]; float scale; } Cfg_16;
extern char g_Video[];
extern Cfg_16* g_OptionsRecord;
const float D_004C1FC8[2] = { 191.25f, 0.0f };
extern int D_005383D4;
extern int D_005383C0;
extern void Renderer_Teardown(void* p);
extern void XLib_Init(void* p, int w, int h, int a, int b, int mode, int c, int d);
/* Selects display resolution and refresh settings for a video mode. */
void cMachine_SetVideoMode(Disp_16* d, unsigned char mode)
{
    switch (mode) {
    case 0:
        d->width = 0x280;
        d->height = 0x1C0;
        d->rate = 30;
        break;
    case 2:
        d->width = 0x280;
        d->height = 0x200;
        d->rate = 50;
        break;
    case 4:
        d->width = 0x280;
        d->height = 0x1E0;
        d->rate = 30;
        break;
    }
    d->mode = mode;
    Renderer_Teardown(g_Video);
    XLib_Init(g_Video, d->width, d->height, 0x20, 0x10, d->mode, 0xFA0, 0x1F4);
    D_005383D4 = d->rate;
    D_005383C0 = (unsigned char)(int)((*(float*)D_004C1FC8) * g_OptionsRecord->scale);
}
static inline void merge_flush_func_00165420(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00165420 */

/* merge_units: begin func_00165540 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Kb_165540 { char pad[0x98]; int active; unsigned short code; };
struct Tog_165540 { char a; unsigned char on; };
struct Obj_165540 { char pad[0x2C]; Tog_165540 tog; };
extern "C" {
int cUSBKeybd_Read(Kb_165540* k, int n);
int cUSBKeybd_GetAsciiKey(Kb_165540* k);
void cConsole_Activate(Tog_165540* t);
void cConsole_Deactivate(Tog_165540* t);
extern Kb_165540 D_0055A700;
extern signed char g_GameState;
extern signed char g_PrevGameState;
}
static inline bool IsKey(Kb_165540* k, unsigned char c) { return k->active ? (unsigned char)cUSBKeybd_GetAsciiKey(k) == c : false; }
static inline bool IsCode(Kb_165540* k, int c) { return k->active ? k->code == c : false; }
extern "C" void cMachine_KeyboardHandler(Obj_165540* o) {
    Kb_165540* k = &D_0055A700;
    if (cUSBKeybd_Read(k, 1)) {
        if (IsKey(k, 0x60)) {
            if (!o->tog.on) cConsole_Activate(&o->tog); else cConsole_Deactivate(&o->tog);
        }
        if (IsCode(k, 0x402D)) {
            g_PrevGameState = g_GameState;
            g_GameState = 0x10;
        }
    }
}
static inline void merge_flush_func_00165540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00165540 */

/* merge_units: begin func_00165610 */
#pragma push /* merge_units */
extern int g_FrameCounter;  /* counter */

void cMachine_CalcFrameTime(void) {
    g_FrameCounter = g_FrameCounter + 1;
}
static inline void merge_flush_func_00165610(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00165610 */
