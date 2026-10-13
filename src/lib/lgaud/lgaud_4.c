/*
 * lib/lgaud: 4 files, 00325960-00325BB8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00325960 */
extern int D_0049147C;
extern int* D_00491474;
extern char D_0052AD00[];
extern int func_0010D1A0(int sema);
extern int func_0010D180(int sema);
extern int func_00110528(void* cd, int rpc, int mode, void* send, int ssize, void* recv, int rsize, void* end, void* param);
extern int func_00127358(const char* fmt, ...);

int func_00325960(int device)
{
    int* buf;
    if (D_0049147C == -1)
        return 0x8000000A;
    func_0010D1A0(D_0049147C);
    buf = D_00491474;
    buf[3] = device;
    if (func_00110528(D_0052AD00, 4, 0, buf, 0x20, buf, 0x20, 0, 0) == 0) {
        device = *D_00491474;
        func_0010D180(D_0049147C);
        return device;
    }
    func_00127358("lgAudStartRecording: rpc call failed
");
    func_0010D180(D_0049147C);
    return 0x80000000;
}
/* merge_units: end func_00325960 */

/* merge_units: begin func_00325A28 */
extern char D_004B82C8[];

int func_00325A28(int device)
{
    int* buf;
    if (D_0049147C == -1)
        return 0x8000000A;
    func_0010D1A0(D_0049147C);
    buf = D_00491474;
    buf[3] = device;
    if (func_00110528(D_0052AD00, 5, 0, buf, 0x20, buf, 0x20, 0, 0) == 0) {
        device = *D_00491474;
        func_0010D180(D_0049147C);
        return device;
    }
    func_00127358(D_004B82C8);
    func_0010D180(D_0049147C);
    return 0x80000000;
}
/* merge_units: end func_00325A28 */

/* merge_units: begin func_00325AF0 */
int lgAudStartPlayback(int device)
{
    int* buf;
    if (D_0049147C == -1)
        return 0x8000000A;
    func_0010D1A0(D_0049147C);
    buf = D_00491474;
    buf[3] = device;
    if (func_00110528(D_0052AD00, 6, 0, buf, 0x20, buf, 0x20, 0, 0) == 0) {
        device = *D_00491474;
        func_0010D180(D_0049147C);
        return device;
    }
    func_00127358("lgAudStartPlayback: rpc call failed
");
    func_0010D180(D_0049147C);
    return 0x80000000;
}
/* merge_units: end func_00325AF0 */

/* merge_units: begin func_00325BB8 */
int lgAudStopPlayback(int device)
{
    int* buf;
    if (D_0049147C == -1)
        return 0x8000000A;
    func_0010D1A0(D_0049147C);
    buf = D_00491474;
    buf[3] = device;
    if (func_00110528(D_0052AD00, 7, 0, buf, 0x20, buf, 0x20, 0, 0) == 0) {
        device = *D_00491474;
        func_0010D180(D_0049147C);
        return device;
    }
    func_00127358("lgAudStopPlayback: rpc call failed
");
    func_0010D180(D_0049147C);
    return 0x80000000;
}
/* merge_units: end func_00325BB8 */
