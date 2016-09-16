#include "bnarithm.h"

using namespace std;

BN* bn_sub(BN* b1,BN* b2){
    BN* rez = bn_create();
    unsigned long dif =0;
    unsigned long max =0;
    
    int temp1=0;
    if (b1->ch.size() == b2->ch.size()){
        for (int i = 0; i < b1->ch.size();i++){
            if (b1->ch[i] > b2->ch[i])
                temp1 = 1;
            if (b2->ch[i] > b1->ch[i])
                temp1 = 2;
            if (temp1 != 0)
                break;
        }
    }
    if(b1->ch.size() < b2->ch.size())
        temp1=2;
    if(b1->ch.size() > b2->ch.size())
        temp1=1;
    
    
    if (temp1 ==1){
        max = b1->ch.size();
        dif = b1->ch.size() - b2->ch.size();

        for (int i = 0; i < dif; i++){
            b2->ch.insert(b2->ch.begin(),'0');
        }
    
        int temp = 0;
        for (int i = (static_cast<int>(max)-1); i >=0 ; i--){
        if ((b1->ch[i] - b2->ch[i] - temp) >= 0){
            rez->ch.insert(rez->ch.begin(),b1->ch[i] - b2->ch[i] - temp +48);
            temp = 0;
        }
        else{
            rez->ch.insert(rez->ch.begin(), b1->ch[i] - b2->ch[i] - temp + 58);
            temp = 1;
        }
        while (rez->ch[0] ==48)
            rez->ch.erase(rez->ch.begin());
        }
    }
    
    
    if (temp1==2){
        max = b2->ch.size();
        dif = b2->ch.size() - b1->ch.size();
        
        for (int i = 0; i < dif; i++){
            b1->ch.insert(b1->ch.begin(),'0');
        }
        int temp =0;
        for (int i = (static_cast<int>(max)-1); i >=0 ; i--){
            if ((b2->ch[i] - b1->ch[i] - temp) >= 0){
                rez->ch.insert(rez->ch.begin(),b2->ch[i] - b1->ch[i] - temp +48);
                temp = 0;
            }
            else{
                rez->ch.insert(rez->ch.begin(), b2->ch[i] - b1->ch[i] - temp + 58);
                temp = 1;
            }
        }
        while (rez->ch[0] ==48){
            rez->ch.erase(rez->ch.begin());
        }
    }
    while ((b1->ch[0]=='0') && (b1->ch.size() != 1)){
        b1->ch.erase(b1->ch.begin());
    }
    while ((b2->ch[0]=='0') && (b2->ch.size() != 1)){
        b2->ch.erase(b2->ch.begin());
    }

    return rez;
}




BN* bn_sum(BN* b1, BN* b2){
    BN* sum = bn_create();
    unsigned long max = 0;
    unsigned long dif = 0;
    
    if (b1->ch.size() >= b2->ch.size()){
        max = b1->ch.size();
        dif = b1->ch.size() - b2->ch.size();
        for (int i = 0; i < dif; i++)
        {
            b2->ch.insert(b2->ch.begin(),'0');
        }
    }
    
    else{
        max = b2->ch.size();
        dif = b2->ch.size() - b1->ch.size();
        for (int i = 0; i < dif; i++)
        {
            b1->ch.insert(b1->ch.begin(), '0');
        }
    }
    
    int temp = 0;
    for (int i = (static_cast<int>(max)-1); i >=0 ; i--){
        if (b1->ch[i] + b2->ch[i] + temp - 96<=9){
            sum->ch.insert(sum->ch.begin(), b1->ch[i] + b2->ch[i] + temp - 48);
            temp = 0;
        }
        else{
            sum->ch.insert(sum->ch.begin(), b1->ch[i] + b2->ch[i] + temp - 58);
            temp = 1;
        }
    }
    
    if (temp == 1){
        sum->ch.insert(sum->ch.begin(), 49);
        temp = 0;
    }
    while ((b1->ch[0]=='0')&& (b1->ch.size() != 1)){
        b1->ch.erase(b1->ch.begin());
    }
    while ((b2->ch[0]=='0') && (b1->ch.size() != 1)){
        b2->ch.erase(b2->ch.begin());
    }
    return sum;
}

int bn_operations1(vector<string>& mas){
    mas.clear();
    mas.push_back("функция bn_sum:сложение двух чисел");
    mas.push_back("функция bn_sub:вычитание из большего меньшее");
    return 0;
}






