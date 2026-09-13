//Date implementation



#include<regex>
#include<utilitu>
#include<sstream>


void Date::swap(Date& otherDate) noexcept {
    std::swap(m_date.tm_mon, otherDate.m_date.tm_mon);
    std::swap(m_date.tm_mday, otherDate.m_date.tm_mday);
    std::swap(m_date.tm_year, otherDate.m_date.tm_year);
    std::swap(m_date.tm_hour, otherDate.m_date.tm_hour);
    std::swap(m_date.tm_min, otherDate.m_date.tm_min);
    std::swap(m_date.tm_sec, otherDate.m_date.tm_sec);
    std::swap(m_date.tm_isdst, otherDate.m_date.tm_isdst);
    std::swap(m_date.tm_isLT, otherDate.m_date.tm_isLT);
}
void swap(Date& one, Date& other){
    one.swap(other);
}
