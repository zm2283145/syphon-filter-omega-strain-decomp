/*
 * lib/medius: 2 files, 002F96B8-002F96F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F96B8 */
#include "types.h"

extern int RSA_GenerateKeyPair(int, int);
extern int InitializePRNG(void);

int KM_GenerateRSAKeyPair(int a0, int a1) {
    InitializePRNG();
    return RSA_GenerateKeyPair(a0, a1);
}
/* merge_units: end func_002F96B8 */

/* merge_units: begin func_002F96F0 */
extern int RSA_GenerateKeyPair2(int, int);

int KM_GenerateRSAKeyPairEZ(int a0, int a1) {
    InitializePRNG();
    return RSA_GenerateKeyPair2(a0, a1);
}
/* merge_units: end func_002F96F0 */
