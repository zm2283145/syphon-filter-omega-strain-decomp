#include "types.h"

extern int GetPlayerCountInSet(int);

int GridGetPlayerCount(int a0) {
    return GetPlayerCountInSet((a0 + 80));
}
