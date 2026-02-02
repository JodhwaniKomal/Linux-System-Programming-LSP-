int SumOfFactors(int No)
{
    int i = 0;
    int sum = 0;
    for(i = 1;i < No;i++)
    {
        if(No % i == 0)
        {
            sum = i + sum;
        }
    }
    if(sum == No)
    {
        return No;
    }
    else
    {
        return -1;
    }


}