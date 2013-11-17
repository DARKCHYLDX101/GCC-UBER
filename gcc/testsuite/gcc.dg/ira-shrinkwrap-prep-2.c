/* { dg-do compile { target { x86_64-*-* && lp64 } } } */
/* { dg-options "-O3 -fdump-rtl-ira -fdump-rtl-pro_and_epilogue"  } */

int __attribute__((noinline, noclone))
foo (int a)
{
  return a + 5;
}

static int g;

int __attribute__((noinline, noclone))
bar (int a)
{
  int r;

  if (a)
    {
      r = a;
      while (r < 500)
	if (r % 2)
	  r = foo (r);
	else
	  r = foo (r+1);
      g = r + a;
    }
  else
    r = g+1;
  return r;
}

/* { dg-final { scan-rtl-dump "Will split live ranges of parameters" "ira"  } } */
/* { dg-final { scan-rtl-dump "Split live-range of register" "ira"  } } */
/* { dg-final { scan-rtl-dump "Performing shrink-wrapping" "pro_and_epilogue"  } } */
/* { dg-final { cleanup-rtl-dump "ira" } } */
/* { dg-final { cleanup-rtl-dump "pro_and_epilogue" } } */
