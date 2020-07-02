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

## Vorteile Nachteile Vererbung vs Templates
# Templates
Mit Templates lassen sich zu Kompilierzeit ges