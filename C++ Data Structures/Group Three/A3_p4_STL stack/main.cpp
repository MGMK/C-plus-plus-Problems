#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

bool TestConditionsFun(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}
bool ExprationFunction(string str)
{
	stack<char>S;
	for(int i = 0;i<str.length();i++)
	{
		if(str[i] == '(' || str[i] == '{' || str[i] == '[' || str[i] == '/*')
			S.push(str[i]);

		else if(str[i] == ')' || str[i] == '}' || str[i] == ']' || str[i] == '*/')
		{
			if(S.empty() || !TestConditionsFun(S.top(),str[i]))
				return false;
			else
				S.pop();
		}
	}
//
//	if(S.empty())
//        return true;
//    else
//        return false;

}

int main()
{
	string expression;
	cout<<"Enter an expression:  ";
    cin>>expression;
	if(ExprationFunction(expression))
		cout<<"Valid\n";
	else
		cout<<"Not Valid\n";
}
