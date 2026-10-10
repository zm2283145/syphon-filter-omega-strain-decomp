#include "types.h"

typedef struct State44 {
    char pad000[0x44];
    unsigned char state; /* 0x44 */
    char pad045[0x133];
    unsigned char ready; /* 0x178 */
} State44;

/* Advances state 3 to 4 once the ready flag is set. */
void func_001C9400(void* unused, State44* obj) {
    if (obj->state == 3 && obj->ready) {
        obj->state = 4;
    }
}
