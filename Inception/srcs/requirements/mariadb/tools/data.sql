CREATE DATABASE Data;
CREATE USER '$NAME'@'%' IDENTIFIED BY '$PWD';
GRANT ALL PRIVILEGES ON Data.* TO '$NAME'@'%' IDENTIFIED BY '$PWD';
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY '$ROOTPWD';