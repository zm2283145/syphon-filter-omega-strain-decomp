#include "types.h"
typedef struct SsoString {
    union {
        struct { unsigned char isLong : 1; unsigned char shortLen : 7; } s;
        int flags;
    } h;
    int longLen;
    char* longData;
} SsoString;
typedef struct { char pad[0x48]; SsoString text; char pad2[0x24]; void* view; char pad3[4]; unsigned char active; char pad4[0xB]; int mode; } TextBox;
extern void func_0041BE50(TextBox* t);
extern void func_0041AE90(void* view, int len);
extern void func_0041A100(TextBox* t, int mode);
/* Refreshes the text box, updating the view with the text length when active. */
void func_0041AA10(TextBox* t)
{
    func_0041BE50(t);
    if (t->active) {
        int len;
        if (!(t->text.h.flags & 1))
            len = (unsigned char)t->text.h.s.shortLen;
        else
            len = t->text.longLen;
        func_0041AE90(t->view, len);
    }
    func_0041A100(t, t->mode);
}
