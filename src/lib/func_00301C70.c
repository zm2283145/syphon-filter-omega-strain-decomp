#define SCF_PUT32LE(name, T) int name(unsigned char *p, T v) { int ret = 2; if (p == 0) return ret; *p++ = v; *p++ = v >> 8; *p++ = v >> 16; *p = v >> 24; return 0; }
#define SCF_PUT32BE(name, T) int name(unsigned char *p, T v) { int ret = 2; if (p == 0) return ret; *p++ = v >> 24; *p++ = v >> 16; *p++ = v >> 8; *p = v; return 0; }
#define SCF_GET32LE(name) int name(unsigned char *p, unsigned int *out) { int ret = 2; if (p == 0) return ret; if (out == 0) return ret; *out = *p++; *out |= *p++ << 8; *out |= *p++ << 16; *out |= *p << 24; return 0; }
#define SCF_GET32BE(name) int name(unsigned char *p, unsigned int *out) { int ret = 2; if (p == 0) return ret; if (out == 0) return ret; *out = *p++ << 24; *out |= *p++ << 16; *out |= *p++ << 8; *out |= *p; return 0; }
SCF_PUT32BE(func_00301C70, unsigned int)
