int UpperCase(char *str)
{
    int Count = 0;
    int i = 0;

    for(i = 0;str[i] != '\0';i++)
    {
        if((str[i] >= 'A') && (str[i] <= 'Z'))
        {
            Count++;
        }
    }
    return Count;
    
}

int LowerCase(char *str)
{
    int Count = 0;
    int i = 0;

    for(i = 0;str[i] != '\0';i++)
    {
        if((str[i] >='a') && (str[i] <='z'))
        {
            Count++;
        }
    }
    return Count;
    
}

int Numbers(char *str)
{
    int Count = 0;
    int i = 0;

    for(i = 0;str[i] != '\0';i++)
    {
        if((str[i] >= '0') && (str[i] <= '9'))
        {
            Count++;
        }
    }
    return Count;
    
}