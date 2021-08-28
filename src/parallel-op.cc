#ifndef P_OPERATIONS_H
#define P_OPERATIONS_H

#include "operations.cc"

class Parallel_OP : public Operation {
public:
  BigNumber sum(const BigNumber &A, const BigNumber &B) { return BigNumber{}; }
  BigNumber sub(const BigNumber &A, const BigNumber &B) { return BigNumber{}; }
  BigNumber mul(const BigNumber &A, const BigNumber &B) { return BigNumber{}; }
  BigNumber div(const BigNumber &A, const BigNumber &B) { return BigNumber{}; }
  BigNumber mod(const BigNumber &A, const BigNumber &B) { return BigNumber{}; }
};

#endif