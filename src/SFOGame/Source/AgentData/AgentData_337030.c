/*
 * main/AgentData: range (2 files, 00337030-00337140)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "net_msg_clone.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vector_resize.h"
#pragma pop

/* merge_units: begin func_00337030 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Clone a network message. */
extern "C" {
char D_004B9988[] = "AgentData.cc";
}
DEFINE_NET_MSG_CLONE(cNetAddObjectiveMsg_Clone, 0x28, D_004B9988, 0x3C4, D_004DE810, NMC_W(0x24))
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00337030(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00337030 */

/* merge_units: begin func_00337140 */
#pragma push /* merge_units */
#pragma cplusplus on
DEFINE_RESIZE_ELEMENT(Elem4_2FF0, 2)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(std_vector_pod_eRequirementState_resize, Elem4_2FF0, std_vector_pod_eRequirementState_insert, std_vector_pod_eRequirementState_erase)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_00337140 */
