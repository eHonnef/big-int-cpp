#ifndef B_OPERATIONS_H
#define B_OPERATIONS_H

#include "operations.cc"

class Basic_OP : public Operation {
public:
  BigNumber sum(const BigNumber &A, const BigNumber &B) {
    BigNumber NumberRtn{};
    uint nCarry = 0;
    uint nRst = 0;
    uint nSize = A.size() > B.size() ? A.size() : B.size();

    for (uint i = 0; i < nSize; i++) {
      nRst = A[i] + B[i] + nCarry;
      nCarry = nRst / 10;
      NumberRtn.back_insert_number(nRst % 10);
    }
    if (nCarry != 0)
      NumberRtn.back_insert_number(nCarry);
    return NumberRtn;
  }

  BigNumber sub(const BigNumber &A, const BigNumber &B) {
    BigNumber NumberRtn{};
    uint nCarry = 10;
    uint nRst = 0;
    uint nSize = A.size() > B.size() ? A.size() : B.size();

    for (uint i = 0; i < nSize; i++) {
      nCarry = 9 + A[i] - B[i] + nCarry / 10;
      nRst = nCarry % 10;
      NumberRtn.back_insert_number(nRst);
    }
    NumberRtn.trim_zeroes();
    return NumberRtn;
  }

  BigNumber mul(const BigNumber &A, const BigNumber &B) { return BigNumber{}; }
  BigNumber div(const BigNumber &A, const BigNumber &B) { return BigNumber{}; }
  BigNumber mod(const BigNumber &A, const BigNumber &B) { return BigNumber{}; }
};

#endif