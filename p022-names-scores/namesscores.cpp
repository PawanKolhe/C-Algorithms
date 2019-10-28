// Project Euler 2019
// Vinicius Rodrigues 20.10.2019
// Names Scores : Problem 22


#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <map>
#include <algorithm>

using namespace std;
map<char, int> charMap;

vector<string> split(const string& s, const char& c)
{
	vector<string> result;
	string aux = "";
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == c)
		{
			result.push_back(aux);
			aux = "";
		}
		else
			aux += s[i];
	}
	if(aux != "")
		result.push_back(aux);
	return result;
}

string strip(const string& s, const char& c)
{
	string new_str = "";
	auto i = s.begin();
	while(*i == c and i != s.end())
		i++;

	while(*i != c and i != s.end())
	{
		new_str += *i;
		i++;
	}
	return new_str;
}

int calcPoints(const string& s)
{
	int score = 0;
	for(auto i = s.begin(); i != s.end(); i++)
		score += charMap[*i];
	return score;
}

int main()
{
	ifstream file("p022_names.txt");
	istream_iterator<string> ii(file);
	string text = *ii;
	
	vector<string> words = split(text, ',');
	for(int i = 0; i < words.size(); i++)
		words[i] = strip(words[i], '\"');

	sort(words.begin(), words.end());

	for(int i = 0; i < 'Z'-'A'+1; i++)
		charMap['A'+i] = i+1;

	int summation = 0;
	for(int i = 0; i < words.size(); i++)
		summation += calcPoints(words[i]) * (i+1);

	cout << summation << endl;
}
