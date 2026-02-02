#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{
    void *handle = NULL;
    int (*fp)(int,int);
    int iRet = 0; 
    char *cptr = NULL;

    handle = dlopen("./libServer1.so",RTLD_LAZY);

    if(handle == NULL)
    {
        fprintf(stderr,"Error is :%s\n",dlerror());
        return -1;
    }

    printf("Library gets loaded succesfully\n");

    dlerror();;

    fp = (int(*)(int,int))dlsym(handle,"Addition");
    cptr = dlerror();

    if(cptr != NULL)
    {
        fprintf(stderr,"Error is :%s\n",cptr);
        dlclose(handle);
        return -1;

    }

    iRet = fp(11,10);

    printf("Addition is : %d\n",iRet);

    dlerror();

    fp = (int(*)(int,int))dlsym(handle,"Substraction");
    cptr = dlerror();

    if(cptr != NULL)
    {
        fprintf(stderr,"Error is :%s\n",cptr);
        dlclose(handle);
        return -1;

    }

    iRet = fp(11,10);

    printf("Substraction is : %d\n",iRet);


    dlclose(handle);

    return 0;
}