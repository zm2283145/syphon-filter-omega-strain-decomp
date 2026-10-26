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
void Alloc_Unlock(int id);
void* Mem_Alloc(int heap, int size, const char* file, int line);
int String_AssignCStr_1C43A0(Str* s, const char* t);
int func_004134B0(Self* self, Str* path, const char* name, unsigned char* flag);
void String_Dtor(Str* s, int f);
char* String_CStr(Str* s);
void* func_003F9850(void* files, char* path, int mode);
void* Archive_Open(void* files, char* path, int a, int b);
int sprintf(char* buf, const char* fmt, ...);
void Resource_Construct(Hog* h);
void Hog_Register(Hog* h, char* name, void* arc, int z);
void* Interface_Ctor(void* p, Hog* h);
void String_CtorCStr_13B480(Str* s, const char* t);
void String_AssignString(Str* d, Str* s);
void FileMan_Release(Hog* h, int flags);
int GuiManager_FindInterface(Self* self, const char* name);
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
        if (e->ref && String_AssignCStr_1C43A0(&e->name, key) == 0) return i;
        i++;
        e++;
    } while (i < 20);
    return -1;
}

#pragma push
/* like GuiResource_Find (same unit family): keeps the &path zeroing through the argument register */
#pragma opt_propagation off
/* Finds (upper-cased name) or loads an interface into a free slot: opens the archive
 * (pak or plain), registers its .IE hog, creates the Interface and records it. */
extern "C" int GuiManager_FindInterface(Self* self, const char* name)
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
        if (!func_004134B0(self, ps, name, &flag)) {
            String_Dtor(&path, 0);
            return -1;
        }
        if (flag) {
            arc = func_003F9850(self->files, String_CStr(&path), self->mode);
        } else {
            arc = Archive_Open(self->files, String_CStr(&path), 0, 0);
            asm { .set reorder } /* barrier: keeps the then-arm's own move (retail does not merge the tails) */
        }
        sprintf(buf, D_004BEF48, name);
        Resource_Construct(&hog);
        Hog_Register(&hog, buf, arc, 0);
        if (g_ProfileLockEnabled) Alloc_Lock(9);
        g_ProfileLockDepth++;
        p = Mem_Alloc(0, 8, D_004BEF30, 0x133);
        if (g_ProfileLockEnabled) Alloc_Unlock(9);
        g_ProfileLockDepth--;
        if (p) p = Interface_Ctor(p, &hog);
        { char* t = up2.text; Copy(&up2, t, name); Upper(&up2, t); }
        String_CtorCStr_13B480(&t, up2.text);
        String_AssignString(&self->e[i].name, &t);
        String_Dtor(&t, 0);
        self->e[i].data = p;
        self->e[i].ref = 1;
        self->e[i].arc = arc;
        FileMan_Release(&hog, -1);
        String_Dtor(&path, 0);
    }
    return i;
}
#pragma pop
