#include <iostream>

class Date {
    private:
        int month_arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year_;
        int month_;
        int day_;
    public: 
        void SetDate(int year, int month, int date) {
            year_ = year;
            month_ = month;
            day_ = date;
        }

        void AddDay(int inc) {
            while((day_ += inc) > month_arr[month_ - 1]) {
                day_ -= month_arr[month_ - 1];
                AddMonth(1);
            }
        }

        void AddMonth(int inc) {
            while ((month_ += inc) > 12) {
                year_++;
                month_ -= 12;
            }
        }

        void AddYear(int inc) {
            year_ += inc;
        }


};


int main(void) {

    Date date1;

    date1.SetDate(2022, 7, 8);

    
    return 0;
}