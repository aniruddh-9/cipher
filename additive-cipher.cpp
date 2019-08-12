#include<iostream>
#include<vector>
using namespace std;

int key = -2;

void getInput(vector<char>&);
void encipher(vector<char>&,vector<char>&);
void decipher(vector<char>&,vector<char>&);
void print(vector<char>&);

void getInput(vector<char>& msg){
    char ch;
    cout<<"Enter the Message: ";
    while(1){
        ch=getchar();
        if(ch=='\n')
            break;
        msg.push_back(ch);
    }
    return;
}

void encipher(vector<char>& msg,vector<char>& cipher){
    for(int i=0;i<msg.size();i++){
        cipher.push_back(msg[i]+key);
    }
}

void decipher(vector<char>& cipher,vector<char>& msgd){
    for(int i=0;i<cipher.size();i++){
        msgd.push_back(cipher[i]-key);
    }
}

void print(vector<char>& msg){
    for(int i=0;i<msg.size();i++){
        cout<<msg[i];
    }
    cout<<'\n';
    return;
}
int main(){
    vector<char> msg,cipher,msgd;
    getInput(msg);
    encipher(msg,cipher);
    cout<<"Cipher: ";
    print(cipher);
    decipher(cipher,msgd);
    cout<<"Deciphered Message: ";
    print(msgd);
    return 0;
}