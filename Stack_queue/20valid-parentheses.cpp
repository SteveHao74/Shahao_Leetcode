class Solution {
public:
    stack<char> st_char;
    std::unordered_map <char,char> map;

    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        map.insert(pair<char,char>('(',')'));
        map.insert(pair<char,char>('[',']'));
        map.insert(pair<char,char>('{','}'));
        for(char c:s){
            auto inter = map.find(c);
            if(inter !=map.end()){
                st_char.push(map[c]);
            }
            else{
                if(st_char.empty()||c!=st_char.top())return false;
                st_char.pop();
            }
        }
        return st_char.empty();

    }
};