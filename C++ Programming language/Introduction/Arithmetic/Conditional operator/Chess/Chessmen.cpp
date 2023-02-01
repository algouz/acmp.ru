#include<bits/stdc++.h>
using namespace std;
int main(){
    int x1, y1, x2, y2;
    char X1, X2;
    cin >> X1 >> y1 >> X2 >> y2;
    x1 = X1 - 64;
    x2 = X2 - 64;
    bool nobody = true;

    if(abs(x1-x2) == abs(y1-y2) || x1 == x2 || y1 == y2){
        cout << "Queen\n";
        nobody = false;
    }
    if(x1 == x2 || y1 == y2) cout << "Rook\n";
    if(abs(x1-x2) == abs(y1-y2)) cout << "Bishop\n";
    if(abs(x1-x2)*abs(y1-y2)==2){
        cout << "Knight\n";
        nobody = false;
    }
    if(max(abs(x1-x2), abs(y1-y2)) == 1) cout << "King\n";
    if(x1==x2 && y1 > 1 && (y1+1==y2 || (y1==2 && y2==4))) cout << "Pawn\n";
    
    if(nobody) cout << "Nobody";    
    return 0;
}