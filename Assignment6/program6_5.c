#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{
    void *handle = NULL;
    int (*fp)(int,int);
    int iRet = 0; 
    char *cptr = NULL;

    handle = dlopen("./libMath.so",RTLD_NOW);

    if(handle == NULL)
    {
        fprintf(stderr,"Error in loading the library is :%s\n",dlerror());
        return -1;
    }

    printf("Library gets loaded succesfully\n");

    dlerror();

    fp = (int(*)(int,int))dlsym(handle,"Addition");
    cptr = dlerror();

    if(cptr != NULL)
    {
        fprintf(stderr,"Error is performing addition is :%s\n",cptr);
        dlclose(handle);
        return -1;

    }

    iRet = fp(110,40);

    printf("Addition is : %d\n",iRet);

    dlerror();

    fp = (int(*)(int,int))dlsym(handle,"Maximum");
    cptr = dlerror();

    if(cptr != NULL)
    {
        fprintf(stderr,"Error in finding the max number is :%s\n",cptr);
        dlclose(handle);
        return -1;

    }

    iRet = fp(25,5);

    printf("Maximum number is : %d\n",iRet);


    dlclose(handle);

    return 0;
}

//RTLD_NOW 