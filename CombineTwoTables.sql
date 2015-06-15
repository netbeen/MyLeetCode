/*

给定表1：
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| PersonId    | int     |
| FirstName   | varchar |
| LastName    | varchar |
+-------------+---------+
给定表2:
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| AddressId   | int     |
| PersonId    | int     |
| City        | varchar |
| State       | varchar |
+-------------+---------+

要求给出表：
FirstName, LastName, City, State
其中不管这人有没有地址，都要显示出来。

分析：很显然是连接语法。不过要求表1的内容必须要显示出来，则要用左外连接。
注意：连接的筛选语法要用关键字on！！！！！

*/select FirstName,LastName,City,State from Person left outer join Address on Person.PersonId=Address.PersonId
