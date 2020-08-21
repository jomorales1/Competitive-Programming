#include <bits/stdc++.h>
using namespace std;

int main() {
    int depth;
    cin >> depth;
    int distance;
    int cache;
    long long iterator = 1;
    cout << iterator << "\n";
    cout.flush();
    cin >> distance;

    if(distance > 30){ //cout << "this shouldn't' happend";
        return -1;
    }

    while(distance >0){

        cout << iterator * 2 + 1 << "\n";
        cout.flush();
        cin >> cache; //vamos a preguntar la distancia de irnos a la derecha

        if(cache<distance){// si reduce nos vamos a la derecha
            iterator = iterator * 2 + 1;
            distance = cache;
        }
        else{// si no a la izquierda
            iterator= iterator*2;
            distance--;
        }


    }
    cout << "!" << " " << iterator << "\n";
}