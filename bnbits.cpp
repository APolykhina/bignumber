#include "bnbits.h"
#include <cmath>

void del_two(BN* rez,string& s){
    string str = "";
    int temp;
    
    if (s[0] == '1'){
        temp = (static_cast<int>(s[0]) -48)*10;
        for (int i = 1;i < s.size() ;i++){
            int ch = temp +(static_cast<int>(s[i])-48);
            str = str + to_string(ch/2);
            temp = (ch % 2)*10;
        }
        if (temp == 0)
            rez->ch.insert(rez->ch.begin(),'0');
        else
            rez->ch.insert(rez->ch.begin(),'1');
    }
    
    if (s[0] != '1'){
        temp = 0;
        for (int i = 0;i < s.size() ;i++){
            int ch = temp +(static_cast<int>(s[i])-48);
            str = str + to_string(ch/2);
            temp = (ch % 2)*10;
        }
        if (temp == 0)
            rez->ch.insert(rez->ch.begin(),'0');
        else
            rez->ch.insert(rez->ch.begin(),'1');
    }
    s =str;
}

void to_bits(BN* b, BN* rez){
    string s;
    bn_to_string(b,s);
    if (s =="1"){
        rez->ch.insert(rez->ch.begin(),'1');
    }
    if (s =="0"){
        rez->ch.insert(rez->ch.begin(),'0');
    }
    while ((s != "1") && (s != "0")){
        del_two(rez,s);
        if (s == "0"){
            rez->ch.insert(rez->ch.begin(),'0');
        }
        if (s == "1"){
            rez->ch.insert(rez->ch.begin(),'1');
        }
    }
}

void from_bits(BN* b){
    BN* temp = bn_create();
    BN* sum = bn_create();
    string s,str;
    bn_to_string(b,s);
    b->ch.clear();
    int rez=0;
    for (int i= 0; i<s.length(); ++i){
        if (s[i] == '1'){
            rez = pow(2,(s.length()-i-1));
            string s1 =to_string(rez);
            bn_from_string(temp,s1);
            sum = bn_sum(b, temp);
            bn_to_string(sum,str);
            bn_from_string(b,str);
        }
    }
    bn_destroy(temp);
    bn_destroy(sum);
}

BN* bn_or(BN* b1, BN* b2){
    BN* brez =bn_create();
    BN* bch1 = bn_create();
    BN* bch2 = bn_create();
    to_bits(b1,bch1);
    to_bits(b2,bch2);
    
    if ( bch1->ch.size() > bch2->ch.size()){
        int div =static_cast<int>(bch1->ch.size() - bch2->ch.size());
        for (int i = 0; i < div ; i++ ){
        bch2->ch.insert(bch2->ch.begin(),'0');
        }
    }
    
    if ( bch2->ch.size() > bch1->ch.size()){
        int div =static_cast<int>(bch2->ch.size() - bch1->ch.size());
        for (int i = 0; i <div ; i++ ){
            bch1->ch.insert(bch1->ch.begin(),'0');
        }
    }
    
    for (int i = static_cast<int>(bch1->ch.size()-1) ;i >=0 ; i-- ){
        if ((bch1->ch[i] == '0') && (bch2->ch[i] =='0')){
            brez->ch.insert(brez->ch.begin(),'0');
        }
        else
            brez->ch.insert(brez->ch.begin(),'1');
   }
    bn_destroy(bch1);
    bn_destroy(bch2);
    
    from_bits(brez);
    
    return brez;
}


BN* bn_and(BN* b1, BN* b2){
    BN* brez =bn_create();
    
    BN* bch1 = bn_create();
    BN* bch2 = bn_create();
    to_bits(b1,bch1);
    to_bits(b2,bch2);
    
    if ( bch1->ch.size() > bch2->ch.size()){
        int div =static_cast<int>(bch1->ch.size() - bch2->ch.size());
        for (int i = 0; i < div ; i++ ){
            bch2->ch.insert(bch2->ch.begin(),'0');
        }
    }
    
    if ( bch2->ch.size() > bch1->ch.size()){
        int div =static_cast<int>(bch2->ch.size() - bch1->ch.size());
        for (int i = 0; i <div ; i++ ){
            bch1->ch.insert(bch1->ch.begin(),'0');
        }
    }
    
    for (int i = static_cast<int>(bch1->ch.size()-1) ;i >=0 ; i-- ){
        if ((bch1->ch[i] == '1') && (bch2->ch[i] =='1')){
            brez->ch.insert(brez->ch.begin(),'1');
        }
        else
            brez->ch.insert(brez->ch.begin(),'0');
    }
    bn_destroy(bch1);
    bn_destroy(bch2);
    
    from_bits(brez);
    
    return brez;
}

BN* bn_xor(BN* b1, BN* b2){
    BN* brez =bn_create();
    BN* bch1 = bn_create();
    BN* bch2 = bn_create();
    
    to_bits(b1,bch1);
    to_bits(b2,bch2);
    
    if ( bch1->ch.size() > bch2->ch.size()){
        int div =static_cast<int>(bch1->ch.size() - bch2->ch.size());
        for (int i = 0; i < div ; i++ ){
            bch2->ch.insert(bch2->ch.begin(),'0');
        }
    }
    
    if ( bch2->ch.size() > bch1->ch.size()){
        int div =static_cast<int>(bch2->ch.size() - bch1->ch.size());
        for (int i = 0; i <div ; i++ ){
            bch1->ch.insert(bch1->ch.begin(),'0');
        }
    }
    
    for (int i = static_cast<int>(bch1->ch.size()-1) ;i >=0 ; i-- ){
        if (((bch1->ch[i] == '1') && (bch2->ch[i] =='0')) || ((bch1->ch[i] == '0') && (bch2->ch[i] =='1'))){
            brez->ch.insert(brez->ch.begin(),'1');
        }
        else
            brez->ch.insert(brez->ch.begin(),'0');
    }
    bn_destroy(bch1);
    bn_destroy(bch2);
    
    from_bits(brez);
    
    return brez;
}


int bn_operations3(vector<string>& mas){
    mas.clear();
    mas.push_back("Функция bn_or : побитовое ИЛИ");
    mas.push_back("Функция bn_and : побитовое И");
    mas.push_back("Функция bn_xor : исключающее ИЛИ");
    return 0;
}