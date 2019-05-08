//Junho Lee
//824002195
//CSCE 420
//Due: 03/07/2018
//hw2pr4.cpp


#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool temp_b = false;

bool AND (bool a, bool b) {
	if (a != b)
		return false;
	else 
		return a;
}

bool OR (bool a, bool b) {
	if (a == true || b == true)
		return true;
	else 
		return false;
}



void print_v (vector <int> v) {
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}
void print_v (vector <string> v) {
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

void print_v (vector <char> v) {
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}
void print_v (vector <bool> v) {
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}


bool OR (vector <bool> v, int i, int size) {
	print_v(v);

	if (i == size-1) {
	temp_b = v[i];
	return v[i];	
	}
	
	v[i+1] = OR(v[i], v[i+1]);
	
	OR(v, i+1, size);
	
	
	cout <<"test: " <<v[i+1] << endl;
	return v[i+1];
}


vector <bool> parse_v (vector <string> v) {
	vector <char> pv;
	vector <int> cv;
	cv.push_back(0);
	vector <bool> bv;
	vector <bool> OR_v;
	for (int i=0; i<v.size(); i++) {
		for (int j=0; j<v[i].length(); j++) {
		pv.push_back(v[i].at(j));
		}
	}
	cout << "pv: ";
	print_v(pv);
	
	int alpha_count = 0;
	
	for (int i=0; i<pv.size(); i++) {
		if (isalpha(pv[i])) {
			bv.push_back(true);
			alpha_count++;
		}
		else if (pv[i] == '.') {
			//cout << alpha_count << endl;
			cv.push_back(alpha_count);
			alpha_count=0;
		}
		else if (pv[i] == '-') {
			bv.push_back(false);
			alpha_count++;
			i++;
		}
	}
	
	cout << "bv: ";
	print_v(bv);
	
	cout << "cv: ";
	print_v(cv);
	cout << endl;

	
	for (int i=0; i<cv.size(); i++) {
		temp_b = OR(bv, i, cv[i]);
		OR_v.push_back(temp_b);
		i = cv[i]-1;
	}


	cout << "OR_v: ";
	print_v (OR_v);
	
	
	return bv;
}

int main() {
	string str;
	vector <string> str_v;
	int c = 0;
	
	while (c == 0) {
		cout << "type in your CNF. input exit to end." <<endl;
		cin >> str;
			if (str == "exit") {
				cout << "exiting..." << endl;
			
				c = 1;
				break;
			}
		str_v.push_back(str);
		str_v.push_back(".");
	}
	
	cout << "str_v";
	print_v(str_v);
	cout << endl;
	print_v(parse_v(str_v));
}