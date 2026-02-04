#include<iostream>
#include<fstream>
#include<cctype>
#include<string>
#include<functional>

using namespace std;

string hashPassword(const string& password) {
	hash<string> hasher;
	return to_string(hasher(password));
}

int checkStrength(const string& password){
	bool hasUpper=false, hasLower=false, hasDigit=false, hasSymbol=false;

for (char ch : password) {
	if (isupper(ch)) hasUpper=true;
	else if (islower(ch)) hasLower=true;
	else if (isdigit(ch)) hasDigit=true;
	else hasSymbol=true;
}

int score=0;
if (password.length() >=8) score++;
if (hasUpper) score++;
if (hasLower) score++;
if (hasDigit) score++;
if (hasSymbol) score++;

return score;
}

string suggestPassword(const string& password) {
	string suggestion=password;
	
	if (password.length() <8)
	suggestion +="6@G";
	
	if (suggestion.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ")==string::npos)
	suggestion +="D";
	
	if (suggestion.find_first_of("abcdefghijklmnopqrstuvwxyz")==string::npos)
	suggestion +="d";
	
	if (suggestion.find_first_of("0123456789")==string::npos)
	suggestion +="9";
	
	if (suggestion.find_first_of("!@#$%&*?")==string::npos)
	suggestion +="&";
	
	return suggestion;
}

int main () {
	string password;
	cout<<"Enter password: "<<endl;
	cin>>password;
	
	int strength=checkStrength(password);
	
	if (strength<=2)
	cout<<"Weak"<<endl;
	
	else if (strength<=4)
	cout<<"Medium"<<endl;
	
	else
	cout<<"Strong"<<endl;
	
	if (strength<5){
		cout<<"Suggested password: "<<suggestPassword(password)<<endl;
	}
	
	ofstream file("passwords.txt", ios::app);
	{
		if (file.is_open()) {
			cout<<"Hashed Password: "<<hashPassword(password)<<endl;
			file.close();
			cout<<"Password saved securely. "<<endl;
		}
		else{
			cout<<"There's error in saving passwords. "<<endl;
		}
	}
	return 0;
}