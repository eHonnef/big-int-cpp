#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "number.cc"

class BigNumber;

class Operation {
public:
  virtual BigNumber sum(const BigNumber &A, const BigNumber &B) = 0;
  virtual BigNumber sub(const BigNumber &A, const BigNumber &B) = 0;
  virtual BigNumber mul(const BigNumber &A, const BigNumber &B) = 0;
  virtual BigNumber div(const BigNumber &A, const BigNumber &B) = 0;
  virtual BigNumber mod(const BigNumber &A, const BigNumber &B) = 0;
};

#endif