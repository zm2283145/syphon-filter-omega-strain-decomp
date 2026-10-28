/*
 * Libs/SFOLib/Source/man: 1 file, 0038DB30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0038DB30 */
#pragma push /* merge_units */
#include "types.h"

#pragma cplusplus on

struct manAttribs {
    __int128 a;
    __int128 b;
};

struct SKL {
    __int128 hdr[4];
    manAttribs manAttribsTable[32];
};

struct cMan {
    char pad0[0x20];
    char SKLName[0x20];
    SKL skl;
    char pad480[0x22C0 - 0x480];
    short tex[0x20];
    short tex2[0x60];
    unsigned short count;
    char pad23C2[0x2BD0 - 0x23C2];
    int faceCamo;
    char pad2BD4[0x2C0D - 0x2BD4];
    char race;
};

extern "C" {
extern char g_AgentPartCache[];
extern char D_005711B0[];
extern char D_004BC398[];
extern char D_004BC3A0[];
void strCpyPad(char* dst, int n, char* src);
char* Libc_Strcpy(char* dst, const char* src);
int String_CompareNoCase(const char* a, const char* b);
char SKL_FindRace(SKL* skl);
int SKL_CountAttribs(SKL* skl);
void SKL_AddAccessorySKL(SKL* skl, int identity, int count, char* name);
void SKL_RemoveBlanks(SKL* skl);
int SKL_LoadSKLParts(SKL* skl, int hard, char* name);
void Monster_FindAddTexture(char* cache, __int128 name, char* tex, short* a, short* b);
void cMan_SortParts(cMan* self);
void cMan_BuildMan(cMan* self, int flag);
}

/* skl = *sklData quad copy loop (hand-written addi); GCC-style operands also put mwcc in the
   no-global-CSE/no-loop-opt mode retail shows (loop tests and bodies reload separately) */
static inline void QMove(void* dd, void* ss, int nn) { int n = nn; __int128 q; void* s = ss; void* d = dd;
    __asm__ volatile(".set noreorder; nop; 1: lq %0, 0(%2); addiu %1, %1, 0x10; addi %3, %3, -1; addiu %2, %2, 0x10; bgtz %3, 1b; sq %0, -0x10(%1); .set reorder" : "=&r"(q), "+r"(d), "+r"(s), "+r"(n) : : "memory");
}

extern "C" void cMan_Load(cMan* self, char* name, SKL* sklData, int identity)
{
    int count;
    int texParts;
    if (sklData) QMove(&self->skl, sklData, sizeof(SKL) / 16);
    if (name) strCpyPad(self->SKLName, 31, name);
    else Libc_Strcpy(self->SKLName, D_004BC398);
    for (char* p = self->SKLName; *p; p++) {
        char c = *p; if (c >= 'a' && c <= 'z') *p = c - 32;
    }
    self->race = SKL_FindRace(&self->skl);
    if (identity >= 0) {
        self->count = SKL_CountAttribs(&self->skl);
        if (String_CompareNoCase(name, D_004BC3A0)) {
            SKL_AddAccessorySKL(&self->skl, identity, self->count, self->SKLName);
        } else {
            count = self->count;
            self->skl.manAttribsTable[0] = self->skl.manAttribsTable[count];
            count++; self->skl.manAttribsTable[1] = self->skl.manAttribsTable[count];
            self->count = 0;
        }
    } else {
        SKL_RemoveBlanks(&self->skl);
    }
    cMan_SortParts(self);
    for (texParts = 0; self->skl.manAttribsTable[texParts].b; texParts++) {
        Monster_FindAddTexture(g_AgentPartCache, self->skl.manAttribsTable[texParts].b, D_005711B0, &self->tex[texParts], &self->tex2[texParts]);
    }
    self->tex[texParts] = 0;
    self->count = SKL_LoadSKLParts(&self->skl, 1, self->SKLName);
    if (self->count < texParts) self->faceCamo = 1;
    cMan_BuildMan(self, 1);
}
static inline void merge_flush_func_0038DB30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0038DB30 */
