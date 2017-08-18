//
//  main.cpp
//  baseConversionProgram
//
//  Created by Zeke on 2/23/17.
//  Copyright © 2017 Zeke. All rights reserved.
//

//Student: Zeke Faison


#include <iostream>
#include <string>
#include <math.h>
using namespace std;
string numToBinary(int num);
string binaryToHex(string binaryNum);
string twoComp(string binaryNum);
string hexToDec(string hexNum);
int findNum(char charAc);


int main(int argc, const char * argv[]) {
    // insert code here...
    cout<< "Hello!"<<endl;
    cout<<"Enter b for decimal to binary and hex or enter h for hexadecimal to decimal...."<<endl;
    char ans;
    cin >> ans;
    if(ans == 'b'){
        int input;
        cout<<"please type in a number: ";
        cin >> input;
        string ans = numToBinary(input);
        cout<<"Here's the binary representation: " << ans<<endl;
        string hex = binaryToHex(ans);
        cout<<"Here's the hex representation: " << hex<<endl;
        cout<<"Bye!"<<endl;
    }else{
        string input;
        cout<<"please type in an unsigned hexadecimal number in 32 bits ";
        cin >> input;
        string ans = hexToDec(input);
        cout<<"Here's the decimal rep: " << ans<<endl;
        cout<<"Bye!"<<endl;
    }
    return 0;
}



string numToBinary(int num){
    
    string result = "";
    bool isNeg = false;
    if(num < 0){
        isNeg = true;
    }
    num = abs(num);
    int base = 2;
    int remainder = 0;
    while(num>0){
        remainder = num%base;
        result = to_string(remainder) + result;
        num/=base;
    }
    int difference = 32 - result.length();
    while(difference >0){
        result = "0" + result;
        difference-- ;
    }
    if(isNeg){
        result = twoComp(result);
    }
    return result;
}

string binaryToHex(string binaryNum){
    
    string result = "";
    int total = 0;
    int powerPlace = 0;
    int counter = 31;
    char biVals [32];
    for (int x = 0; x < binaryNum.length(); x++){
        biVals[x] = binaryNum[x];
    }
    while(counter > 0){
        if(biVals[counter] == '1'){
            total += int(pow(2, powerPlace));
        }
        counter--;
        powerPlace++;
    }
    string ans = "";
    int num = total;
    int base = 16;
    int remainder = 0;
    while(num>0){
        remainder = num%base;
        if(remainder > 9){
            switch (remainder){
                case 10:
                    ans = "A" + ans;
                    break;
                case 11:
                    ans = "B" + ans;
                    break;
                case 12:
                    ans = "C" + ans;
                    break;
                case 13:
                    ans = "D" + ans;
                    break;
                case 14:
                    ans = "E" + ans;
                    break;
                case 15:
                    ans = "F" + ans;
                    break;
                default:
                    cout<<"error"<<endl;
            }
        }else{
            ans = to_string(remainder) + ans;
        }
        
        num/=base;
    }
    int difference = 8 - ans.length();
    while(difference >0){
        ans = "0" + ans;
        difference-- ;
    }
    result = ans;
    return result;
}

string twoComp(string binaryNum){
    
    cout<<"binary num: " << binaryNum<<endl;
    bool isFirstOnefound = false;
    for(int i = 31; i < binaryNum.length(); i--){
        if(binaryNum[i] == '1' && isFirstOnefound == false){
            isFirstOnefound = true;
        }else{
            if(binaryNum[i] == '0' && isFirstOnefound){
                binaryNum[i] = '1';
            }
            else if(binaryNum[i] == '1' && isFirstOnefound){
                binaryNum[i] = '0';
            }
        }
    }
    cout<<"comp: "<<binaryNum<<endl;
    return binaryNum;
}

string hexToDec(string hexNum){
    
    int total = 0;
    int base = 16;
    int powerPlace = 7;
    for(int i = 0; i < hexNum.length(); i++){
        total += findNum(hexNum[i])*(int(pow(base, powerPlace)));
        powerPlace--;
    }
    return to_string(total);
}

int findNum(char charAc){
    switch (charAc){
            case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        case 'A':
            return 10;
        case 'a':
            return 10;
        case 'B':
            return 11;
        case 'b':
            return 11;
        case 'C':
            return 12;
        case 'c':
            return 12;
        case 'D':
            return 13;
        case 'd':
            return 13;
        case 'E':
            return 14;
        case 'e':
            return 14;
        case 'F':
            return 15;
        case 'f':
            return 15;
        default:
            return 0;
    }
    
    
}
