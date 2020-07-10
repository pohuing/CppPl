# C++ Prüfungsleistung

## How To
### Dieses Projekt
`make` generiert das TUI mit debugsymbolen
`make release` generiert das TUI mit Optimierungen
`make bench` generiert ein Benchmark für Templated vs Inherited für 10.000 Werte mit 20 Wiederholungen und gibt die fünf besten Werte aus. Anzahl der Wiederholungen ist mit `COUNT` änderbar. Bsp.: `make bench COUNT=100`
### Templated
Sortierfunktion ist sort_it und operiert mit RandomIt Iteratoren und einem Funktor zum Vergleich. Der Funktor muss zwei Argumente von gleichem Typ akzeptieren und eine "less than" Funktion implementieren. Bsp:
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
ComparableCollection erbt von `std::vector<std::unique_ptr<IComparable>>` um einfache Datenzugriffe zu erlauben. IComparable erfordert `operator<` und `operator>`.
```c++
#include "lib/inherited/IComparable/Point.h"


auto collection = ComparableCollection();
collection.push_back(std::make_unique<Point>(1,1));
collection.push_back(std::make_unique<Point>(0,0));

collection.sort();
```
## Vorteile Nachteile Vererbung vs Templates
# Templates
Mit Templates lassen sich zu Kompilierzeit verifiziert machbare Operationen garantieren. Dank Static Dispatch können nur Methoden verwendet werden welche auch tatsächlich existieren, sofern kein Laufzeitpolymorphismus verwendet wird.
Die konkrete Implementierung von `sort_it` erlaubt einfache Verwendung ohne viel drumherum oder Vorbereitung. Im schlimmsten Fall muss die Datenstruktur RandomIt Zugriffe implementieren, etwas was sich sowieso empfiehlt für Kompatibilität mit anderen Bibliotheken. Ausserdem muss ein Lambda geschrieben werden, aber hier kann auch auf  `operator<` zurückgefallen werden
```c++
std::vector<int> a {3,1,2};
sort_it(a.begin(), a.end());
```
Ein Nachteil ist die größere kompilierte Anwendung, da für jeden Typ mit dem die Template verwendet wird ein eigener Pfad generiert wird. Dieses Erstellen der Version der Funktion für jeden verwendeten Typen kann ausserdem verhältnismäßig lange dauern.

# Vererbung
Durch Laufzeitpolymorphismus via gemeinsamer Interfaces können verschiedene Typen verglichen werden. Eine Sammlung ist also nicht strikt an einen Typ gebunden. Ein Beispiel mit 2D und 3D Vektoren, gesamter Code ist in `lib/inherited/IComparable/example.cpp`
```cpp
#include "lib/inherited/IComparable/IComparable.h"
#include "lib/inherited/IComparable/Point.h"

class Point : public IComparable{
        Point(int x, int y) : m_x(x), m_y(y){
        [...]
};
class Point3D : public Point{
        Point3D(int x, int y, int z) : Point(x,y), m_z(z){}
        [...]
};


int main(){
    ComparableCollection collection;
    collection.push_back(std::make_unique<Point>(1,1));
    collection.push_back(std::make_unique<Point>(0,0));
    collection.push_back(std::make_unique<Point3D>(0,0,1));
    collection.sort();

    print_all(collection);
    // Output:
    // 0 (0 0)
    // 1 (0 0 1)
    // 1.41421 (1 1)
}
```
Laufzeitpolymorphismus ist unter Umständen langsam. Das Aufrufen virtueller Funktionen erfordert einen weiteren Sprung im Speicher. 
Mit Vererbung kann man nur bedingt sicherstellen, dass Typen auch tatsächlich vergleichbar sind. Um die Casts im Vergleich sicher durchzuführen ist ein ordentlicher Mehraufwand nötig. Die Besten fünf Zahlen für 10.000 Werte von `bench.cpp`:
|Vererbt | Vererbt mit static_cast | Templated|
|---|---|---|
| 393872µs | 195935µs | 192937µs |
| 396898µs | 196936µs | 192937µs |
| 397871µs | 197948µs | 192938µs |
| 405718µs | 199950µs | 193338µs |
| 406880µs | 200935µs | 193996µs |
