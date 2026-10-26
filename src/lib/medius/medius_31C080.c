/*
 * lib/medius: 12 files, 0031C080-0031C3F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0031C080 */
#include "types.h"
typedef struct {
    long magic;
    char pad08[0x10];
    unsigned char state;
    char pad19[3];
    void* inner;
} Handle_0031C080;
extern void NellySetPitchOffsetSase3200(void* p);
int nciSetPitchOffsetSase3200(Handle_0031C080* h)
{
    if (h == 0 || h->magic != 0xFACE) return 0x17D4;
    if (h->state != 10) return 0x17DE;
    NellySetPitchOffsetSase3200(h->inner);
    return 0;
}
/* merge_units: end func_0031C080 */

/* merge_units: begin func_0031C0D0 */
typedef struct {
    long magic;
    char pad08[0x10];
    unsigned char state;
    char pad19[3];
    void* inner;
} Handle_0031C0D0;
extern void NellySetSpectralFactorSase3200(void* p);
int nciSetSpectralFactorSase3200(Handle_0031C0D0* h)
{
    if (h == 0 || h->magic != 0xFACE) return 0x17D4;
    if (h->state != 10) return 0x17DE;
    NellySetSpectralFactorSase3200(h->inner);
    return 0;
}
/* merge_units: end func_0031C0D0 */

/* merge_units: begin func_0031C120 */
typedef struct {
    long magic;
    char pad08[0x10];
    unsigned char state;
    char pad19[3];
    void* inner;
} Handle_0031C120;
extern void NellySetSpectralLedgeSase3200(void* p);
int nciSetSpectralLedgeSase3200(Handle_0031C120* h)
{
    if (h == 0 || h->magic != 0xFACE) return 0x17D4;
    if (h->state != 10) return 0x17DE;
    NellySetSpectralLedgeSase3200(h->inner);
    return 0;
}
/* merge_units: end func_0031C120 */

/* merge_units: begin func_0031C170 */
typedef struct {
    long magic;
    char pad08[0x10];
    unsigned char state;
    char pad19[3];
    void* inner;
} Handle_0031C170;
extern void NellySetWhisperFactorSase3200(void* p);
int nciSetWhisperFactorSase3200(Handle_0031C170* h)
{
    if (h == 0 || h->magic != 0xFACE) return 0x17D4;
    if (h->state != 10) return 0x17DE;
    NellySetWhisperFactorSase3200(h->inner);
    return 0;
}
/* merge_units: end func_0031C170 */

/* merge_units: begin func_0031C1C0 */
typedef struct {
    long magic;
    char pad08[0x10];
    unsigned char state;
    char pad19[3];
    void* inner;
} Handle_0031C1C0;
extern void NellySetRoboticFactorSase3200(void* p);
int nciSetRoboticFactorSase3200(Handle_0031C1C0* h)
{
    if (h == 0 || h->magic != 0xFACE) return 0x17D4;
    if (h->state != 10) return 0x17DE;
    NellySetRoboticFactorSase3200(h->inner);
    return 0;
}
/* merge_units: end func_0031C1C0 */

/* merge_units: begin func_0031C210 */
typedef struct {
    long magic;
    char pad08[0x10];
    unsigned char state;
    char pad19[3];
    void* inner;
} Handle_0031C210;
extern void NellyPrimaryOnSase3200(void* p);
int nciEnableVoiceFontsSase3200(Handle_0031C210* h)
{
    if (h == 0 || h->magic != 0xFACE) return 0x17D4;
    if (h->state != 10) return 0x17DE;
    NellyPrimaryOnSase3200(h->inner);
    return 0;
}
/* merge_units: end func_0031C210 */

/* merge_units: begin func_0031C260 */
typedef struct {
    long magic;
    char pad08[0x10];
    unsigned char state;
    char pad19[3];
    void* inner;
} Handle_0031C260;
extern void NellyPrimaryOffSase3200(void* p);
int nciDisableVoiceFontsSase3200(Handle_0031C260* h)
{
    if (h == 0 || h->magic != 0xFACE) return 0x17D4;
    if (h->state != 10) return 0x17DE;
    NellyPrimaryOffSase3200(h->inner);
    return 0;
}
/* merge_units: end func_0031C260 */

