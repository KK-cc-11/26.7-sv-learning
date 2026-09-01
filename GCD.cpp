#include<iostream>
#include<cstdlib>
using namespace std;

int findGCD(int a, int b){
    if (a==0){
        return b;
    }
    return findGCD(b%a, a);
}

// extended Euclidean Algorithm

// how to prove this algorithm is valid?

// ax+by = gcd -> (b%a)x1+ay1 = gcd right? -> b%a = (b-floor(b/a)·a) -> then formulate the equation can get the result between x,y and x1,y1

int gcdExtended(int a,int b,int &x,int &y){
    if (a == 0){
        x = 0;
        y = 1;
        return b;
    }
    int x1,y1;
    int gcd = gcdExtended(b%a,a,x1,y1);
    
    // how to memorize this equation?
    
    // directly, considering the other equation -> b%a = b-floor(b/a)*a and make a extension of the original one I think is the best solution to figure out this equation
    
    x = y1-(b/a)*x1;
    y = x1;
    return gcd;
}


// My Practice of this Extended Algorithm
int gcdExtendedPra(int a, int b, int &x,int &y){
    if (a==0){
        x=0,y=1;
        return b;
    }
    int x1,y1;
    int gcd = gcdExtended((b%a),a,x1,y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return gcd;
}

// Can be used to deal with long size integer

int boolGCD(int a, int b){
    if (b==0){
        return a;
    }
    if (a==0){
        return b;
    }
    if ((a&1)==0 && (b&1)==0){
        return (2 * boolGCD(a/2,b/2));
    }
    if ((a&1)==0 && b&1){
        return boolGCD(a/2,b);
    }
    if (a&1 && (b&1)==0){
        return boolGCD(a,b/2);
    }
    else{
        return boolGCD(abs(a-b)/2,min(a,b));
    }
}
// LCM can produce by getting the GCD of something
int lcm(int a, int b){
    if(a==0||b==0){
        return 0;
    }
    return abs(a/boolGCD(a,b)*b);
}

int main(){
    int a = 48, b =  20;
    int g = boolGCD(a,b);
    cout<<g<<endl;
    return 0;
}