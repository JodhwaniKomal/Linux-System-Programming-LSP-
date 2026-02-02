//Client program that

#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{
    void *handle = NULL;
    int (*fp)(char *);
    char carr[100] = {'\0'};
    char *cptr = carr;
    int ans = 0;

    printf("Enter string:\n");
    fgets(carr,sizeof(carr),stdin);

    handle = dlopen("./libmystring.so",RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }

    fp = (int(*)(char *))dlsym(handle,"MyStrlen");
    ans = fp(cptr);

    if(ans == 0)
    {
        printf("No string was entered\n");
    }
    else
    {
        printf("The length of the entered string is :%d\n",ans);
    }

    dlclose(handle);

    return 0;
}