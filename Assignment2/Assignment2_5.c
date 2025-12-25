/* Accepts directory name and prints the largest file name and bytes(size)
working on current directory (for regular files only)
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<dirent.h>
#include<sys/stat.h>


int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        printf("Invaild Number of command line arguments\n");
        return -1;
    }

    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    struct stat sobj;
    long int file_size = 0;
    char fname[1024] = "\0";


    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory");
        return -1;
    }

     while(ptr = readdir(dp))
     {
        if(strcmp(ptr->d_name,"..") == 0)
        {
            continue;
        }
        stat(ptr->d_name,&sobj);

        if((sobj.st_size > file_size)&& (S_ISREG(sobj.st_mode)))
        {
            file_size = sobj.st_size;
            strcpy(fname,ptr->d_name);
        }

     }
     printf("Largest file name:%s\n",fname);
     printf("Its size in bytes:%ld\n",file_size);
   
    close(dp);
    return 0;
}