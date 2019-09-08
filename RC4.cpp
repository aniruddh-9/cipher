#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<bits/stdc++.h>
using namespace std;
#define SIZE 256

int keylen;
int S[SIZE],T[SIZE];

void getInput(string&,vector<int>&);
void toBin(string&,string&);
void encipher(int [],string,vector<char>&);
void initialize(int[]);
void initPermutation();
void streamGenerate(vector<int>&,vector<int>&);
string XOR(string,string);
string hex2bin(string);
string bin2hex(string);
string toHex(string);
string toHex(int);
int hex_to_int(char);
int hex_to_ascii(char,char);
string fromHex(string);

string hex2bin(string str){ 
    unordered_map<char, string> bin; 
    bin['0']= "0000"; 
    bin['1']= "0001"; 
    bin['2']= "0010"; 
    bin['3']= "0011"; 
    bin['4']= "0100"; 
    bin['5']= "0101"; 
    bin['6']= "0110"; 
    bin['7']= "0111"; 
    bin['8']= "1000"; 
    bin['9']= "1001"; 
    bin['A']= "1010"; 
    bin['B']= "1011"; 
    bin['C']= "1100"; 
    bin['D']= "1101"; 
    bin['E']= "1110"; 
    bin['F']= "1111"; 
    string binary=""; 
    for(int i=0; i<str.size(); i++){ 
        binary+= bin[str[i]]; 
    } 
    return binary; 
} 

string bin2hex(string str){ 
    unordered_map<string, string> hex; 
    hex["0000"]= "0"; 
    hex["0001"]= "1"; 
    hex["0010"]= "2"; 
    hex["0011"]= "3"; 
    hex["0100"]= "4"; 
    hex["0101"]= "5"; 
    hex["0110"]= "6"; 
    hex["0111"]= "7"; 
    hex["1000"]= "8"; 
    hex["1001"]= "9"; 
    hex["1010"]= "A"; 
    hex["1011"]= "B"; 
    hex["1100"]= "C"; 
    hex["1101"]= "D"; 
    hex["1110"]= "E"; 
    hex["1111"]= "F"; 
    string hexa=""; 
    for(int i=0; i<str.length(); i+=4){ 
        string ch=""; 
        ch+= str[i]; 
        ch+= str[i+1]; 
        ch+= str[i+2]; 
        ch+= str[i+3]; 
        hexa+= hex[ch]; 
    } 
    return hexa; 
} 

string toHex(string inp){
    string op="";
    for(int i=0;i<inp.length();i++){
        int n = (int)inp[i];
        string s="";
        while(n!=0){
            int temp=n%16;
            if(temp<10)
                s.push_back((char)(temp+48));
            else
                s.push_back((char)(temp+55));
            n=n/16;
        }
        reverse(s.begin(),s.end());
        op+=s;
    }
    return op;
}

string toHex(int n) {    
    string a="";
    int i = 0; 
    while(n!=0) {    
        int temp  = 0; 
        char ch; 
        temp = n % 16; 
        if(temp < 10) { 
            ch=temp+48;
            a+=ch;
        } 
        else{ 
            ch=temp+55;
            a+=ch;
        }   
        n = n/16; 
    } 
    reverse(a.begin(),a.end());
    return a;
}

int hex_to_int(char c){
        int first = c / 16 - 3;
        int second = c % 16;
        int result = first*10 + second;
        if(result > 9) result--;
        return result;
}
int hex_to_ascii(char c, char d){
        int high = hex_to_int(c) * 16;
        int low = hex_to_int(d);
        return high+low;
}
string fromHex(string out){
    char buf;
    string plain;
    for(int i = 0; i < out.length(); i++){
                if(i % 2 != 0){
                        plain.push_back(hex_to_ascii(buf, out[i]));
                }else{
                        buf = out[i];
                }
        }
    return plain;
}

void getKey(vector<char>& keystr,vector<int>& key){
    cout<<"Enter Key: ";
    while(true){
        char ch;
        ch=getchar();
        if(ch=='\n')
            break;
        keystr.push_back(ch);
    }
    keylen=keystr.size();
    for(int i=0;i<keylen;i++)
        key.push_back((int)keystr[i]);
    }

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

void initialize(vector<int>& key){
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

void streamGenerate(string plainHex,vector<char>& cipher){
    int k;
    int i=0;
    int j=0;
    int cnt=0;
    while(cnt<plainHex.length()){
        i=(i+1)%SIZE;
        j=(j+S[i])%SIZE;
        swap(S[i],S[j]);
        k=S[(S[i]+S[j])%SIZE];
        string result = XOR(plainHex.substr(cnt,2),toHex(k));
        cipher.push_back(result[0]);
        cipher.push_back(result[1]);
        cnt+=2;
    }
}

string XOR(string a,string b){
    a=hex2bin(a);
    b=hex2bin(b);
    string result="";
    for(int i=0;i<8;i++){
        if(a[i]==b[i])
            result.append("0");
        else
            result.append("1");
    }
    result=bin2hex(result);
    return result;
}

void encipher(vector<int>& key,string input,vector<char>& cipher,bool decipher){
    initialize(key);
    initPermutation();
    if(decipher)
        streamGenerate(input,cipher);
    else
        streamGenerate(toHex(input),cipher);
}

void print(vector<char>& vec){
    for(int i=0;i<vec.size();i++)
        cout<<vec[i];
    cout<<endl;
}

int main(){
    string input,plainHex;
    vector<char> keystr,cipher,decipher;
    vector<int> plain,key;
    getKey(keystr,key);
    getInput(input,plain);
    encipher(key,input,cipher,false);
    cout<<"Cipher: ";
    print(cipher);
    encipher(key,string (cipher.begin(),cipher.end()),decipher,true);
    cout<<"Decipher: "<<fromHex(string (decipher.begin(),decipher.end()));
    cout<<endl;
    return 0;
}