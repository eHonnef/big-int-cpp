#ifndef BIGINT_H
#define BIGINT_H

#include <memory>

#include "basic-op.cc"
#include "number.cc"
#include "parallel-op.cc"

enum OP { opBasic, opParallel };

class BigInt {
private:
  std::shared_ptr<Operation> m_op;
  BigNumber m_number;

public:
  BigInt() = default;

  BigInt(std::string strNumber, OP op = opBasic) {
    if (op == opParallel)
      m_op = std::shared_ptr<Operation>(new Parallel_OP);
    else
      m_op = std::shared_ptr<Operation>(new Basic_OP);

    m_number = BigNumber(strNumber);
  }

  BigNumber get_number() const { return m_number; }

  std::string to_string() { return m_number.to_string(); }

  // BigInt &operator++() {}
  // BigInt operator++(int) {}
  // BigInt &operator--() {}
  // BigInt operator--(int) {}
  BigInt &operator+=(const BigInt &rhs) {
    m_number = m_op->sum(m_number, rhs.get_number());
    return *this;
  }

  friend BigInt operator+(BigInt lhs, const BigInt &rhs) {
    lhs += rhs;
    return lhs;
  }

  BigInt &operator-=(const BigInt &rhs) {
    m_number = m_op->sub(m_number, rhs.get_number());
    return *this;
  }

  friend BigInt operator-(BigInt lhs, const BigInt &rhs) {
    lhs -= rhs;
    return lhs;
  }
};

//*****************************************************************
#endif // BIGINT_H
//*****************************************************************
