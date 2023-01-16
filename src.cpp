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
