/*
 * Libs/SFOLib/Source/interface_manager: 1 file, 00412ED0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00412ED0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char data[0xA0]; } TextObj;
typedef struct { char pad[0xC]; void* target; void* enabled; int color; } Label412; /* 0x18 bytes */

extern void* std_basic_string_char_char_traits_char_c_str(Label412* label);
extern int sprintf(char* buf, const char* fmt, ...);
extern void cFileMan_ctor_void(TextObj* obj);
extern void cFileMan_EncodeFilename_charP_cHogFileR_bool(TextObj* obj, char* text, int color, int flags);
extern void cInterface_Refresh(void* target, TextObj* obj);
extern void cFileMan_dtor(TextObj* obj, int flags);

/* Builds and attaches a text object for each of the 20 active labels. */
void cInterfaceManager_Refresh(Label412* self)
{
    Label412* p;
    int i;
    i = 0;
    p = self;
    for (; i < 20; i++, p++) {
        if (p->enabled && p->target) {
            TextObj obj;
            char buf[0x20];
            sprintf(buf, "%s.IE", std_basic_string_char_char_traits_char_c_str(p));
            cFileMan_ctor_void(&obj);
            cFileMan_EncodeFilename_charP_cHogFileR_bool(&obj, buf, p->color, 0);
            cInterface_Refresh(p->target, &obj);
            cFileMan_dtor(&obj, -1);
        }
    }
}
static inline void merge_flush_func_00412ED0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00412ED0 */
