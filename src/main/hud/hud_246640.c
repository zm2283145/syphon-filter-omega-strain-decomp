/*
 * main/hud: range (7 files, 00246640-002468A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "hud_types.h"

/* merge_units: begin func_00246640 */
#pragma push /* merge_units */
void Global_SetNVInterfaceTextColor(int r, int g, int b, float a); /* gsynth: defined below */
#if 0 /* merge_units */
extern void Global_SetNVInterfaceTextColor(int a, int b, int c, float d);
#endif /* merge_units */
#define Global_SetNVInterfaceTextColor(a0, a1, a2, a3) (Global_SetNVInterfaceTextColor((a0), (a1), (a2), (a3))) /* merge_units */


/* Script native: sets the night-vision interface text colour. */
int Script_SetNVInterfaceTextColor(ScriptArg* args)
{
    int a3[1];
    int a2[1];
    int a1[1];
    int a0[1];
    a3[0] = args[3].i;
    a2[0] = args[2].i;
    a1[0] = args[1].i;
    a0[0] = args[0].i;
    Global_SetNVInterfaceTextColor(*(int*)a0, *(int*)a1, *(int*)a2, *(float*)a3);
    return 0;
}
#undef Global_SetNVInterfaceTextColor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00246640(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00246640 */

/* merge_units: begin func_00246690 */
#pragma push /* merge_units */
extern float D_004F7D70;
extern float D_004F7D74;
extern float D_004F7D78;
extern float D_004F7D7C;

/* Sets the night-vision interface text color from 0..255 components and an alpha. */
void Global_SetNVInterfaceTextColor(int r, int g, int b, float a)
{
    D_004F7D7C = a;
    D_004F7D70 = (float)r / 255.0f;
    D_004F7D74 = (float)g / 255.0f;
    D_004F7D78 = (float)b / 255.0f;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00246690(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00246690 */

/* merge_units: begin func_002466F0 */
#pragma push /* merge_units */
void Global_SetInterfaceTextColor(int r, int g, int b, float a); /* gsynth: defined below */
#if 0 /* merge_units */
extern void Global_SetInterfaceTextColor(int item, int r, int g, float alpha);
#endif /* merge_units */
#define Global_SetInterfaceTextColor(a0, a1, a2, a3) (Global_SetInterfaceTextColor((a0), (a1), (a2), (a3))) /* merge_units */


/* Script native: sets interface text color (item, r, g, alpha); returns 0. */
int Script_SetInterfaceTextColor(ScriptArg* args)
{
    int a3[1];
    int a2[1];
    int a1[1];
    int a0[1];
    a3[0] = args[3].i;
    a2[0] = args[2].i;
    a1[0] = args[1].i;
    a0[0] = args[0].i;
    Global_SetInterfaceTextColor(*(int*)a0, *(int*)a1, *(int*)a2, *(float*)a3);
    return 0;
}
#undef Global_SetInterfaceTextColor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002466F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002466F0 */

/* merge_units: begin func_00246740 */
#pragma push /* merge_units */
extern float D_004F7D60;
extern float D_004F7D64;
extern float D_004F7D68;
extern float D_004F7D6C;

/* Sets the interface text colour from 0-255 RGB and a float alpha. */
void Global_SetInterfaceTextColor(int r, int g, int b, float a)
{
    D_004F7D6C = a;
    D_004F7D60 = r / 255.0f;
    D_004F7D64 = g / 255.0f;
    D_004F7D68 = b / 255.0f;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00246740(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00246740 */

/* merge_units: begin func_002467A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */


extern unsigned char D_004F7D40;
extern void Global_SetInfoBarFont(int font);

/* Script native: SetInfoBarFont(font). */
int Script_SetInfoBarFont(ScriptArg* args) {
    Global_SetInfoBarFont((unsigned char)args[0].i);
    return 0;
}

/* Sets the info bar font index (Global_SetInfoBarFont). */
void Global_SetInfoBarFont(int font) {
    D_004F7D40 = font;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002467A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002467A0 */

/* merge_units: begin func_002467D0 */
#pragma push /* merge_units */
typedef struct { char pad[0x24]; float time; char sub[1]; } cNetTimerMsg;

extern unsigned char* D_005061D0; /* network write cursor */
extern void func_00281C80(void* sub);

static inline void write16(int v)
{
    short s = v;
    *D_005061D0++ = s;
    *D_005061D0++ = s >> 8;
}

/* cNetTimerMsg virtual 4: writes the time (raw float bits) little-endian, then serializes the payload. */
void cNetTimerMsg_v04(cNetTimerMsg* self)
{
    float time = self->time;
    int value = *(int*)&time;
    write16((unsigned short)value);
    write16(value >> 16);
    func_00281C80(self->sub);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002467D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002467D0 */

/* merge_units: begin func_002468A0 */
#pragma push /* merge_units */
extern int D_004F7DC8;

int cNetTimerMsg_v05(void) {
    return D_004F7DC8;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002468A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002468A0 */
