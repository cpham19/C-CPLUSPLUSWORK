#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>
#include "mapentry.h"
#include <algorithm>

using namespace std;

template<class K, class V> class Map {
    public:
        Map();
        void addEntry(K keyIn, V valueIn);
        void addEntry(MapEntry<K, V>);
        V* findValue(K keyIn);
        void deleteEntry(K keyIn);
        void remapKey(K keyIn, V valueIn);
        template <class C, class F> friend ostream &operator<<(ostream &output, const Map<C, F> &m);
    private:
        vector<MapEntry<K, V> > pairs;
};

template<class K, class V> ostream &operator<<(ostream &output, const Map<K, V> &m) {
    for (MapEntry <K, V> e : m.pairs) {
        output << e;
    }
    
    output << endl;
    return output;
}
template<class K, class V> Map<K, V>::Map() = default;

template<class K, class V> void Map<K, V>::addEntry(K keyIn, V valueIn) {
    if (!findValue(keyIn)) {
        pairs.push_back(MapEntry<K, V> (keyIn, valueIn));
    }
    sort(pairs.begin(), pairs.end());
}

template<class K, class V> void Map<K, V>::addEntry(MapEntry<K, V> entryIn) {
    if (!findValue(entryIn.getKey())) {
        pairs.push_back(entryIn);
    }
}

template<class K, class V> V* Map<K, V>::findValue(K keyIn) {
    for (MapEntry<K, V> p : pairs) {
        if (p.getKey() == keyIn) {
            V *vptr = new V;
            *vptr = p.getValue();
            return vptr;
        }
    }
    return nullptr;
}

template<class K, class V> void Map<K, V>::deleteEntry(K keyIn) {
    vector<int> matches;
    for (int counter = 0; counter < pairs.size(); counter++) {
        if (pairs[counter].getKey() == keyIn) {
            matches.push_back(counter);
        }
    }
    for (int counter = 0; counter < matches.size(); counter++) {
        pairs.erase(matches[counter]);
    }
}

template<class K, class V> void Map<K, V>::remapKey(K keyIn, V valueIn) {
    for (MapEntry<K, V> p : pairs) {
        if (p.getKey == keyIn) {
            p.setValue(valueIn);
        }
    }
}

#endif