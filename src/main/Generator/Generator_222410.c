/*
 * main/Generator: range (4 files, 00222410-00222750)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00222410 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DB660[];
extern "C" char D_004DB600[];

struct Msg_00222410 : ClonedMessageBase {
    int a24;
    char b28;
};

#define CLONE_BODY(p, s) p->vtable = D_004DB660; p->a24 = s->a24; p->vtable = D_004DB600; p->b28 = s->b28;

extern "C" { char D_004A4C88[] = "generator.hh"; }
DEFINE_MESSAGE_CLONE(cGeneratorMessage_Clone, Msg_00222410, 44, D_004A4C88, 227, CLONE_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_00222410 */

/* merge_units: begin func_00222530 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" char D_004DB620[];

struct Msg_00222530 : ClonedMessageBase {
    int a24;
};

#undef CLONE_BODY /* merge_units */
#define CLONE_BODY(p, s) p->vtable = D_004DB660; p->a24 = s->a24; p->vtable = D_004DB620;

extern "C" { char D_004A4C98[] = "generator.hh"; }
DEFINE_MESSAGE_CLONE(cDespawnedNPCMsg_Clone, Msg_00222530, 40, D_004A4C98, 207, CLONE_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_00222530 */

/* merge_units: begin func_00222640 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" char D_004DB640[];

struct Msg_00222640 : ClonedMessageBase {
    int a24;
};

#undef CLONE_BODY /* merge_units */
#define CLONE_BODY(p, s) p->vtable = D_004DB660; p->a24 = s->a24; p->vtable = D_004DB640;

extern "C" { char D_004A4CA8[] = "generator.hh"; }
DEFINE_MESSAGE_CLONE(cSpawnedNPCMsg_Clone, Msg_00222640, 40, D_004A4CA8, 191, CLONE_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_00222640 */

/* merge_units: begin func_00222750 */
#pragma push /* merge_units */
#pragma cplusplus on


struct Msg_00222750 : ClonedMessageBase {
    int a24;
};

#undef CLONE_BODY /* merge_units */
#define CLONE_BODY(p, s) p->vtable = D_004DB660; p->a24 = s->a24;

extern "C" { char D_004A4CB8[] = "generator.hh"; }
DEFINE_MESSAGE_CLONE(cGeneratorMessageBase_Clone, Msg_00222750, 40, D_004A4CB8, 163, CLONE_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_00222750 */
