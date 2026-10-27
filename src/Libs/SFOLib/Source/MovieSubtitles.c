/*
 * Libs/SFOLib/Source/MovieSubtitles: 5 files, 0040F9F0-0040FBC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040F9F0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "guarded_release.h"

/* Free an allocation under the allocator guard. */
DEFINE_GUARDED_RELEASE(opDelete_nodeP_int_bool_charP_etc_11)
static inline void merge_flush_func_0040F9F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040F9F0 */

/* merge_units: begin func_0040FAA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" { extern char D_004BEDE8[]; 
#if 0 /* merge_units */
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
#endif /* merge_units */
#define cMemMan_Deallocate(a0, a1, a2, a3) ((void)cMemMan_Deallocate((a0), (a1), (a2), (a3))) /* merge_units */
}
extern "C" void cAllocator_node_deallocate_nodeP_uint_12(void* tree, void* node)
{
    if (node) {
        AllocGuard guard;
        cMemMan_Deallocate(0, node, D_004BEDE8, 0x64);
    }
}
#undef cMemMan_Deallocate /* merge_units */
static inline void merge_flush_func_0040FAA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040FAA0 */

/* merge_units: begin func_0040FB40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

extern void World_FreePendingTree(Tree* t, int root);

/* Address of the tree header (end()). */
int* func_0040FB40(Tree* t) {
    return &t->header;
}

void* func_0040FB50(void* self) {
    return self;
}

/* Erases every node of the tree and resets it to empty. */
void World_ClearPending(Tree* t) {
    if (t->header != 0) {
        World_FreePendingTree(t, t->header);
        t->unk0 = 0;
        t->header = 0;
        t->leftmost = &t->header;
    }
}

Map* MotionManager_Ctor(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
static inline void merge_flush_func_0040FB40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040FB40 */

/* merge_units: begin func_0040FBC0 */
#pragma push /* merge_units */
typedef struct { union { struct { unsigned int word; unsigned int length; char* data; } l; struct { unsigned char isLong : 1; unsigned char len : 7; } s; } u; } Str_40FE50;
char* func_0040FE50(void* a, Str_40FE50* s); /* gsynth: defined below */
typedef struct { int a; int b; int c; } Str40FBC0;
typedef struct {
    char pad00[0x40];
    unsigned char mode;  /* 0x40 */
    char pad41[3];
    int lang;            /* 0x44 */
    char pad48[0x1C];
    int f64;             /* 0x64 */
    int f68;             /* 0x68 */
} Subs40FBC0;

static char D_004BEEF8[] = "FEED";
static char D_004BEF00[] = "INIT";
static char D_004BEF08[] = "END";
extern void std_basic_string_char_char_traits_char_opAddAssign(Str40FBC0* s, int c);
extern char* cString_opCast_constcharPtr(Str40FBC0* s);
extern void cString_ctor_charP(Str40FBC0* s, char* cs);
#if 0 /* merge_units */
extern int func_0040FE50(Str40FBC0* s, Str40FBC0* key);
#endif /* merge_units */
#define func_0040FE50(a0, a1) ((int)func_0040FE50((void *)(a0), (Str_40FE50 *)(a1))) /* merge_units */


extern void String_Dtor_138350(Str40FBC0* s, int flags);
extern void String_Dtor(Str40FBC0* s, int flags);
extern int nSubtitles_GetLanguageId(Str40FBC0* s);
extern void cSubtitleFeed_ParseINISectionINIT(Subs40FBC0* self, Str40FBC0* s);
extern void cSubtitleFeed_ParseINISectionFEED(Subs40FBC0* self, Str40FBC0* s);

void cSubtitleFeed_ParseINI(Subs40FBC0* self, const char* s, const char* end)
{
    const char* p = s;
    while (p < end) {
        Str40FBC0 line;
        int c;
        int* q = (int*)&line;
        q[0] = 0;
        q[1] = 0;
        q[2] = 0;
        while (!(p < end) == 0 && (c = *p) != '\n') {
            if (c == '\r') {
                p++;
            } else {
                p++;
                std_basic_string_char_char_traits_char_opAddAssign(&line, c);
            }
        }
        if (p < end && *p == '\n') p++;
        if (*cString_opCast_constcharPtr(&line) != 0 && *cString_opCast_constcharPtr(&line) != '#') {
            if (*cString_opCast_constcharPtr(&line) == '%') {
                int r;
                Str40FBC0 k1;
                Str40FBC0 k2;
                Str40FBC0 k3;
                cString_ctor_charP(&k1, D_004BEF08);
                r = func_0040FE50(&line, &k1);
                String_Dtor_138350(&k1, -1);
                if (r) {
                    self->mode = 0;
                } else {
                    cString_ctor_charP(&k2, D_004BEF00);
                    r = func_0040FE50(&line, &k2);
                    String_Dtor_138350(&k2, -1);
                    if (r) {
                        self->mode = 1;
                    } else {
                        cString_ctor_charP(&k3, D_004BEEF8);
                        r = func_0040FE50(&line, &k3);
                        String_Dtor_138350(&k3, -1);
                        if (r) self->mode = 2;
                    }
                }
                switch (self->mode) {
                case 2:
                    { int r2 = nSubtitles_GetLanguageId(&line); if (r2 != self->lang) self->mode = 0; }
                    break;
                }
            } else {
                switch (self->mode) {
                case 1:
                    cSubtitleFeed_ParseINISectionINIT(self, &line);
                    break;
                case 2:
                    cSubtitleFeed_ParseINISectionFEED(self, &line);
                    break;
                }
            }
        }
        String_Dtor(&line, 0);
    }
    self->f64 = self->f68;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040FBC0(void) {}
#undef func_0040FE50 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040FBC0 */

/* merge_units: begin func_0040FE50 */
#pragma push /* merge_units */
extern int std_basic_string_char_char_traits_char_find_basicstringR_uint(void* a, Str_40FE50* s, int c);
extern char* std_basic_string_char_char_traits_char_c_str(void* a);
static inline unsigned int Len_40FE50(Str_40FE50* s) { return (s->u.l.word & 1) ? s->u.l.length : (unsigned char)s->u.s.len; }
#pragma opt_rotateloops off
char* func_0040FE50(void* a, Str_40FE50* s)
{
    char* p = 0;
    int r = std_basic_string_char_char_traits_char_find_basicstringR_uint(a, s, 0);
    if (r > -1) {
        p = std_basic_string_char_char_traits_char_c_str(a) + r + Len_40FE50(s);
        while (*p == ' ' || *p == '\t') p++;
    }
    return p;
}
#pragma opt_rotateloops reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040FE50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040FE50 */
