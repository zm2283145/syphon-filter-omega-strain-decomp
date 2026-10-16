/*
 * main/gameFrontEnd: range (3 files, 002C90F0-002C9270)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

/* merge_units: begin func_002C90F0 */
#pragma push /* merge_units */
typedef struct { char pad[0x24C]; int textIndex; } Ctx9070;
typedef struct { char pad[0x35]; unsigned char enabled; } Obj9070;
extern unsigned char D_005721C8;
extern Ctx9070* D_004FFC04;
extern char D_004ACBE8[];
extern char D_004ACBF8[];
extern char D_004ACC08[];
extern char D_004ACC18[];
static void * const dat_0048C1B0[20] = { (void*)0x0, (void*)0x0, (void*)0x0, (void*)D_004ACBE8, (void*)0x0, (void*)0x0, (void*)D_004ACBF8, (void*)0x0, (void*)0x0, (void*)0x0, (void*)D_004ACC08, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)D_004ACC18, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0 };
extern char* Loc_LookupText(char* key);
char* func_002C90F0(Obj9070* o)
{
    int i;
    char* key;
    if (o->enabled && !D_005721C8) {
        i = D_004FFC04->textIndex;
        if (i != -1) {
            key = ((char**)dat_0048C1B0)[i];
            if (key)
                return Loc_LookupText(key);
        }
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C90F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C90F0 */

/* merge_units: begin func_002C9170 */
#pragma push /* merge_units */
void func_002C9270(char* buf, int id, int nameId, int newline); /* gsynth: defined below */
#pragma cplusplus on
class Ctl9170 {
public:
    VPAD16(p) VPAD2(q) VPAD1(r)
    virtual int isTeamed();      /* slot 19 */
};
struct Obj9170 { char pad[0xC]; unsigned int flags; char pad2[0x48]; Ctl9170* ctl; };
extern "C" {
Obj9170* PlayerSlots_Get(int i);
#if 0 /* merge_units */
void func_002C9270(int a, Obj9170* o, int key, int c);
#endif /* merge_units */
#define func_002C9270(a0, a1, a2, a3) (func_002C9270((char *)(a0), (int)(a1), (a2), (a3))) /* merge_units */

}
extern "C" void func_002C9170(int a, int key, int c)
{
    int i;
    for (i = 0; i < 4; i++) {
        Obj9170* o = PlayerSlots_Get(i);
        int k;
        if (!o)
            continue;
        if (D_005721C8) {
            unsigned char has = 0;
            if (o->ctl && o->ctl->isTeamed())
                has = 1;
            if (has)
                k = ((o->flags & 0x7F000000) >> 24) - 1;
            else
                k = -1;
        } else {
            k = 0;
        }
        if (key == k) {
            func_002C9270(a, o, key, c);
            return;
        }
    }
}
#undef func_002C9270 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C9170(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C9170 */

/* merge_units: begin func_002C9270 */
#pragma push /* merge_units */
#pragma opt_propagation off
extern void* func_00185C70(int id);
extern char* AgentData_GetName(void* p);
extern char* Game_GetPlayerNameSlot(void* tbl, int id);
extern char D_004FFB50[];
extern char D_004ACF28[];

typedef struct {
    char pad[0xB70];
    unsigned char active;
} Ent9270;

static inline void Append(char* buf, const char* s)
{
    char* d;
    const char* p;
    int n;
    n = buf[0];
    d = buf + n + 1;
    p = s;
    if (n < 0x7E) {
        while ((*d++ = *p++) != 0) {
            if (++n >= 0x7E) {
                n++;
                d[0] = '\n';
                d[1] = 0;
                break;
            }
        }
    }
    buf[0] = n;
}


void func_002C9270(char* buf, int id, int nameId, int newline)
{
    char tmp[0x70];
    char c;
    if (func_00185C70(id) && ((Ent9270*)func_00185C70(id))->active) {
        Append(buf, AgentData_GetName(func_00185C70(id)));
    }
    c = newline ? '\n' : ' ';
    sprintf(tmp, D_004ACF28, (char)c, 0x11, Game_GetPlayerNameSlot(D_004FFB50, nameId), 0x10);
    Append(buf, tmp);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C9270(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C9270 */
