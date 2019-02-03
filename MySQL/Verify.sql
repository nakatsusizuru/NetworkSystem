-- phpMyAdmin SQL Dump
-- version 4.7.9
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: 2019-02-04 00:18:14
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
CREATE DEFINER=`root`@`localhost` FUNCTION `Common_Signin` (`name` CHAR(15), `pass` CHAR(30)) RETURNS INT(10) begin
	declare id int default null;
	
	if IFNULL(name, '') = false then
		return -1; -- 账号为空
	end if;
	
	if IFNULL(pass, '') = false then
		return -2; -- 密码为空
	end if;

	if (@id := Common_Verify(name)) is null then
		return -3; -- 账号错误
	end if;

	if (select uid in(@id) from common_member where password in(pass)) is null then
		return -4; -- 密码错误
	end if;

	return 0; -- 验证通过
end$$

CREATE DEFINER=`root`@`localhost` FUNCTION `Common_Verify` (`name` CHAR(15)) RETURNS INT(10) UNSIGNED BEGIN
	RETURN (SELECT uid FROM common_member WHERE username IN(name));
END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- 表的结构 `common_member`
--

CREATE TABLE `common_member` (
  `uid` int(10) UNSIGNED NOT NULL,
  `username` char(15) NOT NULL,
  `password` char(32) NOT NULL,
  `date` int(10) UNSIGNED DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- 转存表中的数据 `common_member`
--

INSERT INTO `common_member` (`uid`, `username`, `password`, `date`) VALUES
(1, '123', '123', 0);

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
  MODIFY `uid` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
