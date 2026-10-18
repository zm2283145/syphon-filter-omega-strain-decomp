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
extern "C" void String_Copy(char* dst, const char* src);
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
extern "C" void Resource_Construct(void* p);
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
extern "C" SoundActionA0E0* SoundRequest_CtorStart(SoundActionA0E0* p, int type, const char* name, VecA0E0* pos, int x180) {
    p->voiceId = -2;
    p->voice = 0;
    Resource_Construct((char*)p + 0x48);
    Resource_Construct((char*)p + 0xE4);
    p->type = type;
    SetVoice(p, 0);
    p->pos = *pos;
    p->x180 = x180;
    p->x184 = -1;
    MemClearA0E0(p->name, 0x10);
    String_Copy(p->name, name);
    p->x186 = 0;
    return p;
}
