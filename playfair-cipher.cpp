#include<iostream>
#include<vector>
using namespace std;

int flag=0;
const char encoder[5][5]=  {{'E','Q','U','I','N'},        // EQUINOX IS THE KEY
                            {'O','X','A','B','C'},
                            {'D','F','G','H','K'},
                            {'L','M','P','R','S'},
                            {'T','V','W','Y','Z'}};

void getPosition(char,int&,int&);
void sameColoumn(vector<char>&,int,int,int);
void sameRow(vector<char>&,int,int,int);
void diffColoumn(vector<char>&,int,int,int,int);
void declutter(vector<char>&,vector<char>&);
void getInput(vector<char>&);               // & required for reference
vector<char> encipher(vector<char>&);
vector<char> decipher(vector<char>&);
void print(vector<char>&);

void getInput(vector<char>& msg){
    char ch;
    while(1){
        ch=getchar();
        if(ch=='\n')
            break;
        if(ch>=97 && ch<=122)
            ch-=32;
        if(ch=='J')
            ch='I';
        msg.push_back(ch);
    }
}

void declutter(vector<char>& msg, vector<char>& msgx){
    int count=0;
    for(int i=0;i<msg.size();i++){
        if(msg[i]==' '){
            count++;
            msgx.push_back(' ');
            continue;
        }
        else if(msg[i]==msg[i+1]){
            msgx.push_back(msg[i]);
            msgx.push_back('X');
        }
        else{
            msgx.push_back(msg[i]);
        }
    }
    if((msgx.size()-count)%2)
        msgx.push_back('X');
    return;
}

void print(vector<char>& msg){
    for(int i=0;i<msg.size();i++){
        cout<<msg[i];
    }
    cout<<"\n";
    return;
}

void getPosition(char ch,int& row, int& col){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(encoder[i][j]==ch){
                row=i;
                col=j;
            }
        }
    }
    return;
}

vector<char> encipher(vector<char>& msgx){
    vector<char> cipher;
    int r1,r2,c1,c2;
    int i=0;
    while(i<msgx.size()){
        if(msgx[i]==' '){
            cipher.push_back(' ');
            i++;
            continue;
        }
        getPosition(msgx[i],r1,c1);
        i++;
        if(msgx[i]==' '){
            flag=1;
            i++;
        }
        getPosition(msgx[i],r2,c2);
        i++;
        if(r1==r2)
            sameRow(cipher,r1,c1,c2);
        else if(c1==c2)
            sameColoumn(cipher,c1,r1,r2);
        else
            diffColoumn(cipher,r1,r2,c1,c2);      
    }
    return cipher;

}

void sameRow(vector<char>& cipher,int r1,int c1,int c2){
    cipher.push_back(encoder[r1][(c1+1)%5]);
    if (flag){
            cipher.push_back(' ');
            flag=0;
        }
    cipher.push_back(encoder[r1][(c2+1)%5]);
    return;
}

void sameColoumn(vector<char>& cipher,int c1,int r1,int r2){
    cipher.push_back(encoder[(r1+1)%5][c1]);
    if (flag){
            cipher.push_back(' ');
            flag=0;
        }
    cipher.push_back(encoder[(r2+1)%5][c1]);
    return;
}

void diffColoumn(vector<char>& cipher,int r1,int r2,int c1,int c2){
    cipher.push_back(encoder[r1][c2]);
    if (flag){
            cipher.push_back(' ');
            flag=0;
        }
    cipher.push_back(encoder[r2][c1]);
    return;
}

int main(){
    vector<char> msg;
    vector<char> msgx;
    vector<char> cipher;
    vector<char> msgd;
    getInput(msg);
    print(msg);
    declutter(msg,msgx);
    print(msgx);
    cipher = encipher(msgx);
    cout<<"Cipher Text: ";
    print(cipher);
   // cout<<"Decipher Text: ";
   // msgd = decipher(cipher);
   // print(msgd);
    return 0;
}
