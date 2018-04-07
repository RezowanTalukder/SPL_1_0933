#include<bits/stdc++.h>

using namespace std;


int getWeight(char ch) {
       switch (ch) {
              case '^': return 3;
              case '/':
              case '*': return 2;
              case '+':
              case '-': return 1;
              default : return 0;
       }
}

int main() {
    int n ;
    cin>>n ;
    while(n--){
           string infix ;
           cin>>infix ;
           int l = infix.length() ;
           string postfix  = "" ;

           stack<char> s;
           int weight;
           int i = 0;
           char ch;

           for(i=0 ;i<l ;i++) {
                  ch = infix[i];
                  if (ch == '(') {
                        s.push(ch);
                        i++;
                        continue;
                  }
                  if (ch == ')') {
                     while (!s.empty() && s.top() != '(') {
                        postfix += s.top();
                        s.pop();
                     }

                     if (!s.empty()) {
                        s.pop();
                     }


                     i++;
                     continue;
                  }

                  weight = getWeight(ch);

                  if (weight == 0) {
                     postfix += ch;

                  }
                  else {

                     if (s.empty()) {
                         s.push(ch);
                     }
                     else {
                        while (!s.empty() && s.top() != '(' &&
                                weight <= getWeight(s.top())) {
                                postfix+= s.top();
                                s.pop();

                        }
                        s.push(ch);
                     }
                  }
                  i++;
           }

           while (!s.empty()) {
               postfix += s.top();
               s.pop();
           }

           cout<<postfix<<endl ;
        }
        return 0;
}
