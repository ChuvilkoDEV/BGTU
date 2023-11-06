-- we don't know how to generate root <with-no-name> (class Root) :(

grant select on performance_schema.* to 'mysql.session'@localhost;

grant trigger on sys.* to 'mysql.sys'@localhost;

grant super on *.* to 'mysql.session'@localhost;

grant alter, alter routine, create, create routine, create tablespace, create temporary tables, create user, create view, delete, drop, event, execute, file, index, insert, lock tables, process, references, reload, replication client, replication slave, select, show databases, show view, shutdown, super, trigger, update, grant option on *.* to root@localhost;

CREATE DATABASE IF NOT EXISTS dealership;

CREATE TABLE IF NOT EXISTS `dealership`.`contact_details`
(
    `id`         INT(11)     NOT NULL AUTO_INCREMENT,
    `first_name` VARCHAR(20) NOT NULL,
    `last_name`  VARCHAR(20) NOT NULL,
    `email`      VARCHAR(30) NULL,
    `phone`      VARCHAR(12) NULL,
    PRIMARY KEY (`id`)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `dealership`.`buyer`
(
    `id`                 INT(11) NOT NULL AUTO_INCREMENT,
    `contact_details_id` INT(11) NOT NULL,
    PRIMARY KEY (`id`),
    FOREIGN KEY (contact_details_id) REFERENCES contact_details (id)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `dealership`.`qualification`
(
    `id`               INT(11)      NOT NULL AUTO_INCREMENT,
    `post`             VARCHAR(30)  NOT NULL,
    `experience`       INT(2)       NOT NULL,
    `certification`    VARCHAR(30)  NOT NULL,
    `additional_notes` VARCHAR(255) NOT NULL,
    PRIMARY KEY (`id`)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `dealership`.`seller`
(
    `id`                 INT(11) NOT NULL AUTO_INCREMENT,
    `contact_details_id` INT(11) NOT NULL,
    `qualification_id`   INT(11) NOT NULL,
    PRIMARY KEY (`id`),
    FOREIGN KEY (contact_details_id) REFERENCES contact_details (id),
    FOREIGN KEY (qualification_id) REFERENCES qualification (id)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `dealership`.`car`
(
    `id`              INT(11)     NOT NULL AUTO_INCREMENT,
    `mark`            VARCHAR(20) NOT NULL,
    `model`           VARCHAR(20) NOT NULL,
    `year_of_release` DATE        NOT NULL,
    `color`           VARCHAR(10) NOT NULL,
    `VIN`             VARCHAR(18)     NOT NULL,
    `price`           INT(11)     NOT NULL,
    PRIMARY KEY (`id`)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `dealership`.`dealer`
(
    `id`      INT(11)      NOT NULL AUTO_INCREMENT,
    `title`   VARCHAR(30)  NOT NULL,
    `address` VARCHAR(100) NOT NULL,
    `city`    VARCHAR(30)  NOT NULL,
    `rating`  FLOAT(4)     NOT NULL,
    `car_id`  INT(11)      NOT NULL,
    PRIMARY KEY (`id`),
    FOREIGN KEY (car_id) REFERENCES car (id)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `dealership`.`sales_contract`
(
    `id`           INT(11)  NOT NULL AUTO_INCREMENT,
    `date_of_sale` DATETIME NOT NULL,
    `sale_amount`  INT(2)   NOT NULL,
    `seller_id`    INT(11)  NOT NULL,
    `buyer_id`     INT(11)  NOT NULL,
    `dealer_id`    INT(11)  NOT NULL,
    `car_id`       INT(11)  NOT NULL,
    PRIMARY KEY (`id`),
    FOREIGN KEY (seller_id) REFERENCES seller (id),
    FOREIGN KEY (buyer_id) REFERENCES buyer (id),
    FOREIGN KEY (dealer_id) REFERENCES dealer (id),
    FOREIGN KEY (car_id) REFERENCES car (id)
) ENGINE = InnoDB;


