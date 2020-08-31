//
//  main.c
//  CalculateTrainer
//
//  Created by Eric on 16-4-23.
//  Copyright (c) 2016年 Bakantu Eric. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, const char * argv[]) {
    int i;
    int sign[4] = {0, 0, 0, 0},f_num,s_num,input_num,q_num,max,p_sign;
    int right = 0, wrong = 0;
    int sign_right[4] = {0, 0, 0, 0},sign_question[4] = {0, 0, 0, 0};
    double aver_time = 0;
    time_t start = 0,end;
    char ch;
    srand((unsigned int)time(NULL));
    system("clear");
    printf("=======================================================================\n");
    printf("      Wellcome to Calculate Trainer(BY Eric.Bakantu 2016.4.23).\n");
    printf("                            V 1.0.0\n");
    printf("=======================================================================\n");
    while (1){
        printf("Let's start a calculate training.\n");
        printf("#How many question(s): ");
        scanf("%d",&q_num);
        printf("#Which sign(0.+ 1.- 2.* 3./ q to end): ");
        while((ch = getchar()) != 'q'){
            sign[ch-48] = 1;
        }
        printf("#MAX NUM: ");
        scanf("%d",&max);
        system("clear");
        for (i = 0; i < q_num; i++){
            printf("------------[R %d]--[%d of %d]--[W %d]-----------\n",right,i+1,q_num,wrong);
            while (sign[(p_sign = rand()%4)] == 0);
            f_num = rand()%max;
            usleep(1000);
            s_num = rand()%max;
            if (p_sign == 0){
                printf("%d + %d = ",f_num,s_num);
                start = time(NULL);
                scanf("%d",&input_num);
                end = time(NULL);
                sign_question[0]++;
                if (input_num == f_num+s_num) {
                    printf("----------------------------------------------\n");
                    printf("#RESULT : √\n");
                    right++;
                    sign_right[0]++;
                }
                else {
                    printf("----------------------------------------------\n");
                    printf("#RESULT : ×\n");
                    printf("RRIGHT ANSWER: %d\n",f_num+s_num);
                    wrong++;
                    usleep((unsigned int)1000000);
                }
                aver_time += difftime(end,start);
                printf("$TIME : %.0fs\n",difftime(end,start));
            }
            if (p_sign == 1){
                printf("%d - %d = ",f_num,s_num);
                start = time(NULL);
                scanf("%d",&input_num);
                end = time(NULL);
                sign_question[1]++;
                if (input_num == f_num-s_num) {
                    printf("----------------------------------------------\n");
                    printf("#RESULT : √\n");
                    right++;
                    sign_right[1]++;
                }
                else {
                    printf("----------------------------------------------\n");
                    printf("#RESULT : ×\n");
                    printf("RRIGHT ANSWER: %d\n",f_num-s_num);
                    wrong++;
                    usleep((unsigned int)1000000);
                }
                aver_time += difftime(end,start);
                printf("$TIME : %.0fs\n",difftime(end,start));
            }
            if (p_sign == 2){
                printf("%d * %d = ",f_num,s_num);
                start = time(NULL);
                scanf("%d",&input_num);
                end = time(NULL);
                sign_question[2]++;
                if (input_num == f_num*s_num) {
                    printf("----------------------------------------------\n");
                    printf("#RESULT : √\n");
                    right++;
                    sign_right[2]++;
                }
                else {
                    printf("-------------------------------------------------\n");
                    printf("#RESULT : ×\n");
                    printf("RRIGHT ANSWER: %d\n",f_num*s_num);
                    wrong++;
                    usleep((unsigned int)1000000);
                }
                aver_time += difftime(end,start);
                printf("$TIME : %.0fs\n",difftime(end,start));
            }
            if (p_sign == 3){
                printf("%d / %d = ",f_num*s_num,s_num);
                start = time(NULL);
                scanf("%d",&input_num);
                end = time(NULL);
                sign_question[3]++;
                if (input_num == f_num) {
                    printf("----------------------------------------------\n");
                    printf("#RESULT : √\n");
                    right++;
                    sign_right[3]++;
                }
                else {
                    printf("----------------------------------------------\n");
                    printf("#RESULT : ×\n");
                    printf("RRIGHT ANSWER: %d\n",f_num);
                    wrong++;
                    usleep(800000);
                }
                aver_time += difftime(end,start);
                printf("$TIME : %.2fs\n",difftime(end,start));
            }
            usleep(800000);
            system("clear");
        }
        printf("------------------------------------[RESULT]-------------------------------------\n");
        printf("[ RAW: %.2lf %% ] [ +: %.2lf %% ] [ -: %.2lf %% ] [ *: %.2lf %% ] [ /:%.2lf %% ]\n",\
               (double)right/q_num*100,\
               sign_question[0] == 0 ? -1 : (double)sign_right[0]/sign_question[0]*100,\
               sign_question[1] == 0 ? -1 : (double)sign_right[1]/sign_question[1]*100,\
               sign_question[2] == 0 ? -1 : (double)sign_right[2]/sign_question[2]*100,\
               sign_question[3] == 0 ? -1 : (double)sign_right[3]/sign_question[3]*100);
        printf("Average Time : %.2f\n",aver_time/q_num);
        printf("------------------------------------[RESULT]-------------------------------------\n");
        printf("Press any key to start the next training...");
        getchar();
        getchar();
        system("clear");
    }
    return 0;
}
