/*Accepts a file name and reads till the end of the file
prints the total number of bytes read
*/
#include<stdio.h>
#include<fcntl.h>
#include<string.h>


int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        printf("Invaild Number of command line arguments\n");
        return -1;
    }
    int fd = 0;
    int iRet = 0;
    int iCount = 0;
    char Buffer[1024];

    memset(Buffer,'\0',sizeof(Buffer));
    fd = open(argv[1],O_RDONLY);
    if(fd < 0)
    {
        printf("Unable to open file");
        return -1;
    }
    printf("Data from the file is:\n");
    do
    {
        iRet = read(fd,Buffer,1024);
        printf("%s\n",Buffer);
        memset(Buffer,'\0',sizeof(Buffer));
        iCount = iCount + iRet;
    }while(iRet != 0);
    printf("Total bytes read:%d\n",iCount);
 
    return 0;
}