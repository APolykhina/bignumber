#include "bncompare.h"

int bn_compare(BN* b1, BN* b2){
    int temp=0;
    if (b1->ch.size() == b2->ch.size()){
        for (int i = 0; i < b1->ch.size();i++){
            if (b1->ch[i] > b2->ch[i])
                temp = 1;
            if (b2->ch[i] > b1->ch[i])
                temp = 2;
            if (temp != 0)
                break;
        }
    }
    if(b1->ch.size() < b2->ch.size())
        temp=2;
    if(b1->ch.size() > b2->ch.size())
        temp=1;
    return temp;
}

int bn_operations2(vector<string>& mas) {
    mas.clear();
    mas.push_back("Функция bn_compare сравнивает два числа и выводит номер того,который больше или 0,если они равны");
    return 0;
}