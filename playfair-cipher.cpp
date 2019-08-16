#include<iostream>
#include<vector>
using namespace std;

const char encoder[5][5]={{'E','Q','U','I','N'},        // EQUINOX IS THE KEY
                    {'O','X','A','B','C'},
                    {'D','F','G','H','K'},
                    {'L','M','P','R','S'},
                    {'T','V','W','Y','Z'}};

void getPosition(char,int&,int&);
void sameColoumn(vector<char>&,int,int,int);
void sameRow(vector<char>&,int,int,int);
void sameColoumnDecipher(vector<char>&,int,int,int);
void sameRowDecipher(vector<char>&,int,int,int);
void diffColoumn(vector<char>&,int,int,int,int);
void declutter(vector<char>&,vector<char>&);
void getInput(vector<char>&);               // & required for reference
vector<char> encipher(vector<char>&);
vector<char> decipher(vector<char>&);
void print(vector<char>&);

void getInput(vector<char>& msg){
    char c;
    cout<<"Enter the message:\n";
    while(1){
        c=getchar();
        if (c=='j')
            c='I';
        else if(c>=97 && c<=122)
            c-=32;
        else if(c==' ')
            continue;
        else if(c=='\n')
            break;
        else if(c=='J')
            c='I';
        else if(!(c>=65 && c<=90))
            continue;
        msg.push_back(c);
    }
    return;
}

void declutter(vector<char>& msg, vector<char>& msgx){
    for(int i=0;i<msg.size();i++){
        if(msg[i]==msg[i+1]){
            msgx.push_back(msg[i]);
            msgx.push_back('X');
        }
        else{
            msgx.push_back(msg[i]);
        }
    }
    if(msgx.size()%2)
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
        getPosition(msgx[i],r1,c1);
        i++;
        getPosition(msgx[i],r2,c2);
        if(r1==r2)
            sameRow(cipher,r1,c1,c2);
        else if(c1==c2)
            sameColoumn(cipher,c1,r1,r2);
        else
            diffColoumn(cipher,r1,r2,c1,c2);  
        i++;      
    }
    return cipher;

}

void sameRow(vector<char>& cipher,int r1,int c1,int c2){
    cipher.push_back(encoder[r1][(c1+1)%5]);
    cipher.push_back(encoder[r1][(c2+1)%5]);
    return;
}

void sameColoumn(vector<char>& cipher,int c1,int r1,int r2){
    cipher.push_back(encoder[(r1+1)%5][c1]);
    cipher.push_back(encoder[(r2+1)%5][c1]);
    return;
}

void sameRowDecipher(vector<char>& cipher,int r1,int c1,int c2){
    cipher.push_back(encoder[r1][(c1-1)%5]);
    cipher.push_back(encoder[r1][(c2-1)%5]);
    return;
}

void sameColoumnDecipher(vector<char>& cipher,int c1,int r1,int r2){
    cipher.push_back(encoder[(r1-1)%5][c1]);
    cipher.push_back(encoder[(r2-1)%5][c1]);
    return;
}

void diffColoumn(vector<char>& cipher,int r1,int r2,int c1,int c2){
    cipher.push_back(encoder[r1][c2]);
    cipher.push_back(encoder[r2][c1]);
    return;
}

vector<char> decipher(vector<char>& cipher){
    vector<char> decipher;
    int r1,r2,c1,c2;
    int i=0;
    while(i<cipher.size()){
        getPosition(cipher[i],r1,c1);
        i++;
        getPosition(cipher[i],r2,c2);
        if(r1==r2)
            sameRowDecipher(decipher,r1,c1,c2);
        else if(c1==c2)
            sameColoumnDecipher(decipher,c1,r1,r2);
        else
            diffColoumn(decipher,r1,r2,c1,c2);  
        i++;      
    }
    return decipher;
}

int main(){
    vector<char> msg;
    vector<char> msgx;
    vector<char> cipher;
    vector<char> msgd;
    getInput(msg);
    declutter(msg,msgx);
    cipher = encipher(msgx);
    cout<<"Cipher Text: ";
    print(cipher);
    cout<<"Decipher Text: ";
    msgd = decipher(cipher);
    print(msgd);
    return 0;
}
