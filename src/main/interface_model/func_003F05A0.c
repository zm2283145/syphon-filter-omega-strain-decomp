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
extern int g_TextureMgr;
extern char D_004BE048[];
extern void cFileMan_ctor_void(FileMan05A0* f);
extern void cFileMan_EncodeFilename_charP_cFileManR(FileMan05A0* f, char* name, int a);
extern void cFileMan_dtor(FileMan05A0* f, int flag);
extern int cTexMan_AddTextureFromFile_cFileManR(int mgr, FileMan05A0* f);

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

void cInterfaceModel_Refresh(Obj05A0* o, int arg1)
{
    PStr05A0 s;
    FileMan05A0 fm;
    int i;

    if (Len05A0(&o->name) > 0) {
        Copy(&s, s.text, std_basic_string_char_char_traits_char_c_str(&o->name));
        Append((char*)&s, D_004BE048);
        cFileMan_ctor_void(&fm);
        cFileMan_EncodeFilename_charP_cFileManR(&fm, (char*)&s + 1, arg1);
        o->f18 = cTexMan_AddTextureFromFile_cFileManR(g_TextureMgr, &fm);
        cFileMan_dtor(&fm, -1);
    }
    for (i = 0; i < o->count; i++) {
        cInterfaceModel_Refresh(o->kids[i], arg1);
    }
}


