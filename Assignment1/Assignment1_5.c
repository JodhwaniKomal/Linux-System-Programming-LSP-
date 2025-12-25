/* Accept file name and number of bytes(N) from user
read those many number of bytes from the file and print 
*/

#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc,char *argv[])
{
    int fd = 0;
    char Buffer[1024];
    int iRet = 0;

    memset(Buffer,'\0',sizeof(Buffer));

    fd = open(argv[1],O_RDONLY);
    if(fd < 0)
    {
        printf("Unable to open file\n");
        printf("%s\n",strerror(errno));
        return -1;
    }
    iRet = read(fd,Buffer,argv[2]);
    printf("data from file is :%s\n",Buffer);

    close(fd);
    return 0;
}