
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int init_permut[64]=  { 58,50,42,34,26,18,10,2, 
                        60,52,44,36,28,20,12,4, 
                        62,54,46,38,30,22,14,6, 
                        64,56,48,40,32,24,16,8, 
                        57,49,41,33,25,17,9,1, 
                        59,51,43,35,27,19,11,3, 
                        61,53,45,37,29,21,13,5, 
                        63,55,47,39,31,23,15,7 
                        }; 

int expand[48]=  {   32,1,2,3,4,5,4,5, 
                    6,7,8,9,8,9,10,11, 
                    12,13,12,13,14,15,16,17, 
                    16,17,18,19,20,21,20,21, 
                    22,23,24,25,24,25,26,27, 
                    28,29,28,29,30,31,32,1 
                }; 

int s[8][4][16]= 
    {{ 
        14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7, 
        0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8, 
        4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0, 
        15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13 
    }, 
    { 
        15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10, 
        3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5, 
        0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15, 
        13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9 
    }, 
  
  
    { 
        10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8, 
        13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1, 
        13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7, 
        1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12 
    }, 
    { 
        7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15, 
        13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9, 
        10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4, 
        3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14 
    }, 
    { 
        2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9, 
        14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6, 
        4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14, 
        11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3 
    }, 
    { 
        12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11, 
        10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8, 
        9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6, 
        4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13 
    }, 
    { 
        4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1, 
        13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6, 
        1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2, 
        6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12 
    }, 
    { 
        13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7, 
        1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2, 
        7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8, 
        2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11 
    }};

int Straight_Per[32]= {  16,7,20,21, 
                29,12,28,17, 
                1,15,23,26, 
                5,18,31,10, 
                2,8,24,14, 
                32,27,3,9, 
                19,13,30,6, 
                22,11,4,25 
            }; 

int final_permut[64]={40,8,48,16,56,24,64,32, 
                    39,7,47,15,55,23,63,31, 
                    38,6,46,14,54,22,62,30, 
                    37,5,45,13,53,21,61,29, 
                    36,4,44,12,52,20,60,28, 
                    35,3,43,11,51,19,59,27, 
                    34,2,42,10,50,18,58,26, 
                    33,1,41,9,49,17,57,25 
                    }; 

int key_permut[56]={  57,49,41,33,25,17,9, 
                1,58,50,42,34,26,18, 
                10,2,59,51,43,35,27, 
                19,11,3,60,52,44,36,           
                63,55,47,39,31,23,15, 
                7,62,54,46,38,30,22, 
                14,6,61,53,45,37,29, 
                21,13,5,28,20,12,4 
                }; 

int shift_table[16]= {  1, 1, 2, 2, 
                        2, 2, 2, 2,  
                        1, 2, 2, 2,  
                        2, 2, 2, 1 
                    }; 
      
int key_compress[48]= { 14,17,11,24,1,5, 
                        3,28,15,6,21,10, 
                        23,19,12,4,26,8, 
                        16,7,27,20,13,2, 
                        41,52,31,37,47,55, 
                        30,40,51,45,33,48, 
                        44,49,39,56,34,53, 
                        46,42,50,36,29,32 
                    }; 

string getInput(int&);
string hex2bin(string);
string bin2hex(string);
string permutation(string,int*,int);
string shift_key(string,int);
string XOR(string,string);
string encrypt(string,vector<string>,vector<string>);
string toHex(string);
string fromHex(string);

string toHex(string inp){
    string op="";
    for(int i=0;i<inp.length();i++){
        int n = (int)inp[i];
        string s="";
        while(n!=0){
            int temp=n%16;
            if(temp<10)
                s.push_back((char)(temp+48));
            else
                s.push_back((char)(temp+55));
            n=n/16;
        }
        reverse(s.begin(),s.end());
        op+=s;
    }
    return op;
}

int hex_to_int(char c){
        int first = c / 16 - 3;
        int second = c % 16;
        int result = first*10 + second;
        if(result > 9) result--;
        return result;
}
int hex_to_ascii(char c, char d){
        int high = hex_to_int(c) * 16;
        int low = hex_to_int(d);
        return high+low;
}
string fromHex(string out){
    char buf;
    string plain;
    for(int i = 0; i < out.length(); i++){
                if(i % 2 != 0){
                        plain.push_back(hex_to_ascii(buf, out[i]));
                }else{
                        buf = out[i];
                }
        }
    return plain;
}

string getInput(int& length){
    string inp;
    cout<<"Enter Message: ";
    getline(cin,inp);
    length=inp.length();
    inp=toHex(inp);
    if(inp.length()%16){
        while(inp.length()%16)
            inp+='0';
    }
    cout<<"\nMessage in Hexadecimal: "<<inp<<endl;
    return inp;
}

string hex2bin(string str){ 
    unordered_map<char, string> bin; 
    bin['0']= "0000"; 
    bin['1']= "0001"; 
    bin['2']= "0010"; 
    bin['3']= "0011"; 
    bin['4']= "0100"; 
    bin['5']= "0101"; 
    bin['6']= "0110"; 
    bin['7']= "0111"; 
    bin['8']= "1000"; 
    bin['9']= "1001"; 
    bin['A']= "1010"; 
    bin['B']= "1011"; 
    bin['C']= "1100"; 
    bin['D']= "1101"; 
    bin['E']= "1110"; 
    bin['F']= "1111"; 
    string binary=""; 
    for(int i=0; i<str.size(); i++){ 
        binary+= bin[str[i]]; 
    } 
    return binary; 
} 

