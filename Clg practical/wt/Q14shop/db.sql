CREATE DATABASE ShopDB;
USE ShopDB;
CREATE TABLE inventory (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100),
    price DECIMAL(10,2),
    quantity INT
);