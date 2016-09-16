#include <iostream>
#include <string>
#include "bn.h"
#include <dlfcn.h>

using namespace std;

using dl_handle = void*;

typedef BN* (*pFunc1)(BN*, BN*);
typedef int (*pFunc2)(BN*, BN*);
typedef int (*pinf)(vector<string>&);


int main() {
    pFunc1 Func1;
    pFunc2 Func2;
    pinf F_inf;
    int temp;
    string str;
    char* s1= new char;
    char* s2 = new char;
    vector<string> mas_inf;
    
    cout << "Введите первое число "  << endl;
    cin >> s1;
    cout << endl;
    cout << "Введите второе число " << endl;
    cin >> s2;
    cout << endl;
    
    
    BN* big1 = bn_create();
    BN* big2 = bn_create();
    bn_from_char(big1,s1);
    bn_from_char(big2,s2);
    
    
    while (true){
        cout << "Выберите оперции,которые хотите выполнить  над числами" <<endl;
        cout << "1: Сложение,вычитание" <<endl;
        cout << "2: Сравнение" <<endl;
        cout << "3: Побитовое ИЛИ,побитовое И, исключение ИЛИ" <<endl;
        cout << "4: Выйти" <<endl;
        cin >>temp;
        if (temp ==4){
            break;
        }
        if ( temp ==1 ){
            void* h1 = dlopen("libbnarithm.so",RTLD_LAZY);
            if (h1) {
                cout << "выберите фукцию,которую хотите использовать" <<endl;
                F_inf =(pinf)dlsym(h1,"bn_operations1");
                F_inf(mas_inf);
                for (auto i:mas_inf){
                    cout << i << endl;
                }
                cin >> str;
                if (str == "bn_sum")
                    Func1 = (pFunc1)dlsym(h1,"bn_sum");
                if (str == "bn_sub")
                    Func1 = (pFunc1)dlsym(h1,"bn_sub");
                if (Func1){
                    BN* rez =Func1(big1,big2);
                    for (int i=0; i < rez->ch.size() ; i++)
                        cout << rez->ch[i];
                    }
                dlclose(h1);
            }
            cout <<endl <<endl;
        }
        
        if ( temp ==2){
            void* h1 = dlopen("libbncompare.so",RTLD_LAZY);
            if (h1) {
                cout << "выберите фукцию,которую хотите использовать" <<endl;
                F_inf =(pinf)dlsym(h1,"bn_operations2");
                F_inf(mas_inf);
                for (auto i:mas_inf){
                    cout << i << endl;
                }
                cin >> str;
                Func2 = (pFunc2)dlsym(h1,"bn_compare");
                if (Func2){
                    cout << Func2(big1,big2) <<endl;
                }
                dlclose(h1);
            }
            cout <<endl <<endl;
        }
        
        if ( temp ==3){
            void* h1 = dlopen("libbnbits.so",RTLD_LAZY);
            if (h1) {
                cout << "выберите фукцию,которую хотите использовать" <<endl;
                F_inf =(pinf)dlsym(h1,"bn_operations3");
                F_inf(mas_inf);
                for (auto i:mas_inf){
                    cout << i << endl;
                }
                cin >> str;
                if (str == "bn_or")
                    Func1 = (pFunc1)dlsym(h1,"bn_or");
                if (str == "bn_and")
                    Func1 = (pFunc1)dlsym(h1,"bn_and");
                if (str == "bn_xor")
                    Func1 = (pFunc1)dlsym(h1,"bn_xor");
                if (Func1){
                    BN* rez =Func1(big1,big2);
                    for (int i=0; i < rez->ch.size() ; i++)
                        cout << rez->ch[i];
                }
                dlclose(h1);
            }
            cout <<endl <<endl;
        }
        if( temp !=1 && temp !=2 && temp!=3)
            break;

    }
    return 0;
}
