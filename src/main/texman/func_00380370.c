#include "types.h"

/* Read a TDX resource from a stream and relocate it. */
int func_0036DE50(void* stream);
void func_0036D990(void* stream, int* out, int size);
void func_0036DEC0(void* stream);
int Tdx_Relocate(void* tdx, int data, void* arg);

int Tdx_Read(void* tdx, void* stream, void* arg)
{
    int data = 0;
    func_0036D990(stream, &data, func_0036DE50(stream));
    func_0036DEC0(stream);
    if (data == 0)
        return 0;
    else {
        int r = Tdx_Relocate(tdx, data, arg);
        return r;
    }
}