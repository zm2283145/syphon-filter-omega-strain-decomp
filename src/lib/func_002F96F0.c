#include "types.h"

extern int RSA_GenerateKeyPair2(int, int);
extern int func_002F7F60(void);

int func_002F96F0(int a0, int a1) {
    func_002F7F60();
    return RSA_GenerateKeyPair2(a0, a1);
}
