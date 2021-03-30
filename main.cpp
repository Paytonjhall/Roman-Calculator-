#include <iostream>
#include <vector>

using namespace std;
//List of constants
const int I = 1;
const int V = 5;
const int X = 10;
const int L = 50;
const int C= 100;
const int D = 500;
const int M = 1000;

//Converts char value into correct int value
int getVal(char input){
    if(input == 'I') return I;
    if(input == 'V') return V;
    if(input == 'X') return X;
    if(input == 'L') return L;
    if(input == 'C') return C;
    if(input == 'D') return D;
    if(input == 'M') return M;
    return 0;
}

//Calculate the total.
int calc(vector<int> list){
    int total=0;
    for(int i = 0; i < list.size(); i++){
    if(i+1 < list.size() && list.at(i) < list.at(i+1)){
        total = total - list.at(i) + list.at(i+1);
        i++;
    }
    else{
        total += list.at(i);
         }
    }

    return total;
}

string testM(int &val){
    bool halfCheck = false;
    int counter = 0;
    string returner = "";
    if(val >= M){
        do{
            val = val-M;
            counter++;
        }
        while(val >= M);
    }
    if(val >= (M-C)){
        val = val - (M - C);
        halfCheck = true;
    }
    if(halfCheck) returner += "CM";
    for(int i = 0; i < counter; i++){
        returner += 'M';
    }
    return returner;
}

string testD(int &val){
    bool halfCheck = false;
    int counter = 0;
    string returner = "";
    if(val >= D){
        do{
            val = val-D;
            counter++;
        }
        while(val >= D);
    }
    if(val >= (D-C)){
        val = val - (D - C);
        halfCheck = true;
    }
    if(halfCheck) returner += "CD";
    for(int i = 0; i < counter; i++){
        returner += 'D';
    }
    return returner;
}

string testC(int &val){
    bool halfCheck = false;
    int counter = 0;
    string returner = "";
    if(val >= C){
        do{
            val = val-C;
            counter++;
        }
        while(val >= C);
    }
    if(val >= (C-X)){
        val = val - (C - X);
        halfCheck = true;
    }
    if(halfCheck) returner += "XC";
    for(int i = 0; i < counter; i++){
        returner += 'C';
    }
    return returner;
}

string testL(int &val){
    bool halfCheck = false;
    int counter = 0;
    string returner = "";
    if(val >= L){
        do{
            val = val-L;
            counter++;
        }
        while(val >= L);
    }
    if(val >= (L-X)){
        val = val - (L - X);
        halfCheck = true;
    }
    if(halfCheck) returner += "XL";
    for(int i = 0; i < counter; i++){
        returner += 'L';
    }
    return returner;
}

string testX(int &val){
    bool halfCheck = false;
    int counter = 0;
    string returner = "";
    if(val >= X){
        do{
            val = val-X;
            counter++;
        }
        while(val >= X);
    }
    if(val >= (X-I)){
        val = val - (X - I);
        halfCheck = true;
    }
    if(halfCheck) returner += "IX";
    for(int i = 0; i < counter; i++){
        returner += 'X';
    }
    return returner;
}

string testV(int &val){
    bool halfCheck = false;
    int counter = 0;
    string returner = "";
    if(val >= V){
        do{
            val = val-V;
            counter++;
        }
        while(val >= V);
    }
    if(val >= (V-I)){
        val = val - (V - I);
        halfCheck = true;
    }
    if(halfCheck) returner += "IV";
    for(int i = 0; i < counter; i++){
        returner += 'V';
    }
    return returner;
}

string testI(int &val){
    string returner = "";
    if(val >= I){
        do{
            val = val-I;
            returner+='I';
        }
        while(val != 0);
    }

    return returner;
}

bool intCheck(string val){
    for(int i = 0; i < val.size(); i++){
        if(!isdigit(val.at(i))) return false;
    }
    return true;
}

bool stringCheck(string val){
    for(int i = 0; i < val.size(); i++){
        if(isdigit(val.at(i))) return false;
    }
    return true;
}


//Steps: find the largest value, if that value is not in the first position, subtraction will need to be done.
//if the largest value is in the first position, then no subtraction will ne done.
//Have a search algorithm go through and find location of largest number.

int main() {
    int total = 0;
    string input = "";
    int calcR = 0;
    string romanNum="";
    vector<int> calcList;

    cout << "Please insert the roman numeral value without any spaces at the beginning, in between numbers, or end" << endl;
    cout << "To close the program, simply enter 'end'" << endl;
    do {
        //Reset the values each time the program executes.
        input = "";
        calcR = 0;
        total = 0;
        romanNum = "";
        cin >> input;
        if (input == "end" || input == "\'end\'" || input == "End" || input == "END") return 0;
        else if (isdigit(input.at(0))) {
            if(!intCheck(input)){
                cout << "You have entered a value with numbers and characters. Sorry, that is not allowed" << endl;
                return 0;
            }
            calcR = stoi(input);
            do {
                romanNum += testM(calcR);
                romanNum += testD(calcR);
                romanNum += testC(calcR);
                romanNum += testL(calcR);
                romanNum += testX(calcR);
                romanNum += testV(calcR);
                romanNum += testI(calcR);
            } while (calcR > 0);
            cout << romanNum << endl;
        } else {
            if(!stringCheck(input)){
                cout << "You have entered a value with numbers and characters. Sorry, that is not allowed" << endl;
                return 0;
            }
            for (int i = 0; i < input.size(); i++) {
                calcList.push_back(getVal(input.at(i)));
            }
            total = calc(calcList);
            cout << total << endl;
        }
    }
    while(input != "end");
    return 0;
}
