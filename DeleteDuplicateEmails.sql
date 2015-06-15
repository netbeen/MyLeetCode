/*

给定表Person:
+----+------------------+
| Id | Email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
| 3  | john@example.com |
+----+------------------+

要求删除重复的Email条目，保留Id最小的Email
+----+------------------+
| Id | Email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
+----+------------------+

首先将两个表连接（左外连），然后删除。
注意：连接之后的删除：需要在delete from之间加入需要删除那个表的明确指示。
比如delete t1 from t1 join t2...

*/

delete a from Person a left outer join Person b using(Email) where a.Id > b.Id
