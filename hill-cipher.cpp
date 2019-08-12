#include<iostream>
#include<vector>
using namespace std;


const char alphaIndex[26]={'A','B','C','D','E','F',
                            'G','H','I','J','K','L',
                            'M','N','O','P','Q','R',
                            'S','T','U','V','W','X',
                            'Y','Z'};

const int key[3][3]={2,51,19,
                    18,32,4,
                    6,21,102};


int index;

void getInput(vector<char>&);
void print(vector<char>&);
void getNext(vector<char>&);
void generateVector(vector<char>&,vector<int>&);
int searchIndex(char);
void matrixMultiply(vector<int>&,vector<int>&);
vector<char> getCipher(vector<int>&);
vector<char> encipher(vector<char>&);

void getInput(vector<char>& msg){
    char ch;
    cout<<"Enter the message: ";
    while(1){
        ch=getchar();
        if(ch>=97 && ch<=122)
            ch-=32;
        else if(ch=='\t'||ch==' ');

        else if(ch=='\n')
            break;
        else if(!(ch>=65 && ch<=90))
            continue;
        msg.push_back(ch);
    }
    if(msg.size()%3){
        if(msg.size()%3==1){
            msg.push_back('Q');
            msg.push_back('Q');
        }
        else
            msg.push_back('Q');
    }
    else
        return;
    return;
}

void getNext(vector<char>& msg,vector<char>& text){
    for(int count=0;count<3;count++){
        text.push_back(msg[index++]);
    }
}

void generateVector(vector<char>& text,vector<int>& vec){
    for(int i=0;i<3;i++){
        vec.push_back(searchIndex(text[i]));
    }
}

int searchIndex(char ch){
    int i;
    for(i=0;i<26;i++){
        if(ch==alphaIndex[i])
            break;
    }
    return i;
}

void matrixMultiply(vector<int>& vec,vector<int>& result){
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<3;j++){
            sum=sum+key[i][j]*vec[j];
        }
        result.push_back(sum%26);
    }
}

vector<char> getCipher(vector<int>& result){
    vector<char> ciph;
    for(int i=0;i<3;i++){
        ciph.push_back(alphaIndex[result[i]]);
    }
    return ciph;
}


vector<char> encipher(vector<char>& msg){
    vector<char> cipher,partCipher;
    for(index=0;index<msg.size();index++){
        vector<char> text;
        vector<int> vec;
        vector<int> result;
        getNext(msg,text);
        generateVector(text,vec);
        matrixMultiply(vec,result);
        partCipher = getCipher(result);
        for(int j=0;j<3;j++){
            cipher.push_back(partCipher[j]);
        }
    }
    return cipher;
}

void print(vector<char>& msg){
    for(int i=0;i<msg.size();i++){
        cout<<msg[i];
    }
    cout<<"\n";
    return;
}

int main(){
    vector<char> msg,msgx,cipher;
    getInput(msg);
    print(msg);
    cipher = encipher(msg);
    cout<<"Cipher: ";
    print(cipher);
    return 0;
}