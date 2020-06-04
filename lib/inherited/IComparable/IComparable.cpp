#include "IComparable.h"
void ComparableCollection::sort() {
    for (int head = 0; head < m_data.size(); head++)
    {
        int reverse_head = head;
        while (reverse_head && *m_data[reverse_head].get() < *m_data[reverse_head - 1].get())
        {
            std::swap(m_data[reverse_head], m_data[reverse_head - 1]);
            --reverse_head;
        }
    }
}

std::vector<std::unique_ptr<IComparable>> &ComparableCollection::get_data_ref() {
    return m_data;
}

void ComparableCollection::push_back(std::unique_ptr<IComparable> value) {
    m_data.emplace_back(std::move(value));
}
