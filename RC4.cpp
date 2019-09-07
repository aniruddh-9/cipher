#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
// 8 x 8 bit

#define SIZE 256
#define keylen 8

int S[SIZE],T[SIZE];

void getInput(string&,vector<int>&);
void toBin(string&,string&);
//string encipher(string);
void initialize(int[]);
void initPermutation();
void streamGenerate(vector<int>&,vector<int>&);
string XOR(int,int);
string inBinary(char a);

/*void getInputKey(vector<int>& key,int& keylen){
    int input;
    cout<<"Enter Key: ";
    while (cin >> input)
        key.push_back(input);
    keylen=key.size();
    return;
}*/

void getInput(string& input,vector<int>& plain){
    cout<<"Enter the message: ";
    getline(cin,input);
    for(int i=0;i<input.length();i++)
        plain.push_back((int)input[i]);
}

void swap(int& a,int& b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void initialize(int key[]){
    for(int i=0;i<SIZE;i++){
        S[i]=i;
        T[i]=key[i%keylen];
    }
}

void initPermutation(){
    int j=0;
    for(int i=0;i<SIZE;i++){
        j=(j+S[i]+T[i])%SIZE;
        swap(S[i],S[j]);
    }
}

int toDec(string s){
    int num=0;
    int i=0;
    while(i<8){
        num=num+pow(2,s.length()-i-1)*((int)s[i]-48);
        i++;
    }
    return num;
}

void streamGenerate(vector<int>& plain,vector<int>& cipher){
    int k;
    int index=0;
    int i=0;
    int j=0;
    while(i<keylen){
        i=(i+1)%SIZE;
        j=(j+S[i])%SIZE;
        swap(S[i],S[j]);
        k=S[(S[i]+S[j])%SIZE];
        string a=XOR(plain[i-1],k);
        cipher.push_back(toDec(a));
    }
}

string inBinary(int a){
    int temp=a;
   // cout<<temp<<"\n";
    string binary="";
    while(temp){
        binary+=(char)(temp%2)+48;
        temp=temp/2;
    }
    while(binary.length()!=keylen)
        binary+='0';
    for(int i=0;i<binary.length()/2;i++)
        swap(binary[i],binary[binary.length()-1-i]);
    return binary;
} 


string XOR(int a,int b){
    int temp;
    int k=0;
    string str1,str2;
    string str3="";
    str1=inBinary(a);
    str2=inBinary(b);
    for(int i=0;i<keylen;i++){
        if(str1[k]==str2[k])
            str3.append("0");
        else
            str3.append("1");
        k++;
    }
    return str3;
}


/*void toBin(string& input,string& plain){
    for(int i=0;i<input.length();i++)
        plain+=inBinary(input[i]);
}
*/
int main(){
    string input;
    vector<int> plain,cipher;
    int key[keylen]={18,120,7,65,0,203,8,4};
    getInput(input,plain);
    initialize(key);
    initPermutation();
    streamGenerate(plain,cipher);
    for(int i=0;i<cipher.size();i++)
        cout<<cipher[i]<<"\t";
    cout<<endl;
    return 0;
}