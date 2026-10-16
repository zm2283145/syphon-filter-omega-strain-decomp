/*
 * main/particle: range (2 files, 003A5550-003A5630)
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
#include "SFOLobby_helpers.h"
int strlen(const char *);
char *strncpy(void *, const void *, int);

/* merge_units: begin func_003A5550 */
#pragma push /* merge_units */
/* Lower-cased base name (no directory, no extension, max 16 chars) of a path. */
extern char* strchr(const char* s, int c);
extern char* strrchr(const char* s, int c);
extern int String_ToLower(int c);
#define strlen(a0) ((unsigned int)strlen((a0))) /* merge_units */

static inline unsigned int Min_3A5550(unsigned int a, unsigned int b) { return a < b ? a : b; }

void ParticleLib_NormalizeName(char* out, const char* path, unsigned int n)
{
    char* p;
    char buf[0x80];
    unsigned int i;
    char* name;
    if (n == 0) {
        String_Copy(buf, path);
    } else {
        strncpy(buf, path, n);
        buf[n] = 0;
    }
    p = strchr(buf, '.');
    if (p)
        *p = 0;
    name = strrchr(buf, '\\');
    if (!name)
        name = buf;
    else
        name++;
    for (i = 0; i < Min_3A5550(strlen(name) + 1, 16); i++)
        *out++ = String_ToLower(name[i]);
}
#undef strlen /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A5550(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A5550 */

/* merge_units: begin func_003A5630 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_propagation off

extern "C" {
void* Mem_Alloc(int, int, char*, int);
void* Ptr_Identity(void*);
int strtod(char*, char**);
float SoftFloat_DoubleToFloat(int);
#if 0 /* merge_units */
char* strchr(const char*, int);
#endif /* merge_units */
#define strchr(a0, a1) (strchr((a0), (a1))) /* merge_units */

int strtoul(char*, char**, int);
void ParticleDef_ParseType1(void*);
void ParticleDef_ParseCommon(void*, float, char*, int);
extern char D_004BC5D0[];
extern char D_004DFB90[];
extern char D_004DFB70[];
}

struct Elem3A5630 {
    int d[4];
};

struct Obj3A5630 {
    void* vt;
    unsigned char type;
    char pad5[0x900 - 5];
    Elem3A5630 e[1];
};

inline void* Alloc3A5630(int size, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, D_004BC5D0, line);
}

inline Obj3A5630* Ctor3A5630(Obj3A5630* r, char* vt, int end)
{
    if (r) {
        Elem3A5630* e;
        ParticleDef_ParseType1(r);
        r->vt = vt;
        e = r->e;
        do {
            Ptr_Identity(e);
            e++;
        } while (e != (Elem3A5630*)((char*)r + end));
    }
    return r;
}

extern "C" Obj3A5630* ParticleDef_Parse(void* self, char* str, int arg, Obj3A5630* obj)
{
    char* s = str;
    Obj3A5630* r = 0;
    float ver;
    unsigned char type;

    ver = SoftFloat_DoubleToFloat(strtod(s, &s));
    if (ver <= 2.1f) {
        s = strchr(s, '\n') + 1;
        type = strtoul(s, &s, 10);
        s = strchr(s, '\n') + 1;
        if (obj) {
            r = obj;
        } else if (type == 0) {
            r = Ctor3A5630((Obj3A5630*)Alloc3A5630(0x9D0, 0x1AB), D_004DFB90, 0x990);
        } else if (type == 1) {
            r = Ctor3A5630((Obj3A5630*)Alloc3A5630(0xA70, 0x1AF), D_004DFB70, 0xA20);
        }
        r->type = type;
        ParticleDef_ParseCommon(r, ver, s, arg);
    }
    return r;
}
#undef strchr /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A5630(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A5630 */
