#include <stdio.h>
#include <string.h>

#define MAXN 100
#define BASE 1000000007

int Decode( char NumStr[] );

int main()
{
    char NumStr[MAXN];

    scanf("%s", NumStr);
    printf("%d", Decode(NumStr));

    return 0;
}

int Decode(char NumStr[])
{
    int len=strlen(NumStr);
    int ret=0;
    int dp[MAXN] = {0};
    dp[len-1] = 1;
    if(NumStr[len-2]=='1' || (NumStr[len-2]=='2' && NumStr[len-1]<='6'))
        dp[len-2] = 2;
    else
        dp[len-2] = 1;
    for(int i=len-3;i>=0;i--)
    {
        if(NumStr[i]=='1' || (NumStr[i]=='2' && NumStr[i+1]<='6'))
            dp[i] = (dp[i+1]+dp[i+2])%BASE;
        else
            dp[i] = dp[i+1];
    }
    return dp[0];
    
}