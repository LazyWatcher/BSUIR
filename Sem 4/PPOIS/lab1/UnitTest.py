import unittest
from Car import *
from Customer import *
from Documentation import *
from Showroom import *
from Showroom import *
from Warehouse import *
from Test_Drive import *
from Seller import *
import pickle
import time

class MyTestCase(unittest.TestCase):
    def test_sold(self):
        warehouse = Warehouse()
        index = 1
        seller = Seller("Олег", "NM5739224")
        car1 = Car("Toyota", "Camry", 2022, 25000, 6, "car")
        customer = Customer("Иван", "88005553535", "pochta@gmail.com", 40000)
        warehouse.add_car_to_warehouse(car1)

        showroom = Showroom("AutoPark", "Москва, ул. Центральная 456", 3, warehouse)
        showroom.add_car_to_showroom(0)
        document = Documentation(customer, seller, car1, "много букв", showroom)
        document.sign_document_by_customer()
        document.sign_document_by_seller()
        document.sell_car()

        self.assertEqual(car1.sold, True)

    def test_broken(self):
        warehouse = Warehouse()
        index = 1
        seller = Seller("Олег", "NM5739224")
        car1 = Car("Toyota", "Camry", 2022, 25000, 6, "car")
        customer = Customer("Иван", "88005553535", "pochta@gmail.com", 40000)
        warehouse.add_car_to_warehouse(car1)

        showroom = Showroom("AutoPark", "Москва, ул. Центральная 456", 3, warehouse)
        showroom.add_car_to_showroom(0)
        document = Documentation(customer, seller, car1, "много букв", showroom)
        document.sign_document_by_customer()
        document.sign_document_by_seller()
        document.sell_car()
        car1.crash_test()
        car1.service_maintenance()
        self.assertEqual(car1.broken, False)
if __name__ == '__main__':
    unittest.main()
