#include "IComparable.h"
void ComparableCollection::sort() {
    for (int head = 0; head < size(); head++)
    {
        int reverse_head = head;
        while (reverse_head && *(*this)[reverse_head].get() < *(*this)[reverse_head - 1].get())
        {
            std::swap((*this)[reverse_head], (*this)[reverse_head - 1]);
            --reverse_head;
        }
    }
}