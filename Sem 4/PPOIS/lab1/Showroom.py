from Warehouse import *

class Showroom:
    def __init__(self, name: str, location: str, capacity: int, warehouse: Warehouse):
        self.name: str = name
        self.location: str = location
        self.capacity: int = capacity
        self.cars = []
        self.warehouse = warehouse

    def add_car_to_showroom(self, index: int):
        if index < len(self.warehouse.cars_in_warehouse):
            car = self.warehouse.take_car_from_warehouse(index)
            if car:
                if len(self.cars) >= self.capacity:
                  print("Зал переполнен. Введите индекс машины для замены: ")
                  while True:
                    try:
                        replace_index = int(input("Введите число: "))
                    except ValueError:
                        print("Некорректный ввод")
                        continue
                    if 0 <= replace_index < len(self.cars):
                      self.warehouse.add_car_to_warehouse = self.cars[replace_index]
                      self.cars[replace_index] = car
                      print("Машина успешно заменена в зале")
                      break
                    else:
                      print("Неправильный индекс для замены")
                else:
                    self.cars.append(car)
            else:
                print("На складе нет машин для добавления в зал")
        else:
            print("Индекс вне границ допустимого диапазона")

    def remove_car_from_showroom(self, index: int):
        if 0 <= index < len(self.cars):
            return self.cars.pop(index)
        return f"Индекс вне границ допустимого диапазона"


    def take_car_from_warehouse(self, index: int):
        if index < len(self.cars_in_warehouse):
            return self.cars_in_warehouse.pop(index)
        return f"Индекс вне границ допустимого диапазона"
    def display_cars_info(self):
        if self.cars:
            for car in self.cars:
                print(car.display_info())
        else:
            print("В зале нет машин")