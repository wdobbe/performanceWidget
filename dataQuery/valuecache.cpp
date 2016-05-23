#include "valuecache.h"

ValueCache::ValueCache()
{

}

const std::vector<float> &ValueCache::values() const
{
    return m_values;
}

const QString &ValueCache::backGroundText() const
{
    return m_backgroundText;
}

size_t ValueCache::size() const
{
    return m_values.size();
}

std::vector<float> &ValueCache::values()
{
    return m_values;
}

void ValueCache::setBackGroundText(const QString &text)
{
    m_backgroundText = text;
}
