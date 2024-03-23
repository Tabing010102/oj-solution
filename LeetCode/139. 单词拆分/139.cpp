#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 10;
string ts;
int n;
string sl[MAXN];
int sll[MAXN];
int ansv[MAXN];
bool vis[MAXN];
bool ans;

class Solution {
public:
	bool fit(int p, int slp) {
		string &s = sl[slp];
		for (int i = sll[slp] - 1, j = 0; i >= 0; i--, j++) {
			if (ts[p - j] != s[i]) {
				return false;
			}
		}
		return true;
	}
	bool search(int p) {
		if (vis[p]) { return ansv[p]; }
		else if (ans) { return true; }
		else if (ansv[p] == true) { return true; }
		else {
			for (int i = 0; i < n; i++) {
				if (p - sll[i] > -1 && (vis[p - sll[i]] || ansv[p - sll[i]])) {
					if (ansv[p - sll[i]]) { return ansv[p] = true; }
					else { continue; }
				} else if (sll[i] > p + 2) { continue; }
				else if (sll[i] == p + 1 && fit(p, i)) {
					ans = true;
					return ansv[p] = true;
				} else if (p - sll[i] > -1 && ansv[p - sll[i]]) {
					return ansv[p] = true;
				} else if (p - sll[i] >= -1 && fit(p, i)) {
					int a = search(p - sll[i]);
					if (a) { return ansv[p] = a; }
					else { continue; }
				}
			}
			vis[p] = true;
			return ansv[p];
		}
	}
    bool wordBreak(string s, vector<string>& wordDict) {
    	ts = s;
    	n = wordDict.size();
		for (int i = 0; i < n; i++) {
			sl[i] = wordDict[i]; 
			sll[i] = sl[i].size();
		}
		memset(ansv, 0, sizeof(ansv));
		memset(vis, 0, sizeof(vis));
		ans = false;
		bool ans1 = search(s.size() - 1);
		return ans1;
    }
};

