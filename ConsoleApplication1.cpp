#include <iostream>
#include <map>
using namespace std;

void MapFunc(map<int, int> myMap, int n)
{
    auto it1 = myMap.begin();
    auto it2 = myMap.begin();
    int k = 0;
    advance(it2, 1);
    while (it1->first != myMap.rbegin()->first) {
        if (it1->second == it2->second && it2->first != myMap.rbegin()->first){
            advance(it2, 1);
            k++;
        }
        else if (!k) {
            advance(it1, 1);
            advance(it2, 1);
        }
        else {
            advance(it2, -1);
            int l1 = it1->first, l2 = it2->first;
            for (int i = 1; i <= k+1; i++) {
                if ( i%n == 0) {
                    advance(it1, 1);
                }
                else if (it1->first != l1 && it1->first != l2){
                    advance(it1, -1);
                    myMap.erase(it1++);
                    advance(it1, 1);
                }
                else {
                    advance(it1, 1);
                };
            }
            k = 0;
            advance(it2, 2);
        };
    };
    it1 = myMap.begin();
    cout << "Результат при n = " << n << ":";
    for (int i = 0; i < myMap.size(); i++) {
        cout << " (" << it1->first << ", " << it1->second << ") ";
        it1++;
    };
};


int main()
{
    setlocale(LC_ALL, "Russian");
    int n = 3;
    map<int, int> myMap;
    myMap.emplace(1, 10);
    myMap.emplace(2, 11);
    myMap.emplace(3, 11);
    myMap.emplace(4, 11);
    myMap.emplace(5, 11);
    myMap.emplace(6, 10);
    myMap.emplace(7, 11);
    myMap.emplace(8, 11);
    myMap.emplace(9, 11);
    myMap.emplace(10, 11);
    myMap.emplace(11, 10);

    auto it = myMap.begin();
    cout << "Исходная: " << endl;
    for (int i = 0; i < myMap.size(); i++) {
        cout << " (" << it->first << ", " << it->second << ")";
        it++;
    };
    cout << endl;
    MapFunc(myMap, n);
    
    return 0;
}
