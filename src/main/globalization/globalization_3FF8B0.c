/*
 * main/globalization: 9 files, 003FF8B0-00400140
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003FF8B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
#include "vslot_pad.h"
struct Obj003FF8B0 { VPAD8(a) virtual void Set(int v); };
typedef struct { int kind; int id; int val; } Pk003FF8B0;
extern "C" {
extern unsigned char D_005721D0;
Obj003FF8B0** NetMap_Lookup(int);
}
#pragma push
#pragma opt_propagation off
extern "C" int func_003FF8B0(int a0, int a1, int a2, Pk003FF8B0* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Pk003FF8B0* p = arg;
        Obj003FF8B0** obj = NetMap_Lookup(p->id);
        if (obj) (*obj)->Set(p->val);
    }
    return 0xC;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_003FF8B0 */

/* merge_units: begin func_003FF930 */
#pragma push /* merge_units */
extern unsigned char D_005721C8;
extern void Transport_Send(int a, int b, int c, int d);
void func_003FF930(int a, int b)
{
    if (D_005721C8)
        Transport_Send(b, a, -1, -1);
}
#pragma pop /* merge_units */
/* merge_units: end func_003FF930 */

/* merge_units: begin func_003FF970 */
#pragma push /* merge_units */
float Math_StepAngleEighth(float target, float cur, float* maxStep) {
    float d = target - cur;
    float step;
    if (d > 3.1415927f) cur += 6.2831855f;
    if (d < -3.1415927f) cur -= 6.2831855f;
    step = (target - cur) / 8.0f;
    d = cur + step;
    if (step < 0.0f) step = -step;
    if (step > *maxStep) *maxStep = step;
    return d;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FF970 */

/* merge_units: begin func_003FFA20 */
#pragma push /* merge_units */
float Math_StepEighth(float* p, float a, float b) {
    float d = (a - b) / 8.0f;
    float r = b + d;
    if (d < 0.0f) {
        d = -d;
    }
    if (d > *p) {
        *p = d;
    }
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FFA20 */

/* merge_units: begin func_003FFA70 */
#pragma push /* merge_units */
typedef struct { char name[16]; } MorphShape;
extern MorphShape* D_005712F8[];
extern int D_005712F0[];
extern int strcmp(const char*, const char*);
int Morph_FindShapeIndex(const char* name, int set)
{
    MorphShape* s = D_005712F8[set];
    int n = D_005712F0[set];
    int i;
    for (i = 0; i < n; i++, s++) {
        if (strcmp(s->name, name) == 0)
            return i;
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FFA70 */

/* merge_units: begin func_003FFB20 */
#pragma push /* merge_units */
typedef union { __int128 q; char c[16]; } SkmName;
typedef struct { char* data; short free; char flag; char type; char* base; } SkmPkt;
extern SkmName D_005609B0[];
extern unsigned char D_005639B6[];
extern int String_CompareN(const char*, const char*, int);
extern char D_004BE618[], D_004BE620[], D_004BE628[], D_004BE630[], D_004BE638[], D_004BE640[],
    D_004BE648[], D_004BE650[], D_004BE658[], D_004BE660[], D_004BE668[], D_004BE670[],
    D_004BE678[], D_004BE680[], D_004BE688[], D_004BE690[], D_004BE698[], D_004BE6A0[],
    D_004BE6A8[], D_004BE6B0[], D_004BE6B8[], D_004BE6C0[], D_004BE6C8[], D_004BE6D0[],
    D_004BE6E0[], D_004BE6F0[], D_004BE700[], D_004BE710[], D_004BE720[], D_004BE730[],
    D_004BE740[], D_004BE750[];

void Skm_ClassifyParts(SkmPkt* b, int a, int c)
{
    int kind = 8;
    __int128 n = D_005609B0[a].q;
    char* p = (char*)&n;
    int flag = 0;
    if (String_CompareN(D_004BE618, p + 1, 3) == 0) kind = 8;
    if (String_CompareN(D_004BE620, p + 1, 3) == 0) kind = 8;
    if (String_CompareN(D_004BE628, p + 1, 3) == 0) kind = 8;
    if (String_CompareN(D_004BE630, p + 1, 3) == 0) kind = 8;
    if (String_CompareN(D_004BE638, p + 1, 3) == 0) kind = 8;
    if (String_CompareN(D_004BE640, p + 1, 3) == 0) kind = 8;
    if (String_CompareN(D_004BE648, p + 1, 3) == 0) kind = 4;
    if (String_CompareN(D_004BE650, p + 1, 3) == 0) kind = 4;
    if (String_CompareN(D_004BE658, p + 1, 3) == 0) kind = 4;
    if (String_CompareN(D_004BE660, p + 1, 3) == 0) kind = 4;
    if (String_CompareN(D_004BE668, p + 1, 3) == 0) kind = 0x1C;
    if (String_CompareN(D_004BE670, p + 1, 3) == 0) kind = 4;
    if (String_CompareN(D_004BE678, p + 1, 3) == 0) kind = 4;
    if (String_CompareN(D_004BE680, p + 1, 3) == 0) kind = 0x1C;
    if (String_CompareN(D_004BE688, p + 1, 3) == 0) kind = 0x1C;
    if (String_CompareN(D_004BE690, p + 1, 3) == 0) kind = 4;
    if (String_CompareN(D_004BE698, p + 1, 3) == 0) kind = 4;
    if (String_CompareN(D_004BE6A0, p + 1, 3) == 0) kind = kind;
    if (String_CompareN(D_004BE6A8, p + 1, 3) == 0) kind = 0x1C;
    if (String_CompareN(D_004BE6B0, p + 1, 3) == 0) kind = 0x1C;
    if (String_CompareN(D_004BE6B8, p + 1, 3) == 0) kind = 0x1C;
    if (String_CompareN(D_004BE6C0, p + 1, 3) == 0) kind = 0xC;
    if (String_CompareN(D_004BE6C8, p + 1, 3) == 0) kind = 8;
    if (String_CompareN(D_004BE6D0, p + 1, 8) == 0) kind = 0x10;
    if (String_CompareN(D_004BE6E0, p + 1, 8) == 0) { kind = 0xC; flag = 0x80; }
    if (String_CompareN(D_004BE6F0, p + 1, 8) == 0) { kind = 0x14; flag = 0x80; }
    if (String_CompareN(D_004BE700, p + 1, 9) == 0) { kind = 0x14; flag = 0x80; }
    if (String_CompareN(D_004BE710, p + 1, 9) == 0) { kind = 0x14; flag = 0x80; }
    if (String_CompareN(D_004BE720, p + 1, 9) == 0 || String_CompareN(D_004BE730, p + 1, 9) == 0 ||
        String_CompareN(D_004BE740, p + 1, 9) == 0 || String_CompareN(D_004BE750, p + 1, 9) == 0)
        kind = 0xC;
    D_005639B6[a * 32 + c * 16] |= (unsigned char)(kind | flag);
}
#pragma pop /* merge_units */
/* merge_units: end func_003FFB20 */

/* merge_units: begin func_003FFFC0 */
#pragma push /* merge_units */
extern void Skm_ClassifyParts(SkmPkt* b, int a, int c);
static inline __int128 skmzero(int* pc) {
    __int128 z;
    int t;
    asm {
        paddub t, zero, zero
        pcpyld z, zero, t
    }
    *pc = t;
    return z;
}
static inline int skmeq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
void Skm_LoadPacket(SkmPkt* b, char* buf, int size, long a, long c, char flag) {
    int pad;
    __int128 z = skmzero(&pad);
    char* p = buf + size;
    p -= 16;
    b->type = buf[0];
    b->base = buf;
    b->data = buf + ((buf[0] * 2 + 0x11) & ~0xF);
    while (skmeq(*(__int128*)p, z)) {
        p -= 16;
        pad++;
    }
    b->free = (size >> 4) - pad - (b->data - (char*)*(char* volatile*)&b->base) / 16;
    if (buf[1] != 3) {
        b->data = 0;
        b->free = 0;
        b->type = 0;
    }
    b->flag = flag;
    Skm_ClassifyParts(b, a, c);
}
#pragma pop /* merge_units */
/* merge_units: end func_003FFFC0 */

/* merge_units: begin func_00400090 */
#pragma push /* merge_units */
typedef struct { char* data; short free; char used; char type; char* base; int pos; } B090;
static inline __int128 b090zero(void) {
    __int128 z;
    long long t;
    asm {
        paddub t, zero, zero
        pcpyld z, zero, t
    }
    return z;
}
static inline int b090eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
/* Initialises a block reader over buf, skipping zero padding at its end. */
void Skm_ParseRecord(B090* b, char* buf, int size) {
    __int128 z = b090zero();
    int pad = 0;
    char* p = buf + size;
    p -= 16;
    b->type = buf[0];
    b->base = buf;
    b->data = buf + ((buf[0] * 2 + 0x11) & ~0xF);
    while (b090eq(*(__int128*)p, z)) {
        p -= 16;
        pad++;
    }
    b->free = (size >> 4) - pad - (b->data - (char*)*(char* volatile*)&b->base) / 16;
    b->used = 0;
    b->pos = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00400090 */

/* merge_units: begin func_00400140 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

void func_00400140(Unk400140* self, int a, int b, int c, int d) {
    self->unk00 = 0;
    self->unk04 = a;
    self->unk06 = c;
    self->unk07 = 0;
    self->unk08 = b;
    self->unk0C = d;
}
#pragma pop /* merge_units */
/* merge_units: end func_00400140 */
