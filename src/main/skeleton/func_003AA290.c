#include "types.h"

/* Temporary file/stream object used while loading. */
typedef struct LoadStream {
    char data[0xA0];
} LoadStream;

extern void func_0036E5D0(LoadStream* s);
extern void Hog_Register(LoadStream* s, int name, int flags, int mode);
extern void Skel_ReadFile(int skel, int arg, int name, LoadStream* s);
extern void func_0036E220(LoadStream* s, int flags);

/* Loads a skeleton through a temporary stream opened on `name`; returns 0. */
int Skel_Load(int skel, int arg, int name, int flags) {
    LoadStream stream;
    func_0036E5D0(&stream);
    Hog_Register(&stream, name, flags, 0);
    Skel_ReadFile(skel, arg, name, &stream);
    func_0036E220(&stream, -1);
    return 0;
}
