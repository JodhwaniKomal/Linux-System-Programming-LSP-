/*Accepts a directory name and delets all files with 0 size
and prints the number of files deleted
*/
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<dirent.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>


int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        printf("Invaild Number of command line arguments\n");
        return -1;
    }

    int iRet = 0;
    DIR *dp = NULL;
    struct dirent *ptr;
    int iCount = 0;
    char Buffer[256] = "\0";

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        printf("%s\n",strerror(errno));
        return -1;
    }

    ptr = readdir(dp);
    while(ptr = readdir(dp))
    {
        if(ptr->d_reclen == 0)
        {
            realpath(ptr->d_name,Buffer);
            iRet = remove(Buffer);
            if(iRet == 0)
            {
                iCount++;
            }
        }
    }
    printf("The number of files deleted are:%d\n",iCount);

    closedir(dp);

    return 0;
}