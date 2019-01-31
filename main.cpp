#include <string>
#include <set>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <chrono>
#include "resources/SortedStrings.h"
//#include "resources/library_1.h"
#include "resources/Person.h"
#include "resources/ReversibleString.h"
#include "resources/ImageWeighted.h"
#include "resources/FileStreamEx.h"
#include "resources/OverloadOperator.h"
#include "resources/AvgTemperature2.h"
#include "resources/BlockMass.h"


using namespace std;


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
/*    quadratic_equation(2, 5, 2);
    quadratic_equation(2, 4, 2);
    quadratic_equation(2, 1, 2);
    quadratic_equation(0, 4, 10);*/
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
    // 7
    // -10 -8.92 4 11.3434 12.34 2.0001 .5967
//    RunAvgTemperature2();

    // 4 11
    // 1 2 3
    // 1 2 6
    // 2 4 8
    // 16 12 12
    RunMassCalculator();
    return 0;
}




