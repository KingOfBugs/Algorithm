class Solution {
public:
    void reverseWords(string &s) {
        int n = s.size();
        if(0 == n)
            return;
		
		//去除多余空格
        int slow = -1, fast = 0;
        while(fast < n && s[fast] == ' ')
            ++fast;
        while(fast < n) {
            if(s[fast] != ' ' || s[fast] == ' ' && s[slow] != ' ') {
                s[++slow] = s[fast];
            }
            fast++;
        }
        if(s[slow] == ' ') {
            s.resize(slow);
        }
        else {
            s.resize(slow + 1);
        }
		
		//整体翻转
        n = s.size();
        rev(s, 0, n-1);
		
		//各个单词翻转
        slow = 0;
        fast = 0;
        while(fast < n) {
            if(fast == n - 1 || s[fast+1] == ' ') { //后边有空格或者到达最后一个单词则表示一个单词结束
                rev(s, slow, fast);
                slow = fast + 2;
                fast = fast + 2;
            }
            else {
                ++fast;
            }
        }        
    }
    
    void rev(string& s, int slow, int fast) {
        while(slow < fast) {
            swap(s[slow++], s[fast--]);
            
        }
    }
};