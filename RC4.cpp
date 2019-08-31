#include<iostream>
#include<vector>
using namespace std;

int S[256],T[256];

void getInput();
void KSA();
void PRGA();
void encipher();
void initialize(int[],int);
void initPermutation();
void streamGenerate();

void swap(int& a,int& b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void initialize(int key[],int keylen){
    for(int i=0;i<256;i++){
        S[i]=i;
        T[i]=key[i%keylen];
    }
}

void initPermutation(){
    int j=0;
    for(int i=0;i<256;i++){
        j=(j+S[i]+T[i])%256;
        swap(S[i],S[j]);
    }
}

void streamGenerate(){
    int t;
    int i=0;
    int j=0;
    int k;
    while(true)
        i=(i+1)%256;
    j=(j+S[i])%256;
    swap(S[i],S[j]);
    t=(S[i]+S[j])%256;
    k=S[t];
}

int main(){
    int keylen;
    cout<<"Enter Key Length: ";
    cin>>keylen;
    int key[keylen];
    cout<<"Enter Key: ";
    for(int i=0;i<keylen;i++)
        cin>>key[i];
    initialize(key,keylen);
    initPermutation();
    streamGenerate();
    return 0;
}