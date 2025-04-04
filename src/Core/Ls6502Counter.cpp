////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "Ls6502Counter.h"
#include <cstdint>
#include <numeric>

namespace ls6502
{

////////////////////////////////////////////////////////////
Ls6502Counter::Ls6502Counter()
{
    m_ls6502Counters.resize(static_cast<uint32_t>(RequestType::COUNT), 0);
}


////////////////////////////////////////////////////////////
void Ls6502Counter::increment(RequestType requestType)
{
    m_ls6502Counters[static_cast<uint32_t>(requestType)]++;
};


////////////////////////////////////////////////////////////
uint32_t Ls6502Counter::getValue(RequestType requestType) const
{
    return m_ls6502Counters[static_cast<uint32_t>(requestType)];
};


////////////////////////////////////////////////////////////
uint32_t Ls6502Counter::getSum() const
{
    return std::accumulate(m_ls6502Counters.begin(), m_ls6502Counters.end(), 0);
}


} // namespace ls6502
