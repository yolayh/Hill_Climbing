#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void run(int, int, int);           
string initialization(int);       // set initail number
int evaluation(string);
string transition(string);

int main(){

    srand((unsigned)time(NULL));
    run(30,1000,100);            //(run,iteration,bit)

    return 0 ;
}

void run(int run, int Iter, int bit){
    int result[run] = {};
    for(int i = 0; i < run; i++){
        cout << "run-" << i+1 <<endl; 
        string solution = initialization(bit);                        
        int iteration = 0;
        int f1 = evaluation(solution);
        cout << "initial random string: " << solution << endl;
        while (iteration < Iter){
            string new_search = transition(solution);
            cout << new_search << endl;                                         //check
            int f2 = evaluation(new_search);
            //cout << new_search << "; max: " << f2 << endl;
            
            //Determination
            if (f2>f1){
                solution = new_search;
                f1 = f2;
            }
            iteration ++;
        }
        result[i] = f1;
        cout <<  "---> Result:" << solution << ", " << f1 << endl;
        cout << " " << endl;

    }
    int sum =0;
    cout << "Every Run result:" << endl;
    for (int i = 0; i < run; i++){
        cout << result[i] << " ";
        sum += result[i]; 
    }
    int average = sum/run;
    cout << "\naverage = " << average << endl; 

}

//Initialize
string initialization(int bit){
    string initial_result;                    
    for (int i =0; i < bit; i++)
        initial_result += to_string(rand() % 2);       //initial result
    return initial_result;
}

//Evaluation
int evaluation(string num){
    int size = num.length();
    int num_sum = 0;
    for (int i=0; i< size; i++){
        int num_bit = int(num[i]) - 48;
        num_sum += num_bit;
    }
    return num_sum;
}


//Transition; adopt random method
string transition(string initial){
    int size = initial.length();
    int change_index = rand() % size;
    if (int(initial[change_index])-48 == 0)
        initial[change_index] = '1';
    else
        initial[change_index] = '0';

    return initial;
}


