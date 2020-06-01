#ifndef CPPPL_SORT_H
#define CPPPL_SORT_H

#include <vector>
#include <functional>
#include <iterator>

/**
 * @brief sorts any collection<T> between \p start and \p end
 *
 * @tparam RandomIt Iterator over a collection<T>
 * @tparam F the functor over two T returning a bool
 * @param start RandomAccessIterator at the start of the section to be sorted
 * @param end RandomAccessIterator at the end of the section to be sorted
 * @param le a functor for a less than comparison between two T, defaults to std::less
 */
template <typename RandomIt, typename F >
void sort_it(RandomIt start, RandomIt end, F le = std::less<decltype(*std::declval<RandomIt>())>{}) {
    // Assert that F is a callable function returning a bool with two parameter
    static_assert(std::is_invocable_r_v<bool, F, decltype(*start), decltype(*start)>, "Callable must compare two elements of the range and returns a boolean");

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
