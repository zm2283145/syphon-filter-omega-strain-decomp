#include "types.h"
typedef struct {
    char p0[0x1B38]; int f1B38; char p1B3C[0x1B80 - 0x1B3C]; int f1B80;
    char p1B84[0x1BE8 - 0x1B84]; char f1BE8[0x40];
    int f1C28; int f1C2C; char p1C30[0x1EB4 - 0x1C30]; int f1EB4; char f1EB8[0x40];
} S451BE0;
extern int D_00497770;
extern char D_004C0FA0[];
extern char D_004C0FA8[];
extern void String_Copy(char*, char*);
extern char* strrchr(const char*, int);
extern int sprintf(char*, const char*, ...);
extern int func_00451D70(S451BE0*, int);
extern int func_00451ED0(S451BE0*, char*);
extern int func_004524C0(S451BE0*, char*, char*);
extern int func_00452050(S451BE0*, int, int);

int func_00451BE0(S451BE0* s, int id)
{
    char buf[0x40];
    int i;
    char* p;

    for (i = 1; i < D_00497770; ) {
        if (!func_00451D70(s, id))
            return 0;
        if (s->f1C2C - s->f1C28 > 0) {
            if (!func_00452050(s, id, 0))
                return 0;
            s->f1EB4 = id;
            String_Copy(s->f1EB8, s->f1BE8);
            return 1;
        }
        String_Copy(buf, s->f1BE8);
        p = strrchr(buf, '_');
        if (!p)
            return 0;
        sprintf(p, D_004C0FA0, i++);
        if (!func_00451ED0(s, buf)) {
            if (!func_004524C0(s, buf, D_004C0FA8))
                return 0;
            if (!func_00452050(s, s->f1B38, 0))
                return 0;
            s->f1EB4 = s->f1B38;
            String_Copy(s->f1EB8, buf);
            return 1;
        }
        id = s->f1B80;
    }
    return 0;
}
