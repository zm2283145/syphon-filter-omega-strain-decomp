struct siov_00124C58 { const void* iov_base; unsigned int iov_len; };
struct suio_00124C58 { struct siov_00124C58* uio_iov; int uio_iovcnt; int uio_resid; };
extern int __sfvwrite(void* fp, struct suio_00124C58* uio);
unsigned int func_00124C58(const void* buf, unsigned int size, unsigned int count, void* fp)
{
  unsigned int n;
  struct suio_00124C58 uio;
  struct siov_00124C58 iov;

  iov.iov_base = buf;
  uio.uio_resid = iov.iov_len = n = count * size;
  uio.uio_iov = &iov;
  uio.uio_iovcnt = 1;

  if (__sfvwrite(fp, &uio) == 0)
    return count;
  return (n - uio.uio_resid) / size;
}