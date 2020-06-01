#ifndef CPPPL_SORT_H
#define CPPPL_SORT_H

#include <vector>
#include <functional>
#include <iterator>

/**
 * @brief sorts any collection<T> between \p start and \p end
 *
 *
 * @tparam RandomIt Iterator over a collection<T>
 * @tparam T The Datatype of the collection to be sorted
 * @param start RandomAccessIterator at the start of the section to be sorted
 * @param end RandomAccessIterator at the end of the section to be sorted
 * @param le a function pointer or lambda for a less than comparison between two T, defaults to a<b
 */
template <typename T, typename RandomIt>
void sort_it(RandomIt start, RandomIt end, std::function<bool(const T&, const T&)> le = [](const T& a, const T& b){return a<b;}) {

    for (RandomIt head = start; head != end; ++head)
    {
        RandomIt reverse_head = head;
        while (reverse_head != start && le(*reverse_head, *(reverse_head - 1)))
        {
            std::swap(*reverse_head, *(reverse_head - 1));
            --reverse_head;
        }
    }
}
#endif //CPPPL_SORT_H
