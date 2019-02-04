-- phpMyAdmin SQL Dump
-- version 4.7.9
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: 2019-02-05 00:12:49
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
-- 函数
--
CREATE DEFINER=`root`@`localhost` FUNCTION `Common_RandString` (`uSize` INT(30) UNSIGNED) RETURNS VARCHAR(30) CHARSET utf8 SQL SECURITY INVOKER
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

CREATE DEFINER=`root`@`localhost` FUNCTION `Common_Signin` (`name` CHAR(15), `pass` CHAR(30)) RETURNS BIGINT(20) begin

	declare id bigint default null;
	
	if (isnull(name) || (length(name) = 0)) then
		return -1; -- 账号为空
	end if;
	
	if (isnull(pass) || (length(pass) = 0)) then
		return -2; -- 密码为空
	end if;

	if (@id := Common_Verify(name)) is null then
		return -3; -- 账号错误
	end if;

	if strcmp(pass, (select password from common_member where uid in(@id))) <> 0 then
		return -4; -- 密码错误
	end if;

	return @id; -- 验证通过
end$$

CREATE DEFINER=`root`@`localhost` FUNCTION `Common_Test` (`n` INT(10) UNSIGNED) RETURNS INT(10) UNSIGNED SQL SECURITY INVOKER
begin
	declare i int default 0;
	while (i < n)
	do
		insert common_member(username, password, date) values (Common_RandString(15), Common_RandString(30), unix_timestamp(now()));
		set i := i + 1;
	end while;
	return i;
end$$

CREATE DEFINER=`root`@`localhost` FUNCTION `Common_Verify` (`name` CHAR(15)) RETURNS BIGINT(20) UNSIGNED begin

	if (isnull(name) || (length(name) = 0)) then
		return null; -- 账号为空
	end if;

	return (select uid from common_member where username in(name));
end$$

DELIMITER ;

-- --------------------------------------------------------

--
-- 表的结构 `common_member`
--

CREATE TABLE `common_member` (
  `uid` bigint(20) UNSIGNED NOT NULL,
  `username` char(15) NOT NULL,
  `password` char(32) NOT NULL,
  `date` int(10) UNSIGNED DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `common_member`
--
ALTER TABLE `common_member`
  ADD PRIMARY KEY (`uid`),
  ADD UNIQUE KEY `username` (`username`) USING HASH;

--
-- 在导出的表使用AUTO_INCREMENT
--

--
-- 使用表AUTO_INCREMENT `common_member`
--
ALTER TABLE `common_member`
  MODIFY `uid` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
