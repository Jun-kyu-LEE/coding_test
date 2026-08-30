#include<iostream>
#include<vector>
using namespace std;

int main() {

    int board[100][100];
    for (int tc = 1; tc <= 10; tc++) {
        int dummy;
        cin >> dummy;

        int c1 = 0;
        int c2 = 0;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> board[i][j];
                if (i == j) {
                    c1 += board[i][j];
                }
                if (i + j == 99) {
                    c2 += board[i][j];
                }
            }
        }
            
       
      
        int d1 = 0;
        int d2 = 0;
        
        for (int i = 0; i < 100; i++) {
            
            int sum_row = 0;
            for (int j = 0; j < 100; j++) {
                sum_row += board[i][j];
                
            }
            d1 = max(d1, sum_row);
        }

        for (int j = 0; j < 100; j++) {
            int sum_col = 0;
            for (int i = 0; i < 100; i++) {
                sum_col += board[i][j];
            }
            d2 = max(d2, sum_col);
        }
        
        int result = max(max(d1, d2), max(c1, c2));
        cout << "#" << tc << " " << result << "\n";


    }
}