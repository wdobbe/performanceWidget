#ifndef VALUECACHE_H
#define VALUECACHE_H

#include <QString>
#include <vector>

class ValueCache
{
    public:
        ValueCache();

        const std::vector<float> &values() const;
        const QString &backGroundText() const;
        size_t size() const;

        std::vector<float> &values();
        void setBackGroundText(const QString &text);

    private:
        QString m_backgroundText;
        std::vector<float> m_values;
};

#endif // VALUECACHE_H
