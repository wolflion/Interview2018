

/* 2016年校招
 * 写一段代码，判断一个包括'{','[','(',')',']','}'的表达式是否合法
 (注意看样例的合法规则。)给定一个表达式A,请返回一个bool值，代表它是否合法。
 */

 // "[a+b*(5-4)]*{x+b+b*(({1+2)}}"  返回true

 // 点评题 https://www.nowcoder.com/questionTerminal/227893ccf81d4e8589875922f0d9319e

// 参考：http://blog.csdn.net/nanami809/article/details/49513237
 #include <iostream>
 #include <string>
 #include <stdlib.h>

 using namespace std;

 int isBracket(char a)
 {
 	if(a=='{' || a=='[' || a=='(')
 	{
 		return 1;
 	}
 	else if (a=='}' || a==']' || a==')')
 	{
 		return 2;
 	}
 	return 0;
 }

 bool chkLegal(string A)
 {
 	int n = A.length();
 	int top = 0;  // 栈顶指针
 	for(int i=0;i<n;i++)
 	{
 		int c = isBracket(A[i]);
 		if(c == 0)
 		{
 			continue;
 		}
 		else if(c == 1)
 		{
 			top++;
 		}
 		else if(c == 2)
 		{
 			top--;
 			if(top < 0)  // 右括号比左括号多
 			{
 				return false;  
 			}
 		}
 	}
 	if(top == 0)
 		return true;
 	else 
 		return false;
 }


int main()
{
	string s = "[a+b*(5-4)]*{x+b+b*(({1+2)}}";
	//cin >> s;
	if( chkLegal(s) == true)
		// return true; 我这写的是return，所以到system("pause")那没用
		cout << "true" << endl;
	else
		cout << "false" << endl;
	
	system("pause");
	return 0;
}


#if 0  
// 这也是我想学好STL的原因，这样简单数据结构的问题，可以直接用了。
public static boolean chkLegal(String A) {
        // write code here
        Stack<Character> stack = new Stack<Character>();
        char[] cs = A.toCharArray();  // 这个string的操作，我见得不多。
        for(int i=0;i<cs.length;i++){
            if(cs[i] == '(' || cs[i] == '{' || cs[i] == '['){
                stack.push(cs[i]);
            }
            if(cs[i] == ')' || cs[i] == '}' || cs[i] == ']'){
                stack.pop();
            }
        }
        return stack.isEmpty();
    }
#endif


#if 0
// 这个解决文案，我不知道是不是适合所有场景，而不只是验证两边的括号相等
class ChkExpression {
public:
    bool chkLegal(string A) {
        int num=A.size();
        int s=0;
        int *flag=new int[num];
        for(int i=0;i<num;i++)
            flag[i]=0;
        for(int i=0;i<num;i++)
            {
            if(A[i]=='{'&&flag[i]==0)
                {
                flag[i]=1;
                s++;
                for(int j=i+1;j<num;j++)
                    if(A[j]=='}'&&flag[j]==0)
                {flag[j]=1;s--; break;}
            }
             if(A[i]=='('&&flag[i]==0)
                {
                flag[i]=1;
                s++;
                for(int j=i+1;j<num;j++)
                    if(A[j]==')'&&flag[j]==0)
                {flag[j]=1;s--; break;}
             }
             if(A[i]=='['&&flag[i]==0)
                {
                flag[i]=1;
                s++;
                for(int j=i+1;j<num;j++)
                    if(A[j]==']'&&flag[j]==0)
                {flag[j]=1;s--; break;}
             }
                  
            }
        if(s==0)return true;
        else return false;
        }
};

#endif 