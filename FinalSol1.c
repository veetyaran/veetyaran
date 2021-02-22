#include <stdio.h>
#include <stdlib.h>


int unique(int* mas, int a, int k);


int main(int argc, char *argv[argc])
{   
    int count[5];
    for(int i = 0; i < 5; i++){count[i] = 0;}
    int * indices = malloc(sizeof(int)*(argc));
    
    for(int i = 0; i < argc; i++)
    {
    int flag = 0;
        char *end;
         strtol(argv[i], &end, 10);

        if(end[0] != 0)
        {
            strtol(argv[i], &end, 17);
            
            
            if(end[0] != 0)
            {
                    strtod(argv[i], &end);
                if(end[0] != 0)
                {
                    
                 while(end[0] != 0)
                        {
                            if((strtol(argv[i], &end, 10) == 0)&&(end[0] != ' ') && (end[0]!= 0))
                            {
                            
                                flag++;
                            }

                            argv[i]++;
                            
                        }
                        if(flag == 0)
                        {
                            count[3]++;
                            indices[i] = 0;
                        
                        }
                        else
                        {
                            count[4]++;
                            indices[i] = 1;
                        }
                }
                else{
                    count[2]++;
                    indices[i] = 2;
                }

            }
            else{
                count[1]++;
                indices[i] = 17;
            }


        }
        else
        {
            count[0]++;
            indices[i] = 10;
        }
    }


    //sort order

    int order[2][5];
    for(int i = 0; i < 5; i++){order[0][i] = -1;}
    int start = 0;
    for(int i = 0; i < 5; i++)
    {
        
        for(int j = start; j < argc; j++)
        {
            if(unique(indices, indices[j], j) == 0)
            {
                order[0][i] = indices[j];
                j++;
                while(unique(indices, indices[j], j) != 0)
                {
                    j++;
                    if(j == argc)break;
                }
                    start = j;
                break;
            }
        }
    }
        for(int i = 0; i < 5; i++)
        {
            if(order[0][i] == 10){order[1][i] = count[0];}             
            if(order[0][i] == 17){order[1][i] = count[1];}
            if(order[0][i] == 2){order[1][i] = count[2];}
            if(order[0][i] == 0){order[1][i] = count[3];}
            if(order[0][i] == 1){order[1][i] = count[4];}
            if(order[0][i] == -1){order[1][i] = 0;}
        }
        int out[2][5];
        int max = -1;
        int num = 0;
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(order[1][j] > max)
                {
                    max = order [1][j];
                    num = j;
    
                }
            }
            out[1][i] = max;
            out[0][i] = order[0][num];
            order[1][num] = -2;
            max = -1;
        }
