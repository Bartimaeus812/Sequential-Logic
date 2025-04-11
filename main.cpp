#include <iostream>

using namespace std;

/*
a==1
    a=0 -> 0
    a=1 -> 1
    NO CHANGE
b==0
    b=0 -> 1
    b=1 -> 0
    NOT
c==d
    c=0,d=0 -> 1
    c=0,d=1 -> 0
    c=1,d=0 -> 0
    c=1,d=1 -> 1
    EXCLUSIVE AND
e!=f
    e=0,f=0 -> 0
    e=0,f=1 -> 1
    e=1,f=0 -> 1
    e=1,f=1 -> 0
    EXCLUSIVE OR
*/

int main() {
    int xarr[12] = {0,1,1,0,1,1,0,1,0,0,0,1};
    int q1p = 0, q2p = 1;
    int** table = new int*[12];
    for (int i = 0; i<12; i++) {
        table[i] = new int[10];
    }
    for (int i = 0; i<12; i++) {
        //x changes
        int x = xarr[i];
        //q1 becomes q1p from previous
        int q1 = q1p;
        //q2 becomes q2p from previous
        int q2 = q2p;
        //j1 is q2
        int j1 = q2;
        //k1 is not q2
        int k1 = j1==0;
        //since j1!=k1 : j1=0,k1=1 -> q1p=0 : j1=1,k1=0 -> q1p=1
        q1p = j1;
        //j2 is exclusive and between x and q1
        int j2 = x==q1;
        //k2 is j2
        int k2 = j2;
        //When j2=0,k2=0 -> q2p=q2 : j2=1,k2=1 -> q2p=!q2
        if (j2==1) {
            q2p = q2==0;
        }
        //yp is exclusive and between q2p and exlusive and between x and q1p
        int yp0 = x!=q1p;
        int yp1 = q2p!=yp0;
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