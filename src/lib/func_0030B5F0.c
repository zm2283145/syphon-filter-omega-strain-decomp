typedef unsigned int size_t;
extern char *strncpy(char *d, const char *s, size_t n);
extern size_t strlen(const char *s);
extern long strtol(const char *s, char **end, int base);
extern char *func_0030B468(char **sp, const char *delim);
extern unsigned char D_00499C70[];
extern const char D_004AF990[];
#define isdigit(c) ((D_00499C70 + 1)[(int)(c)] & 4)

/* Splits "proto://host:port/path"-style URL text: copies the path to path, host to host, port to *port. */
int func_0030B5F0(char *url, char *path, char *host, unsigned short *port)
{
    char *rest = 0;
    int slashes = 0;
    unsigned int i = 0;
    char *p;
    char *tok;

    if (url == 0) return 2;
    if (path == 0) return 2;
    if (host == 0) return 2;
    if (port == 0) return 2;
    for (i = 0; i < strlen(url); i++) {
        p = url + i;
        if (*p == '/') {
            slashes++;
            if (slashes == 2) {
                rest = p + 1;
            } else if (slashes == 3) {
                strncpy(path, p + 1, 0x200);
                *p = 0;
                tok = func_0030B468(&rest, D_004AF990);
                if (!isdigit(*tok)) return 11;
                strncpy(host, tok, 0x10);
                if (rest != 0)
                    *port = strtol(rest, 0, 10);
                else
                    *port = 80;
            }
        }
    }
    return 0;
}


