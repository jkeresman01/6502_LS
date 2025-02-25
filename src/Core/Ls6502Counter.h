#pragma once

#include <cstdint>
#include <vector>

#include "../Enums/RequestType.h"

namespace ls6502
{
class Ls6502Counter
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructors (default, copy, move)
    ///        and assignment operators
    ///
    //////////////////////////////////////////////////////////////
    Ls6502Counter();
    Ls6502Counter(const Ls6502Counter &) = delete;
    Ls6502Counter(Ls6502Counter &&) = delete;
    Ls6502Counter &operator=(const Ls6502Counter &) = delete;
    Ls6502Counter &operator=(Ls6502Counter &&) = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Increments the request counter
    ///
    /// @param [in] requestType
    ///
    //////////////////////////////////////////////////////////////
    void increment(RequestType requestType);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Gets the value of requested counter
    ///
    /// @param [in] requestType
    ///
    //////////////////////////////////////////////////////////////
    uint32_t getValue(RequestType requestType) const;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Gets the accumulated sum of all counters
    ///
    //////////////////////////////////////////////////////////////
    uint32_t getSum() const;

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Keeps track of received requests
    ///
    /// @param [in] requestType
    ///
    //////////////////////////////////////////////////////////////
    std::vector<uint32_t> m_ls6502Counters;
};
} // namespace ls6502
