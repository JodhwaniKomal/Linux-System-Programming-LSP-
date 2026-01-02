/* File copy with offset: Accepts a source file destination file and offset
copes from the offset provided to the end of file into the destination file
*/
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    int fd1 = 0,fd2 = 0;
    int iRet = 0,iWrt = 0;
    int offset = atoi(argv[3]);
    int ret = 0;
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

    ret = lseek(fd1,offset,SEEK_SET);
    if(ret == -1)
    {
        printf("Error%s\n",strerror(errno));
    }

    do
    {
        iRet = read(fd1,Buffer,1024);
        iWrt = write(fd2,Buffer,iRet);
        memset(Buffer,'\0',sizeof(Buffer));

    }while(iRet != 0);
    printf("All contents from source file are copired into the destination file from the given offset\n");

    return 0;
}