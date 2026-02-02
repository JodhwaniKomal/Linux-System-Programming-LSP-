//Client program 

#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{
    void *handle = NULL;
    int (*fp)(int,int);
    int iRet = 0; 

    handle = dlopen("./libServer1.so",RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }

    fp = (int(*)(int,int))dlsym(handle,"Addition");

    iRet = fp(100,50);

    printf("Addition is : %d\n",iRet);

    fp = (int(*)(int,int))dlsym(handle,"Substraction");

    iRet = fp(100,10);

    printf("Substraction is : %d\n",iRet);


    dlclose(handle);

    return 0;
}