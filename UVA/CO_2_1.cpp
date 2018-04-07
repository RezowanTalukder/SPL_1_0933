#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int n ;
    cin >> n ;

    while(n--)
    {
        string str ;
        stack<char>st ;
        cin>>str ;
        int l = str.length() ;
        int flag = 1 ;

        for(int i=0 ;i<l ;i++){
            if(str[i]=='('){
                st.push(str[i]) ;
            }
            else if(str[i]=='['){
                st.push(str[i]) ;
            }
            else if(str[i]==')'){

                if(st.empty()){
                        cout<<"No"<<endl ;
                        flag = 0 ;
                        break ;
                }

                char ch = st.top() ;

                if(ch!='('){
                    cout<<"No"<<endl ;
                    flag = 0 ;
                    break ;
                }

                else st.pop() ;

            }
            else if(str[i]==']'){
                if(st.empty()){
                        cout<<"No"<<endl ;
                        flag = 0 ;
                        break ;
                }

                char ch = st.top() ;

                if(ch!='['){
                    cout<<"No"<<endl ;
                    flag = 0 ;
                    break ;
                }


                else st.pop() ;

            }
        }
        if(st.empty() && flag==1)cout<<"Yes"<<endl  ;
    }
    return 0;
}
