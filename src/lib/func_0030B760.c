typedef unsigned int size_t;
extern unsigned char D_00499C70[];
const char D_004AF990[] = ":";
#define isspace(c) ((D_00499C70 + 1)[(int)(c)] & 8)
char *func_0012AC70(char *s, const char *delim);
long strtol(const char *s, char **end, int base);
int func_0030B510(const char *s1, const char *s2, size_t n);
char *func_0030B468(char **sp, const char *delim);
size_t strlen(const char *s);
char *strncpy(char *d, const char *s, size_t n);

typedef struct {
    int status;
    int maxage;
    int clen;
    char date[0x200];
    char usn[0x200];
    char ext[0x200];
    char location[0x200];
    char server[0x200];
    char st[0x200];
    char ctype[0x200];
    char clang[0x200];
} SsdpResp;

int func_0030B760(char *buf, SsdpResp *r)
{
    char *p = 0;
    const char *names[] = {
        "Cache-Control", "USN", "Location", "Server", "ST", "EXT", "Date",
        "Content-length", "Content-language", "Content-type", 0
    };
    int status = -1;
    int line = 0;
    char *tok;
    int i;

    tok = func_0012AC70(buf, "\r\n");
    while (tok) {
        if (line == 0) {
            if (func_0030B510(tok, "http/1.", 7) == 0) {
                p = tok + 9;
                status = (short)strtol(p, 0, 10);
                r->status = status;
                if (status != 200)
                    return status;
            } else {
                return status;
            }
        } else {
            p = tok;
            func_0030B468(&p, D_004AF990);
            while (isspace(*p))
                p++;
            for (i = strlen(tok); i > 0; i--) {
                if (isspace(tok[i]))
                    tok[i] = 0;
            }
            for (i = 0; names[i] && func_0030B510(names[i], tok, strlen(names[i])); i++)
                ;
            switch (i) {
            case 0:
                if (func_0030B510(func_0030B468(&p, "="), "max-age", 7) == 0)
                    r->maxage = strtol(p, 0, 10);
                break;
            case 1:
                strncpy(r->usn, p, 0x200);
                break;
            case 2:
                strncpy(r->location, p, 0x200);
                break;
            case 3:
                strncpy(r->server, p, 0x200);
                break;
            case 4:
                strncpy(r->st, p, 0x200);
                break;
            case 5:
                strncpy(r->ext, p, 0x200);
                break;
            case 6:
                strncpy(r->date, p, 0x200);
                break;
            case 7:
                r->clen = strtol(p, 0, 10);
                break;
            case 8:
                strncpy(r->clang, p, 0x200);
                break;
            case 9:
                strncpy(r->ctype, p, 0x200);
                break;
            }
        }
        tok = func_0012AC70(0, "\r\n");
        line++;
    }
    return status;
}




