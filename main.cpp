#include <string>
//#include <set>
#include <iostream>
#include <vector>
//#include <map>
#include <algorithm>
//#include <cmath>
//#include <chrono>
//#include <tuple>
//#include "resources/SortedStrings.h"
//#include "resources/library_1.h"
//#include "resources/Person.h"
//#include "resources/ReversibleString.h"
//#include "resources/ImageWeighted.h"
//#include "resources/FileStreamEx.h"
//#include "resources/OverloadOperator.h"
//#include "resources/AvgTemperature2.h"
//#include "resources/BlockMass.h"
//#include "resources/FunctionsTemplateTask.h"
//#include "resources/UnitTest.h"
//#include "resources/UsingIterators_test.h"
#include "resources/StringSplit_test.h"
#include "resources/Benchmark.h"


using namespace std;

/*

void PrintSortedStrings(SortedStrings &strings) {
    for (const string &s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

void UseSortedStrings() {
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);
}

//int main() {
//    int a = internal_types();
//    how_structs_work();
//    iterate_containers();
//    cin_cout();
//    cond_cycles();
//    lexic_less();
*/
/*    quadratic_equation(2, 5, 2);
    quadratic_equation(2, 4, 2);
    quadratic_equation(2, 1, 2);
    quadratic_equation(0, 4, 10);*//*

//    iterate_map();
//    for_i();
//    test_division();
//    test_calc_price();
//    test_even();
//    test_charpos2();
//    test_biggest_common_div();
//    test_dec2bin();
//    test_Factorial();
//    test_IsPalindrom();
//    test_Swap();
//    howToBehchmark();
//    ConstReference();
//    benchmark_UpdateIfGreater();
//    test_MoveStrings();
//    test_Reverse();
//    benchmark_Reverse();
//    vector_for_reference();
//    more_vector_functions();
//    test_AboveMeanTemperature();
//    WorryQueue();
//    test_IsAnagram();
//    BusStops();
//    SetsUsage();
//    CountUniqueStrings();
//    Synonyms();
//    CountIfLambda();
//    ModForCycle();
//    SortByModuleAsc();
//    SortByLexicRegisterIndependent();
//    EstimateLength("five");
//    UseLecture();
//    return 0;
//}

void UsePersonClass() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

}

void UsePersonClassHistory() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

}

void UseReversableString() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString &s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;
}

void UseImageWeighted() {
    Image image = {10, 2, 6};
    Params params = {4, 2, 6};
    cout << ComputeImageWeight(params, image) << endl;
    cout << ComputeQualityByWeight(params, image, 52) << endl;
//    cout << ComputeQualityByWeight(params, image, 52) << endl;
}

void UseFileStream() {
    FileReaderCsv filestream = FileReaderCsv("input.csv");
    cout << filestream.GetDashed() << endl;
    filestream.CoutGlued();
}

void USeWriteToFstream() {
    FileWriterCsv filestream = FileWriterCsv("output.csv");

    vector<string> line1 = {"1", "KBP", "Kyiv Boryspil",};
    vector<string> line2 = {"2", "NCE", "Nice",};

    filestream.AddAsCsvLine(line1);
    filestream.AddAsCsvLine(line2);
}

void UseWriteToTable() {
    vector<string> columns = {"A1", "X1", "Y2"};
    FileWriterTable filestream = FileWriterTable("table.txt", columns);

    vector<double> line1 = {.01, 12, 16};
    vector<double> line2 = {.0012, 7, 49};

    filestream.AddTr(line1);
    filestream.AddTr(line2);
}

void UseOverloadOperator() {
    stringstream duration_str_stream("1 20 40"); //create stringstream, not to use cin;
    Interval duration;

    duration_str_stream >> duration;
    cout << duration << endl;

    Interval interval_a = {2, 40, 40};
    Interval interval_b = {1, 25, 50};

    cout << interval_a << endl;
    cout << interval_b << endl;
    cout << "sum: " << interval_a + interval_b << endl;

    vector<Interval> v = {interval_a, interval_b, interval_a + interval_b};
    cout << "before sort:" << endl;
    for (auto i:v) {
        cout << i << "  ";
    }
    cout << endl;
    cout << "after sort:" << endl;
    sort(v.begin(), v.end());
    for (auto i:v) {
        cout << i << "  ";
    }

    cout << (-1 < 1u) << endl;
}

void HowToUseConstants() {
    const int REQUEST_ADD = 0;
    const int REQUEST_REMOVE = 1;
    const int REQUEST_NEGATE = 2;
    int a = 1;
    if (a == REQUEST_REMOVE) {
        cout << "Remove request" << endl;
    }
}


// --- Enum type
enum class RequestType {
    ADD = 1,
    REMOVE,
    NEGATE,
    OTHER
};

void ProcessRequestType(RequestType type) {

    switch(type){
        case RequestType::ADD:
            cout << "ADD" <<endl;
            break;
        case RequestType::REMOVE:
            cout << "REMOVE" << endl;
            break;
        case RequestType::NEGATE:
            cout << "NEGATE" << endl;
            break;
        default:
            cout << "Unknown <type>: " << static_cast<int>(type) << endl;
            break;
    }

}

void EnumerationExample() {
    RequestType request_type =  static_cast<RequestType>(1);

    ProcessRequestType(request_type);
    ProcessRequestType(RequestType::REMOVE);
    ProcessRequestType(RequestType::OTHER);


}

// ---
*/


