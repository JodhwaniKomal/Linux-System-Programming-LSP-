/* Accepts a directory name from user and prints all file names with file type
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<dirent.h>


int main(int argc,char *argv[])
{
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
        printf("%s:",ptr->d_name);

        if(ptr->d_type == DT_BLK)
        {
            printf("Block Device\n");
        }
        else if(ptr->d_type == DT_REG)
        {
            printf("Regular file\n");
        }
        else if(ptr->d_type == DT_CHR)
        {
            printf("Character file\n");
        }
        else if(ptr->d_type == DT_DIR)
        {
            printf("Directory file\n");
        }
        else if(ptr->d_type == DT_FIFO)
        {
            printf("Named pipe file\n");
        }
        else if(ptr->d_type == DT_LNK)
        {
            printf("Symbolic link file\n");
        }
        else
        {
            printf("Unknown file\n");
        }

     }
   
    close(dp);
    return 0;
}