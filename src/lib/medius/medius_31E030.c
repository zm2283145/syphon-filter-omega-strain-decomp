/*
 * lib/medius: 12 files, 0031E030-0031E3C8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0031E030 */
#include "types.h"
typedef struct {
    char pad00[0x14];
    short f14;
    short f16;
    unsigned short f18;
    unsigned short f1A;
    unsigned short f1C;
    unsigned char f1E;
} Params_31E;
typedef struct { char pad[0x4C]; Params_31E* p; } Inner_31E;
typedef struct {
    long magic;
    char pad08[0x10];
    unsigned char state;
    char pad19[3];
    Inner_31E* inner;
} Handle_31E;
#define CHECK_31E(h) \
    if (h == 0 || h->magic != 0xFACE) return 0x17D4; \
    if (h->state != 10) return 0x17DE;
int nciSetVADSilenceDuration(Handle_31E* h, unsigned short v) { CHECK_31E(h) h->inner->p->f1A = v; return 0; }
/* merge_units: end func_0031E030 */

/* merge_units: begin func_0031E080 */
int nciGetVADSilenceDuration(Handle_31E* h, unsigned short* out) { CHECK_31E(h) *out = h->inner->p->f1A; return 0; }
/* merge_units: end func_0031E080 */

/* merge_units: begin func_0031E0D0 */
int nciSetVADEnergyTrigLevel(Handle_31E* h, unsigned short v) { Params_31E* p; CHECK_31E(h) p = h->inner->p; if (v >= 0x100) return 0x1968; p->f18 = v; return 0; }
/* merge_units: end func_0031E0D0 */

/* merge_units: begin func_0031E128 */
int nciGetVADEnergyTrigLevel(Handle_31E* h, unsigned short* out) { if (out == 0) return 0x181A; CHECK_31E(h) *out = h->inner->p->f18; return 0; }
/* merge_units: end func_0031E128 */

/* merge_units: begin func_0031E180 */
int nciGetVADVoiceActivity(Handle_31E* h, unsigned short* out) { if (out == 0) return 0x181A; CHECK_31E(h) *out = h->inner->p->f1C; return 0; }
/* merge_units: end func_0031E180 */

/* merge_units: begin func_0031E1D8 */
int nciEnableAGC(Handle_31E* h) { CHECK_31E(h) h->inner->p->f1E = 1; return 0; }
/* merge_units: end func_0031E1D8 */

/* merge_units: begin func_0031E228 */
int nciDisableAGC(Handle_31E* h) { Params_31E* p; CHECK_31E(h) p = h->inner->p; p->f1E = 0; p->f14 = 0; return 0; }
/* merge_units: end func_0031E228 */

/* merge_units: begin func_0031E278 */
int nciSetAGCTargetGain(Handle_31E* h, short v) { CHECK_31E(h) h->inner->p->f16 = v; return 0; }
/* merge_units: end func_0031E278 */

/* merge_units: begin func_0031E2C8 */
int nciGetAGCTargetGain(Handle_31E* h, short* out) { if (out == 0) return 0x181A; CHECK_31E(h) *out = h->inner->p->f16; return 0; }
/* merge_units: end func_0031E2C8 */

/* merge_units: begin func_0031E320 */
int nciSetAGCControlValue(Handle_31E* h, short v) { CHECK_31E(h) h->inner->p->f14 = v; return 0; }
/* merge_units: end func_0031E320 */

/* merge_units: begin func_0031E370 */
int nciGetAGCControlValue(Handle_31E* h, short* out) { if (out == 0) return 0x181A; CHECK_31E(h) *out = h->inner->p->f14; return 0; }
/* merge_units: end func_0031E370 */

/* merge_units: begin func_0031E3C8 */
typedef struct {
    int f0;
    void* f4;
    void* f8;
    float fC;
    float f10;
    short f14;
    short f16;
    unsigned short f18;
    unsigned short f1A;
    short f1C;
    unsigned char f1E;
} S_0031E3C8;
extern float nemAgcGetMeanEnergy(void* p);
extern float EnergyToLevel(float x);
extern void nemVadBlockDec(float x, void* p);
extern void nemVadSpkrDec(float a, float b, short n, void* p);
extern void nemVadUpdateNoiseFlr(float x, void* p);
extern int nemVadTransmit(float a, short n, unsigned short m, void* p);
extern int nemVadVoicingDec(void* p, int f, float x);
extern void nemAgcMeanEngLevel(int n, void* p);
extern int nemAgcCalc(void* p, int n);
extern void nemAgcUpdateCounter(void* p);
int nemAgcVadMain(S_0031E3C8* s, float a, float b)
{
    float g, r;
    int pos;
    unsigned char c;
    s->fC = a;
    s->f10 = b;
    g = nemAgcGetMeanEnergy(s->f8);
    pos = s->f16 >= 0;
    if (!s->f18) s->f18 = 1;
    if (!s->f1A) s->f1A = 90;
    r = EnergyToLevel(a);
    c = (unsigned int)(r + 0.5f);
    nemVadBlockDec(a, s->f4);
    nemVadSpkrDec(r, g, s->f18, s->f4);
    nemVadUpdateNoiseFlr(a, s->f4);
    s->f1C = nemVadTransmit(r, s->f18, s->f1A, s->f4);
    if (nemVadVoicingDec(s->f4, pos, b)) {
        nemAgcMeanEngLevel(c, s->f8);
        if (s->f1E) s->f14 = nemAgcCalc(s->f8, s->f16);
    } else {
        nemAgcUpdateCounter(s->f8);
    }
    return 0;
}
/* merge_units: end func_0031E3C8 */
