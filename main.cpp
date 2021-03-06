// CheckDigit Calc
// Coding by S.H.
// Date November 3th, 2017
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cmath>

constexpr int Number = 12;

//番号読み取り関数
//NumberRead
std::vector<std::string> NumberRead(std::vector<std::string> Num){
    
    //カード番号を配列に格納
    for(std::string num; std::getline(std::cin, num); )
        Num.emplace_back(std::move(num));

    return Num;
}

template <typename T, std::size_t N>
std::array<T, N> GetNumber(std::array<T, N> Degit, const std::string Num){
    //番号を一桁ずつ格納
    for(int i = 0; i < Number; i++)
        Degit[i] = static_cast<int>(Num[i]) - 48;

    return Degit;
}

template <typename T, std::size_t N>
auto CalcDegit(const std::array<T, N> Degit){

    //チェックデジット計算変数
    int temp = 0;

    //桁数分、チェックデジット用の計算を行う
    for(int j = 0; j < Number; j++){
        if((j + 1) % 2 == 0){
            if((Degit[j] * 2) > 9)
                temp += (((Degit[j] * 2) % 10) + 1);
            else
                temp += (Degit[j] * 2);         
        } else
            temp += Degit[j];
    }

    return temp;
}

template <typename T, std::size_t N>
void NumberDraw(std::array<T, N> Degit, std::string Num){

    Degit = GetNumber(Degit, Num);

    int t = (10 - (CalcDegit(Degit) % 10));
    //番号とチェックデジットを表示
    std::cout << Num << ((t == 10)? 0 : t) << std::endl;
}

//チェックデジット書き込み関数
//NumberWrite
void NumberWrite(const std::vector<std::string> Num){

    //格納されている番号分だけループ
    for(auto&& d : Num){

        //番号を一時的に格納する変数
        std::array<int, Number> Degit;

        NumberDraw(Degit, d);
    }
}

int main(){

    //番号格納配列
    std::vector<std::string> Num;
    
    //番号データ読み取り
    Num = NumberRead(Num);

    //チェックデジットを計算し表示
    NumberWrite(Num);

    return 0;
}