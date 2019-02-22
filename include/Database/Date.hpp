#ifndef DATABASE_DATE_HPP
#define DATABASE_DATE_HPP

#include <Database/DLL.hpp>
#include <Serialization/Serializable.hpp>
#include <cstdint>
#include <string>
#include <array>



namespace db {
   
  class DATABASE_DLL Date : public serialization::Serializable {

    uint16_t m_Day;
    uint16_t m_Month;
    uint32_t m_Year;
  
    static std::array<uint16_t,12> m_DaysOfMonth;
    
    public:
    Date();
    Date(uint16_t day, uint16_t month, uint32_t year);
    ~Date();

    static Date Today;
 
    bool operator > (const Date& date) const;
    bool operator >= (const Date& date) const;
    bool operator < (const Date& date) const;
    bool operator <= (const Date& date) const;
    bool operator != (const Date& date) const;
    bool operator == (const Date& date) const;
    
    Date& operator ++();
    Date& operator ++(int);
    Date& operator --();
    Date& operator --(int);
    
    static uint16_t getDaysOfMonth( uint16_t month );
    static bool isLeapYear( uint32_t year );
    
    uint32_t getFullYearDifference( Date date ) const;
    
    std::string toString() const;
    
    void save(const serialization::BinaryWriter& writer) const override
    {
      writer( m_Day );
      writer( m_Month );
      writer( m_Year );
    }

    void load(serialization::BinaryReader& reader) override
    {
      reader( m_Day );
      reader( m_Month );
      reader( m_Year );
    }
    
    
  };
  
}

#endif