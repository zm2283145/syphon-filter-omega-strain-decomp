/* newlib 1.9.0 vfscanf.c (FLOATING_POINT, _NO_LONGDBL, no MB_CAPABLE): __svfscanf. Retail newlib was built with -g. */
__asm__(".set nomove\n dptofp = SoftFloat_DoubleToFloat\n");
typedef unsigned int size_t;
typedef int wchar_t;
typedef __builtin_va_list va_list;
#define va_arg __builtin_va_arg
#define NULL 0
#define EOF (-1)
#define _CONST const
#define _PTR void *
#define _POINTER_INT long
#define _CAST_VOID (void)
#define _LONG_DOUBLE long double
#define CHAR_BIT 8

struct _reent;
struct __sbuf { unsigned char *_base; int _size; };
typedef struct __sFILE {
    unsigned char *_p; int _r; int _w; short _flags; short _file; struct __sbuf _bf; int _lbfsize;
    void *_cookie; int (*_read)(); int (*_write)(); int (*_seek)(); int (*_close)();
    struct __sbuf _ub; unsigned char *_up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1];
    struct __sbuf _lb; int _blksize; int _offset; struct _reent *_data;
} FILE;

extern const char D_00499C70[];     /* _ctype_ */
#define _ctype_ D_00499C70
#define _U 01
#define _S 010
#define isupper(c) ((_ctype_+1)[(unsigned)(c)]&_U)
#define isspace(c) ((_ctype_+1)[(unsigned)(c)]&_S)

extern int __srefill(FILE *);                       /* __srefill */
extern int ungetc(int, FILE *);                  /* ungetc */
extern size_t fread(void *, size_t, size_t, FILE *); /* fread */
extern long atol(const char *);                /* atol */
extern double atof(const char *);              /* atof */
extern long strtol(const char *, char **, int);  /* strtol */
extern unsigned long strtoul(const char *, char **, int); /* strtoul */
extern int sprintf(char *, const char *, ...);
#define __srefill __srefill
#define ungetc ungetc
#define fread fread
#define atol atol
#define atof atof
#define strtol strtol
#define strtoul strtoul
#define __sccl __sccl

#define MAXEXP		308
#define MAXFRACT	39
#define	BUF	(MAXEXP+MAXFRACT+3)
#define MAX_LONG_LEN ((CHAR_BIT * sizeof (long)  - 1) * 4 / 13 + 2)

#define	LONG		0x01
#define	LONGDBL		0x02
#define	SHORT		0x04
#define	SUPPRESS	0x08
#define	POINTER		0x10
#define	NOSKIP		0x20

#define	SIGNOK		0x40
#define	NDIGITS		0x80

#define	DPTOK		0x100
#define	EXPOK		0x200

#define	PFXOK		0x100
#define	NZDIGITS	0x200

#define	CT_CHAR		0
#define	CT_CCL		1
#define	CT_STRING	2
#define	CT_INT		3
#define	CT_FLOAT	4

#define u_char char
#define u_long unsigned long

/*static*/ u_char *__sccl ();

#define BufferEmpty (fp->_r <= 0 && __srefill(fp))

