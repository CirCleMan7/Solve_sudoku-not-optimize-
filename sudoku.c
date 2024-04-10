#include <stdio.h>

void displaySolution(int solution[9][9]);
int checkFixedNumInQuestion(int solution[9][9], int question[9][9], int i, int j);

int checkSameInBox(int box[9])
{
    int fixNum = 0;
    int same = 0;

    for (int i = 0; box[i] != 0; i++)
    {
        fixNum = box[i];
        for (int j = 0; box[j] != 0; j++)
        {
            if (box[j] == box[i])
                same++;
            if (same > 1)
                return (1);
        }
        same = 0;
    }
    return (0);
}

int checkSameNum(int solution[9][9], int i, int j)
{
    int checkRow = 0;
    int checkCollum = 0;
    int checkTopLeft = 0;
    int checkBottomRight = 0;
    int checkExtraCase = 0;
    int checkSameBox = 0;
    int box[10];
    int x = 0;
    int y = 0;

    for (y = i, x = 0; x < 9; x++)
    {
        if (solution[y][x] == solution[i][j])
        {
            checkRow++;
        }
    }
    
    for (y = 0, x = j; y < 9; y++)
    {
        if (solution[y][x] == solution[i][j])
        {
            checkCollum++;
        }
    }


    y = i;
    x = j;
    int amountRow = (i + 1) % 3;
    if (amountRow == 0)
        amountRow = 3;
    int amountCollum = (j + 1) % 3;
    if (amountCollum == 0)
        amountCollum = 3;
    x = j;
    int a = 0;
    for (y = i; amountRow > 0 && y >= 0; y--, amountRow--)
    {
        for (; amountCollum > 0 && x >= 0; x--, amountCollum--)
        {
            box[a] = solution[y][x];
            a++;
        }
        amountCollum = 3;
        x = j;
        while ((x + 1) % 3 != 0)
        {
            x++;
        }
    }
    box[a] = 0;

    checkSameBox = checkSameInBox(box);


    // y = i;
    // x = j;
    // if (((y + 1) % 3 == 0 && (x + 1) % 3 == 0) && ((x + 1) != 0))
    // {
    //     for (int time = 0; time < 3; x--, y--, time++)
    //     {
    //         if (solution[x][y] == solution[i][j])
    //         {
    //             checkTopLeft++;
    //             // printf("Topleft\n");
    //         }
    //     }
    // }
    y = i;
    x = j;
    // int checkSameBox = 1;
    // if (((y + 1) % 3 == 0 && (x + 1) % 3 == 0) && ((x + 1) != 0))
    // {
    //     int sum = 0;
    //     for (int amountRow = 0; amountRow < 3, y >= 0; y--, amountRow++)
    //     {
    //         for (int amountCollum = 0, x = j; amountCollum < 3, x >= 0; x--, amountCollum++)
    //         {
    //             i
    //         }
    //     }
    //     if (sum != 45)
    //     {
    //         checkSameBox = 0;
    //     }
    //     // displaySolution(solution);
    // }

    // for (x = i, y = j; x > 0 && y > 0; x++, y++)
    // {
    //     if (solution[x][y] == solution[i][j])
    //     {
    //         checkBottomRight++;
    //         printf("Bottomright\n");
    //     }
    //     printf(".");
    // }

    // y = i;
    // x = j;
    // if (((x + 1) % 3 == 0 && (y + 1) % 3 == 0) && ((x + 1) != 9))
    // {
    //     for (int amount = 0; amount < 3; x++, y--, amount++)
    //     {
    //         if (solution[y][x] == solution[i][j])
    //         {
    //             checkBottomRight++;
    //             // printf("checkwith solution[%d][%d] : %d but real = %d\n", x, y, solution[y][x], solution[i][j]);
    //         }
    //         // displaySolution(solution);
    //     }
    // }

    // if ((x + 1) % 3 == 0)
    

    // for ()
    // printf("eiei\n");
    if (checkCollum > 1 || checkRow > 1 || checkSameBox == 1)
    {
        return (1);
    }

    return (0);
}

void displaySolution(int solution[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", solution[i][j]);
        }
        printf("\n");
    }
}

void random(int solution[9][9], int question[9][9])
{
    int randomNum = 1;
    int count = 0;
    int backward = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            // if (backward == 1)
            //     randomNum = solution[i][j] + 1;
            solution[i][j] = randomNum;
            // printf("this i ; %d | this j : %d \n", i, j);
            // count = 0;
            // displaySolution(solution); 
            if (checkSameNum(solution, i, j) == 1 || randomNum > 9 || checkFixedNumInQuestion(solution, question, i, j) == 1)
            {
                // printf("before j = %d\n", j);
                if (randomNum > 9)
                {
                    solution[i][j] = 0;
                    if (j == 0)
                    {
                        j = 7;
                        i -= 1;
                        randomNum = solution[i][j + 1];
                    }
                    else
                    {
                        j -= 2;
                        randomNum = solution[i][j + 1];
                        // printf("eiei\n");
                    }
                    count = 0;  
                    // printf("i : %d | j : %d\n", i, j);
                    // printf("randomNumber = %d\n", randomNum);
                    // printf("\n");
                    // backward = 1;
                    // printf("eiei\n");
                }
                else
                {
                    j--;
                    // printf("eiei\n");
                    // backward = 0;
                }
                count++;
                // randomNum = 0;
            }
            else
            {
                count = 0;
                randomNum = 0;
            }
            randomNum++;
            // printf("after j = %d\n", j);
            // printf("randomNumber = %d\n", randomNum);
            // displaySolution(solution);
            // printf("\n");

        }
        // displaySolution(solution);
    }
}

