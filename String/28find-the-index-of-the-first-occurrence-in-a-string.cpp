class Solution {
public:
    int strStr(string haystack, string needle) {
        int next[needle.size()];
        getNext(next,needle);
        int index_sub = 0;
        int index_orin = 0;
        while(index_orin<haystack.size()){
            if(needle[index_sub]==haystack[index_orin]){
                index_sub++;
                index_orin++;
            }
            else{
                if(index_sub>0){
                    index_sub = next[index_sub-1];                                        
                }
                else{
                    index_orin++;
                }
            }
            if(index_sub==needle.size()){
                return index_orin-needle.size();
            }            
        }

        return -1;
    }

    void getNext(int* next, const string& s){
        int index_front = 0;
        next[0] = 0;
        // int index_back = 
        for(int index_back =1;index_back<s.size();index_back++){
            while(index_front>0&&s[index_front]!=s[index_back]){
                index_front = next[index_front-1];
            }
            if(s[index_front]==s[index_back]){
                index_front++;
            }
            next[index_back] = index_front;

        }
    }

};