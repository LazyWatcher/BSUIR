from Documentation import *
from Showroom import *
from Warehouse import *
from Test_Drive import *
from Seller import *
from Car import *
from Customer import *
import pickle


if __name__ == '__main__':
    warehouse = Warehouse()
    car1 = Car("Toyota", "Camry", 2022, 25000, 6, "car")
    car2 = Car("BMW", "X5", 2023, 40000, 6, "car")
    car3 = Car("Audi", "A4", 2021, 30000, 6, "car")
    warehouse.add_car_to_warehouse(car1)
    warehouse.add_car_to_warehouse(car2)
    warehouse.add_car_to_warehouse(car3)
    showroom = Showroom("AutoPark", "Минск, ул. Космонавтов 10", 5, warehouse)
    customer = Customer("Иван", "88005553535", "pochta@gmail.com", 4000)
    seller = Seller("Олег", "NM5739224")
    document = Documentation(customer, seller, car1, "контракт", showroom)
    test_drive = Test_Drive(customer, seller, car1, "21", "3", "2024", showroom)

while True:
    print("1. Cохранить в файл")
    print("2. Загрузить файл")
    print("3. Вывести информацию о машинах на складе")
    print("4. Выставить в зал машину из склада")
    print("5. Вывести информацию о машинах в выставочном зале")
    print("6. Выбрать машину для контракта")
    print("7. Подписать контракт")
    print("8. Вывод контракта")
    print("9. Продажа машины")
    print("10. Выбор машины для тест драйва")
    print("11. Проведение тест драйва")
    print("12. Информация о модели машины")
    print("13. Сервисное обслуживание")
    print("14. Crash тест")
    print("0. Выход")
    try:
      choice = int(input("Введите число: "))
    except ValueError:
      print("Некорректный ввод")
      continue
    if choice == 1:
      with open("Warehouse.pickle", "wb") as file:
        pickle.dump(warehouse, file)
    elif choice == 2:
      with open("Warehouse.pickle", "rb") as file:
        warehouse = pickle.load(file)
        showroom.warehouse = warehouse
    elif choice == 3:
      warehouse.display_all_cars_in_warehouse()
    elif choice == 4:
      showroom.add_car_to_showroom(0)
    elif choice == 5:
      showroom.display_cars_info()
    elif choice == 6:
        print("Введите индекс машины для контракта ")
        document.change_car_in_contract()
    elif choice == 7:
      document.sign_document_by_seller()
      document.sign_document_by_customer()
      print("Контракт подписан")
    elif choice == 8:
      document.print_contract()
    elif choice == 9:
      document.sell_car()
    elif choice == 10:
      print("Введите индекс машины для тест драйва: ")
      test_drive.car_for_test()
    elif choice == 11:
      test_drive.run_test_drive(5)
    elif choice == 12:
       car1.model_info()
    elif choice == 13:
        customer.car.service_maintenance()
    elif choice == 14:
        customer.car.crash_test()
    elif choice == 0:
        break
    else:

        print("Некорректный ввод числа")