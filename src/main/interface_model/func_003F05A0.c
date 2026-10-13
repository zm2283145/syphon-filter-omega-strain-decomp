#include "types.h"
#include "sso_string.h"
typedef struct { char pad[0x9C]; } FileMan05A0;
typedef struct { signed char len; char text[0x80]; } PStr05A0;
typedef struct Obj05A0 {
    char pad0[0xC];
    SsoString name;
    int f18;
    char pad1C[0x6E - 0x1C];
    unsigned short count;
    char pad70[0x84 - 0x70];
    struct Obj05A0** kids;
} Obj05A0;
extern int D_00539248;
extern char D_004BE048[];
extern void func_0036E5D0(FileMan05A0* f);
extern void func_0036DFB0(FileMan05A0* f, char* name, int a);
extern void func_0036E220(FileMan05A0* f, int flag);
extern int func_00380A40(int mgr, FileMan05A0* f);

static inline void Copy(PStr05A0* buf, char* t, const char* s)
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

static inline int Len05A0(SsoString* s) { return SSO_IS_LONG(s) ? s->longLen : (unsigned char)s->h.s.len; }

void func_003F05A0(Obj05A0* o, int arg1)
{
    PStr05A0 s;
    FileMan05A0 fm;
    int i;

    if (Len05A0(&o->name) > 0) {
        Copy(&s, s.text, String_CStr(&o->name));
        Append((char*)&s, D_004BE048);
        func_0036E5D0(&fm);
        func_0036DFB0(&fm, (char*)&s + 1, arg1);
        o->f18 = func_00380A40(D_00539248, &fm);
        func_0036E220(&fm, -1);
    }
    for (i = 0; i < o->count; i++) {
        func_003F05A0(o->kids[i], arg1);
    }
}


