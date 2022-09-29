mysql
mysql -e "CREATE DATABASE Data"; #DB 생성하기
mysql -e "CREATE USER 'yson'@'%' IDENTIFIED BY 'password'"; #유저 생성하기
mysql -e "GRANT ALL PREVILEGES ON Data.* TO 'yson'@'%'"; #사용자 권한 설정
mysql -e "ALTER USER 'root'@'%' IDENTIFIED BY '0000'"; #루트 비밀번호 변경
mysql -e "FLUSH PRIVILEGES"; #변경사항 적용
mysql -e "exit";
