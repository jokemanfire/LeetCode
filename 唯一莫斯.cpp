#include"global.h"

class Solution {
public:
	int uniqueMorseRepresentations(vector<string>& words) {
		vector<string> Secr = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
		set<string> Result;
		for (int i = 0; i < words.size(); i++)
		{
			string temp;
			for (int j = 0; j < words[i].size(); j++)
			{
				temp += Secr[words[i][j] - 'a'];
			}
			Result.insert(temp);
		}
		return Result.size();


	};
}