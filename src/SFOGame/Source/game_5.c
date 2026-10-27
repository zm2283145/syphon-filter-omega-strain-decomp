/*
 * SFOGame/Source/game: 6 files, 0012F280-0012F5B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0012F280 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_0012F280(char* self, float value) {
    *(float*)(self + 212) = value;
}

float func_0012F290(char* self) {
    return *(float*)(self + 212);
}

void* pString_CStr(char* self) {
    return self + 1;
}

void* cSystem_GetObjectID_void(char* self) {
    return self + 12;
}

int func_0012F2C0(char* self) {
    return *(int*)(self + 220);
}

/* Empties a string buffer. */
char* pString_ctor(char* str) {
    str[0] = 0;
    return str;
}
static inline void merge_flush_func_0012F280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0012F280 */

/* merge_units: begin func_0012F2E0 */
#pragma push /* merge_units */
#pragma cplusplus on
class V_0012F2E0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual int f();
};
struct O_0012F2E0 { char pad[0xC]; unsigned int xC; char pad2[0x58-0x10]; V_0012F2E0* x58; };
extern "C" { extern unsigned char g_IsMultiplayer; }
extern "C" int cGOBJ_GetGobjClientIndex(O_0012F2E0* o)
{
    int r;
    if (g_IsMultiplayer) {
        bool ok = false;
        if (o->x58 && o->x58->f()) ok = true;
        r = ok ? (int)((o->xC & 0x7F000000) >> 24) - 1 : -1;
    } else {
        r = 0;
    }
    return r;
}
static inline void merge_flush_func_0012F2E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0012F2E0 */

/* merge_units: begin func_0012F370 */
#pragma push /* merge_units */
extern signed char* D_005061D0; /* read cursor into a byte stream */

int cGobjController_IsPlayer(void) {
    return 0;
}

/* Reads one byte from the stream and stores it as a bool (nonzero -> 1). */
void cNetMsg_GetChar(char* out) {
    signed char* p;
    signed char b;

    p = D_005061D0;
    b = *p;
    D_005061D0 = p + 1;
    *out = b != 0;
}

/* Reads one byte from the stream. */
void Stream_ReadByte(char* out) {
    signed char* p;
    signed char b;

    p = D_005061D0;
    b = *p;
    D_005061D0 = p + 1;
    *out = b;
}
static inline void merge_flush_func_0012F370(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0012F370 */

/* merge_units: begin func_0012F3D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on

#pragma opt_common_subs off

extern "C" {
int cMemMan_Allocate(int, int, char *, int);                      
int cMemMan_Deallocate(int, int, char *, int);                         
int Libc_Strcpy(int, int);                            
int strlen(int);                                    
extern unsigned char g_ProfileLockEnabled;
}
extern "C" void cGameSystem_SetPlayerFilename(char * arg0, int arg1) {
    int temp_s2;
    int temp_s2_2;
    int temp_s2_3;

    temp_s2 = F_(arg0, 0x1C0, int);
    if (temp_s2 != 0) {
        {
            AllocGuard g;
        cMemMan_Deallocate(0, temp_s2, "game.cc", 0xC1A);
        }
        F_(arg0, 0x1C0, int) = 0;
    }
    if (arg1 != 0) {
        temp_s2_2 = strlen(arg1) + 1;
        {
            AllocGuard g;
        temp_s2_3 = cMemMan_Allocate(0, temp_s2_2, "game.cc", 0xC20);
        }
        F_(arg0, 0x1C0, int) = temp_s2_3;
        Libc_Strcpy(F_(arg0, 0x1C0, int), arg1);
    }
}
static inline void merge_flush_func_0012F3D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0012F3D0 */

/* merge_units: begin func_0012F530 */
#pragma push /* merge_units */
extern int g_ProfileLockDepth;
void EnableIntc(int id);
void operator_delete(void* p);
void* cTimerDisable_dtor(void* self, short flags)
{
    if (self) {
        if (g_ProfileLockEnabled)
            EnableIntc(9);
        g_ProfileLockDepth--;
        if (flags > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_0012F530(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0012F530 */

/* merge_units: begin func_0012F5B0 */
#pragma push /* merge_units */
#include "game_types.h"

extern int strncpy(char* dst, const char* src, int n); /* bounded string copy */

int cGameSystem_GetClientPlayerLocation(NameSlotTable* t, int i) {
    return t->values[i];
}

void cGameSystem_SetClientPlayerLocation(NameSlotTable* t, int i, int value) {
    t->values[i] = value;
}

char* cGameSystem_GetClientPlayerName(NameSlotTable* t, int i) {
    return t->names[i];
}

/* Copies up to 15 characters of name into slot i and terminates it. */
int cGameSystem_SetClientPlayerName(NameSlotTable* t, int i, const char* name) {
    int ret;

    ret = strncpy(t->names[i], name, 15);
    t->names[i][15] = 0;
    return ret;
}
static inline void merge_flush_func_0012F5B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0012F5B0 */
