#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>
using namespace std;


bool isVowel(char check, vector<char> &v)
{
  if (count(v.begin(), v.end(), check))
  {
    return true;
  }
  return false;
}


string constructName(vector<char> &a, vector<char> &c, vector<char> &v, char len, string aff, char gender)
{

  int nlength;
  if (len == 's') nlength = 3;
  else if (len == 'm') nlength = 4;
  else if (len == 'l') nlength = 5;
  else if (len == 'v') nlength = 10;
  else nlength = 3;

  string result = aff;

  if (aff == "0") result.back() = a[rand() % 26 + 1];

  if (isVowel(result.back(), v)) result.push_back(c[rand() % 21 + 1]);
  else result.push_back(v[rand() % 5 + 1]);

  for (int i = aff.length(); i < nlength; i++)
  {
    if(isVowel(result[i], v)) result.push_back(c[rand() % 21 + 1]);
    else result.push_back(v[rand() % 5 + 1]);
  }


  vector<string> msuffix = {"an", "ar", "oth", "us", "ok", "llo", "ro", "ph", "ang", "kot", "rad", "no", "lo", "dan", "den", "ric", "rick", "ius", "onh", "rak", "tim", "esh", "aro", "ort", "baa", "orru", "zhee", "sam", "rash", "tash", "kud", "osh", "sid", "zav", "hure", "aron", "oron", "ssem", "ham", "mosh", "arum", "aku", "rakul", "eesh", "som", "eem", "yao", "zzor", "gho", "zhul"};
  vector<string> fsuffix = {"th", "na", "ma", "da", "ida", "ava", "tha", "na", "she", "sa", "dra", "ki", "ae", "vae", "ina", "ha", "tai", "lia", "lya", "rae", "lla", "ia", "ina", "ena", "etta", "una", "assa", "sha", "asha", "saa", "essa", "anda", "hoba", "yah", "mah", "zah", "ara", "ryaa", "ya", "nea", "ayo", "zaah", "hee", "ala", "ko", "toko", "sama", "kun", "chan", "yuki", "ji"};
  vector<string> nsuffix = {"nesh", "th", "ne", "me", "ra", "hu", "inx", "ris", "umni", "ni", "ion", "zem", "zu", "see", "his", "yos", "aze", "ral", "za", "maz", "zul", "lleh", "shi", "umni", "esh", "esh", "etu", "zzee", "aim", "tha", "azza", "iros", "rra", "khee", "nen", "zeh", "varh", "shita", "tarr", "eden", "anas", "aral", "sham", "amos", "aam", "yee", "yuu", "mazu"};

  if (gender == 'm') result.append(msuffix[rand() % msuffix.size()]);
  if (gender == 'f') result.append(fsuffix[rand() % fsuffix.size()]);
  if (gender == 'n') result.append(nsuffix[rand() % nsuffix.size()]);

  string substr = result;
  char capital = toupper(result.front());
  substr.erase(0,1);
  result = capital + substr;

  return result;
}


int main()
{

  srand(time(NULL));

  cout << endl;

cout << R"( __  _    __    __ __   ___    __   ___   __  _     __       __
|  \| |  /  \  |  V  | | __|  / _] | __| |  \| |   /  |     /  \
| | ' | | /\ | | \_/ | | _|  | [/\ | _|  | | ' |   `7 | __ | // |
|_|\__| |_||_| |_| |_| |___|  \__/ |___| |_|\__|    |_| \/  \__/  )" << endl << endl << endl;



  cout << "Choose gender (enter 'm' or 'f' or 'n'): " << endl;
  char gender;
  cin >> gender;

  cout << "Choose name length (enter 's', 'm', 'l' or 'v' for very long):" << endl;
  char len;
  cin >> len;

  cout << "Choose affix string (enter 0 for random)" << endl;
  string affix;
  cin >> affix;



  vector<char> vowels, conson, alphabet;


  vowels = {'a','e','i','o','u'};
  conson = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z',};
  int c = 97;
  for (int i = 0; i < 26; i++) {
    alphabet.push_back(c);
    //cout << alphabet[i] << endl;
    c++;
  }


  bool repeat;
  while(repeat)
  {
    string name = constructName(alphabet, conson, vowels, len, affix, gender);
    cout << name << endl;

    if (cin.get() == '\n')
    {
      repeat = true;
      //cout << "---" << endl;
    }
    else
    {
      repeat = false;
    }

  }

}
