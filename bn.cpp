#include "bn.h"

BN* bn_create() {
    return new BN;
}

int bn_destroy(BN* bn){
    delete bn;
    return 0;
}

int bn_from_string(BN* bn,string& s) {
    bn->ch.clear();
    for (int i=0;i<s.length(); i++){
        bn->ch.push_back(static_cast<char>(s[i]));
    }
    return 0;
}

int bn_to_string (BN* bn,string& s){
    s.clear();
    for (int i=0;i < bn->ch.size(); i++){
        s = s + static_cast<char>(bn->ch[i]);
    }
    return 0;
}

int bn_from_char(BN* bn,const char* s) {
    string str(s);
    bn->ch.clear();
    for (int i=0;i<str.length(); i++){
        bn->ch.push_back(static_cast<char>(str[i]));
    }
    return 0;
}

