#ifndef UNTITLED_FUNCTIONSTEMPLATETASK_H
#define UNTITLED_FUNCTIONSTEMPLATETASK_H


// Предварительное объявление шаблонных функций
template<typename T>
vector<T> SquaredContainer(const vector<T> &vector_arg);

template<typename T>
const pair<T, T> SquaredContainer(const pair<T, T> &pair_arg);

template<typename K, typename V>
const map<K, V> SquaredContainer(const map<K, V> &map_arg);

template<typename K, typename V>
V& GetRefStrict(const map<K, V> &map_arg, const K& key);

// Объявляем шаблонные функции
template<typename T>
vector<T> SquaredContainer(const vector<T> &vector_arg) {

    vector<T> squared;
    for (const auto i: vector_arg) {
        squared.push_back(i * i);
    }

    return squared;
}


template<typename T>
const pair<T, T> SquaredContainer(const pair<T, T> &pair_arg) {
    pair<T, T> squared = {pair_arg.first * pair_arg.first, pair_arg.second * pair_arg.second};
    return squared;
}

template<typename K, typename V>
const map<K, V> SquaredContainer(const map<K, V> &map_arg) {
    map<K, V> squared;
    for (const auto&[key, value]:map_arg) {
        squared[key] = value * value;
    }

    return squared;
}

template<typename K, typename V>
V& GetRefStrict(map<K, V> &map_arg, const K& key){

    if ( map_arg.find(key) == map_arg.end() ) {
        throw runtime_error("key not found");
    } else {
        return map_arg[key];
    }
}

#endif //UNTITLED_FUNCTIONSTEMPLATETASK_H
