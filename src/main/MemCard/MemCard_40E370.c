/*
 * main/MemCard: range (2 files, 0040E370-0040E4C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int strlen(const char *);

/* merge_units: begin func_0040E370 */
#pragma push /* merge_units */
int String_ToLower(int c);
#define strlen(a0) ((unsigned int)strlen((a0))) /* merge_units */
int MemCardWrap_MatchName(char* pat, char* str)
{
    char* p;
    char* q;
    p = pat;
    q = str;
    while (*p != 0 && *q != 0 && *p != '*') {
        if (*p != '?') {
            if (String_ToLower(*p) != String_ToLower(*q))
                return 0;
        }
        p++;
        q++;
    }
    p = pat + strlen(pat) - 1;
    q = str + strlen(str) - 1;
    while (p >= pat && q >= str && *p != '*') {
        if (*p != '?') {
            if (String_ToLower(*p) != String_ToLower(*q))
                return 0;
        }
        p--;
        q--;
    }
    return 1;
}
#undef strlen /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040E370(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040E370 */

/* merge_units: begin func_0040E4C0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Card40E4C0 { char pad[0x5A0]; unsigned char done; };
struct Ctx40E4C0 { Card40E4C0* card; bool busy; char pad[3]; void (*cb)(void); unsigned char cancel; };
extern "C" {
extern char D_004BED38[];
void* Mem_Alloc(int pool, int size, char* file, int line);
Card40E4C0* MemCard_SetupIconSys(void* p);
int MemCard_MemCardMain(Card40E4C0* c);
void cMemCard_Init(Ctx40E4C0* c);
}
static inline void* new40E4C0(void) {
    AllocGuard guard;
    return Mem_Alloc(0, 0x5C0, D_004BED38, 0x2F9);
}
void cMemCard_Init(Ctx40E4C0* c)
{
    Card40E4C0* m = (Card40E4C0*)new40E4C0();
    if (m)
        m = MemCard_SetupIconSys(m);
    c->card = m;
    bool idle;
    do {
        c->busy = MemCard_MemCardMain(c->card) != 0;
        if (!c->busy)
            c->cancel = 0;
        if (c->cb)
            c->cb();
        idle = !c->busy;
    } while (!idle || !c->card->done);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040E4C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040E4C0 */
