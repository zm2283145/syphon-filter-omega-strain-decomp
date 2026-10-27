#include "types.h"
extern char* g_LosRequestMsgClass;
extern char* g_LosResultMsgClass;
void StaticInit_los(void) {
    g_LosRequestMsgClass = "LOS Request";
    g_LosResultMsgClass = "LOS Result Ready";
}