#include "Header.h"
#include <cmath>
#include <iostream>
using namespace std;




void ToBin(int n, int arr[]) {
	if (n > 0) arr[0] = 0;
	if (n < 0) arr[0] = 1;
	for (int i = 7; i > 0; i--) {

		arr[i] = abs(n) % 2;
		n = n / 2;

	}


}

void ToBin2(int n, int arr[]) {
	for (int i = 7; i >= 0; i--) {

		arr[i] = abs(n) % 2;
		n = n / 2;

	}


}

void ToBinFraction(double fraction, int arr[]) {
	for (int i = 0; i < 5; i++) {
		fraction *= 2;
		arr[i] = static_cast<int>(fraction);
		fraction -= arr[i];
	}
}

double ToFractionFromBin(int arr[], int size) {
	double fraction = 0;

	for (int i = 0; i < size; i++) {
		fraction += arr[i] * pow(0.5, i + 1);
	}

	return fraction;
}


void RightShift(int arr[], int length, bool one) {
	
	for (int i = length - 1; i > 0; i--) {
		arr[i] = arr[i - 1]; 
	}
	if (one == false) arr[0] = 0; else arr[0] = 1;
}


void ToFloatBin(float n, int arr[]) {
	arr[0] = 0;
	int intPart = static_cast<int>(n);
	double fract = n - intPart;
	int whole[8] = {0}, fraction[5] = {0};
	ToBin(intPart, whole);
	ToBinFraction(fract, fraction);
	for (int i = 7; i > 0; i--) {
		arr[i] = whole[i];

		
	}
	int a = 0;
	for (int i = 8; i < 13; i++) {
		arr[i] = fraction[a];
		a++;

	}
	
}

double ForFloatBin(int arr[]) {
	arr[0] = 0;
	int whole[8] = { 0 }, fraction[5] = { 0 };
	int l = 4, intpart = 0;
	double fract = 0, p =0;
	for (int i = 12; i >= 8; i--) {
		fraction[l] = arr[i];
		l--;
	}
	for (int i = 7; i >= 0; i--) {
		whole[i] = arr[i];
		
	}
	intpart = ToTen(whole);
	fract = ToFractionFromBin(fraction, 5);
	p = intpart + fract;
	
	return p;
}



int ToTen(int arr[]) {
	int decimal = 0;
	int power = 1;

	for (int i = 7; i > 0; i--) {
		if (arr[i] == 1) {
			decimal += power;
		}
		power = power * 2;
	}

	return decimal;

}

int ToTenExp(int arr[]) {
	int decimal = 0;
	int power = 1;

	for (int i = 7; i >= 0; i--) {
		if (arr[i] == 1) {
			decimal += power;
		}
		power = power * 2;
	}

	return decimal;

}





void ToWhole(int t, int arr[]) {

	for (int i = 7; i >= 0; i--) {
		if (t % 2 == 0) arr[i] = 0;
		if (t % 2 != 0) arr[i] = 1;
		if (t == 1) break;
		t = t / 10;
		
	}

}

int ForWhole(int arr[]) {
	bool first = false;
	int p = 0;
	for (int i = 0; i < 8; i++) {
		if (first == true && arr[i] == 1) p = p * 10 + 1;
		if (first == true && arr[i] == 0) p = p * 10;
		if (first == false && arr[i] == 1) { first = true; p = 1; }

	}
	return p;
}


int Divider(int arr[]) {
	int t; bool one = false;
	for (int i = 1; i < 8; i++) {

		if (arr[i] == 1 && one == true) {
			t = t * 10 + 1;
		}
		if (arr[i] == 1 && one == false) {
			t = 1; one = true;
		}
		if (arr[i] == 0 && one == true) {
			t = t * 10;
		}
	}

	return t;
}

void ToReverse(int arr[], int arr2[]) {
	for (int i = 7; i > 0; i--) {
		if (arr[i] == 1) arr2[i] = 0;
		else  arr2[i] = 1;

	}
	arr2[0] = arr[0];
}

void Addition(int arr[], int arr2[], int arr3[]) {
	int p = 0, f = 0;
	for (int i = 7; i >= 0; i--) {
		f = arr[i] + arr2[i] + p;
		arr3[i] = abs(f) % 2;
		p = f / 2;
	}
}

void AdditionMantissa(int arr[], int arr2[], int arr3[]) {
	int p = 0, f = 0;
	for (int i = 23; i >= 0; i--) {
		f = arr[i] + arr2[i] + p;
		arr3[i] = abs(f) % 2;
		p = f / 2;
	}
}

