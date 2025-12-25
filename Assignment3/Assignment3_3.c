/* Accepts source and destination directory and copys all files from source
to destination directory
*/

#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>


int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        printf("Invaild Number of command line arguments\n");
        return -1;
    }
    
    int iRet = 0;
    DIR *dp1 = NULL;
    DIR *dp2 = NULL;
    int iCount = 0;
    char Buffer[256] = "\0";
    char *path = NULL;

    struct dirent *ptr;

    dp1 = opendir(argv[1]);
    if(dp1 == NULL)
    {
        printf("Unable to open directory\n");
        printf("%s\n",strerror(errno));
        return -1;
    }

    dp2 = opendir(argv[2]);

    ptr = readdir(dp1);
    while(ptr = readdir(dp1))
    {
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
        continue;

        path = realpath(ptr->d_name,Buffer);

        iRet = rename(Buffer,argv[2]);
        if(iRet == 0)
        {
            iCount++;
        }
    }
    printf("Total files moved:%d\n",iCount);

    closedir(dp1);
    closedir(dp2);

    return 0;
}