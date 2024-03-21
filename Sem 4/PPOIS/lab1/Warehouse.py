

class Warehouse:
    def __init__(self):
        self.cars_in_warehouse = []

    def add_car_to_warehouse(self, car):
        self.cars_in_warehouse.append(car)

    def take_car_from_warehouse(self, index: int):
        if index < len(self.cars_in_warehouse):
            return self.cars_in_warehouse.pop(index)
        return f"Индекс вне границ допустимого диапазона"

    def display_all_cars_in_warehouse(self):
        if self.cars_in_warehouse:
            for car in self.cars_in_warehouse:
                print(car.display_info())
        else:
            print("На складе нет машин")

