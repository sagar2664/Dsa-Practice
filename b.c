#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);  
    
    char s[100];      
    scanf("%s", s);   

    int cnt = 0;
    for (int i = 0; i < strlen(s); i++)  
    {
        if (s[i] == '1')  
            cnt++;
    }

    if (cnt == 1)
        printf("True\n");  
    else
        printf("False\n"); 

    return 0;
}
