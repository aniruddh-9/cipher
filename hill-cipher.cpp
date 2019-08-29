#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


const char alphaIndex[26]=  {'A','B','C','D','E','F',
                            'G','H','I','J','K','L',
                            'M','N','O','P','Q','R',
                            'S','T','U','V','W','X',
                            'Y','Z'};

int key[3][3]= {2,3,4,
                9,6,1,
                9,6,4};

int inverse[3][3];
int flag=0;
int index;

void getInput(vector<char>&);
void print(vector<char>&);
void getNext(vector<char>&);
void generateVector(vector<char>&,vector<int>&);
int searchIndex(char);
void matrixMultiply(vector<int>&,vector<int>&,int[3][3]);
vector<char> getCipher(vector<int>&);
vector<char> encipher(vector<char>&);
void decipher(vector<char>&,vector<char>&);
void findinverse();

void modulo(int& a){
    while(a<0)
        a+=26;
    while(a>26){      //  modulo 26
        a%=26;
    }
}

void getInput(vector<char>& msg){
    char ch;
    cout<<"Enter the message: ";
    while(1){
        ch=getchar();
        if(ch>=97 && ch<=122)
            ch-=32;
       // else if(ch=='\t'||ch==' ');

        else if(ch=='\n')
            break;
       // else if(!(ch>=65 && ch<=90))
         //   continue;
        msg.push_back(ch);
    }
  /*  int i=0;
    int count=0;
    while(i<msg.size()){
        if(msg[i]==' ')
            count++;
        i++;
    }*/
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
       /* if(msg[index]==' '){
            count--;
            flag=1;
            continue;
        }*/
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

void matrixMultiply(vector<int>& vec,vector<int>& result,int key[3][3]){
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<3;j++){
            sum=sum+key[i][j]*vec[j];
        }
        modulo(sum);
        result.push_back(sum);
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
    for(index=0;index<msg.size();){
        vector<char> text;
        vector<int> vec;
        vector<int> result;
        getNext(msg,text);
        generateVector(text,vec);
        matrixMultiply(vec,result,key);
        partCipher = getCipher(result);
        for(int j=0;j<3;j++){
            cipher.push_back(partCipher[j]);
        }
    }
    index=0;
    return cipher;
}

void print(vector<char>& msg){
    for(int i=0;i<msg.size();i++){
        cout<<msg[i];
    }
    cout<<"\n";
    return;
}

int DetInverse(){
    int det=0;          // finding determinant
    for(int i=0;i<3;i++)
		det=det + (key[0][i] * (key[1][(i+1)%3] * key[2][(i+2)%3] - 
                   key[1][(i+2)%3] * key[2][(i+1)%3]));
    modulo(det);
    for(int i=1;i<26;i++){  // find det inverse
        if((det*i)%26 == 1 )
            return i;
    }
}

void findInverse(){
    int inv=DetInverse();
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            inverse[i][j]=((key[(j+1)%3][(i+1)%3] * key[(j+2)%3][(i+2)%3]) - (key[(j+1)%3][(i+2)%3] * key[(j+2)%3][(i+1)%3]));
            inverse[i][j]*=inv;
            modulo(inverse[i][j]);
        }
    }
}

void decipher(vector<char>& cipher,vector<char>& msgd){
    findInverse();
    vector<char> partDec;
    for(index=0;index<cipher.size();){
        vector<char> text;
        vector<int> vec;
        vector<int> result;
        getNext(cipher,text);
        generateVector(text,vec);
        matrixMultiply(vec,result,inverse);
        partDec = getCipher(result);
        for(int j=0;j<3;j++){
            msgd.push_back(partDec[j]);
        }
    }
}

int main(){
    vector<char> msg,msgx,cipher,msgd;
    getInput(msg);
    print(msg);
    cipher = encipher(msg);
    cout<<"Cipher: ";
    print(cipher);
    decipher(cipher,msgd);
    print(msgd);
    return 0;
}