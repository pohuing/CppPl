# C++ Prüfungsleistung

## How To
### Templated
Sortierfunktion ist sort_it und operiert mit RandomIt Iteratoren und einem Funktor zum Vergleich. Der Funktor muss zwei argumente von gleichem Typ akzeptieren und eine "less" than Funktion implementieren. Bsp:
```c++
// Beispieldaten
auto data = std::vector<datatype>();
data.emplace_back(1, 3);
data.emplace_back(-0, 0);
data.emplace_back(0, 2);
//      RandomIt start    RandomIt ende
sort_it(data.begin(), data.end(),
        // C++ Lambda für Vergleiche
        [](const datatype &a, const datatype &b) -> bool {
            return sqrt(a.first * a.first + a.second * a.second) <
                    sqrt(b.first * b.first + b.second * b.second);
        });
```

### Inherited
ComparableCollection erbt von std::vector<std::unique_ptr<IComparable>> um einfache Datenzugriffe zu erlauben. IComparable erfordert operator< und operator>.
```c++
#include "lib/inherited/IComparable/Point.h"


auto collection = ComparableCollection();
collection.push_back(std::make_unique<Point>(1,1));
collection.push_back(std::make_unique<Point>(0,0));

collection.sort();
```
## Vorteile Nachteile Vererbung vs Templates
# Templates
Mit Templates lassen sich zu Kompilierzeit ges