#define SCF_GET16(name) int name(unsigned char *p, unsigned short *out) { int ret = 2; if (p == 0) return ret; if (out == 0) return ret; *out = p[0]; *out |= p[1] << 8; return 0; }
SCF_GET16(func_00301950)
