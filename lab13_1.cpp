#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double Au[],int Nu,double bu[]){
    double sum = 0;
    double ssum = 0;
    double sssum = 1;
    double ssssum = 0;
    double max = 0;
    double min = Au[0];
    for(int i =0;i <Nu;i++){
        sum += Au[i];
        sssum *= Au[i];
        ssssum += 1/Au[i];
    }
    double amean = sum/Nu;
    bu[0] = amean;
    for(int j = 0;j < Nu;j++){
        ssum += pow(Au[j]-amean,2);
    }
    double sde = ssum/Nu;
    bu[1] = sqrt(sde);
    double gem = pow(sssum,1.0/Nu);
    bu[2] = gem;
    double ham = Nu/ssssum;
    bu[3] = ham;
    for(int k=0;k<Nu;k++){
        if(Au[k] > max) max = Au[k];
        if(Au[k] < min) min = Au[k];
    }
    bu[4] = max;
    bu[5] = min;
    
}