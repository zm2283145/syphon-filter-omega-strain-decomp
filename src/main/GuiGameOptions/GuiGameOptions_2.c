/*
 * main/GuiGameOptions: 6 files, 0029BDA0-0029C0A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0029BDA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiGameOptions.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

int cGameSystem_GetPlayer(char* self) {
    return *(int*)(self + 188);
}
#pragma pop /* merge_units */
/* merge_units: end func_0029BDA0 */

/* merge_units: begin func_0029BDB0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cNetObj_GetPlayer(int);                             
extern unsigned char g_IsMultiplayer;

int NumClientConnections(void) {
    int var_s1;
    int var_s0;

    if (g_IsMultiplayer == 0) {
        return 1;
    }
    var_s1 = 0;
    var_s0 = 0;
    do {
        if (cNetObj_GetPlayer(var_s0) != 0) {
            var_s1 += 1;
        }
        var_s0 += 1;
    } while (var_s0 < 4);
    return var_s1;
}
#pragma pop /* merge_units */
/* merge_units: end func_0029BDB0 */

/* merge_units: begin func_0029BE20 */
#pragma push /* merge_units */
typedef struct { char pad[0x24]; int player; int reason; } cNetKickMsg;

extern unsigned char* D_005061D0; /* network write cursor */

static inline void write16(int v)
{
    short s = v;
    *D_005061D0++ = s;
    *D_005061D0++ = s >> 8;
}

static inline void write32(int v)
{
    write16((unsigned short)v);
    write16(v >> 16);
}

/* cNetKickMsg virtual 4: writes the player and reason as 32-bit little-endian values. */
void cNetKickMsg_Pack(cNetKickMsg* self)
{
    write32(self->player);
    write32(self->reason);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0029BE20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0029BE20 */

/* merge_units: begin func_0029BF70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiGameOptions.cc. Functions are named by address
 * until real names are known.
 */


extern int D_00506448;

int cNetKickMsg_GetMsgId(void) {
    return D_00506448;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0029BF70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0029BF70 */

/* merge_units: begin func_0029BF80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "net_msg_clone.h"

/* Clone a network message. */
extern "C" { char D_004AA980[] = "GuiGameOptions.cc"; }
DEFINE_NET_MSG_CLONE(cNetKickMsg_Clone, 0x2C, D_004AA980, 0x8E, D_004DD5E0,
                     NMC_W(0x24); NMC_W(0x28))
#pragma pop /* merge_units */
/* merge_units: end func_0029BF80 */

/* merge_units: begin func_0029C0A0 */
#pragma push /* merge_units */
typedef struct String {
    int a, b, c;
} String;

/* Empty tag object passed by value (an allocator in the original C++). */
typedef struct Tag {
    signed char unused;
} Tag;

extern int strlen(const char*);
extern void std_basic_string_char_char_traits_char_reserve(String*, int);
extern void std_basic_string_char_char_traits_char_do_replace(String*, int, int, const char*, const char*, Tag);

/* Constructs a string from a C string. */
String* func_0029C0A0(String* self, const char* text) {
    Tag tag;
    int len;
    self->a = 0;
    self->b = 0;
    self->c = 0;
    len = strlen(text);
    std_basic_string_char_char_traits_char_reserve(self, len);
    std_basic_string_char_char_traits_char_do_replace(self, 0, 0, text, text + len, tag);
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0029C0A0 */
