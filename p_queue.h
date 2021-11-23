#ifndef P_QUEUE_H
#define P_QUEUE_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct order {
    order(std::string name, unsigned int price) {
        this->name = name;
        this->price = price;
    }
    std::string name;
    unsigned int price;
};

template<typename T>
struct CompareOrderPrice {
    auto operator()(T value, T iteratedValue) {
        return value.price < iteratedValue.price;
    }
};

template<typename T, typename Priority = CompareOrderPrice<T>>
class p_queue {
public:
    p_queue() {}
    explicit p_queue(Priority priorityCondition):prio(priorityCondition) {}

    T operator[](size_t index) {
        return buffer[index];
    }

    void pop() {
        buffer.erase(buffer.begin());
        return;
    }

    void push(T value) {
        auto isLess = [&value, this](T iteratedValue){return this->prio(value, iteratedValue);};
        buffer.insert(std::find_if(buffer.begin(), buffer.end(), isLess), value);
        return;
    }

    void remove(typename std::vector<T>::iterator It) {
        buffer.erase(It);
        return;
    }

    const size_t size() const {
        return buffer.size();
    }

    bool empty() const {
        return buffer.empty();
    }

    const typename std::vector<T>::iterator begin() {
        return buffer.begin();
    }

    const typename std::vector<T>::iterator end() {
        return buffer.end();
    }

    void print() const {
        for(auto e: buffer) {
            std::cout << "Price = " << e.price << "kr, Name = " << e.name << std::endl;
        }
        return;
    }


private:
    std::vector<T> buffer;
    Priority prio;

};

#endif