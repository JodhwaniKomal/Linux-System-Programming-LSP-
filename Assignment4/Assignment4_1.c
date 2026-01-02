/* File Copy Utility: Copies all contents from source file to destination file
*/
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>


int main(int argc,char *argv[])
{
    int fd1 = 0,fd2 = 0;
    int iRet = 0,iWrt = 0;
    char Buffer[1024];

    memset(Buffer,'\0',sizeof(Buffer));

    fd1 = open(argv[1],O_RDONLY);
    if(fd1 < 0)
    {
        printf("Error in source file:%s\n",strerror(errno));
        return -1;
    }

    fd2 = open(argv[2],O_CREAT|O_WRONLY,0777);
    if(fd2 < 0)
    {
        printf("Error in destination file:%s\n",strerror(errno));
        return -1;
    }

    do
    {
        iRet = read(fd1,Buffer,1024);
        iWrt = write(fd2,Buffer,iRet);
        memset(Buffer,'\0',sizeof(Buffer));

    }while(iRet != 0);
    printf("All contents from source file are copired into the destination file\n");

    return 0;
}