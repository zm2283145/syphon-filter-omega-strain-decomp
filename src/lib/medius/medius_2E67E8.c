#include "types.h"

extern int SendGroupedFieldUpdate(int, int, int);

int NetISendFieldUpdates(int a0) {
    return SendGroupedFieldUpdate(a0, 0, 0);
}
