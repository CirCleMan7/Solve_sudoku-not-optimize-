#include <stdio.h>

void displaySolution(int solution[9][9]);
int checkFixedNumInQuestion(int solution[9][9], int question[9][9], int i, int j);
void displayRow(int solution[9][9]);
void setQuestion(int solution[9][9], int question[9][9]);

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

int checkRow(int solution[9][9], int i, int j)
{
    int y = i;
    int x = 0;
    int checkRowNum = 0;

    for (y = i, x = 0; x < 9; x++)
    {
        if (solution[y][x] == solution[i][j])
        {
            checkRowNum++;
            if (checkRowNum > 1)
                return (1);
        }
    }
    return (0);
}

int checkCollum(int solution[9][9], int i, int j)
{
    int y = 0;
    int x = j;
    int checkCollumNum = 0;

    for (y = 0, x = j; y < 9; y++)
    {
        if (solution[y][x] == solution[i][j])
        {
            checkCollumNum++;
            if (checkCollumNum > 1)
                return (1);
        }
    }
    return (0);
}

int checkSameNum(int solution[9][9], int i, int j)
{
    int checkSameBox = 0;
    int box[10];
    int x = 0;
    int y = 0;
    int amountRow = (i + 1) % 3;
    int amountCollum = (j + 1) % 3;
    int a = 0;

    if (checkCollum(solution, i, j) == 1)
        return (1);

    if (checkRow(solution, i, j) == 1)
        return (1);
    

    y = i;
    x = j;
    if (amountRow == 0)
        amountRow = 3;
    if (amountCollum == 0)
        amountCollum = 3;
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
    if (checkSameBox == 1)
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

void findFirstNum(int solution[9][9], int question[9][9], int *firstI, int *firstJ)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (question[i][j] == 0)
            {
                *firstI = i;
                *firstJ = j;
                // printf("firstI = %d | firstJ = %d\n", *firstI, *firstJ);
                return ;
            }
        }
    }
}



int setlimit(int firstI, int firstJ, int *count, int i, int j)
{
    // printf("count = %d\n", *count);
    // printf("firstI = %d | firstJ = %d\n", firstI, firstJ);
    if (*count > 500000000)
    {
        if (firstI == i && firstJ == j)
        {
            *count = 0;
            return(0);
        }
        return (1);
    }
    return (0);
}

int checkfix(int solution[9][9], int question[9][9], int i, int j)
{
    if (question[i][j] != 0)
    {
        return (1);
    }
    return (0);
}

void random(int solution[9][9], int question[9][9])
{
    int randomNum = 1;
    int count = 0;
    int countShow = 0;
    // int firstI = 0;
    // int firstJ = 0;

    // findFirstNum(solution, question, &firstI, &firstJ);
    // int backward = 0;
    for (int i = 0; i < 9; i++)
    {
        setQuestion(solution, question);
        for (int j = 0; j < 9; j++, count++, countShow++)
        {
            // if (countShow / 1000000 == 1)
            // {
            //     displaySolution(solution);
            //     printf("\n");
            //     countShow = 0;
            // }
            // if (backward == 1)
            //     randomNum = solution[i][j] + 1;
            // while (checkfix(solution, question, i, j) == 0)
            // {
                // solution[i][j] = question[i][j];
                // i++;
            // }

            // while (checkfix(solution, question, i, j) == 1)
            // {
            //     solution[i][j] = question[i][j];
            //     j++;
            //     printf("j = %d\n", j);
            // }
            // while (question[i][j] != 0)
            // {
            //     solution[i][j] = question[i][j];
            //     j++;
            //     if (i > 8)
            //         break;
            //     else if (j > 8)
            //     {
            //         j = 0;
            //         i++;
            //     }
            // }
            solution[i][j] = randomNum;
            // printf("this i ; %d | this j : %d \n", i, j);
            // count = 0;
            // displaySolution(solution); 
            // displaySolution(solution);
            if (checkSameNum(solution, i, j) == 1 || randomNum > 9 || checkFixedNumInQuestion(solution, question, i, j) == 1)
            {
                // displaySolution(solution);
                // printf("before j = %d\n", j);
                if (randomNum > 9)
                {
                    // if (checkfix(solution, question, i, j) == 0)
                        // solution[i][j] = question[i][j];
                    // else
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
                    // count = 0;  
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
                // count++;
                // randomNum = 0;
            }
            else
            {
                // count = 0;
                randomNum = 0;
            }
            randomNum++;
            // printf("after j = %d\n", j);
            // printf("randomNumber = %d\n", randomNum);
            // displaySolution(solution);
            // printf("\n");

        }
        // displaySolution(solution);
        // printf("%d\n", solution[0][3]);
        // displayRow(solution);
        // printf("%d\n", solution[0][0]);
    }
}

void setInitial(int solution[9][9], int question[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            solution[i][j] = 0;
        }
    }
}

