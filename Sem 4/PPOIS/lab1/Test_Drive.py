
import time
from Car import *
from Customer import *
from Seller import *
from Showroom import *
class Test_Drive:
    start_time = None
    end_time = None
    def __init__(self, customer: Customer, seller: Seller, car: Car, day: str, mouth: str, year: str, showroom: Showroom):
        self.customer = customer
        self.car = car
        self.seller = seller
        self.showroom = showroom
        self.day = day
        self.mouth = mouth
        self.year = year
        self.start_time = None
        self.end_time = None

    def convert_current_date(self):
        current_date = datetime.now()
        day = str(current_date.day)
        month = str(current_date.month)
        year = str(current_date.year)
        return day, month, year
    def start_test(self):
        if self.car.sold == True:
            print(f'Машина {self.car.brand} {self.car.model} уже продана!')
        else:
            current_day, current_mouth, current_year = self.convert_current_date()
            if int(current_day) < int(self.day) and int(current_mouth) <= int(self.mouth) and int(current_year) <= int(self.year):
              print(f"Тест-драйв {self.car.brand} {self.car.model} еще не начался. Запланированная дата: {self.day} {self.mouth} {self.year}")
            if int(current_day) == int(self.day) and int(current_mouth) == int(self.mouth) and int(current_year) == int(self.year):
              self.start_time = datetime.now().strftime("%H:%M:%S")
            print(f'Тест-драйв {self.car.brand} {self.car.model} начался! Текущее время:', self.start_time)


    def end_test(self):
        if self.start_time == None:
            print(f'Тест-драйв {self.car.brand} {self.car.model} не начинался')
        else:
            self.end_time = datetime.now().strftime("%H:%M:%S")
            print(f'Тест-драйв {self.car.brand} {self.car.model} закончился! Текущее время:', self.end_time)
            self.start_time = None
            self.end_time = None
            del self

    def run_test_drive(self, sec: int):
        count = sec
        self.start_test()
        time.sleep(count)
        self.end_test()

    def car_for_test(self):
        if len(self.showroom.cars) == 0:
            print("В зале нет машин.")
        else:
          while True:
            try:
                index = int(input())
            except ValueError:
                print("Некорректный ввод. Попробуй ещё раз.")
                continue
            break
          if 0 <= index < len(self.showroom.cars):
            self.car = self.showroom.cars[index]
            print(f"Машина для тест драйва: {self.car.brand} {self.car.model}")
          else:
            print("Индекс вне границ допустимого диапазона")
