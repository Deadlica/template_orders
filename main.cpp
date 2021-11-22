#include <iostream>
#include <ctime>
#include "p_queue.h"

void printSales(p_queue<order> sellOrders, p_queue<order> buyOrders);
void addSellers(p_queue<order>& sellOrders);
void addBuyers(p_queue<order>& buyOrders);

int main() {
    system("clear");
    srand((unsigned) time(0));
    p_queue<order> sellOrders;
    p_queue<order> buyOrders;

    addSellers(sellOrders);
    addBuyers(buyOrders);
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
    for(size_t sIndex = 0, bIndex = 0; sIndex < sellOrders.size() && bIndex < buyOrders.size();) {
        if(sellOrders[sIndex].price <= buyOrders[bIndex].price && sellOrders[sIndex].name != buyOrders[bIndex].name) {
            salesPrice = sellOrders[sIndex].price;
            std::cout << "Köpare: " << buyOrders[bIndex].name <<
            ", Säljare: " << sellOrders[sIndex].name << ", Pris: " << salesPrice << "kr" << std::endl;
            sIndex++;
            bIndex++;
        }
        else {
            bIndex++;
        }
    }
}

void addSellers(p_queue<order>& sellOrders) {
    for(int i = 0; i < 7; i++) {
        sellOrders.push(order("Erik Pendel", rand() % 15 + 15));
    }
    for(int i = 0; i < 7; i++) {
        sellOrders.push(order("Jarl Wallenburg", rand() % 15 + 15));
    }
    for(int i = 0; i < 7; i++) {
        sellOrders.push(order("Joakim von Anka", rand() % 15 + 15));
    }
}

void addBuyers(p_queue<order>& buyOrders) {
    for(int i = 0; i < 7; i++) {
        buyOrders.push(order("Erik Pendel", rand() % 15 + 15));
    }
    for(int i = 0; i < 7; i++) {
        buyOrders.push(order("Jarl Wallenburg", rand() % 15 + 15));
    }
    for(int i = 0; i < 7; i++) {
        buyOrders.push(order("Joakim von Anka", rand() % 15 + 15));
    }
}