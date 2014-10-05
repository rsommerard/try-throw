#include <stdio.h>

void* mebp;
void* mesp;

void* bebp;
void* besp;

void a();
void b();
void c();

void a()
{
    void* ebp;
    void* esp;
    int* ptr;

    asm("mov %%ebp, %0" : "=r" (ebp));
    asm("mov %%esp, %0" : "=r" (esp));

    ptr = (int*)mebp;

    printf("##Stack a##\n");

    do
    {
        if(ptr == (int*)mebp)
        {
            printf("\tmebp \t0x%p = 0x%0x\n", (void*)ptr, *ptr);
        }
        else if(ptr == (int*)mesp)
        {
           printf("\tmesp \t0x%p = 0x%0x\n", (void*)ptr, *ptr);
        }
        else if(ptr == (int*)ebp)
        {
            printf("\taebp \t0x%p = 0x%0x\n", (void*)ptr, *ptr);
        }
        else if(ptr == (int*)esp)
        {
            printf("\taesp \t0x%p = 0x%0x\n", (void*)ptr, *ptr);
        }
        else
        {
            printf("\t\t0x%p = 0x%0x\n", (void*)ptr, *ptr);
        }
    } while(ptr-- > (int*)esp);

    printf("###########\n");
}

void b()
{
    void* ebp;
    void* esp;
    int* ptr;

    asm("mov %%ebp, %0" : "=r" (ebp));
    asm("mov %%esp, %0" : "=r" (esp));

    bebp = ebp;
    besp = esp;

    ptr = (int*)mebp;

    printf("##Stack b##\n");

    do
    {
        if(ptr == (int*)mebp)
        {
            printf("\tmebp \t0x%p = 0x%0x\n", (void*)ptr, *ptr);
        }
        else if(ptr == (int*)mesp)
        {
           printf("\tmesp \t0x%p = 0x%0x\n", (void*)ptr, *ptr);
        }
        else if(ptr == (int*)ebp)
        {
            printf("\tbebp \t0x%p = 0x%0x\n", (void*)ptr, *ptr);
        }
        else if(ptr == (int*)esp)
        {
            printf("\tbesp \t0x%p = 0x%0x\n", (void*)ptr, *ptr);
        }
        else
        {
            printf("\t\t0x%p = 0x%0x\n", (void*)ptr, *ptr);
        }
    } while(ptr-- > (int*)esp);

    printf("###########\n");

    c();
}

void c()
{
    void* ebp;
    void* esp;
    int* ptr;

    asm("mov %%ebp, %0" : "=r" (ebp));
    asm("mov %%esp, %0" : "=r" (esp));

    ptr = (int*)mebp;

    printf("##Stack c##\n");

    do
    {
        if(ptr == (int*)mebp)
        {
            printf("\tmebp \t0x%p = 0x%0x\n", (void*)ptr, *ptr);
        }
        else if(ptr == (int*)mesp)
        {
           printf("\tmesp \t0x%p = 0x%0x\n", (void*)ptr, *ptr);
        }
        if(ptr == (int*)bebp)
        {
            printf("\tbebp \t0x%p = 0x%0x\n", (void*)ptr, *ptr);
        }
        else if(ptr == (int*)besp)
        {
           printf("\tbesp \t0x%p = 0x%0x\n", (void*)ptr, *ptr);
        }
        else if(ptr == (int*)ebp)
        {
            printf("\tcebp \t0x%p = 0x%0x\n", (void*)ptr, *ptr);
        }
        else if(ptr == (int*)esp)
        {
            printf("\tcesp \t0x%p = 0x%0x\n", (void*)ptr, *ptr);
        }
        else
        {
            printf("\t\t0x%p = 0x%0x\n", (void*)ptr, *ptr);
        }
    } while(ptr-- > (int*)esp);

    printf("###########\n");
}

int main()
{
    void* ebp;
    void* esp;
    int* ptr;

    asm("mov %%ebp, %0" : "=r" (ebp));
    asm("mov %%esp, %0" : "=r" (esp));

    mebp = ebp;
    mesp = esp;

    ptr = (int*)ebp;

    printf("##Stack main##\n");

    do
    {
        if(ptr == (int*)ebp)
        {
            printf("\tebp \t0x%p = 0x%0x\n", (void*)ptr, *ptr);
        }
        else if(ptr == (int*)esp)
        {
           printf("\tesp \t0x%p = 0x%0x\n", (void*)ptr, *ptr);
        }
        else
        {
            printf("\t\t0x%p = 0x%0x\n", (void*)ptr, *ptr);
        }
    } while(ptr-- > (int*)esp);

    printf("###########\n");

    a();
    b();

    return 0;
}
