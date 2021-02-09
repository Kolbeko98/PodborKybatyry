//
//  main.cpp
//  PodborKubatyry
//
//  Created by Илья Колбеко on 10/2/20.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>

std::vector<std::string> PL_15_20 = {"16", "18", "20", "22", "24"};
//std::vector<std::string> PL_21_25 = {"21", "22", "23", "24", "25"};
std::vector<std::string> PL_26_30 = {"26", "28", "30", "32", "34"};
//std::vector<std::string> PL_31_35 = {"31", "32", "33", "34", "35"};

struct element {
    long firstNum, secondNum, thirdNum, fourNum, fiftNum;
    float firstCub, secondCub, thirdCub, fourCub, fifthCub;
    float allSum;
};

// 2.6
// std::vector<element> base_26_1624;
// std::string txt_26_1624 = "2.6_16-24.txt";
// std::vector<element> base_26_2634;
// std::string txt_26_2634 = "2.6_26-34.txt";

// 3.2
// std::vector<element> base_32_1624;
// std::string txt_32_1624 = "3.2_16-24.txt";
// std::vector<std::string> FB_16_24 = {"16", "18", "20", "22", "24"};

// std::vector<element> base_32_2634;
// std::string txt_32_2634 = "3.2_26-34.txt";
// std::vector<std::string> FB_26_34 = {"26", "28", "30", "32", "34"};

//// 4.0
//std::vector<element> base_40_1424;
//std::string txt_40_1424 = "4.0_14-24.txt";
//std::vector<std::string> PL_14_24 = {"14", "16", "18", "20", "24"};

// 4.8
std::vector<element> base_48_1624;
std::string txt_48_1624 = "4.8_16-24_2cm.txt";
std::vector<element> base_48_2634;
std::string txt_48_2634 = "4.8_26-34_2cm.txt";


// 6.0
std::vector<element> base_60_1624;
std::string txt_60_1624 = "6.0_16-24_2cm.txt";
std::vector<element> base_60_2634;
std::string txt_60_2634 = "6.0_26-34_2cm.txt";


int choise = 1;
float input = 0;

// Read
std::vector<element> read (std::string file){
        std::cout << "Read...\n";
        system("clear");
        element temp;
        std::vector<element> tempBase;
        std::ifstream  read;
        read.open(file);
        while (!read.eof()) {
            while (read >> temp.firstNum >> temp.secondNum >> temp.thirdNum >> temp.fourNum >> temp.fiftNum >> temp.firstCub >> temp.secondCub >> temp.thirdCub >> temp.fourCub >> temp.fifthCub >> temp.allSum) {
                tempBase.push_back(temp);
            }
        }
    read.close();
    return tempBase;
}