int
__svfscanf (fp, fmt0, ap)
     register FILE *fp;
     char _CONST *fmt0;
     va_list ap;
{
  register u_char *fmt = (u_char *) fmt0;
  register int c;
  register size_t width;
  register char *p;
  register int n;
  register int flags;
  register char *p0;
  int nassigned;
  int nread;
  int base = 0;
  int nbytes = 1;
  wchar_t wc;

  u_long (*ccfn) () = 0;
  char ccltab[256];
  char buf[BUF];
  char *lptr;

  short *sp;
  int *ip;
  float *flp;
  _LONG_DOUBLE *ldp;
  double *dp;
  long *lp;

  static _CONST short basefix[17] =
    {10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

  nassigned = 0;
  nread = 0;
  for (;;)
    {
      wc = *fmt;
      fmt += nbytes;
      if (wc == 0)
	return nassigned;
      if (nbytes == 1 && isspace (wc))
	{
	  for (;;)
	    {
	      if (BufferEmpty)
		return nassigned;
	      if (!isspace (*fp->_p))
		break;
	      nread++, fp->_r--, fp->_p++;
	    }
	  continue;
	}
      if (wc != '%')
	goto literal;
      width = 0;
      flags = 0;

    again:
      c = *fmt++;

      switch (c)
	{
	case '%':
	literal:
          lptr = fmt - nbytes;
          for (n = 0; n < nbytes; ++n)
            {
	      if (BufferEmpty)
	        goto input_failure;
	      if (*fp->_p != *lptr)
	        goto match_failure;
	      fp->_r--, fp->_p++;
	      nread++;
              ++lptr;
            }
	  continue;

	case '*':
	  flags |= SUPPRESS;
	  goto again;
	case 'l':
	  flags |= LONG;
	  goto again;
	case 'L':
	  flags |= LONGDBL;
	  goto again;
	case 'h':
	  flags |= SHORT;
	  goto again;

	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	  width = width * 10 + c - '0';
	  goto again;

	case 'D':
	  flags |= LONG;
	case 'd':
	  c = CT_INT;
	  ccfn = (u_long (*)())strtol;
	  base = 10;
	  break;

	case 'i':
	  c = CT_INT;
	  ccfn = (u_long (*)())strtol;
	  base = 0;
	  break;

	case 'O':
	  flags |= LONG;
	case 'o':
	  c = CT_INT;
	  ccfn = strtoul;
	  base = 8;
	  break;

	case 'u':
	  c = CT_INT;
	  ccfn = strtoul;
	  base = 10;
	  break;

	case 'X':
	case 'x':
	  flags |= PFXOK;
	  c = CT_INT;
	  ccfn = strtoul;
	  base = 16;
	  break;

	case 'E':
	case 'G':
	case 'e':
	case 'f':
	case 'g':
	  c = CT_FLOAT;
	  break;

	case 's':
	  c = CT_STRING;
	  break;

	case '[':
	  fmt = __sccl (ccltab, fmt);
	  flags |= NOSKIP;
	  c = CT_CCL;
	  break;

	case 'c':
	  flags |= NOSKIP;
	  c = CT_CHAR;
	  break;

	case 'p':
	  flags |= POINTER | PFXOK;
	  c = CT_INT;
	  ccfn = strtoul;
	  base = 16;
	  break;

	case 'n':
	  if (flags & SUPPRESS)
	    continue;
	  if (flags & SHORT)
	    {
	      sp = va_arg (ap, short *);
	      *sp = nread;
	    }
	  else if (flags & LONG)
	    {
	      lp = va_arg (ap, long *);
	      *lp = nread;
	    }
	  else
	    {
	      ip = va_arg (ap, int *);
	      *ip = nread;
	    }
	  continue;

	case '\0':
	  return EOF;

	default:
	  if (isupper (c))
	    flags |= LONG;
	  c = CT_INT;
	  ccfn = (u_long (*)())strtol;
	  base = 10;
	  break;
	}

      if (BufferEmpty)
	goto input_failure;

      if ((flags & NOSKIP) == 0)
	{
	  while (isspace (*fp->_p))
	    {
	      nread++;
	      if (--fp->_r > 0)
		fp->_p++;
	      else
	      if (__srefill (fp))
		goto input_failure;
	    }
	}

      switch (c)
	{

	case CT_CHAR:
	  if (width == 0)
	    width = 1;
	  if (flags & SUPPRESS)
	    {
	      size_t sum = 0;

	      for (;;)
		{
		  if ((n = fp->_r) < width)
		    {
		      sum += n;
		      width -= n;
		      fp->_p += n;
		      if (__srefill (fp))
			{
			  if (sum == 0)
			    goto input_failure;
			  break;
			}
		    }
		  else
		    {
		      sum += width;
		      fp->_r -= width;
		      fp->_p += width;
		      break;
		    }
		}
	      nread += sum;
	    }
	  else
	    {
	      size_t r = fread ((_PTR) va_arg (ap, char *), 1, width, fp);

	      if (r == 0)
		goto input_failure;
	      nread += r;
	      nassigned++;
	    }
	  break;

	case CT_CCL:
	  if (width == 0)
	    width = ~0;
	  if (flags & SUPPRESS)
	    {
	      n = 0;
	      while (ccltab[*fp->_p])
		{
		  n++, fp->_r--, fp->_p++;
		  if (--width == 0)
		    break;
		  if (BufferEmpty)
		    {
		      if (n == 0)
			goto input_failure;
		      break;
		    }
		}
	      if (n == 0)
		goto match_failure;
	    }
	  else
	    {
	      p0 = p = va_arg (ap, char *);
	      while (ccltab[*fp->_p])
		{
		  fp->_r--;
		  *p++ = *fp->_p++;
		  if (--width == 0)
		    break;
		  if (BufferEmpty)
		    {
		      if (p == p0)
			goto input_failure;
		      break;
		    }
		}
	      n = p - p0;
	      if (n == 0)
		goto match_failure;
	      *p = 0;
	      nassigned++;
	    }
	  nread += n;
	  break;

	case CT_STRING:
	  if (width == 0)
	    width = ~0;
	  if (flags & SUPPRESS)
	    {
	      n = 0;
	      while (!isspace (*fp->_p))
		{
		  n++, fp->_r--, fp->_p++;
		  if (--width == 0)
		    break;
		  if (BufferEmpty)
		    break;
		}
	      nread += n;
	    }
	  else
	    {
	      p0 = p = va_arg (ap, char *);
	      while (!isspace (*fp->_p))
		{
		  fp->_r--;
		  *p++ = *fp->_p++;
		  if (--width == 0)
		    break;
		  if (BufferEmpty)
		    break;
		}
	      *p = 0;
	      nread += p - p0;
	      nassigned++;
	    }
	  continue;

	case CT_INT:
	  if (--width > sizeof (buf) - 2)
	    width = sizeof (buf) - 2;
	  width++;
	  flags |= SIGNOK | NDIGITS | NZDIGITS;
	  for (p = buf; width; width--)
	    {
	      c = *fp->_p;
	      switch (c)
		{
		case '0':
		  if (base == 0)
		    {
		      base = 8;
		      flags |= PFXOK;
		    }
		  if (flags & NZDIGITS)
		    flags &= ~(SIGNOK | NZDIGITS | NDIGITS);
		  else
		    flags &= ~(SIGNOK | PFXOK | NDIGITS);
		  goto ok;

		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		  base = basefix[base];
		  flags &= ~(SIGNOK | PFXOK | NDIGITS);
		  goto ok;

		case '8':
		case '9':
		  base = basefix[base];
		  if (base <= 8)
		    break;
		  flags &= ~(SIGNOK | PFXOK | NDIGITS);
		  goto ok;

		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
		  if (base <= 10)
		    break;
		  flags &= ~(SIGNOK | PFXOK | NDIGITS);
		  goto ok;

		case '+':
		case '-':
		  if (flags & SIGNOK)
		    {
		      flags &= ~SIGNOK;
		      goto ok;
		    }
		  break;

		case 'x':
		case 'X':
		  if (flags & PFXOK && p == buf + 1)
		    {
		      base = 16;
		      flags &= ~PFXOK;
		      goto ok;
		    }
		  break;
		}

	      break;
	    ok:
	      *p++ = c;
	      if (--fp->_r > 0)
		fp->_p++;
	      else
	      if (__srefill (fp))
		break;
	    }
	  if (flags & NDIGITS)
	    {
	      if (p > buf)
		_CAST_VOID ungetc (*(u_char *)-- p, fp);
	      goto match_failure;
	    }
	  c = ((u_char *) p)[-1];
	  if (c == 'x' || c == 'X')
	    {
	      --p;
	      ungetc (c, fp);
	    }
	  if ((flags & SUPPRESS) == 0)
	    {
	      u_long res;

	      *p = 0;
	      res = (*ccfn) (buf, (char **) NULL, base);
	      if (flags & POINTER)
		*(va_arg (ap, _PTR *)) = (_PTR) (unsigned _POINTER_INT) res;
	      else if (flags & SHORT)
		{
		  sp = va_arg (ap, short *);
		  *sp = res;
		}
	      else if (flags & LONG)
		{
		  lp = va_arg (ap, long *);
		  *lp = res;
		}
	      else
		{
		  ip = va_arg (ap, int *);
		  *ip = res;
		}
	      nassigned++;
	    }
	  nread += p - buf;
	  break;

	case CT_FLOAT:
	{
	  long leading_zeroes;
	  long zeroes, exp_adjust;
	  char *exp_start;
	  if (--width > sizeof (buf) - 2)
	    width = sizeof (buf) - 2;
	  width++;
	  flags |= SIGNOK | NDIGITS | DPTOK | EXPOK;
	  zeroes = 0;
	  exp_adjust = 0;
	  for (p = buf; width; )
	    {
	      c = *fp->_p;
	      switch (c)
		{

		case '0':
		  if (flags & NDIGITS)
		    {
		      flags &= ~SIGNOK;
		      zeroes++;
		      goto fskip;
		    }
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		  flags &= ~(SIGNOK | NDIGITS);
		  goto fok;

		case '+':
		case '-':
		  if (flags & SIGNOK)
		    {
		      flags &= ~SIGNOK;
		      goto fok;
		    }
		  break;
		case '.':
		  if (flags & DPTOK)
		    {
		      flags &= ~(SIGNOK | DPTOK);
		      leading_zeroes = zeroes;
		      goto fok;
		    }
		  break;
		case 'e':
		case 'E':
		  if ((flags & (NDIGITS | EXPOK)) == EXPOK
		      || ((flags & EXPOK) && zeroes))
		    {
		      if (! (flags & DPTOK))
			{
			  exp_adjust = zeroes - leading_zeroes;
			  exp_start = p;
			}
		      flags =
			(flags & ~(EXPOK | DPTOK)) |
			SIGNOK | NDIGITS;
		      zeroes = 0;
		      goto fok;
		    }
		  break;
		}
	      break;
	    fok:
	      *p++ = c;
	      width--;
	    fskip:
              ++nread;
	      if (--fp->_r > 0)
		fp->_p++;
	      else
	      if (__srefill (fp))
		break;
	    }
	  if (zeroes)
	    flags &= ~NDIGITS;
	  if (flags & NDIGITS)
	    {
	      if (flags & EXPOK)
		{
		  while (p > buf)
                    {
		      ungetc (*(u_char *)-- p, fp);
                      --nread;
                    }
		  goto match_failure;
		}
	      c = *(u_char *)-- p;
              --nread;
	      if (c != 'e' && c != 'E')
		{
		  _CAST_VOID ungetc (c, fp);
		  c = *(u_char *)-- p;
                  --nread;
		}
	      _CAST_VOID ungetc (c, fp);
	    }
	  if ((flags & SUPPRESS) == 0)
	    {
	      double res;
	      long new_exp;

	      *p = 0;
	      if ((flags & (DPTOK | EXPOK)) == EXPOK)
		{
		  exp_adjust = zeroes - leading_zeroes;
		  new_exp = -exp_adjust;
		  exp_start = p;
		}
	      else if (exp_adjust)
		new_exp = atol (exp_start + 1) - exp_adjust;
	      if (exp_adjust)
		{
		  if (exp_start >= buf + sizeof (buf) - MAX_LONG_LEN)
		    exp_start = buf + sizeof (buf) - MAX_LONG_LEN - 1;
                 sprintf (exp_start, "e%ld", new_exp);
		}
	      res = atof (buf);
	      if (flags & LONG)
		{
		  dp = va_arg (ap, double *);
		  *dp = res;
		}
	      else if (flags & LONGDBL)
		{
		  ldp = va_arg (ap, _LONG_DOUBLE *);
		  *ldp = res;
		}
	      else
		{
		  flp = va_arg (ap, float *);
		  *flp = res;
		}
	      nassigned++;
	    }
	  break;
	}
	}
    }
input_failure:
  return nassigned ? nassigned : -1;
match_failure:
  return nassigned;
}
