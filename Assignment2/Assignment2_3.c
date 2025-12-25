/* Accepts a directory name from user and prints all file names from that 
directory. (Skips . and ..)
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<dirent.h>


int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        printf("Invaild Number of command line arguments\n");
        return -1;
    }

    DIR *dp = NULL;
    int iRet = 0;
    struct dirent *ptr = NULL;

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory");
        return -1;
    }
     ptr = readdir(dp);

     while(ptr = readdir(dp))
     {
        if(strcmp(ptr->d_name,"..") == 0)
        {
            continue;
        }
        printf("%s\n",ptr->d_name);

     }
   
    close(dp);
    return 0;
}