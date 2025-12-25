/*Accepts a directory name and a file name and checks if that file is 
present in that directory and returns its absolute path
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
    if(argc != 3)
    {
        printf("Invaild Number of command line arguments\n");
        return -1;
    }

    int iRet = 0;
    DIR *dp = NULL;
    struct dirent *ptr;
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
        if(strcmp(ptr->d_name,argv[2]) == 0)
        {
            printf("The file exists in the directory\n");
            realpath(ptr->d_name,Buffer);
            printf("Its absolute path is:%s\n",Buffer);
            break;
        }
    }

    closedir(dp);

    return 0;
}