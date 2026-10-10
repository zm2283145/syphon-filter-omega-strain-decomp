#include "types.h"

typedef struct LosProvider {
    char pad[0x14];
    unsigned int exclusionCount;
    int exclusions[2];
} LosProvider;

/* Adds a non-null object to the (max 2) LOS exclusion list. */
void LosProvider_AddExclusion(LosProvider* los, int obj) {
    if (obj && los->exclusionCount < 2) {
        los->exclusions[los->exclusionCount] = obj;
        los->exclusionCount++;
    }
}
