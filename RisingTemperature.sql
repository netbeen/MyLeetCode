/*

给定一个表：
+---------+------------+------------------+
| Id(INT) | Date(DATE) | Temperature(INT) |
+---------+------------+------------------+
|       1 | 2015-01-01 |               10 |
|       2 | 2015-01-02 |               25 |
|       3 | 2015-01-03 |               20 |
|       4 | 2015-01-04 |               30 |
+---------+------------+------------------+

要求返回一个表，其中每一个id对应的天的温度，比前一天高
+----+
| Id |
+----+
|  2 |
|  4 |
+----+

分析：也是内连接比较题，注意：日期的比较需要用TO_DAYS()函数，这个函数可以将Data转化为int型

*/
select a.Id from Weather a inner join Weather b 
where TO_DAYS(a.Date) = TO_DAYS(b.Date)+1 and a.Temperature > b.Temperature