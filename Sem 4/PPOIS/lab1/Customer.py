from Car import *
class Customer:
    car: Car = None
    def __init__(self, name: str, phone_number: str, email: str, money: int):
        self.__name = name
        self.__phone_number = phone_number
        self.__email = email
        self.money = money
        self.signature_customer: bool = False

    @property
    def name(self):
        return self.__name

    @property
    def phone_number(self):
        return self.__phone_number

    @property
    def email(self):
        return self.__email
    def sign_document(self) -> bool:
        self.signature_customer: bool = True
        return self.signature_customer