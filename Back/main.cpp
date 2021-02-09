//
//  main.cpp
//  Touchkovka
//
//  Created by Илья Колбеко on 9/28/20.
//

#include <iostream>
//#include <thread>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

//std::string nameSortiment = "4.8_21-25.txt";
//float cubage[5] = {0.202, 0.220, 0.240, 0.260, 0.285};



std::string nameSortiment = "6.0_26-34_2cm.txt";
float cubage[5] = {0.390, 0.450, 0.520, 0.590, 0.660};

// std::string nameSortiment = "6.0_16-24_2cm.txt";
// float cubage[5] = {0.155, 0.194, 0.230, 0.280, 0.330};

//std::string nameSortiment = "4.8_26-34_2cm.txt";
//float cubage[5] = {0.310, 0.350, 0.410, 0.460, 0.520};

//std::string nameSortiment = "4.8_16-24_2cm.txt";
//float cubage[5] = {0.118, 0.150, 0.183, 0.220, 0.260};


//std::string nameSortiment = "3.0_26-34.txt";
//float cubage[5] = {0.185, 0.220, 0.250, 0.280, 0.320};

struct element {
    int firstNum, secondNum, thirdNum, fourNum, fiftNum;
    float firstCub, secondCub, thirdCub, fourCub, fifthCub;
    float allSum;
};

std::vector<element> Base;
std::vector<element> cleanBase;

int stayNumber = 40;
int voidNuber = 0;

int main(int argc, const char * argv[]) {
    
    // Generation
    std::ofstream write;
    write.open(nameSortiment, std::ofstream::trunc);
    
    for (int i = 0; i < stayNumber; ++i)
        for (int j = 0; j < stayNumber; ++j)
            for (int x = 0; x < stayNumber; ++x)
                for (int a = 0; a < stayNumber; ++a)
                    for (int k = 0; k < stayNumber; ++k) {
                        
                            write << "\t" << k << " " << a << " " << x << " " << j << " " << i << " " << k * cubage[0] << " " << a * cubage[1] << " " << x * cubage[2] << " " << j * cubage[3] << " " << i * cubage[4] << " " << (k * cubage[0]) + (a * cubage[1]) + (x * cubage[2]) + (j * cubage[3]) + (i * cubage[4]) << "\n";

                        //std::cout << voidNuber << "   " << i << "\n"; // << j << " " << x << " " << a << " " << k << "\n";
                        voidNuber++;
        }
    write.close();
    
    // Read
    system("clear");
    std::cout << "Read...\n";
    element temp;
    std::ifstream  read;
    read.open(nameSortiment);
    while (!read.eof()) {
        while (read >> temp.firstNum >> temp.secondNum >> temp.thirdNum >> temp.fourNum >> temp.fiftNum >> temp.firstCub >> temp.secondCub >> temp.thirdCub >> temp.fourCub >> temp.fifthCub >> temp.allSum) {
            Base.push_back(temp);
        }
    }
    
    
    // Sorting
    system("clear");
    std::cout << "Sorting...\n";
    std::sort(Base.begin(), Base.end(), [](const element& a, const element& b) -> bool {
        return a.allSum < b.allSum;
    });
    
    
    // Write
    system("clear");
    std::cout << "\nWrite...\n";
    remove("3.2_16-24.txt");
    std::ofstream writeTwo;
    writeTwo.open(nameSortiment, std::ofstream::trunc);
    
    float t = 0;
    for (int i = 0; i < Base.size(); i++) {
        
        if (t == Base[i].allSum) {
        	system("clear");
            std::cout << "Delete.." << "\n"; // << t << "\n";
        }else {
            writeTwo << Base[i].firstNum << " " << Base[i].secondNum << " " <<  Base[i].thirdNum << " " <<  Base[i].fourNum << " " <<  Base[i].fiftNum << " " << Base[i].firstCub << " " << Base[i].secondCub << " " << Base[i].thirdCub << " " << Base[i].fourCub << " "<< Base[i].fifthCub << " " << Base[i].allSum << "\n";
            std::cout << Base[i].allSum << "\n";
            t = Base[i].allSum;
        }
    }
    writeTwo.close();
    
    
//    // Read
//    system("clear");
//    std::cout << "Read.2..\n";
//    element temp2;
//    float f = 0;
//    std::ifstream  read2;
//    read2.open(nameSortiment);
//    while (!read2.eof()) {
//        while (read2 >> temp2.firstNum >> temp2.secondNum >> temp2.thirdNum >> temp2.fourNum >> temp2.fiftNum >> temp2.firstCub >> temp2.secondCub >> temp2.thirdCub >> temp2.fourCub >> temp2.fifthCub >> temp2.allSum) {
//            if (f == temp2.allSum) {
//                std::cout << "Delete...." << f << "\n";
//            }else {
//                cleanBase.push_back(temp2);
//                f = temp2.allSum;
//            }
//        }
//    }
//
//    // Write
//    system("clear");
//    std::cout << "\nWrite...\n";
//    remove("3.2_16-24.txt");
//    std::ofstream writeFinish;
//    writeFinish.open(nameSortiment, std::ofstream::trunc);
//    for (int i = 0; i < cleanBase.size(); i++) {
//        writeFinish << cleanBase[i].firstNum << " " << cleanBase[i].secondNum << " " <<  cleanBase[i].thirdNum << " " <<  cleanBase[i].fourNum << " " <<  cleanBase[i].fiftNum << " " << cleanBase[i].firstCub << " " << cleanBase[i].secondCub << " " << cleanBase[i].thirdCub << " " << cleanBase[i].fourCub << " "<< cleanBase[i].fifthCub << " " << cleanBase[i].allSum << "\n";
//    }
//    writeFinish.close();
    
    system("clear");
    std::cout << "Finish!";
    
    return 0;
}

