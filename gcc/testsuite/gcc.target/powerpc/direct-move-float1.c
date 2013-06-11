/* { dg-do compile { target { powerpc*-*-linux* && lp64 } } } */
/* { dg-skip-if "" { powerpc*-*-darwin* } { "*" } { "" } } */
/* { dg-skip-if "" { powerpc*-*-*spe* } { "*" } { "" } } */
/* { dg-require-effective-target powerpc_p8vector_ok } */
/* { dg-options "-mcpu=power8 -O2" } */
/* { dg-final { scan-assembler-times "mtvsrd" 2 } } */
/* { dg-final { scan-assembler-times "mfvsrd" 2 } } */
/* { dg-final { scan-assembler-times "xscvdpspn" 2 } } */
/* { dg-final { scan-assembler-times "xscvspdpn" 2 } } */

/* Check code generation for direct move for long types.  */

#define TYPE float
#define IS_FLOAT 1
#define NO_ALTIVEC 1

#include "direct-move.h"
