 #include<iostream>
 #include<vector>
 using namespace std;

void getInput(vector<char>&);
vector<char> encipher(vector<char>&);
vector<char> decipher(vector<char>&);
void print(vector<char>&);

int key = 10;

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
    return;
}

void print(vector<char>& msg){
    for(int i=0;i<msg.size();i++){
        cout<<msg[i];
    }
    cout<<"\n";
    return;
}

vector<char> encipher(vector<char>& msg){
    vector<char> cipher;
    for(int i=0;i<msg.size();i++){
        if(msg[i]=='\n' || msg[i]=='\t' || msg[i]==' ')
            cipher.push_back(msg[i]);
        else
            cipher.push_back(msg[i]+key);        
    }
    return cipher;
}

vector<char> decipher(vector<char>& cipher){
    vector<char> msg;
    for(int i=0;i<cipher.size();i++){
        if(cipher[i]=='\n' || cipher[i]=='\t' || cipher[i]==' ')
            msg.push_back(cipher[i]);
        else
            msg.push_back(cipher[i]-key);        
    }
    return msg;
}

 int main(){
    vector<char> msg;
    vector<char> cipher;
    vector<char> msg1;
    getInput(msg);
    cipher = encipher(msg);
    cout<<"Cipher: ";
    print(cipher);
    msg1=decipher(cipher);
    cout<<"Decipher: ";
    print(msg1);
    return 0;
 }