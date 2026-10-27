/*
 * vfiprintf.c: newlib's vfprintf.c built with -DINTEGER_ONLY (the integer-only
 * printf core): __sprint, __sbprintf, vfiprintf and _vfiprintf_r.
 * Compiler: EE-GCC 2.96 -O2 -G0 (retail newlib was built with -g).
 */
__asm__(".set nomove\n __umoddi3 = Libgcc_Umoddi3\n __udivdi3 = Libgcc_Udivdi3\n");
typedef unsigned int size_t;
typedef int wchar_t;
typedef __builtin_va_list va_list;
#define va_arg __builtin_va_arg
#define NULL 0
#define EOF (-1)
typedef unsigned long u_long;
typedef unsigned short u_short;
typedef unsigned int u_int;

/* struct _reent: only the stdio init fields */
struct _reent {
    char pad[0x38];
    int __sdidinit;                         /* +0x38 */
    void (*__cleanup)(struct _reent *);     /* +0x3C */
};
struct __siov { void *iov_base; size_t iov_len; };
struct __suio { struct __siov *uio_iov; int uio_iovcnt; int uio_resid; };
struct __sbuf { unsigned char *_base; int _size; };
typedef struct __sFILE {                    /* 0x58 bytes */
    unsigned char *_p; int _r; int _w; short _flags; short _file; struct __sbuf _bf; int _lbfsize;
    void *_cookie; int (*_read)(); int (*_write)(); int (*_seek)(); int (*_close)();
    struct __sbuf _ub; unsigned char *_up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1];
    struct __sbuf _lb; int _blksize; int _offset; struct _reent *_data;
} FILE;

#define __SNBF 0x0002
#define __SWR  0x0008
#define __SRW  0x0010
#define __SERR 0x0040

extern struct _reent *D_00489738;   /* _impure_ptr */
extern int D_00489740;              /* __mb_cur_max */
#define _REENT D_00489738
#define MB_CUR_MAX D_00489740

extern int fflush(FILE *);                            /* fflush */
extern void __sinit(struct _reent *);                  /* __sinit */
extern int __sfvwrite(FILE *, struct __suio *);           /* __sfvwrite */
extern int __swsetup(FILE *);                            /* __swsetup */
extern int _mbtowc_r(struct _reent *, wchar_t *, const char *, size_t, int *); /* _mbtowc_r */
extern void *Libc_Memchr(const void *, int, size_t);       /* memchr */
extern size_t strlen(const char *);
#define fflush fflush
#define __sinit __sinit
#define __sfvwrite __sfvwrite
#define __sprint Newlib_Sprint_void
#define __swsetup __swsetup
#define _mbtowc_r _mbtowc_r
#define memchr Libc_Memchr

#define CHECK_INIT(fp) \
    do { if ((fp)->_data == 0) (fp)->_data = _REENT; if (!(fp)->_data->__sdidinit) __sinit((fp)->_data); } while (0)

int vfiprintf(FILE *fp, const char *fmt0, va_list ap);
int _vfiprintf_r(struct _reent *data, FILE *fp, const char *fmt0, va_list ap);

/*
 * Flush out all the vectors defined by the given uio,
 * then reset it so that it can be reused.
 */
int
__sprint(FILE *fp, register struct __suio *uio)
{
	register int err;

	if (uio->uio_resid == 0) {
		uio->uio_iovcnt = 0;
		return (0);
	}
	err = __sfvwrite(fp, uio);
	uio->uio_resid = 0;
	uio->uio_iovcnt = 0;
	return (err);
}

/*
 * Helper function for `fprintf to unbuffered unix file': creates a
 * temporary buffer.  We only work on write-only files; this avoids
 * worries about ungetc buffers and so forth.
 */
int
__sbprintf(register FILE *fp, const char *fmt, va_list ap)
{
	int ret;
	FILE fake;
	unsigned char buf[1024];

	/* copy the important variables */
	fake._data = fp->_data;
	fake._flags = fp->_flags & ~__SNBF;
	fake._file = fp->_file;
	fake._cookie = fp->_cookie;
	fake._write = fp->_write;

	/* set up the buffer */
	fake._bf._base = fake._p = buf;
	fake._bf._size = fake._w = sizeof(buf);
	fake._lbfsize = 0;	/* not actually used, but Just In Case */

	/* do the work, then copy any error status */
	ret = vfiprintf(&fake, fmt, ap);
	if (ret >= 0 && fflush(&fake))
		ret = EOF;
	if (fake._flags & __SERR)
		fp->_flags |= __SERR;
	return (ret);
}