/* merge_units: begin func_0031C2B0 */
typedef struct {
    long magic;
    char pad08[0x10];
    unsigned char state;
    char pad19[3];
    void* inner;
} Handle_0031C2B0;
extern void NellyRobotOnSase3200(void* p);
int nciRobotOnSase3200(Handle_0031C2B0* h)
{
    if (h == 0 || h->magic != 0xFACE) return 0x17D4;
    if (h->state != 10) return 0x17DE;
    NellyRobotOnSase3200(h->inner);
    return 0;
}
/* merge_units: end func_0031C2B0 */

/* merge_units: begin func_0031C300 */
typedef struct {
    long magic;
    char pad08[0x10];
    unsigned char state;
    char pad19[3];
    void* inner;
} Handle_0031C300;
extern void NellyRobotOffSase3200(void* p);
int nciRobotOffSase3200(Handle_0031C300* h)
{
    if (h == 0 || h->magic != 0xFACE) return 0x17D4;
    if (h->state != 10) return 0x17DE;
    NellyRobotOffSase3200(h->inner);
    return 0;
}
/* merge_units: end func_0031C300 */

/* merge_units: begin func_0031C350 */
typedef struct {
    long magic;
    char pad08[0x10];
    unsigned char state;
    char pad19[3];
    void* inner;
} Handle_0031C350;
extern void NellyWhisperOnSase3200(void* p);
int nciWhisperOnSase3200(Handle_0031C350* h)
{
    if (h == 0 || h->magic != 0xFACE) return 0x17D4;
    if (h->state != 10) return 0x17DE;
    NellyWhisperOnSase3200(h->inner);
    return 0;
}
/* merge_units: end func_0031C350 */

/* merge_units: begin func_0031C3A0 */
typedef struct {
    long magic;
    char pad08[0x10];
    unsigned char state;
    char pad19[3];
    void* inner;
} Handle_0031C3A0;
extern void NellyWhisperOffSase3200(void* p);
int nciWhisperOffSase3200(Handle_0031C3A0* h)
{
    if (h == 0 || h->magic != 0xFACE) return 0x17D4;
    if (h->state != 10) return 0x17DE;
    NellyWhisperOffSase3200(h->inner);
    return 0;
}
/* merge_units: end func_0031C3A0 */

/* merge_units: begin func_0031C3F0 */
typedef struct {
    void *in;
    int a4;
    void *out;
    unsigned short len;
    unsigned short posE;
    unsigned char b10;
    unsigned short pos12;
    unsigned char b14;
} Buf_c3f0;

typedef struct {
    long magic;
    char pad8[0x10];
    unsigned char b18;
    void *st;
} Ctx_c3f0;

typedef struct { float f[20]; } Tmp_c3f0;

extern int func_00323248(void);
extern void VU0Save(Ctx_c3f0 *c);
extern void VU0Restore(Ctx_c3f0 *c);
extern void NellyEncodeSC(void *in, void *st, Tmp_c3f0 *t);
extern void NellyQuantSC3(Tmp_c3f0 *o, void *st, Tmp_c3f0 *p);
extern void NellyPackSC3(Tmp_c3f0 *t, void *out, unsigned short *pos, unsigned char *bit, unsigned short len, int flag);

int nciEncodeSase3200(Ctx_c3f0 *c, Buf_c3f0 *b)
{
    Tmp_c3f0 t1, t2;

    if (b == 0) return 0x181A;
    if (b->out == 0) return 0x17F2;
    if (b->in == 0) return 0x17ED;
    if (b->posE >= b->len) return 0x1801;
    if (b->pos12 >= b->len) return 0x1806;
    if (b->b10 >= 8) return 0x17F7;
    if (b->b14 >= 8) return 0x17FC;
    if (c == 0 || c->magic != 0xFACE) return 0x17D4;
    if (c->b18 != 10) return 0x17DE;
    if (func_00323248() == 3) VU0Save(c);
    NellyEncodeSC(b->in, c->st, &t1);
    NellyQuantSC3(&t2, c->st, &t1);
    NellyPackSC3(&t2, b->out, &b->pos12, &b->b14, b->len, 0);
    if (func_00323248() == 3) VU0Restore(c);
    return 0;
}
/* merge_units: end func_0031C3F0 */
