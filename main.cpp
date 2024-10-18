#include <iostream>
#include <array>

int main() {
    using namespace std;

    int payment, price, remain, charge;
    cout << "料金 > ";
    cin >> payment;
    cout << "支払金額 > ";
    cin >> price;
    charge = price - payment;

    array<int, 4> charge_by_coin = {0};
    array<int, 4> coin_types = {500, 100, 50, 10};

    for (auto [itr_k, itr_v] = pair{coin_types.begin(), charge_by_coin.begin()}; itr_k != coin_types.end(); ++itr_k, ++itr_v) {
        *itr_v = charge / *itr_k;
        charge -= *itr_k * *itr_v;
    } 
    
    for (auto [itr_k, itr_v] = pair{coin_types.begin(), charge_by_coin.begin()}; itr_k != coin_types.end(); ++itr_k, ++itr_v) {
        cout << *itr_k << "円硬貨: " << -*itr_v << "枚\n";
    }
}