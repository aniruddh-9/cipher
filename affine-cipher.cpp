#include<iostream>
#include<vector>
using namespace std;

void getInput(vector<char>&);
void crypt(char,vector<char>&);
void encipher(vector<char>&,vector<char>& );
void decrypt(char,vector<char>&,int,int,int);
vector<char> decipher(vector<char>&,vector<char>&,int,int,int);
void print(vector<char>&);
int findInverse(int);
void bruteForce(vector<char>& cipher);
bool isGCD(int);
int GCD(int,int);
void knownplaintext(vector<char>&,vector<char>&);
void negativeModulo(int&);
void fractionModulo(int&,int&);

int key1=11;
int key2=20;
const int m=26;
int flag=0;

void encipher(vector<char>& msg,vector<char>& cipher){
    for(int i=0;i<msg.size();i++){
        crypt(msg[i],cipher);
    }
}

vector<char> decipher(vector<char>& cipher,int key1,int key2){
    vector<char> msgd;
    int inv;
    inv = findInverse(key1);
    for(int i=0;i<cipher.size();i++){
        decrypt(cipher[i],msgd,key1,key2,inv);
    }
    return msgd;
}

void getInput(vector<char>& msg){
    char ch;
    while(1){
        ch=getchar();
        if(ch=='\n')
            break;
        else if(ch>=97 && ch<=122)
            ch-=32;
        msg.push_back(ch);
    }
}

void print(vector<char>& msg){
    for(int i=0;i<msg.size();i++){
        cout<<msg[i];
    }
    cout<<"\n";
}

void crypt(char ch,vector<char>& cipher){
    int c,ci;
    if(!(ch==' ')){
        c= (int)ch - 65;
        ci = key1*c + key2 % 26;
        ci = ci%26;
        ch = (char)ci+65;
    }
    else{
        cipher.push_back(' ');
        return;
    }
    cipher.push_back(ch);
    return;
}

void decrypt(char ch,vector<char>& msgd,int key1,int key2,int inv){
    int dec,temp;
    if(ch==' '){
        msgd.push_back(' ');
        return;
    }
    temp = ch-65-key2;
    if(temp<0){
        temp+=26;
    }
    dec = inv*temp%26;
    dec+=65;
    ch = (char)dec;
    msgd.push_back(ch);   
}

int findInverse(int a){
    for(int i=1;i<26;i++){
        if((a*i)%26 == 1 )
            return i;
    }
}
int GCD(int i,int j){
    if(i==0)
        return j;
    return GCD(j%i,i);
}

bool isGCD(int i){
    if(GCD(i,26)==1)
        return true;
    return false;
}

void bruteForce(vector<char>& msg,vector<char>& cipher){
    int i,j;
    for(int i=1;i<=26;i++){
        if(isGCD(i)){
            for(int j=1;j<26;j++){
                if(GCD(i,j)!=1)
                    continue;
                vector<char> opt;
                opt=decipher(cipher,i,j);
                if(msg==opt)
                    cout<<"\nKEY :"<<i<<"\t"<< j<<"\n";
            }
        }
    }
}
void fractionModulo(int& temp1,int & temp2){
    if(temp1%temp2){
        while(temp1%temp2)
            temp1+=26;
    }
}
void negativeModulo(int& temp1){
    if(temp1<0){
        while(temp1<0)
            temp1+=26;
    }
}
void knownplaintext(vector<char>& plain,vector<char>& cipher){
    char ch;
    int a,b;
    int temp1,temp2;
    temp1=(int)cipher[0]-(int)cipher[1];
    temp2=(int)plain[0]-(int)plain[1];
    negativeModulo(temp1);
    negativeModulo(temp2);
    fractionModulo(temp1,temp2);
    a=temp1/temp2;
    b=(int)cipher[0]-65-((int)plain[0]-65)*a;
    negativeModulo(b);
    cout<<"Keys are: "<<a<<"  "<<b<<"\n";
}

int main(){
    vector<char> msg,cipher,msgd,a,b;
    cout<<"Enter the message: ";
    getInput(msg);
    encipher(msg,cipher);
    cout<<"Cipher: ";
    print(cipher);
    cout<<"Decipher: ";
    msgd=decipher(cipher,key1,key2);
    print(msgd);
    cout<<"BruteForce: ";
    bruteForce(msg,cipher);
    cout<<"------ PLAIN TEST ATTACK --------\n";
    cout<<" Enter Plain Text :";
    getInput(a);
    cout<<" Enter Cipher Text :";
    getInput(b);
    knownplaintext(a,b);
    return 0;
}
