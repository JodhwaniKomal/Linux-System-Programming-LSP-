/* Accepts file name from user and prints the content of file in reverse order on console
*/
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    int fd1 = 0;
    int iRet = 0;
    char ch = "\0";


    fd1 = open(argv[1],O_RDONLY);
    if(fd1 < 0)
    {
        printf("Error in file:%s\n",strerror(errno));
        return -1;
    }

    iRet = lseek(fd1,0,SEEK_END);
    if(iRet == -1)
    {
        printf("Error%s\n",strerror(errno));
    }
    for(int i = 1; i <= iRet; i++)
    {
        lseek(fd1, -i, SEEK_END);  
        read(fd1, &ch, 1);
        printf("%c", ch);
    }
    
    close(fd1);
    return 0;
}