int
vfiprintf(FILE *fp, const char *fmt0, va_list ap)
{
	CHECK_INIT (fp);
	return _vfiprintf_r (fp->_data, fp, fmt0, ap);
}

#define cantwrite(fp) \
	((((fp)->_flags & __SWR) == 0 || (fp)->_bf._base == NULL) && \
	 __swsetup(fp))
#define __sferror(p) (((p)->_flags & __SERR) != 0)

#define	BUF		40

#define	to_digit(c)	((c) - '0')
#define is_digit(c)	((unsigned)to_digit(c) <= 9)
#define	to_char(n)	((n) + '0')

#define	ALT		0x001
#define	HEXPREFIX	0x002
#define	LADJUST		0x004
#define	LONGDBL		0x008
#define	LONGINT		0x010
#define	QUADINT		0x020
#define	SHORTINT	0x040
#define	ZEROPAD		0x080
#define FPT		0x100

int
_vfiprintf_r(struct _reent *data, FILE * fp, const char *fmt0, va_list ap)
{
	register char *fmt;
	register int ch;
	register int n, m;
	register char *cp;
	register struct __siov *iovp;
	register int flags;
	int ret;
	int width;
	int prec;
	char sign;
	wchar_t wc;
	u_long _uquad;
	enum { OCT, DEC, HEX } base;
	int dprec;
	int realsz;
	int size;
	char *xdigs;
#define NIOV 8
	struct __suio uio;
	struct __siov iov[NIOV];
	char buf[BUF];
	char ox[2];
        int state = 0;

#define	PADSIZE	16
	static const char blanks[PADSIZE] =
	 {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	static const char zeroes[PADSIZE] =
	 {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};

#define	PRINT(ptr, len) { \
	iovp->iov_base = (ptr); \
	iovp->iov_len = (len); \
	uio.uio_resid += (len); \
	iovp++; \
	if (++uio.uio_iovcnt >= NIOV) { \
		if (__sprint(fp, &uio)) \
			goto error; \
		iovp = iov; \
	} \
}
#define	PAD(howmany, with) { \
	if ((n = (howmany)) > 0) { \
		while (n > PADSIZE) { \
			PRINT(with, PADSIZE); \
			n -= PADSIZE; \
		} \
		PRINT(with, n); \
	} \
}
#define	FLUSH() { \
	if (uio.uio_resid && __sprint(fp, &uio)) \
		goto error; \
	uio.uio_iovcnt = 0; \
	iovp = iov; \
}

#define	SARG() \
	(flags&LONGINT ? va_arg(ap, long) : \
	    flags&SHORTINT ? (long)(short)va_arg(ap, int) : \
	    (long)va_arg(ap, int))