void setQuestion(int solution[9][9], int question[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (question[i][j] != 0)
            {
                solution[i][j] = question[i][j];
                // printf("solution[%d][%d] = %d | question[%d][%d] = %d\n", i, j, solution[i][j], i, j, question[i][j]);
            }
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

void displayRow(int solution[9][9])
{
    for (int i = 0; i < 9; i++)
        printf("%d ", solution[0][i]);
    printf("\n");
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

    int zero[9][9] =
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0 ,0, 0},
        {0, 0, 0, 0, 0, 0, 0 ,0, 0},
        {0, 0, 0, 0, 0, 0, 0 ,0, 0},
        {0, 0, 0, 0, 0, 0, 0 ,0, 0},
        {0, 0, 0, 0, 0, 0, 0 ,0, 0}
    };

    int question[9][9] = {
        {0, 7, 0, 0, 4, 0, 0, 5, 0},
        {0, 9, 0, 7, 6, 0, 0, 0, 1},
        {0, 6, 0, 0, 0, 0, 0, 2, 0},
        {5, 0, 0, 0, 7, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0 ,0, 0},
        {0, 4, 0, 0, 8, 0, 9 ,0, 0},
        {0, 0, 0, 2, 0, 6, 0 ,0, 0},
        {4, 0, 0, 0, 0, 8, 0 ,0, 2},
        {3, 0, 0, 0, 1, 0, 0 ,8, 0}
    };

    int questiontestMedium[9][9] = {
        {5, 0, 1, 2, 0, 7, 0, 8, 0},
        {6, 4, 0, 1, 0, 3, 2, 0, 0},
        {0, 2, 7, 9, 5, 0, 6, 0, 3},
        {7, 0, 0, 4, 0, 0, 0, 9, 6},
        {0, 0, 6, 0, 0, 0, 8 ,0, 2},
        {2, 0, 8, 0, 3, 9, 7 ,0, 0},
        {0, 0, 0, 0, 4, 0, 3 ,0, 8},
        {3, 7, 0, 8, 0, 0, 0 ,6, 1},
        {1, 0, 0, 0, 0, 0, 4 ,0, 0}
    };

    int questiontestHard[9][9] = {
        {3, 8, 2, 0, 6, 7, 0, 9, 1},
        {0, 0, 0, 0, 1, 3, 2, 0, 0},
        {0, 9, 6, 0, 4, 8, 3, 7, 5},
        {9, 2, 0, 0, 0, 0, 6, 5, 0},
        {0, 0, 0, 0, 0, 6, 0 ,4, 9},
        {0, 0, 4, 3, 0, 0, 0 ,0, 0},
        {0, 1, 9, 7, 0, 2, 0 ,0, 0},
        {4, 3, 0, 6, 0, 0, 0 ,0, 7},
        {0, 0, 0, 0, 0, 9, 5 ,0, 0}
    };

     int questiontestExpert[9][9] = {
        {2, 0, 0, 0, 3, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 7},
        {8, 0, 5, 0, 0, 4, 1, 0, 0},
        {5, 0, 6, 0, 8, 0, 0, 0, 9},
        {0, 7, 0, 0, 0, 6, 0, 0, 0},
        {0, 2, 0, 0, 0, 0, 5, 0, 0},
        {0, 0, 0, 0, 9, 0, 0, 3, 0},
        {0, 6, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 4, 0, 0, 8, 7, 0, 0}
    };

    int questiontestExtreme[9][9] = {
        {1, 0, 3, 0, 0, 4, 0, 8, 7},
        {0, 0, 0, 9, 0, 0, 0, 6, 0},
        {0, 8, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 0, 0, 0, 0, 0, 0},
        {5, 0, 7, 0, 0, 3, 0 ,0, 1},
        {0, 0, 0, 0, 4, 0, 3 ,0, 0},
        {0, 4, 0, 0, 0, 0, 0 ,0, 8},
        {8, 0, 5, 0, 6, 0, 0 ,7, 0},
        {0, 2, 0, 0, 0, 5, 0 ,0, 0}
    };

    setInitial(solution, questiontestExtreme);
    displaySolution(solution);
    random(solution, questiontestExtreme);
    printf("\n");
    printf("\n");
    displaySolution(solution);
    // testMatrix(question);
    // int firstI = 0;
    // int firstJ = 0;
    // findFirstNum(solution, question, &firstI, &firstJ);
    
    return 0;
    // printf("question = %d\n", question[3][0]);
    // 3 4 5 2 6 9 7 8 1
}