void setInitial(int solution[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            solution[i][j] = 0;
        }
    }
}

void setInitialArray(int box[10])
{
    for (int i = 0; i < 10; i++)
    {
        box[i] = 0;
    }
}

void testMatrix(int question[9][9])
{
    int checkRow = 0;
    int checkCollum = 0;
    int checkTopLeft = 0;
    int checkBottomRight = 0;
    int x = 0;
    int y = 0;
    int i = 8;
    int j = 5;

    // for (x = i, y = j; x >= 0 && y >= 0; x--, y--)
    // {
    //     printf("%d\n", question[x][y]);
    //     // if (solution[x][y] == solution[i][j])
    //     // {
    //     //     checkTopLeft++;
    //     //     // printf("Topleft\n");
    //     // }
    // }

    // y = i;
    // x = j;
    // if (((y + 1) % 3 == 0 && (x + 1) % 3 == 0) && ((x + 1) != 0))
    // {
    //     for (int time = 0; time < 3; x--, y--, time++)
    //     {
    //     //     if (solution[x][y] == solution[i][j])
    //     //     {
    //     //         checkTopLeft++;
    //     //         // printf("Topleft\n");
    //     //     }
    //         printf("%d\n", question[y][x]);
    //     }
    // }

    // y = i;
    // x = j;
    // int checkSameBox = 1;
    // if (((y + 1) % 3 == 0 && (x + 1) % 3 == 0) && ((x + 1) != 0))
    // {
    //     int sum = 0;
    //     for (int amountRow = 0; amountRow < 3; y--, amountRow++)
    //     {
    //         for (int amountCollum = 0, x = j; amountCollum < 3; x--, amountCollum++)
    //         {
    //             printf("%d\n", question[y][x]);
    //             sum += question[y][x];
    //         }
    //     }
    //     printf("sum = %d \n", sum);
    //     if (sum != 45)
    //     {
    //         printf("False\n");
    //     }
    //     else
    //         printf("True\n");
    // }

    y = i;
    x = j;
    int checkSameBox = 1;
    // if (((y + 1) % 3 == 0 && (x + 1) % 3 == 0) && ((x + 1) != 0))
    // {
    int sum = 0;
    int amountRow = (i + 1) % 3;
    if (amountRow == 0)
        amountRow = 3;
    int amountCollum = (j + 1) % 3;
    if (amountCollum == 0)
        amountCollum = 3;
    // int amountCollum = (j + 1) % 3;
    // if (amountCollum == 0)
    //     amountCollum = 3;
    int box[10];

    printf("amountRow : %d\n", amountRow);
    x = j;
    int a = 0;
    // printf("amountCollum : %d\n", amountCollum);
    for (y = i; amountRow > 0 && y >= 0; y--, amountRow--)
    {
        for (; amountCollum > 0 && x >= 0; x--, amountCollum--)
        {
            box[a] = question[y][x];
            printf("%d\n", question[y][x]);
            a++;
        }
        amountCollum = 3;
        x = j;
        while ((x + 1) % 3 != 0)
        {
            x++;
        }
    }
    
    box[a] = 0;

    // for (int i = 0; box[i] != 0; i++)
    // {
    //     printf("box[%d] = %d\n", i, box[i]);
    // }

    // printf("this is %d\n", checkSameInBox(box));
        // if (sum != 45)
        // {
        //     checkSameBox = 0;
        // }
        // // displaySolution(solution);
    // }

}


int checkFixedNumInQuestion(int solution[9][9], int question[9][9], int i, int j)
{
    if (solution[i][j] != question[i][j] && question[i][j] != 0)
    {
        // printf("solution[%d][%d] = %d | question[%d][%d] = %d\n", i, j, solution[i][j], i, j, question[i][j]);
        // printf("Notsame\n");
        return (1);
    }      
    // printf("same\n");
    return (0);
}


int main()
{
    int solution[9][9];

    setInitial(solution);

    int question[9][9] = {
        {5, 0, 0, 2, 0, 0, 9, 8, 0},
        {6, 4, 0, 0, 3, 8, 0, 5, 0},
        {8, 0, 7, 9, 4, 0, 0, 0, 3},
        {0, 5, 3, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 9, 0, 7 ,4, 0},
        {4, 9, 0, 0, 5, 0, 0 ,0, 2},
        {0, 0, 2, 5, 0, 0, 3 ,0, 0},
        {0, 7, 0, 0, 0, 9, 5 ,6, 1},
        {1, 0, 5, 3, 0, 7, 4 ,0, 9}
    };

    int questiontest[9][9] = {
        {9, 1, 0, 6, 8, 0, 0, 0, 0},
        {4, 0, 7, 0, 0, 0, 0, 6, 5},
        {0, 8, 0, 2, 0, 0, 7, 0, 1},
        {2, 0, 0, 0, 0, 1, 0, 7, 0},
        {0, 0, 0, 0, 0, 0, 0 ,0, 8},
        {0, 0, 0, 0, 4, 5, 0 ,2, 0},
        {0, 0, 0, 0, 0, 9, 5 ,8, 0},
        {0, 9, 0, 0, 6, 0, 0 ,3, 7},
        {7, 6, 0, 0, 0, 0, 9 ,0, 2}
    };

    random(solution, questiontest);
    printf("\n");
    displaySolution(solution);
    // testMatrix(question);
    
    return 0;
    // printf("question = %d\n", question[3][0]);
}