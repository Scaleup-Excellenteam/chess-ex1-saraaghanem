
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <list>
#include <stdexcept>

template<typename T, typename Comparator>
class PriorityQueue {
private:
    std::list<T> elements;
    Comparator cmp;

public:
    void push(const T& item) {
        auto it = elements.begin();
        while (it != elements.end() && cmp(*it, item) < 0) {
            ++it;
        }
        elements.insert(it, item);
    }

    T poll() {
        if (elements.empty()) {
            throw std::runtime_error("PriorityQueue is empty");
        }
        T top = elements.front();
        elements.pop_front();
        return top;
    }

    bool empty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }

    typename std::list<T>::const_iterator begin() const {
        return elements.begin();
    }

    typename std::list<T>::const_iterator end() const {
        return elements.end();
    }
};

// Example comparator (for int or any type with operator- defined)
struct MyComparator {
    int operator()(int a, int b) const {
        return a - b;
    }
};

#endif // PRIORITY_QUEUE_H
