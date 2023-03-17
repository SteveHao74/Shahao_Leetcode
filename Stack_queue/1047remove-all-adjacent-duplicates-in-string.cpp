// class Solution {
// public:
//     string removeDuplicates(string s) {
//         stack<char> stack_char;
//         for(char c:s){
//             if(!stack_char.empty()&&stack_char.top()==c){
//                 stack_char.pop();
//             }
//             else{
//                 stack_char.push(c);
//             }
//         }
//         string result = "";
//         //for(int i=0;i<stack_char.size();i++)
//         while(!stack_char.empty()){
//             result += stack_char.top();
//             stack_char.pop();
//         }
//         reverse(result.begin(),result.end());

//         return result;
//     }
// };

class Solution {
public:
    string removeDuplicates(string s) {
        string stk;
        for (char ch : s) {
            if (!stk.empty() && stk.back() == ch) {
                stk.pop_back();
            } else {
                stk.push_back(ch);
            }
        }
        return stk;
    }
};

