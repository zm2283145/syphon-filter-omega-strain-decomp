extern int func_0034A7A8(void *cd, int fno, void *buf, int ssize, int rsize);
#define NET_RPC0(name, fno) int name(void *cd, unsigned int *buf) { if (func_0034A7A8(cd, fno, buf, 0, 4) < 0) return -0x21E; return buf[0]; }
#define NET_RPC1(name, fno) int name(void *cd, unsigned int *buf, unsigned int a) { buf[0] = a; if (func_0034A7A8(cd, fno, buf, 4, 4) < 0) return -0x21E; return buf[0]; }
#define NET_RPC2(name, fno) int name(void *cd, unsigned int *buf, unsigned int a, unsigned int b) { buf[0] = a; buf[1] = b; if (func_0034A7A8(cd, fno, buf, 8, 4) < 0) return -0x21E; return buf[0]; }

NET_RPC0(func_0034B8A8, 0x1F)
