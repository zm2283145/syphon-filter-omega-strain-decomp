/*
 * SFOGame/Source/gameSound: 6 files, 001CA0E0-001CA5C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001CA0E0 */
#pragma push /* merge_units */
#pragma opt_foldconstants off
#include "types.h"
#pragma cplusplus on
struct VecA0E0 {
    int v[4];
    VecA0E0& operator=(const VecA0E0& o) { VecA0E0* d = this; const VecA0E0* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
typedef struct { char pad[0xC]; int id; } VoiceA0E0;
typedef struct {
    int type;
    char pad04[0xC];
    char name[0x10];
    VoiceA0E0* voice;
    int voiceId;
    char pad28[8];
    VecA0E0 pos;
    char pad40[0x180 - 0x40];
    int x180;
    short x184;
    char x186;
} SoundActionA0E0;
extern "C" void Libc_Strcpy(char* dst, const char* src);
static inline void MemClearA0E0(void* d0, int n0) { int n = n0; void* dst = d0;
    asm {
        .set noreorder
        blez n, done
        nop
        andi $a0, dst, 0xF
        andi $v0, n, 0xF
        or $a0, $a0, $v0
        nop
        bgtz $a0, bytes
        srl $v0, n, 4
        nop
        blez $v0, bytes
        nop
        nop
    quads:
        addi $v0, $v0, -1
        sq $zero, 0(dst)
        bgtz $v0, quads
        addiu dst, dst, 0x10
        b done
        nop
    bytes:
        addi n, n, -1
        sb $zero, 0(dst)
        bgtz n, bytes
        addiu dst, dst, 1
        .set reorder
    done:
    }
}
extern "C" void cFileMan_ctor_void(void* p);
static inline void SetVoice(SoundActionA0E0* p, VoiceA0E0* voice) {
    int tmp;
    int* r;
    p->voice = voice;
    if (voice) {
        r = &voice->id;
    } else {
        tmp = -1;
        r = &tmp;
    }
    p->voiceId = *r;
}
extern "C" SoundActionA0E0* cSndFx_ctor_int_charP_cVectorR_int(SoundActionA0E0* p, int type, const char* name, VecA0E0* pos, int x180) {
    p->voiceId = -2;
    p->voice = 0;
    cFileMan_ctor_void((char*)p + 0x48);
    cFileMan_ctor_void((char*)p + 0xE4);
    p->type = type;
    SetVoice(p, 0);
    p->pos = *pos;
    p->x180 = x180;
    p->x184 = -1;
    MemClearA0E0(p->name, 0x10);
    Libc_Strcpy(p->name, name);
    p->x186 = 0;
    return p;
}
static inline void merge_flush_func_001CA0E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CA0E0 */

/* merge_units: begin func_001CA210 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int id; } VoiceA210;
typedef struct {
    int type;
    char pad04[0xC];
    char name[0x10];
    VoiceA210* voice;
    int voiceId;
    char pad28[8];
    int x30;
    int x34;
    int x38;
    char pad3C[0x180 - 0x3C];
    int x180;
    short x184;
    char x186;
} SoundActionA210;
extern void Libc_Strcpy(char* dst, const char* src);
static inline void MemClearA210(void* d0, int n0) { int n = n0; void* dst = d0;
    asm {
        .set noreorder
        blez n, done
        nop
        andi $v1, dst, 0xF
        andi $v0, n, 0xF
        or $v1, $v1, $v0
        nop
        bgtz $v1, bytes
        srl $v0, n, 4
        nop
        blez $v0, bytes
        nop
        nop
    quads:
        addi $v0, $v0, -1
        sq $zero, 0(dst)
        bgtz $v0, quads
        addiu dst, dst, 0x10
        b done
        nop
    bytes:
        addi n, n, -1
        sb $zero, 0(dst)
        bgtz n, bytes
        addiu dst, dst, 1
        .set reorder
    done:
    }
}
extern void cFileMan_ctor_void(void* p);
SoundActionA210* cSndFx_ctor_int_charP_cGOBJP_int(SoundActionA210* p, int type, const char* name, VoiceA210* voice, int x180) {
    int tmp;
    int* r;
    p->voiceId = -2;
    p->voice = 0;
    cFileMan_ctor_void((char*)p + 0x48);
    cFileMan_ctor_void((char*)p + 0xE4);
    p->type = type;
    p->voice = voice;
    if (voice) {
        r = &voice->id;
    } else {
        tmp = -1;
        r = &tmp;
    }
    p->voiceId = *r;
    p->x184 = -1;
    p->x180 = x180;
    p->x30 = 0;
    p->x34 = 0;
    p->x38 = 0;
    MemClearA210(p->name, 0x10);
    Libc_Strcpy(p->name, name);
    p->x186 = 0;
    return p;
}
static inline void merge_flush_func_001CA210(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CA210 */

/* merge_units: begin func_001CA340 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cStopAllQuipsMsg virtual slots.
 */

#include "gameSound_types.h"

extern int D_004F2CF0; /* cStopAllQuipsMsg script type key */

void cStopAllQuipsMsg_v04(void) {
}

int cStopAllQuipsMsg_v05(void) {
    return D_004F2CF0;
}
static inline void merge_flush_func_001CA340(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CA340 */

/* merge_units: begin func_001CA360 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "net_msg_clone.h"
#pragma pop
#include "net_write_two_words.h"

#pragma cplusplus on
extern "C" {
char D_0049F708[] = "gameSound.cc";
}
DEFINE_NET_MSG_CLONE(cPlayQuipMsg_Clone, 0x24, D_0049F708, 0x6D0, D_004DAC50, (void)0)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001CA360(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001CA360 */

/* merge_units: begin func_001CA470 */
#pragma push /* merge_units */
/* Serialize the two 32-bit message fields. */
DEFINE_NET_WRITE_TWO_WORDS(cPlayQuipMsg_Pack)
static inline void merge_flush_func_001CA470(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CA470 */

/* merge_units: begin func_001CA5C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cPlayQuipMsg virtual slot.
 */


extern int D_004F2D08; /* cPlayQuipMsg script type key */

int cPlayQuipMsg_v05(void) {
    return D_004F2D08;
}
static inline void merge_flush_func_001CA5C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CA5C0 */
