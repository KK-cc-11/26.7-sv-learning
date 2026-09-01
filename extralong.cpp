#include<bits/stdc++.h>
using namespace std;
void extraLong(string str1,string str2){
    // first, deal with the strings
    int i;
    int *num1, *num2;
    int maxLen = (str1.size() > str2.size())?str1.size():str2.size();
    if(str1.size()>str2.size()){
        num1 = new int[str1.size()],num2 = new int[str2.size()];
        for(i = 0;i<str1.size();i++) num1[i] = str1[str1.size()-i-1] - '0';
        for(i = 0;i<str2.size();i++) num2[i] = str2[str2.size()-i-1] - '0';
    }
    else{
        num1 = new int[str2.size()],num2 = new int[str1.size()];
        for(i = 0;i<str1.size();i++) num1[i] = str2[str2.size()-i-1] - '0';
        for(i = 0;i<str2.size();i++) num2[i] = str1[str1.size()-i-1] - '0';
    }
    
    // Sum

    int sum[maxLen+1];
    memset(sum,0,sizeof(sum));
    for(i=0;i<maxLen;i++) sum[i] = num1[i]+num2[i];
    for(i=0;i<maxLen;i++){
        sum[i+1]+=sum[i]/10;
        sum[i]%=10;
    }

    // Tricky triffle

    if(sum[maxLen]==1) cout<<"1";
    
    for(int i = 0;i<maxLen;i++) cout<<sum[maxLen-i-1];
    cout << endl;

    // Subtraction
    
    int sub[maxLen+1];
    memset(sub,0,sizeof(sub));
    for(i=0;i<maxLen;i++){
        if(num1[i]<num2[i]){
            num1[i+1]--;
            num1[i]+=10;
        }
        sub[i]=num1[i]-num2[i];
    }

    // Multiplication
    int maxLenMul = str1.size()+str2.size();
    int mul[maxLenMul+1];
    memset(mul,0,sizeof(mul));
    for(i=0;i<str2.size();i++){
        for(int j = 0;j<str1.size();j++){
            mul[i+j]+=num2[i]*num1[j];
        }
    }
    for(i=0;i<maxLenMul;i++){
        mul[i+1]+=mul[i]/10;
        mul[i]%=10;
    }
    for(int i = 0;i<maxLenMul;i++){
        cout<<mul[maxLenMul-i-1];
    }
}