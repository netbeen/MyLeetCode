/*

给定一个表Person
+----+---------+
| Id | Email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+

要求返回全部的重复Email
+---------+
| Email   |
+---------+
| a@b.com |
+---------+

思路：先筛选出全部重复条目，再去重。
筛选：Person a inner join Person b using(Email) where a.Id != b.Id
去重：select distinct Email from 

*/

select distinct Email from Person a inner join Person b using(Email) where a.Id != b.Id
