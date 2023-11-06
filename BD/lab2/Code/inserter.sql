-- Вставка данных в таблицу "qualification"
INSERT INTO dealership.qualification (post, experience, certification, additional_notes)
VALUES ('Менеджер по продажам', 3, 'Сертификат №12345', 'Дополнительные навыки: клиентоориентированность'),
       ('Технический специалист', 5, 'Сертификат №54321',
        'Дополнительные навыки: техническое обслуживание автомобилей');


-- Вставка данных в таблицу "contact_details"
INSERT INTO dealership.contact_details (first_name, last_name, email, phone)
VALUES ('John', 'Doe', 'john@example.com', '1234567890'),
       ('Jane', 'Smith', 'jane@example.com', '9876543210'),
       ('Alice', 'Johnson', 'alice@example.com', '5555555555'),
       ('Bob', 'Williams', 'bob@example.com', '7777777777'),
       ('Eva', 'Brown', 'eva@example.com', '8888888888'),
       ('Mike', 'Davis', 'mike@example.com', '6666666666'),
       ('Lisa', 'Lee', 'lisa@example.com', '4444444444'),
       ('Alex', 'Taylor', 'alex@example.com', '2222222222'),
       ('Sarah', 'Clark', 'sarah@example.com', '9999999999'),
       ('Tom', 'Wilson', 'tom@example.com', '1111111111');


-- Вставка данных в таблицу "buyer"
INSERT INTO dealership.buyer (contact_details_id)
VALUES (1), -- Ссылка на контакт с id = 1
       (3), -- Ссылка на контакт с id = 3
       (5), -- Ссылка на контакт с id = 5
       (7), -- Ссылка на контакт с id = 7
       (9);
-- Ссылка на контакт с id = 9


-- Вставка данных в таблицу "seller"
INSERT INTO dealership.seller (contact_details_id, qualification_id)
VALUES (2, 1), -- Ссылка на контакт с id = 2 и квалификацию с id = 1
       (4, 2), -- Ссылка на контакт с id = 4 и квалификацию с id = 2
       (6, 1), -- Ссылка на контакт с id = 6 и квалификацию с id = 1
       (8, 2);
-- Ссылка на контакт с id = 8 и квалификацию с id = 2


-- Вставка данных в таблицу "car"
INSERT INTO dealership.car (mark, model, year_of_release, color, VIN, price)
VALUES ('Toyota', 'Camry', '2020-01-01', 'Blue', 12345678901234567, 20000),
       ('Honda', 'Civic', '2019-01-01', 'Red', 98765432109876543, 18000),
       ('Ford', 'Focus', '2018-01-01', 'Silver', 56789012345678901, 15000),
       ('Chevrolet', 'Malibu', '2021-01-01', 'Black', 23456789012345678, 22000),
       ('Nissan', 'Altima', '2017-01-01', 'White', 78901234567890123, 16000);


-- Вставка данных в таблицу "dealer"
INSERT INTO dealership.dealer (title, address, city, rating, car_id)
VALUES ('Auto World', '123 Main Street', 'New York', 4.5, 1),
       ('City Motors', '456 Elm Street', 'Los Angeles', 4.0, 2),
       ('Speedy Cars', '789 Oak Street', 'Chicago', 4.2, 3),
       ('Mega Autos', '101 Pine Street', 'Houston', 4.8, 4),
       ('Elite Motors', '202 Maple Street', 'Miami', 4.6, 5);


-- Вставка данных в таблицу "sales_contract"
INSERT INTO dealership.sales_contract (date_of_sale, sale_amount, seller_id, buyer_id, dealer_id, car_id)
VALUES ('2023-10-01 10:00:00', 20000, 1, 1, 1, 1),
       ('2023-10-02 11:30:00', 18000, 2, 2, 2, 2),
       ('2023-10-03 09:45:00', 15000, 3, 3, 3, 3),
       ('2023-10-04 15:20:00', 22000, 4, 4, 4, 4),
       ('2023-10-05 13:15:00', 16000, 2, 5, 5, 5);


UPDATE dealership.car
SET price = 21000
WHERE id = 1;

UPDATE dealership.car
SET model = 'Accord'
WHERE id = 2;

UPDATE dealership.dealer
SET address = '123 Oak Street'
WHERE id = 4;

UPDATE dealership.dealer
SET rating = rating + 0.5
WHERE id = 5;


DELETE
FROM dealership.contact_details
WHERE id = 10;