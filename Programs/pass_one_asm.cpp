#include <bits/stdc++.h>

using namespace std;

// initializing Symbol Table 
map<string, int> symbolTable;

int SymTabCounter = 0;
int startAddress = -1;
int ind = -1;

// initializing MOT 
map<string, pair<string, string>> MOT;

// check if instruction is literal
bool onlyNum(string input){
    for (auto it: input){
        if (it>='0' && it<='9'){
            continue;
        }
        return false;
    }
    return true;
}

string computeIC(vector<string> &input){
    string ans = " ";
    bool flag_pass_two = false;

    // evaluating the instruction (word) scanned
    for (int i=0; i<input.size(); i++){
        ans += "( ";
        // checking if instruction is literal
        if (onlyNum(input[i])){
            ans += "c, " + input[i];
        }
        // checking if instruction is START Assembler Directive
        else if (input[i] == "START"){
            ans += MOT[input[i]].first + ", "+ MOT[input[i]].second;
            startAddress = stoi(input[i+1]);
        }
        // checking for instruction in MOT  
        else if (MOT.find(input[i]) != MOT.end()){
            ans += MOT[input[i]].first + ", " + MOT[input[i]].second;
        }
        // evaluating the instruction as a Symbol
        else {
            ans+="S, ";
            // checking if the symbol exists in the Symbol Table      
            if (symbolTable.find(input[i])!=symbolTable.end())
            {
                ans += to_string(symbolTable[input[i]]);
            }
            // since symbol is new, add it to symbol table  
            else
            {
                symbolTable[input[i]] = SymTabCounter;
                ans += to_string(symbolTable[input[i]]);
                SymTabCounter++;
            }
        }
        ans += " )";
    }
    return ans;
}



int main(){
    MOT["STOP"]={"IS","00"};
    MOT["ADD"]={"IS","01"};
    MOT["SUB"]={"IS","02"};
    MOT["MUL"]={"IS","03"};
    MOT["MOVER"]={"IS","04"};
    MOT["MOVEM"]={"IS","05"};
    MOT["COMP"]={"IS","06"};
    MOT["BC"]={"IS","07"};
    MOT["DIV"]={"IS","08"};
    MOT["READ"]={"IS","09"};
    MOT["PRINT"]={"IS","10"};
   
    MOT["START"]={"AD","01"};
    MOT["END"]={"AD","02"};
    MOT["ORIGIN"]={"AD","03"};
    MOT["EQU"]={"AD","04"};
    MOT["LTORG"]={"AD","05"};
   
    MOT["DS"]={"DL","01"};
    MOT["DC"]={"DL","02"};
   
    MOT["AREG"]={"RG","01"};
    MOT["BREG"]={"RG","02"};
    MOT["CREG"]={"RG","03"};
   
    MOT["LT"]={"CC","01"};
    MOT["LE"]={"CC","02"};
    MOT["EQ"]={"CC","03"};
    MOT["GT"]={"CC","04"};
    MOT["GE"]={"CC","05"};
    MOT["ANY"]={"CC","06"};
    
    int n;
    cout << "Enter number of lines: "; cin >> n;
    cout << "Enter " << n << " number of lines:\n";

    vector<vector<string>> inputProgram;
    for (int i=0; i<n; i++){
        string s;
        if (i==0) getline(cin, s);
        getline(cin, s);
        string temp = "";
        vector<string> tempInput;
        for (auto it: s){
            if (it == ' '){
                tempInput.push_back(temp);
                temp = "";
                continue;
            }
            temp+=it;
        }
        tempInput.push_back(temp);
        inputProgram.push_back(tempInput);
    }
    
    cout << "\tPASS-1 Table:\n";
    cout << "\nLC \t Intermediate Code\n";

    for (auto it: inputProgram){
        string pass1 = computeIC(it);
        if (ind >= 0) cout << (startAddress+ind);
        cout << " \t " << pass1 << endl;    
        ind++;    
    }

    cout << "\nSymbol Table:\n";
    for (auto it: symbolTable){
        if(it.first.size()==1){
            cout << it.first << " \t " << (501+it.second) << endl;
        }
    }
    return 0;
}