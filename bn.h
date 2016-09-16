#ifndef dn_cpp
#define dn_cpp

#include <string>
#include <vector>
#include <iostream>


using namespace std;

struct BN{
    vector<unsigned char>ch;
};

extern "C" {
    BN* bn_create();
    int bn_destroy(BN*);
    int bn_from_string(BN*,string&);
    int bn_to_string (BN*,string&);
    int bn_from_char(BN* ,const char*);
}

#endif /* dn_cpp */

