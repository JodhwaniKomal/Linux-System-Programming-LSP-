//Client program that links two different libraries libaddition.so and libsubstraction.so

#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{
    void *handle1 = NULL;
    void *handle2 = NULL;
    int (*fp)(int,int);
    int iRet = 0; 

    handle1 = dlopen("./libaddition.so",RTLD_LAZY);

    if(handle1 == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }

    handle2 = dlopen("./libsubstraction.so",RTLD_LAZY);

    if(handle2 == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }


    fp = (int(*)(int,int))dlsym(handle1,"Addition");

    iRet = fp(100,50);

    printf("Addition is : %d\n",iRet);

    fp = (int(*)(int,int))dlsym(handle2,"Substraction");

    iRet = fp(100,10);

    printf("Substraction is : %d\n",iRet);


    dlclose(handle1);
    dlclose(handle2);

    return 0;
}