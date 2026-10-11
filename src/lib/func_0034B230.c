extern int func_0034A7A8(void *cd, int fno, void *buf, int ssize, int rsize);
extern int func_0034A828(void *cd, void *buf, int idx, void *src, int len);
extern int func_0034A880(void *cd, void *dst, void *buf, int idx, int len);
extern int func_0034A968(void *cd, char *dst, void *buf, int idx);

#define NET_RPC_IO(name, fno) int name(void *cd, int *buf, int a, int b, void *data, int len) { int r; buf[0] = a; buf[1] = b; buf[2] = len; r = func_0034A828(cd, buf, 3, data, len); if (r < 0) return r; if (func_0034A7A8(cd, fno, buf, len + 12, len + 12) < 0) return -0x21E; r = func_0034A880(cd, data, buf, 3, len); if (r < 0) return r; return buf[0]; }
#define NET_RPC_LIST(name, fno, esz) int name(void *cd, int *buf, void *dst, int n) { int r; buf[0] = n; if (func_0034A7A8(cd, fno, buf, 4, n * esz + 4) < 0) return -0x21E; if (buf[0] < 0) return buf[0]; r = func_0034A880(cd, dst, buf, 1, buf[0] * esz); if (r < 0) return r; return buf[0]; }
NET_RPC_LIST(func_0034B230, 8, 4)