int main() {
	Solution s;
//	vector<string> x = { "leet", "code" };
//	auto ans = s.wordBreak("leetcode", x);
//	vector<string> x = { "apple", "pen" };
//	auto ans = s.wordBreak("applepenapple", x);
//	vector<string> x = { "cats", "dog", "sand", "and", "cat" };
//	auto ans = s.wordBreak("catsandog", x);
//	vector<string> x = { "b" };
//	auto ans = s.wordBreak("a", x);
//	vector<string> x = { "aaaa","aa" };
//	auto ans = s.wordBreak("aaaaaaa", x);
//	vector<string> x = { "pavira","pavi","raa","gi","ag","ii" };
//	auto ans = s.wordBreak("paviraagi", x);
	vector<string> x = { "kfomka","hecagbngambii","anobmnikj","c","nnkmfelneemfgcl","ah","bgomgohl","lcbjbg","ebjfoiddndih","hjknoamjbfhckb","eioldlijmmla","nbekmcnakif","fgahmihodolmhbi","gnjfe","hk","b","jbfgm","ecojceoaejkkoed","cemodhmbcmgl","j","gdcnjj","kolaijoicbc","liibjjcini","lmbenj","eklingemgdjncaa","m","hkh","fblb","fk","nnfkfanaga","eldjml","iejn","gbmjfdooeeko","jafogijka","ngnfggojmhclkjd","bfagnfclg","imkeobcdidiifbm","ogeo","gicjog","cjnibenelm","ogoloc","edciifkaff","kbeeg","nebn","jdd","aeojhclmdn","dilbhl","dkk","bgmck","ohgkefkadonafg","labem","fheoglj","gkcanacfjfhogjc","eglkcddd","lelelihakeh","hhjijfiodfi","enehbibnhfjd","gkm","ggj","ag","hhhjogk","lllicdhihn","goakjjnk","lhbn","fhheedadamlnedh","bin","cl","ggjljjjf","fdcdaobhlhgj","nijlf","i","gaemagobjfc","dg","g","jhlelodgeekj","hcimohlni","fdoiohikhacgb","k","doiaigclm","bdfaoncbhfkdbjd","f","jaikbciac","cjgadmfoodmba","molokllh","gfkngeebnggo","lahd","n","ehfngoc","lejfcee","kofhmoh","cgda","de","kljnicikjeh","edomdbibhif","jehdkgmmofihdi","hifcjkloebel","gcghgbemjege","kobhhefbbb","aaikgaolhllhlm","akg","kmmikgkhnn","dnamfhaf","mjhj","ifadcgmgjaa","acnjehgkflgkd","bjj","maihjn","ojakklhl","ign","jhd","kndkhbebgh","amljjfeahcdlfdg","fnboolobch","gcclgcoaojc","kfokbbkllmcd","fec","dljma","noa","cfjie","fohhemkka","bfaldajf","nbk","kmbnjoalnhki","ccieabbnlhbjmj","nmacelialookal","hdlefnbmgklo","bfbblofk","doohocnadd","klmed","e","hkkcmbljlojkghm","jjiadlgf","ogadjhambjikce","bglghjndlk","gackokkbhj","oofohdogb","leiolllnjj","edekdnibja","gjhglilocif","ccfnfjalchc","gl","ihee","cfgccdmecem","mdmcdgjelhgk","laboglchdhbk","ajmiim","cebhalkngloae","hgohednmkahdi","ddiecjnkmgbbei","ajaengmcdlbk","kgg","ndchkjdn","heklaamafiomea","ehg","imelcifnhkae","hcgadilb","elndjcodnhcc","nkjd","gjnfkogkjeobo","eolega","lm","jddfkfbbbhia","cddmfeckheeo","bfnmaalmjdb","fbcg","ko","mojfj","kk","bbljjnnikdhg","l","calbc","mkekn","ejlhdk","hkebdiebecf","emhelbbda","mlba","ckjmih","odfacclfl","lgfjjbgookmnoe","begnkogf","gakojeblk","bfflcmdko","cfdclljcg","ho","fo","acmi","oemknmffgcio","mlkhk","kfhkndmdojhidg","ckfcibmnikn","dgoecamdliaeeoa","ocealkbbec","kbmmihb","ncikad","hi","nccjbnldneijc","hgiccigeehmdl","dlfmjhmioa","kmff","gfhkd","okiamg","ekdbamm","fc","neg","cfmo","ccgahikbbl","khhoc","elbg","cbghbacjbfm","jkagbmfgemjfg","ijceidhhajmja","imibemhdg","ja","idkfd","ndogdkjjkf","fhic","ooajkki","fdnjhh","ba","jdlnidngkfffbmi","jddjfnnjoidcnm","kghljjikbacd","idllbbn","d","mgkajbnjedeiee","fbllleanknmoomb","lom","kofjmmjm","mcdlbglonin","gcnboanh","fggii","fdkbmic","bbiln","cdjcjhonjgiagkb","kooenbeoongcle","cecnlfbaanckdkj","fejlmog","fanekdneoaammb","maojbcegdamn","bcmanmjdeabdo","amloj","adgoej","jh","fhf","cogdljlgek","o","joeiajlioggj","oncal","lbgg","elainnbffk","hbdi","femcanllndoh","ke","hmib","nagfahhljh","ibifdlfeechcbal","knec","oegfcghlgalcnno","abiefmjldmln","mlfglgni","jkofhjeb","ifjbneblfldjel","nahhcimkjhjgb","cdgkbn","nnklfbeecgedie","gmllmjbodhgllc","hogollongjo","fmoinacebll","fkngbganmh","jgdblmhlmfij","fkkdjknahamcfb","aieakdokibj","hddlcdiailhd","iajhmg","jenocgo","embdib","dghbmljjogka","bahcggjgmlf","fb","jldkcfom","mfi","kdkke","odhbl","jin","kcjmkggcmnami","kofig","bid","ohnohi","fcbojdgoaoa","dj","ifkbmbod","dhdedohlghk","nmkeakohicfdjf","ahbifnnoaldgbj","egldeibiinoac","iehfhjjjmil","bmeimi","ombngooicknel","lfdkngobmik","ifjcjkfnmgjcnmi","fmf","aoeaa","an","ffgddcjblehhggo","hijfdcchdilcl","hacbaamkhblnkk","najefebghcbkjfl","hcnnlogjfmmjcma","njgcogemlnohl","ihejh","ej","ofn","ggcklj","omah","hg","obk","giig","cklna","lihaiollfnem","ionlnlhjckf","cfdlijnmgjoebl","dloehimen","acggkacahfhkdne","iecd","gn","odgbnalk","ahfhcd","dghlag","bchfe","dldblmnbifnmlo","cffhbijal","dbddifnojfibha","mhh","cjjol","fed","bhcnf","ciiibbedklnnk","ikniooicmm","ejf","ammeennkcdgbjco","jmhmd","cek","bjbhcmda","kfjmhbf","chjmmnea","ifccifn","naedmco","iohchafbega","kjejfhbco","anlhhhhg" };
	auto ans = s.wordBreak("fohhemkkaecojceoaejkkoedkofhmohkcjmkggcmnami", x);
	cout << ans << endl;
	return 0;
}
