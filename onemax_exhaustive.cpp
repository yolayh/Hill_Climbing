#include <iostream>
#include <cmath>                    //pow()
#include <string>
#include <algorithm>               //reverse
#include <chrono>
#include <ctime>
using namespace std;

string transition(int);           //(bit)
string dtob(int);                 // decimal to binary; for trasition function
int evaluation(string);           // calculate number of "1"
string initialization(int);       // set initail number
int search(int, double);          //(bit, limit time(seconds))

int main(){

    search(30,1800.0);

    return 0;
}

int search(int bit, double time){
    string solution =initialization(bit);
    //cout << solution << endl;                       //print initial string
    int f1 = evaluation(solution);
    int max = pow(2, bit)-1;
    auto start = std::chrono::system_clock::now();  //start time
    for(int i = 0; i < max; i++){
        string v = transition(bit);
        //cout << v << " ";                          //print new string
        int f2 = evaluation(v);
        if (f2>f1){
            solution = v;
            f1 = f2;
        }
        //cout << "max:" << f1 << " (string: " << solution << ")" << endl;             // current max number of one
        auto end = std::chrono::system_clock::now();   //every loop end time
        std::chrono::duration<double> elapsed_seconds = end-start;
        if(elapsed_seconds.count() >= time){                        
            cout << "excecution time:" << elapsed_seconds.count() << endl;
            break;
        }
    
    }

    cout << "\nThe final solution is: " << solution << endl;
    cout << "The number of one: " << f1 << endl;
    return 0;

}


//Transition
int number = 1;
string transition(int bit){
    int max = pow(2, bit)-1;
    string new_num = dtob(number);
    if (number<max){
        number++;
    }
    if (new_num.length() < bit){
        string zero = string(bit - new_num.length(), '0');
        new_num = zero + new_num;
    }
    return new_num;
}

//decimal to binary
string dtob(int num){
    int rem;   // 餘數
    string binary; 
    while (num != 1){
        rem = num % 2;
        num /= 2;
        binary += to_string(rem);
    }
    binary += "1";
    reverse(binary.begin(), binary.end());
    return binary;
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

//Initialize
string initialization(int bit){
    string initial_result = string(bit, '0');       //initial result

    return initial_result;
}






