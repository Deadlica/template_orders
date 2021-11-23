#include <ctime>
#include "p_queue.h"

struct order {
    order(std::string name, unsigned int price) {
        this->name = name;
        this->price = price;
    }
    std::string name;
    unsigned int price;
};

template<>
struct std::less<order> {
    bool operator()(order value, order currentElement) {
        return value.price < currentElement.price;
    }
};

template<typename T>
struct CompareOrderPrice {
    auto operator()(T value, T iteratedValue) {
        return value.price < iteratedValue.price;
    }
};

void printSales(p_queue<order> sellOrders, p_queue<order> buyOrders);
void addBrokers(p_queue<order>& queue);

int main() {
    system("clear");
    srand((unsigned) time(0));
    p_queue<order> sellOrders;
    p_queue<order> buyOrders;
    addBrokers(sellOrders);
    addBrokers(buyOrders);
    std::cout << "Sellers:" << std::endl;
    sellOrders.print();
    std::cout << std::endl << "Buyers:" << std::endl;
    buyOrders.print();
    std::cout << std::endl << "Sales:" << std::endl;
    printSales(sellOrders, buyOrders);

    return 0;
}

void printSales(p_queue<order> sellOrders, p_queue<order> buyOrders) {
    unsigned int salesPrice;
    while(!sellOrders.empty() && !buyOrders.empty()) {
        if(sellOrders.front().price <= buyOrders.front().price) {
            salesPrice = sellOrders.front().price;
            std::cout << "Köpare: " << buyOrders.front().name <<
            ", Säljare: " << sellOrders.front().name << ", Pris: " << salesPrice << "kr" << std::endl;
            sellOrders.pop();
            buyOrders.pop();
        }
        else {
            buyOrders.pop();
        }
    }
}

void addBrokers(p_queue<order>& queue) {
    for(int i = 0; i < 7; i++) {
        queue.push(order("Erik Pendel", rand() % 15 + 15));
    }
    for(int i = 0; i < 7; i++) {
        queue.push(order("Jarl Wallenburg", rand() % 15 + 15));
    }
    for(int i = 0; i < 7; i++) {
        queue.push(order("Joakim von Anka", rand() % 15 + 15));
    }
}
