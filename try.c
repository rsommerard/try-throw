#include <assert.h>
#include "try.h"

static int val;

int try(struct ctx_s *pctx, func_t *f, int arg)
{
    pctx->ctx_magic = CORRECTMAGIC;

    asm("mov %%esp, %0" "\n\t" "mov %%ebp, %1"
        : "=r" (pctx->ctx_esp), "=r" (pctx->ctx_ebp));

    return f(arg);
}

int throw(struct ctx_s *pctx, int r)
{
    assert(pctx->ctx_magic == CORRECTMAGIC);

    val = r;

    asm("mov %0, %%esp" "\n\t" "mov %1, %%ebp"
        :
        : "r" (pctx->ctx_esp), "r" (pctx->ctx_ebp));

    return val;
}
