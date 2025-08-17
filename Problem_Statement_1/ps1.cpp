#include <iostream>
using namespace std;

int main(){
    cout<<"Enter secret message";
    string msg;
    getline (cin,msg);

    int shft,diff,add;
    cout<<"Enter shift value between 1 to 26";
    cin>> shft;

    //for encoding message
    // for lowercase characters 
    for (int i=0; i<msg.length();i++){
        if ( 97<= msg[i] && msg[i]<= 122){
            if (msg [i] + shft > 122 ){
                diff = (msg[i]+= shft)-122;
                msg[i]='a' +(diff-1);
            }else{
                msg [i] += shft;
            }
        }
    }

    // for uppercase characters
    for (int i=0; i<msg.length();i++){
        if ( 65<= msg[i] && msg[i]<= 90){
            if (msg [i] + shft > 90){
                diff = (msg[i]+= shft)-90;
                msg[i]='A' +(diff-1);
            }else{
                msg [i] += shft;
            }
        }
    }
    cout<<"The encoded message is"<<msg<<endl;

    //to decode a message 
    // for lowercase characters 
    for (int i=0; i<msg.length();i++){
        if ( 97<= msg[i] && msg[i]<= 122){
            if (msg [i] - shft < 97 ){
                add =97- (msg[i]-= shft);
                msg[i]='z' -(add-1);
            }else{
                msg [i] -= shft;
            }
        }
    }

    // for uppercase characters
    for (int i=0; i<msg.length();i++){
        if ( 65<= msg[i] && msg[i]<= 90){
            if (msg [i] - shft < 65 ){
                add =65- (msg[i]-= shft);
                msg[i]='Z' -(add-1);
            }else{
                msg [i] -= shft;
            }
        }
    }
    cout<<"The decoded message is"<<msg<<endl;;
}