#include <iostream>

using namespace std;

int main() {
    int xarr[12] = {0,1,1,0,1,1,0,1,0,0,0,1};
    int q1p = 0, q2p = 1;
    int** table = new int*[12];
    for (int i = 0; i<12; i++) {
        table[i] = new int[10];
    }
    for (int i = 0; i<12; i++) {
        int x = xarr[i];
        int q1 = q1p;
        int q2 = q2p;
        int j1 = q2;
        int k1 = j1==1 ? 0 : 1;
        if (j1==k1) {
            if (j1==1) {
                q1p = q1==1 ? 0 : 1;
            }
        } else {
            q1p = j1==1 && k1==0 ? 1 : 0;
        }
        int j2 = x==q1;
        int k2 = j2;
        if (j2==k2) {
            if (j2==1) {
                q2p = q2==1 ? 0 : 1;
            }
        } else {
            q2p = j2==1 && k2==0 ? 1 : 0;
        }
        int yp0 = x!=q1p ? 1 : 0;
        int yp1 = q2p!=yp0 ? 1 : 0;
        table[i][0] = x;
        table[i][1] = j1;
        table[i][2] = k1;
        table[i][3] = q1;
        table[i][4] = q1p;
        table[i][5] = j2;
        table[i][6] = k2;
        table[i][7] = q2;
        table[i][8] = q2p;
        table[i][9] = yp1;
    }
    cout << "X   J1  K1  Q1  Q1+ J2  K2  Q2  Q2+ Y+\n";
    for (int i = 0; i<12; i++) {
        for (int j = 0; j<10; j++) {
            cout << table[i][j] << "   ";
        }
        cout << '\n';
    }
}