string bin2hex(string str){ 
    unordered_map<string, string> hex; 
    hex["0000"]= "0"; 
    hex["0001"]= "1"; 
    hex["0010"]= "2"; 
    hex["0011"]= "3"; 
    hex["0100"]= "4"; 
    hex["0101"]= "5"; 
    hex["0110"]= "6"; 
    hex["0111"]= "7"; 
    hex["1000"]= "8"; 
    hex["1001"]= "9"; 
    hex["1010"]= "A"; 
    hex["1011"]= "B"; 
    hex["1100"]= "C"; 
    hex["1101"]= "D"; 
    hex["1110"]= "E"; 
    hex["1111"]= "F"; 
    string hexa=""; 
    for(int i=0; i<str.length(); i+=4){ 
        string ch=""; 
        ch+= str[i]; 
        ch+= str[i+1]; 
        ch+= str[i+2]; 
        ch+= str[i+3]; 
        hexa+= hex[ch]; 
    } 
    return hexa; 
} 

string permutation(string str, int* arr, int n){ 
    string result=""; 
    for(int i=0; i<n ; i++){ 
        result+= str[arr[i]-1]; 
    } 
    return result; 
} 
  
string shift_key(string str, int shift){ 
    string temp=""; 
    for(int i=0; i<shift; i++){ 
        for(int j=1; j<28; j++){ 
            temp+= str[j]; 
        } 
        temp+= str[0]; 
        str= temp; 
        temp=""; 
    } 
    return str; 
} 
  
string XOR(string a, string b){ 
    string result= ""; 
    for(int i=0; i<a.size(); i++){ 
        if(a[i]==b[i]){ 
            result+= "0"; 
        }else{ 
            result+= "1"; 
        } 
    } 
    return result; 
} 

string encrypt(string plain, vector<string> fnKeyBin, vector<string> fnKeyHex){   
    plain= hex2bin(plain); 
    plain= permutation(plain, init_permut, 64); 
    //cout<<"After Initial Permutation: "<<bin2hex(plain)<<endl; 
    string left= plain.substr(0, 32); 
    string right= plain.substr(32, 32); 
    //cout<<"After Splitting: L0="<<bin2hex(left) 
       //     <<" R0="<<bin2hex(right)<<endl; 
   // cout<<"\t  Left\t  Right\t  Round Key"<<endl;
    for(int i=0; i<16; i++){ 
        string right_expanded= permutation(right, expand, 48);  // EXPANSION OF KEY
        string x= XOR(fnKeyBin[i], right_expanded); 

        string op="";                                   // S-BOX
        for(int i=0;i<8; i++){ 
            int row= 2*int(x[i*6]-'0')+ int(x[i*6 +5]-'0'); 
            int col= 8*int(x[i*6 +1 ]-'0')+ 4*int(x[i*6 +2]-'0')+  
                                 2*int(x[i*6 +3]-'0')+ int(x[i*6 +4]-'0'); 
            int val= s[i][row][col]; 
            op+= char(val/8+ '0'); 
            val= val%8; 
            op+= char(val/4+ '0'); 
            val= val%4; 
            op+= char(val/2+ '0'); 
            val= val%2; 
            op+= char(val+ '0'); 
        } 

        op= permutation(op, Straight_Per, 32);         // STRAIGHT PERMUTATION
        x= XOR(op, left); 

        left=right; 
        right= x;

        if(i== 15){ 
            swap(left, right); 
        } 
      //  cout<<"Round "<<i+1<<" "<<bin2hex(left)<<" "<<bin2hex(right)<<" "<<fnKeyHex[i]<<endl; 
    } 
    string combine= left+right;  
    string cipher= bin2hex(permutation(combine, final_permut, 64)); 
    return cipher; 
} 

string encipher(string msg,string key,bool decrypt){
    string plain;
    plain=msg;
    key= hex2bin(key);  
    key= permutation(key, key_permut, 56);
    string left= key.substr(0, 28); 
    string right= key.substr(28, 28);   
    vector<string> fnKeyBin;
    vector<string> fnKeyHex;
    for(int i=0; i<16; i++){ 
        left= shift_key(left, shift_table[i]); 
        right= shift_key(right, shift_table[i]); 
          
        string combine= left + right; 
        string FunctionKey= permutation(combine, key_compress, 48);     
        fnKeyBin.push_back(FunctionKey); 
        fnKeyHex.push_back(bin2hex(FunctionKey)); 
    }   
    if(decrypt){
        reverse(fnKeyBin.begin(), fnKeyBin.end()); 
        reverse(fnKeyHex.begin(), fnKeyHex.end()); 
    }  
    string cipher= encrypt(plain, fnKeyBin,fnKeyHex);
    return cipher;
}

int main(){  
    string plain,cipher,decipher;
    int length;
    plain=getInput(length);
    string key="245DFA61C05B6E3F";
    for(int i=0;i<plain.length();i+=16){
        string sub= plain.substr(i,i+16);
        cipher+=encipher(sub,key,false);
    }
    cout<<"\nCipher: "<<cipher<<endl;;

    for(int i=0;i<cipher.length();i+=16){
        string sub= cipher.substr(i,i+16);
        decipher+=encipher(sub,key,true);
    } 
    cout<<"\nDecipher: "<<decipher<<endl;
    decipher=decipher.substr(0,2*length);
    decipher=fromHex(decipher);
    cout<<"\nPlain Text: "<<decipher<<endl;;
} 