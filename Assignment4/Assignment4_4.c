/* Merge file utility: Accept a destinaton file and multiple other files 
copies all data from the other files in order they were given into the destination file.
*/
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>


int main(int argc,char *argv[])
{
    int fd1 = 0,fd2 = 0,fd3 = 0;
    int iRet = 0,iWrt = 0;
    char Buffer[1024];
    int numFiles = argc - 2;
    int fd[numFiles];
    
    memset(Buffer,'\0',sizeof(Buffer));

    fd[1] = open(argv[1],O_CREAT|O_WRONLY|O_APPEND,0777);

    if(fd[1] < 0)
    {
        printf("Error in destination file:%s\n",strerror(errno));
        return -1;
    }


    for(int i = 2; i < argc; i++)
    {
        fd[i] = open(argv[i], O_RDONLY);
        if(fd[i] < 0)
        {
            printf("Error opening %s: %s\n", argv[i+1], strerror(errno));
        }
        do
        {
        iRet = read(fd[i],Buffer,1024);
        iWrt = write(fd[1],Buffer,iRet);
        memset(Buffer,'\0',sizeof(Buffer));
        }while(iRet != 0);
        close(fd[i]);
    }
    printf("All files content is copied\n");
    close(fd[1]);

    return 0;
}