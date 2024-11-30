#include<iostream>
#include<climits>
using namespace std;
int main() {
	cout << "Type: signed char"<<endl;
	cout<<"Size: "<< sizeof(signed char)<<" byte(s)"<<endl;
	cout<<"MIN: "<<SCHAR_MIN<<"; MAX: "<<SCHAR_MAX<<endl;
	cout<<endl;

	cout << "Type: unsigned char"<<endl;
	cout<<"Size: "<< sizeof(unsigned char)<<" byte(s)"<<endl;
	cout<<"MIN: "<<0<<"; MAX: "<<UCHAR_MAX<<endl;
	cout<<endl;

	cout << "Type: short int"<<endl;
	cout<<"Size: "<< sizeof(short int)<<" byte(s)"<<endl;
	cout<<"MIN: "<<SHRT_MIN<<"; MAX: "<<SHRT_MAX<<endl;
	cout<<endl;

	cout << "Type: unsigned short int"<<endl;
	cout<<"Size: "<< sizeof(unsigned short int)<<" byte(s)"<<endl;
	cout<<"MIN: "<<0<<"; MAX: "<<USHRT_MAX<<endl;
	cout<<endl;

	cout << "Type: int"<<endl;
	cout<<"Size: "<< sizeof(int)<<" byte(s)"<<endl;
	cout<<"MIN: "<<INT_MIN<<"; MAX: "<<INT_MAX<<endl;
	cout<<endl;

	cout << "Type: unsigned int"<<endl;
	cout<<"Size: "<< sizeof(unsigned int)<<" byte(s)"<<endl;
	cout<<"MIN: "<<0<<"; MAX: "<<UINT_MAX<<endl;
	cout<<endl;

	cout << "Type: long int"<<endl;
	cout<<"Size: "<< sizeof(long int)<<" byte(s)"<<endl;
	cout<<"MIN: "<<LONG_MIN<<"; MAX: "<<LONG_MAX<<endl;
	cout<<endl;

	cout << "Type: unsigned long int"<<endl;
	cout<<"Size: "<< sizeof(unsigned long int)<<" byte(s)"<<endl;
	cout<<"MIN: "<<0<<"; MAX: "<<ULONG_MAX<<endl;
	cout<<endl;

	cout << "Type: signed long long"<<endl;
	cout<<"Size: "<< sizeof(signed long long)<<" byte(s)"<<endl;
	cout<<"MIN: "<<LLONG_MIN<<"; MAX: "<<LLONG_MAX<<endl;
	cout<<endl;

	cout << "Type: unsigned long long"<<endl;
	cout<<"Size: "<< sizeof(signed long long)<<" byte(s)"<<endl;
	cout<<"MIN: "<<0<<"; MAX: "<<ULLONG_MAX<<endl;
	cout<<endl;

	cout << "Type: bool"<<endl;
	cout<<"Size: "<< sizeof(bool)<<" byte(s)"<<endl;
	cout<<"MIN: "<<0<<"; MAX: "<<1<<endl;
	cout<<endl;

	cout << "Type: float"<<endl;
	cout<<"Size: "<< sizeof(float)<<" byte(s)"<<endl;
	cout<<"MIN: "<<FLT_MIN<<"; MAX: "<<FLT_MAX<<endl;
	cout<<endl;

	cout << "Type: double"<<endl;
	cout<<"Size: "<< sizeof(double)<<" byte(s)"<<endl;
	cout<<"MIN: "<<DBL_MIN<<"; MAX: "<<DBL_MAX<<endl;
	cout<<endl;

	cout << "Type: long double"<<endl;
	cout<<"Size: "<< sizeof(long double)<<" byte(s)"<<endl;
	cout<<"MIN: "<<LDBL_MIN<<"; MAX: "<<LDBL_MAX<<endl;
	cout<<endl;

	cout<<"examples:"<<endl;

	char c = 97;
	cout<<c<<" "<<char(c+12)<<endl;

	bool f1 = 0;
	bool f2 = true;
	cout<<(f1 || f2)<<" "<<(f1 & f2)<<endl;

	int a = 77;
	int b = 33;
	cout<<a+b<<" "<<a-b<<" "<<a*b<<endl;

	double d = 3.52;
	double s = 131.76;
	cout<<d+s<<" "<<d/s<<endl;
	
	return 0;
}