/*
void TupleUsage() {

    string my_str = "My string";
    uint8_t my_int = 42;
    bool my_bool = true;

    tuple<string&, uint8_t&, bool&> tuple_a = tie(my_str,my_int,my_bool);

    auto tuple_b = tie(my_str,my_int,my_bool);

    auto tuple_c = make_tuple(.1 , 2, "strings");

    tuple tuple_d("D", pow(2,8), 0);

    cout << get<0>(tuple_c) << endl;
    cout << get<2>(tuple_b) << endl;
    cout << get<0>(tuple_a) << endl;
    cout << get<1>(tuple_d) << endl;
}
*/
/*

void UseFunctionsTemplate() {
    cout << Squared(8) << endl;
    cout << Squared(.8) << endl;
    cout << Squared(1.2) << endl;

    auto pair_1 = make_pair(2, 4);
    auto squared_pair = Squared(pair_1);
    cout << squared_pair.first << ", " << squared_pair.second << endl;

    vector<int> vec = {1, 2, 3, 4};
    vector<string> strings = {"O", "1u", "element"};

    cout << vec << endl;
    cout << strings << endl;

    map<int, string> my_map = {{1, "first"},
                               {2, "second"}};
    cout << my_map << endl;

    cout << MaxOf<double>(4, 5.1) << endl;
    cout << max<double>(4, 5.1) << endl;


}
*/
/*
void UseFunctionTemplateTask() {

    vector<double> vec = {2, 4.2, 5};
    map<string, int> m = {{"one", 3},
                          {"two", 5}};

    pair<int ,int> p = {2, 4};

    map<vector<int>, pair<int, double>> composite = {
            {
                    {2,3,4}, {2, .5}
            },
            {
                {1,2,0}, {4, 1.5}
            }
    };

    cout << vec << endl;
    cout << SquaredContainer(vec) << endl;

    cout << m << endl;
    cout << SquaredContainer(m) << endl;

    cout << p << endl;
    cout << SquaredContainer(p) << endl;


    cout << composite << endl;
    cout << SquaredContainer(composite) << endl;


    map<int, string> map_search = {{0, "value"}};
    string& item = GetRefStrict(map_search, 0);
    item = "newvalue";
    cout << map_search[0] << endl; // выведет newvalue

}*/
/*

void UnitTestInts() {
    AssertEqual(1, 1, "1 == 1");
    AssertEqual(3, 3, "2 == 3");
}

void UnitTestStrings() {
    AssertNotEqual("abc", "absc", "abc string");
    AssertNotEqual("ccc", "ccc", "ccc string");
}

void UnitTestVecs() {
    AssertNotEqual(vector<int>{1,2,3}, vector<int>{1,2,3}, "vector1");
    AssertNotEqual(vector<int>{1,2,4}, vector<int>{1,2,3}, "vector2");
}

void UseUnitTests() {
    TestRunner tr;
    tr.RunTest(UnitTestInts, "Ints");
    tr.RunTest(UnitTestStrings, "Strs");
    tr.RunTest(UnitTestVecs, "Vectors");
}
*/
/*
void UseIteratorForContainer(){
    std::vector<std::string> v = {"a", "b", "c", "d", "e"};
    PrintContainerByIterators(begin(v), end(v));
    cout << endl;

    string st = "My string";
    PrintContainerByIterators(begin(st), end(st));
    cout << endl;

    auto border = find(begin(v), end(v), "c");
    PrintContainerByIterators(begin(v),border);
    cout << endl;
    PrintContainerByIterators(border, end(v));


}*/


void StringSplit_subject(){
    auto split = StringSplit();
    auto actual = split.Split("Founded by Suroosh Alvi, Gavin McInnes and Shane Smith,[3] the magazine was launched in 1994 as the Voice of Montreal with government funding, and the intention of the founders was to provide work and a community service.[4] When the editors later sought to dissolve their commitments with the original publisher Alix Laurent, they bought him out and changed the name to Vice in 1996.[5]\n"
                              "\n"
                              "Richard Szalwinski, a Canadian software millionaire, acquired the magazine and relocated the operation to New York City in the late 1990s. Following the relocation, the magazine quickly developed a reputation for provocative and politically incorrect content. Under Szalwinski's ownership, a few retail stores were opened in New York City and customers could purchase fashion items that were advertised in the magazine. However, due to the end of the dot-com bubble, the three founders eventually regained ownership of the Vice brand, followed by the closure of the stores.[3]\n"
                              "\n"
                              "The British edition of Vice was launched in 2002 and Andy Capper was its first editor. Capper explained in an interview shortly after the UK debut that the publication's remit was to cover \"the things we're meant to be ashamed of\", and articles were published on topics such as bukkake and bodily functions.[6]\n"
                              "\n"
                              "By the end of 2007, 13 foreign editions of Vice magazine were published, the Vice independent record label was functional, and the online video channel VBS.com had 184,000 unique viewers from the U.S. during the month of August. The media company was still based in New York City, but the magazine began featuring articles on topics that were considered more serious, such as armed conflict in Iraq, than previous content. Alvi explained to The New York Times in November 2007: \"The world is much bigger than the Lower East Side and the East Village.\"[3] ", ' ');
}

void StringSplit_benchmark(){
    Benchmark bm;
    bm.DoBenchmark(StringSplit_subject, 100, "StringSplit_benchmark");


}

int main() {

//    UsePersonClassHistory();
//    UseReversableString();
//    UseImageWeighted();
//    UseFileStream();
//    USeWriteToFstream();
//    UseWriteToTable();
//    UseOverloadOperator();
//    HowToUseConstants();
//    EnumerationExample();
//    RunAvgTemperature2();
//    RunMassCalculator();
//    TupleUsage();
//    UseFunctionsTemplate();
//    UseFunctionTemplateTask();
//    UseUnitTests();
//    UsingIterators_test();
//    StringSplit_test();
    StringSplit_benchmark();

    return 0;
}




