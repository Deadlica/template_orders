#ifndef P_QUEUE_H
#define P_QUEUE_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template<typename T, typename Priority = std::less<T>>
class p_queue {
public:
    p_queue() {}
    explicit p_queue(Priority priorityCondition):prio(priorityCondition) {}

    void pop() {
        buffer.erase(buffer.begin());
        return;
    }

    void push(T value) {
        auto isLess = [&value, this](T iteratedValue){return this->prio(value, iteratedValue);};
        buffer.insert(std::find_if(buffer.begin(), buffer.end(), isLess), value);
        return;
    }

    const T front() const {
        return buffer[0];
    }

    const size_t size() const {
        return buffer.size();
    }

    bool empty() const {
        return buffer.empty();
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