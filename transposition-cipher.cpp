#include<iostream>
#include<vector>
using namespace std;

vector<vector<char>> matrix;
vector<int> order;
int minInd=1;
vector<char> key {'E','N','I','G','M','A'};

int findMin();
void getInput(vector<char>&);
void print(vector<char>&);
void printCipher(vector<char>&);
void encipher(vector<char>&);
void makeMatrix(vector<char>&);
void findRank(char,vector<char>&);
void decipher(vector<char>&,vector<char>&);

void getInput(vector<char>& msg){
    char ch;
    cout<<"Enter the message: ";
    while(1){
        ch=getchar();
        if(ch=='\n')
            break;
        else 
            msg.push_back(ch);
    }
    if(msg.size()%key.size()){
        int k = key.size()-(msg.size()%key.size());
        while(k){
            msg.push_back('o');
            k--;
        }
    }
    return;
}

void print(vector<char>& msg){
    for(int i=0;i<msg.size();i++){
        cout<<msg[i];
        cout<<"  ";
    }
    cout<<"\n";
    return;
}

void printCipher(vector<char>& msg){
    for(int i=0;i<msg.size();i++){
        cout<<msg[i];
    }
    cout<<"\n";
    return;
}

void findRank(char ch,vector<char>& key){
    int rank=1;
    for(int i=0;i<key.size();i++){
        if(ch>key[i])
            rank++;
    }
    order.push_back(char(rank));
    return;
}

void makeMatrix(vector<char>& msg){
    matrix.push_back(key);
    for(int j=0;j<key.size();j++){
        findRank(key[j],key);
    }
    int i=0;
    while(i<=msg.size()){
        vector<char> temp;
        for(int j=0;j<key.size();j++){
            temp.push_back(msg[i++]);
        }
        matrix.push_back(temp);
    }
    return;
}

int findMin(){
    int minIndex;
    for(int i=0;i<order.size();i++){
        if(minInd==order[i]){
            minIndex=i;
            minInd++;
            break;
        }
    }
    return minIndex;
}

void encipher(vector<char>& cipher){
    int count = key.size();
    while(count){
        int i = findMin();
        for(int j=1;j<matrix.size()-1;j++){
            cipher.push_back(matrix[j][i]);
        }
        count--;
    }
}

int main(){
    vector<char> msg,cipher,msgd;
    vector<int> order;
    getInput(msg);
    makeMatrix(msg);
    for(int i=0;i<matrix.size();i++)
        print(matrix[i]);
    encipher(cipher);
    cout<<"Cipher: ";
    printCipher(cipher);
    return 0;
}