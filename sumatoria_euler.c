#include <stdio.h>
#include <omp.h>

unsigned int n = 0; // Iteration.  Start with n=0;
double fact = 1;    // 0! = 1.  Keep running product of iteration numbers for factorial.
double sum = 0;     // Starting summation.  Keep a running sum of terms.
double last;        // Sum of previous iteration for computing e
static long num_steps = 100000000;
double step;

int main(){

        step = 1.0 / (double)num_steps;
        omp_set_num_threads(4);
        #pragma omp parallel 
        {
        #pragma omp for reduction(+:last) private(sum)
        for (int i = 1; i <= num_steps; i++){
            last = sum;
            sum += 1 / fact;
            fact *= ++n;
        }
    }

}

//https://www.wolframalpha.com/input/?i=sum&assumption=%7B%22F%22,+%22Sum%22,+%22sumfunction%22%7D+-%3E%221%2Fx!%22&assumption=%7B%22F%22,+%22Sum%22,+%22sumlowerlimit%22%7D+-%3E%220%22&assumption=%7B%22F%22,+%22Sum%22,+%22sumupperlimit2%22%7D+-%3E%22infinity%22&assumption=%7B%22FVarOpt%22,+%221%22%7D+-%3E+%7B%7B%7D,+%7B%7B%7B%22Sum%22,+%22sumvariable%22%7D%7D%7D,+%7B%7D%7D&assumption=%7B%22C%22,+%22sum%22%7D+-%3E+%7B%22Calculator%22,+%22dflt%22%7D