void ToExtraBin(int arr[], int arr2[]) {
	int temp[8];
	int one[8] = { 0, 0, 0, 0, 0, 0, 0, 1 };
	ToReverse(arr, temp);
	temp[0] = 1;
	Addition(temp, one, arr2);
}


void Subtraction(int arr[], int arr2[], int arr3[]) {
	int temp[8];
	if (arr[0] == 0 && arr2[0] == 1) {
		arr3[0] = 0;
		Addition(arr, arr2, arr3);
	}
	if (arr[0] == 1 && arr2[0] == 0) {
		arr3[0] = 1;
		Addition(arr, arr2, arr3);
	}
	if (arr[0] == 1 && arr2[0] == 1) {
		ToExtraBin(arr, temp);
		Addition(arr2, temp, arr3);

	}
	if (arr[0] == 0 && arr2[0] == 0) {
		ToExtraBin(arr2, temp);
		Addition(arr, temp, arr3);
	}


}

void Multiplication(int arr[], int arr2[], int arr3[]) {
	bool first = false, second = false, end = false;
	if (arr[0] + arr2[0] == 1) arr3[0] = 1; else arr3[0] = 0;
	int temp[8] = {0}, temp2[8] = {0}, temp3[8] = {0};
	for (int i = 7; i > 0; i--) {
		if (arr2[i] == 1) {
			int k = i;
			for (int j = 7; k > 0; k--) {

				if (first == false) {
					temp[k] = arr[j];

				}
				else {
					temp2[k] = arr[j];
					end = true;
				}
				j--;
			}
			first = true;
			if (end == true) {
				Addition(temp, temp2, temp3);
				second = true;
				for (int l = 7; l > 0; l--) {
					temp[l] = temp3[l];
				}
				end = false;
				for (int l = 7; l > 0; l--) {
					temp2[l] = 0;
				}
			}
		}



	}
	if (second == false) {
		for (int i = 7; i > 0; i--) {
			arr3[i] = temp[i];
		}
	}
	else {
		for (int i = 7; i > 0; i--) {
			arr3[i] = temp3[i];
		}
	}

}

void InArr(int arr[], int arr2[], int a, int b) {
	int n = 7;
	for (int i = b; i >= a; i--) {
		arr2[n] = arr[i];
		n--;
	}


}

void OutArr(int arr[], int arr2[], int a, int b) {
	int n = 7;
	for (int i = b; i >= a; i--) {
		arr[i] = arr2[n];
		n--;
	}


}




void Division(int arr[], int arr2[], int arr3[]) {
	int temp2[8] = {0}, temp[8] = {0}, whole[8] = {0}, fraction[5] = {0};
	for (int i = 7; i >= 0; i--) {
		temp[i] = arr[i];
	}
	for (int i = 7; i >= 0; i--) {
		temp2[i] = arr2[i];
	}
	int divider = Divider(arr2);
	int p = 0;
	int t = 1, n = 0, k = 0, begin, end; bool one = false, first = false; int temp3[8] = {0}, temp4[8] = {0};
	
	for (int i = 1; i < 8; i++) {
		if (temp[i] == 1 && one == true) {
			t = t * 10 + 1;
		}
		if (temp[i] == 1 && one == false) {
			t = 1; one = true;  begin = i;
		};
		if (temp[i] == 0 && one == true) {
			t = t * 10;
		}


		if (t == divider) {
			whole[n] = 1; n++; k++; first = true;
			if (i == 7) break;
			p = 0;
			for (int a = i + 1; a < 8; a++) {
				if (temp[a] == 1) p++;
			}
			if (p > 0) first = false; else {
				for (int a = i + 1; a < 8; a++) {

					whole[n] = 0;
					n++; k++;

				}
				one = false;
				break;
			}
			one = false;
			t = 1; continue;

		}
		if (t < divider) {
			whole[n] = 0; n++; k++;


		}
		if (t > divider && one == true) {
			whole[n] = 1; n++; k++; end = i;


			InArr(temp, temp3, begin, end);

			Subtraction(temp3, temp2, temp4);

			OutArr(temp, temp4, begin, end);

			for (int i = 7; i >= 0; i--) {
				temp3[i] = 0;
			}
			for (int i = 7; i >= 0; i--) {
				temp4[i] = 0;
			}

			one = false;


			for (int a = begin; a <= end; a++) {

				if (temp[a] == 1 && one == true) {
					t = t * 10 + 1;
				}
				if (temp[a] == 1 && one == false) {
					t = 1; one = true; begin = a;
				}
				if (temp[a] == 0 && one == true) {
					t = t * 10;
				}


			}
			one = true;
			
		}



	}

	for (int i = 7; i >= 0; i--) {
		arr3[i] = 0;

	}

	int x = 7;
	for (int i = k - 1; i >= 0; i--) {
		arr3[x] = whole[i];
		x--;
	}
	//if (t % (t - 1) == 1) t = t - 1;
	for (int i = 4; i >= 0; i--) {
		
		t = t * 10;


		if (t == divider) {
			fraction[i] = 1;
			break;
		}
		if (t < divider) {
			fraction[i] = 0;


		}
		if (t > divider) {
			fraction[i] = 1;
			for (int i = 7; i >= 0; i--) {
				temp[i] = 0;
			}

			ToWhole(t, temp);

			Subtraction(temp, temp2, temp3);

			t = ForWhole(temp3);

			for (int i = 7; i >= 0; i--) {
				temp3[i] = 0;
			}

		}
	}
	int l = 0;
	for (int i = 12; i >= 8; i--) {
		arr3[i] = fraction[l];
		l++;
	}

}


