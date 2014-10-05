#ifndef _TRY_H_
#define _TRY_H_

#define CORRECTMAGIC 0xDEADBEEF

typedef int (func_t)(int);

struct ctx_s
{
    void* ctx_esp;
    void* ctx_ebp;
    int ctx_magic;
};

int try(struct ctx_s *pctx, func_t *f, int arg);

int throw(struct ctx_s *pctx, int r);

#endif
