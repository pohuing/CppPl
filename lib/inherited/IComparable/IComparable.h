#ifndef CPPPL_ICOMPARABLE_H
#define CPPPL_ICOMPARABLE_H


#include <vector>
#include <memory>

class IComparable {
public:
    // -1 if other < b 0 if equal, 1 if this > b
    virtual bool operator<(const IComparable&) const = 0;
    virtual bool operator>(const IComparable&) const = 0;
};


// A collection for IComparables, owns data through a std::unique_ptr
class ComparableCollection{
public:
    // Sorts the collection in place
    void sort();
    void push_back(std::unique_ptr<IComparable> value);
    // Returns a reference to the data vector
    std::vector<std::unique_ptr<IComparable>>& get_data_ref();

private:
    std::vector<std::unique_ptr<IComparable>> m_data;
};
#endif //CPPPL_ICOMPARABLE_H