void To32bit(int arr[], int arr32[]) {
	arr32[0] = 0;
	arr[0] = 0;
	int temp[8] = {0};
	bool first = false;
	int begin = 0, a = 0;
	for (int i = 0; i < 13; i++) {
		if (arr[i] == 1) { first = true; begin = i; break; }
	}
	a = 9;
	for (int i = begin + 1; i < 13; i++) {
		arr32[a] = arr[i];
		a++;
	}

	int exponent = (7 - begin) + 127;
	ToBin2(exponent, temp);
	a = 0;
	for (int i = 1; i < 9; i++) {
		arr32[i] = temp[a];
		a++;
	}

}


void bit32Addition(int arr[], int arr2[], int arr3[]) {
	int a = 0;
	bool first = false;
	int temp[8] = {0}, temp2[8] = {0}, temp3[8] = { 0 }, mantisa[24] = {0}, mantisa2[24] = {0}, mantisa3[24] = { 0 }, one[8] = {0,0,0,0,0,0,0,1};
	for (int i = 1; i < 9; i++) {
		temp[a] = arr[i];
		a++;
	}
	a = 0;
	for (int i = 1; i < 9; i++) {
		temp2[a] = arr2[i];
		a++;
	}
	a = 1;
	mantisa[0] = 1;
	for (int i = 9; i < 32; i++) {
		mantisa[a] = arr[i];
		a++;
	}
	a = 1;
	mantisa2[0] = 1;
	for (int i = 9; i < 32; i++) {
		mantisa2[a] = arr2[i];
		a++;
	}
	a = 1;
	int exp = ToTenExp(temp);
	int exp2 = ToTenExp(temp2);
	int diff = abs(exp2 - exp);
	if (exp > exp2) {
		for (int i = 0; i < diff; i++) {
		 RightShift(mantisa2, 24, false);
		}

		AdditionMantissa(mantisa, mantisa2, mantisa3);
		if (mantisa3[0] == 0) { Addition(temp, one, temp3); 
		RightShift(mantisa3, 24, false);
		}
		for (int i = 9; i < 32; i++) {
			arr3[i] = mantisa3[a];
			a++;
		}
		a = 0;
		for (int i = 1; i < 9; i++) {
			arr3[i] = temp3[a];
			a++;
		}
		a = 1;
	}
	first = false;
	if (exp2 > exp) {
		for (int i = 0; i < diff; i++) {
			RightShift(mantisa, 24, false);
		}
		AdditionMantissa(mantisa2, mantisa, mantisa3);
		if (mantisa3[0] == 0) {
			Addition(temp2, one, temp3);
			for (int i = 0; i < 8; i++) {
				temp2[i] = temp3[a];

			}
			for (int i = 1; i < 9; i++) {
				arr3[i] = temp2[a];
				a++;
			}

		}
		a = 0;
			for (int i = 9; i < 32; i++) {
				arr3[i] = mantisa3[a];
				a++;
			}
			a = 0;
			for (int i = 1; i < 9; i++) {
				arr3[i] = temp3[a];
				a++;
			}

		

	}
}






