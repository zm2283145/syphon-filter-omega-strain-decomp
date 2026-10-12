#include "types.h"

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
extern void String_PushBack(Str40FBC0* s, int c);
extern char* func_002071A0(Str40FBC0* s);
extern void func_001F12D0(Str40FBC0* s, char* cs);
extern int func_0040FE50(Str40FBC0* s, Str40FBC0* key);
extern void func_00138350(Str40FBC0* s, int flags);
extern void func_00138B70(Str40FBC0* s, int flags);
extern int func_00412C40(Str40FBC0* s);
extern void func_00410630(Subs40FBC0* self, Str40FBC0* s);
extern void func_0040FF20(Subs40FBC0* self, Str40FBC0* s);

void func_0040FBC0(Subs40FBC0* self, const char* s, const char* end)
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
                String_PushBack(&line, c);
            }
        }
        if (p < end && *p == '\n') p++;
        if (*func_002071A0(&line) != 0 && *func_002071A0(&line) != '#') {
            if (*func_002071A0(&line) == '%') {
                int r;
                Str40FBC0 k1;
                Str40FBC0 k2;
                Str40FBC0 k3;
                func_001F12D0(&k1, D_004BEF08);
                r = func_0040FE50(&line, &k1);
                func_00138350(&k1, -1);
                if (r) {
                    self->mode = 0;
                } else {
                    func_001F12D0(&k2, D_004BEF00);
                    r = func_0040FE50(&line, &k2);
                    func_00138350(&k2, -1);
                    if (r) {
                        self->mode = 1;
                    } else {
                        func_001F12D0(&k3, D_004BEEF8);
                        r = func_0040FE50(&line, &k3);
                        func_00138350(&k3, -1);
                        if (r) self->mode = 2;
                    }
                }
                switch (self->mode) {
                case 2:
                    { int r2 = func_00412C40(&line); if (r2 != self->lang) self->mode = 0; }
                    break;
                }
            } else {
                switch (self->mode) {
                case 1:
                    func_00410630(self, &line);
                    break;
                case 2:
                    func_0040FF20(self, &line);
                    break;
                }
            }
        }
        func_00138B70(&line, 0);
    }
    self->f64 = self->f68;
}

