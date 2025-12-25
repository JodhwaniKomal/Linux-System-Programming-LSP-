/* Copy's File contents from a source file to a destination file
creates the destination file if not already present
*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>


int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        printf("Invaild Number of command line arguments\n");
        return -1;
    }

    int fd1 = 0,fd2 = 0;
    int iRet = 0;
    int iWret = 0;
    char Buffer[1024] = "\0";
    struct stat sobj;
    int iCount = 0;

    fd1= open(argv[1],O_RDONLY);
    if(fd1 < 0)
    {
        printf("Unable to open source file\n");
        return -1;
    }

    fstat(fd1,&sobj);

    fd2 = open(argv[2],O_CREAT|O_WRONLY|O_TRUNC,sobj.st_mode);

    if(fd2 < 0)
    {
        printf("Unabe to open destination file\n");
        return -1;
    }

    do
    {
        iRet = read(fd1,Buffer,1024);
        iWret = write(fd2,Buffer,iRet);
        iCount = iCount + iWret;
    }while(iRet != 0);


    printf("Total number of bytes written in the destination file are:%d\n",iCount);

    close(fd1);
    close(fd2);


    return 0;
}