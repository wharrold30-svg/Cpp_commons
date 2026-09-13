//This class handles the date and time

#ifndef DATE_H  //header guard
#define DATE_H

#include<compare>
#include<iostream>
#include<string>
#include<string_view>
#include<stdexcept>
#include<ctime>
#include"nlohmann/json.hpp"


namespace nlohmann{
    template<>
    struct adl_serializer<std::tm>{
        static void to_json(json& j, const std::tm& time){
            j["month"] = time.tm_mon;
            j["day"] = time.tm_mday;
            j["year"] = time.tm_year;
            j["hour"] = time.tm_hour;
            j["min"] = time.tm_min;
            j["sec"] = time.tm_sec;
            j["isdst"] = time.tm_isdst;
        }

        static void from_json(const json& j, std::tm& time){
            time.tm_mon = j["month"].get<int>( );
            time.tm_mday = j["day"].get<int>( );
            time.tm_year = j["year"].get<int>( );
            time.tm_hour = j["hour"].get<int>( );
            time.tm_min = j["min"].get<int>( );
            time.tm_sec = j["sec"].get<int>( );
            time.tm_isdst = j["isdst"].get<int>( );
            std::mktime(&time);
        }
    };//adl_serializer
}//nlohmann
 

class Date{
private:
    std::tm m_date;
    bool m_isLT{false};
    bool validateDateTime(std::string_view str) const;

public:
    Date();
    explicit Date(const std::tm& date);
    explicit Date(std::string_view date);

    Date(const Date& otherDate);
    Date& operator=(const Date& rhs);
    Date(const Date&& otherDate) noexcept;
    Date& operator=(const Date&& rhs) noexcept;

    ~Date() = default;

    //Member swap() used to implement ninmember swap()
    void swap(Date& otherDate) noexcept;

    //getters
    inline std::tm getTM() const{
        return m_date;
    }
    std::string getStr() const;
    std::string getDBStr()const;
    explicit operator std::string() const;
    bool empty() const;
    inline bool isLT()const {
        return m_isLT;
    }



};//Date

void swap(Date& one, Date& other) noexcept;


#endif //header guard
