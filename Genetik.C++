*
find maximum value of:
h(x,y) = (cos x^2 * sin y^2) + (x+y)
constraint: -1 <= x <= 2 and -1 <= y <= 1
*/
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <time.h>
using namespace std;

int main(){
    int kromosom1[6], kromosom2[6], kromosom3[6], kromosom4[6];
    void Generation(int k1[6], int k2[6], int k3[6], int k4[6]);
    int initKromosom(int chrome[6]);

    srand(time(0));

    initKromosom(kromosom1);
    initKromosom(kromosom2);
    initKromosom(kromosom3);
    initKromosom(kromosom4);
    Generation(kromosom1, kromosom2, kromosom3, kromosom4);

    return 0;
}

void initKromosom(int chrome[6]){// prosedur initkromosom metode pendekodean kromosom adalah dengan metode two complement dimana bit pertama dan kedua adalah biner
                                    // dan bit ketiga adalah sign bit pertama dan kedua berada pada posisi kotak ke 3 dan 2 sedangkan sign berada pada posisi kotak
                                    // kotak pertama 2 fungsi decode berbeda Decode X dan Decode Y.
    int i, bit, hold;

    //Generate Chromosome

    for (i=0; i < 6; i++){
        bit = rand() % 2;
        chrome[i] = bit;
    }

    //Check and fixing DNA of x

    if(chrome[0] == 1 && chrome[1] == 1 && chrome[2] == 1){
        chrome[1] = 0;
    } else if (chrome[0] == 1 && chrome[1] == 1 && chrome[2] == 0){
        chrome[1] = 0;
        chrome[2] = 1;
    } else if(chrome[0] == 0 && chrome[1] == 1 && chrome[2] == 1){
        chrome[2] = 0;
    }

    //Check and fixing DNA of y

    if(chrome[3] == 1 && chrome[4] == 1 && chrome[5] == 1){
        chrome[4] = 0;
    } else if(chrome[3] == 1 && chrome[4] == 1 && chrome[5] == 0){
        chrome[4] = 0;
        chrome[5] = 1;
    } else if(chrome[3] == 0 && chrome[4] == 1 && chrome[5] == 1){
        chrome[4] = 0;
    } else if(chrome[3] == 0 && chrome[4] == 1 && chrome[5] == 0){
        chrome[4] = 0;
        chrome[5] = 1;
    }

}

float decodeX (int kromosom[6]){

    int i, num = 0, neg1 = 0;

    /*
    Decode method = Twos complement/signed binary number (MSB is for a sign)
    EX:

    |---------------|
    | 1 0 1 | 0 1 1 |
    |---------------|

    left box's MSB is 1 and right box's MSB 0 | (0 = +, 1 = -)
    */
    //A.
    // disini saya membuat prosedure pemilihan orangtua nilai fitnes merupakan nilai yang menentukan baik atau tidaknnya individu

    for(i=0; i<6; i++){

        if(kromosom[i] == 1 && i == 0){
                neg1 =  -1;
        }

        if(kromosom[i] == 0 && i == 1){
            num = num + 0;
        } else if(kromosom[i] == 1 && i == 1) {
            num = num + 2;
        }

        if(kromosom[i] == 0 && i == 2){
            num = num + 0;
        } else if (kromosom[i] == 1 && i == 2) {
            num = num + 1;
        }
    }

    if (neg1 != 0){
        num = num*neg1;
    }

    float num1 = (float) num;

    return num1;
}

float decodeY (int kromosom[6]){

    int i, num = 0, neg2 = 0;

    /*
    Decode method = Twos complement/signed binary number (MSB is for a sign)
    EX:

    |---------------|
    | 1 0 1 | 0 1 1 |
    |---------------|

    left box's MSB is 1 and right box's MSB 0 | (0 = +, 1 = -)
    */

    for(i=0; i<6; i++){

        if(kromosom[i] == 1 && i == 3){
            neg2 =  -1;
        }

            if(kromosom[i] == 0 && i == 4){
                num = num + 0;
            } else if(kromosom[i] == 1 && i == 4){
                num = num + 2;
            }

            if (kromosom[i] == 0 && i == 5) {
                num = num + 0;
            } else if (kromosom[i] == 1 && i == 5) {
                num = num + 1;
            }
    }

    if(neg2 != 0){
        num = num*neg2;
    }

    float num2 = (float) num;

    return num2;
}

float fitnessCalc(int chromosome[6]){
    float decodeX(int kromosom[6]);
    float decodeY(int kromosom[6]);
    float X, Y, nilaiPerk, fitness;

    X = decodeX(chromosome);
    Y = decodeY(chromosome);

    // f(max) = h

    fitness = (cos(X*X)*sin(Y*Y))+(X+Y);

    return fitness;
    //B.
}//fungsi pickparent program akan memangil fungsi fitnescale sebagai komparator untuk melakukan roulette yang memiliki  fitness tertinggi akan jadi parent

