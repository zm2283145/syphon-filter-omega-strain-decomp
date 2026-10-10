#include "types.h"

/* EE kernel semaphore parameters (ee_sema_t). */
typedef struct SemaParam {
    int count;
    int maxCount;
    int initCount;
    int waitThreads;
    unsigned int attr;
    unsigned int option;
} SemaParam;

typedef struct Stream3F5 {
    int id;
    unsigned int addr;  /* low 28 bits of the address, mode 2 in the top nibble */
    int size;
    char pad[0xC];
    int sizeShifted;    /* size << 11 */
    char pad2[0x24];
    int sema;
    char pad3[4];
    long position;
    int user0;
    int user1;
} Stream3F5;

extern int CreateSema(SemaParam* param); /* CreateSema */
extern void func_003F54B0(Stream3F5* self);

/* Initializes a stream: address/size fields, a binary semaphore, then resets it. Returns 1. */
int func_003F5650(Stream3F5* self, int id, unsigned int addr, int size, int user0, int user1) {
    SemaParam param;
    self->id = id;
    self->addr = (addr & 0x0FFFFFFF) | 0x20000000;
    self->size = size;
    self->sizeShifted = size << 11;
    self->user0 = user0;
    self->user1 = user1;
    param.initCount = 1;
    param.maxCount = 1;
    self->sema = CreateSema(&param);
    func_003F54B0(self);
    self->position = 0;
    return 1;
}
