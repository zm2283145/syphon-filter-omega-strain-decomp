#include "types.h"

typedef struct FileInfo {
    unsigned char ok;
    char pad[3];
    int open;
    int size;
    int buffer;
    int handle;
    char file[4];
} FileInfo;

extern void func_0036DFB0(void* file, char* name, char* src);
extern int func_0036DEF0(void* file);
extern int func_0036DE50(void* file);
extern int func_001143F0(int size);
extern int func_0036DDC0(void* file);

/* Opens the file named at src+4 and caches its size/buffer/handle; returns success. */
unsigned char func_003F7950(FileInfo* self, char* src) {
    func_0036DFB0(self->file, src + 4, src);
    self->ok = (unsigned char)func_0036DEF0(self->file) == 0;
    if (self->ok) {
        self->size = func_0036DE50(self->file);
        self->open = 1;
        self->buffer = func_001143F0(0x40010);
        self->handle = func_0036DDC0(self->file);
    } else {
        self->open = 0;
        self->buffer = 0;
        self->size = 0;
        self->handle = 0;
    }
    return self->ok;
}
