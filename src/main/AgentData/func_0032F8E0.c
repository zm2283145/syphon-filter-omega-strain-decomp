/*
 * Matched functions (byte-identical with the retail executable).
 * cAgentData script natives (ratings, commendations, omega).
 */

#include "types.h"
#include "AgentData_types.h"

extern int D_00532AB8;
extern unsigned char cAgentData_HasCommendation(cAgentData* agent, int id);
extern unsigned char cAgentData_HasRating(cAgentData* agent, int id);
extern unsigned char cAgentData_HasSpecialRating(cAgentData* agent, int id);
extern int cAgentData_UpdateAchievement(cAgentData* agent, unsigned char* flag, int key, int unk);

int Script_cAgentData_HasSpecialRating(AgentScriptArg* args) {
    int id[1];
    id[0] = args[1].i;
    return cAgentData_HasSpecialRating(args[0].p, STACK_COPY(id));
}

int Script_cAgentData_HasCommendation(AgentScriptArg* args) {
    int id[1];
    id[0] = args[1].i;
    return cAgentData_HasCommendation(args[0].p, STACK_COPY(id));
}

int Script_cAgentData_HasRating(AgentScriptArg* args) {
    int id[1];
    id[0] = args[1].i;
    return cAgentData_HasRating(args[0].p, STACK_COPY(id));
}

/* Updates the omega flag through cAgentData_UpdateAchievement, then reports whether it is set. */
int Script_cAgentData_HasOmega(AgentScriptArg* args) {
    cAgentData* agent = args[0].p;
    unsigned char* omega = agent->omega;
    int has;
    cAgentData_UpdateAchievement(agent, omega, D_00532AB8, 0);
    has = omega ? *omega != 0 : 0;
    return has != 0;
}
