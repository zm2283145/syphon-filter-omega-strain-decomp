#include "types.h"

typedef struct Ctx585E60 {
    char pad000[0x200];
    int failed; /* 0x200 */
} Ctx585E60;

extern Ctx585E60* D_00585E60;
extern int func_004505C0(int a, int b, int c, int d);
extern void memcpy(void* dst, int src, int len);

/* Runs func_004505C0; on failure sets the error flag and copies the message. */
void func_00446F30(int a, int b, int c, int msg) {
    if (!func_004505C0(a, b, c, msg)) {
        D_00585E60->failed = 1;
        memcpy((char*)D_00585E60 + 0x1BCC, msg, 100);
    }
}
