//==========================================
//
//  main.cpp
//  [Github]HighPrecisionALG
//
//  Created by Operator-Ace2022 on 2022/11/13.
//
//==========================================
//Task objective: perform high-precision addition
//==========================================


#include <iostream>//Import header
#include <iomanip>//Import header
#include <cstdio>//Import header
#include <cstdlib>//Import header
#include <string>//Import header
#include <cstring>//Import header
using namespace std;

string addend1 = "0";//"addend1" is used to store the first addend
string addend2 = "0";//"addend2" is used to store the second addend
int add1[200] = {};//array "add1" is used to store the first addend(by int)
int add2[200] = {};//array "add2" is used to store the first addend(by int)
int sum[200] = {};//array "sum" is used to store the sum of "addend1" and "addend2"
int carry;//"carry" is used to store the carry
int len1;//"len1" is used to store the length of "addend1"
int len2;//"len2" is used to store the length of "addend2"
int len3;//"len3" is used to store the length of "sum"

void insert()//insert "addend1" and "addend2"
{
    getline(cin,addend1);//get "addend1"
    getline(cin,addend2);//get "addend2"
    len1 = addend1.length();
    len2 = addend2.length();
    len3 = 1;
    for(int i = 1;i<=len1;i++)
    {
        add1[i] = addend1[len1-i]-'0';//put "addend1" into "add1"
    }
    for(int i = 1;i<=len2;i++)
    {
        add2[i] = addend2[len2-i]-'0';//put "addend2" into "add2"
    }
    carry = 0;//Initialize "carry"
    len3 = 1;//Initialize "len3"
}
void add()
{
    while(len3<=len1||len3<=len2)//Add bit by bit
    {
        sum[len3] = add1[len3]+add2[len3]+carry;//add
        carry = sum[len3]/10;//update "carry"
        sum[len3]%=10;//update "sum[len3]"
        len3++;//update "len3"
    }
    sum[len3] = carry;
    if(sum[len3]==0)//Process the highest bit
    {
        len3--;
    }
    for(int i = len3;i>=1;i--)//out
    {
        printf("%d",sum[i]);
    }
    printf("\n");
}
int main(int argc, const char * argv[])//main
{
    while(1)//If both addends are - 1, exit. Otherwise, it is always calculated.
    {
        insert();//insert
        if(addend1=="-1"&&addend2=="-1")
        {
            return 0;
        }
        add();
    }
    return 0;//quit
}
