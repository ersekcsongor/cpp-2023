#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <random>

using namespace std;

bool containsApple(string &fruit);

bool isBanana(const string &fruit);

void doubleElements(int &num);



int main() {
    std::cout << "Hello, Lab_09" << std::endl;
    vector<string> fruits {
            "melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"
    };
    vector<string> bananas {
            "banana", "banana", "banana","banana", "banana", "banana", "banana"
    };
    vector<int> Array = {1,2,3,4,5};
    auto it = find_if(fruits.begin(), fruits.end(), [](string fruit) {
        return (fruit.find("apple") != string::npos);
    });
    auto it2 = find_if(fruits.begin(), fruits.end(), containsApple);
    if(it2 == fruits.end())
    {
        cout << "No apples!\n";
    }
    else
    {
        cout << "Found\n";
    }
    if (bool areAllBananas =  all_of(bananas.begin(),bananas.end(),[](string &fruit){
        return fruit == "banana";
    }) == 1)
    {
        cout << "All items are bananas" << endl;
    }
    else{
        cout << "Not all items are bananas" << endl;
    }

    for_each(Array.begin(),Array.end(),[](int &num){
        return num *= 2;
    });
    for(int num : Array)
    {
        cout << num << " ";
    }
    cout << endl;
    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };
    int countFiveLetterWords = count_if(months.begin(),months.end(),[](string month){
        return month.size() == 5;
    });
    cout << "Five Letter Word Months: "<< countFiveLetterWords << endl;
    vector<double> realNum = {5.2, 5.3, 9, 1, 7};
    /*sort(realNum.begin(),realNum.end(),[](double a,double b){
        return a > b;
    });*/
    for(double num : realNum)
    {
        cout << num << " ";
    }
    cout << endl;


    sort(realNum.begin(),realNum.end(),greater<>());

    for(double num : realNum)
    {
        cout << num << " ";
    }
    cout << endl;
    vector<pair<string,int>>monthAvgTemp = {
            {"Jan", 5.6},
            {"Feb", 6.8},
            {"Mar", 10.2},
            {"Apr", 14.5},
            {"May", 18.2},
            {"Jun", 21.5},
            {"Jul", 24.2},
            {"Aug", 27.2},
            {"Sep", 21.2},
            {"Oct", 15.2},
            {"Nov", 5.2},
            {"Dec", -5.2}
    };
    cout << fixed << setprecision(0);
    sort(monthAvgTemp.begin(),monthAvgTemp.end(),[](const pair<string,double> &a,const pair<string,double> &b){
        return a.second < b.second;
    });
    for(const pair<string,double>temp : monthAvgTemp)
    {
        cout << temp.first << " " << temp.second << endl;
    }
    vector<double> numbers = {5.6, -2.3, 8.9, -1.2, 3.4};
    sort(numbers.begin(),numbers.end(),[](const double &a,const double &b){
       return abs(a) < abs(b);
    });
    cout << "Numbers after abs value sort: ";
    for(auto num : numbers)
    {
        cout << num << " ";
    }
    cout << endl;
    transform(months.begin(),months.end(),months.begin(),
              [](string &str){
                if(!str.empty())
                {
                    str[0] = ::tolower(str[0]);
                }
                  return str;
    });
    cout << "Kisbetus honapok: ";
    for(const auto &month : months)
        cout << month <<" ";
    cout << endl;
    string alphabet;
    int index = 0;
    for (char letter = 'a'; letter <= 'z'; ++letter) {
        alphabet.push_back(letter);
    }
    random_device rd;
    mt19937 g(rd());
    shuffle(alphabet.begin(), alphabet.end(), g);
    for (char letter : alphabet) {
        cout << letter << " ";
    }

    cout << alphabet << endl;

    auto compare = [&](const string& a, const string& b) {
        for (size_t i = 0; i < min(a.size(), b.size()); ++i) {
            if (a[i] != b[i]) {
                return alphabet.find(a[i]) < alphabet.find(b[i]);
            }
        }
        return a.size() < b.size();
    };

    sort(months.begin(),months.end(),compare);
    cout << "Furcsa abece szerint rendezett honapok: ";
    for(auto month : months)
    {
        cout << month <<" ";
    }
    return 0;
}


bool containsApple(string &fruit) {
    return (fruit.find("apple") != string::npos);
}

bool isBanana(const string &fruit) {
    return fruit == "banana";
}

void doubleElements(int &num) {
    num *= 2;
}

