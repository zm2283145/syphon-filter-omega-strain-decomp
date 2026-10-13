#include "types.h"

extern int RSA_GenerateKeyPair(int, int);
extern int func_002F7F60(void);

int func_002F96B8(int a0, int a1) {
    func_002F7F60();
    return RSA_GenerateKeyPair(a0, a1);
}
