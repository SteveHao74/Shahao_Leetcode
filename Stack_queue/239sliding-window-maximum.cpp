class Solution {
public:

    class Monotonic_queue{
    public:
        deque<int> mono_que;
        
        void mono_pop(int value){
            if(!mono_que.empty() && value==mono_que.front()){//因为后续滑动窗口移动时,队列要先pop再push,所以一开始的情况,是要面对空队列进行统一操作；
                mono_que.pop_front();
            }
        } 
        void mono_push(int value){
            while(!mono_que.empty() && value>mono_que.back()){
                mono_que.pop_back();
            }
            mono_que.push_back(value);
        }

        int mono_front(){
            return mono_que.front();
        }
    };

    Monotonic_queue my_que;

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int index_b = 0;
        int index_f = 0;

        while(index_f<k){
            my_que.mono_push(nums[index_f]);
            index_f++;
        }

        result.push_back(my_que.mono_front());
        while(index_f<nums.size()){
            my_que.mono_pop(nums[index_b]);
            my_que.mono_push(nums[index_f]);
            result.push_back(my_que.mono_front());
            index_b++;
            index_f++;
        }

        return result;
    }
};