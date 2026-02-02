/*Client program that accepts library path and function name using command line arguments
here: string.c library is used 
whatever the function returns is displayed by the program 
*/

#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

typedef int (*fp)(char *);

int main(int argc,char *argv[])
{
    void *handle = NULL;
    fp iRet = 0; 
    char carr[100]= {'\0'};
    char *cptr = carr;
    int ans = 0;

    handle = dlopen(argv[1],RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }

    printf("Enter string:\n");
    fgets(carr,sizeof(carr),stdin);

    iRet = (fp)dlsym(handle,argv[2]);

    if(iRet == NULL)
    {
        printf("Unable to get function address\n");
        dlclose(handle);
        return -1;
    }

    ans = iRet(cptr);

    printf("The function address is :%p\n",iRet);

    printf("Return value from the funstion %s is: %d\n",argv[2],ans);

    dlclose(handle);

    return 0;
}