//Output
void outRes (std::vector<element> Base, std::vector<std::string> diametr, std::string name){
    system("clear");
    element empty;
    empty.allSum = 0;
    empty.firstNum = 0;
    empty.secondNum = 0;
    empty.thirdNum = 0;
    empty.fourNum = 0;
    empty.fiftNum = 0;
    empty.firstCub = 0;
    empty.secondCub = 0;
    empty.thirdCub = 0;
    empty.fourCub = 0;
    empty.fifthCub = 0;
    double gfx = Base[Base.size() - 1].allSum;
    std::cout << "Вы выбрали: " << name << "\n" << "Введите кубатуру: ";
    std::cin >> input;
    
if (input > empty.allSum + gfx){
        for (int a = 0; a < 80; a++) {
                empty.firstNum += Base[Base.size() -1].firstNum;
                empty.secondNum += Base[Base.size()-1].secondNum;
                empty.thirdNum += Base[Base.size()-1].thirdNum;
                empty.fourNum += Base[Base.size()-1].fourNum;
                empty.fiftNum += Base[Base.size()-1].fiftNum;
                
                empty.firstCub += Base[Base.size()-1].firstCub;
                empty.secondCub += Base[Base.size()-1].secondCub;
                empty.thirdCub += Base[Base.size()-1].thirdCub;
                empty.fourCub += Base[Base.size()-1].fourCub;
                empty.fifthCub += Base[Base.size()-1].fifthCub;
                
                empty.allSum = empty.allSum + Base[Base.size()-1].allSum;
                
                //std::cout << empty.allSum << "  " << Base[Base.size() - 1].allSum << "\n";
                //float f = input - empty.allSum;
                //std::cout << f << "   " << a <<"\n";
            if (input < empty.allSum + gfx) {
                break;
            }
            }
    }  if (input <= empty.allSum + gfx) {
                
                for (int i = 0; i < Base.size(); i++) {
                    //std::cout << "Есть: " << empty.allSum << " Еще нужно: " << input - empty.allSum << "\n";
                    
                    float d = Base[i].allSum + empty.allSum;
                    //input = floor(input * 1000) / 1000;
                    //std::cout << d  << "   Подобрано:  " << Base[i].allSum  <<"\n";
                    
                    //if (std::fabs(d - input) < std::numeric_limits<float>::epsilon()) {
                        if (abs(d - input) < 0.0001 ) {
                        
                        empty.firstNum += Base[i].firstNum;
                        empty.secondNum += Base[i].secondNum;
                        empty.thirdNum += Base[i].thirdNum;
                        empty.fourNum += Base[i].fourNum;
                        empty.fiftNum += Base[i].fiftNum;
                        
                        empty.firstCub += Base[i].firstCub;
                        empty.secondCub += Base[i].secondCub;
                        empty.thirdCub += Base[i].thirdCub;
                        empty.fourCub += Base[i].fourCub;
                        empty.fifthCub += Base[i].fifthCub;
                        empty.allSum += Base[i].allSum;
                        
                        long all = empty.firstNum + empty.secondNum + empty.thirdNum + empty.fourNum + empty.fiftNum;
                            
                        //system("clear");
                        std::cout << "\n" << diametr[0] << "  -  " << empty.firstNum << "  -  " << empty.firstCub << "\n\n";
                        std::cout << diametr[1] << "  -  " << empty.secondNum << "  -  " << empty.secondCub << "\n\n";
                        std::cout << diametr[2] << "  -  " << empty.thirdNum<< "  -  " << empty.thirdCub << "\n\n";
                        std::cout << diametr[3] << "  -  " << empty.fourNum<< "  -  " << empty.fourCub << "\n\n";
                        std::cout << diametr[4] << "  -  " << empty.fiftNum << "  -  " << empty.fifthCub << "\n\n";
                        
                        std::cout << "-------------------\n";
                        std::cout << "Всего: " << all << "  -  " << empty.allSum << "\n";
                        break;
                    }else {
                        if (i == Base.size()) {
                            std::cout << "Not result\n";
                            break;
                        }
                        //std::cout << "Read\n";
                    }
                }
    }
    system("read");
    system("clear");
}

int main(int argc, const char * argv[]) {
    
    // base_26_1624 = read(txt_26_1624);
    // base_26_2634 = read(txt_26_2634);
    // base_32_1624 = read(txt_32_1624);
    // base_32_2634 = read(txt_32_2634);
    base_48_1624 = read(txt_48_1624);
    base_48_2634 = read(txt_48_2634);
    base_60_1624 = read(txt_60_1624);
    base_60_2634 = read(txt_60_2634);
    
    while (choise != 0) {
        system("clear");
        std::cout << "Подбор кубатуры - ";
        std::cout << "Диаметр через 2 см\nВыберите сортимент:\n\n";
        // std::cout << "1  - 3.2 (16-24)\n";
        // std::cout << "2  - 3.2 (26-34)\n";
        // std::cout << "==================\n";
        std::cout << "3  - 4.8 (16-24)\n";
        std::cout << "4  - 4.8 (26 и более)\n";
        std::cout << "==================\n";
        std::cout << "5  - 6.0 (16-24)\n";
        std::cout << "6  - 6.0 (26 и более)\n";
        // std::cout << "==================\n\n";
        // std::cout << "7  - 2.6 (16-24)\n";
        // std::cout << "8  - 2.6 (26-34)\n";
       // std::cout << "9  - 3.0 (14-24)\n";
       // std::cout << "10 - 3.0 (26-34)\n";
       // std::cout << "11 - 4.0 (14-24)\n";
       // std::cout << "12 - 5.4 (31-35)\n";
        
        std::cout << "0 - Выход\n\n";
        std::cin >> choise;
        
        switch (choise) {
            // case 1:
            //     outRes(base_32_1624, FB_16_24, "3.2 (16-24)");
            //     break;
            // case 2:
            //     outRes(base_32_2634, FB_26_34, "3.2 (26-34)");
            //     break;
            case 3:
                outRes(base_48_1624, PL_15_20, "4.8 (16-24)");
                break;
            case 4:
                outRes(base_48_2634, PL_26_30, "4.8 (26-34)");
                break;
            case 5:
                outRes(base_60_1624, PL_15_20, "6.0 (16-24)");
                break;
            case 6:
                outRes(base_60_2634, PL_26_30, "6.0 (26-34)");
                break;
            // case 7:
            //     outRes(base_26_1624, FB_16_24, "2.6 (16-24)");
            //     break;
            // case 8:
            //     outRes(base_26_2634, FB_26_34, "2.6 (26-34)");
            //     break;
            default:
                break;
        }
    }
    return 0;
}
