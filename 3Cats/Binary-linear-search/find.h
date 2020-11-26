#pragma once

template<typename T, typename Iterator>
Iterator Find(const T &value, Iterator first, Iterator last, std::random_access_iterator_tag) {
    Iterator end = last;
    while (first != last) {
        Iterator mid = first + ((last - first) / 2);
        if (*mid < value) {
            first = mid + 1;
        } else {
            last = mid;
        }
    }
    if (*last == value) return last;
    return end;
}

template<typename T, typename Iterator>
Iterator Find(const T &value, Iterator first, Iterator last, std::bidirectional_iterator_tag) {
    for (; first != last; ++first) {
        if (*first == value) {
            return first;
        }
    }
    return last;
}

template<typename T, typename Iterator>
Iterator Find(const T &value, Iterator first, Iterator last) {
    typedef typename std::iterator_traits<Iterator>::iterator_category category;
    return Find(value,first,last,category());
}