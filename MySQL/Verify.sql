-- phpMyAdmin SQL Dump
-- version 4.7.9
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: 2019-02-17 19:56:46
-- 服务器版本： 5.7.25-log
-- PHP Version: 7.2.14

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `Verify`
--

DELIMITER $$
--
-- 存储过程
--
CREATE DEFINER=`root`@`%` PROCEDURE `Common_Clear` ()  SQL SECURITY INVOKER
begin

  declare count bigint default null;
  declare i int default 1;

  set @count := (select max(uid) from `common_member`);
 
	while (i <= @count)
	do
    if Common_Conut(i) <> 0 then
      update `common_member` set `count` = '0' where `uid` in(i);
    end if;
		set i := i + 1;
	end while;

end$$

--
-- 函数
--
CREATE DEFINER=`root`@`%` FUNCTION `Common_Code` (`id` INT(11) UNSIGNED) RETURNS INT(11) UNSIGNED SQL SECURITY INVOKER
begin
  return (select `code` from `common_member` where `uid` in(id));
end$$

CREATE DEFINER=`root`@`%` FUNCTION `Common_Conut` (`id` INT(11) UNSIGNED) RETURNS INT(11) UNSIGNED SQL SECURITY INVOKER
begin
return (select `count` from `common_member` where `uid` in(id));
end$$

CREATE DEFINER=`root`@`localhost` FUNCTION `Common_Expires` (`id` INT(11) UNSIGNED) RETURNS INT(11) UNSIGNED begin
  return (select `date` from `common_member` where `uid` in(id));
end$$

CREATE DEFINER=`root`@`localhost` FUNCTION `Common_Password` (`id` INT(11) UNSIGNED, `pass` VARCHAR(32)) RETURNS INT(11) UNSIGNED begin

  if (isnull(pass) || (length(pass) = 0)) then
		return 1; -- 账号为空
	end if;

  return strcmp(pass, (select `password` from `common_member` where `uid` in(id)));
end$$

CREATE DEFINER=`root`@`%` FUNCTION `Common_RandString` (`uSize` INT(11) UNSIGNED) RETURNS VARCHAR(32) CHARSET utf8 SQL SECURITY INVOKER
begin
	declare lpszBuffer varchar(255) default 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789';
	declare lpszString varchar(255) default '';
	declare i int default 0;
	while (i < uSize)
	do
		set lpszString := concat(lpszString, substring(lpszBuffer, floor(1 + rand() *62), 1));
		set i := i + 1;
	end while;
return lpszString;
end$$

CREATE DEFINER=`root`@`localhost` FUNCTION `Common_Signin` (`user` CHAR(16), `pass` CHAR(32), `code` INT(11) UNSIGNED) RETURNS INT(11) begin

	declare id bigint default null;

	if (isnull(user) || (length(user) = 0)) then
		return -1; -- 账号为空
	end if;
	
	if (isnull(pass) || (length(pass) = 0)) then
		return -2; -- 密码为空
	end if;

	if (@id := Common_Verify(user)) is null then
		return -3; -- 账号错误
	end if;

	if Common_Password(@id, pass) <> 0 then
		return -4; -- 密码错误
	end if;
  
  if Common_State(@id) <> 0 then
    return -5; -- 账号封停
  end if;

  if Common_Code(@id) <> code then
    return -6; -- 锁机错误
  end if;

	return @id; -- 验证通过
end$$

CREATE DEFINER=`root`@`%` FUNCTION `Common_State` (`id` INT(11) UNSIGNED) RETURNS INT(11) UNSIGNED SQL SECURITY INVOKER
begin
  return (select `state` from `common_member` where `uid` in(id));
end$$

CREATE DEFINER=`root`@`%` FUNCTION `Common_Test` (`n` INT(11) UNSIGNED) RETURNS INT(11) UNSIGNED SQL SECURITY INVOKER
begin
	declare i int default 0;
	while (i < n)
	do
		insert common_member(username, password, date) values (Common_RandString(15), Common_RandString(30), unix_timestamp(now()));
		set i := i + 1;
	end while;
	return i;
end$$

CREATE DEFINER=`root`@`localhost` FUNCTION `Common_Verify` (`user` CHAR(16)) RETURNS INT(11) begin

	if (isnull(user) || (length(user) = 0)) then
		return -1; -- 账号为空
	end if;

	return (select `uid` from `common_member` where `username` in(user));
end$$

CREATE DEFINER=`root`@`localhost` FUNCTION `Common_Write` (`user` VARCHAR(16), `pass` VARCHAR(32)) RETURNS INT(11) begin
  
  declare id bigint default null;

	if (isnull(user) || (length(user) = 0)) then
		return -1; -- 账号为空
	end if;
	
	if (isnull(pass) || (length(pass) = 0)) then
		return -2; -- 密码为空
	end if;

  if Common_Verify(user) is not null then
    return -3; -- 账号存在
	end if;
  
  insert into `common_member` (`uid`, `username`, `password`, `code`, `count`, `state`, `date`) values (null, user, pass, '0', '0', '0', '0');
  
  if (@id := (select @@Identity)) is not null then
    return @id;
  end if;

  return 0;

end$$

DELIMITER ;

-- --------------------------------------------------------

--
-- 表的结构 `common_member`
--

CREATE TABLE `common_member` (
  `uid` int(11) UNSIGNED NOT NULL,
  `username` char(16) NOT NULL,
  `password` char(32) NOT NULL,
  `code` int(11) UNSIGNED NOT NULL DEFAULT '0',
  `count` int(11) UNSIGNED NOT NULL DEFAULT '0',
  `state` int(11) UNSIGNED NOT NULL DEFAULT '0',
  `date` int(11) UNSIGNED NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- 转存表中的数据 `common_member`
--

INSERT INTO `common_member` (`uid`, `username`, `password`, `code`, `count`, `state`, `date`) VALUES
(1, '123', '123', 0, 0, 0, 1549369582),
(2, 'xb8YkzGwplkqZxy', '0bL5YrakXEdXZUrhVEkvqpCIyuBmR4', 0, 0, 0, 1549369560),
(3, '123123', '123123', 0, 0, 0, 0),
(4, '1', '2', 0, 0, 0, 0),
(5, '2', '2', 0, 0, 0, 0),
(6, '3', '2', 0, 0, 0, 0),
(7, '12311', '456', 0, 0, 0, 0),
(8, '123111', '456', 0, 0, 0, 0),
(9, '12333444', '123', 0, 0, 0, 0),
(10, '123334444', '123', 0, 0, 0, 0),
(11, '1233344445', '123', 0, 0, 0, 0),
(12, '555', '123', 0, 0, 0, 0),
(13, '5556', '123', 0, 0, 0, 0);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `common_member`
--
ALTER TABLE `common_member`
  ADD PRIMARY KEY (`uid`),
  ADD UNIQUE KEY `username` (`username`);

--
-- 在导出的表使用AUTO_INCREMENT
--

--
-- 使用表AUTO_INCREMENT `common_member`
--
ALTER TABLE `common_member`
  MODIFY `uid` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;

DELIMITER $$
--
-- 事件
--
CREATE DEFINER=`root`@`localhost` EVENT `clear_count` ON SCHEDULE EVERY 1 DAY STARTS '2019-02-08 00:00:00' ON COMPLETION PRESERVE ENABLE DO CALL Common_Clear()$$

DELIMITER ;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
