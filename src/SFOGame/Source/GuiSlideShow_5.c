/*
 * SFOGame/Source/GuiSlideShow: 2 files, 00327C70-00327CF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00327C70 */
#pragma push /* merge_units */
#include "types.h"

typedef struct String {
    int a, b, c;
} String;

typedef struct Obj84 {
    char pad[0x6C];
    String name;
    String desc;
    int value;
} Obj84;

extern void std_basic_string_char_char_traits_char_ctor_charP(String*, const char*);
extern void std_basic_string_char_char_traits_char_assign_basicstringR(String*, String*);
extern void String_Dtor(String*, int);

/* Sets two string fields and an int. */
void GuiSlideShow_SetInfo(Obj84* o, const char* name, const char* desc, int value) {
    String tmp2;
    String tmp1;
    std_basic_string_char_char_traits_char_ctor_charP(&tmp1, name);
    std_basic_string_char_char_traits_char_assign_basicstringR(&o->name, &tmp1);
    String_Dtor(&tmp1, 0);
    std_basic_string_char_char_traits_char_ctor_charP(&tmp2, desc);
    std_basic_string_char_char_traits_char_assign_basicstringR(&o->desc, &tmp2);
    String_Dtor(&tmp2, 0);
    o->value = value;
}
static inline void merge_flush_func_00327C70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00327C70 */

/* merge_units: begin func_00327CF0 */
#pragma push /* merge_units */
typedef struct { char data[0x9C]; } SubObj;
typedef struct {
    void* vtable;          /* +0x00 */
    char pad04[0x20 - 4];
    unsigned char flag;    /* +0x20 */
    char pad21[0x78 - 0x21];
    SubObj a;              /* +0x78 */
    SubObj b;              /* +0x114 */
    char pad1B0[0x1D0 - 0x1B0];
} Event; /* 0x1D0-byte stack object */
typedef struct {
    char pad[0x58];
    int state;             /* +0x58 */
    char pad5C[0x90 - 0x5C];
    char ev[0x44];         /* +0x90 */
    unsigned char active;  /* +0xD4 */
} Screen;
extern char g_Game[];
extern char D_004DADF0[];
extern void GuiWidget_onSleep(Screen* self);
extern void cStopSoundMsg_ctor_cSndFxR_bool(Event* e, void* src, int a2);
extern void QueueMessage_cMessageR_cSystemP_int(Event* e, const char* name, int enable);
extern void cFileMan_dtor(SubObj* s, int flags);
extern void cMessage_dtor(Event* e, int flags);
extern void* GetFileStreamMan(void);
extern void cFileStreamMan_Purge(void* p);
extern void cMemMan_ReleaseBin(int a0);

/* Closes the screen: base handler, dispatches a close event, then resets global state. */
void GuiSlideShow_onSleep(Screen* self)
{
    Event e;
    GuiWidget_onSleep(self);
    self->active = 0;
    cStopSoundMsg_ctor_cSndFxR_bool(&e, self->ev, 0);
    e.flag = 1;
    QueueMessage_cMessageR_cSystemP_int(&e, g_Game, 1);
    e.vtable = D_004DADF0;
    cFileMan_dtor(&e.b, -1);
    cFileMan_dtor(&e.a, -1);
    cMessage_dtor(&e, 0);
    cFileStreamMan_Purge(GetFileStreamMan());
    cMemMan_ReleaseBin(1);
    self->state = -1;
}
static inline void merge_flush_func_00327CF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00327CF0 */
