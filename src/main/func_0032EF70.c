#include "types.h"

typedef struct DossierArgs {
    int agent;
    int dossier;
} DossierArgs;

extern void Global_cAgentData__RegisterDossier(int agent, int dossier);

/* Script native: cAgentData._RegisterDossier(agent, dossier). */
int Script_cAgentData__RegisterDossier(DossierArgs* args) {
    volatile int dossier = args->dossier;
    volatile int agent = args->agent;
    Global_cAgentData__RegisterDossier(agent, dossier);
    return 0;
}
