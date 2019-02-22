
#include <Database/Date.hpp>

namespace db {

  DATABASE_DLL Date Date::Today = db::Date(1,1,1900);

  DATABASE_DLL std::array<uint16_t,12> Date::m_DaysOfMonth = {31,28,31,30,31,30,31,31,30,31,30,31};

  DATABASE_DLL Date::Date() : m_Day(0), m_Month(0), m_Year(0) {
    
  }
  
  DATABASE_DLL Date::Date(uint16_t day, uint16_t month, uint32_t year) : m_Day(day), m_Month(month), m_Year(year) {
    
  }
  
  DATABASE_DLL Date::~Date() {
    
  }
  
  uint32_t  DATABASE_DLL Date::getFullYearDifference( Date date ) const {
    if(date < (*this)) {
      date.getFullYearDifference( (*this) );
    }
    if( m_Month < date.m_Month) {
      return date.m_Year - m_Year - 1;
    } else if ( m_Month == date.m_Month ) {
      if(m_Month < date.m_Month) {
        return date.m_Year - m_Year - 1;
      }
    }
    return date.m_Year - m_Year;
  }

  
  uint16_t DATABASE_DLL Date::getDaysOfMonth( uint16_t month ) {
    return (month < 2) ? Date::m_DaysOfMonth[12-month] : Date::m_DaysOfMonth[month-1];
  }
  
  bool DATABASE_DLL Date::isLeapYear( uint32_t year ) {
    return false;
  }

  bool DATABASE_DLL Date::operator > (const Date& date) const {
    if( m_Year > date.m_Year) {
      return true;
    } else if( m_Year == date.m_Year) {
      if(m_Month > date.m_Month) {
        return true;
      } else if( m_Month == date.m_Month) {
        return (m_Day > date.m_Day);
      }
    }
    return false;
  }
  
  bool DATABASE_DLL Date::operator >= (const Date& date) const {
    if( m_Year > date.m_Year) {
      return true;
    } else if( m_Year == date.m_Year) {
      if(m_Month > date.m_Month) {
        return true;
      } else if( m_Month == date.m_Month) {
        return (m_Day >= date.m_Day);
      }
    }
    return false;
  }
  
  bool DATABASE_DLL Date::operator < (const Date& date) const {
    if( m_Year < date.m_Year) {
      return true;
    } else if( m_Year == date.m_Year) {
      if(m_Month < date.m_Month) {
        return true;
      } else if( m_Month == date.m_Month) {
        return (m_Day < date.m_Day);
      }
    }
    return false;
  }
  
  bool DATABASE_DLL Date::operator <= (const Date& date) const {
    if( m_Year < date.m_Year) {
      return true;
    } else if( m_Year == date.m_Year) {
      if(m_Month < date.m_Month) {
        return true;
      } else if( m_Month == date.m_Month) {
        return (m_Day <= date.m_Day);
      }
    }
    return false;
  }
  
  bool DATABASE_DLL Date::operator != (const Date& date) const {
    return (m_Day != date.m_Day) || (m_Month != date.m_Month) || (m_Year != date.m_Year);
  }
  
  bool DATABASE_DLL Date::operator == (const Date& date) const {
    return (m_Day == date.m_Day) && (m_Month == date.m_Month) && (m_Year == date.m_Year);
  }
    
  Date& DATABASE_DLL Date::operator ++() {
    m_Day++;
    while(m_Day > Date::getDaysOfMonth(m_Month)) {
      m_Day -= Date::m_DaysOfMonth[m_Month];
      m_Month++;
      if(m_Month == 13) {
        m_Month = 1;
        m_Year++;
      }
    }
    return (*this);
  }
  
  Date& DATABASE_DLL Date::operator ++(int) {
    m_Day++;
    while(m_Day ==Date::getDaysOfMonth(m_Month)) {
      m_Day -= Date::getDaysOfMonth(m_Month);
      m_Month++;
      if(m_Month == 13) {
        m_Month = 1;
        m_Year++;
      }
    }
    return (*this);
  }
  
  Date& DATABASE_DLL Date::operator --() {
    m_Day--;
    if(m_Day == 0) {
      m_Day = (m_Month > 2) ? Date::m_DaysOfMonth[m_Month-2] : Date::m_DaysOfMonth[12-m_Month];
      m_Month--;
      if(m_Month == 0) {
        m_Month = 12;
        m_Year--;
      }
    }
    return (*this);
  }
  
  Date& DATABASE_DLL Date::operator --(int) {
    m_Day--;
    if(m_Day == 0) {
      if(m_Month-2 != 0) {
        m_Day = Date::m_DaysOfMonth[m_Month-2];
      } else {
        m_Day = Date::m_DaysOfMonth[11];
      }
      m_Month--;
      if(m_Month == 0) {
        m_Month = 12;
        m_Year--;
      }
    }
    return (*this);
  }
    
  std::string DATABASE_DLL Date::toString() const {
     std::string str = "";
     if(m_Day < 10) { str += "0";}
     str += std::to_string(m_Day);
     if(m_Month < 10) { str += "0";}
     return str + std::to_string(m_Month) + "." + std::to_string(m_Year);
  }
    
}