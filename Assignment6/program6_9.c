//Client program 

#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

typedef int (*fp)(char *);

int main()
{
    void *handle = NULL;
    fp arr[5] = {'\0'}; 
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

    arr[0] = (fp)dlsym(handle,"UpperCase");

    ans = arr[0](cptr);

    printf("The function address is :%p\n",arr[0]);

    printf("Count of uppercase alphabets is : %d\n",ans);

    arr[1] = (fp)dlsym(handle,"LowerCase");

    ans = arr[1](cptr);

    printf("The function address is :%p\n",arr[1]);

    printf("Count of lowercase alphabets is : %d\n",ans);

    arr[2] = (fp)dlsym(handle,"Numbers");

    ans = arr[2](cptr);

    printf("The function address is :%p\n",arr[2]);

    printf("Count of numbers is : %d\n",ans);

    dlclose(handle);

    return 0;
}