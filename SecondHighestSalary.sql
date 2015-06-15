/*

给定一个表Employee：
+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+

要求返回第二大的工资。
200

首先查找最大工资，然后在比最大工资低的工资中，寻找最大值。

*/

select max(Salary) from Employee where Salary < (select max(Salary) from Employee)

