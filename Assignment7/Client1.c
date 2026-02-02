//Client program 

#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{
    void *handle = NULL;
    int (*fp)(int);
    int iRet = 0; 

    handle = dlopen("./libPerfect.so",RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }

    fp = (int(*)(int))dlsym(handle,"IsPerfect");

    iRet = fp(6);

    if(iRet != -1)
    {
        printf("%d is a perfect number\n",iRet);
    }
    else
    {
        printf("It is not a perfect number\n");
    }

    dlclose(handle);

    return 0;
}