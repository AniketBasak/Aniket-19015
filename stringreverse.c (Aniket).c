#include<stdio.h>
#include<stdlib.h>

int main()
{
    char str[100], rev[100];
    int n,i;
    printf("Kindly enter the string you want to reverse\n");
    scanf("%s", &str);
    for(n=0; str[n]!='\0'; ++n);
    for(i=0; i<n; i++)
    {
        rev[i]=str[n-i-1];
    }
    rev[i]='\0';

    printf("The reversed string is: %s\n",rev);
    return 0;

}