struct reent_00123A28 { int _errno; };
int func_00123A28(struct reent_00123A28* ptr, const char* mode, int* optr)
{
  register int ret, m, o;

  switch (mode[0])
    {
    case 'r':
      ret = 0x0004;
      m = 0;
      o = 0;
      break;

    case 'w':
      ret = 0x0008;
      m = 1;
      o = 0x200 | 0x400;
      break;

    case 'a':
      ret = 0x0008 | 0x0100;
      m = 1;
      o = 0x200 | 0x8;
      break;

    default:
      ptr->_errno = 22;
      return (0);
    }
  if (mode[1] && (mode[1] == '+' || mode[2] == '+'))
    {
      ret = 0x0010;
      m = 2;
    }
  *optr = m | o;
  return ret;
}