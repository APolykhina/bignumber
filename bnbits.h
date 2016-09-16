#include "bn.h"
#include "bnarithm.h"

extern "C" {
    BN* bn_or(BN*, BN*);
    BN* bn_xor(BN*, BN*);
    BN* bn_and(BN*, BN*);
    int bn_operations3(vector<string>&);
}