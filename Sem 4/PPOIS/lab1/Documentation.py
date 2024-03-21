from Car import *
from Customer import *
from Showroom import *
from Seller import *
from datetime import datetime

class Documentation:
    signature_seller: bool = False
    signature_customer: bool = False

    def __init__(self, customer: Customer, seller: Seller, car: Car, contract: str, showroom: Showroom):
        self.contract = contract
        self.customer = customer
        self.seller = seller
        self.car = car
        self.showroom = showroom

    def sign_document_by_seller(self):
        self.seller.sign_document
        self.signature_seller = True


    def sign_document_by_customer(self):
        self.customer.sign_document
        self.signature_customer = True


    def print_contract(self):
        print(f"Контракт: {self.contract}")
        print(f"Машина: {self.car.brand} {self.car.model}")
        print(f"Цена машины: {self.car.price}")
        print("Продавец")
        print(f"Имя: {self.seller.name}")
        print(f"Подпись: {'Стоит' if self.signature_seller else 'Не стоит'}")
        print("Клиент")
        print(f"Имя: {self.customer.name}")
        print(f"Подпись: {'Стоит' if self.signature_customer else 'Не стоит'}")
        if self.signature_seller and self.signature_customer:
            print(f"Контракт подписан! Машина {self.car.brand} {self.car.model} готова к продаже!")

    def sell_car(self):
        if self.signature_seller and self.signature_customer:
            self.car.owner = self.customer
            self.customer.car = self.car
            self.car.date_of_sale = datetime.now()
            self.car.sold = True
            self.customer.money = self.customer.money - self.car.price
            print(f"Машина {self.car.brand} {self.car.model} продана!")
            self.showroom.cars.remove(self.car)
        else:
            print("В контракте нет подписей")


    def change_car_in_contract(self):
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
            print(f"Машина для контракта: {self.car.brand} {self.car.model}")
          else:
            print("Индекс вне границ допустимого диапазона")