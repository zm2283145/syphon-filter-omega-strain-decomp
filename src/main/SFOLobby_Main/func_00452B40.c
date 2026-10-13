#include "types.h"
typedef struct {
    char p0[0x1B38]; int f1B38; char p1B3C[0x1B80 - 0x1B3C]; int f1B80;
    char p1B84[0x1EB4 - 0x1B84]; int f1EB4; char f1EB8[0x40];
    char p1EF8[0x2564 - 0x1EF8];
    unsigned char err;
    char pad2565[3];
    char* errFile;
    int errLine;
} S452B40;
extern char D_004C0FA8[];
extern char D_004C0FB0[];
extern void String_Copy(char*, char*);
extern void func_00454010(void*);
extern int func_00451ED0(S452B40*, char*);
extern int func_004524C0(S452B40*, char*, char*);
extern int func_00452050(S452B40*, int, void*);
extern int func_00451BE0(S452B40*, int);

static inline void SetErr_452B40(S452B40* self, unsigned char code, char* file, int line)
{
    if (self->err != 5) {
        self->err = code;
        self->errFile = file;
        self->errLine = line;
    }
}

int func_00452B40(S452B40* s, char* name)
{
    char pass[0x100];
    char info[0x60];

    String_Copy(pass, D_004C0FA8);
    func_00454010(info);
    if (!func_00451ED0(s, name)) {
        if (!func_004524C0(s, name, pass)) {
            SetErr_452B40(s, 0x17, D_004C0FB0, 0x457);
            return 0;
        }
        if (!func_00452050(s, s->f1B38, info)) {
            SetErr_452B40(s, 0x16, D_004C0FB0, 0x45C);
            return 0;
        }
        s->f1EB4 = s->f1B38;
        String_Copy(s->f1EB8, name);
    } else if (!func_00451BE0(s, s->f1B80)) {
        return 0;
    }
    return 1;
}
