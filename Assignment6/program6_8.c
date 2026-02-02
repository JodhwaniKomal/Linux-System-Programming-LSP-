//Client program 

#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

typedef int (*fp)(char *);

int main()
{
    void *handle = NULL;
    fp iRet = 0; 
    char carr[100]= {'\0'};
    char *cptr = carr;
    int ans = 0;

    handle = dlopen("./libstring.so",RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }

    printf("Enter string:\n");
    fgets(carr,sizeof(carr),stdin);

    iRet = (fp)dlsym(handle,"UpperCase");

    ans = iRet(cptr);

    printf("Count of uppercase alphabets is : %d\n",ans);

    iRet = (fp)dlsym(handle,"LowerCase");

    ans = iRet(cptr);

    printf("Count of lowercase alphabets is : %d\n",ans);

    iRet = (fp)dlsym(handle,"Numbers");

    ans = iRet(cptr);

    printf("Count of numbers is : %d\n",ans);

    dlclose(handle);

    return 0;
}