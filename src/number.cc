#ifndef BIGNUMBER_H
#define BIGNUMBER_H

#define toDigit(c) (c - '0')

#include <string>
#include <vector>

class BigNumber {
private:
  bool m_bIsPositive = true; // @todo: suporte a numeros negativos
  std::vector<uint> m_lstNumbers;

public:
  BigNumber() = default;

  BigNumber(std::string strNumber) {
    // big-endian store (ex.: the number "1234" will be stored as "4321")
    for (uint i = strNumber.length(); i-- > 0;)
      m_lstNumbers.emplace_back(toDigit(strNumber.at(i)));
  }

  uint operator[](uint nPos) const {
    return get_number(nPos);
  }

  void back_insert_number(uint nNumber) { m_lstNumbers.emplace_back(nNumber); }

  uint get_number(uint nPos) const { 
    if (nPos >= m_lstNumbers.size())
      return 0;

    return m_lstNumbers.at(nPos);
  }

  uint size() const { return m_lstNumbers.size(); }

  std::string to_string() {
    std::string rtn;
    for (uint i = m_lstNumbers.size(); i-- > 0;)
      rtn += std::to_string(m_lstNumbers.at(i));

    if (rtn.empty())
      rtn = "0";
    return rtn;
  }

  void trim_zeroes() {
    uint nPos = 0;
    for (uint i = m_lstNumbers.size(); i-- > 0;)
      if (m_lstNumbers.at(i) == 0)
        nPos = i;
      else
        break;
    
    if (nPos == 0)
      m_lstNumbers.clear();
    else
      m_lstNumbers.resize(nPos);
  }
};

#endif