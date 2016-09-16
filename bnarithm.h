#include <iostream>
#include <vector>
#include <string>
#include "bn.h"

extern "C"{
    BN* bn_sum(BN* b1, BN* b2);
    BN* bn_sub(BN* b1,BN* b2);
    int bn_operations1(vector<string>&);
}



