/*
 * SFOGame/Source/GuiMissionStatistics: 1 file, 00350050
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00350050 */
#pragma push /* merge_units */
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
char* std_basic_string_char_char_traits_char_c_str(Str* s);
void GuiTextArrayWidget_SetText(Tbl* t, int col, int row, char* s);
void Libc_Strcpy(char* d, char* s);
int sprintf(char* buf, const char* fmt, ...);
void GuiMissionStatList_StatsUpdated(Tbl* self);
}

#pragma opt_strength_reduction off
void GuiMissionStatList_StatsUpdated(Tbl* self)
{
    char buf[128];
    unsigned int i;
    if (!self->list || !self->list->count) return;
    self->SetRows(0xB, self->list->count);
    for (i = 0; i < self->rows; i++) {
        Item* it = &self->list->data[i];
        int v;
        GuiTextArrayWidget_SetText(self, 0, i, std_basic_string_char_char_traits_char_c_str(&it->name));
        v = it->r[0].b;
        if (v == -1) Libc_Strcpy(buf, D_00492BC8);
        else sprintf(buf, D_004BAB40, v / 60, v % 60);
        GuiTextArrayWidget_SetText(self, 1, i, buf);
        v = it->r[0].a;
        if (v == -1) Libc_Strcpy(buf, D_00492BC8);
        else sprintf(buf, D_004BAB40, v / 60, v % 60);
        GuiTextArrayWidget_SetText(self, 2, i, buf);
        v = it->r[1].b;
        if (v == -1) Libc_Strcpy(buf, D_00492BC8);
        else sprintf(buf, D_004BAB40, v / 60, v % 60);
        GuiTextArrayWidget_SetText(self, 4, i, buf);
        v = it->r[1].a;
        if (v == -1) Libc_Strcpy(buf, D_00492BC8);
        else sprintf(buf, D_004BAB40, v / 60, v % 60);
        GuiTextArrayWidget_SetText(self, 5, i, buf);
        if (it->r[2].a == -1) Libc_Strcpy(buf, D_00492BC8);
        else sprintf(buf, "%d", it->r[2].a);
        GuiTextArrayWidget_SetText(self, 7, i, buf);
        {
            int a = it->r[3].a;
            int b = it->r[3].b;
            if (a == -1) Libc_Strcpy(buf, D_00492BC8);
            else sprintf(buf, "%d/%d", a, b);
        }
        GuiTextArrayWidget_SetText(self, 9, i, buf);
        if (it->r[4].a == -1) Libc_Strcpy(buf, D_00492BC8);
        else sprintf(buf, "%d", it->r[4].a);
        GuiTextArrayWidget_SetText(self, 0xA, i, buf);
    }
}
static inline void merge_flush_func_00350050(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00350050 */
