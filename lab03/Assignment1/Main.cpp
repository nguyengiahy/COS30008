#include <iostream>
#include "Polynomial.h"
using namespace std;

int main()
{
	Polynomial A;
	cout << "Specify first polynomial (degree followed by coefficients):" << endl;
	cin >> A;
	cout << "A = " << A << endl;

	double x;
	cout << "Specify value of x:" << endl;
	cin >> x; 
	
	cout << "A(x) = " << A(x) << endl; 
	cout << "Indefinite integral of A = " << A.getIndefiniteIntegral() << endl; 
	cout << "Differential of A = " << A.getDifferential() << endl; 
	cout << "Differential of indefinite integral of A = " << A.getIndefiniteIntegral().getDifferential() << endl; cout << "Definite integral of A(xlow=0, xhigh=12.0) = " << A.getDefiniteIntegral(0, 12.0) << endl; 
	if ( A == A.getIndefiniteIntegral().getDifferential() ) 
	{ 
		cout << "Polynomial operations are sound." << endl; 
	}
	else 
	{ 
		cout << "Polynomial operations are broken." << endl; 
	}
	return 0;
}
