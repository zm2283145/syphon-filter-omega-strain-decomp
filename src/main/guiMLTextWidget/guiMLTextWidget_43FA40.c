/*
 * main/guiMLTextWidget: 4 files, 0043FA40-0043FDD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043FA40 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
extern char D_004DFD80[];
extern char D_004E1140[];
}
struct M1EEDC0 { void* vtable; int w4, w8, wC, w10, w14, w18, w1C; char b20; int w24; };
extern "C" M1EEDC0* cWeaponVisChangeMsg_v01(M1EEDC0* self)
{
    M1EEDC0* p;
    {
        AllocGuard guard;
        p = (M1EEDC0*)Mem_Alloc(0, 0x28, "WeaponVisChangeMsg.hh", 0xA);
    }
    if (p) {
        p->vtable = D_004DFD80;
        p->w4 = self->w4;
        p->w8 = self->w8;
        p->wC = self->wC;
        p->w10 = self->w10;
        p->w14 = self->w14;
        p->w18 = self->w18;
        p->w1C = self->w1C;
        p->b20 = self->b20;
        p->vtable = D_004E1140;
        p->w24 = self->w24;
    }
    return p;
}
#pragma pop /* merge_units */
/* merge_units: end func_0043FA40 */

/* merge_units: begin func_0043FB40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Script type registration and accessor for cWeaponVisChangeMsg.
 * Address lies after guiMLTextWidget.cc (ends 0x0043E330).
 */

#include "loose05_types.h"

extern int D_00583970; /* cWeaponVisChangeMsg key */
extern int D_00583978; /* cWeaponVisChangeMsg type id */
extern int* Message_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int parent);

/* Script native: returns the message's visibility word. */
int Script_cWeaponVisChangeMsg_Visibility(ScriptMsg24** args) {
    volatile int value = args[0]->value; /* stored to the stack and reloaded */

    return value;
}

/* cWeaponVisChangeMsg derives from the message base type. */
void ScriptType_cWeaponVisChangeMsg_Init(void) {
    int* parent = Message_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_00583978, *parent);
}

int* cWeaponVisChangeMsg_GetScriptTypeKeyPtr(void) {
    return &D_00583970;
}

int cWeaponVisChangeMsg_v03(void) {
    return D_00583970;
}
#pragma pop /* merge_units */
/* merge_units: end func_0043FB40 */

/* merge_units: begin func_0043FBB0 */
#pragma push /* merge_units */
typedef struct {
    int count;
    unsigned short chars[0xDE];
    unsigned char buf[4][0x100];
    unsigned char* pages[256];
} Map_FBB0;

typedef struct { char pad[0xC4]; char* text; char padC8[8]; } File_FBB0;

extern char D_004C02A0[];
extern unsigned int strlen(const char*);
void FileHal_CtorDefault(File_FBB0* f);
void FileHal_Reopen(File_FBB0* f, const char* path, int mode);
unsigned int FileHal_ReadAll(File_FBB0* f);
void FileHal_Dtor(File_FBB0* f, int a);
int CharMap_Parse(Map_FBB0* m, char* text);

int CharMap_Load(Map_FBB0* m, const char* path)
{
    File_FBB0 f;
    unsigned int size;
    int i;
    int n;
    int j;
    FileHal_CtorDefault(&f);
    FileHal_Reopen(&f, path, 1);
    size = FileHal_ReadAll(&f);
    if (size <= strlen(D_004C02A0) + 2) {
        FileHal_Dtor(&f, -1);
        return 0;
    }
    if (!CharMap_Parse(m, f.text)) {
        FileHal_Dtor(&f, -1);
        return 0;
    }
    for (i = 0; i < 256; i++) m->pages[i] = 0;
    m->pages[0] = m->buf[0];
    n = 1;
    for (i = 0; i < 32; i++) m->pages[0][i] = i;
    for (j = 0; j < m->count; j++) {
        unsigned short c = m->chars[j];
        if (!m->pages[c >> 8]) {
            if (n == 4) {
                FileHal_Dtor(&f, -1);
                return 0;
            }
            m->pages[c >> 8] = m->buf[n];
            n++;
        }
        m->pages[c >> 8][c & 0xFF] = j;
    }
    FileHal_Dtor(&f, -1);
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_0043FBB0 */

/* merge_units: begin func_0043FDD0 */
#pragma push /* merge_units */
/* Initialize an empty lookup table without touching its inline storage. */
Lookup43FDD0* func_0043FDD0(Lookup43FDD0* self) {
    int index;
    self->count = 0;
    for (index = 0; index < 256; index++) {
        self->pages[index] = 0;
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0043FDD0 */
