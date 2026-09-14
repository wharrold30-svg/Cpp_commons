#include<ctime>
#include<type_traits>
#include<utility>
#include<iostream>
#include<chrono>
#include"Date.h"


int main(){
    auto displayResult = [](const bool r){
        std::cout << (r ? "passed" : "failed") << "\n\n";
    };
    std::cout << "Testing Date constructors:\n";
    bool result = true;
    try{
        std::cout << "default constructor test: ";
        DT::Date d;
    }catch(const DT::DateError& err){
        std::cout << "\n" << std::format("Error: {}", err.what()) <<"\n";
        result = false;
    }
    displayResult(result);

    result = true;
     try{
        std::cout << "d2 constructor";
      /*  std::time_t currentTime = std::time(nullptr);
        std::tm* t = std::localtime(&currentTime);
        std::string tStr;
        const int len = 32;
        tStr.resize(len);
        const int newLenstd::strftime(&tStr[0], len, "%F %T", t);
        tStr.resize(newLen);*/
        std::string tStr = "1853-01-21 12:22:30";
        std::cout << "\ndate string: " << tStr << "\n";
        DT::Date d2(tStr);
    }catch(const DT::DateError& err){
    std::cout << "\n" << err.what() <<"\n";
    result = false;
    }

    displayResult(result);

    result = true;
    try{
        std::cout << "d3 constructor ";

        std::time_t currentTime = std::time(nullptr);
    std::tm myTm = *std::localtime(&currentTime);
    DT::Date d3(myTm);
}catch(const DT::DateError& err){
    std::cout << "\n" << std::format("Error: {}", err.what()) <<"\n";
    result = false;
    }

    displayResult(result);
    std::puts("///////////////////////");
    std::cout << "copy, assign, move(deleted), and move assign(deleted) tests: ";

    result =true;
    try{
        std::time_t currentTime = std::time(nullptr);
    std::tm myTm = *std::localtime(&currentTime);
    DT::Date d4(myTm);
    DT::Date d5(d4);
    DT::Date d6;
    d6 = d5;

    }catch(...){
        result = false;
    }
// Compile-time tests ensuring the move operations are NOT available
    static_assert(!std::is_move_constructible_v<DT::Date>, 
                  "Error: DT::Date should NOT be move constructible!");
                  
    static_assert(!std::is_move_assignable_v<DT::Date>, 
                  "Error: DT::Date should NOT be move assignable!");

   displayResult(result); 


    std::puts("///////////////////////");

    std::puts("getStr and getDBStr tests: ");

        std::time_t currentTime = std::time(nullptr);
    std::tm myTm = *std::localtime(&currentTime);
    DT::Date d9(myTm);

   std::cout << d9.getStr() << "\n" << d9.getDBStr() << "\n";
   std::puts("passed");
}

