#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{
    void *handle = NULL;
    int (*fp)(int,int);
    int iRet = 0; 
    char *cptr = NULL;

    handle = dlopen("libCustomLibrary.so",RTLD_LAZY);

    if(handle == NULL)
    {
        fprintf(stderr,"Error in loading the library is :%s\n",dlerror());
        return -1;
    }

    printf("Library gets loaded succesfully\n");

    dlerror();

    fp = (int(*)(int,int))dlsym(handle,"Maximum");
    cptr = dlerror();

    if(cptr != NULL)
    {
        fprintf(stderr,"Error in finding max number is :%s\n",cptr);
        dlclose(handle);
        return -1;

    }

    iRet = fp(110,40);

    printf("Maximum number is : %d\n",iRet);

    dlerror();

    fp = (int(*)(int,int))dlsym(handle,"Minimum");
    cptr = dlerror();

    if(cptr != NULL)
    {
        fprintf(stderr,"Error in finding the min number is :%s\n",cptr);
        dlclose(handle);
        return -1;

    }

    iRet = fp(25,5);

    printf("Minimum number is : %d\n",iRet);


    dlclose(handle);

    return 0;
}

