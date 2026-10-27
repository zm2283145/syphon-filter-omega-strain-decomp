/*
 * main/game: range (2 files, 001359D0-00135A60)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "message_two_member_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "two_member_dtor.h"
#pragma pop

/* merge_units: begin func_001359D0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Message destructor: payload members, then cMessage base. */
DEFINE_MESSAGE_TWO_MEMBER_DTOR(cPlaySoundMsg_dtor_void, D_004DAE30)
#pragma pop /* merge_units */
/* merge_units: end func_001359D0 */

/* merge_units: begin func_00135A60 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destructor: destroy two members, optionally delete. */
DEFINE_TWO_MEMBER_DTOR(cString_dtor, cFileMan_dtor, 0x48, 0xE4)
#pragma pop /* merge_units */
/* merge_units: end func_00135A60 */