int *pickParent(int *k1, int *k2, int *k3, int *k4){
    float fitnessCalc(int chromosome[6]);
    float num1, num2, num3, num4;
    int sum, n1, n2, n3, n4;

    // setup

    num1 = fitnessCalc(k1);
    num2 = fitnessCalc(k2);
    num3 = fitnessCalc(k3);
    num4 = fitnessCalc(k4);

    n1 = (int) num1 + 2;
    n2 = (int) num2 + 2;
    n3 = (int) num3 + 2;
    n4 = (int) num4 + 2;

    sum = n1+n2+n3+n4;

    // roulette wheel method //

    // roulette wheel initialization

    float roulette[sum];

    int i, j, k, l, ball;
    for(i=0;i<sum;i++){
        roulette[i] = NULL;
    }

    for(i=0;i<sum-(n2+n3+n4);i++){
        if(roulette[i] != NULL){
            for(j=0;roulette[j] != NULL;j++){

            }
            roulette[j] = num1;
        } else{
            roulette[i] = num1;
        }
    }

    for(i=0;i<sum-(n1+n3+n4);i++){
        if(roulette[i] != NULL){
            for(j=0;roulette[j] != NULL;j++){

            }
            roulette[j] = num2;
        } else{
            roulette[i] = num2;
        }
    }
    for(i=0;i<sum-(n1+n2+n4);i++){
        if(roulette[i] != NULL){
            for(j=0;roulette[j] != NULL;j++){

            }
            roulette[j] = num3;
        } else{
            roulette[i] = num3;
        }
    }
    for(i=0;i<sum-(n1+n2+n3);i++){
        if(roulette[i] != NULL){
            for(j=0;roulette[j] != NULL;j++){

            }
            roulette[j] = num4;
        } else{
            roulette[i] = num4;
        }
    }

    // roulette start
    ball = rand() % 10;

    if(roulette[ball] == num1){
        return k1;
    } else if(roulette[ball] == num2){
        return k2;
    } else if(roulette[ball] == num3){
        return k3;
    } else if(roulette[ball] == num4){
        return k4;
    } else{
        return 0;
    }
}

int *Crossover(int *father, int *mother, int *newChild){
    int cross, temp[5], i;

    cout<<"Father: ";
    for(i=0; i<6; i++){
        cout<<father[i];
    }
    cout<<endl;
    cout<<"Mother: ";
    for(i=0; i<6; i++){
        cout<<mother[i];
    }
    cout<<endl;

    // 1 point crossover

    //pick a random number to define the crossover point
    cross = rand() % 6;
    //C.
    // crossover process //teknik disini mengunakan teknik roulatee wheel
    if(cross == 0){
        for(i = 0; i<=cross;i++){
            temp[i] = father[i];
            father[i] = mother[i];
            mother[i] = temp[i];
        }
    }else if(cross == 1){
        for(i = 0; i<=cross; i++){
            temp[i] = father[i];
            father[i] = mother[i];
            mother[i] = temp[i];
        }
    }else if(cross == 2){
        for(i = 0; i<=cross; i++){
            temp[i] = father[i];
            father[i] = mother[i];
            mother[i] = temp[i];
        }
    }else if(cross == 3){
        for(i = 0; i<=cross; i++){
            temp[i] = father[i];
            father[i] = mother[i];
            mother[i] = temp[i];
        }
    }else if(cross == 4){
        for(i = 0; i<=cross; i++){
            temp[i] = father[i];
            father[i] = mother[i];
            mother[i] = temp[i];
        }
    }else if(cross == 5){
        for(i = 0; i<=cross; i++){
            temp[i] = father[i];
            father[i] = mother[i];
            mother[i] = temp[i];
        }
    }

    for(i=0; i<6; i++){
        newChild[i] = father[i];
    }

    return newChild;
}

int *Mutate(int *kromosom, int *newKrom){
    float prob;
    int mut, i;
    //D.pc and pn
    //crosever pc yaitu berdasarkan fitnes tiap kromosom(individu)
    // take a random number to compare with mutation probability (0.75)
    prob = (float)rand()/(float)RAND_MAX;

    // mutation process
    if(prob >= 0.75){
        mut = rand()%7;
        if(kromosom[mut] == 0){
            kromosom[mut] = 1;
        } else{
            kromosom[mut] = 0;
        }
    }

    for(i=0;i<6;i++){
        newKrom[i] = kromosom[i];
    }

    return newKrom;
}
//E
//metode pengantian generasi algorithm

void Generation(int k1[6], int k2[6], int k3[6], int k4[6]){
    float x1, x2, x3, x4, x5, x6, goal;
    float y1, y2, y3, y4, y5, y6;
    float sum1, sum2, sum3, sum4, sum5, sum6;
    int *father, *mother, newChild[6], newKrom[6], *child1, *child2, i;
    int *newChrom1, *newChrom2, *newChrom3, *newChrom4;

    // Defining functions

    int *pickParent(int *k1, int *k2, int *k3, int *k4);
    int *Crossover(int *father, int *mother, int *newChild);
    int *Mutate(int *kromosom, int *newKrom);
    float fitnessCalc(int chromosome[6]);
    float decodeX(int kromosom[6]);
    float decodeY(int kromosom[6]);

    goal = (cos(2*2)*sin(1*1))+(2+1);

    // Pick  2 Parent
    father = pickParent(k1,k2,k3,k4);
    mother = pickParent(k1,k2,k3,k4);

    //crossover, make 2 children
    child1 = Crossover(father, mother, newChild);
    child2 = Crossover(father, mother, newChild);

    // mutation for all chromosome (excluding child) if possible
    newChrom1 = Mutate(k1, newKrom);
    newChrom2 = Mutate(k2, newKrom);
    newChrom3 = Mutate(k3, newKrom);
    newChrom4 = Mutate(k4, newKrom);

    //Selection Process
    sum1 = fitnessCalc(newChrom1);
    sum2 = fitnessCalc(newChrom2);
    sum3 = fitnessCalc(newChrom3);
    sum4 = fitnessCalc(newChrom4);
    sum5 = fitnessCalc(child1);
    sum6 = fitnessCalc(child2);

    if(sum6 > sum1  ){

    }

}
