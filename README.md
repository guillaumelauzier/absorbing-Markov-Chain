# absorbing-Markov-Chain

An absorbing Markov Chain is a type of Markov Chain that has one or more states that are absorbing, meaning that once the system is in one of those states, it cannot transition to any other state.

The probability of reaching an absorbing state in an absorbing Markov Chain can be calculated using the following formula:

Q = I - R

Where Q is the probability matrix of reaching an absorbing state, I is the identity matrix, and R is the matrix of transition probabilities for the non-absorbing states.

Once the matrix Q is found, the probability of reaching an absorbing state from any non-absorbing state i can be found by the formula:

P(i,j) = Q^(-1) * q

Where P is the matrix of probability of reaching an absorbing state from any non-absorbing state i and q is a column vector of the probability of starting in state i.

Here's an example of how to calculate the probability of reaching an absorbing state in C++ using the above formulas:

```
#include <iostream>
#include <cmath>
using namespace std;

const int N = 3; // Number of states
const int T = 20; // Number of time steps
const double eps = 1e-6; // Accuracy threshold

double transitionMatrix[N][N] = {
    {0.7, 0.2, 0.1},
    {0.1, 0.6, 0.3},
    {0.2, 0.5, 0.5}
};

int main() {
    double Q[N][N], I[N][N], R[N][N];
    double q[N];
    double P[N][N];

    // Initializing the identity matrix
    for(int i = 0; i< N; i++){
        for(int j = 0; j < N; j++){
            if(i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }

    // Initializing the matrix R
    for(int i = 0; i< N; i++){
        for(int j = 0; j < N; j++){
            if(i != j)
                R[i][j] = transitionMatrix[i][j];
            else
                R[i][j] = 0;
        }
    }

    // Initializing the q column vector
    for(int i = 0; i< N; i++){
        q[i] = 1.0/N;
    }

    // Calculating the Q matrix
    for(int i = 0; i< N; i++){
        for(int j = 0; j < N; j++){
            Q[i][j] = I[i][j] - R[i][j];
        }
    }
    // Calculating the inverse of Q
    // Pseudo-code for the inversion of Q
    // Q_inv = invert(Q)

    // Calculating the P matrix
    for(int i = 0; i< N; i++){
        for(int j = 0; j < N; j++){
            P[i][j] = 0;
            for(int k = 0; k < N; k++){
                P[i][j] += Q_inv
                  P[i][j] += Q_inv[i][k] * q[k];
            }
        }
    }
    // Print the probability of reaching an absorbing state from any non-absorbing state
cout << "Probability of reaching an absorbing state from any non-absorbing state:" << endl;
for (int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++){
        cout << "From State " << i << " to State " << j << ": " << P[i][j] << endl;
    }
}

return 0;


```

This code defines a transition matrix with 3 states and uses the formulas of absorbing Markov Chain to calculate the probability of reaching an absorbing state from any non-absorbing state. The matrices and vectors are defined and initialized as per the formulas, then the Q matrix and P matrix are calculated using the formulas. Finally, the result is printed out in the end.

It is important to note that the above code is just a pseudocode and some functions like invert() are not implemented and in the real code you should use a library or another method to calculate the inverse of a matrix.
