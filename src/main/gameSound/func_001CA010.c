#include "types.h"
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
extern void String_Copy(char* dst, const char* src);
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