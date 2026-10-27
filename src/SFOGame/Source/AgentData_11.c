/*
 * SFOGame/Source/AgentData: 1 file, 0032EF70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032EF70 */
#pragma push /* merge_units */
#include "types.h"

typedef struct DossierArgs {
    int agent;
    int dossier;
} DossierArgs;

extern void cAgentData_RegisterDossier(int agent, int dossier);

/* Script native: cAgentData._RegisterDossier(agent, dossier). */
int Script_cAgentData__RegisterDossier(DossierArgs* args) {
    volatile int dossier = args->dossier;
    volatile int agent = args->agent;
    cAgentData_RegisterDossier(agent, dossier);
    return 0;
}
static inline void merge_flush_func_0032EF70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032EF70 */