#define	UARG() \
	(flags&LONGINT ? va_arg(ap, u_long) : \
	    flags&SHORTINT ? (u_long)(u_short)va_arg(ap, int) : \
	    (u_long)va_arg(ap, u_int))

	if (cantwrite(fp))
		return (EOF);

	if ((fp->_flags & (__SNBF|__SWR|__SRW)) == (__SNBF|__SWR) &&
	    fp->_file >= 0)
		return (__sbprintf(fp, fmt0, ap));

	fmt = (char *)fmt0;
	uio.uio_iov = iovp = iov;
	uio.uio_resid = 0;
	uio.uio_iovcnt = 0;
	ret = 0;

	for (;;) {
	        cp = fmt;
	        while ((n = _mbtowc_r(_REENT, &wc, fmt, MB_CUR_MAX, &state)) > 0) {
			fmt += n;
			if (wc == '%') {
				fmt--;
				break;
			}
		}
		if ((m = fmt - cp) != 0) {
			PRINT(cp, m);
			ret += m;
		}
		if (n <= 0)
			goto done;
		fmt++;

		flags = 0;
		dprec = 0;
		width = 0;
		prec = -1;
		sign = '\0';

rflag:		ch = *fmt++;
reswitch:	switch (ch) {
		case ' ':
			if (!sign)
				sign = ' ';
			goto rflag;
		case '#':
			flags |= ALT;
			goto rflag;
		case '*':
			if ((width = va_arg(ap, int)) >= 0)
				goto rflag;
			width = -width;
		case '-':
			flags |= LADJUST;
			goto rflag;
		case '+':
			sign = '+';
			goto rflag;
		case '.':
			if ((ch = *fmt++) == '*') {
				n = va_arg(ap, int);
				prec = n < 0 ? -1 : n;
				goto rflag;
			}
			n = 0;
			while (is_digit(ch)) {
				n = 10 * n + to_digit(ch);
				ch = *fmt++;
			}
			prec = n < 0 ? -1 : n;
			goto reswitch;
		case '0':
			flags |= ZEROPAD;
			goto rflag;
		case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			n = 0;
			do {
				n = 10 * n + to_digit(ch);
				ch = *fmt++;
			} while (is_digit(ch));
			width = n;
			goto reswitch;
		case 'h':
			flags |= SHORTINT;
			goto rflag;
		case 'l':
			if (*fmt == 'l') {
				fmt++;
				flags |= QUADINT;
			} else {
				flags |= LONGINT;
			}
			goto rflag;
		case 'q':
			flags |= QUADINT;
			goto rflag;
		case 'c':
			*(cp = buf) = va_arg(ap, int);
			size = 1;
			sign = '\0';
			break;
		case 'D':
			flags |= LONGINT;
		case 'd':
		case 'i':
			_uquad = SARG();
			if ((long) _uquad < 0)
			{

				_uquad = -_uquad;
				sign = '-';
			}
			base = DEC;
			goto number;
		case 'n':
			if (flags & LONGINT)
				*va_arg(ap, long *) = ret;
			else if (flags & SHORTINT)
				*va_arg(ap, short *) = ret;
			else
				*va_arg(ap, int *) = ret;
			continue;
		case 'O':
			flags |= LONGINT;
		case 'o':
			_uquad = UARG();
			base = OCT;
			goto nosign;
		case 'p':
			_uquad = (u_long)va_arg(ap, void *);
			base = HEX;
			xdigs = "0123456789abcdef";
			flags |= HEXPREFIX;
			ch = 'x';
			goto nosign;
		case 's':
			if ((cp = va_arg(ap, char *)) == NULL)
				cp = "(null)";
			if (prec >= 0) {
				char *p = memchr(cp, 0, prec);

				if (p != NULL) {
					size = p - cp;
					if (size > prec)
						size = prec;
				} else
					size = prec;
			} else
				size = strlen(cp);
			sign = '\0';
			break;
		case 'U':
			flags |= LONGINT;
		case 'u':
			_uquad = UARG();
			base = DEC;
			goto nosign;
		case 'X':
			xdigs = "0123456789ABCDEF";
			goto hex;
		case 'x':
			xdigs = "0123456789abcdef";
hex:			_uquad = UARG();
			base = HEX;
			if (flags & ALT && _uquad != 0)
				flags |= HEXPREFIX;

nosign:			sign = '\0';
number:			if ((dprec = prec) >= 0)
				flags &= ~ZEROPAD;

			cp = buf + BUF;
			if (_uquad != 0 || prec != 0) {
				switch (base) {
				case OCT:
					do {
						*--cp = to_char(_uquad & 7);
						_uquad >>= 3;
					} while (_uquad);
					if (flags & ALT && *cp != '0')
						*--cp = '0';
					break;

				case DEC:
					while (_uquad >= 10) {
						*--cp = to_char(_uquad % 10);
						_uquad /= 10;
					}
					*--cp = to_char(_uquad);
					break;

				case HEX:
					do {
						*--cp = xdigs[_uquad & 15];
						_uquad >>= 4;
					} while (_uquad);
					break;

				default:
					cp = "bug in vfprintf: bad base";
					size = strlen(cp);
					goto skipsize;
				}
			}
			size = buf + BUF - cp;
		skipsize:
			break;
		default:
			if (ch == '\0')
				goto done;
			cp = buf;
			*cp = ch;
			size = 1;
			sign = '\0';
			break;
		}

		realsz = dprec > size ? dprec : size;
		if (sign)
			realsz++;
		else if (flags & HEXPREFIX)
			realsz+= 2;

		if ((flags & (LADJUST|ZEROPAD)) == 0)
			PAD(width - realsz, blanks);

		if (sign) {
			PRINT(&sign, 1);
		} else if (flags & HEXPREFIX) {
			ox[0] = '0';
			ox[1] = ch;
			PRINT(ox, 2);
		}

		if ((flags & (LADJUST|ZEROPAD)) == ZEROPAD)
			PAD(width - realsz, zeroes);

		PAD(dprec - size, zeroes);

		PRINT(cp, size);
		if (flags & LADJUST)
			PAD(width - realsz, blanks);

		ret += width > realsz ? width : realsz;

		FLUSH();
	}
done:
	FLUSH();
error:
	return (__sferror(fp) ? EOF : ret);
}
