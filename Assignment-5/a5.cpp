    #include <iostream>
    #include <functional>
    #include <vector>
    #include <set>
    #include <numeric>
    #include <ctype.h>
    #include <sstream>
    #include <map>
    using  namespace std;

    class a5{

    public:

        int random(int min, int max){

            if(max<min){
                swap(min,max);
            }
            int randomNumber =min + (rand()% (int)(max-min+1)) ;
            return randomNumber;
        }
    };

    class Random{

    public:
        int operator()(int min,int max){
            if(max<min){
                swap(min,max);
            }

            int randomNumber =min + (rand()% (int)(max-min+1)) ;
            return randomNumber;
        }
    };

    int random(int min, int max){

        if(max<min){
            swap(min,max);
        }
        int randomNumber =min + (rand()% (int)(max-min+1)) ;
        return randomNumber;
    }

    template <class Iterator>
    pair<Iterator,bool> secondMax(Iterator start, Iterator finish){


        auto highest=start;
        auto secondHighest=start;
        for(auto it=start; it!=finish; ++it){
            if(*it>*highest){
                secondHighest=highest;
                highest=it;
            }
        }
        if(start == finish){
            return make_pair(finish,false);
        }
        else if(secondHighest==start){
            return make_pair(highest,false);
        }
        else
            return make_pair(secondHighest, true);

    };

    template <class Container>
    void print(const Container &c, const string &message = " "){
        if(!message.empty())cout<<message<<" : ";
        using valType = typename Container::value_type;
        ostream_iterator<valType> osItr(cout," ");
        copy(c.begin(),c.end(),osItr);
        cout<<endl;
    }



    bool isPalindrome(const string &phrase) {


        string temp;

        auto it = temp.begin();

        auto space = [](char ch)->bool{return isspace(ch);};
        auto lower = [](char ch)->char{ std::locale loc; return std::tolower(ch);};

        remove_copy_if(phrase.begin(), phrase.end(), inserter(temp, it), space);

        transform(temp.begin(), temp.end(), temp.begin(), lower);
        int tempMid = temp.length()/2;

        return equal(temp.begin(),temp.begin()+temp.size()/2,temp.rbegin());

    }

    void wordIndex() {
        std::map<string, vector<int>> wordIndexMap;
        std::string word;
        string strLine;
        int lineCount = 1;
        cout<<"Enter input to be indexed"<<endl;
        while (getline(std::cin, strLine)) {
            if (strLine.size() == 0) {
                break;
            }
            std::istringstream lineStream(strLine);
            while (lineStream >> word) {
                wordIndexMap[word].push_back(lineCount);
            }
            ++lineCount;
        }

        for (auto it = wordIndexMap.begin(); it != wordIndexMap.end(); ++it) {
            std::cout << it->first << ":";
            for (int i: it->second) {
                std::cout << " " << i;
            }
            std::cout << endl;
        }
    }
    int main() {

        srand(53);

        //Solution to 1
        a5 obj;
        int c = obj.random(51,100);
        cout<<"Solution to 1 : "<<c<<endl;

        //Solution to 2
        Random randomObj;
        cout<<"Solution to 2 : "<<randomObj(1,49)<<endl;


        //Solution to 3
        auto randomLambda = [](int min, int max)->int { if(max<min)swap(min,max);int randomNumber =min + (rand()% (int)(max-min+1));return randomNumber;};
        cout<<"Solution to 3 : "<< randomLambda(1,49)<<endl;

        //Solution to 4
        auto random_1_5 = std::bind(randomLambda,1,5);
        vector<int> va(10);
        cout<<"Solution to 4 : ";
        generate_n(va.begin(),10,random_1_5);
        for (auto i = va.begin(); i != va.end(); ++i) {
            cout<<" "<< *i;

        }
        cout<<endl;

        //Solution to 5
        vector<int> vb(0);
        copy(va.begin(),va.end(), back_inserter(vb));
        cout<<"Solution to 5 : ";
        for (auto i = vb.begin(); i != vb.end(); ++i) {
            cout<<" "<<*i;
        }
        cout<<endl;

        //Solution to 6
        auto it = vb.begin();
        copy(va.begin(),va.end(),inserter(vb,it));
        cout<<"Solution to 6 : ";
        for (auto i = vb.begin(); i != vb.end(); ++i) {
            cout<<" "<<*i;
        }
        cout<<endl;

        //Solution to 7
        set<int> sa(vb.begin(),vb.end());
        cout<<"Solution to 7 : ";
        for (auto i = sa.begin(); i != sa.end(); ++i) {
            cout<<" "<<*i;
        }
        cout<<endl;

        //Solution to 8
        cout<<"Solution to 8 : ";
        set<int, std::greater<int>> sb(vb.begin(),vb.end());
        for (auto i = sb.begin(); i != sb.end(); ++i) {
            cout<<" "<<*i;
        }
        cout<<endl;

        //Solution to 9
        multiset<int> msa(vb.begin(),vb.end());
        cout<<"Solution to 9 : ";
        for (auto i = msa.begin(); i != msa.end(); ++i) {
            cout<<" "<<*i;
        }
        cout<<endl;


        //Solution to 10
        multiset<int, std::greater<int>> msb(vb.begin(),vb.end());
        cout<<"Solution to 10 : ";
        for (auto i = msb.begin(); i != msb.end(); ++i) {
            cout<<" "<<*i;
        }
        cout<<endl;

        //Solution to 11
        auto multiplyBy10 = [](int element)->int {return element*10;};
        multiset<int> msc;
        auto multiSetIterator = msc.begin();
        transform(msa.begin(),msa.end(),inserter(msc,multiSetIterator),multiplyBy10);
        cout<<"Solution to 11 : ";
        for (auto i = msc.begin(); i != msc.end(); ++i) {
            cout<<" "<<*i;
        }
        cout<<endl;


        //Solution to 12
        cout<<"Solution to 12 : "<<endl;
        pair<multiset<int>::iterator,multiset<int>::iterator> bound10;
        bound10 = std::equal_range(msc.begin(),msc.end(),10);
        int d10 = std::distance(get<0>(bound10),get<1>(bound10));
        cout<<"Duplicate of 10 in the multiset is "<<d10<<endl;

        pair<multiset<int>::iterator,multiset<int>::iterator> bound20;
        bound20 = std::equal_range(msc.begin(),msc.end(),20);
        int d20 = std::distance(get<0>(bound20),get<1>(bound20));
        cout<<"Duplicate of 10 in the multiset is "<<d20<<endl;

        pair<multiset<int>::iterator,multiset<int>::iterator> bound40;
        bound40 = std::equal_range(msc.begin(),msc.end(),40);
        int d40 = std::distance(get<0>(bound40),get<1>(bound40));
        cout<<"Duplicate of 10 in the multiset is "<<d40<<endl;

        pair<multiset<int>::iterator,multiset<int>::iterator> bound50;
        bound50 = std::equal_range(msc.begin(),msc.end(),50);
        int d50 = std::distance(get<0>(bound50),get<1>(bound50));
        cout<<"Duplicate of 10 in the multiset is "<<d50<<endl;

        //Solution to 13
        int accumulationResult=0;
        multiset<int>::iterator low, high;
        low= lower_bound(msc.begin(),msc.end(),15);
        high= upper_bound(msc.begin(),msc.end(),35);
        accumulationResult = accumulate(low,high,accumulationResult);
        cout<<"Solution to 13 : Accumulation result : "<<accumulationResult<<endl;

        //Solution to 14

        auto isEven = [](int element)->bool{return (element%2)==0;};
        int countOfEven = count_if(vb.begin(),vb.end(),isEven);
        cout<<"Solution to 14 : Count of even number is "<<countOfEven<<endl;

        //Solution to 15
        cout<<"Solution to 15 : ";
        vector<int> int_vec{1,1,5,5,7,7};
        print(int_vec,"int_vec");

        auto retval = secondMax<vector<int>::iterator>(int_vec.begin(),int_vec.end());
        cout<<"Second Maximum is : "<<*retval.first<<endl;

        if(retval.second){
            cout<<"The second largest element in int_vec is "<< *retval.first<<endl;
        }
        else{
            if(retval.first == int_vec.end()){
                cout<<"List empty, no elements \n ";
            }
            else
                cout<<"Container elements are all equal to "<<*retval.first<<endl;
        }

        //Solution to 16
        string str_cat = string("Was it a car or a cat I saw");
        string str_kat =string("Was it a car or a kat I saw");
        bool is_str_cat = isPalindrome(str_cat);
        bool is_str_kat = isPalindrome(str_kat);
        cout<<"Solution to 16 : "<<endl;
        cout<< "the phrase \""+str_cat+"\" is "+(is_str_cat?"":" not ")+" a palindrome \n";
        cout<<"the phrase \""+str_kat+"\" is "+(is_str_kat?"":" not ")+ " a palindrome \n";

        //Solution to 17
        cout<<"Solution to 17 : "<<endl<<endl;
        wordIndex();

        return 0;
    }