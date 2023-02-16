'''
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

 

注意：

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-window-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''


'''
用try,except来直接对付不在子串中的元素,就把本来的遍历O(n)降为O(1),使得整体从O(n2)降为O(n);但不确定try,except是否本身的常数时间也挺大,还请大佬指教；

在优化代码过程中,还发现左指针其实不需要完全满足全部条件才能右移缩小窗口,只要所在元素局部满足条件即可,这种优化可以避免对考虑一些冗余子串,提高了我原始代码的效率.

作者：stevehao
链接：https://leetcode.cn/problems/minimum-window-substring/solution/bie-chu-xin-cai-yong-tryexceptshi-jian-x-ynkl/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
'''
class Solution:

    def minWindow(self, s: str, t: str) -> str:
        if len(s)<len(t):
            return ""
        hash_s, hash_t = self.hash_generate(t)
        index_start,index_end = self.init_index(s,hash_s)
        if (index_end - index_start+1)<len(t):
            return ""

        index_left = index_right = index_start
        sub_string = ""
        sub_string_len = (index_end - index_start+1)
        counter = 0
         
        while index_right <= index_end:
            try:
                hash_s[s[index_right]] += 1
                if hash_s[s[index_right]] <= hash_t[s[index_right]]:
                    counter += 1
            except:
                pass
            

                
            while index_left<=index_right:#move left

                try:
                    if hash_s[s[index_left]] <= hash_t[s[index_left]]:
                        break
                    hash_s[s[index_left]] -= 1
                except:
                    pass
                index_left += 1

            if counter == len(t):  
                if sub_string_len>= (index_right - index_left+1):
                    sub_string_len = (index_right - index_left+1)
                    sub_string = s[index_left:index_right+1] 
            
            #move right
            index_right += 1

        return  sub_string       


    def init_index(self, s, hash_s):
        index_start = 0
        index_end = len(s)-1
        flag_start = False
        flag_end = False
        while True:
            if index_start>index_end:
                break

            if flag_start and flag_end:
                break

            if flag_start==False:
                try:
                    temp = hash_s[s[index_start]]
                    flag_start= True
                except:
                    index_start += 1
            
            if flag_end==False:
                try:
                    temp = hash_s[s[flag_end]]
                    flag_end= True
                except:
                    flag_end -= 1

        return index_start,index_end##left close, right close


    def hash_generate(self, in_string):
        temp_dict_s = {}
        temp_dict_t = {}
        for char in in_string:
            try:
                temp_dict_t[char] += 1
            except:
                temp_dict_t[char] = 1
            temp_dict_s[char] = 0
        return temp_dict_s,temp_dict_t



if __name__ == "__main__":
    s = "ADOBECODEBANC"
    t = "ABC"

    solution = Solution()
    solution.minWindow(s,t)