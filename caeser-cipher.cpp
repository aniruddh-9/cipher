 #include<iostream>
 #include<vector>
 using namespace std;

void getInput(vector<char>&);
void encipher(vector<char>&,vector<char>&);
void decipher(vector<char>&,vector<char>&,int);
void print(vector<char>&);
void bruteForce(vector<char>&,vector<char>&);
void knownPlainText(vector<char>&,vector<char>&);

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

void encipher(vector<char>& msg,vector<char>& cipher){
    for(int i=0;i<msg.size();i++){
        if(msg[i]=='\n' || msg[i]=='\t' || msg[i]==' ')
            cipher.push_back(msg[i]);
        else
            cipher.push_back((msg[i]-97+key)%26+97);        
    }
    return;
}

void decipher(vector<char>& cipher,vector<char>& msgd,int key){
    for(int i=0;i<cipher.size();i++){
        if(cipher[i]=='\n' || cipher[i]=='\t' || cipher[i]==' ')
            msgd.push_back(cipher[i]);
        else{
            int temp = cipher[i]-key-97;
            if(temp<0)
                temp+=26;
            msgd.push_back((temp)%26+97);        
        }
    }
    return;
}

void bruteForce(vector<char>& cipher,vector<char>&msg){
    vector<char> msgb;
    for(int i=0;i<26;i++){
        decipher(cipher,msgb,i);
        if(msgb==msg){
            cout<<"Key : "<<i<<"\n";
            break;
        }
        msgb.clear();
    }
}

void knownPlainText(vector<char>& cipher,vector<char>& plain){
    int k;
    k=(int)cipher[0]-(int)plain[0];
    cout<<"Key : "<<k<<"\n";
}

 int main(){
    vector<char> msg;
    vector<char> cipher;
    vector<char> msgd;
    getInput(msg);
    encipher(msg,cipher);
    cout<<"Cipher: ";
    print(cipher);
    decipher(cipher,msgd,key);
    cout<<"Decipher: ";
    print(msgd);
    cout<<"---- BruteForce ---- \n";
    bruteForce(cipher,msg);
    cout<<" ------ Known Plain Text ------ \n";
    knownPlainText(cipher,msg);
    return 0;
 }