//финальный вывод
    for(int i = 0; i < 5; i++)
        {
            if((out[1][i] != 0))
            {
                if(out[0][i] == 10)//out 10 final
                {
                    if(out[1][i] % 100 == 11 || out[1][i] % 100 == 12 || out[1][i] % 100 == 13 || out[1][i] %100 == 14)//out 10 final
                {

                    printf("%d ", out[1][i]);
                    printf("десятичных чисел:");
                    for(int j = 0; j < argc; j++)
                    {
                        if(indices[j] == 10)printf(" %d", j);
                    }
                    printf("\n");
                }
                else{
                    printf("%d ", out[1][i]);
                    if(out[1][i] % 10 == 1)printf("десятичное число:");
                    if((out[1][i] % 10 >= 2) && (out[1][i] % 10 <= 4))printf("десятичных числа:");
                    if((out[1][i] % 10 >= 5) || (out[1][i] % 10 < 1))printf("десятичных чисел:");
                    for(int j = 0; j < argc; j++)
                    {
                        if(indices[j] == 10)printf(" %d", j);
                    }
                    printf("\n");
                }//10
                }
                 if(out[0][i] == 17) //out 17 final
                 {
                     if((out[1][i]) % 100 == 11 || (out[1][i]) % 100 == 12 || (out[1][i]) % 100 == 13 || (out[1][i]) % 100 == 14)
                     {
                         if(out[0][i] == 17) //out 17 final
                 {
                    printf("%d ", out[1][i]);
                    printf("чисел по основанию 17:");
                       for(int j = 0; j < argc; j++)
                    {
                        if(indices[j] == 17)printf(" %d", j);
                    }
                       printf("\n");
                     }
                     }
                     else{
                    printf("%d ", out[1][i]);
                       if(out[1][i] % 10 == 1)printf("число по основанию 17:");
                       if((out[1][i] % 10 >= 2) && (out[1][i] % 10 <= 4))printf("числа по основанию 17:");
                       if((out[1][i] % 10 >= 5) || (out[1][i] %10 < 1))printf("чисел по основанию 17:");
                       for(int j = 0; j < argc; j++)
                    {
                        if(indices[j] == 17)printf(" %d", j);
                    }
                       printf("\n");
                     }
                }//17
                  if(out[0][i] == 2) //out 2 final
                  {
                      if((out[1][i]) % 100 == 11 || (out[1][i]) % 100 == 12 || (out[1][i]) % 100 == 13 || (out[1][i]) % 100 == 14)
                      {
                          if(out[0][i] == 2) //out 2 final
                  {
                      printf("%d ", out[1][i]);
                    printf("чисел с плавающей точкой:");
                       for(int j = 0; j < argc; j++)
                    {
                        if(indices[j] == 2)printf(" %d", j);
                    }
                       printf("\n");
                  }
                      }
                      else{
                      printf("%d ", out[1][i]);
                    if(out[1][i] % 10 == 1)printf("число с плавающей точкой:");
                       if((out[1][i] % 10 >= 2) && (out[1][i] % 10 <= 4))printf("числа с плавающей точкой:");
                       
                       if((out[1][i] % 10 >= 5) || (out[1][i] %10  < 1))printf("чисел с плавающей точкой:");
                       for(int j = 0; j < argc; j++)
                    {
                        if(indices[j] == 2)printf(" %d", j);
                    }
                       printf("\n");
                  }
                  }//2
                   if(out[0][i] == 0) //out strdec final
                   {
                                if((out[1][i]) % 100 == 11 || (out[1][i]) % 100 == 12 || (out[1][i]) % 100 == 13 || (out[1][i]) % 100 == 14)
                                {
                       if(out[0][i] == 0) //out strdec final
                   {
                       printf("%d ", out[1][i]);
                       printf("списков десятичных чисел, разделённых пробелами:");
                        for(int j = 0; j < argc; j++)
                    {
                        if(indices[j] == 0)printf(" %d", j);
                    }
                        printf("\n");
                   }
                                }
                                else{
                       printf("%d ", out[1][i]);
                       if(out[1][i] % 10 == 1)printf("список десятичных чисел, разделённых пробелами:");
                       if((out[1][i] % 10 >= 2) && (out[1][i] % 10 <= 4))printf("списка десятичных чисел, разделённых пробелами:");
                       
                       if((out[1][i] % 10 >= 5) || (out[1][i] %10 < 1))printf("списков десятичных чисел, разделённых пробелами:");
                        for(int j = 0; j < argc; j++)
                    {
                        if(indices[j] == 0)printf(" %d", j);
                    }
                        printf("\n");
                   }
                   }
                    if(out[0][i] == 1)  //out junk final
                    {
                        if((out[1][i]) % 100 == 11 || (out[1][i]) % 100 == 12 || (out[1][i]) % 100 == 13 || (out[1][i]) % 100 == 14)
                        {
                        if(out[0][i] == 1)  //out junk final
                    {
                        printf("%d ", out[1][i]);
                        printf("строк:");
                    for(int j = 0; j < argc; j++)
                    {
                        if(indices[j] == 1)printf(" %d", j);
                    }
                    printf("\n");
                    }
                        }
                        else{
                        printf("%d ", out[1][i]);
                    if(out[1][i] % 10 == 1)printf("строка:");
                    if((out[1][i] % 10 >= 2) && (out[1][i] % 10 <= 4))printf("строки:");
                    if((out[1][i] % 10 >= 5) || (out[1][i] % 10 < 1))printf("строк:");
                    for(int j = 0; j < argc; j++)
                    {
                        if(indices[j] == 1)printf(" %d", j);
                    }
                    printf("\n");
                    }
                    }
            }
                  
                   
            }

                




    //В массиве ордер лежит порядок появления разных типов данных
    free(indices);
    return 0;
}

int unique(int* mas, int a, int k)
{
    int flag = 0;
    for(int i = 0; i < k; i++)
    {
        if(a == mas[i])flag++;
    }
    return flag;
}