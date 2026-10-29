#pragma cplusplus on
#include "alloc_guard.h"
typedef __int128 u_long128;
struct cArray { int cap; int count; char** data; unsigned char canExpand; };
struct Monster {
    char pad0[0xC0];
    unsigned int monsterPartCount;
    unsigned int monsterHandFaceCount;
    unsigned int monsterCoreCount;
    unsigned int manTexCount;
    unsigned int texCoreCount;
    u_long128* savedPartNames;
    u_long128* savedTexNames;
    unsigned int savedPartCount;
    unsigned int savedTexCount;
    char pad1[0x2C10 - 0xE4];
    u_long128 monsterPartNames[(0xBC10 - 0x2C10) / 16];
    u_long128 texNames[1024];
};
extern "C" {
extern char D_004BE7F0[];
extern u_long128 D_005716E0;
void* cMemMan_Allocate(int pool, int size, char* file, int line);
char* strchr(const char* s, int c);
void strCpyPad(char* dst, int n, char* src);
}
static inline void QCopy(void* d0, void* s0, int n0) { void* d; int n; u_long128 t; void* s; n = n0; d = d0; s = s0;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}
static inline long long QEq(u_long128 a, u_long128 b) {
 u_long128 t;
 long long r;
 asm {
 pceqw t, a, b
 ppach r, t, t
 }
 return r;
}
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_common_subs on
extern "C" void Monster_HideLockedPartsTex(Monster* self, cArray* names) {
    u_long128 partName;
    unsigned int texNumber;
    unsigned int partNumber;
    int found;
    int count;
    char* dot;
    int i;
    count = names->count;
    if (self->savedPartNames == 0) {
        { u_long128* t; { int sz = self->monsterPartCount * 16; AllocGuard g; t = (u_long128*)cMemMan_Allocate(0, sz, D_004BE7F0, 0xA3C); } self->savedPartNames = t; }
        { u_long128* t; { int sz = self->manTexCount * 16; AllocGuard g; t = (u_long128*)cMemMan_Allocate(0, sz, D_004BE7F0, 0xA3D); } self->savedTexNames = t; }
        self->savedPartCount = self->monsterPartCount;
        self->savedTexCount = self->manTexCount;
        QCopy(self->savedPartNames, self->monsterPartNames, self->savedPartCount);
        QCopy(self->savedTexNames, self->texNames, self->savedTexCount);
    }
    for (i = 0; i < count; i++) {
        found = 0;
        dot = strchr(names->data[i], '.'); switch ((int)dot) { case 0: break; default: continue; }
        strCpyPad((char*)&partName, 15, names->data[(int)i]);
        for (partNumber = 0; partNumber < self->monsterPartCount; partNumber++) {
            /* address arithmetic written this way to get retail's idx+self addu order */
            dot = (char*)&self->monsterPartCount + partNumber*16 - 0xC0;
            if (QEq(partName, *(u_long128*)(dot + 0x2C10)) == -1) { found = 1; *(u_long128*)(dot + 0x2C10) = D_005716E0; }
        }
        if (!found) {
            for (texNumber = 0; texNumber < self->manTexCount; texNumber++) {
                dot = (char*)&self->monsterPartCount + texNumber*16 - 0xC0;
                if (QEq(partName, *(u_long128*)(dot + 0xBC10)) == -1) *(u_long128*)(dot + 0xBC10) = D_005716E0;
            }
        }
    }
}


