#include <vector>
#include <algorithm>

using namespace std;

struct Image {
    double quality;
    double freshness;
    double rating;
};

struct Params {
    double a;
    double b;
    double c;
};


class FunctionPart {
public:
    FunctionPart(const char &o, const double &v) {
        operation = o;
        value = v;
    }

    bool IsAdditive(){
        return (operation == '+' || operation == '-');
    }

    double GetCalculation(const double& previous) const{
        if (operation == '+') {
            return value;
        }

        if(operation == '-') {
            return -value;
        }

        if(operation == '*'){
            return previous * value;
        }

        return previous / value;
    }

    double GetCalculationReverted(const double& previous) const{
        if (operation == '+') {
            return -value;
        }
        if(operation == '-') {
            return value;
        }

        if(operation == '*'){
            return previous / value;
        }

        return previous * value;
    }

private:
    char operation;
    double value;
};


class Function {
public:
    void AddPart(const char &o, const double &v) {
        operations.push_back({o, v});
    };

    double Apply(double value) const {

        double result = value;
        for (auto op: operations) {
            if(op.IsAdditive()){
                result += op.GetCalculation(value);
            }else {
                result = op.GetCalculation(result);
            }
        }

        return result;
    }

    double ApplyReverted(double value) const {

        auto reverted_operations = operations;
        reverse(begin(reverted_operations), end(reverted_operations));

        double result = value;
        for (auto op: reverted_operations) {
            if(op.IsAdditive()){
                result += op.GetCalculationReverted(result);
            }else {
                result = op.GetCalculationReverted(result);
            }
        }

        return result;
    }

private:
    vector<FunctionPart> operations;

};


Function MakeWeightFunction(const Params &params,
                            const Image &image) {
    Function function;
    function.AddPart('*', params.a);
    function.AddPart('-', image.freshness * params.b);
    function.AddPart('+', image.rating * params.c);
    return function;
}

double ComputeImageWeight(const Params &params, const Image &image) {
    Function function = MakeWeightFunction(params, image);
    return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params &params,
                              const Image &image,
                              double weight) {
    Function function = MakeWeightFunction(params, image);
    return function.ApplyReverted(weight);
}