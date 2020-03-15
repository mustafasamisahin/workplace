#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

bool sortbysec(const pair<int,string> &a, const pair<int,string> &b){
	            return (a.second < b.second);
}

int main(){
	fstream file;
	string word, filename;
	pair <int, string> vocab[1000];
	int i = 0, j = 0, count = 0;
	bool contains = false;
	
	while (cin >> word){
		contains = false;
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		if(vocab[0].second.empty() ){
			vocab[i].second = word;
			vocab[i].first = 1;
		}
		else{
			for(j = 0; j<distance(begin(vocab), end(vocab)) ; j++){
				if ( get<1>(vocab[j]) == word){
					contains = true;
					vocab[j].first = vocab[j].first + 1;
					break;
				}
			}
			if ( contains){
			}
			else{
				vocab[i].second = word;
				vocab[i].first = 1;
			}
		}
		i++;

	}

	sort(begin(vocab), end(vocab), ::sortbysec);
	for(int i=999; i>0; i--){
		if(vocab[i].first != 0){
			count++;
		}
		
	}
	cout << "Vocabulary Size = " << count << endl;
	for (int i=0; i<distance(begin(vocab), end(vocab)); i++){ 
		if(vocab[i].first < 1)
			continue;	
	       	cout << vocab[i].second << ' ' << vocab[i].first << endl;
	} 
	
	return 0;
}

