class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        // for chrcking the visted one 
        unordered_set<string>st(wordList.begin(),wordList.end());
    q.push({beginWord,1});
    st.erase(beginWord);
    while(!q.empty()){
   string word=q.front().first;
   int len=q.front().second;
   q.pop();
   if(word==endWord)return len;
   // now we will traverse for every word 
   for (int i=0;i<word.length();i++){
  char orginal=word[i];
  for(char ch='a';ch<='z';ch++){
    word[i]=ch;
    if(st.find(word)!=st.end()){
        q.push({word,len+1});
        st.erase(word);
    }
  }
  word[i]=orginal;
    }
    }

return 0;
    }
};