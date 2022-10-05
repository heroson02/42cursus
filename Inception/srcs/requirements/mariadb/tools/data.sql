CREATE DATABASE Data; --DB 생성하기
CREATE USER 'yson'@'localhost' IDENTIFIED BY 'password'; --유저 생성하기
GRANT ALL PREVILEGES ON Data.* TO 'yson'@'localhost'; --사용자 권한 설정
ALTER USER 'root'@'localhost' IDENTIFIED BY '0000'; --루트 비밀번호 변경
FLUSH PRIVILEGES; --변경사항 적용
exit;