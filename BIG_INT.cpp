#include<iostream>
using namespace std;
#include<string.h>

class bigint{

public: 

string addi(string a1,string a2){
    string res="";
    int max= (a1.size()>a2.size()?a1.size():a2.size());
    int* n1 = new int [max] {};
    int* n2 = new int [max] {};
    for( int i=0;i< a1.size();i++)
        n1[i]=a1[a1.size()-1-i]-'0';
        
     for( int i=0;i< a2.size();i++)
        n2[i]=a2[a2.size()-1-i]-'0';
     int carry =0;
     int* sum= new int[max+1];
     for(int k=0; k<max ;k++){
        sum[k]=(n1[k]+n2[k]+carry)%10;
        carry=(n1[k]+n2[k]+carry)/10;
     }
     sum[max]=carry;
     for(int w=max,j=0;w>=0;w--){
        res+=to_string(sum[w]);
     }
      int nonZeroIndex = res.find_first_not_of('0');
    if (nonZeroIndex != string::npos) {
        res = res.substr(nonZeroIndex);
    } else {
        res = "0";
    }
    
      delete[] n1;
    delete[] n2;
    delete[] sum;
    return res;


    
  
}


string subtract(string a, string b) {
    if (a.length() < b.length() || (a.length() == b.length() && a < b)) {
        swap(a, b);
    }
    
    string result = "";
    int carry = 0;
    
    for (int i = a.length() - 1, j = b.length() - 1; i >= 0; i--, j--) {
        int digitA = a[i] - '0';
        int digitB = j >= 0 ? b[j] - '0' : 0;
        
        int diff = digitA - digitB - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        
        result = to_string(diff) + result;
    }
    
    // Remove leading zeros
    int nonZeroIndex = result.find_first_not_of('0');
    if (nonZeroIndex != string::npos) {
        result = result.substr(nonZeroIndex);
    } else {
        result = "0";
    }
    
    return result;
}
string multi(string m1, string m2) {
    int m1len = m1.size();
    int m2len = m2.size();
    int len = m1len + m2len;
    int *res = new int[len]{}; 

    for (int i = 0; i < m1len; i++) {
        int carry = 0;
        int x = m1[m1len - 1 - i] - '0';

        for (int j = 0; j < m2len; j++) {
            int y = m2[m2len - 1 - j] - '0';
            int product = x * y + res[i + j] + carry;
            carry = product / 10;
            res[i + j] = product % 10;
        }

        res[i + m2len] += carry;
    }

    string op;

    for (int i = len - 1; i >= 0; i--)
        op += to_string(res[i]);

    while (op.size() > 1 && op[0] == '0')
        op.erase(op.begin());

    delete[] res;
    return op;
}
string division(string dividend, string divisor) {
    string quotient;
    string currentDividend;
    
  

    int idx = 0;
    while (idx < dividend.length()) {
        currentDividend += dividend[idx];
        int quotientDigit = 0;
        while (currentDividend.length() > 0 && currentDividend[0] == '0') {
            currentDividend = currentDividend.substr(1);
        }
         while ((currentDividend.length() >= divisor.length()) && !((currentDividend.length() < divisor.length() || (currentDividend.length() == divisor.length() && currentDividend < divisor)))) {   
            currentDividend=subtract(currentDividend,divisor);
            quotientDigit++;
        }
        quotient += to_string(quotientDigit);
        idx++;
    }

    if (quotient.empty()) {
        quotient = "0";
    }
    return quotient;
}

string eval(const std::string& s) {
    string temp[3000];
    char opr[3000];
    int operand = 0;
    string tempres;
    int k = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != '+' && s[i] != '-' && s[i] != 'x' && s[i] != '/') {
            temp[operand].insert(temp[operand].size(), 1, s[i]);
        } else {
            while (k >=1 && (opr[k - 1] == 'x' || opr[k - 1] == '/'|| opr[k-1]=='-')){
                string val1 = temp[operand - 1];
                string val2 = temp[operand];
                temp[operand-1]='0';
                temp[operand]='0';
                --operand;

                switch (opr[--k]) {
                    case 'x':
                        tempres = multi(val1, val2);
                        break;
                    case '/':
                        tempres = division(val1, val2);
                        break;
                    case '-':
                         tempres= subtract(val1,val2);    
                }

                temp[operand] = tempres;
            }

            opr[k++] = s[i];
            operand++;
        }
    }
    
    while (k > 0) {
        string val1 = temp[operand - 1];
        string val2 = temp[operand];
        --operand;
        switch (opr[--k]) {
            case '+':
                tempres = addi(val1, val2);
                temp[operand] = tempres;
                break;
            case '-':
                tempres = subtract(val1, val2);
                temp[operand] = tempres;
                break;
            case 'x':
                tempres = multi(val1, val2);
                temp[operand] = tempres;
                break;
            case '/':
                tempres = division(val1, val2);
                temp[operand] = tempres;
                break;   
        }
    }
     int nonZeroIndex = temp[0].find_first_not_of('0');
    if (nonZeroIndex != string::npos) {
        temp[0] = temp[0].substr(nonZeroIndex);
    } else {
        temp[0]= "0";
    }
    
    return temp[0];
}

string expo(string e1,string e2){
    string result;
    int pow=stoll(e2);
    result= multi(e1,e1);
    for(int i=0;i<pow-2;i++)
      result=multi(result,e1);
     
    return result; 
}
string gcd(string g1, string g2) {
    string n1 = g1;
    string n2 = g2;
    string rem;
    
    while (n2 != "0") {
        if (n1.length() < n2.length() || (n1.length() == n2.length() && n1 < n2)) {
            swap(n1, n2);
        } else {
            rem = subtract(n1, n2);
            n1 = n2;
            n2 = rem;
        }
    }
    
    return n1;
}
string fact(string f1){
 string factorial="1";
 string test="1";
 while(test != f1){
    factorial = multi(factorial,test);
    test=addi(test,"1");
 }
  factorial = multi(factorial,test);
    test=addi(test,"1");
 return factorial;
}
};
 


int main(){
 string s1,s2;
 bigint o1;
 int choice;
 cin>>choice;
 switch(choice){
    case 1: cin>>s1;
            cout<<o1.eval(s1)<<endl;;   
             
            break;
    case 2:cin>>s1>>s2;
            cout<<o1.expo(s1,s2)<<endl;
            break;
    case 3: cin>>s1>>s2;
             cout<<o1.gcd(s1,s2)<<endl;
             break;
    case 4: cin>>s1;
            cout<<o1.fact(s1)<<endl;
            break;
    default:cout<<"Invaild Input";                                
 }
 return 0;
}