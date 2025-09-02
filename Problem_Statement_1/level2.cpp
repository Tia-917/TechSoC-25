#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

int main(){
    cout<<"Enter secret message";
    string msg;
    string newMsg;
    getline (cin,msg);
    int shft,diff,add,total,sum, avg,idx;
    double smallest=INT_MAX;
    vector <double> checkVec1={};
    vector <double> checkVec2={};
    double engFreq[]={8.34,1.54,2.73,4.14,12.60,2.03,1.92,6.11,6.71,0.23,0.87,4.24,2.53,6.80,7.70,1.66,0.09,5.68,6.11,9.37,2.85,1.06,2.34,0.20,2.04,0.06};
    
    for (int shft=1; shft<26; shft++){
        newMsg=msg;
        vector <double> checkVec1(26,0);
        double sum=0, avg=0;
        //for encoding message
    // for lowercase characters 
        for (int i=0; i<newMsg.length();i++){
            if ( 97<= newMsg[i] && newMsg[i]<= 122){
                if (newMsg [i] + shft > 122 ){
                    diff = (msg[i]+shft)-122;
                    newMsg[i]='a' +(diff-1);
                }else{
                    newMsg [i] += shft;
                }
            }
        }

    // for uppercase characters
        for (int i=0; i<newMsg.length();i++){
            if ( 65<= newMsg[i] && newMsg[i]<= 90){
                if (newMsg [i] + shft > 90){
                    diff = (newMsg[i]+shft)-90;
                    newMsg[i]='A' +(diff-1);
                }else{
                    newMsg [i] += shft;
                }
            }
        }
        cout<<"For shift ="<<shft<<" the result is " <<newMsg<<endl;

        double freq[26]={0}; // storing frequency of letters of the new encoded message 
        for (int i=0; i<newMsg.length(); i++){
            freq[newMsg[i]-'a']++;
            freq[i] /= newMsg.length();
            freq[i] *= 100;
        }
        int total = 12.54*newMsg.length();
        for (int i=0; i<26;i++){
            checkVec1[i]=engFreq[i]-freq[i];
            sum += checkVec1[i];
        }
        avg = sum/total;
        checkVec2.push_back(avg);
    }

    //for checking most likely decryption
    for (double i:checkVec2){
        smallest= min(i,smallest);
    }

    for (int i=0; i<checkVec2.size();i++){
        if (checkVec2[i]==smallest){
            idx=i;// now i+1 is the most precised shift value
            break;
        }
    }

    //to give the most likely correct decryption
    int rightShift=idx;
    // for lowercase characters 
        for (int i=0; i<newMsg.length();i++){
            if ( 97<= newMsg[i] && newMsg[i]<= 122){
                if (newMsg [i] + shft > 122 ){
                    diff = (msg[i]+ shft)-122;
                    newMsg[i]='a' +(diff-1);
                }else{
                    newMsg [i] += shft;
                }
            }
        }

    // for uppercase characters
        for (int i=0; i<newMsg.length();i++){
            if ( 65<= newMsg[i] && newMsg[i]<= 90){
                if (newMsg [i] + shft > 90){
                    diff = (newMsg[i]+ shft)-90;
                    newMsg[i]='A' +(diff-1);
                }else{
                    newMsg [i] += shft;
                }
            }
        }
    cout<<"the most likely correct decryption"<<msg<<endl;
    return 0;
}