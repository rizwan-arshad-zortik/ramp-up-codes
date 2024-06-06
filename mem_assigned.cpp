#include <iostream>

void assignMem(char **arr);
int main()
{
    char *arr = nullptr;
    assignMem(&arr);
    std::cout<<"\nMem var after function call"<<arr<<std::endl;
    char ch = 'A';
    for (int i=0; i<10; i++)
    {
        arr[i] = ch + i;
    }
    for (int i=0; i<10; i++)
    {
        std::cout<<arr[i];
    }
    return 0;
}

void assignMem(char **arr)
{
    *arr = (char *) malloc(sizeof(char) * 10);
    std::cout<<"Mem Assigned "<< arr <<std::endl;
}
