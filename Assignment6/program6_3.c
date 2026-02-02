//client program for Math.c library(dynamic linking)

#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

typedef int (*fp)(int,int);

int main()
{
    void *handle = NULL;
    fp fptr = NULL;
    char *err = NULL;
    char str[20] = {'\0'};
    int No1 = 0,No2 = 0;
    int Ans = 0;

    handle = dlopen("./libMath.so",RTLD_LAZY);
    if(handle == NULL)
    {
        fprintf(stderr,"Error is :%s\n",dlerror());
        return -1;
    }
    printf("Library gets loaded succesfully\n");
    printf("Choose the operation: Addition,Substraction,Multiplication,Division\n");
    printf("Also enter 2 numbers to perform the operation\n");
    scanf("%s\n",str);
    fptr = (fp)dlsym(handle,str);
    
    err = dlerror();

    if(err != NULL)
    {
        fprintf(stderr,"Error is :%s\n",err);
        dlclose(handle);
        return -1;
    }

    scanf("%d %d",&No1,&No2);

    Ans = fptr(No1,No2);

    printf("%s is :%d\n",str,Ans);

}   
