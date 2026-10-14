/*
 * main/gameSound: range (3 files, 001C9F10-001CA010)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"

/* merge_units: begin func_001C9F10 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
void func_0036E220(void* member, int flags);
void operator_delete(void* p);
}
struct P1C9F10 { char pad[0x20]; char payload[0x48]; char memberA[0x9C]; char memberB[4]; };
extern "C" P1C9F10* func_001C9F10(P1C9F10* self, short deleteFlag)
{
    if (self) {
        if (self->payload) {
            func_0036E220(self->memberB, -1);
            func_0036E220(self->memberA, -1);
        }
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C9F10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C9F10 */

/* merge_units: begin func_001C9F80 */
#pragma push /* merge_units */
#pragma cplusplus on
struct H1C9F80 { int v; };
struct P1C9F80 {
    int id;
    char pad04[0xC];
    __int128 mask;
    int w20;
    H1C9F80 h24;
    char pad28[8];
    int w30, w34, w38;
    char pad3C[0x0C];
    char memberA[0x9C];
    char memberB[0x9C];
    int w180;
    short h184;
    unsigned char b186;
};
extern "C" void func_0036E5D0(void* m);
/* constructor: reset two members, ids, mask, handle (copied through a stack temp) */
#pragma push
#pragma opt_propagation off
extern "C" char* func_001C9F80(char* self)
{
    P1C9F80* p;
    *(int*)(self + 0x44) = -2;
    *(int*)(self + 0x40) = 0;
    p = (P1C9F80*)(self + 0x20);
    func_0036E5D0(p->memberA);
    func_0036E5D0(p->memberB);
    p->id = -1;
    p->mask = -1;
    p->w20 = 0;
    { H1C9F80 h; H1C9F80* hp = &h; h.v = -1; p->h24 = *hp; }
    p->w30 = 0;
    p->w34 = 0;
    p->w38 = 0;
    p->h184 = -1;
    p->w180 = 0;
    p->b186 = 0;
    return self;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C9F80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C9F80 */

/* merge_units: begin func_001CA010 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int id; } VoiceA010;
typedef struct {
    int type;
    char pad04[0xC];
    char name[0x10];
    VoiceA010* voice;
    int voiceId;
    char pad28[8];
    int x30;
    int x34;
    int x38;
    char pad3C[0x180 - 0x3C];
    int x180;
    short x184;
} SoundActionA010;
static inline void MemClearA010(void* d0, int n0) { int n = n0; void* dst = d0;
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
void SoundAction_CtorVoice(SoundActionA010* p, int type, const char* name, VoiceA010* voice, int x180) {
    int tmp;
    int* r;
    p->type = type;
    p->voice = voice;
    if (voice) {
        r = &voice->id;
    } else {
        tmp = -1;
        r = &tmp;
    }
    p->voiceId = *r;
    p->x30 = 0;
    p->x34 = 0;
    p->x38 = 0;
    p->x180 = x180;
    p->x184 = -1;
    MemClearA010(p->name, 0x10);
    String_Copy(p->name, name);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001CA010(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001CA010 */
