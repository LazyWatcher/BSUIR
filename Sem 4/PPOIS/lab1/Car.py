from datetime import datetime


class Car:
    date_of_sale = None
    owner = None
    sold = False
    broken = False
    def __init__(self, brand: str, model: str, year: int, price: int, guarantee: int, info: str):
        self.__brand: str = brand
        self.__model: str = model
        self.__year: int = year
        self.price: int = price
        self.info: str = info
        self.guarantee: int = guarantee



    @property
    def brand(self):
        return self.__brand

    @property
    def model(self):
        return self.__model

    @property
    def year(self):
        return self.__year

    def service_maintenance(self):
        if self.sold:
            current_date = datetime.now()
            if self.date_of_sale:
                months_since_sale = (current_date.year - self.date_of_sale.year) * 12 + current_date.month - self.date_of_sale.month
                if months_since_sale >= self.guarantee:
                    print("Гарантия истекла. Машина удаляется.")
                    del self
                else:
                    if self.broken:
                        self.broken = False
                        print("Машина починена.")
                    else:
                        print("Машина в порядке.")
            else:
                print("Дата продажи не указана.")
        else:
            print("Машина не продана")



    def display_info(self):
        return f"{self.year} {self.brand} {self.model} за {self.price} долларов. Гарантия {self.guarantee} месяцев"

    def model_info(self):
        print(f"Машина: {self.brand} {self.model}")
        print(self.info)

    def crash_test(self):
        self.broken = True