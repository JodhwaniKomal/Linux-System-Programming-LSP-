/*Directory traversal : ls clone - prints name ,type,size and last modified time
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

void printFileType(mode_t mode)
{
    if(S_ISREG(mode))
        printf("File type:Regular file\n");     
    else if(S_ISDIR(mode))
        printf("File type:Directory File\n");      
    else if(S_ISLNK(mode))
        printf("File type:Symbolic link");     
    else if(S_ISCHR(mode))
        printf("File type:Character device\n");     
    else if(S_ISBLK(mode))
        printf("File type:Block device\n");      
    else if(S_ISFIFO(mode))
        printf("File type:Pipe file\n");      
    else if(S_ISSOCK(mode))
        printf("File type:Socket file\n");      
    else
        printf("File type:Unknown\n");     
}

int main(int argc,char *argv[])
{
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
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

        printf("Name of file :%s\n",ptr->d_name);
        printFileType(sobj.st_mode);
        printf("Size of file is :%ld\n",sobj.st_size);
        printf("File last modification time:%ld\n",sobj.st_mtime);

    }
    closedir(dp);


    return 0;
}