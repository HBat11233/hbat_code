#include<iostream> 
#include<cstdlib> 
#include<stdio.h> 
#define ll long long 
using namespace std; 
ll a[31]; 
int main() 
{ 
    ll n; 
    a[0]=1;a[2]=3; 
    for(int i=4;i<=30;i+=2) 
    a[i]=4*a[i-2]-a[i-4]; 
    while(scanf("%lld",&n)) 
    { 
        if(n==-1) break; 
        printf("%lld\n",a[n]); 
    } 
} 