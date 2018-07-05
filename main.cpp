// CheckDigit Calc
// Coding by S.H.
// Date November 3th, 2017
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

//番号格納配列
std::vector<std::string> Num;

//番号読み取り関数
//NumberRead
void NumberRead(){
    
    //カード番号を配列に格納
    for(std::string num; std::getline(std::cin, num); )
        Num.emplace_back(std::move(num));
}

//チェックデジット書き込み関数
//NumberWrite
void NumberWrite(){

    //格納されている番号分だけループ
    for(auto&& d : Num){

        //番号を一時的に格納する変数
        int digit[12];

        //チェックデジット計算変数
        int temp = 0;

        //番号を一桁ずつ格納
        for(int i = 0; i < 12; i++)
            digit[i] = static_cast<int>(d[i]) - 48;

        //桁数分、チェックデジット用の計算を行う
        for(int j = 0; j < 12; j++){
            if((j + 1) % 2 == 0){
                if((digit[j] * 2) > 9)
                    temp += (((digit[j] * 2) % 10) + 1);
                else
                    temp += (digit[j] * 2);         
            } else
                temp += digit[j];
        }
        int t = (10 - (temp % 10));
        //番号とチェックデジットを表示
        std::cout << d << ((t == 10)? 0 : t) << std::endl;
    }
}

int main(){
    
    //番号データ読み取り
    NumberRead();

    //チェックデジットを計算し表示
    NumberWrite();

    return 0;
}