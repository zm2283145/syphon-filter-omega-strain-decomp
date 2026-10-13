/* newlib vfprintf.c (FLOATING_POINT, _NO_LONGLONG, _NO_LONGDBL): _vfprintf_r. Retail newlib was built with -g.
 * Retail is a ~1.9.0 snapshot: plain `double _double` (no union init), no `expsize = 0`,
 * no `xdigs = NULL`, but already has the 1.10.0 `if (expt || ndig)` fix. */
__asm__(".set nomove\n __umoddi3 = func_0011B278\n __udivdi3 = func_0011ACF8\n dpcmp = SoftFloat_UnpackAndCompare\n");
typedef unsigned int size_t;
typedef int wchar_t;
typedef __builtin_va_list va_list;
#define va_arg __builtin_va_arg
#define NULL 0
#define EOF (-1)
typedef unsigned long u_long;
typedef unsigned short u_short;
typedef unsigned int u_int;

struct _reent;
struct __siov { void *iov_base; size_t iov_len; };
struct __suio { struct __siov *uio_iov; int uio_iovcnt; int uio_resid; };
struct __sbuf { unsigned char *_base; int _size; };
typedef struct __sFILE {
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

extern int func_0012C290(FILE *, struct __suio *);           /* __sprint */
extern int func_0012C2D8(FILE *, const char *, va_list);     /* __sbprintf */
extern int func_0012EBB8(FILE *);                            /* __swsetup */
extern int func_00125D88(struct _reent *, wchar_t *, const char *, size_t, int *); /* _mbtowc_r */
extern void *func_00125DC0(const void *, int, size_t);       /* memchr */
extern size_t strlen(const char *);
#define __sprint func_0012C290
#define __sbprintf func_0012C2D8
#define __swsetup func_0012EBB8
#define _mbtowc_r func_00125D88
#define memchr func_00125DC0

#define cantwrite(fp) \
	((((fp)->_flags & __SWR) == 0 || (fp)->_bf._base == NULL) && \
	 __swsetup(fp))
#define __sferror(p) (((p)->_flags & __SERR) != 0)

struct lconv { char *decimal_point; };
extern struct lconv *func_00124F60(void);                    /* localeconv */
extern int func_00120F38(double);                            /* isinf */
extern int Double_IsNaN(double);                             /* isnan */
extern char *func_0012DA78(struct _reent *, double, int, int, char *, int *, int, int *); /* cvt */
extern int func_0012DC38(char *, int, int);                  /* exponent */
#define localeconv func_00124F60
#define isinf func_00120F38
#define isnan Double_IsNaN
#define cvt func_0012DA78
#define exponent func_0012DC38

#define	MAXEXP		308
#define	MAXFRACT	39
#define	BUF		(MAXEXP+MAXFRACT+1)
#define	DEFPREC		6

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
_vfprintf_r(struct _reent *data, FILE * fp, const char *fmt0, va_list ap)
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
	char *decimal_point = localeconv()->decimal_point;
	char softsign;
	double _double;
	#define _fpvalue _double
	int expt;
	int expsize;
	int ndig;
	char expstr[7];
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
		case 'L':
			flags |= LONGDBL;
			goto rflag;
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
		case 'e':
		case 'E':
		case 'f':
		case 'g':
		case 'G':
			if (prec == -1) {
				prec = DEFPREC;
			} else if ((ch == 'g' || ch == 'G') && prec == 0) {
				prec = 1;
			}

			if (flags & LONGDBL) {
				_fpvalue = (double) va_arg(ap, long double);
			} else {
				_fpvalue = va_arg(ap, double);
			}

			if (isinf(_fpvalue)) {
				if (_fpvalue < 0)
					sign = '-';
				cp = "Inf";
				size = 3;
				break;
			}
			if (isnan(_fpvalue)) {
				cp = "NaN";
				size = 3;
				break;
			}

			flags |= FPT;

			cp = cvt(data, _fpvalue, prec, flags, &softsign,
				&expt, ch, &ndig);

			if (ch == 'g' || ch == 'G') {
				if (expt <= -4 || expt > prec)
					ch = (ch == 'g') ? 'e' : 'E';
				else
					ch = 'g';
			} 
			if (ch <= 'e') {
				--expt;
				expsize = exponent(expstr, expt, ch);
				size = expsize + ndig;
				if (ndig > 1 || flags & ALT)
					++size;
			} else if (ch == 'f') {
				if (expt > 0) {
					size = expt;
					if (prec || flags & ALT)
						size += prec + 1;
				} else
					size = prec + 2;
			} else if (expt >= ndig) {
				size = expt;
				if (flags & ALT)
					++size;
			} else
				size = ndig + (expt > 0 ?
					1 : 2 - expt);

			if (softsign)
				sign = '-';
			break;
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

		if ((flags & FPT) == 0) {
			PRINT(cp, size);
		} else {
			if (ch >= 'f') {
				if (_fpvalue == 0) {
					PRINT("0", 1);
					if (expt < ndig || (flags & ALT) != 0) {
						PRINT(decimal_point, 1);
						PAD(ndig - 1, zeroes);
					}
				} else if (expt <= 0) {
					PRINT("0", 1);
					if(expt || ndig) {
						PRINT(decimal_point, 1);
						PAD(-expt, zeroes);
						PRINT(cp, ndig);
					}
				} else if (expt >= ndig) {
					PRINT(cp, ndig);
					PAD(expt - ndig, zeroes);
					if (flags & ALT)
						PRINT(".", 1);
				} else {
					PRINT(cp, expt);
					cp += expt;
					PRINT(".", 1);
					PRINT(cp, ndig-expt);
				}
			} else {
				if (ndig > 1 || flags & ALT) {
					ox[0] = *cp++;
					ox[1] = '.';
					PRINT(ox, 2);
                                       if (_fpvalue) {
						PRINT(cp, ndig-1);
					} else
						PAD(ndig - 1, zeroes);
				} else
					PRINT(cp, 1);
				PRINT(expstr, expsize);
			}
		}
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
