-- phpMyAdmin SQL Dump
-- version 4.7.9
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: 2019-02-19 21:37:52
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

CREATE DEFINER=`root`@`localhost` FUNCTION `Common_Password` (`id` INT(11) UNSIGNED, `pass` CHAR(32)) RETURNS INT(11) begin

  if (isnull(pass) || (char_length(pass) = 0)) then
		return 1; -- 密码为空
	end if;

  return strcmp((select `password` from `common_member` where `uid` in(id)), pass);
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

	if (isnull(user) || (char_length(user) = 0)) then
		return -1; -- 账号为空
	end if;

	if (isnull(pass) || (char_length(pass) = 0)) then
		return -2; -- 密码为空
	end if;
  
  if char_length(user) < 2 || char_length(user) > 16 then
    return -3; -- 账号不符
  end if;

  if char_length(pass) < 2 || char_length(pass) > 32 then
    return -4; -- 密码不符
  end if;

	if (@id := Common_Verify(user)) is null then
		return -5; -- 账号错误
	end if;

	if Common_Password(@id, pass) <> 0 then
		return -6; -- 密码错误
	end if; 
  
  if Common_State(@id) <> 0 then
    return -7; -- 账号封停
  end if;

  if Common_Code(@id) <> code then
    return -8; -- 锁机错误
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

	if (isnull(user) || (char_length(user) = 0)) then
		return -1; -- 账号为空
	end if;

	return (select `uid` from `common_member` where `username` in(user)); 
end$$

CREATE DEFINER=`root`@`localhost` FUNCTION `Common_Write` (`user` CHAR(16), `pass` CHAR(32), `email` CHAR(32), `phone` CHAR(11), `pin` INT(11) UNSIGNED) RETURNS INT(11) begin
  
  declare id bigint default null;

	if (isnull(user) || (char_length(user) = 0)) then
		return -1; -- 账号为空
	end if;
	
	if (isnull(pass) || (char_length(pass) = 0)) then
		return -2; -- 密码为空
	end if;

	if (isnull(email) || (char_length(email) = 0)) then
		return -3; -- 邮件为空
	end if;

	if (isnull(phone) || (char_length(phone) = 0)) then
		return -4; -- 电话为空
	end if;

  if (isnull(pin) || (length(pin) = 0)) then
		return -5; -- pin为空
	end if;

  if char_length(user) < 2 || char_length(user) > 16 then
    return -6; -- 账号不符
  end if;

  if char_length(pass) < 2 || char_length(pass) > 32 then
    return -7; -- 密码不符
  end if;

  if char_length(email) < 4 || char_length(email) > 32 then
    return -8; -- 邮件不符
  end if;

  if char_length(phone) < 6 || char_length(phone) > 11 then
    return -9; -- 电话不符
  end if;

  if length(pin) < 4 || length(pin) > 8 then
    return -10; -- pin不符
  end if;

  if Common_Verify(user) is not null then
    return -11; -- 账号存在 
	end if;

  insert delayed into `common_member` (`uid`, `username`, `password`, `email`, `phone`, `pin`, `code`, `count`, `state`, `date`) values (null, user, pass, email, phone, pin, '0', '0', '0', '0');
  
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
  `email` char(32) NOT NULL,
  `phone` char(11) NOT NULL,
  `pin` int(11) UNSIGNED NOT NULL DEFAULT '0',
  `code` int(11) UNSIGNED NOT NULL DEFAULT '0',
  `count` int(11) UNSIGNED NOT NULL DEFAULT '0',
  `state` int(11) UNSIGNED NOT NULL DEFAULT '0',
  `date` int(11) UNSIGNED NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- 转存表中的数据 `common_member`
--

INSERT INTO `common_member` (`uid`, `username`, `password`, `email`, `phone`, `pin`, `code`, `count`, `state`, `date`) VALUES
(1, '都是啊打发士大夫', '广泛大概让他', '', '0', 0, 0, 0, 0, 0),
(2, '123', '123', '', '0', 0, 0, 0, 0, 1950563878),
(3, '11', '22', '', '0', 0, 0, 0, 0, 0),
(4, '啊啊', '是是', '', '0', 0, 0, 0, 0, 0),
(5, '啊啊啊', '是是', '', '0', 0, 0, 0, 0, 0),
(6, '是是', '是是', '', '0', 0, 0, 0, 0, 0),
(7, '的的', '是是', '', '0', 0, 0, 0, 0, 0),
(8, '打是', '是是', '', '0', 0, 0, 0, 0, 0),
(9, '打是啊', '是是', '', '0', 0, 0, 0, 0, 0),
(10, '打是啊1', '是是', '', '0', 0, 0, 0, 0, 0),
(11, '打是啊12', '是是', '', '0', 0, 0, 0, 0, 0),
(12, '打是啊123', '是是', '', '0', 0, 0, 0, 0, 0),
(13, 'asdasd12', '123123123', '', '0', 0, 0, 0, 0, 0),
(14, '123123123', '123123123', 'master@crack.ee', '18304489877', 521815, 0, 0, 0, 0),
(15, '啊啊1', '是是', '123', '456', 789, 0, 0, 0, 0),
(16, '啊啊123', '是是123', '1234', '123456', 1231231, 0, 0, 0, 0),
(17, 'erte5345345', '234234435345', '540163@qq.com', '18304489877', 521815, 0, 0, 0, 0),
(18, 'erte534534', '23423443534', '540163@qq.com', '18304489877', 521815, 0, 0, 0, 0),
(19, 'erte53453', '23423443534', '540163@qq.com', '18304489877', 521815, 0, 0, 0, 0),
(20, 'erte5345', '23423443534', '540163@qq.com', '18304489877', 521815, 0, 0, 0, 0),
(21, 'erte534', '23423443534', '540163@qq.com', '18304489877', 521815, 0, 0, 0, 0),
(22, 'erte53', '23423443534', '540163@qq.com', '18304489877', 521815, 0, 0, 0, 0),
(23, 'erte53dfs', '23423443534', '540163@qq.com', '18304489877', 521815, 0, 0, 0, 0),
(24, 'erte53df', '23423443534', '540163@qq.com', '18304489877', 521815, 0, 0, 0, 0),
(25, 'erte53d', '23423443534', '540163@qq.com', '18304489877', 521815, 0, 0, 0, 0),
(26, 'erte53d4234', '23423443534', '540163@qq.com', '18304489877', 521815, 0, 0, 0, 0),
(27, 'erte53d4234f', '23423443534', '540163@qq.com', '18304489877', 521815, 0, 0, 0, 0),
(28, 'erte53d4234f534', '23423443534', '540163@qq.com', '18304489877', 521815, 0, 0, 0, 0);

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
  MODIFY `uid` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=29;

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
