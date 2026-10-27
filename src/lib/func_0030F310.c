extern unsigned char D_00499C70[];
#define isspace(c) ((D_00499C70 + 1)[(unsigned)(c)] & 8)

typedef struct {
    int flags;
    char s004[0x100];
    char s104[0x100];
    char s204[0x100];
    char s304[0x100];
    char s404[0x100];
    char s504[0x100];
    char s604[0x100];
    char s704[0x100];
    char s804[0x100];
    char s904[0x100];
    char sA04[0x100];
    char sB04[0x100];
    char sC04[0x100];
    char sD04[0x100];
    char sE04[0x100];
    char sF04[0x100];
    char s1004[0x100];
    char s1104[0x100];
    char s1204[0x100];
} Desc_30F310;

typedef struct {
    char pad0[8];
    char name[0x100];
    char buf[0x100];
    int bufLen;
    unsigned char stop;
    char pad1[3];
    Desc_30F310 *dst;
} Xml_30F310;

typedef struct {
    char *p[20];
} Tags_30F310;

extern Tags_30F310 D_004B0948;
extern char D_004B0828[];
extern char *D_00491384;
extern char *D_00491388;
extern char *D_0049138C;
extern char *D_00491390;
extern char *D_00491398;
extern char *D_0049139C;
extern char *D_004913A0;
extern char *D_004913A4;
extern char *D_004913A8;
extern char *D_004913AC;
extern char *D_004913B0;
extern char *D_004913B4;
extern char *D_004913B8;
extern char *func_0030F0E8(char *buf, int len);
extern int Libc_Strncmp(const char *a, const char *b, int n);
extern char *strncpy(char *d, const char *s, unsigned int n);

void func_0030F310(const char *s, int len, Xml_30F310 *p)
{
    Desc_30F310 *d = p->dst;
    unsigned int i = 0;
    Tags_30F310 tags = D_004B0948;
    char *e;

    if (p->stop) return;
    if (len == 0) return;
    if (isspace(*s)) return;
    e = func_0030F0E8(p->buf, p->bufLen);
    while (tags.p[i] && Libc_Strncmp(tags.p[i], e, 0x100))
        i++;
    switch (i) {
    case 0:
        if (Libc_Strncmp(D_004B0828, p->name, 0x100) || *s != '1')
            p->stop = 1;
        break;
    case 1:
        if (Libc_Strncmp(D_004B0828, p->name, 0x100) || *s != '0')
            p->stop = 1;
        break;
    case 2:
        strncpy(d->s004, s, len);
        d->s004[len] = 0;
        break;
    case 3:
        if (Libc_Strncmp(D_00491384, s, len) == 0) {
            d->flags |= 1;
        } else if (Libc_Strncmp(D_00491388, s, len) == 0) {
            d->flags |= 2;
        } else if (Libc_Strncmp(D_0049138C, s, len) == 0) {
            d->flags |= 4;
            strncpy(p->name, s, len);
            p->name[len] = 0;
        } else if (Libc_Strncmp(D_00491390, s, len) == 0) {
            d->flags |= 0x10;
        }
        break;
    case 4:
        if (Libc_Strncmp(D_0049138C, p->name, 0x100) == 0) {
            strncpy(d->s104, s, len);
            d->s104[len] = 0;
        }
        break;
    case 5:
        if (Libc_Strncmp(D_0049138C, p->name, 0x100) == 0) {
            strncpy(d->s204, s, len);
            d->s204[len] = 0;
        }
        break;
    case 6:
        if (Libc_Strncmp(D_0049138C, p->name, 0x100) == 0) {
            strncpy(d->s304, s, len);
            d->s304[len] = 0;
        }
        break;
    case 7:
        if (Libc_Strncmp(D_0049138C, p->name, 0x100) == 0) {
            strncpy(d->s404, s, len);
            d->s404[len] = 0;
        }
        break;
    case 8:
        if (Libc_Strncmp(D_0049138C, p->name, 0x100) == 0) {
            strncpy(d->s504, s, len);
            d->s504[len] = 0;
        }
        break;
    case 9:
        if (Libc_Strncmp(D_0049138C, p->name, 0x100) == 0) {
            strncpy(d->s604, s, len);
            d->s604[len] = 0;
        }
        break;
    case 10:
        if (Libc_Strncmp(D_0049138C, p->name, 0x100) == 0) {
            strncpy(d->s704, s, len);
            d->s704[len] = 0;
        }
        break;
    case 11:
        if (Libc_Strncmp(D_0049138C, p->name, 0x100) == 0) {
            strncpy(d->s804, s, len);
            d->s804[len] = 0;
        }
        break;
    case 12:
        if (Libc_Strncmp(D_0049138C, p->name, 0x100) == 0) {
            strncpy(d->s904, s, len);
            d->s904[len] = 0;
        }
        break;
    case 13:
        if (Libc_Strncmp(D_0049138C, p->name, 0x100) == 0) {
            strncpy(d->sA04, s, len);
            d->sA04[len] = 0;
        }
        break;
    case 14:
        if (Libc_Strncmp(D_00491398, s, len) == 0) {
            d->flags |= 0x20;
        } else if (Libc_Strncmp(D_0049139C, s, len) == 0) {
            d->flags |= 0x40;
        } else if (Libc_Strncmp(D_004913A0, s, len) == 0) {
            d->flags |= 0x80;
        } else if (Libc_Strncmp(D_004913A4, s, len) == 0) {
            d->flags |= 0x100;
        } else if (Libc_Strncmp(D_004913A8, s, len) == 0) {
            d->flags |= 0x200;
        } else if (Libc_Strncmp(D_004913AC, s, len) == 0) {
            d->flags |= 0x400;
        } else if (Libc_Strncmp(D_004913B0, s, len) == 0) {
            d->flags |= 0x800;
            strncpy(p->name, s, len);
            p->name[len] = 0;
        } else if (Libc_Strncmp(D_004913B4, s, len) == 0) {
            d->flags |= 0x1000;
            strncpy(p->name, s, len);
            p->name[len] = 0;
        } else if (Libc_Strncmp(D_004913B8, s, len) == 0) {
            d->flags |= 0x2000;
        }
        break;
    case 15:
        if (Libc_Strncmp(D_004913B0, p->name, 0x100) == 0) {
            strncpy(d->sB04, s, len);
            d->sB04[len] = 0;
        } else if (Libc_Strncmp(D_004913B4, p->name, 0x100) == 0) {
            strncpy(d->sF04, s, len);
            d->sF04[len] = 0;
        }
        break;
    case 16:
        if (Libc_Strncmp(D_004913B0, p->name, 0x100) == 0) {
            strncpy(d->sD04, s, len);
            d->sD04[len] = 0;
        } else if (Libc_Strncmp(D_004913B4, p->name, 0x100) == 0) {
            strncpy(d->s1104, s, len);
            d->s1104[len] = 0;
        }
        break;
    case 17:
        if (Libc_Strncmp(D_004913B0, p->name, 0x100) == 0) {
            strncpy(d->sE04, s, len);
            d->sE04[len] = 0;
        } else if (Libc_Strncmp(D_004913B4, p->name, 0x100) == 0) {
            strncpy(d->s1204, s, len);
            d->s1204[len] = 0;
        }
        break;
    case 18:
        if (Libc_Strncmp(D_004913B0, p->name, 0x100) == 0) {
            strncpy(d->sC04, s, len);
            d->sC04[len] = 0;
        } else if (Libc_Strncmp(D_004913B4, p->name, 0x100) == 0) {
            strncpy(d->s1004, s, len);
            d->s1004[len] = 0;
        }
        break;
    }
}
