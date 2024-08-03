// ^B.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int arr1u[26] = { 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 };
    bool arr1d[] = { 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 };
    int n, m;
    char c;
    std::cin >> n >> m >> c;
    char A[100][100];
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            std::cin >> A[row][col];
        }
    }
    
    int dep = 0;
    for (int row = 0; row < n; row++) {

        for (int col = 0; col < m; col++) {

            if (A[row][col] == c) {
                bool move = true;
                int left = col - 1;
                int right = col + 1;
                int down = row + 1;
                int up = row - 1;
                //iff moving is vertical

                //uppp
                if (A[up][col] == c) {
                    while (move){

                        //Gather direction data

                        //down
                        if (A[down][col] != c && down >= m - 1) {
                            if (A[down][col] != '.') {

                                dep++;
                            }
                        }
                        
                    //up
                        if (up >= 0) {
                        if (A[up][col] != '.') {
                            if (A[up][col] == c) {
                                move = true;
                            }
                            else {
                                dep++;
                                move = false;
                            }
                        }
                        else {
                            move = false;
                        }
                      }
                        else {
                                 move = false;
                            }

                     //right
                            if (right <= m - 1) {
                              if (A[row][right] != '.') {
                               if (arr1u[short(A[row][right]) - 65] == 0) {
                                for (int i = 0; i < 26; i++) {
                                    arr1u[i] = 0;
                                }
                                arr1u[short(A[row][right]) - 65] = 1;
                                dep++;
                            }
                         }
                        else if (A[row][right] == '.') {
                            for (int i = 0; i < 26; i++) {
                                arr1u[i] = 0;
                            }
                        }
                      }

                    //left
                        if (left >= 0) {
                        if (A[row][left] != '.') {
                            if (arr1d[short(A[row][left]) - 65] == 0) {
                                for (int i = 0; i < 26; i++) {
                                    arr1d[i] = 0;
                                }
                                arr1d[short(A[row][left]) - 65] = 1;
                                dep++;
                            }
                        }
                        else if (A[row][left] == '.') {
                            for (int i = 0; i < 26; i++) {
                                arr1d[i] = 0;
                            }
                        }
                        }
                         row--;
                         if (row < 0)break;//if we finished all
                    }
                    std::cout << dep;
                    return 0;
                }
                //end

                //downn
                if (A[down][col] == c) {
                    while (move) {

                        //Gather direction data

                        //up
                        if (A[up][col] != c && up >= 0) {
                            if (A[up][col] != '.') {

                                dep++;
                            }
                        }

                        //down
                        if (down >= m-1) {
                            if (A[down][col] != '.') {
                                if (A[down][col] == c) {
                                    move = true;
                                }
                                else {
                                    dep++;
                                    move = false;
                                }
                            }
                            else {
                                move = false;
                            }
                        }
                        else {
                            move = false;
                        }

                        //right
                        if (right <= m - 1) {
                            if (A[row][right] != '.') {
                                if (arr1u[short(A[row][right]) - 65] == 0) {
                                    for (int i = 0; i < 26; i++) {
                                        arr1u[i] = 0;
                                    }
                                    arr1u[short(A[row][right]) - 65] = 1;
                                    dep++;
                                }
                            }
                            else if (A[row][right] == '.') {
                                for (int i = 0; i < 26; i++) {
                                    arr1u[i] = 0;
                                }
                            }
                        }

                        //left
                        if (left >= 0) {
                            if (A[row][left] != '.') {
                                if (arr1d[short(A[row][left]) - 65] == 0) {
                                    for (int i = 0; i < 26; i++) {
                                        arr1d[i] = 0;
                                    }
                                    arr1d[short(A[row][left]) - 65] = 1;
                                    dep++;
                                }
                            }
                            else if (A[row][left] == '.') {
                                for (int i = 0; i < 26; i++) {
                                    arr1d[i] = 0;
                                }
                            }
                        }
                        row++;
                        if (row > n-1)break;//if we finished all
                    }
                    std::cout << dep;
                    return 0;
                }
                //end of down




                //if and only if moving is is horizontal
                if (move) {
                    
                    //Gather direction data

                    //left
                    if (A[row][left] != c && left >= 0) {
                        if (A[row][left] != '.') {

                            dep++;
                        }
                    }

                    //right
                    if (right <= m-1) {
                        if (A[row][right] != '.') {
                            if (A[row][right] == c) {
                                move = true;
                            }
                            else {
                                dep++;
                                move = false;
                            }
                        }
                        else {
                            move = false;
                        }
                    }
                    else {
                        move = false;
                    }

                    //up
                    if (up >= 0) {
                        if (A[up][col] != '.') {
                            if (arr1u[short(A[up][col]) - 65] == 0){
                                for (int i = 0; i < 26; i++) {
                                    arr1u[i] = 0;
                                }
                            arr1u[short(A[up][col]) - 65] = 1;
                            dep++;
                        }
                        }
                        else if (A[up][col] == '.') {
                            for (int i = 0; i < 26; i++) {
                                arr1u[i] = 0;
                            }
                        }
                    }

                    //down
                    if (down <= n - 1) {
                        if (A[down][col] != '.') {
                            if (arr1d[short(A[down][col]) - 65] == 0) {
                                for (int i = 0; i < 26; i++) {
                                    arr1d[i] = 0;
                                }
                                arr1d[short(A[down][col]) - 65] = 1;
                                dep++;
                            }
                        }
                        else if (A[down][col] == '.') {
                            for (int i = 0; i < 26; i++) {
                                arr1d[i] = 0;
                            }
                        }
                    }
                    //end of loop
                    if (!move) {
                        std::cout << dep;
                        return 0;

                   }
                    

                    

                }
               
            }
        }
    }
}

