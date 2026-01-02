/* Directory report : travels the whole dir counts no of regular files ,dir files
the total size and the largest file in the dir
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

int main(int argc,char *argv[])
{
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    int fcount = 0;
    int dcount = 0;
    int largest = 0,total = 0;
    char fname[256] = "\0";
    struct stat sobj;

    char fullPath[1024];


    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while(ptr = readdir(dp))
    {
        if(strcmp(ptr->d_name,".") == 0 || (strcmp(ptr->d_name,"..")==0))
        {
            continue;
        }
        snprintf(fullPath, sizeof(fullPath), "%s/%s", argv[1], ptr->d_name);

        stat(fullPath,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            fcount++;
            total = total + sobj.st_size;

            if(sobj.st_size > largest)
            {
                largest = sobj.st_size;
                strcpy(fname,ptr->d_name);
            }
        }
        else if(S_ISDIR(sobj.st_mode))
        {
            dcount++;
        }
    }
    printf("-----Directory Report-----\n");
    printf("Total number of files in directory:%d\n",fcount);
    printf("Total number of directories in the given directory:%d\n",dcount);
    printf("Total size:%d\n",total);
    printf("Largest file in the directory is %s and its size is:%d\n",fname,largest);

    closedir(dp);


    return 0;
}