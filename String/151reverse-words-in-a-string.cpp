
#include <string> 
#include <iostream>
using namespace std;

class Solution {
public:
    //step1: 使用快慢指针清除空格,并重新调整字符串长度
    //s2: reverse整体串
    //s3: 找到局部单词串reverse回来


    string remove_space(string s){
        int ind_sl=0,ind_fas = 0;

        while(s.size()>0&&ind_fas<s.size()&&s[ind_fas]==' '){
            ind_fas++;
        }


        for(;ind_fas<s.size();ind_fas++){

            if(s[ind_fas]==' '&&(s[ind_fas]==s[ind_fas-1])){
                continue;
            }
            s[ind_sl] = s[ind_fas];
            ind_sl++;
        }

        if(ind_sl>1&&s[ind_sl-1]==' '){
            s.resize(ind_sl-1);
        }
        else{
            s.resize(ind_sl);    
        }

        return s; 
    }

    string reverse_string(string s,int start,int end) {
        int index_left = start;
        int index_right = end;
        while(index_left<index_right){
            char temp = s[index_left];
            s[index_left] = s[index_right];
            s[index_right] = temp;
            // swap(s[index_left],s[index_right]);
            index_left++;
            index_right--;
        }
        return s; 
    }

    string reverseWords(string s) {
        s = remove_space(s);
        s = reverse_string(s,0,s.size()-1);
        int word_start=0,word_end = 0;
        while(word_end<s.size()){
            if((word_end<(s.size()-1) && s[word_end+1]==' ')|| word_end==s.size()-1){
                s = reverse_string(s,word_start,word_end);
                word_start = word_end+2;
            }
            word_end++;
        }

        return s; 
    }

};



int main(void)
{
    Solution solution;
    string s= " shahao && gaojinglei ";
    s = solution.reverseWords(s);
    cout << s << endl;
    return 0;
} 