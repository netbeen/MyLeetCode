/*

给定Employee表：
+----+-------+--------+--------------+
| Id | Name  | Salary | DepartmentId |
+----+-------+--------+--------------+
| 1  | Joe   | 70000  | 1            |
| 2  | Henry | 80000  | 2            |
| 3  | Sam   | 60000  | 2            |
| 4  | Max   | 90000  | 1            |
+----+-------+--------+--------------+

给定表Department：
+----+----------+
| Id | Name     |
+----+----------+
| 1  | IT       |
| 2  | Sales    |
+----+----------+

要求返回每个部门最高薪水的人：
+------------+----------+--------+
| Department | Employee | Salary |
+------------+----------+--------+
| IT         | Max      | 90000  |
| Sales      | Henry    | 80000  |
+------------+----------+--------+

思路：由于每个部门可能有两个拥有相同最高薪水的人，因此不能直接max(Salary)再group by来得到（这样只会得到一个人，另一个人会被丢弃），
解：首先找到每个部门的最高薪水，然后通过最高薪水去内连查找该部门中持有该薪水的人，最后再内连部门表查询部门名称。
*/

select Department.Name,MaxSalaryPersonTable.Name,MaxSalaryPersonTable.Salary from Department inner join
    (select Name,Salary,MaxSalaryTable.DepartmentId from Employee inner join 
        (select max(Salary) as MaxSalary, DepartmentId from Employee group by DepartmentId) as MaxSalaryTable
    on Employee.Salary=MaxSalaryTable.MaxSalary and Employee.DepartmentId = MaxSalaryTable.DepartmentId) as MaxSalaryPersonTable
on MaxSalaryPersonTable.DepartmentId=Department.Id;
