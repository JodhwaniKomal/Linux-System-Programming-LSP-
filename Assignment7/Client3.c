//Client program that accept string from user calls display function from display library 
//and prints on screen

#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{
    void *handle = NULL;
    void (*fp)(char *);
    char carr[100] = {'\0'};
    char *cptr = carr;

    printf("Enter string:\n");
    fgets(carr,sizeof(carr),stdin);

    handle = dlopen("./libdisplay.so",RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }

    fp = (void(*)(char *))dlsym(handle,"Display");
    fp(cptr);
    dlclose(handle);

    return 0;
}