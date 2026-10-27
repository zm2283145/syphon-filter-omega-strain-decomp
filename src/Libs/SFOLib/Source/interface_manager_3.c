/*
 * Libs/SFOLib/Source/interface_manager: 2 files, 00412F80-00413370
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00412F80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"

struct Str { int a; int b; int c; };
static inline Str* Init(Str* s) { s->a = 0; s->b = 0; s->c = 0; return s; }
struct PStr { signed char len; char text[0x8F]; };
struct Ent {
    Str name;           /* 0x00 */
    void* data;         /* 0x0C */
    int ref;            /* 0x10 */
    void* arc;          /* 0x14 */
};
struct Self {
    Ent e[20];          /* 0x000 */
    void* files;        /* 0x1E0 */
    int pad1E4;
    int mode;           /* 0x1E8 */
};
struct Hog { char pad[0xA0]; };

extern "C" {
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char D_004BEF30[], D_004BEF48[];
void Alloc_Lock(int id);
void EnableIntc(int id);
void* cMemMan_Allocate(int heap, int size, const char* file, int line);
int std_basic_string_char_char_traits_char_compare_charP(Str* s, const char* t);
int cInterfaceManager_FindHogFile(Self* self, Str* path, const char* name, unsigned char* flag);
void String_Dtor(Str* s, int f);
char* std_basic_string_char_char_traits_char_c_str(Str* s);
void* cHogList_OpenFromHog(void* files, char* path, int mode);
void* cHogList_Open(void* files, char* path, int a, int b);
int sprintf(char* buf, const char* fmt, ...);
void cFileMan_ctor_void(Hog* h);
void cFileMan_EncodeFilename_charP_cHogFileR_bool(Hog* h, char* name, void* arc, int z);
void* cInterface_ctor(void* p, Hog* h);
void std_basic_string_char_char_traits_char_ctor_charP(Str* s, const char* t);
void std_basic_string_char_char_traits_char_assign_basicstringR(Str* d, Str* s);
void cFileMan_dtor(Hog* h, int flags);
int cInterfaceManager_AddInterface(Self* self, const char* name);
}

static inline void Copy(PStr* buf, char* t, const char* s)
{
    char* d;
    const char* p;
    int n;
    n = 0;
    d = t;
    p = s;
    while ((*d++ = *p++) != 0) {
        if (++n >= 0x7E) {
            n++;
            d[0] = '\n';
            d[1] = 0;
            break;
        }
    }
    buf->len = n;
}

static inline void Upper(PStr* buf, char* t)
{
    int n;
    char* p;
    for (n = buf->len, p = t; n > 0; n--, p++) {
        if (*p >= 'a' && *p <= 'z') *p -= 0x20;
    }
}

static inline void CopyUpper(PStr* buf, const char* s)
{
    char* t = buf->text;
    Copy(buf, t, s);
    Upper(buf, t);
}

static inline int Find(Self* self, const char* key)
{
    int i;
    Ent* e;
    i = 0;
    e = self->e;
    do {
        if (e->ref && std_basic_string_char_char_traits_char_compare_charP(&e->name, key) == 0) return i;
        i++;
        e++;
    } while (i < 20);
    return -1;
}

#pragma push
/* like cInterfaceManager_OpenHogFile (same unit family): keeps the &path zeroing through the argument register */
#pragma opt_propagation off
/* Finds (upper-cased name) or loads an interface into a free slot: opens the archive
 * (pak or plain), registers its .IE hog, creates the Interface and records it. */
extern "C" int cInterfaceManager_AddInterface(Self* self, const char* name)
{
    unsigned char flag;
    Str path;
    Str t;
    char buf[0x20];
    Hog hog;
    PStr up2;
    PStr up;
    int i;
    void* arc;
    void* p;
    { char* t = up.text; Copy(&up, t, name); Upper(&up, t); }
    i = Find(self, up.text);
    if (i != -1) {
        self->e[i].ref++;
        return i;
    }
    {
        int j;
        Ent* e;
        for (j = 0, e = self->e; i == -1 && j < 20; e++, j++) {
            if (!e->ref) i = j;
        }
    }
    if (i != -1 && self->files) {
        Str* ps = &path;
        ps->a = 0; ps->b = 0; ps->c = 0;
        if (!cInterfaceManager_FindHogFile(self, ps, name, &flag)) {
            String_Dtor(&path, 0);
            return -1;
        }
        if (flag) {
            arc = cHogList_OpenFromHog(self->files, std_basic_string_char_char_traits_char_c_str(&path), self->mode);
        } else {
            arc = cHogList_Open(self->files, std_basic_string_char_char_traits_char_c_str(&path), 0, 0);
            asm { .set reorder } /* barrier: keeps the then-arm's own move (retail does not merge the tails) */
        }
        sprintf(buf, D_004BEF48, name);
        cFileMan_ctor_void(&hog);
        cFileMan_EncodeFilename_charP_cHogFileR_bool(&hog, buf, arc, 0);
        if (g_ProfileLockEnabled) Alloc_Lock(9);
        g_ProfileLockDepth++;
        p = cMemMan_Allocate(0, 8, D_004BEF30, 0x133);
        if (g_ProfileLockEnabled) EnableIntc(9);
        g_ProfileLockDepth--;
        if (p) p = cInterface_ctor(p, &hog);
        { char* t = up2.text; Copy(&up2, t, name); Upper(&up2, t); }
        std_basic_string_char_char_traits_char_ctor_charP(&t, up2.text);
        std_basic_string_char_char_traits_char_assign_basicstringR(&self->e[i].name, &t);
        String_Dtor(&t, 0);
        self->e[i].data = p;
        self->e[i].ref = 1;
        self->e[i].arc = arc;
        cFileMan_dtor(&hog, -1);
        String_Dtor(&path, 0);
    }
    return i;
}
#pragma pop
static inline void merge_flush_func_00412F80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00412F80 */

/* merge_units: begin func_00413370 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * interface_manager.cc
 */

#include "interface_manager_types.h"

/* unk0C of slot `index`, or 0 when the index is out of range. */
int cInterfaceManager_GetInterface(IfManager* mgr, int index) {
    int inRange = index < IFMGR_SLOT_COUNT; /* computed before the sign test (matches) */

    if (index < 0 || !inRange) {
        return 0;
    }
    return mgr->slots[index].unk0C;
}
static inline void merge_flush_func_00413370(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00413370 */
