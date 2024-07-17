class Solution {
  public:

    string printString(string s, char ch, int count) {
        string str = "";
        int c = 0;
        for(int i = 0; i<s.size(); i++){
            if( c < count){
                if(s[i] == ch)  c++;
            }else{
                str += s[i];
            }
        }
        
        return str;
    }
};
