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

void getInput(vector<char>&);
void print(vector<char>&);
void declutter(vector<char>&,vector<char>&);
vector<char> encipher(vector<char>&);

void getInput()

int main(){
    vector<char> msg,msgx,cipher;
    getInput(msg);
    print(msg);
    return 0;
}