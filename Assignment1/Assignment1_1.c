/* Accept file name and open the file and print success message and print fd
*/

#include<stdio.h>
#include<errno.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        printf("Invaild Number of command line arguments\n");
        return -1;
    }

    int fd = 0;
    fd = open(argv[1],O_CREAT|O_RDONLY);

    if(fd == -1)
    {
        perror("Error message");
    }
    else
    {
        printf("File opened succesfully with fd:%d\n",fd);
    }

    close(fd);
    return 0;
}

