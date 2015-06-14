/*
给定一个表：
+----+-------+--------+-----------+
| Id | Name  | Salary | ManagerId |
+----+-------+--------+-----------+
| 1  | Joe   | 70000  | 3         |
| 2  | Henry | 80000  | 4         |
| 3  | Sam   | 60000  | NULL      |
| 4  | Max   | 90000  | NULL      |
+----+-------+--------+-----------+

要求返回比经理工资还要高的员工姓名
+----------+
| Employee |
+----------+
| Joe      |
+----------+

由于要比较员工和经理的薪水，所以要将两个信息放到同一行，即连接：Employee a inner join Employee b
之后就比较简单了，筛选条件：where a.ManagerId=b.Id and a.Salary > b.Salary
最后展现条件：select a.Name as Employee

*/

select a.Name as Employee from Employee a inner join Employee b where a.ManagerId=b.Id and a.Salary > b.Salary
