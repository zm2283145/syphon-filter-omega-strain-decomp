#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
typedef struct { int w; int len; char* data; } Str;
typedef struct { unsigned char ok; int a; int b; } Rng;
typedef struct {
    Str name;
    unsigned char on;
    Rng r[5];
    char pad[0x5C - 0x4C];
} Item;
struct IList { int f0; int count; Item* data; };
class Tbl {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void SetRows(int a, int n);
    char pad4[0x4C - 4];
    unsigned int rows;
    char pad50[0xC0 - 0x50];
    IList* list;
};
extern "C" {
extern char* D_00492BC8;
extern char D_004BAB40[];
extern char D_004BAB50[];
extern char D_004BAB58[];
char* func_001692D0(Str* s);
void func_00426510(Tbl* t, int col, int row, char* s);
void String_Copy(char* d, char* s);
int sprintf(char* buf, const char* fmt, ...);
void func_00350050(Tbl* self);
}

#pragma opt_strength_reduction off
void func_00350050(Tbl* self)
{
    char buf[128];
    unsigned int i;
    if (!self->list || !self->list->count) return;
    self->SetRows(0xB, self->list->count);
    for (i = 0; i < self->rows; i++) {
        Item* it = &self->list->data[i];
        int v;
        func_00426510(self, 0, i, func_001692D0(&it->name));
        v = it->r[0].b;
        if (v == -1) String_Copy(buf, D_00492BC8);
        else sprintf(buf, D_004BAB40, v / 60, v % 60);
        func_00426510(self, 1, i, buf);
        v = it->r[0].a;
        if (v == -1) String_Copy(buf, D_00492BC8);
        else sprintf(buf, D_004BAB40, v / 60, v % 60);
        func_00426510(self, 2, i, buf);
        v = it->r[1].b;
        if (v == -1) String_Copy(buf, D_00492BC8);
        else sprintf(buf, D_004BAB40, v / 60, v % 60);
        func_00426510(self, 4, i, buf);
        v = it->r[1].a;
        if (v == -1) String_Copy(buf, D_00492BC8);
        else sprintf(buf, D_004BAB40, v / 60, v % 60);
        func_00426510(self, 5, i, buf);
        if (it->r[2].a == -1) String_Copy(buf, D_00492BC8);
        else sprintf(buf, D_004BAB50, it->r[2].a);
        func_00426510(self, 7, i, buf);
        {
            int a = it->r[3].a;
            int b = it->r[3].b;
            if (a == -1) String_Copy(buf, D_00492BC8);
            else sprintf(buf, D_004BAB58, a, b);
        }
        func_00426510(self, 9, i, buf);
        if (it->r[4].a == -1) String_Copy(buf, D_00492BC8);
        else sprintf(buf, D_004BAB50, it->r[4].a);
        func_00426510(self, 0xA, i, buf);
    }
}



